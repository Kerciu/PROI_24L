#include <vector>
#include "fastSpoilingCollection.h"

fastSpoilingCollection::fastSpoilingCollection() { }

// Element collection operations
void fastSpoilingCollection::searchForElement(const fastSpoiling& element) const {
    for (size_t i = 0; i < sizeOfCollection(); i++) {
        if (element == elementCollection[i]) {
            std::cout << "Element is present at the index of " << i << '\n';
            return;
        }
    }
    throw std::out_of_range("Element was not found!");
}

void fastSpoilingCollection::addNewElement(const fastSpoiling& element) {
    for (size_t i = 0; i < elementCollection.size(); i++) {
        if (element == elementCollection[i]) {
            throw std::invalid_argument("Element already in the collection!");
        }
    }
    elementCollection.push_back(element);
}

void fastSpoilingCollection::modifyCollectionElement(fastSpoiling& element) {
    if (!elementInCollection(element)) {
        throw std::invalid_argument("Element not in the collection!");
    }
    // Logic
}

void fastSpoilingCollection::deleteElement(const fastSpoiling& element) const {
    auto it = std::find(elementCollection.begin(), elementCollection.end(), element);
    if (it != elementCollection.end()) {
        elementCollection.erase(it);
    }
}

bool fastSpoilingCollection::elementInCollection(const fastSpoiling& element) const {
    return std::find(elementCollection.begin(), elementCollection.end(), element) != elementCollection.end();
}

int fastSpoilingCollection::sizeOfCollection() const {
    return elementCollection.size();
}