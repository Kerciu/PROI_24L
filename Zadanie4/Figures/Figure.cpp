#include "Figure.h"

Figure::Figure() : fill(""), stroke("") { }
Figure::Figure(const color& f) : fill(f), stroke("") { }
Figure::Figure(const color& f, const color& s) : fill(f), stroke(s) { }

Figure::~Figure() { }

Figure::svgFormat Figure::draw()
{
    // TODO SVG format
    return svgFormat();
}

Figure::color Figure::getFill() {
    return fill;
}

Figure::color Figure::getStroke() {
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
