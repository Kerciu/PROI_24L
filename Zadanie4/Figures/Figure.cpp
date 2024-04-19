#include "Figure.h"
#include "Figure.h"
#include "Figure.h"
#include "Figure.h"

Figure::~Figure() { }

Figure::Figure() : fill(""), stroke("") { }

Figure::Figure(const color& stroke) : fill(""), stroke(stroke) { }

Figure::Figure(const color& fill, const color& stroke) : fill(fill), stroke(stroke) { }

Figure::svgFormat Figure::draw() const
{
    return svgFormat("");
}

Figure::color Figure::getFill() const {
    return fill;
}

Figure::color Figure::getStroke() const {
    return stroke;
}

void Figure::setFill(const color& f)
{
    fill = f;
}

void Figure::setStroke(const color& s)
{
    stroke = s;
}
