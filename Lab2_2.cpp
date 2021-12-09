#include <iostream>
#include "conio.h"

class Point {
protected:
    int x, y;
public:
    Point() { //конструктор без параметров
        printf("Point()\n");
        x = 0;
        y = 0;
    }
    Point(int x, int y) { //конструктор с параметрами
        printf("Point(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point& p) { //конструктор копирования
        printf("Point(const Point &p)\n");
        x = p.x;
        y = p.y;
    }
    ~Point() { //деструктор
        printf("%d, %d\n", x, y);
        printf("~Point()\n");
    }
    void move(int dx, int dy) { //метод класса: изменяет координаты
        x = x + dx;
        y = y + dy;
    }
    void reset(); //метод класса: обнуляет координаты
};

void Point::reset() { //реализация метода после объявления класса
    x = 0;
    y = 0;
}

int main()
{
    //динамическое создание объектов
    Point* p = new Point(1, 2);
    Point* p2 = new Point(1, 2);

    p->move(10, 10); //вызываем метод move

    p2->reset(); //вызываем метод reset
    p2->move(10, 10); //вызываем метод move

    delete p;
    delete p2;

    return 0;
}