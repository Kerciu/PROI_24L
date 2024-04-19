#include <memory>
#include <string>
#include "pch.h"
#include "../Figures/Figure.h"
#include "../Figures/Collection.h"
#include "../Figures/DerivedFigures.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(CreateRectangleObject)
		{
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>("", "");
			Assert::AreEqual(rect->getFill().c_str(), "");
			Assert::AreEqual(rect->getStroke().c_str(), "");
			rect->setFill("black");
			rect->setStroke("green");
			Assert::AreEqual(rect->getFill().c_str(), "black");
			Assert::AreEqual(rect->getStroke().c_str(), "green");
		}

		TEST_METHOD(RectangleConstructorTest)
		{
			std::string fill = "red";
			std::string stroke = "blue";
			std::unique_ptr<Rectangle> rect = std::make_unique<Rectangle>(fill, stroke);
			Assert::AreEqual(rect->getFill().c_str(), "red");
			Assert::AreEqual(rect->getStroke().c_str(), "blue");
		}

		TEST_METHOD(CircleConstructorTest)
		{
			std::string fill = "green";
			std::string stroke = "yellow";
			std::unique_ptr<Circle> circle = std::make_unique<Circle>(fill, stroke);
			Assert::AreEqual(circle->getFill().c_str(), "green");
			Assert::AreEqual(circle->getStroke().c_str(), "yellow");
		}

		TEST_METHOD(LineConstructorTest)
		{
			std::string stroke = "blue";
			std::unique_ptr<Line> line = std::make_unique<Line>("", stroke);
			Assert::AreEqual(line->getStroke().c_str(), "blue");
		}
	};
}
