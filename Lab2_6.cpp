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
    virtual void move(int dx, int dy) { //виртуальный метод класса
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
public:
    ColoredPoint() : Point() { //конструктор без параметров
        printf("ColoredPoint()\n");
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x, y) { //конструктор с параметрами
        printf("ColoredPoint(int x, int y)\n");
        this->color = color;
    }
    ColoredPoint(const ColoredPoint& p) { //конструктор копирования
        printf("ColoredPoint(const Point &p)\n");
        color = p.color;
        x = p.x;
        y = p.y;
    }
    ~ColoredPoint() { //деструктор
        printf("%d, %d, color = %d\n", x, y, color);
        printf("~ColoredPoint()\n");
    }
    void change_color(int new_color) { //метод класса: изменяет значение 
        color = new_color;
    }
};

int main()
{
    //динамическое создание объектов
    Point* p = new Point(1, 2);
    ColoredPoint* p1 = new ColoredPoint(1, 2, 42); //объект помещается в переменную своего класса

    p1->move(10, 20);


    delete p; //вызовутся деструкторы обоих классов
    delete p1; //вызовется деструктор только класса Point

    return 0;
}