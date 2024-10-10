#include <iostream>
#include "decimal.h"

int main() {
    // создание
    Decimal a("123");
    std::cout << a.toString() << std::endl;

    // копирование
    Decimal b(a);
    std::cout << b.toString() << std::endl;

    // перемещение
    Decimal c(std::move(a));
    std::cout << c.toString() << std::endl;

    // присваивание
    Decimal d = Decimal("222");
    std::cout << d.toString() << std::endl;

    // сложение
    Decimal e = b + d;
    std::cout << e.toString() << std::endl;

    // вычитание
    Decimal f = e - b;
    std::cout << f.toString() << std::endl;

    // сравнения
    Decimal x1("1000");
    Decimal x2("1001");

    bool n = x1 > x2;
    std::cout << n << std::endl; // false

    n = x1 < x2;
    std::cout << n << std::endl; // true

    n = x1 == x2;
    std::cout << n << std::endl; // false

    n = x1 != x2;
    std::cout << n << std::endl; // true
}
