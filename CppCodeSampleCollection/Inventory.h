#pragma once

#include "Item.h"
#include <cstdlib>
#include <string>

// class > allows null values
class Inventory {
private:
    // Data
    const int MAX_ITEMS = 10;

    int _totalItems = 0;
    Item* _head = NULL;
    Item* _last = NULL;

public:
    // Functions
    Inventory() {};
    ~Inventory() {};

    bool AddInventoryItem(string itemName, int quantity);

    bool AddInventoryDescription(Item* item, string itemDescription);
    string GetInventoryDescription(Item* item);
    bool SetInventoryDescription(Item* item, string itemDescription);

    int GetInventoryQuantity(Item* item);
    bool SetInventoryQuantity(Item* item, int newQuantity);
    bool IncrementInventoryQuantity(Item* item, int value);
    bool DecrementInventoryQuantity(Item* item, int value);

    Item GetHeadItem();
    Item GetLastItem();
    bool SetHeadItem(Item* newItem);
    bool SetLastItem(Item* newItem);
};