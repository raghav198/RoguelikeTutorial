//
//  Weapons.hpp
//  RoguelikeTutorial
//
//  Created by Malik, Raghav on 6/23/19.
//  Copyright © 2019 Malik, Raghav. All rights reserved.
//

#ifndef Weapons_hpp
#define Weapons_hpp

enum MeleeWeaponClass {
    HAND,
    SHORT,
    SMALL_SWORD,
    LARGE_SWORD,
    AXE,
    BLUNT,
    WHIP
};

enum RangedWeaponClass {
    THROWING,
    BOW,
    SHORTBOW,
    CROSSBOW,
    SLING,
    BLOWGUN,
    GUNPOWDER
};

enum AmmunitionType {
    HARPOON,
    JAVELIN,
    CHAKRAM,
    ARROW,
    BOLT,
    ROCK,
    DART,
    BULLET
};

enum WeaponBrand {
    SPEED,
    VORPAL,
    FLAMING,
    FREEZING,
    ELECTRICITY,
    VENOM,
    SPLASH
};

struct MeleeWeapon {
    MeleeWeaponClass weaponClass;
    WeaponBrand brand;
    int damage;
    int attackSpeed;
};

struct RangedWeapon {
    RangedWeaponClass weaponClass;
    WeaponBrand brand;
    AmmunitionType ammo;
    int damage;
}

#endif /* Weapons_hpp */
