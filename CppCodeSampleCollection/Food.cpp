#include "Item.h"
#include "Food.h"

#include <cstdlib>
#include <string>

using std::string;

Food::Food(string name, int quantity) : Item(name, quantity) {
	SetItemName(name);
	SetItemQuantity(quantity);
}

Food::~Food() {}

float Food::GetValue() {
	return _value;
}

bool Food::SetValue(float value) {
	_value = value;
	return true;
}

bool Food::IsRation() {
	return _ration;
}

bool Food::IsSpoiled() {
	return _spoiled;
}

void Food::ToggleSpoiled() {
	_spoiled = !_spoiled;
}

int Food::GetAge() {
	return _age;
}

bool Food::SetAge(float value) {
	_age = value;
	if (_age > SPOILING_AGE) {
		return true;
	}
	return false;
}
bool Food::IncrementAge(float value) {
	SetAge(_age - value);
	if (_age > SPOILING_AGE) {
		return true;
	}
	return false;
}