#pragma once
#include <vector>
#include <memory>
#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>
#include "../Figure/Figure.h"

class Collection
{
private:
	std::vector<std::unique_ptr<Figure>> pointerCollection;
	friend std::ostream& operator<<(std::ostream& os, const Collection& other);
public:
	Collection();
	Collection(std::unique_ptr<Figure> itemToCollect);
	Collection(std::vector<std::unique_ptr<Figure>> pointerCollection);
	Collection(const Collection& other);
	~Collection();

	std::unique_ptr<Figure> deleteItem(const Figure& item);
	bool findItem(const Figure& item) const;
	std::unique_ptr<Figure> popItem();
	size_t collectionSize() const;
	void addItem(std::unique_ptr<Figure> item);
	std::unique_ptr<Figure> getLastItem();
	std::string generateSVGString();

	Collection& operator=(Collection& other);
	bool operator==(const Collection& other) const;
};
