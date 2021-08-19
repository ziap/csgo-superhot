# Superhot Time Control Mod

My own implementation of Superhot time control. Better than other similar mods because they only slow down time when you release a key and make time progresses normally when you press down a key. This mod also takes into account the combination of keys you are pressing so it can handle more complex movements and actions.

## Affected keys:

 - WASD: movement
 - Mouse1: shoot
 - Mouse2: secondary attack
 - E: use
 - If you want to add or remove keybinds, edit [input.txt](input.txt), compile and run the C++ code to generate a new config file.
 
## Installation:

 - Download [superhot.cfg](superhot.cfg) and put it in your config folder.
 - In-game: use the command exec superhot to activate the mod and reset_binds to deactivate the mod.
 - You can restart the game after deactivation and play online normally. 

## Notes:

 - If you're too noob to hit anything in slow-motion, use these extra commands:
```
weapon_accuracy_nospread 1
weapon_recoil_scale 0
```

 - This mod also sets the freeze time to 0 so if you're playing classic modes, you don't have to wait in slow-motion.
