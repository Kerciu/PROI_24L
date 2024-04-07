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
		Price price;
		price.showAvailableCurrenciesShortAndCode();
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