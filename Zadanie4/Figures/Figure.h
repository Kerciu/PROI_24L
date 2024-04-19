#pragma once
#include <string>

class Figure
{
protected:
	typedef std::string color;
	typedef std::string svgFormat;

	color fill;
	color stroke;

public:
	Figure() { }
	Figure(const color& s) { }
	Figure(const color& f) { }
	Figure(const color& f, const color& s) { }

	virtual ~Figure() { }

	virtual svgFormat draw();
	virtual void setFill(const color& f);
	virtual void setStroke(const color& s);
};

