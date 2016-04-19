#include <iostream>
#include "Image.h"
#include "Vector.h"
#include "Matrix.h"
#include "stdafx.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include <cmath>
#include <math.h>
#include "Canvas.h"

//inkluder andre headerfiler du lager
using namespace std;

int main()
{

	double PI = 3.141592654;

	Image bilde(100, 100);
	Color fyllFarge(0, 0, 50);
	Color prikkFarge(255, 111, 0);
	bilde.fill(fyllFarge);

	Coordinate nedre(55, 60);
	Coordinate ovre(65, 70);
	Rectangle rectangle(nedre, ovre, prikkFarge);

	Coordinate nedre1(35, 60);
	Coordinate ovre2(45, 70);
	Rectangle rectangle1(nedre1, ovre2, prikkFarge);

	Coordinate sentrum(50, 50);
	unsigned int radius = 30;
	double angles = 2 * PI;
	Interval angle(-PI, PI);

	Circle sirkel(sentrum, radius, angle, prikkFarge);

	Coordinate sentrum1(50,50);

	unsigned int radius1 = 20;
	double angles1 = -PI;
	Circle sirkel1(sentrum1, radius1, angles1, prikkFarge);
	
	Coordinate start(0, 0);
	Coordinate stop(200, 100);
	Line l(start, stop, prikkFarge);
	l.draw(bilde);

	Canvas pic;
	pic.addShape(&rectangle);
	pic.addShape(&rectangle1);
	pic.addShape(&sirkel);
	pic.addShape(&sirkel1);
	pic.rasterizeTo(bilde);

	saveImage(bilde, "bilde2.bmp");


	system("pause");
	return 0;
}
