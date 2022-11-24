#include "Table.h"

Table::Table(int n) {
	((int)pow(2, n), std::vector<Cell>((5 + (int)pow(2, n))));
	table.resize((int)pow(2, n));
	for (int i = 0; i < (int)pow(2, n); ++i) {
		table[i].resize((int)pow(2, n));
	}
	Cell tmp;
	std::vector<Cell> t(pow(2, n), tmp);
	num = n;
	this->fillInTable(n);
}

void Table::draw(sf::RenderWindow &window) {
	for (int i = 0; i < 5 + (int)pow(2, num); i++) {
		for (int j = 0; j < (int)pow(2, num); j++) {
			table[i][j].draw(window);
		}
	}
}
void Table::fillInTable(int n) {
	Cell pos;
	pos.value = 1;
	Cell neg;
	sf::Vector2f position = sf::Vector2f(10, 10);
	for (int i = 0; i < n; ++i) {
		table[0][i] = neg;
		table[0][i].setPosition(sf::Vector2f(10 + (i * 100), 10));
	}
	for (int i = 1; i < pow(2, n); ++i) {
		table[i] = table[i - 1];
		for (int j = n - 1; j >= 0; --j) {
			if (table[i][j].value == neg.value) {
				table[i][j] = pos;
				table[i][j].setPosition(sf::Vector2f(10 + (j * 100), 10 + (i * 30)));
				break;
			}
			else {
				table[i][j] = neg;
				table[i][j].setPosition(sf::Vector2f(10 + (j * 100), 10 + (i * 30)));

			}
		}
	}
	for (int i = n ; i < (int)pow(2, n); i++) {
		for (int j = 0; j < (int)pow(2, n); j++) {
			table[i][j] = neg;
		}
	}
}