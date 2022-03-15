/*
    g++ drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Graph.h"
#include "Simple_window.h"

double one(double x) { return 1; }

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
    Simple_window win{ Point{100,100},600,600,"Function graphs" };

    Axis xa{ Axis::x, Point{100,300}, 400, 20, "“1 = = 20 pixels”" };
    xa.set_color(Color::red);
    win.attach(xa);

    Axis ya{ Axis::y, Point{300,500}, 400, 20, "“1 = = 20 pixels”" };
    ya.set_color(Color::red);
    win.attach(ya);

    const Point orig { 300,300 };
    constexpr int r_min = -10; // range [–10:11)
    constexpr int r_max = 11;
    constexpr int n_points = 400; // number of points
    constexpr int x_scale = 20; // scaling
    constexpr int y_scale = 20;

    Function s (one, r_min, r_max, orig, n_points, x_scale, y_scale);
    s.set_color(Color::black);
    Function s2 (slope, r_min, r_max, orig, n_points, x_scale, y_scale);
    s2.set_color(Color::black);
    Text ts2{ Point{100,390},"x/2" };
    ts2.set_color(Color::black);
    Function s3 (square, r_min, r_max, orig, n_points, x_scale, y_scale);
    s3.set_color(Color::black);
    Function s4(cos, r_min, r_max, orig, n_points, x_scale, y_scale);
    s4.set_color(Color::blue);
    Function s5(sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale);
    s5.set_color(Color::black);

    win.attach(s);
    win.attach(s2);
    win.attach(ts2);
    win.attach(s3);
    win.attach(s4);
    win.attach(s5);

    win.wait_for_button();
}