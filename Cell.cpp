#include "Cell.h"

void Cell::draw(sf::RenderWindow &window) {
	window.draw(cell_bg);
}
void Cell::setPosition(sf::Vector2f vec) {
	cell_bg.setPosition(vec);
}
void Cell::setSize(sf::Vector2f vec) {
	cell_bg.setSize(sf::Vector2f(vec.x - 1, vec.y - 1));
}
Cell::Cell() {
	cell_bg.setSize(sf::Vector2f(99, 29));
	cell_bg.setOutlineThickness(1);
	cell_bg.setFillColor(sf::Color::Black);
	cell_bg.setOutlineColor(sf::Color::White);
	value = 0;
}
