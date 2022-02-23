/*
    g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    Simple_window win {Point{100,100}, 600, 400, "My window"};

    Axis xa {Axis::x, Point{20,300}, 300, 10, "x axis"};
    xa.label.set_color(Color::blue);
    win.attach(xa);

    Axis ya {Axis::y, Point{20,300}, 250, 10, "y axis"};
    ya.set_color(Color::dark_cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);

    Function sine {sin,0,100,Point{20,150},1000,50,50};
    sine.set_color(Color::dark_green);
    win.attach(sine);

    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash,2));
    win.attach(poly);

    Rectangle r {Point{200,200}, 80, 60};
    r.set_fill_color(Color::cyan);
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,60});
    poly_rect.add(Point{200,90});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{75,75});
    poly_rect.set_style(Line_style(Line_style::dash,4));
    poly_rect.set_fill_color(Color::red);
    win.attach(poly_rect);

    Text t {Point{100,150}, "Goodbye, graphical world!"};
    t.set_font(Font::times_bold);
    t.set_font_size(15);
    win.attach(t);

    Image ii {Point{450,250},"100.jpg"};
    win.attach(ii);

    Circle c {Point{500,150},50};
    c.set_color(Color::dark_magenta);
    win.attach(c);

    Ellipse e {Point{500,150}, 25,75};
    win.attach(e);

    Mark m {Point{500,150},'o'};
    win.attach(m);

    win.wait_for_button();
}