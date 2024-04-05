#pragma once
#include <string>
#include <fstream>

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

	std::string readFromFile() const;
	void writeToFile(const std::string& content);
	
};

