#pragma once
#include "ehglobal.h"
class Genre
{
	const int num;
	string name;
public:
	Genre(int num, string name);
	int GetNum() const;
	string GetName() const;
	void View() const;
};