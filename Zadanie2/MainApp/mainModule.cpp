#include <iostream>
#include "../Price/Price.h"
#include "../Date/Date.h"
#include "../FastSpoiling/fastSpoiling.h"
#include "../FastSpoilingCollection/FastSpoilingCollection.h"
#include "../Transport/Transport.h"
#include "../WeightAndVolume/weightAndVolume.h"
#include "../FileHandler/FileHandler.h"

#define P(x) std::cout << x << std::endl;

int main(int argc, char* argv[]) {
	try {
		FileHandler handler;
		fastSpoilingCollection collection;
		fastSpoiling chicken("chicken", "poultry", Price(20, "UAH"), Date(10, 5, 2024), Transport("Store in freezer"), weightAndVolume(10, 10));
		fastSpoiling chocolatemilk("chocolate milk", "dairy", Price(4.95, "PLN"), Date(10, 3, 2024), Date(15, 7, 2024), weightAndVolume(1, 1));
		fastSpoiling ribeye("Ribeye Steak", "Beef", Price(10.55, "USD"), Date(15, 7, 2030), weightAndVolume(5, 5));

		collection.addNewElement(chicken);
		collection.addNewElement(chocolatemilk);
		collection.addNewElement(ribeye);
		std::cout << collection;

		handler.writeToFile(collection);

		fastSpoilingCollection newCollection = handler.readFromFile();
		std::cout << newCollection;

		std::cout << "\nDisplay Content: \n";
		newCollection.displayContent();

	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}