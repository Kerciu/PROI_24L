#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Kacper\source\repos\Zad1_203_Kacper_Górski\Zad1_203_Kacper_Górski\Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace dateTest
{
	TEST_CLASS(dateTest)
	{
	public:
		
		TEST_METHOD(ConstructorCreation)
		{
			Date date(15, 10, 2004);
			Assert::AreEqual(15, date.getDay());
			Assert::AreEqual(10, date.getMonthDigits());
			Assert::AreEqual(2004, date.getYear());
		}
		TEST_METHOD(ConstructorParameterless)
		{
			Assert::ExpectException<std::invalid_argument>([] { Date date; });
		}
	};
}
