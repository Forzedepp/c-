#include <graphics.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

class Point {
protected:
    int x, y;
    int color;
public:
    Point(int xn, int yn, int c) : x(xn), y(yn), color(c) {}
    virtual void show() = 0;
    virtual void hide() = 0;
    void locate(int &xl, int &yl) { xl = x; yl = y; }
    void fly(int step);
};

void Point::fly(int step) {
    int xx, yy;
    show();
    srand(time(0));
    do {
        locate(xx, yy);
        do { xx += (rand() % 3 - 1) * step; } while (xx <= 0 || xx >= getmaxx());
        do { yy += (rand() % 3 - 1) * step; } while (yy <= 0 || yy >= getmaxy());
        hide();
        x = xx; y = yy;
        show();
        delay(300);
    } while (!kbhit());
    getch();
}

class Circle : public Point {
protected:
    int radius;
public:
    Circle(int xn, int yn, int r, int c) : Point(xn, yn, c), radius(r) {}
    void show() override {
        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        fillellipse(x, y, radius, radius);
    }
    void hide() override {
        setcolor(getbkcolor());
        setfillstyle(SOLID_FILL, getbkcolor());
        fillellipse(x, y, radius, radius);
    }
};

class Ring : public Circle {
private:
    int width;
public:
    Ring(int xn, int yn, int r, int c, int w) : Circle(xn, yn, r, c), width(w) {}
    void show() override {
        Circle::show();
        setfillstyle(SOLID_FILL, getbkcolor());
        fillellipse(x, y, radius - width, radius - width);
    }
};

int main() {
    int d = DETECT, m;
    initgraph(&d, &m, "");
    setbkcolor(8);
    cleardevice();

    Circle testCircle(150, 40, 50, 1);
    Ring testRing(450, 80, 90, 50, 10);

    testCircle.fly(100);
    testRing.fly(60);
    testCircle.fly(60);

    testCircle.hide();
    testRing.hide();
    closegraph();
    return 0;
}
