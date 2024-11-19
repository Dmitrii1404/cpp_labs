#include <iostream>
#include "dinFig.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"



int main() {

    Figure* a = new Rectangle({0,5},{0,15},{15,15},{15,5});
    Figure* b = new Rectangle({0,0}, {0,-5}, {-5,-5}, {-5,0});
    Figure* c = new Rhombus({1,4},{3,6},{5,4},{3,2});
    Figure* d = new Rhombus({-2,-5},{-4,-7},{-6,-5},{-4,-3});
    Figure* e = new Trapezoid({1,2},{3,5},{7,5}, {9,2});
    Figure* f = new Trapezoid({-2,-3},{-4,-6},{-8,-6}, {-10,-3});
    DinFig<Figure*> F;
    F.push_back(a);
    F.push_back(b);
    F.push_back(c);
    F.push_back(d);
    F.push_back(e);
    F.push_back(f);
    std::cout << F.getAllSquare() << std::endl;
    F.remove_ind(2);
    std::cout << F.getAllSquare() << std::endl;
    F.remove_ind(0);
    std::cout << F.getAllSquare() << std::endl;

    Figure* y = new Trapezoid();
    std::cin >> *y;
    std::cout << "Figure: " << *y << ", square: " << y->square()
              << ", centre: (" << y->center().first << ", " <<  y->center().second << ")"<< std::endl;

    DinFig<Figure*> G;
    Trapezoid r({1,2},{3,5},{7,5}, {9,2});
    G.push_back(&r);
    G.printCoords();
    G.printCenters();
    G.printSquares();
    std::cout << G.getAllSquare() << std::endl;

    Trapezoid n(r);
    Trapezoid t;
    t = n;

    std::cout << "Figure: " << r << ", square: " << r.square()
              << ", centre: (" << r.center().first << ", " <<  r.center().second << ")"<< std::endl;
    std::cout << "Figure: " << t << ", square: " << t.square()
              << ", centre: (" << t.center().first << ", " <<  t.center().second << ")"<< std::endl;

    DinFig<Figure*> Z;
    Rectangle q({10,10},{10,15},{15,15}, {15,10});
    Rectangle rect1 = Rectangle ({0,0}, {0,5}, {5,5}, {5,0});
    Rectangle r2({20,20},{20,25},{25,25}, {25,20});

    Z.push_back(&q);
    Z.push_back(&rect1);
    Z.push_back(&r2);

    Z.printCoords();
    Z.printCenters();
    Z.printSquares();

    Z.remove_ind(1);

    Z.printCoords();
    Z.printCenters();
    Z.printSquares();

    return 0;
}
