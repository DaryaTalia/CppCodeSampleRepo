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
    Item* _lastItem = NULL;
    Item* _nextItem = NULL;

public:
    // Functions
    Item(string name, int quantity);
    ~Item();

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
};