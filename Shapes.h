//
// Created by ash on 30.09.22.
//
#include<vector>
#include "Cell.h"

#ifndef GRAPHICS_SHAPES_H
#define GRAPHICS_SHAPES_H

namespace GraphicsProject {

    class Shape {

    public:
        std::vector<Cell> s;
        double eps = 0.5e-1;

        virtual bool under(double x, double y) = 0;

        virtual bool over(double x, double y) = 0;

        virtual bool contains(double x, double y) = 0;

        virtual ~Shape()=default;

    };

    class Line : public Shape {

        double a{}, b{}, c{};
    public:
        bool under(double x, double y) override;

        bool over(double x, double y) override;

        bool contains(double x, double y) override;

        Line() = default;

        Line(double k, double l);

        Line(double a, double b, double c);

    };

    class Circle : public Shape {

        double a{}, b{}, c{};
    public:
        Circle() = default;

        Circle(double x, double y, double r);

        bool contains(double x, double y) override;

        bool under(double x, double y) override;

        bool over(double x, double y) override;

    };

    class Parabola : public Shape {
        double eps=1e-1;
        double a{}, b{}, c{}, d{}, e{};
    public:
        Parabola() = default;

        Parabola(double a, double b, double c, double d, double e);

        bool contains(double x, double y) override;

        bool over(double x, double y) override;

        bool under(double x, double y) override;
    };

    class Romb : public Shape {
        double eps=1e-1;
        double a{}, b{}, c{}, d{}, e{};

        Romb() = default;

    public:
        Romb(double a, double b, double c, double d, double e);

        bool contains(double x, double y) override;

        bool under(double x, double y) override;

        bool over(double x, double y) override;
    };

    class Rectangle : public Shape {

        double a{}, b{}, c{}, d{};

        Rectangle() = default;

    public:
        Rectangle(double a, double b, double c, double d);

        bool contains(double x, double y) override;

        bool under(double x, double y) override;

        bool over(double x, double y) override;

    };

} // GraphicsProject

#endif //GRAPHICS_SHAPES_H
