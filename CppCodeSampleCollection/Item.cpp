#include "Item.h"

#include <cstdlib>
#include <string>

using std::string;

Item::Item(string name, int quantity){
}

Item::~Item() {}

string Item::GetItemName() {
    return _itemName;
}

bool Item::SetItemName(string newName) {
    _itemName = newName;
    return true;
}

int Item::GetItemQuantity() {
    return _itemQuantity;
}

bool Item::SetItemQuantity(int quantity) {
    _itemQuantity = quantity;
    return true;
}

bool Item::IncrementItemQuantity(int amount) {
    if (GetItemQuantity() < MAX_QUANTITY) {
        SetItemQuantity(GetItemQuantity() + amount);

        if (GetItemQuantity() > MAX_QUANTITY) {
            SetItemQuantity(MAX_QUANTITY);
        }
        return true;
    }
    return false;
}

bool Item::DecrementItemQuantity(int amount) {
    if (GetItemQuantity() > 0) {
        SetItemQuantity(GetItemQuantity() - amount);

        if (GetItemQuantity() < 0) {
            SetItemQuantity(0);
        }
        return true;
    }
    return false;
}

string Item::GetItemDescription() {
    return _itemDescription;
};

bool Item::SetItemDescription(string newDescription) {
    _itemDescription = newDescription;
    return true;
}

Item Item::GetLastItem() {
    return *_lastItem;
}

Item Item::GetNextItem() {
    return *_nextItem;
}

bool Item::SetLastItem(Item* newLast) {
    _lastItem = newLast;
    if (_lastItem != NULL) {
        return true;
    }
    return false;
}

bool Item::SetNextItem(Item* newNext) {
    _nextItem = newNext;
    if (_nextItem != NULL) {
        return true;
    }
    return false;
}