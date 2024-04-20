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

inline void Collection::deleteItem(std::unique_ptr<Figure> item)
{
}

inline bool Collection::findItem(std::unique_ptr<Figure> item) const
{
	return false;
}

inline size_t Collection::collectionSize() const
{
	return size_t();
}

inline void Collection::addItem(std::unique_ptr<Figure> item)
{
	pointerCollection.push_back(std::move(item));
}

inline std::unique_ptr<Figure> Collection::getLastItem()
{
	size_t collectionSize = pointerCollection.size();
	if (collectionSize > 0) return std::move(pointerCollection[collectionSize - 1]);
	else throw std::out_of_range("Insufficient elements in the collecton");
}

inline void Collection::operator+(const Collection& other) const
{
}

inline void Collection::operator=(const Collection& other) const
{
}

inline void Collection::operator==(const Collection& other) const
{
}

inline std::ostream& operator<<(std::ostream& os, const Collection& collect)
{
	os << "Hello World!\n";
	return os;
}

inline std::istream& operator>>(std::istream& is, const Collection& collect)
{
	is >> collect;
	return is;
}
