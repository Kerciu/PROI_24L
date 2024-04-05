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

std::string FileHandler::readFromFile() const
{
	std::ifstream file(fileName);

	if (!file.is_open()) {
		throw std::runtime_error("Unable to open the file.");
	}

	std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	if (validateFileInfo(content)) {
		throw wrongItemContentError("Items in file are incorrect!");
	}
	file.close();

	return content;
}

void FileHandler::writeToFile(const std::string& content)
{
	std::ofstream file(fileName);

	if (!file.is_open()) {
		throw std::runtime_error("Unable to open the file.");
	}

	file << content;

	file.close();
}
