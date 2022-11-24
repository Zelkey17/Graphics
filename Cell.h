#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <set>
#include <cmath>


class Cell
{
public:
	void draw(sf::RenderWindow&);
	void setPosition(sf::Vector2f);
	void setSize(sf::Vector2f);
	Cell();
	int value;
private:
	sf::RectangleShape cell_bg;
};

