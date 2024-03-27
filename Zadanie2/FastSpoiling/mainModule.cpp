#include <iostream>
#include "Date.h"
#include "fastSpoiling.h"
#include "FastSpoilingCollection.h"
#include "Transport.h"
#include "weightAndVolume.h"

#define P(x) std::cout << ChocolateMilk.x() << std::endl;

int main() {
	try {
		// Creating Chicken Object
		fastSpoiling ChickenBreast("Chicken Breast", "Poultry", Date(3, 3, 2024), Transport(10, "Store in a fridge", 50), weightAndVolume(10, 10));

		// Creating Banana Object
		fastSpoiling Banana("Banana", "Fruit", Date(15, 4, 2024), weightAndVolume(12, 12));

		// Creating Chocolate Milk Object
		fastSpoiling ChocolateMilk("Chocolate Milk", "Dairy", Date(12, 1, 2024), Date(15, 5, 2025), Transport("Store in a cartoon lid to the sky"), weightAndVolume(1, 1));

		// Creating Breakfast Cereal Object
		fastSpoiling BreakfastCereal("Breakfast Cereal", "Cereal", weightAndVolume(0.7, 2));

		// Add element to collection
		fastSpoilingCollection collection;
		collection.addNewElement(ChickenBreast);
		collection.addNewElement(Banana);
		collection.addNewElement(ChocolateMilk);
		collection.addNewElement(BreakfastCereal);

		std::cout << collection << '\n';

		std::cout << "Show all the Chocolate milk getters: \n";
		P(getName);
		P(getType);
		P(getProductionDateVerbalizedDay);
		P(getExpirationDateVerbalizedDay);
		P(getTransportTemperature);
		P(getTransportPackaging);
		P(getTransportHumidity);
		P(getWeight);
		P(getVolume);

		std::cout << ChocolateMilk.getWeight("gram") << " grams\n";
		std::cout << ChocolateMilk.getVolume("mililiter") << " mililiters\n";

		std::cout << "\nLet's remove cereal, banana, and change chocolate milk and chicken breast\n";

		collection.deleteElement(BreakfastCereal);
		collection.deleteElement(Banana);
		
		// Element at the index of 0 in vector
		collection.searchForElement(ChickenBreast);
		collection.searchForElement(ChocolateMilk);

		collection.modifyName(1, "Strawberry Milk");
		collection.modifyCollectionElement(0, "Turkey Breast", "Poultry", Date(1, 1, 1), Date(16, 7, 2024), Transport(-15, "Store freezed"), weightAndVolume(15, 14.5));

		std::cout << collection;

		std::cout << "Let's delete already deleted Banana\n";
		collection.deleteElement(Banana);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}