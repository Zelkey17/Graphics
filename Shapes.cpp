//
// Created by ash on 30.09.22.
//

#include "Shapes.h"
#include <cmath>

namespace GraphicsProject {
    template<class T>
    int sign(T x) {
        return x < 0 ? -1 : 1;
    }

    bool Line::under(double x, double y) {
        return a * x + b * y < c;
    }

    bool Line::over(double x, double y) {
        return !under(x, y);
    }

    Line::Line(double k, double l) {
        a = -k;
        b = 1;
        c = l;
    }

    Line::Line(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    bool Line::contains(double x, double y) {
        return std::abs(a * x + b * y - c) < eps;
    }

    Circle::Circle(double x, double y, double r) {
        a = x, b = y, c = r;
    }

    bool Circle::under(double x, double y) {
        return (x - a) * (x - a) + (y - b) * (y - b) < c * c;
    }

    bool Circle::over(double x, double y) {
        return !under(x, y);
    }

    bool Circle::contains(double x, double y) {
        return std::abs(std::sqrt((x - a) * (x - a) + (y - b) * (y - b)) - std::abs(c)) < eps;
    }

    Parabola::Parabola(double a, double b, double c, double d, double e) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->e = e;
    }

    bool Parabola::over(double x, double y) {
        return a * x * x + b * x + c * y * y + d * y < e;
    }

    bool Parabola::under(double x, double y) {
        return !over(x, y);
    }

    bool Parabola::contains(double x, double y) {
        double f = (a * x * x + b * x + c * y * y + d * y);
        return std::abs(f - e) < eps;
    }

    Romb::Romb(double a, double b, double c, double d, double e) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->e = e;
    }

    bool Romb::under(double x, double y) {
        return std::abs(d * x - a) + std::abs(e * y - b) < c;
    }

    bool Romb::over(double x, double y) {
        return !under(x, y);
    }

    bool Romb::contains(double x, double y) {
        return std::abs(std::abs(d * x - a) + std::abs(e * y - b) - c) < eps;
    }

    Rectangle::Rectangle(double a, double b, double c, double d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    bool Rectangle::under(double x, double y) {
        return x > a && x < c && y > b && y < d;
    }

    bool Rectangle::over(double x, double y) {
        return !under(x, y);
    }

    bool Rectangle::contains(double x, double y) {
        return (y > b && y < d && (std::abs(x - a) < eps || std::abs(x - c) < eps)) ||
               (x > a && x < c && (std::abs(y - b) < eps || std::abs(y - d) < eps));
    }

} // GraphicsProject