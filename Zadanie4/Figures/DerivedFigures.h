#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
public:
	Rectangle(const color& fill, const size& width);
	Rectangle(const color& fill, const size& width, const size& height);
	Rectangle(const color& fill, const color& stroke, const size& width);
	Rectangle(const color& fill, const color& stroke, const size& width, const size& height);
	Rectangle(const coordinate& x, const coordinate& y,const color& fill, const color& stroke , const size& width);
	Rectangle(const coordinate& x, const coordinate& y, const color& fill, const color& stroke, const size& width, const size& height);
	inline svgFormat draw() const override;

protected:
	size width;
	size height;
};

class Circle : public Figure
{
public:
	Circle(const color& fill, const size& radius);
	Circle(const color& fill, const color& stroke, const size& radius);
	Circle(const coordinate& x, const coordinate& y, const color& fill, const size& radius);
	Circle(const coordinate& x, const coordinate& y, const color& fill, const color& stroke, const size& radius);
	inline svgFormat draw() const override;

protected:
	size radius;
};

class Line : public Figure
{
public:
	Line(const color& stroke);
	Line(const coordinate& x, const coordinate& y, const color& stroke);
	Line(const coordinate& x, const coordinate& y, const color& stroke, const int& strokeWidth);
	Line(const coordinate& x, const coordinate& y, const coordinate& x2, const coordinate& y2, const color& stroke);
	Line(const coordinate& x, const coordinate& y, const coordinate& x2, const coordinate& y2, const color& strok, const int& strokeWidth);
	virtual inline svgFormat draw() const override;
	virtual color getFill() const override;
	virtual bool isFillable() const override;

protected:
	coordinate x2;
	coordinate y2;
	int strokeWidth;
};

class Text : public Figure
{
public:
	typedef std::string family;
	typedef std::string anchor;
	typedef std::string content;

	Text(const color& fill, const content& textContent);
	Text(const color& fill, const content& textContent, const anchor& textAnchor);
	Text(const color& fill, const size& fontSize, const content& textContent, const anchor& textAnchor);
	Text(const color& fill, const family& fontFamily, const content& textContent, const anchor& textAnchor);
	Text(const color& fill, const family& fontFamily, const size& fontSize, const content& textContent, const anchor& textAnchor);
	Text(const coordinate& x, const coordinate& y, const color& fill, const content& textContent, const anchor& textAnchor);
	Text(const coordinate& x, const coordinate& y, const color& fill, const size& fontSize, const content& textContent, const anchor& textAnchor);
	Text(const coordinate& x, const coordinate& y, const color& fill, const family& fontFamily, const content& textContent, const anchor& textAnchor);
	Text(const coordinate& x, const coordinate& y, const color& fill, const family& fontFamily, const size& fontSize, const content& textContent, const anchor& textAnchor);
	inline svgFormat draw() const override;

protected:
	family fontFamily;
	size fontSize;
	anchor textAnchor;
	content textContent;
};

