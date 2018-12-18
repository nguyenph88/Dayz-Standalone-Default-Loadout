# Dayz-Standalone-Default-Loadout
Change default loadout of the fresh spawner

## How to use
- Open your mpmissions/dayzOffline.chernarusplus/init.c
- Delete anything inside `override void StartingEquipSetup(PlayerBase player, bool clothesChosen)` function
- Add this to the above function `DefaultPlayerLoadout dplObj = new DefaultPlayerLoadout(player);`
- On the same init.c file, add this line to the very top `#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Scripts\\DefaultPlayerLoadout.c"`
- Copy the *Scripts* folder to the mission folder

*Optional:*
- If you don't have anything inside your init, just copy and paste my init.c and replace yours.

## How to change loot
- The script will allow you to be spawn with: an M4, a handgun, some stuff and a *Hatchback*
- Just open DefaultPlayerLoadout.c and make changes according to your needs