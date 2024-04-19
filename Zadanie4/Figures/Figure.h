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

	virtual inline svgFormat draw() const = 0;
	virtual inline color getFill() const;
	virtual inline color getStroke() const;
	virtual inline void setFill(const color& f);
	virtual inline void setStroke(const color& s);

protected:
	color fill;
	color stroke;

};

