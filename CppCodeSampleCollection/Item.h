#pragma once

#include <cstdlib>
#include <string>

using std::string;

class Item {
private:
    // Data
    const int MAX_QUANTITY = 16;

    string _itemName;
    int _itemQuantity = 0;
    string _itemDescription;

    // Nodes
    Item* NULL_ITEM = new Item("NULLITEM", -1);

    Item* _lastItem = NULL_ITEM;
    Item* _nextItem = NULL_ITEM;

public:
    // Functions
    Item();
    Item(string name, int quantity);
    ~Item();
    Item& operator=(const Item&);

    string GetItemName();
    bool SetItemName(string newName);

    int GetItemQuantity();
    bool SetItemQuantity(int quantity);
    bool IncrementItemQuantity(int amount);
    bool DecrementItemQuantity(int amount);

    string GetItemDescription();
    bool SetItemDescription(string newDescription);

    Item GetLastItem();
    Item GetNextItem();
    bool SetLastItem(Item* newLast);
    bool SetNextItem(Item* newNext);

    bool CompareNullItem(Item comparison);
};