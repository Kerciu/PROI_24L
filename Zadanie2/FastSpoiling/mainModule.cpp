#include <iostream>
#include "Date.h"
#include "fastSpoiling.h"
#include "FastSpoilingCollection.h"
#include "Transport.h"
#include "weightAndVolume.h"

#define P(x) std::cout << ChocolateMilk.x() << std::endl;

int main(int argc, char* argv[]) {
	try {
		fastSpoiling fs;
		std::cin >> fs;

		std::cout << fs;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << '\n';
	}

	return 0;
}