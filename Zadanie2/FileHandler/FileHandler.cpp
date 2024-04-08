#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

// Exceptions
wrongItemContentError::wrongItemContentError(const std::string& mes) : message(mes) { }
const char* wrongItemContentError::what() const throw() {
	return message.c_str();
}

// File handling class
FileHandler::FileHandler() : fileName("deafult_file.txt") { }
FileHandler::FileHandler(const std::string& name) : fileName(name) { }

std::string FileHandler::getName() const
{
	return std::string();
}

bool FileHandler::validateFileInfo(std::string& content) const {
	return true;		// For now
}

void FileHandler::setName(const std::string& newName)
{
	fileName = newName;
}

fastSpoilingCollection FileHandler::readFromFile() const
{	
	fastSpoilingCollection collection;
	std::ifstream file(fileName.c_str());

	if (!file.is_open()) {
		throw std::runtime_error(("Unable to open the file called ", fileName).c_str());
	}
	if (file.fail()) {
		throw std::runtime_error("Error while writing to file: Write operation failed.");
	}
	if (file.bad()) {
		throw std::runtime_error("Error while writing to file: Critical stream failure.");
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::vector<std::string> attributes;

		std::string substring;
		while (std::getline(iss, substring, ';')) {
			attributes.push_back(substring);
		}

		if (attributes.size() != 11) {
			throw std::runtime_error("Invalid number of attributes in the file.");
		}

		std::istringstream dateStream(attributes[4]);
		int day, month, year;
		char delimiter;
		dateStream >> day >> delimiter >> month >> delimiter >> year;

		
		Date productionDate(day, month, year);

		dateStream.clear();
		dateStream.str(attributes[5]);
		dateStream >> day >> delimiter >> month >> delimiter >> year;
		Date expirationDate(day, month, year);

		Price price(std::stod(attributes[2]), attributes[3].c_str());
		Transport transport(std::stod(attributes[6]), attributes[7], std::stod(attributes[8]));
		weightAndVolume wv(std::stod(attributes[9]), std::stod(attributes[10]));

		fastSpoiling product(attributes[0], attributes[1], price, productionDate, expirationDate, transport, wv);
		collection.addNewElement(product);
	}

	return collection;
 }

void FileHandler::writeToFile(const fastSpoiling& content)
{
	std::ofstream file(fileName, std::ios::app);

	if (!file.is_open()) {
		throw std::runtime_error("Unable to open the file.");
	}

	file << content;

	if (file.fail()) {
		throw std::runtime_error("Error while writing to file: Write operation failed.");
	}
	if (file.bad()) {
		throw std::runtime_error("Error while writing to file: Critical stream failure.");
	}

	file.close();
}
