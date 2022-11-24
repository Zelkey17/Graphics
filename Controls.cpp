//
// Created by ash on 02.10.22.
//

#include "Controls.h"

namespace GraphicsProject {
    void Anim::show(sf::RenderWindow &win) {
        sf::Texture gif_texture;
        i = ((i + 1) % (n * s));
        gif_texture.loadFromFile(s1 + std::to_string(i / s + 1) + s2);
        sf::Sprite gif(gif_texture);
        gif.setScale(sc, sc);
        gif.setPosition(x, y);
        win.draw(gif);
    }

    Anim::Anim(std::string s1, std::string s2, int n, int s, int x, int y, double sc) :
            i(0),
            n(n),
            s(s),
            x(x),
            y(y),
            sc(sc),
            s1(std::move(s1)),
            s2(std::move(s2)) {

    }

    Label::Label(std::string s, int x, int y, int size, std::string font, int r, int g, int b) {
        if (!label_font.loadFromFile(font)) {}
        label = sf::Text(s, label_font, size);
        label.setOutlineColor(sf::Color(r, g, b));
        label.setFillColor(sf::Color(r, g, b));
        label.setPosition(x, y);

    }

    sf::Text Label::get() { return label; }

    textbox::textbox(int x1, int y1, int h, int w, int r, int g, int b, std::string s) {
        x = x1;
        y = y1;
        width = w;
        height = h;
        box.setSize(sf::Vector2f(width, height));
        box.setPosition(x, y);
        box.setFillColor(sf::Color(r, g, b));
        box.setOutlineThickness(2);
        box.setOutlineColor(sf::Color(0, 250, 200));
        text1 = s;
    }

    void textbox::change(char one) {
        if (active) {
            if (one == 8) {
                if (!text.empty()) {
                    text.erase(text.size() - 1);
                    text3 /= 10;
                }
                if (text.empty()) {
                    text = "0";
                }
            } else if (one <= '9' && one >= '0') {
                if (text.size() < 3) {
                    text3 *= 10;
                    text3 += one - '0';
                } else {
                    text = "999";
                    text3 = 999;
                }
                text = std::to_string(text3);
            }
        }
    }

    void textbox::show(sf::RenderWindow &win) {
        win.draw(box);
        win.draw(Label(text1, x, y - 5, height, "font.ttf", 10, 10, 10).get());
        win.draw(Label(text, x + (text1.size() * height / 3), y - 5, height, "font.ttf", 10, 10, 10).get());
    }

    void textbox::select(sf::Vector2i _mouse) {
        if ((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)) {
            active = true;
        } else {
            active = false;
        }

    }

    Button::Button(double _x, double _y, double _width, double _height, int r, int g, int b) {
        x = _x;
        y = _y;
        width = _width;
        height = _height;
        box.setSize(sf::Vector2f(width, height));
        box.setPosition(x, y);
        box.setFillColor(sf::Color(r, g, b));
        box.setOutlineThickness(2);
        box.setOutlineColor(sf::Color(100, 100, 100));

    }

    sf::RectangleShape Button::displayButton() const {
        return box;
    }

    bool Button::select(sf::Vector2i _mouse) const {
        if ((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)) {
            return true;
        } else {
            return false;
        }
    }
}