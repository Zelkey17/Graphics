//
// Created by ash on 27.09.22.
//
#include "MainWindow.h"
#include "Shapes.h"
#include<fstream>

namespace GraphicsProject {
    void MainWindow::start() {
        sf::Vector2i local_point = sf::Mouse::getPosition(window);
        while (window.isOpen()) {
            sf::Event event{};

            while (window.pollEvent(event)) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
                        if (zoom.x < 200 && zoom.y < 200) {
                            zoom.x++;
                            zoom.y++;
                            ul_coord.x = -(win_size.x / zoom.x) / 2.f;
                            ul_coord.y = -(win_size.y / zoom.y) / 2.f;
                        }
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
                        if (zoom.x > 20 && zoom.y > 20) {
                            zoom.x--;
                            zoom.y--;
                            ul_coord.x = -(win_size.x / zoom.x) / 2.f;
                            ul_coord.y = -(win_size.y / zoom.y) / 2.f;
                        }
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                        ul_coord.x -= 0.1;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                        ul_coord.x += 0.1;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                        ul_coord.y -= 0.1;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                        ul_coord.y += 0.1;
                    }
                }
                if (event.type == sf::Event::Closed)
                    window.close();
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    ul_coord.x += (float) (local_point.x - sf::Mouse::getPosition(window).x) / zoom.x;
                    ul_coord.y += (float) (local_point.y - sf::Mouse::getPosition(window).y) / zoom.y;
                }
                local_point = sf::Mouse::getPosition(window);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    double x = local_point.x / zoom.x + ul_coord.x,
                            y = -local_point.y / zoom.y - ul_coord.y;
                    unsigned long long mask = 0;
                    if(x>0)mask+=1ull<<63;
                    if(y>0)mask+=1ull<<62;
                    for (size_t ind = 0; ind < shapes.size(); ind++) {
                        if (shapes[ind]->under(x, y))mask += 1 << ind;
                    }
                    areas[mask]+=1;
                    areas[mask]%=(int)colors.size();

                }

                if (event.type == sf::Event::MouseWheelScrolled) {
                    if (std::max(zoom.x, zoom.y) + event.mouseWheelScroll.delta < 20)continue;
                    double x = local_point.x / zoom.x + ul_coord.x,
                            y = -local_point.y / zoom.y - ul_coord.y;

                    ul_coord.x = x - (x - ul_coord.x) / (zoom.x + event.mouseWheelScroll.delta) * zoom.x;
                    zoom.x += event.mouseWheelScroll.delta;

                    ul_coord.y = (y + ul_coord.y) / (zoom.y + event.mouseWheelScroll.delta) * zoom.y - y;
                    zoom.y += event.mouseWheelScroll.delta;

                }

            }
            update();
        }

    }

    MainWindow::MainWindow(const std::string &title, const sf::Vector2i &size) :
            window(sf::VideoMode(size.x, size.y), title),
            win_size(size),
            zoom(35, 35),
            ul_coord(-(win_size.x / zoom.x) / 2.f, -(win_size.y / zoom.y) / 2.f) {
        init();

    }

    void MainWindow::init() {

        pix = new uint8_t[win_size.x * win_size.y * 4];
        texture.create(win_size.x, win_size.y);
        sprite.setTexture(texture);
        colors={sf::Color::White,sf::Color::Cyan,sf::Color::Black,sf::Color::Yellow,sf::Color::Red};

    }

    void MainWindow::update() {
        window.clear({255, 255, 255, 255});
        for (int i = 0; i < win_size.y; i++) {
            for (int j = 0; j < win_size.x; j++) {
                sf::Color clr = color(i, j);
                pix[(i + j * win_size.y) * 4] = clr.r;
                pix[(i + j * win_size.y) * 4 + 1] = clr.g;
                pix[(i + j * win_size.y) * 4 + 2] = clr.b;
                pix[(i + j * win_size.y) * 4 + 3] = clr.a;
            }
        }
        texture.update(pix);
        window.draw(sprite);
        window.display();
    }

    void MainWindow::read_shapes() {
        std::ifstream cin("input.txt");
        char h;
        while (cin >> h) {
            if (h == 'e') start();
            if (h == 'l') {
                double k, l;
                cin >> k >> l;
                shapes.push_back(new Line(k, l));
            }
            if (h == 'c') {
                double x, y, r;
                cin >> x >> y >> r;
                shapes.push_back(new Circle(x, y, r));
            }
            if (h == 'p') {
                double a, b, c, d, e;
                cin >> a >> b >> c >> d >> e;
                shapes.push_back(new Parabola(a, b, c, d, e));
            }
            if (h == 'r') {
                double a, b, c, d, e;
                cin >> a >> b >> c >> d >> e;
                shapes.push_back(new Romb(a, b, c, d, e));
            }
            if (h == 'b') {
                double a, b, c, d;
                cin >> a >> b >> c >> d;
                shapes.push_back(new Rectangle(a, b, c, d));
            }
        }
    }

    sf::Color MainWindow::color(int i, int j) {
        double x = (double) (i) / zoom.x + ul_coord.x,
                y = (double) (-j) / zoom.y - ul_coord.y;

        ///
        /// Axis
        ///

        if (std::abs(x) < 2 / zoom.x) return {0, 0, 0, 255};
        if (std::abs(y) < 2 / zoom.y) return {0, 0, 0, 255};

        ///
        ///Coordinate grid
        ///
        if (std::abs(x) - (int) std::abs(x) < 1 / zoom.x) return {100, 100, 100, 255};
        if (std::abs(y) - (int) std::abs(y) < 1 / zoom.x) return {100, 100, 100, 255};

        ///
        ///Lines
        ///
        unsigned long long mask = 0;

        if(x>0)mask+=1ull<<63;
        if(y>0)mask+=1ull<<62;

        for (size_t ind = 0; ind < shapes.size(); ind++) {
            if (shapes[ind]->contains(x, y))return sf::Color::Black;
            if (shapes[ind]->under(x, y))mask += 1 << ind;
        }
        ///
        ///Areas
        ///
        return colors[areas[mask]];
    }

} // GraphicsProject

