#include "CppUnitTest.h"
#include <sstream>
#include "../FastSpoiling/fastSpoiling.h"
#include "../FastSpoiling/Transport.h"
#include "../FastSpoiling/weightAndVolume.h"
#include "../FastSpoiling/FastSpoilingCollection.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FastSpoilingTest
{
	TEST_CLASS(FastSpoilingTest)
	{
	public:

		TEST_METHOD(CreateFastSpoilingObject)
		{
			// Arrange
			std::string itemName = "Apple";
			std::string itemType = "Fruit";
			Date productionDate(15, 3, 2024);
			Date expirationDate(20, 3, 2024);
			Transport transport(15.5, "In a box", 50);
			weightAndVolume weightVolume(0.2, 0.1);

			// Act
			fastSpoiling fs(itemName, itemType, productionDate, expirationDate, transport, weightVolume);

			// Assert
			Assert::AreEqual(itemName, fs.getName());
			Assert::AreEqual(itemType, fs.getType());
			Assert::AreEqual(productionDate.slashOutput(), fs.getProductionDateSlashed());
			Assert::AreEqual(expirationDate.slashOutput(), fs.getExpirationDateSlashed());
			Assert::AreEqual(0.2, fs.getWeight());
			Assert::AreEqual(0.1, fs.getVolume());
		}

		TEST_METHOD(SetFastSpoilingAttributes)
		{
			// Arrange
			fastSpoiling fs("Apple", "Fruit", Date(15, 3, 2023), Date(20, 3, 2023), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));

			// Act
			fs.setName("Banana");
			fs.setType("Fruit");
			fs.setProductionDate(16, 3, 2023);
			fs.setExpirationDate(21, 3, 2023);
			fs.setTransportTemperature(20.0);
			fs.setTransportPackaging("Crate");
			fs.setWeight(0.3);
			fs.setVolume(0.2);

			// Assert
			Assert::AreEqual("Banana", fs.getName().c_str());
			Assert::AreEqual("Fruit", fs.getType().c_str());
			Assert::AreEqual(Date(16, 3, 2023).slashOutput(), fs.getProductionDateSlashed());
			Assert::AreEqual(Date(21, 3, 2023).slashOutput(), fs.getExpirationDateSlashed());
			Assert::AreEqual(0.3, fs.getWeight());
			Assert::AreEqual(0.2, fs.getVolume());
		}

		TEST_METHOD(FastSpoilingEqualityOperator)
		{
			// Arrange
			fastSpoiling fs1("Apple", "Fruit", Date(15, 3, 2023), Date(15, 3, 2023), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoiling fs2("Apple", "Fruit", Date(15, 3, 2023), Date(15, 3, 2023), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoiling fs3("Banana", "Fruit", Date(14, 3, 2023), Date(16, 3, 2023), Transport(15.5, "In a cooler", 50), weightAndVolume(0.3, 0.2));

			// Act & Assert
			Assert::IsTrue(fs1 == fs2);
			Assert::IsFalse(fs1 == fs3);
		}

		TEST_METHOD(TransportConstructorAndGetters)
		{
			// Arrange
			double temperature = 25.0;
			std::string packaging = "Box";
			double humidity = 60;

			// Act
			Transport transport(temperature, packaging, humidity);

			// Assert
			Assert::AreEqual(temperature, transport.getTemperature());
			Assert::AreEqual(packaging, transport.getPackaging());
			Assert::AreEqual(humidity, transport.getHumidity());
		}

		TEST_METHOD(SetTemperature)
		{
			// Arrange
			Transport transport(10.0, "Box", 50);

			// Act
			transport.setTemperature(20.0);

			// Assert
			Assert::AreEqual(20.0, transport.getTemperature());
		}

		TEST_METHOD(SetHumidity)
		{
			// Arrange
			Transport transport(10.0, "Box", 50.0);

			// Act
			transport.setHumidity(70.0);

			// Assert
			Assert::AreEqual(70.0, transport.getHumidity());
		}

		TEST_METHOD(TransportEqualityOperator)
		{
			// Arrange
			Transport transport1(25.0, "Box", 60);
			Transport transport2(25.0, "Box", 60);
			Transport transport3(30.0, "Crate", 50);

			// Act & Assert
			Assert::IsTrue(transport1 == transport2);
			Assert::IsFalse(transport1 == transport3);
		}

		TEST_METHOD(WeightAndVolumeConstructorAndGetters)
		{
			// Arrange
			weightAndVolume wv(2.5, 3.0);

			// Act
			double weight = wv.getWeight();
			double volume = wv.getVolume();

			// Assert
			Assert::AreEqual(2.5, weight);
			Assert::AreEqual(3.0, volume);
		}

		TEST_METHOD(WeightConversion)
		{
			// Arrange
			weightAndVolume wv(2500, 3.0); // 2500 kilo

			// Act
			double weightInTonnes = wv.getWeight("tonne");

			// Assert
			if (weightInTonnes != -1) {
				Assert::AreEqual(2.5, weightInTonnes, 0.001);		// Precyzja
			}
			else {
				Assert::Fail(L"Invalid unit");
			}
		}

		TEST_METHOD(VolumeConversion)
		{
			// Arrange
			weightAndVolume wv(3000, 3000); // 3000 litrów

			// Act
			double volumeInLiters = wv.getVolume("hectoliter");

			// Assert
			if (volumeInLiters != -1) {
				Assert::AreEqual(3.0, volumeInLiters, 0.001);
			}
			else {
				Assert::Fail(L"Invalid unit");
			}
		}

		TEST_METHOD(WeightAndVolumeAdditionOperator)
		{
			// Arrange
			weightAndVolume wv1(2.5, 3.0);
			weightAndVolume wv2(1.0, 2.0);

			// Act
			weightAndVolume result = wv1 + wv2;

			// Assert
			Assert::AreEqual(3.5, result.getWeight());
			Assert::AreEqual(5.0, result.getVolume());
		}

		TEST_METHOD(WeightAndVolumeSubtractionOperator)
		{
			// Arrange
			weightAndVolume wv1(2.5, 3.0);
			weightAndVolume wv2(1.0, 1.0);

			// Act
			weightAndVolume result = wv1 - wv2;

			// Assert
			Assert::AreEqual(1.5, result.getWeight());
			Assert::AreEqual(2.0, result.getVolume());
		}

		TEST_METHOD(WeightAndVolumeMultiplicationOperator)
		{
			// Arrange
			weightAndVolume wv(2.5, 3.0);
			double factor = 2.0;

			// Act
			weightAndVolume result = wv * factor;

			// Assert
			Assert::AreEqual(5.0, result.getWeight());
			Assert::AreEqual(6.0, result.getVolume());
		}

		TEST_METHOD(WeightAndVolumeEqualityOperator)
		{
			// Arrange
			weightAndVolume wv1(2.5, 3.0);
			weightAndVolume wv2(2.5, 3.0);
			weightAndVolume wv3(1.5, 2.0);

			// Act & Assert
			Assert::IsTrue(wv1 == wv2);
			Assert::IsFalse(wv1 == wv3);
		}

		TEST_METHOD(AddElement)
		{
			fastSpoiling fs("Apple", "Fruit", Date(15, 3, 2023), Date(20, 3, 2023), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoilingCollection collection;

			collection.addNewElement(fs);

			Assert::AreEqual(static_cast<size_t>(1), collection.sizeOfCollection());
		}

		TEST_METHOD(SearchElement)
		{
			// Arrange
			fastSpoiling fs("Apple", "Fruit", Date(15, 3, 2023), Date(20, 3, 2023), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoilingCollection collection;
			collection.addNewElement(fs);

			// Act & Assert
			Assert::ExpectException<std::out_of_range>([&]() {
				collection.searchForElement(fastSpoiling("Banana", "Fruit", Date(2023, 3, 16), Date(2023, 3, 21), Transport(15.5, "In a cooler", 50), weightAndVolume(0.3, 0.2)));
				});
		}

		TEST_METHOD(DeleteElement)
		{
			// Arrange
			fastSpoiling fs("Apple", "Fruit", Date(15, 3, 2023), Date(20, 3, 2023), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoilingCollection collection;
			collection.addNewElement(fs);

			// Act
			collection.deleteElement(fs);

			// Assert
			Assert::AreEqual(static_cast<size_t>(0), collection.sizeOfCollection());
		}

		TEST_METHOD(ModifyElement)
		{
			// Arrange
			fastSpoiling fs("Apple", "Fruit", Date(15, 3, 2023), Date(20, 3, 2023), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoilingCollection collection;
			collection.addNewElement(fs);

			// Act
			collection.modifyCollectionElement(0, "Banana", "Fruit", Date(16, 3, 2023), Date(21, 3, 2024), Transport(20.0, "In a cooler", 60), weightAndVolume(0.3, 0.2));

			// Assert
			Assert::AreEqual("Banana", fs.getName().c_str());
			Assert::AreEqual("Fruit", fs.getType().c_str());
			Assert::AreEqual(Date(16, 3, 2023).slashOutput(), fs.getProductionDateSlashed());
			Assert::AreEqual(Date(21, 3, 2024).slashOutput(), fs.getExpirationDateSlashed());
			Assert::AreEqual(0.3, fs.getWeight());
			Assert::AreEqual(0.2, fs.getVolume());
			Assert::AreEqual(20.0, fs.getTransportTemperature());
			Assert::AreEqual("In a cooler", fs.getTransportPackaging().c_str());
			Assert::AreEqual(60.0, fs.getTransportHumidity());
		}

		TEST_METHOD(RepresentCollection) {
			fastSpoiling fs("Apple", "Fruit", Date(15, 3, 2023), Date(20, 3, 2023), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			std::ostringstream oss;
			oss << fs;
			Assert::AreEqual(oss.str().c_str(), "Apple;Fruit;15/03/2023;20/03/2023;15.5;In a box;50;0.2;0.1\n");
		}

		TEST_METHOD(TransportOutputOperator)
		{
			Transport transport(25.5, "In a box", 50);
			std::ostringstream oss;
			oss << transport;
			Assert::AreEqual(oss.str().c_str(), "25.5;In a box;50");
		}

		TEST_METHOD(TransportInputOperator)
		{
			std::istringstream iss("25.5 In a box 50");
			Transport transport;
			iss >> transport;
			Assert::AreEqual(transport.getTemperature(), Transport::Temperature(25.5));
			Assert::AreEqual(transport.getPackaging(), Transport::Packaging("In"));
			Assert::AreEqual(transport.getHumidity(), Transport::Humidity(50));
		}

		TEST_METHOD(WeightAndVolumeInputOperator_ValidInput)
		{
			std::istringstream iss("10.5;20.3");
			weightAndVolume wv;
			iss >> wv;
			Assert::AreEqual(wv.getWeight(), weightAndVolume::Weight(10.5));
			Assert::AreEqual(wv.getVolume(), weightAndVolume::Volume(20.3));
		}

		TEST_METHOD(WeightAndVolumeInputOperator_InvalidInput)
		{
			std::istringstream iss("abc;20.3");
			weightAndVolume wv;
			iss >> wv;
			Assert::IsTrue(iss.fail());
		}

		TEST_METHOD(WeightAndVolumeInputOperator_NegativeInput)
		{
			std::istringstream iss("-10.5;-20.3");
			weightAndVolume wv;
			iss >> wv;
			Assert::AreEqual(wv.getWeight(), weightAndVolume::Weight(-10.5));
			Assert::AreEqual(wv.getVolume(), weightAndVolume::Volume(-20.3));
		}

		TEST_METHOD(WeightAndVolumeAssignmentOperator)
		{
			weightAndVolume wv1(15.7, 30.9);
			weightAndVolume wv2;
			wv2 = wv1;
			Assert::AreEqual(wv2.getWeight(), weightAndVolume::Weight(15.7));
			Assert::AreEqual(wv2.getVolume(), weightAndVolume::Volume(30.9));
		}

		TEST_METHOD(CompareTwoDefaultDates)
		{
			Date date1;
			Date date2;
			Assert::IsFalse(date1 == date2);
		}

		TEST_METHOD(DateOutputOperator_ValidDate)
		{
			Date date(15, 3, 2023);
			std::ostringstream oss;
			oss << date;
			Assert::AreEqual(oss.str().c_str(), "15/3/2023");
		}

		TEST_METHOD(DateOutputOperator_DefaultDate)
		{
			Date date;
			std::ostringstream oss;
			oss << date;
			Assert::AreEqual(oss.str().c_str(), "N/A");
		}

		TEST_METHOD(DateInputOperator_ValidInput)
		{
			std::istringstream iss("10/12/2022");
			Date date;
			iss >> date;
			Assert::AreEqual(date.getDay(), 10);
			Assert::AreEqual(date.getMonthDigits(), 12);
			Assert::AreEqual(date.getYear(), 2022);
		}

		TEST_METHOD(DateInputOperator_DefaultInput)
		{
			std::istringstream iss("N/A");
			Date date;
			iss >> date;
			Assert::AreEqual(date.getYear(), 1);
		}
	};
}
