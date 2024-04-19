#include <exception>
#include "Figure.h"
#include "Collection.h"
#include <stdexcept>

Collection::Collection(std::unique_ptr<Figure> itemToCollect)
{
	pointerCollection.push_back(std::move(itemToCollect));
}

Collection::Collection(std::vector<std::unique_ptr<Figure>> pointerCollection) : pointerCollection(std::move(pointerCollection)) { }

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


