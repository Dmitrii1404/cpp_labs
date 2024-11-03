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
    Decimal d = Decimal("456");
    std::cout << d.toString() << std::endl;

    // сложение
    Decimal e;
    e.prisv(b.plus(d));
    std::cout << e.toString() << std::endl;

    // вычитание
    Decimal f;
    f.prisv(e.minus(b));
    std::cout << f.toString() << std::endl;

    // сравнения
    Decimal x1("342");
    Decimal x2("343");

    bool n = x1.bolshe(x2);
    std::cout << n << std::endl; // false

    n = x1.menshe(x2);
    std::cout << n << std::endl; // true

    n = x1.ravno(x2);
    std::cout << n << std::endl; // false

    n = x1.not_ravno(x2);
    std::cout << n << std::endl; // true
}
