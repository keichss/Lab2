#include <iostream>
#include "conio.h"

class Point {
protected:
    int x, y;
public:
    Point() { //конструктор без параметров
        printf("Point()\n");
        x = 1;
        y = 2;
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

class ColoredPoint : public Point {
protected:
    int color;
};

int main()
{
    //динамическое создание объектов
    Point *p = new Point();
    ColoredPoint *p1 = new ColoredPoint(); //сработает конструктор класса Point

    delete p; 
    delete p1; //вызовется деструктор класса Point

    return 0;
}
