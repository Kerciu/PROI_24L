#pragma once
#include "Collection.h"

class HtmlParser
{
private:
	std::string fileHandle;

public:
	Collection parseFromFile() const;
	void saveToSVG(const Collection& collection) const;
};

