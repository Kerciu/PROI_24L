#include "pch.h"
#include "../Figures/Figure.h"
#include "../Figures/Collection.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(CreateFigureObject)
		{
			Figure unnamedFigure1;
			Figure unnamedFigure2;
			Figure unnamedFigure3;

			Assert::AreEqual(unnamedFigure1.setFill().c_str(), "");
			Assert::AreEqual(unnamedFigure1.setStroke().c_str(), "");
		}
	};
}
