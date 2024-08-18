#include "Inventory.h"
#include "Item.h"

#include <cstdlib>
#include <string>
#include <cmath>

using std::abs;

bool Inventory::AddInventoryItem(string itemName, int quantity) {
    if (_totalItems < MAX_ITEMS) {
        //Init Item pointer
        Item* newItem = new Item(itemName, quantity);
        _totalItems++;

        //Add Head and Last
        if (_totalItems == 1 && _head == NULL) {
            _head = newItem;
            _last = newItem;
        }
        else if (_last != NULL) {
            _last->SetNextItem(newItem);
            newItem->SetLastItem(_last);
            SetLastItem(newItem);
        }
        else {
            _last = newItem;
        }
        return true;
    }
    return false;
}

Item Inventory::GetItem(string nameKey) {
    Item search = GetHeadItem();
    bool itemFound = false;

    while (!itemFound || search.CompareNullItem(search)) {
        if (search.GetItemName() == nameKey) {
            return search; //Contains correct name key
        }
        else {
            search = search.GetNextItem();
        }
    }

    return search; //Null Item
}

bool Inventory::AddInventoryDescription(Item* item, string itemDescription) {
    // Since item is a pointer, dereference it first (*item) to obtain 
    // reference and access object's fields and methods.
    // a-> notation is horthand for (*a).b

    //return (*item).SetItemDescription(itemDescription);
    return item->SetItemDescription(itemDescription);
}//end AddInventoryDescription

string Inventory::GetInventoryDescription(Item* item) {
    if (item->GetItemDescription() != "") {
        return item->GetItemDescription();
    }
    return "Null Item Description";
}//end GetInventoryDescription

bool Inventory::SetInventoryDescription(Item* item, string itemDescription) {
    return item->SetItemDescription(itemDescription);
}//end GetInventoryDescription

int Inventory::GetInventoryQuantity(Item* item) {
    return item->GetItemQuantity();
}//end GetInventoryQuantity

bool Inventory::SetInventoryQuantity(Item* item, int newQuantity) {
    return item->SetItemQuantity(abs(newQuantity));
}//end SetInventoryQuantity

bool Inventory::IncrementInventoryQuantity(Item* item, int value) {
    return item->IncrementItemQuantity(abs(value));
}//end IncrementInventoryQuantity

bool Inventory::DecrementInventoryQuantity(Item* item, int value) {
    return item->DecrementItemQuantity(abs(value));
}//end DecrementInventoryQuantity

int Inventory::GetTotalItems() {
    return _totalItems;
}

Item Inventory::GetHeadItem() {
    return *_head;
}

Item Inventory::GetLastItem() {
    return *_last;
}

bool Inventory::SetHeadItem(Item* newItem) {
    _head = newItem;
    if (_head != NULL) {
        return true;
    }
    return false;
}

bool Inventory::SetLastItem(Item* newItem) {
    _last = newItem;
    if (_last != NULL) {
        return true;
    }
    return false;
}
