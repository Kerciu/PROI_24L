#include <iostream>
#include "Date.h"
#include "fastSpoiling.h"
#include "FastSpoilingCollection.h"
#include "Transport.h"
#include "weightAndVolume.h"
#include "FileHandler.h"

#define P(x) std::cout << x << std::endl;

int main(int argc, char* argv[]) {
	try {
		fastSpoiling fs("chicken", "poultry", Date(12,10,2004), Date(13,10,2024), Transport(), weightAndVolume(10, 10));
		FileHandler handler("collection.txt");

		fastSpoilingCollection collection = handler.readFromFile();

		P(fs);
		P(collection);
		
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