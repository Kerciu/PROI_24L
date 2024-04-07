#pragma once
#include <vector>
#include "../FastSpoiling/fastSpoiling.h"
#include "../Transport/Transport.h"
#include "../Date/Date.h"
#include "../WeightAndVolume/weightAndVolume.h"

class fastSpoilingCollection {
private:
    using collect = std::vector<fastSpoiling>;

    collect elementCollection;

public:
    fastSpoilingCollection() { }

    // Element collection operations
    void searchForElement(const fastSpoiling& element) const;
    void addNewElement(const fastSpoiling& element);
    void modifyName(size_t index, const fastSpoiling::Name& newName);
    void modifyType(size_t index, const fastSpoiling::Type& newType);
    void modifyProductionDate(size_t index, const Date& newProdDate);
    void modifyExpiryDate(size_t index, const Date& newExpirDate);
    void modifyTransport(size_t index, const Transport& newTransport);
    void modifyWeightAndVolume(size_t index, const weightAndVolume& newWandV);
    void modifyCollectionElement(size_t index,
        const fastSpoiling::Name& newName,
        const fastSpoiling::Type& newType,
        const Date& newProdDate,
        const Date& newExpirDate,
        const Transport& newTransport,
        const weightAndVolume& newWandV);
    void deleteElement(const fastSpoiling& element);
    bool elementInCollection(const fastSpoiling& element) const;
    size_t sizeOfCollection(void) const;

    friend std::ostream& operator<<(std::ostream& os, const fastSpoilingCollection& collect);
};


