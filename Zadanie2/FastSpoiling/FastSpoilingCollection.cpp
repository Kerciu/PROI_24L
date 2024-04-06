#include <vector>
#include <iostream>
#include <iomanip>
#include "fastSpoiling.h"
#include "fastSpoilingCollection.h"
#include "Transport.h"
#include "Date.h"
#include "weightAndVolume.h"

// Element collection operations
void fastSpoilingCollection::searchForElement(const fastSpoiling& element) const {
    for (size_t i = 0; i < sizeOfCollection(); i++) {
        if (element == elementCollection[i]) {
            std::cout << element.getName() <<" is present at the index of " << i << '\n';
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

void fastSpoilingCollection::modifyName(size_t index, const fastSpoiling::Name& newName) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setName(newName);
}

void fastSpoilingCollection::modifyType(size_t index, const fastSpoiling::Type& newType) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setType(newType);
}

void fastSpoilingCollection::modifyProductionDate(size_t index, const Date& newProdDate) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setProductionDate(newProdDate.getDay(), newProdDate.getMonthDigits(), newProdDate.getYear());
}

void fastSpoilingCollection::modifyExpiryDate(size_t index, const Date& newExpirDate) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setExpirationDate(newExpirDate.getDay(), newExpirDate.getMonthDigits(), newExpirDate.getYear());
}

void fastSpoilingCollection::modifyTransport(size_t index, const Transport& newTransport) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setTransportTemperature(newTransport.getTemperature());
    elementCollection[index].setTransportPackaging(newTransport.getPackaging());
    elementCollection[index].setTransportHumidity(newTransport.getHumidity());
}

void fastSpoilingCollection::modifyWeightAndVolume(size_t index, const weightAndVolume& newWandV) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setWeight(newWandV.getWeight());
    elementCollection[index].setVolume(newWandV.getVolume());
}

void fastSpoilingCollection::modifyCollectionElement(size_t index,
    const fastSpoiling::Name& newName,
    const fastSpoiling::Type& newType,
    const Date& newProdDate,
    const Date& newExpirDate,
    const Transport& newTransport,
    const weightAndVolume& newWandV) {
    if (index >= sizeOfCollection()) {
        throw std::out_of_range("Invalid index!");
    }

    try {
        modifyName(index, newName);
        modifyType(index, newType);
        modifyProductionDate(index, newProdDate);
        modifyExpiryDate(index, newExpirDate);
        modifyTransport(index, newTransport);
        modifyWeightAndVolume(index, newWandV);
    }
    catch (const std::invalid_argument& e) {
        throw e;
    }
    catch (const std::out_of_range& e) {
        throw e;
    }
}


void fastSpoilingCollection::deleteElement(const fastSpoiling& element) {
    auto it = std::find(elementCollection.begin(), elementCollection.end(), element);
    if (it != elementCollection.end()) {
        elementCollection.erase(it);
    }
    else {
        throw std::out_of_range("Element not found in the collection!");
    }
}

bool fastSpoilingCollection::elementInCollection(const fastSpoiling& element) const {
    return std::find(elementCollection.begin(), elementCollection.end(), element) != elementCollection.end();
}

size_t fastSpoilingCollection::sizeOfCollection() const {
    return elementCollection.size();
}

std::ostream& operator<<(std::ostream& os, const fastSpoilingCollection& collect) {
    os << "Collection of elements:\n";
    for (const auto& element : collect.elementCollection) {
        os << element << '\n';
    }
    return os;
}