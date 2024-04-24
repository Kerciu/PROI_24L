#pragma once
#include <string>

class Figure
{
public:
	typedef std::string color;
	typedef std::string svgFormat;
	typedef int size;
	typedef int coordinate;

	Figure();
	Figure(const color& colorValue);
	Figure(const color& fill, const color& stroke);
	Figure(const coordinate& x, const color& colorValue);
	Figure(const coordinate& x, const coordinate& y, const color& colorValue);
	Figure(const coordinate& x, const color& fill, const color& stroke);
	Figure(const coordinate& x, const coordinate& y, const color& fill, const color& stroke);
	inline virtual ~Figure() = default;

	virtual inline svgFormat draw() const;
	virtual inline size getX() const;
	virtual inline size getY() const;
	virtual inline color getFill() const;
	virtual inline color getStroke() const;
	virtual inline void setX(const size& newX);
	virtual inline void setY(const size& newY);
	virtual inline void setFill(const color& f);
	virtual inline void setStroke(const color& s);
	bool operator==(const Figure& other) const;

protected:
	coordinate x;
	coordinate y;
	color fill;
	color stroke;
	color unique;

	virtual inline bool isFillable() const;
};

