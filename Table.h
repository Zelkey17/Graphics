#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <set>
#include <cmath>

#include "Cell.h"
#include "Table.h"

class d{
    d()=default;
};


class Table
{
public:
	void fillInTable(int);
	void draw(sf::RenderWindow&);
	explicit Table(int);
	Table() = default;
private:
	std::vector<std::vector<Cell>> table;
	int num{};
};

