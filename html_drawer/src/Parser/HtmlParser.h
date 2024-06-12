#pragma once
#include <string>
#include "../Collection/Collection.h"

class HtmlParser
{
private:
	typedef std::string handle;
	handle fileHandle;

public:
	HtmlParser();
	HtmlParser(const handle& fileHandle);

	void saveToSVG(const Collection& collection) const;

	HtmlParser::handle getFileName();
	void setFileName(const HtmlParser::handle& newFilename);
};

