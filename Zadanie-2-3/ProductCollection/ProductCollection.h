#pragma once
#include <vector>
#include "../Product/Product.h"
#include "../Transport/Transport.h"
#include "../Date/Date.h"
#include "../WeightAndVolume/weightAndVolume.h"
#include "../Price/Price.h"

class ProductCollection {
private:
    using collect = std::vector<Product>;

    collect elementCollection;

public:
    ProductCollection() { }

    // Element collection operations
    void searchForElement(const Product& element) const;
    void addNewElement(const Product& element);
    void modifyName(size_t index, const Product::Name& newName);
    void modifyType(size_t index, const Product::Type& newType);
    void modifyPrice(size_t index, const Price& newPrice);
    void modifyProductionDate(size_t index, const Date& newProdDate);
    void modifyExpiryDate(size_t index, const Date& newExpirDate);
    void modifyTransport(size_t index, const Transport& newTransport);
    void modifyWeightAndVolume(size_t index, const weightAndVolume& newWandV);
    void modifyCollectionElement(size_t index,
        const Product::Name& newName,
        const Product::Type& newType,
        const Price& newPrice,
        const Date& newProdDate,
        const Date& newExpirDate,
        const Transport& newTransport,
        const weightAndVolume& newWandV);
    void deleteElement(const Product& element);
    void displayContent(void);
    bool elementInCollection(const Product& element) const;
    size_t sizeOfCollection(void) const;

    friend std::ostream& operator<<(std::ostream& os, const ProductCollection& collect);
};


