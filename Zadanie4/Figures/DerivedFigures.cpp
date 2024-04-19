#include "DerivedFigures.h"

Rectangle::Rectangle(const color& fill, const color& stroke) : Figure(fill, stroke) { }

Circle::Circle(const color& fill, const color& stroke) : Figure(fill, stroke) { }

Line::Line(const color& stroke) : Figure(stroke) { }

inline Figure::svgFormat Rectangle::draw() const
{
	//TODO add x, y (optional), width, height, 
	 Figure::svgFormat formatStr = "<rect width=\"300\" height=\"100\" fill=\"red\" />";
	 return formatStr;
}

inline Figure::svgFormat Circle::draw() const
{
	//TODO add cx, cy, r parameters for circle, make stroke optional
	Figure::svgFormat formatStr = "<circle cx=\"150\" cy=\"100\" r=\"80\" fill=\"green\" />";
	return formatStr;
}

inline Figure::svgFormat Line::draw() const
{
	//TODO add x1, y1, x2, y2, stroke-width
	Figure::svgFormat formatStr = "<line x1=\"50\" y1=\"50\" x2=\"250\" y2=\"150\" stroke=\"black\" stroke-width=\"2\" />";
	return formatStr;
}

Figure::color Line::getFill() const
{
	return Figure::color("");
}
