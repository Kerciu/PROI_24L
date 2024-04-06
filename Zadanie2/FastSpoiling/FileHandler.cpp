#include "FileHandler.h"
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
	fastSpoiling product;
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

	while (file >> product) {
		collection.addNewElement(product);
	}

	file.close();

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
