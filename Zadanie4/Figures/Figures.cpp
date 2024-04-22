#include "Figure.h"
#include "DerivedFigures.h"
#include "Collection.h"
#include "HtmlParser.h"
#include <iostream>
#include <memory>

int main()
{
    HtmlParser saver("file.html");
    std::unique_ptr<Rectangle> rect1 = std::make_unique<Rectangle>(0, 0, "red","none", 300, 100);
    std::unique_ptr<Rectangle> rect2 = std::make_unique<Rectangle>(10, 10, "none", "blue", 280, 180);
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(150, 100, "green", 80);
    // const coordinate& x, const coordinate& y, const color& fill, const family& fontFamily, const size& fontSize, const content& textContent, const anchor& textAnchor
    // Text(const coordinate& x, const coordinate& y, const color& fill, const family& fontFamily, const size& fontSize, const content& textContent, const anchor& textAnchor);
    std::unique_ptr<Text> text_main = std::make_unique<Text>(280, 180, "blue", "Arial", 20, "24.Z", "end");
    std::unique_ptr<Text> text = std::make_unique<Text>(150, 125, "white", "Arial", 60, "SVG", "middle");
    // x, const coordinate& y, const color& fill, const size& fontSize, const content& textContent, const anchor& textAnchor)
    Collection collection;
    collection.addItem(std::move(rect1));
    collection.addItem(std::move(rect2));
    collection.addItem(std::move(circle));
    collection.addItem(std::move(text));
    collection.addItem(std::move(text_main));

    std::cout << collection;

    saver.saveToSVG(std::move(collection));
    return 0;
}
