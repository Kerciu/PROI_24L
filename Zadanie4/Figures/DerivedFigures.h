#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
public:
	Rectangle(const color& fill, const color& stroke);
	inline svgFormat draw() const override;
};

class Circle : public Figure
{
public:
	Circle(const color& fill, const color& stroke);
	inline svgFormat draw() const override;
};

class Line : public Figure
{
public:
	Line(const color& stroke);
	virtual inline svgFormat draw() const override;
	virtual color getFill() const override;
};

