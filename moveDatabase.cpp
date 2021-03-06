#include "trainer.cpp"
#include <map>

// Move(Name, PP, Category, Power, Accurracy, Side eff, Type)
map<string,Move*> moves = {
    {"Scratch", new Move("Scratch",35,PHYSICAL,40,100,"",NORMAL),},
    {"Tackle",new Move("Tackle",35,PHYSICAL,40,100,"",NORMAL)},
    {"Pound",new Move("Pound",35,PHYSICAL,40,100,"",NORMAL)},
    {"Quick Attack",new Move("Quick Attack",30,PHYSICAL,40,100,"*+1",NORMAL)},
    {"Fury Swipes",new Move("Fury Swipes",30,PHYSICAL,18,80,"2-35%3-35%4-15%5-15%",NORMAL)},
    {"Giga Impact",new Move("Giga Impact",5,PHYSICAL,150,90,"recharge",NORMAL)},
    {"Hyper Beam",new Move("Hyper Beam",5,SPECIAL,150,90,"recharge",NORMAL)},
    {"Leer",new Move("Leer",3,STATUS,0,100,"stat|100|-enemy|DEF|1",NORMAL)},
    {"Growl",new Move("Growl",40,STATUS,0,100,"stat|100|-enemy|ATK|1",NORMAL)},
    {"Tail Whip",new Move("Tail Whip",30,STATUS,0,100,"stat|100|-enemy|DEF|1",NORMAL)},
    {"Defense Curl",new Move("Defense Curl",40,STATUS,0,100,"stat|100|+user|DEF|1",NORMAL)},
    {"Growth",new Move("Growth",20,STATUS,0,100,"stat|100|+user|ATK|1",NORMAL)},
    {"Double Team",new Move("Double Team",15,STATUS,0,100,"stat|100|+user|EV|1",NORMAL)},
    {"Focus Energy",new Move("Focus Energy",30,STATUS,0,100,"Next move is crit",NORMAL)},
    {"Supersonic",new Move("Supersonic",30,STATUS,0,55,"status|100|CFD",NORMAL)},
    {"Mean Look",new Move("Mean Look",5,STATUS,0,100,"e/Can't escape",NORMAL)},
    {"Recover",new Move("Recover",10,STATUS,0,100,"recover|50",NORMAL)},
    {"Splash",new Move("Splash",40,STATUS,0,100,"",NORMAL)},
    {"Leafage",new Move("Leafage",40,PHYSICAL,40,100,"",GRASS)},
    {"Absorb",new Move("Absorb",25,SPECIAL,20,100,"effect|100|Drain|50",GRASS)},
    {"Energy Ball",new Move("Energy Ball",10,SPECIAL,90,100,"stat|10|-enemy|DEF|1",GRASS)},
    {"Solar Beam", new Move("Solar Beam",10,SPECIAL,120,100,"turn",GRASS)},
    {"Stun Spore",new Move("Stun Spore",30,STATUS,0,75,"status|100|PAR",GRASS)},
    {"Worry Seed", new Move("Worry Seed",10,STATUS,0,100,"effect|100|enemy|AB|imsomnia",GRASS) },
    {"Water Gun",new Move("Water Gun",25,SPECIAL,40,100,"",WATER)},
    {"Muddy Water", new Move("Muddy Water",10,SPECIAL,90,85,"stat|30|-enemy|ACC|1",WATER)  },
    {"Surf", new Move("Surf",15,SPECIAL,90,85,"",WATER)},
    {"Withdraw", new Move("Withdraw",40,STATUS,0,100,"stat|100|+user|DEF|1",WATER) },
    {"Aqua Ring", new Move("Aqua Ring",20,STATUS,0,0,"+1/16hp every turn",WATER) },
    {"Withdraw", new Move("Withdraw",20,STATUS,0,100,"stat|100|-enemy|ATK|2",FAIRY) },
    {"Ember", new Move("Ember",25,SPECIAL,40,100,"status|10|BRN",FIRE) },
    {"Flare Blitz", new Move("Flare Blitz", 15, PHYSICAL, 120,100,"status|10|BRN",FIRE)},
    {"Flamethrower", new Move("Flamethrower",15,SPECIAL,90,100,"status|10|BRN",FIRE)},
    {"Overheat", new Move("Overheat", 5,SPECIAL,140,90,"stat|100|-user|SPA|2",FIRE)},
    {"Sunny Day", new Move("Sunny Day",5,STATUS,0,100,"weather|SUN",FIRE)},
    {"Will-O-Wisp", new Move("Will-O-Wisp",15,STATUS,0,75,"status|100|BRN",FIRE) },
    {"Silver Wind", new Move("Silver Wind",60,SPECIAL,60,100,"10*/. + all stat",BUG) },
    {"Struggle Bug", new Move("Struggle Bug",20,SPECIAL,50,100,"stat|100|-enemy|ATK|1",BUG) },
    {"X-Scissor", new Move("X-Scissor",15,PHYSICAL,80,100,"",BUG) },
    {"Revenge", new Move("Revenge",10,PHYSICAL,60,100,"doubles DMG if gets hit",FIGHTING) },
    {"Power-Up-Punch", new Move("Power-Up-Punch",20,PHYSICAL,40,100,"stat|100|+user|ATK|1",FIGHTING) },
    {"Low Kick", new Move("Low Kick",20,PHYSICAL,0,100,"DmgPerWeight",FIGHTING) },
    {"Aura Sphere", new Move("Aura Sphere",20,PHYSICAL,80,100,"",FIGHTING) },
    {"Mach Punch", new Move("Mach Punch",30,PHYSICAL,40,100,"priority|1",FIGHTING)},
    {"Brick Break", new Move("Brick Break",15,PHYSICAL,75,100,"Breaks Reflect & Light Screen",FIGHTING) },
    {"Thunder Shock", new Move("Thunder Shock",30,SPECIAL,40,100,"status|10|PAR",ELECTRIC) },
    {"Thunder Punch", new Move("Thunder Punch", 15, PHYSICAL, 75, 100,"status|10|PAR",ELECTRIC)},
    {"Thunderbolt", new Move("Thunderbolt",15,SPECIAL,95,100,"status|10|PAR",ELECTRIC) },
    {"Charge", new Move("Charge",20,SPECIAL,0,100,"Next e-2Power && u+1/spd",ELECTRIC) },
    {"Wing Attack", new Move("Wing Attack",35,PHYSICAL,60,100,"",FLYING)},
    {"Bounce", new Move("Bounce",5,PHYSICAL,85,85,"turn",FLYING)},
    {"Rollout", new Move("Rollout",20,PHYSICAL,30,90,"Power*2->everyTurn",ROCK) },
    {"Stone Edge", new Move("Stone Edge",5,PHYSICAL,100,80,"effect|20|CRIT",ROCK) },
    {"Rock Slide", new Move("Rock Slide", 10,PHYSICAL,75,90,"effect|30|FLI",ROCK)},
    {"Dark Pulse", new Move("Dark Pulse",15, SPECIAL,80,100,"effect|20|FLI",DARK)},
    {"Faint Attack", new Move("Faint Attack",20, SPECIAL,60,100,"",DARK)},
    {"Pursuit", new Move("Pursuit",20, SPECIAL,40,100,"",DARK)},
    {"Embargo", new Move("Embargo",15, STATUS,0,100,"Enemy cannot use items",DARK)},
    {"Dark Void", new Move("Dark Void",10,STATUS,0,80,"status|100|SLP",DARK)},
    {"Taunt", new Move("Taunt",20,STATUS,0,100,"effect|NO_ATTACKS",DARK)},
    {"Nasty Plot", new Move("Nasty Plot",20,STATUS,0,100,"stat|100|+user|SPA|2",DARK)},
    {"Astonish", new Move("Astonish",25,PHYSICAL,50,100,"status|10|CFD",PSYCHIC)},
    {"Shadow Ball", new Move("Shadow Ball",10,SPECIAL,90,100,"stat|10|-enemy|DEF|1",GHOST)},
    {"Psychic", new Move("Psychic",10,SPECIAL,90,100,"stat|10|-enemy|DEF|1",PSYCHIC)},
    {"Confusion", new Move("Confusion",15,PHYSICAL,30,100,"effect|30|FLI",PSYCHIC)},
    {"Extrasensory", new Move("Extrasensory",20,PHYSICAL,80,100,"effect|10|FLI",PSYCHIC)},
    {"Luster Purge", new Move("Luster Purge",5,SPECIAL,70,100,"stat|50|-enemy|DEF|1",PSYCHIC)},
    {"Dream Eater", new Move("Dream Eater",15,SPECIAL,100,100,"Enemy needs to be sleep|Recovers 50 dmg",PSYCHIC)},
    {"Teleport", new Move("Teleport",20,STATUS,0,100,"Runs from battle",PSYCHIC)},
    {"Mirror Coat", new Move("Mirror Coat",20,STATUS,0,100,"Special attack counter",PSYCHIC)},
    {"Light Screen", new Move("Light Screen",30,STATUS,0,100,"Doubles Defense for 5 turns",PSYCHIC)},
    {"Sludge Bomb",new Move("Sludge Bomb",10,SPECIAL,90,100,"status|30|PSN",POISON)},
    {"Toxic", new Move("Toxic",10,STATUS,0,75,"status|100|PSN",POISON)},
    {"Earthquake", new Move("Earthquake",10,PHYSICAL,100,100,"",GROUND)},
    {"Dragon Pulse", new Move("Dragon Pulse",10,SPECIAL,90,100,"",DRAGON)},
    {"Dragon Rush", new Move("Dragon Rush",10,PHYSICAL,100,75,"effect|20|FLI",DRAGON)},
    {"Ice Beam", new Move("Ice Beam",10,SPECIAL,90,100,"status|10|FRZ",ICE)}
};