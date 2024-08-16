// Player.h file for 
// Metal Gear Solid 3 as C++ Objects

#pragma once

#include "Inventory.h"
#include <cstdlib>
#include <list>
#include <string>

using std::list;

class Player
{
public:
    const float MAX_HEALTH = 100.0;
    const float MAX_STAMINA = 100.0;
    const int MAX_CAMO_INDEX = 100;
    const int MIN_CAMO_INDEX = 0;
    static const int MAX_CAMO_ITEMS = 88;

    const string name = "Jack";
    const string codename1 = "Naked Snake";
    const string codename2 = "Big Boss";
    const string codename3 = "Snake";
    const string camoTypes[5] = { "Boss Camoflouge", "Uniforms", "Disguise", "Face Paint", "Special" };
    const string camoStatuses[2] = { "Not Collected", "Collected" };

    enum Injury_Types { arrow_bolt, broken_bone, burn, cut, gunshot_wound, hypodermic_needle, leech, no_injury }; //rows
    enum Injury_Tools { survival_knife, cigar, ointment, disinfectant, styptic, plint, bandage, suture_kit }; // columns

    enum Ailment_Types { cold, food_poisoning, stomach_sickness, venom_poisoning, no_ailment }; //rows
    enum Ailment_Tools { serum, cold_medicine, antidote, digestive_medicine }; // columns

    enum Camo_Status { Unhidden = 20, Semihidden = 50, Hidden = 80, Invisible = 100 };
    enum Camoflouge_Properties { camo_name, camo_type, camo_description, camo_status };

    Player();
    ~Player();

    float GetHealth();
    bool SetHealth(float newHealth);
    bool HealHealth(float amount);
    bool DamageHealth(float amount);

    float GetStamina();
    bool SetStamina(float newStamina);
    bool HealStamina(float amount);
    bool DamageStamina(float amount);

    void DetermineCamoStatus();
    int GetCamoIndex();
    void SetCamoIndex(int value);
    bool IncrementCamoIndex(int value);
    bool DecrementCamoIndex(int value);


private:
    float _health = 100.0;
    float _stamina = 100.0;
    int _camoIndex = 30;

    Inventory* primaryInventory;

    list<Injury_Types> _currentInjuries;
    const bool injury_chart[7][8] =
    {// survival_knife, cigar, ointment, disinfectant, styptic, plint, bandage, suture_kit
        { {true}, {false}, {false}, {false}, {false}, {false}, {true}, {false} }, // arrow_bolt
        { {false}, {false}, {false}, {false}, {false}, {true}, {true}, {false} }, // broken_bone
        { {false}, {false}, {true}, {false}, {false}, {false}, {true}, {false} }, // burn
        { {false}, {false}, {false}, {true}, {true}, {false}, {true}, {true} }, // cut
        { {true}, {false}, {false}, {true}, {true}, {false}, {true}, {false} }, // gunshot_wound
        { {true}, {false}, {false}, {false}, {false}, {false}, {false}, {false} }, // hypodermic_needle
        { {false}, {true}, {false}, {false}, {false}, {false}, {false}, {false} }  // leech
    };

    list<Ailment_Types> _currentAilments;
    const Ailment_Tools ailment_chart[4] =
    {
        // cold, food_poisoning, stomach_sickness, venom_poisoning
        {cold_medicine}, {antidote}, {digestive_medicine}, {serum}
    };

    Camo_Status _camoStatus;
    string _currentCamo[3] = { "", "", "" };
    string camoInventory[MAX_CAMO_ITEMS][4] =
    {
        // Boss Camos
        { { "Animal" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
        { { "Spirit" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
        { { "Moss" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
        { { "Spider" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
        { { "Hornet Stripe" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
        { { "Fire" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
        { { "Cold War" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },
        { { "Snake" }, { camoTypes[0] }, { "Description" }, { camoStatuses[0] } },

        //Uniforms
        { { "Naked" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Tiger Stripe Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Olive Drab" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Leaf Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Tree Bark Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Squares Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Black Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Raindrop Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Chocolate Chip Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Splitter Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Snow Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Fly Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "GA-KO" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Water" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Sneaking Suit" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Banana Camouflage" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Tuxedo" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Fruits" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Grenade" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Mummy" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Yodobashi" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Santa" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "New Years" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "St.Valentines" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Former West Germany" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Former East Germany" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "KLMK" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Urban Tiger" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Soviet Woodland" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "E-DEN" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Rainbow" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Anubis" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Rock" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Swamp" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Night Desert" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Watersnake" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Chameleon" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Barracuda" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Flower" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Festival" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Dododo" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Bonsai" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "USMX" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "DPM" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Desert Tiger" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Desert Auscam" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "WonderGOO" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Flecktarn" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Dododo" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Bonsai" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "USMX" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "DPM" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },
        { { "Desert Tiger" }, { camoTypes[1] }, { "Description" }, { camoStatuses[0] } },

        //Disguises
        { { "Scientist" }, { camoTypes[2] }, { "Description" }, { camoStatuses[0] } },
        { { "Raikov's Uniform" }, { camoTypes[2] }, { "Description" }, { camoStatuses[0] } },
        { { "Maintenance" }, { camoTypes[2] }, { "Description" }, { camoStatuses[0] } },

        //Face Paints
        { { "No Paint" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Black" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Splitter" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Zombie" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Woodland" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Mask" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Infinite" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Kabuki" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Oyama" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Snow" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Desert" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Water" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Green" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Brown" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Soviet Union" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "United Kingdom" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "France" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Germany" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Italy" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Spain" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Sweden" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "Japan" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },
        { { "USA" }, { camoTypes[3] }, { "Description" }, { camoStatuses[0] } },

        //Special
        { { "Stealth Camoflouge" }, { camoTypes[4] }, { "Description" }, { camoStatuses[0] } }
    };




};

