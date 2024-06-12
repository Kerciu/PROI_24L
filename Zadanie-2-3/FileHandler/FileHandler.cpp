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

ProductCollection FileHandler::readFromFile() const
{	
	ProductCollection collection;
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

		if (!(attributes.size() == 15)) {
			std::cout << attributes.size();
			throw std::runtime_error("Invalid number of attributes in the file.");
		}
		Price price(std::stod(attributes[2]), attributes[3]);
		Date prodDate(std::stoi(attributes[4]), std::stoi(attributes[5]), std::stoi(attributes[6]));
		Date expirDate(std::stoi(attributes[7]), std::stoi(attributes[8]), std::stoi(attributes[9]));
		Transport transport(std::stod(attributes[10]), attributes[11], std::stod(attributes[12]));
		weightAndVolume wv(std::stod(attributes[13]), std::stod(attributes[14]));

		Product product(attributes[0], attributes[1], price, prodDate, expirDate, transport, wv);
		collection.addNewElement(product);
	}

	return collection;
 }

void FileHandler::writeToFile(const ProductCollection& content)
{
	std::ofstream file(fileName);

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
