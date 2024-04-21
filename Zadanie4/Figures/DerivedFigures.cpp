#include "DerivedFigures.h"

Rectangle::Rectangle(const color& fill, const size& width) : Figure(fill, ""), width(width), height(width) { }

Rectangle::Rectangle(const color& fill, const size& width, const size& height) : Figure(fill, ""), width(width), height(height) { }

Rectangle::Rectangle(const color& fill, const color& stroke, const size& width) : Figure(fill, stroke), width(width), height(width) { }

Rectangle::Rectangle(const color& fill, const color& stroke, const size& width, const size& height) : Figure(fill, stroke), width(width), height(height) { }

Rectangle::Rectangle(const coordinate& x, const coordinate& y, const color& fill, const color& stroke, const size& width)
	: Figure(x, y, fill, stroke), width(width), height(width) { }

Rectangle::Rectangle(const coordinate& x, const coordinate& y, const color& fill, const color& stroke, const size& width, const size& height)
	: Figure(x, y, fill, stroke), width(width), height(height) { }

Circle::Circle(const color& fill, const size& radius) : Figure(fill, ""), radius(radius) { }

Circle::Circle(const color& fill, const color& stroke, const size& radius) : Figure(fill, stroke), radius(radius) { }

Circle::Circle(const coordinate& x, const coordinate& y, const color& fill, const size& radius)
	: Figure(x, y, fill), radius(radius) { }

Circle::Circle(const coordinate& x, const coordinate& y, const color& fill, const color& stroke, const size& radius)
	: Figure(x, y, fill, stroke), radius(radius) { }

Line::Line(const color& stroke) : Figure(stroke), x2(0), y2(0), strokeWidth(1) { }

Line::Line(const coordinate& x, const coordinate& y, const color& stroke)
	: Figure(x, y, stroke), x2(0), y2(0), strokeWidth(1) { }

Line::Line(const coordinate& x, const coordinate& y, const color& stroke, const int& strokeWidth)
	: Figure(x, y, stroke), x2(0), y2(0), strokeWidth(strokeWidth) { }

Line::Line(const coordinate& x, const coordinate& y, const coordinate& x2, const coordinate& y2, const color& stroke)
	: Figure(x, y, stroke), x2(x2), y2(y2), strokeWidth(1) { }

Line::Line(const coordinate& x, const coordinate& y, const coordinate& x2, const coordinate& y2, const color& stroke, const int& strokeWidth)
	: Figure(x, y, stroke), x2(x2), y2(y2), strokeWidth(strokeWidth) { }

Text::Text(const color& fill) : Figure(fill, "") { }

Text::Text(const color& fill, const size& fontSize)
	 : Figure(fill), fontSize(fontSize), fontFamily("Arial") { }

Text::Text(const color& fill, const family& fontFamily)
	 : Figure(fill), fontSize(11), fontFamily(fontFamily) { }

Text::Text(const color& fill, const family& fontFamily, const size& fontSize)
	 : Figure(fill), fontSize(fontSize), fontFamily(fontFamily) { }

Text::Text(const coordinate& x, const coordinate& y, const color& fill)
	: Figure(x, y, fill), fontSize(11), fontFamily("Arial") { }

Text::Text(const coordinate& x, const coordinate& y, const color& fill, const size& fontSize)
	: Figure(x, y, fill), fontSize(fontSize), fontFamily("Arial") { }

Text::Text(const coordinate& x, const coordinate& y, const color& fill, const family& fontFamily)
	: Figure(x, y, fill), fontSize(11), fontFamily(fontFamily) { }

Text::Text(const coordinate& x, const coordinate& y, const color& fill, const family& fontFamily, const size& fontSize)
	: Figure(x, y, fill), fontSize(fontSize), fontFamily(fontFamily) { }

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

inline Figure::svgFormat Text::draw() const
{
	Figure::svgFormat formatStr = "<text x = \"150\" y = \"125\" font - size = \"60\" text - anchor = \"middle\" fill = \"white\">SVG< / text>";
	return formatStr;
}

Figure::color Line::getFill() const
{
	return Figure::color("");
}

bool Line::isFillable() const
{
	return false;
}


