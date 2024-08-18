#pragma once
#include "Inventory.h"
#include "Player.h"

#include <cstdlib>
#include <string>

using std::string;

class HUD {
private:

public:
	string PrintInventory(Inventory accessInventory);
	string PrintWellness(Player accessPlayer);
};