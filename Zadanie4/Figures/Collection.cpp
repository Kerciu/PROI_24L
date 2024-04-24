#include <exception>
#include <iostream>
#include <string>
#include "Figure.h"
#include "Collection.h"
#include <stdexcept>

Collection::Collection() : pointerCollection() { }

Collection::Collection(std::unique_ptr<Figure> itemToCollect)
{
	pointerCollection.push_back(std::move(itemToCollect));
}

Collection::Collection(std::vector<std::unique_ptr<Figure>> pointerCollection) : pointerCollection(std::move(pointerCollection)) { }

Collection::Collection(const Collection& other)
{
	pointerCollection.reserve(other.pointerCollection.size());
	for (const auto& elem : other.pointerCollection) {
		pointerCollection.push_back(std::make_unique<Figure>(*elem));
	}
}

Collection::~Collection() { }

std::unique_ptr<Figure> Collection::deleteItem(const Figure& itemToDelete)
{
	for (auto it = pointerCollection.begin(); it != pointerCollection.end(); ++it)
	{
		auto& currentObject = **it;
		if (currentObject == itemToDelete) {
			auto deletedElem = std::move(*it);
			pointerCollection.erase(it);
			return deletedElem;
		}
	}
	throw std::out_of_range("No such element found in the collection");
}

bool Collection::findItem(const Figure& item) const
{
	for (auto it = pointerCollection.begin(); it != pointerCollection.end(); ++it)
	{
		if (typeid(**it) == typeid(item)) {
			auto& currentObject = **it;
			if (currentObject == item) {
				return true;
			}
		}
	}
	return false;
}

std::unique_ptr<Figure> Collection::popItem()
{
	if (!pointerCollection.empty()) {
		std::unique_ptr<Figure> result = std::move(pointerCollection.back());
		pointerCollection.pop_back();
		return result;
	}
	else throw std::out_of_range("The collection is empty");
}

size_t Collection::collectionSize() const
{
	return pointerCollection.size();
}

void Collection::addItem(std::unique_ptr<Figure> item)
{
	int counter = 0;
	for (int i = 0; i < pointerCollection.size(); i++) {
		if (*(pointerCollection[i]) == *item) {
			counter++;
		}
	}
	if (counter == 0) {
		pointerCollection.push_back(std::move(item));
	}
}

std::unique_ptr<Figure> Collection::getLastItem()
{
	size_t collectionSize = pointerCollection.size();
	if (collectionSize > 0) return std::move(pointerCollection[collectionSize - 1]);
	else throw std::out_of_range("Insufficient elements in the collecton");
}

std::string Collection::generateSVGString()
{
	return std::string();
}

Collection Collection::operator+(Collection& other) const
{
	Collection result(*this);

	for (const auto& item : other.pointerCollection) {
		if (!result.findItem((*item))) {
			result.pointerCollection.emplace_back(std::make_unique<Figure>(*item));
		}
	}
	return result;
}

Collection& Collection::operator=(Collection& other)
{
	if (&other != this) {
		pointerCollection.clear();
		pointerCollection.reserve(other.pointerCollection.size());
		for (const auto& elem : other.pointerCollection) {
			pointerCollection.push_back(std::make_unique<Figure>(*elem));
		}
	}
	return *this;
}

bool Collection::operator==(const Collection& other) const
{
	if (pointerCollection.size() != other.pointerCollection.size()) return false;
	for (size_t i = 0; i < pointerCollection.size(); ++i) {
		if (!(*pointerCollection[i] == *other.pointerCollection[i])) return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const Collection& collection)
{
	os << "<svg version=\"1.1\"\n"
		"\twidth=\"300\" height=\"200\"\n"
		"\txmlns=\"http://www.w3.org/2000/svg\">\n\n";
	for (const auto& elem : collection.pointerCollection) {
		os << '\t' << elem->draw() << '\n';
	}
	os << "\n</svg>";
	return os;
}
