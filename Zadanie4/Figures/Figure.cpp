#include "Figure.h"

Figure::Figure() : fill(""), stroke("") { }
Figure::Figure(const color& s) : fill(""), stroke(s) { }
Figure::Figure(const color& f) : fill(f), stroke("") { }
Figure::Figure(const color& f, const color& s) : fill(f), stroke(s) { }

Figure::~Figure() { }

Figure::svgFormat Figure::draw()
{
    // TODO SVG format
    return svgFormat();
}

void Figure::setFill(const color& f)
{
    fill = f;
}

void Figure::setStroke(const color& s)
{
    stroke = s;
}
