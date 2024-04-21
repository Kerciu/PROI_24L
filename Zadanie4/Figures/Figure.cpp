#include "Figure.h"
#include "Figure.h"
#include "Figure.h"
#include "Figure.h"

Figure::Figure() : fill(""), stroke("") { }

Figure::Figure(const color& stroke) : fill(""), stroke(stroke) { }

Figure::Figure(const color& fill, const color& stroke) : fill(fill), stroke(stroke) { }

inline Figure::svgFormat Figure::draw() const
{
    return svgFormat("");
}

inline Figure::color Figure::getFill() const {
    return fill;
}

inline Figure::color Figure::getStroke() const {
    return stroke;
}

inline void Figure::setFill(const color& f)
{
    fill = f;
}

inline void Figure::setStroke(const color& s)
{
    stroke = s;
}

bool Figure::operator==(const Figure& other) const
{
    return (this->fill == other.fill) && (this->stroke == other.stroke);
}
