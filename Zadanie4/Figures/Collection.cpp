#include <exception>
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

void Collection::deleteItem(std::unique_ptr<Figure> item)
{
	auto it = std::find_if(pointerCollection.begin(), pointerCollection.end(),
		[&item](const std::unique_ptr<Figure>& ptr) { return *ptr == *item; });

	if (it != pointerCollection.end()) {
		pointerCollection.erase(it);
	}
	else {
		throw std::out_of_range("No such element found in the collection");
	}
}

bool Collection::findItem(std::unique_ptr<Figure> item) const
{
	for (const auto& ptr : pointerCollection) {
		if (*ptr == *item) {
			return true;
		}
	}
	return false;
}

std::unique_ptr<Figure> Collection::popItem()
{
	if (collectionSize() != 0) {
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
	if (findItem(std::make_unique<Figure>(*item))) {
		pointerCollection.emplace_back(std::make_unique<Figure>(*item));
	}
	else {
		throw std::out_of_range("Element already in collection");
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
		if (!result.findItem(std::make_unique<Figure>(*item))) {
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
	if (collectionSize() != other.collectionSize()) return false;
	for (size_t i = 0; i < collectionSize(); ++i) {
		if (!(*pointerCollection[i] == *other.pointerCollection[i])) return false;
	}
	return true;
}
