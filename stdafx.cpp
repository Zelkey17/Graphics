#include "stdafx.h"

void MainWindow() {

	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
	Table table(3);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(35, 40, 40));
		
		window.display();
	}
}