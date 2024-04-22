#include "Figure.h"
#include "DerivedFigures.h"
#include "Collection.h"
#include "HtmlParser.h"
#include <iostream>
#include <memory>

int main()
{
    HtmlParser saver("file.html");
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(150, 100, "blue", "black", 60);
    // const coordinate& x, const coordinate& y, const color& fill, const family& fontFamily, const size& fontSize, const content& textContent, const anchor& textAnchor
    std::unique_ptr<Text> text = std::make_unique<Text>(150, 100, "yellow", "Arial", 26, "Some TEXT", "middle");
    std::cout << circle->draw() << '\n' << text->draw() << '\n';

    Collection collection;
    collection.addItem(std::move(circle));
    collection.addItem(std::move(text));

    std::cout << collection;

    saver.saveToSVG(std::move(collection));
    return 0;
}
