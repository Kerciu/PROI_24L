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
	inline Figure() { }
	inline Figure(const color& f) { }
	inline Figure(const color& f, const color& s) { }

	inline virtual ~Figure() { }

	virtual svgFormat draw();
	virtual color getFill();
	virtual color getStroke();
	virtual void setFill(const color& f);
	virtual void setStroke(const color& s);
};

