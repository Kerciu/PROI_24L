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
		TEST_METHOD(InvalidConstructorParameters)
		{
			Assert::ExpectException<std::invalid_argument>([&] { Date date(40, 29, 0); });
		}
		TEST_METHOD(SetValues)
		{
			Date date(15, 10, 2004);
			date.setDay(16);
			date.setMonth(12);
			date.setYear(2024);
			Assert::AreEqual(16, date.getDay());
			Assert::AreEqual(12, date.getMonthDigits());
			Assert::AreEqual(2024, date.getYear());
		}
		TEST_METHOD(SlashOutput)
		{
			Date date(15, 10, 2004);
			Assert::AreEqual(std::string("15/10/2004"), date.slashOutput());
		}

		TEST_METHOD(HyphenOutput)
		{
			Date date(15, 10, 2004);
			Assert::AreEqual(std::string("15-10-2004"), date.hyphenOutput());
		}

		TEST_METHOD(DotOutput)
		{
			Date date(15, 10, 2004);
			Assert::AreEqual(std::string("15.10.2004"), date.dotOutput());
		}

		TEST_METHOD(VerbalMonthOutput)
		{
			Date date(15, 10, 2004);
			Assert::AreEqual(std::string("15 Pazdziernik 2004"), date.verbalMonthOutput());
		}

		TEST_METHOD(VerbalDayOutput)
		{
			Date date(15, 10, 2004);
			Assert::AreEqual(std::string("Piatek 15.10.2004"), date.verbalDayOutput());
		}

		TEST_METHOD(InvalidDayValue)
		{
			Date date(15, 10, 2004);
			Assert::ExpectException<std::out_of_range>([&] {date.setDay(32); });
		}
		TEST_METHOD(InvalidMonthValue)
		{
			Date date(15, 10, 2004);
			Assert::ExpectException<std::out_of_range>([&] {date.setMonth(13); });
		}
		TEST_METHOD(InvalidYearValue)
		{
			Date date(15, 10, 2004);
			Assert::ExpectException<std::out_of_range>([&] {date.setYear(0); });
		}
		TEST_METHOD(ValidLeapYear)
		{
			Date date(29, 2, 2024);
			Assert::AreEqual(29, date.getDay());
			Assert::AreEqual(2, date.getMonthDigits());
			Assert::AreEqual(2024, date.getYear());
		}
		TEST_METHOD(InvalidLeapYear)
		{
			Assert::ExpectException<std::out_of_range>([&] {Date date(29, 2, 2025); });
		}
	};
}
