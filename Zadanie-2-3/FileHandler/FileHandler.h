#pragma once
#include <string>
#include <fstream>
#include "../Product/Product.h"
#include "../ProductCollection/ProductCollection.h"

class wrongItemContentError : public std::exception {
private:
	std::string message;

public:
	wrongItemContentError(const std::string& mes);

	virtual const char* what() const throw();
};


class FileHandler
{
	std::string fileName;
	
	bool validateFileInfo(std::string& content) const;

public:
	FileHandler();
	FileHandler(const std::string& name);

	std::string getName() const;
	void setName(const std::string& newName);

	ProductCollection readFromFile() const;
	void writeToFile(const ProductCollection& content);
	
};

