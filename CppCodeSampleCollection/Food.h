#pragma once

#include "Item.h"

class Food : public Item {
private:
	float _value = 5.0;
	bool _ration = false;
	bool _spoiled = false;
	int _age = 0;

public:
	const int SPOILING_AGE = 2;

	Food(string name, int quantity);
	~Food();

	float GetValue();
	bool SetValue(float value);

	bool IsRation();
	bool IsSpoiled();
	void ToggleSpoiled();

	int GetAge();
	bool SetAge(float value);
	bool IncrementAge(float value);
};