#include "pch.h"
#include "CppUnitTest.h"
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
			Date productionDate(2023, 3, 15);
			Date expirationDate(2023, 3, 20);
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
			fastSpoiling fs("Apple", "Fruit", Date(2023, 3, 15), Date(2023, 3, 20), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));

			// Act
			fs.setName("Banana");
			fs.setType("Fruit");
			fs.setProductionDate(2023, 3, 16);
			fs.setExpirationDate(2023, 3, 21);
			fs.setTransportTemperature(20.0);
			fs.setTransportPackaging("Crate");
			fs.setWeight(0.3);
			fs.setVolume(0.2);

			// Assert
			Assert::AreEqual("Banana", fs.getName().c_str());
			Assert::AreEqual("Fruit", fs.getType().c_str());
			Assert::AreEqual(Date(2023, 3, 16).slashOutput(), fs.getProductionDateSlashed());
			Assert::AreEqual(Date(2023, 3, 21).slashOutput(), fs.getExpirationDateSlashed());
			Assert::AreEqual(0.3, fs.getWeight());
			Assert::AreEqual(0.2, fs.getVolume());
		}

		TEST_METHOD(FastSpoilingEqualityOperator)
		{
			// Arrange
			fastSpoiling fs1("Apple", "Fruit", Date(2023, 3, 15), Date(2023, 3, 20), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoiling fs2("Apple", "Fruit", Date(2023, 3, 15), Date(2023, 3, 20), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoiling fs3("Banana", "Fruit", Date(2023, 3, 16), Date(2023, 3, 21), Transport(15.5, "In a cooler", 50), weightAndVolume(0.3, 0.2));

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
			weightAndVolume wv(2500, 3.0); // 2500 gramów = 2.5 kg

			// Act
			double weightInKilograms = wv.getWeight("kilogram");

			// Assert
			Assert::AreEqual(2.5, weightInKilograms);
		}

		TEST_METHOD(VolumeConversion)
		{
			// Arrange
			weightAndVolume wv(2.5, 3000); // 3000 mililitrów = 3 litry

			// Act
			double volumeInLiters = wv.getVolume("liter");

			// Assert
			Assert::AreEqual(3.0, volumeInLiters);
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
			// Arrange
			fastSpoiling fs("Apple", "Fruit", Date(2023, 3, 15), Date(2023, 3, 20), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoilingCollection collection;

			// Act
			collection.addNewElement(fs);

			// Assert
			Assert::AreEqual(static_cast<size_t>(1), collection.sizeOfCollection());
		}

		TEST_METHOD(SearchElement)
		{
			// Arrange
			fastSpoiling fs("Apple", "Fruit", Date(2023, 3, 15), Date(2023, 3, 20), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
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
			fastSpoiling fs("Apple", "Fruit", Date(2023, 3, 15), Date(2023, 3, 20), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
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
			fastSpoiling fs("Apple", "Fruit", Date(2023, 3, 15), Date(2023, 3, 20), Transport(15.5, "In a box", 50), weightAndVolume(0.2, 0.1));
			fastSpoilingCollection collection;
			collection.addNewElement(fs);

			// Act
			collection.modifyCollectionElement(1, "Banana", "Fruit", Date(2023, 3, 16), Date(2023, 3, 21), Transport(20.0, "In a cooler", 60), weightAndVolume(0.3, 0.2));

			// Assert
			Assert::AreEqual("Banana", fs.getName().c_str());
			Assert::AreEqual("Fruit", fs.getType().c_str());
			Assert::AreEqual(Date(2023, 3, 16).slashOutput(), fs.getProductionDateSlashed());
			Assert::AreEqual(Date(2023, 3, 21).slashOutput(), fs.getExpirationDateSlashed());
			Assert::AreEqual(0.3, fs.getWeight());
			Assert::AreEqual(0.2, fs.getVolume());
			Assert::AreEqual(20.0, fs.getTransportTemperature());
			Assert::AreEqual("In a cooler", fs.getTransportPackaging().c_str());
			Assert::AreEqual(60.0, fs.getTransportHumidity());
		}
	};
}
