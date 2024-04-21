#include <memory>
#include <string>
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
			std::unique_ptr<Line> line = std::make_unique<Line>(stroke);
			Assert::AreEqual(line->getStroke().c_str(), "blue");
		}

		TEST_METHOD(CreateCollection)
		{
			std::unique_ptr<Circle> circle = std::make_unique<Circle>("blue", "yellow");
			std::vector<std::unique_ptr<Figure>> veccy;

			veccy.push_back(std::move(circle));
			Collection col1(std::move(veccy));
			Collection col2(std::make_unique<Circle>("red", "green"));

			Assert::IsTrue((int)col1.collectionSize() == 1);
			Assert::AreEqual("blue", col1.getLastItem()->getFill().c_str());


			Assert::IsTrue((int)col2.collectionSize() == 1);
			Assert::AreEqual("red", col2.getLastItem()->getFill().c_str());
		}

		TEST_METHOD(AddToCollection)
		{
			std::unique_ptr<Circle> circle1 = std::make_unique<Circle>("brown", "yellow");
			std::unique_ptr<Circle> circle2 = std::make_unique<Circle>("brown", "green");
			std::unique_ptr<Circle> circle3 = std::make_unique<Circle>("brown", "black");
			Collection collection;

			collection.addItem(std::make_unique<Figure>(*circle1));
			collection.addItem(std::make_unique<Figure>(*circle2));

			Assert::IsTrue(collection.findItem(std::make_unique<Figure>(*circle1)));
			Assert::IsFalse(collection.findItem(std::make_unique<Figure>(*circle2)));
			Assert::AreEqual(collection.getLastItem()->getFill().c_str(), "brown");
		}

		TEST_METHOD(DeleteFromCollection)
		{
			std::unique_ptr<Circle> circle1 = std::make_unique<Circle>("brown", "yellow");
			std::unique_ptr<Circle> circle2 = std::make_unique<Circle>("brown", "green");
			std::unique_ptr<Circle> circle3 = std::make_unique<Circle>("brown", "black");
			Collection collection;

			collection.addItem(std::make_unique<Figure>(*circle1));
			collection.addItem(std::make_unique<Figure>(*circle2));
			collection.addItem(std::make_unique<Figure>(*circle3));

			std::unique_ptr<Figure> circle3Ptr = std::make_unique<Figure>(*circle3);

			Assert::IsTrue(collection.findItem(std::make_unique<Figure>(*circle1)));
			Assert::IsTrue(collection.findItem(std::make_unique<Figure>(*circle2)));
			Assert::IsTrue(collection.findItem(std::make_unique<Figure>(*circle3)));

			collection.deleteItem(std::make_unique<Figure>(*circle3));

			Assert::ExpectException<std::out_of_range>([&collection, &circle3Ptr] {
				collection.deleteItem(std::move(circle3Ptr));
				});

			Assert::IsFalse(collection.findItem(std::make_unique<Figure>(*circle3)));
		}
		TEST_METHOD(AddTwoCollections)
		{
			std::unique_ptr<Circle> circle1 = std::make_unique<Circle>("brown", "yellow");
			std::unique_ptr<Circle> circle2 = std::make_unique<Circle>("brown", "green");
			std::unique_ptr<Circle> circle3 = std::make_unique<Circle>("brown", "black");
			Collection col1;
			col1.addItem(std::make_unique<Circle>(*circle1));
			col1.addItem(std::make_unique<Circle>(*circle2));

			Collection col2;
			col2.addItem(std::make_unique<Circle>(*circle3));

			Collection col3 = col1 + col2;
			Assert::AreEqual(col3.collectionSize(), (size_t)3);
		}

		TEST_METHOD(AssignCollection)
		{
			std::unique_ptr<Circle> circle1 = std::make_unique<Circle>("brown", "yellow");
			std::unique_ptr<Circle> circle2 = std::make_unique<Circle>("brown", "green");
			std::unique_ptr<Circle> circle3 = std::make_unique<Circle>("brown", "black");
			Collection col1;
			Collection col2;
			col1.addItem(std::move(circle1));
			col1.addItem(std::move(circle2));
			Assert::AreEqual(col1.collectionSize(), (size_t)2);
			col2.addItem(std::move(circle3));
			col1 = std::move(col2);
			Assert::AreEqual(col1.collectionSize(), (size_t)1);
		}
	};
}
