#include <vector>
#include "fastSpoiling.h"

class fastSpoilingCollection {
    private:
    using collect = std::vector<fastSpoiling>;
    collect elementCollection;

    public:
    fastSpoilingCollection() { }

    // Element collection operations
    void searchForElement(const fastSpoiling& element);
    void addNewElement(const fastSpoiling& element);
    void modifyCollectionElement(fastSpoiling& element);
    void deleteElement(const fastSpoiling& element);
    bool elementInCollection(const fastSpoiling& element) const;
    int sizeOfCollection(void) const;
};