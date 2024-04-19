#pragma once
#include <string>

class Figure
{
public:
	typedef std::string color;
	typedef std::string svgFormat;

	Figure();
	Figure(const color& stroke);
	Figure(const color& fill, const color& stroke);
	inline virtual ~Figure() = default;

	virtual svgFormat draw() const = 0;
	virtual color getFill() const;
	virtual color getStroke() const;
	virtual void setFill(const color& f);
	virtual void setStroke(const color& s);

protected:
	color fill;
	color stroke;

};

