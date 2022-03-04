/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win {Point{100,100}, 800, 1000, "Window"};
	
	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;
	
	Lines grid;
	for (int x=x_grid; x<x_size; x+=x_grid)
	grid.add(Point{x,0},Point{x,y_size});
	for (int y = y_grid; y<y_size; y+=y_grid)
	grid.add(Point{0,y},Point{x_size,y});
	
	Rectangle r0 {Point{0,0}, 100, 100};
	Rectangle r1 {Point{100,100}, 100, 100};
	Rectangle r2 {Point{200,200}, 100, 100};
	Rectangle r3 {Point{300,300}, 100, 100};
	Rectangle r4 {Point{400,400}, 100, 100};
	Rectangle r5 {Point{500,500}, 100, 100};
	Rectangle r6 {Point{600,600}, 100, 100};
	Rectangle r7 {Point{700,700}, 100, 100};
	r0.set_fill_color(Color::red);
	r1.set_fill_color(Color::red);
	r2.set_fill_color(Color::red);
	r3.set_fill_color(Color::red);
	r4.set_fill_color(Color::red);
	r5.set_fill_color(Color::red);
	r6.set_fill_color(Color::red);
	r7.set_fill_color(Color::red);
	
	Image i1 {Point{200,0},"200.jpg"};
	Image i2 {Point{0,600},"200.jpg"};
	Image i3 {Point{600,400},"200.jpg"};
	
	win.attach(grid);
	win.attach(r0);
	win.attach(r1);
	win.attach(r2);
	win.attach(r3);
	win.attach(r4);
	win.attach(r5);
	win.attach(r6);
	win.attach(r7);
	win.attach(i1);
	win.attach(i2);
	win.attach(i3);
	
	while(true){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
		Image ii {Point{j*100,i*100},"100.jpg"};
		win.attach(ii);
		win.set_label("Window");
		win.wait_for_button();
		}
	}
	}
}
