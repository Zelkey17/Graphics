//
// Created by ash on 02.10.22.
//

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>
#include <utility>

#ifndef GRAPHICS_CONTROLS_H
#define GRAPHICS_CONTROLS_H

namespace GraphicsProject {

    class Anim {
    public:
        int i, n, s, x, y;
        double sc;
        std::string s1, s2;

        Anim(std::string s1, std::string s2, int n, int s, int x, int y, double sc);

        void show(sf::RenderWindow &win);
    };

    class Label {
    public:
        sf::Font label_font;
        sf::Text label;

        Label(std::string s, int x, int y, int size = 55, std::string font = "font.ttf", int r = 50, int g = 150,
              int b = 20);

        sf::Text get();
    };

    class textbox {
    public:
        int x, y, width, height, text3 = 8;
        bool active = false;
        sf::RectangleShape box;
        std::string text = "8", text1;

        textbox(int x1, int y1, int h, int w, int r, int g, int b, std::string s = "");

        void change(char one);

        void show(sf::RenderWindow &win);

        void select(sf::Vector2i _mouse);
    };


    class Button {
    public:
        int x, y, width, height;
        sf::RectangleShape box;
    public:
        explicit Button(double _x = 0, double _y = 0, double _width = 150, double _height = 30, int r = 255, int g = 255,
               int b = 255);

        bool select(sf::Vector2i _mouse) const;

        sf::RectangleShape displayButton() const;
    };

} // GraphicsProject

#endif //GRAPHICS_CONTROLS_H
