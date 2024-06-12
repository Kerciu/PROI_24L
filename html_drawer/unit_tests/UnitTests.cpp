#include <memory>
#include <string>
#include <fstream>
#include "../src/Parser/HtmlParser.h"
#include "../src/Figure/Figure.h"
#include "../src/Collection/Collection.h"
#include "../src/Derived/DerivedFigures.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:

		TEST_METHOD(RectangleConstructorWidthOnly) {
			Figure::color fill = "blue";
			Figure::size width = 10;
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(fill, width);
			Assert::AreEqual(rect->getFill().c_str(), "blue");
			Assert::AreEqual(rect->getWidth(), 10);
			Assert::AreEqual(rect->getHeight(), 10);
		}

		TEST_METHOD(RectangleConstructorWidthAndHeight) {
			Figure::color fill = "red";
			Figure::size width = 5;
			Figure::size height = 15;
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(fill, width, height);
			Assert::AreEqual(rect->getFill().c_str(), "red");
			Assert::AreEqual(rect->getWidth(), 5);
			Assert::AreEqual(rect->getHeight(), 15);
		}

		TEST_METHOD(RectangleConstructorWidthWithStroke) {
			Figure::color fill = "green";
			Figure::color stroke = "yellow";
			Figure::size width = 8;
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(fill, stroke, width);
			Assert::AreEqual(rect->getFill().c_str(), "green");
			Assert::AreEqual(rect->getStroke().c_str(), "yellow");
			Assert::AreEqual(rect->getWidth(), 8);
			Assert::AreEqual(rect->getHeight(), 8);
		}

		TEST_METHOD(RectangleConstructorWidthHeightWithStroke) {
			Figure::color fill = "purple";
			Figure::color stroke = "orange";
			Figure::size width = 12;
			Figure::size height = 9;
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(fill, stroke, width, height);
			Assert::AreEqual(rect->getFill().c_str(), "purple");
			Assert::AreEqual(rect->getStroke().c_str(), "orange");
			Assert::AreEqual(rect->getWidth(), 12);
			Assert::AreEqual(rect->getHeight(), 9);
		}

		TEST_METHOD(RectangleConstructorWithCoordinatesWidthWithStroke) {
			Figure::coordinate x = 3;
			Figure::coordinate y = 7;
			Figure::color fill = "cyan";
			Figure::color stroke = "magenta";
			Figure::size width = 20;
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(x, y, fill, stroke, width);
			Assert::AreEqual(rect->getX(), 3);
			Assert::AreEqual(rect->getY(), 7);
			Assert::AreEqual(rect->getFill().c_str(), "cyan");
			Assert::AreEqual(rect->getStroke().c_str(), "magenta");
			Assert::AreEqual(rect->getWidth(), 20);
			Assert::AreEqual(rect->getHeight(), 20);
		}

		TEST_METHOD(RectangleConstructorWithCoordinatesWidthHeightWithStroke) {
			Figure::coordinate x = 12;
			Figure::coordinate y = 8;
			Figure::color fill = "black";
			Figure::color stroke = "white";
			Figure::size width = 15;
			Figure::size height = 25;
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(x, y, fill, stroke, width, height);
			Assert::AreEqual(rect->getX(), 12);
			Assert::AreEqual(rect->getY(), 8);
			Assert::AreEqual(rect->getFill().c_str(), "black");
			Assert::AreEqual(rect->getStroke().c_str(), "white");
			Assert::AreEqual(rect->getWidth(), 15);
			Assert::AreEqual(rect->getHeight(), 25);
		}

		TEST_METHOD(RectangleSetters) {
			Figure::color fill = "blue";
			Figure::size width = 10;
			Figure::size height = 20;
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(fill, width, height);
			rect->setFill("red");
			rect->setWidth(15);
			rect->setHeight(25);
			Assert::AreEqual(rect->getFill().c_str(), "red");
			Assert::AreEqual(rect->getWidth(), 15);
			Assert::AreEqual(rect->getHeight(), 25);
		}

		TEST_METHOD(CircleConstructorRadiusOnly) {
			Figure::color fill = "blue";
			Figure::size radius = 10;
			std::unique_ptr<Circle> circle = std::make_unique<Circle>(fill, radius);
			Assert::AreEqual(circle->getFill().c_str(), "blue");
			Assert::AreEqual(circle->getRadius(), 10);
		}

		TEST_METHOD(CircleConstructorWithStroke) {
			Figure::color fill = "green";
			Figure::color stroke = "yellow";
			Figure::size radius = 8;
			std::unique_ptr<Circle> circle = std::make_unique<Circle>(fill, stroke, radius);
			Assert::AreEqual(circle->getFill().c_str(), "green");
			Assert::AreEqual(circle->getStroke().c_str(), "yellow");
			Assert::AreEqual(circle->getRadius(), 8);
		}

		TEST_METHOD(CircleConstructorWithCoordinates) {
			Figure::coordinate x = 3;
			Figure::coordinate y = 7;
			Figure::color fill = "cyan";
			Figure::size radius = 20;
			std::unique_ptr<Circle> circle = std::make_unique<Circle>(x, y, fill, radius);
			Assert::AreEqual(circle->getX(), 3);
			Assert::AreEqual(circle->getY(), 7);
			Assert::AreEqual(circle->getFill().c_str(), "cyan");
			Assert::AreEqual(circle->getRadius(), 20);
		}

		TEST_METHOD(CircleConstructorWithCoordinatesAndStroke) {
			Figure::coordinate x = 12;
			Figure::coordinate y = 8;
			Figure::color fill = "black";
			Figure::color stroke = "white";
			Figure::size radius = 15;
			std::unique_ptr<Circle> circle = std::make_unique<Circle>(x, y, fill, stroke, radius);
			Assert::AreEqual(circle->getX(), 12);
			Assert::AreEqual(circle->getY(), 8);
			Assert::AreEqual(circle->getFill().c_str(), "black");
			Assert::AreEqual(circle->getStroke().c_str(), "white");
			Assert::AreEqual(circle->getRadius(), 15);
		}

		TEST_METHOD(CircleSetters) {
			Figure::color fill = "blue";
			Figure::size radius = 10;
			std::unique_ptr<Circle> circle = std::make_unique<Circle>(fill, radius);
			circle->setFill("yellow");
			circle->setRadius(20);
			Assert::AreEqual(circle->getFill().c_str(), "yellow");
			Assert::AreEqual(circle->getRadius(), 20);
		}

		TEST_METHOD(LineConstructorStrokeOnly) {
			Figure::color stroke = "red";
			std::unique_ptr<Line> line = std::make_unique<Line>(stroke);
			Assert::AreEqual(line->getStroke().c_str(), "red");
			Assert::AreEqual(line->getX(), 150);
			Assert::AreEqual(line->getY(), 100);
			Assert::AreEqual(line->getX2(), 0);
			Assert::AreEqual(line->getY2(), 0);
			Assert::AreEqual(line->getStrokeWidth(), 1);
		}

		TEST_METHOD(LineConstructorWithCoordinatesAndStroke) {
			Figure::coordinate x = 5;
			Figure::coordinate y = 3;
			Figure::color stroke = "blue";
			std::unique_ptr<Line> line = std::make_unique<Line>(x, y, stroke);
			Assert::AreEqual(line->getX(), 5);
			Assert::AreEqual(line->getY(), 3);
			Assert::AreEqual(line->getStroke().c_str(), "blue");
			Assert::AreEqual(line->getX2(), 0);
			Assert::AreEqual(line->getY2(), 0);
			Assert::AreEqual(line->getStrokeWidth(), 1);
		}

		TEST_METHOD(LineConstructorWithCoordinatesStrokeAndWidth) {
			Figure::coordinate x = 8;
			Figure::coordinate y = 10;
			Figure::color stroke = "green";
			int strokeWidth = 2;
			std::unique_ptr<Line> line = std::make_unique<Line>(x, y, stroke, strokeWidth);
			Assert::AreEqual(line->getX(), 8);
			Assert::AreEqual(line->getY(), 10);
			Assert::AreEqual(line->getStroke().c_str(), "green");
			Assert::AreEqual(line->getX2(), 0);
			Assert::AreEqual(line->getY2(), 0);
			Assert::AreEqual(line->getStrokeWidth(), 2);
		}

		TEST_METHOD(LineConstructorWithCoordinatesAndEndpoints) {
			Figure::coordinate x1 = 2;
			Figure::coordinate y1 = 4;
			Figure::coordinate x2 = 6;
			Figure::coordinate y2 = 8;
			Figure::color stroke = "yellow";
			std::unique_ptr<Line> line = std::make_unique<Line>(x1, y1, x2, y2, stroke);
			Assert::AreEqual(line->getX(), 2);
			Assert::AreEqual(line->getY(), 4);
			Assert::AreEqual(line->getX2(), 6);
			Assert::AreEqual(line->getY2(), 8);
			Assert::AreEqual(line->getStroke().c_str(), "yellow");
			Assert::AreEqual(line->getStrokeWidth(), 1);
		}

		TEST_METHOD(LineConstructorWithAllParameters) {
			Figure::coordinate x1 = 3;
			Figure::coordinate y1 = 7;
			Figure::coordinate x2 = 5;
			Figure::coordinate y2 = 9;
			Figure::color stroke = "orange";
			int strokeWidth = 3;
			std::unique_ptr<Line> line = std::make_unique<Line>(x1, y1, x2, y2, stroke, strokeWidth);
			Assert::AreEqual(line->getX(), 3);
			Assert::AreEqual(line->getY(), 7);
			Assert::AreEqual(line->getX2(), 5);
			Assert::AreEqual(line->getY2(), 9);
			Assert::AreEqual(line->getStroke().c_str(), "orange");
			Assert::AreEqual(line->getStrokeWidth(), 3);
		}

		TEST_METHOD(LineSetters) {
			Figure::color stroke = "black";
			std::unique_ptr<Line> line = std::make_unique<Line>(stroke);
			line->setStroke("white");
			line->setStrokeWidth(2);
			Assert::AreEqual(line->getStroke().c_str(), "white");
			Assert::AreEqual(line->getStrokeWidth(), 2);
		}

		TEST_METHOD(TextConstructorFillAndTextContent) {
			Figure::color fill = "blue";
			Text::content textContent = "Hello";
			std::unique_ptr<Text> text = std::make_unique<Text>(fill, textContent);
			Assert::AreEqual(text->getFill().c_str(), "blue");
			Assert::AreEqual(text->getFontFamily().c_str(), "Arial");
			Assert::AreEqual(text->getFontSize(), 11);
			Assert::AreEqual(text->getTextContent().c_str(), "Hello");
			Assert::AreEqual(text->getTextAnchor().c_str(), "");
		}

		TEST_METHOD(TextConstructorFillTextContentAndTextAnchor) {
			Figure::color fill = "red";
			Text::content textContent = "World";
			Text::anchor textAnchor = "start";
			std::unique_ptr<Text> text = std::make_unique<Text>(fill, textContent, textAnchor);
			Assert::AreEqual(text->getFill().c_str(), "red");
			Assert::AreEqual(text->getFontFamily().c_str(), "Arial");
			Assert::AreEqual(text->getFontSize(), 11);
			Assert::AreEqual(text->getTextContent().c_str(), "World");
			Assert::AreEqual(text->getTextAnchor().c_str(), "start");
		}

		TEST_METHOD(TextConstructorFillFontSizeTextContentAndTextAnchor) {
			Figure::color fill = "green";
			Text::family fontFamily = "Arial";
			Text::content textContent = "Banana";
			Text::anchor textAnchor = "middle";
			Text text(fill, fontFamily, textContent, textAnchor);
			std::unique_ptr<Text> textPtr = std::make_unique<Text>(std::move(text));
			Assert::AreEqual(textPtr->getFill().c_str(), "green");
			Assert::AreEqual(textPtr->getFontFamily().c_str(), "Arial");
			Assert::AreEqual(textPtr->getTextContent().c_str(), "Banana");
			Assert::AreEqual(textPtr->getTextAnchor().c_str(), "middle");
		}

		TEST_METHOD(TextConstructorFillFontFamilyTextContentAndTextAnchor) {
			Figure::color fill = "orange";
			Text::family fontFamily = "Helvetica";
			Text::content textContent = "Something";
			Text::anchor textAnchor = "end";
			std::unique_ptr<Text> text = std::make_unique<Text>(fill, fontFamily, textContent, textAnchor);
			Assert::AreEqual(text->getFill().c_str(), "orange");
			Assert::AreEqual(text->getFontFamily().c_str(), "Helvetica");
			Assert::AreEqual(text->getFontSize(), 11);
			Assert::AreEqual(text->getTextContent().c_str(), "Something");
			Assert::AreEqual(text->getTextAnchor().c_str(), "end");
		}

		TEST_METHOD(TextConstructorFillFontFamilyFontSizeTextContentAndTextAnchor) {
			Figure::color fill = "purple";
			Text::family fontFamily = "Times New Roman";
			Figure::size fontSize = 18;
			Text::content textContent = "Poland";
			Text::anchor textAnchor = "start";
			std::unique_ptr<Text> text = std::make_unique<Text>(fill, fontFamily, fontSize, textContent, textAnchor);
			Assert::AreEqual(text->getFill().c_str(), "purple");
			Assert::AreEqual(text->getFontFamily().c_str(), "Times New Roman");
			Assert::AreEqual(text->getFontSize(), 18);
			Assert::AreEqual(text->getTextContent().c_str(), "Poland");
			Assert::AreEqual(text->getTextAnchor().c_str(), "start");
		}

		TEST_METHOD(TextConstructorWithCoordinatesFillTextContentAndTextAnchor) {
			Figure::coordinate x = 10;
			Figure::coordinate y = 20;
			Figure::color fill = "yellow";
			Text::content textContent = "content";
			Text::anchor textAnchor = "middle";
			std::unique_ptr<Text> text = std::make_unique<Text>(x, y, fill, textContent, textAnchor);
			Assert::AreEqual(text->getX(), 10);
			Assert::AreEqual(text->getY(), 20);
			Assert::AreEqual(text->getFill().c_str(), "yellow");
			Assert::AreEqual(text->getFontFamily().c_str(), "Arial");
			Assert::AreEqual(text->getFontSize(), 11);
			Assert::AreEqual(text->getTextContent().c_str(), "content");
			Assert::AreEqual(text->getTextAnchor().c_str(), "middle");
		}

		TEST_METHOD(TextConstructorWithCoordinatesFillFontSizeTextContentAndTextAnchor) {
			Figure::coordinate x = 15;
			Figure::coordinate y = 25;
			Figure::color fill = "pink";
			Figure::size fontSize = 16;
			Text::content textContent = "x86-64";
			Text::anchor textAnchor = "end";
			std::unique_ptr<Text> text = std::make_unique<Text>(x, y, fill, fontSize, textContent, textAnchor);
			Assert::AreEqual(text->getX(), 15);
			Assert::AreEqual(text->getY(), 25);
			Assert::AreEqual(text->getFill().c_str(), "pink");
			Assert::AreEqual(text->getFontFamily().c_str(), "Arial");
			Assert::AreEqual(text->getFontSize(), 16);
			Assert::AreEqual(text->getTextContent().c_str(), "x86-64");
			Assert::AreEqual(text->getTextAnchor().c_str(), "end");
		}

		TEST_METHOD(TextConstructorWithCoordinatesFillFontFamilyTextContentAndTextAnchor) {
			Figure::coordinate x = 30;
			Figure::coordinate y = 40;
			Figure::color fill = "cyan";
			Text::family fontFamily = "Verdana";
			Text::content textContent = "For these tests max points are inevitable";
			Text::anchor textAnchor = "start";
			std::unique_ptr<Text> text = std::make_unique<Text>(x, y, fill, fontFamily, textContent, textAnchor);
			Assert::AreEqual(text->getX(), 30);
			Assert::AreEqual(text->getY(), 40);
			Assert::AreEqual(text->getFill().c_str(), "cyan");
			Assert::AreEqual(text->getFontFamily().c_str(), "Verdana");
			Assert::AreEqual(text->getFontSize(), 11);
			Assert::AreEqual(text->getTextContent().c_str(), "For these tests max points are inevitable");
			Assert::AreEqual(text->getTextAnchor().c_str(), "start");
		}

		TEST_METHOD(TextConstructorWithAllParameters) {
			Figure::coordinate x = 50;
			Figure::coordinate y = 60;
			Figure::color fill = "brown";
			Text::family fontFamily = "Courier New";
			Figure::size fontSize = 20;
			Text::content textContent = "Text";
			Text::anchor textAnchor = "middle";
			std::unique_ptr<Text> text = std::make_unique<Text>(x, y, fill, fontFamily, fontSize, textContent, textAnchor);
			Assert::AreEqual(text->getX(), 50);
			Assert::AreEqual(text->getY(), 60);
			Assert::AreEqual(text->getFill().c_str(), "brown");
			Assert::AreEqual(text->getFontFamily().c_str(), "Courier New");
			Assert::AreEqual(text->getFontSize(), 20);
			Assert::AreEqual(text->getTextContent().c_str(), "Text");
			Assert::AreEqual(text->getTextAnchor().c_str(), "middle");
		}

		TEST_METHOD(TextSetters) {
			Text::content content = "Sample text";
			Figure::color fill = "black";
			std::unique_ptr<Text> text = std::make_unique<Text>(fill, content);
			text->setFill("blue");
			text->setTextContent("New text");
			Assert::AreEqual(text->getFill().c_str(), "blue");
			Assert::AreEqual(text->getTextContent().c_str(), "New text");
		}
		
		TEST_METHOD(RectangleDraw) {
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>("red", 10, 20);
			Assert::AreEqual(rect->draw().c_str(), "<rect x=\"150\" y=\"100\" width=\"10\" height=\"20\" fill=\"red\" />");
		}

		TEST_METHOD(CircleDraw) {
			std::unique_ptr<Circle> circle = std::make_unique<Circle>("blue", 15);
			Assert::AreEqual(circle->draw().c_str(), "<circle cx=\"150\" cy=\"100\" r=\"15\" fill=\"blue\" />");
		}

		TEST_METHOD(LineDraw) {
			std::unique_ptr<Line> line = std::make_unique<Line>("black");
			line->setX(10);
			line->setY(10);
			line->setX2(50);
			line->setY2(50);
			line->setStroke("black");
			Assert::AreEqual(line->draw().c_str(), "<line x1=\"10\" y1=\"10\" x2=\"50\" y2=\"50\" stroke=\"black\" />");
		}

		TEST_METHOD(TextDraw) {
			std::unique_ptr<Text> text = std::make_unique<Text>("green", "Hello, world!");
			text->setX(100);
			text->setY(100);
			Assert::AreEqual(text->draw().c_str(), "<text x=\"100\" y=\"100\" font-size=\"11\" font-family=\"Arial\" fill=\"green\" >Hello, world!</text>");
		}

		TEST_METHOD(CreateCollection)
		{
			std::unique_ptr<Figure> circle = std::make_unique<Circle>("blue", 20);
			std::unique_ptr<Figure> circle2 = std::make_unique<Circle>("red", 69);
			std::vector<std::unique_ptr<Figure>> veccy;

			veccy.push_back(std::move(circle));
			Collection col1(std::move(veccy));
			Collection col2(std::move(circle2));

			Assert::IsTrue((int)col1.collectionSize() == 1);
			Assert::AreEqual("blue", col1.getLastItem()->getFill().c_str());


			Assert::IsTrue((int)col2.collectionSize() == 1);
			Assert::AreEqual("red", col2.getLastItem()->getFill().c_str());
		}

		TEST_METHOD(AddToCollection)
		{
			Figure::coordinate x = 12;
			Figure::coordinate y = 8;
			Figure::color fill = "black";
			Figure::color stroke = "white";
			Figure::size radius = 15;
			Circle circle1(x, y, fill, stroke, radius);
			std::unique_ptr<Figure> circle1Ptr = std::make_unique<Circle>(std::move(circle1));
			Collection collection;

			collection.addItem(std::move(circle1Ptr));

			Assert::IsTrue(collection.findItem(circle1));
			Assert::AreEqual(collection.getLastItem()->getFill().c_str(), "black");
		}

		TEST_METHOD(DeleteFromCollection)
		{
			Circle circle1("green", 80);
			Circle circle2("yellow", 60);
			Circle circle3("white", 40);
			std::unique_ptr<Figure> circle1Ptr = std::make_unique<Circle>(std::move(circle1));
			std::unique_ptr<Figure> circle2Ptr = std::make_unique<Circle>(std::move(circle2));
			std::unique_ptr<Figure> circle3Ptr = std::make_unique<Circle>(std::move(circle3));
			Collection collection;

			collection.addItem(std::move(circle1Ptr));
			collection.addItem(std::move(circle2Ptr));
			collection.addItem(std::move(circle3Ptr));

			Assert::IsTrue(collection.findItem(circle1));
			Assert::IsTrue(collection.findItem(circle2));
			Assert::IsTrue(collection.findItem(circle3));

			collection.deleteItem(circle3);

			Assert::ExpectException<std::out_of_range>([&collection, &circle3] {
				collection.deleteItem(circle3);
				});

			Assert::IsFalse(collection.findItem(circle3));
		}

		TEST_METHOD(AssignCollection)
		{
			std::unique_ptr<Circle> circle1 = std::make_unique<Circle>("brown", 1);
			std::unique_ptr<Circle> circle2 = std::make_unique<Circle>("brown", 2);
			std::unique_ptr<Circle> circle3 = std::make_unique<Circle>("brown", 3);
			Collection col1;
			Collection col2;
			col1.addItem(std::move(circle1));
			col1.addItem(std::move(circle2));
			Assert::AreEqual(col1.collectionSize(), (size_t) 1);
			col2.addItem(std::move(circle3));
			col1 = col2;
			Assert::AreEqual(col1.collectionSize(), (size_t)1);
		}

		TEST_METHOD(HtmlSaverConstructorWithoutParameters)
		{
			HtmlParser parser;
			Assert::AreEqual(parser.getFileName().c_str(), "");
		}

		TEST_METHOD(HtmlSaverConstructorWithParameter)
		{
			HtmlParser parser("output.svg");
			Assert::AreEqual(parser.getFileName().c_str(), "output.svg");
		}

		TEST_METHOD(HtmlSaverSetFileNameAndGetFileName)
		{
			HtmlParser parser;
			parser.setFileName("output.svg");
			Assert::AreEqual(parser.getFileName().c_str(), "output.svg");
		}

		TEST_METHOD(HtmlSaverSaveToSVG)
		{
			HtmlParser parser("test_output.svg");
			Figure::coordinate x = 15;
			Figure::coordinate y = 25;
			Figure::color fill = "pink";
			Figure::size fontSize = 16;
			Text::content textContent = "x86-64";
			Text::anchor textAnchor = "end";
			std::unique_ptr<Text> text = std::make_unique<Text>(x, y, fill, fontSize, textContent, textAnchor);
			Collection collection;
			collection.addItem(std::move(text));
			parser.saveToSVG(collection);

			std::ifstream file("test_output.svg");
			Assert::IsTrue(file.good());

			std::stringstream buffer;
			buffer << file.rdbuf();
			std::string fileContent = buffer.str();
			Assert::IsTrue(fileContent.find("x86-64") != std::string::npos);

			file.close();
			remove("test_output.svg");
		}
	};
}
