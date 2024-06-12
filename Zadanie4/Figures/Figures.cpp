#include "Figure.h"
#include "DerivedFigures.h"
#include "Collection.h"
#include "HtmlParser.h"
#include <iostream>
#include <memory>

int main()
{
    try {
        HtmlParser saver("file.html");
        Rectangle rect1(0, 0, "red", "none", 300, 100);
        Rectangle rect2(10, 10, "none", "blue", 280, 180);
        Circle circle(150, 100, "green", 80);
        Text textLower(280, 180, "blue", "Arial", 20, "24.Z", "end");
        Text textMain(150, 125, "white", "Arial", 60, "SVG", "middle");
        std::unique_ptr<Figure> rect1Ptr = std::make_unique<Rectangle>(std::move(rect1));
        std::unique_ptr<Figure> rect2Ptr = std::make_unique<Rectangle>(std::move(rect2));
        std::unique_ptr<Figure> circlePtr = std::make_unique<Circle>(std::move(circle));
        std::unique_ptr<Figure> textLowerPtr = std::make_unique<Text>(std::move(textLower));
        std::unique_ptr<Figure> textMainPtr = std::make_unique<Text>(std::move(textMain));

        Collection collection;
        collection.addItem(std::move(rect1Ptr));
        collection.addItem(std::move(rect2Ptr));
        collection.addItem(std::move(circlePtr));
        collection.addItem(std::move(textLowerPtr));
        collection.addItem(std::move(textMainPtr));

        std::cout << "Initial collection:\n";
        std::cout << collection;
        saver.saveToSVG(std::move(collection));

        std::cout << "\nCollection after deletion of main text:\n";
        auto deleteElem = collection.deleteItem(textMain);

        std::cout << collection;

        std::cout << "\nPopped item:\n";
        std::unique_ptr<Figure> poppedItem = collection.popItem();
        std::cout << *poppedItem << '\n';

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}
