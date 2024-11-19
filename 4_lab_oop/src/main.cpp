#include <iostream>
#include <memory>

#include "point.hpp"
#include "figure.hpp"
#include "dinFig.hpp"
#include "rectangle.hpp"
#include "rhombus.hpp"
#include "trapezoid.hpp"



int main() {
    // Создание
    Rectangle<double> r ({Point<double>(0,5), Point<double>{0,15}, Point<double>{15,15}, Point<double>{15,5}});
    std::cout << r.square() << std::endl;

    // Конструктор копирования
    Rectangle R(r);
    std::cout << R.square() << std::endl;

    Rectangle h = R;
    std::cout << h.square() << std::endl;

    // Оператор копирования
    Rectangle<double> H;
    H = r;
    std::cout << H.square() << std::endl;

    // Сравнение
    bool flag;
    flag = H == r;
    std::cout << flag << std::endl;

    flag = H != r;
    std::cout << flag << std::endl;

    // Массив фигур
    DinFig<std::shared_ptr<Figure<double>>> F;
    Rhombus<double> k ({{1,4},{3,6},{5,4},{3,2}});

    F.push_back(std::make_shared<Rectangle<double>>(r));
    F.push_back(std::make_shared<Rhombus<double>>(k));
    F.printCenters();
    F.printCoords();
    F.printSquares();
    std::cout << F.getAllSquare() << std::endl;
    F.remove_ind(1);
    std::cout << F.getAllSquare() << std::endl;

    std::cout << "---------------------------------------" << std::endl;

    // Потоковый ввод данных
    Figure<double>* y = new Trapezoid<double>();
    std::cin >> *y;
    std::cout << "Figure: " << *y << ", square: " << y->square()
              << ", centre: (" << y->center().getX() << ", " <<  y->center().getY() << ")"<< std::endl;


    return 0;
}
