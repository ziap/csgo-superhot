#include <fstream>
#include <iostream>
#include <vector>
#include <string>

std::ifstream fin("input.txt");
std::ofstream fout("superhot.cfg");
std::vector<std::string> keys;
std::vector<std::string> commands;

void read() {
    int n;
    fin >> n;
    std::string key; std::string command;
    for (int i = 0; i < n; i++) {
        fin >> key >> command;
        keys.push_back(key);
        commands.push_back(command);
    }
}

void reset_binds() {
    fout << "alias reset_binds \"";
    for (int i = 0; i < keys.size() - 1; i++) fout << "bind " << keys[i] << " +" << commands[i] << ";";
    fout << "bind " << keys.back() << " +" << commands.back() << ";host_timescale 1\"\n\n";
}

void init() {
    fout << "sv_cheats 1\n";
    fout << "mp_freezetime 0\n";
    fout << "sv_staminamax 0\n";
    fout << "sv_staminajumpcost 0\n";
    fout << "sv_staminalandcost 0\n";
    fout << "sv_staminarecoveryrate 0\n\n";

    for (int i = 0; i < keys.size() - 1; i++) fout << "bind " << keys[i] << " +sh_" << commands[i] << '\n';
    fout << "bind " << keys.back() << " +sh_" << commands.back() << "\n\n";
}

void set_movement() {
    for (unsigned long long i = 0; i < (0x1ULL << keys.size()); i++) {
        fout << "alias STATE_" << i << " \"";
        for (int j = 0; j < keys.size(); j++) fout << (i >> (keys.size() - j - 1) & 0x1ULL ? '+' : '-') << commands[j] << ";";
        for (int j = 0; j < keys.size(); j++) {
            fout << "alias +sh_" << commands[j] << " STATE_" << (i | (0x1ULL << (keys.size() - j - 1))) << ";";
            fout << "alias -sh_" << commands[j] << " STATE_" << (i & (~(0x1ULL << (keys.size() - j - 1)))) << ";";
        }
        fout << (
            (i == 0) ? 
            "host_timescale 0.05" :
            "host_timescale 1"
        );
        fout << "\"\n";
    }
    fout << "\nSTATE_0\n";
}

int main() {
    read();
    reset_binds();
    init();
    set_movement();
}