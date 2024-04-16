#include <vector>
#include <iostream>
#include <iomanip>
#include "../Product/Product.h"
#include "ProductCollection.h"
#include "../Transport/Transport.h"
#include "../Date/Date.h"
#include "../WeightAndVolume/weightAndVolume.h"
#include "../Price/Price.h"

#define P(x) std::cout << x << '\n'

// Element collection operations
void ProductCollection::searchForElement(const Product& element) const {
    for (size_t i = 0; i < sizeOfCollection(); i++) {
        if (element == elementCollection[i]) {
            std::cout << element.getName() <<" is present at the index of " << i << '\n';
            return;
        }
    }
    throw std::out_of_range("Element was not found!");
}

void ProductCollection::addNewElement(const Product& element) {
    for (size_t i = 0; i < elementCollection.size(); i++) {
        if (element == elementCollection[i]) {
            throw std::invalid_argument("Element already in the collection!");
        }
    }
    elementCollection.push_back(element);
}

void ProductCollection::modifyName(size_t index, const Product::Name& newName) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setName(newName);
}

void ProductCollection::modifyType(size_t index, const Product::Type& newType) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setType(newType);
}

void ProductCollection::modifyPrice(size_t index, const Price& newPrice)
{
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setPriceValue(newPrice.getValue());
    elementCollection[index].setPriceCurrency(newPrice.getCurrency());
}

void ProductCollection::modifyProductionDate(size_t index, const Date& newProdDate) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setProductionDate(newProdDate.getDay(), newProdDate.getMonthDigits(), newProdDate.getYear());
}

void ProductCollection::modifyExpiryDate(size_t index, const Date& newExpirDate) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setExpirationDate(newExpirDate.getDay(), newExpirDate.getMonthDigits(), newExpirDate.getYear());
}

void ProductCollection::modifyTransport(size_t index, const Transport& newTransport) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setTransportTemperature(newTransport.getTemperature());
    elementCollection[index].setTransportPackaging(newTransport.getPackaging());
    elementCollection[index].setTransportHumidity(newTransport.getHumidity());
}

void ProductCollection::modifyWeightAndVolume(size_t index, const weightAndVolume& newWandV) {
    if (!elementInCollection(elementCollection[index])) {
        throw std::invalid_argument("Element not in the collection!");
    }
    elementCollection[index].setWeight(newWandV.getWeight());
    elementCollection[index].setVolume(newWandV.getVolume());
}

void ProductCollection::modifyCollectionElement(size_t index,
    const Product::Name& newName,
    const Product::Type& newType,
    const Price& newPrice,
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
        modifyPrice(index, newPrice);
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


void ProductCollection::deleteElement(const Product& element) {
    auto it = std::find(elementCollection.begin(), elementCollection.end(), element);
    if (it != elementCollection.end()) {
        elementCollection.erase(it);
    }
    else {
        throw std::out_of_range("Element not found in the collection!");
    }
}

void ProductCollection::displayContent(void) {
    int index = 1;
    for (auto it = elementCollection.begin(); it != elementCollection.end(); it++) {
        P("Elem # " << index);
        P("Name: " << (*it).getName());
        P("Type: " << (*it).getType());
        P("Price: " << (*it).getPriceValue() << ' ' << (*it).getPriceCurrencyName());
        ((*it).getProductionYear() != 1) ? P("Production date: " << (*it).getProductionDateSlashed()) : P("Production date: N/A");
        ((*it).getExpirationYear() != 1) ? P("Expiration date: " << (*it).getExpirationDateSlashed()) : P("Expiration date : N/A");
        P("Transport Temperature: " << (*it).getTransportTemperature() << "�C");
        P("Transport Means/Packaging: " << (*it).getTransportPackaging());
        P("Transport Humidity: " << (*it).getTransportHumidity() << '%');
        P("Product Weight: " << (*it).getWeight() << " kg's");
        P("Product Volume: " << (*it).getVolume() << " liters");
        std::cout << '\n';
        index++;
    }
}

bool ProductCollection::elementInCollection(const Product& element) const {
    return std::find(elementCollection.begin(), elementCollection.end(), element) != elementCollection.end();
}

size_t ProductCollection::sizeOfCollection() const {
    return elementCollection.size();
}

std::ostream& operator<<(std::ostream& os, const ProductCollection& collect) {
    for (const auto& element : collect.elementCollection) {
        os << element;
    }
    return os;
}