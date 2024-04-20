#pragma once
#include <vector>
#include <memory>
#include "Figure.h"

class Collection
{
private:
	std::vector<std::unique_ptr<Figure>> pointerCollection;

public:
	Collection();
	Collection(std::unique_ptr<Figure> itemToCollect);
	Collection(std::vector<std::unique_ptr<Figure>> pointerCollection);
	Collection(const Collection& other);
	~Collection();

	void addItem(std::unique_ptr<Figure> item);
	void deleteItem(std::unique_ptr<Figure> item);
	bool findItem(std::unique_ptr<Figure> item) const;
	std::unique_ptr<Figure> popItem();
	size_t collectionSize() const;
	std::unique_ptr<Figure> getLastItem();
	std::string generateSVGString();

	Collection& operator+(Collection& other) const;
	Collection& operator=(Collection& other);
	bool operator==(const Collection& other) const;
};
