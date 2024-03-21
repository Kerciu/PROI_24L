#pragma once
#include <string>
#include <vector>
#include "Date.h"
#include "weightAndVolume.h"

class fastSpoiling {
    private:
    using name = std::string;
    using type = std::string;
    using transport = std::string

    name mName;
    type mType;
    Date mProdDate;
    Date mExpirdate;
    transport mTransportMeans;
    weightAndVolume mWeightAndVolume;
    std::vector<fastSpoiling> elementCollection;

public:
    // Constructors
    fastSpoiling(const name& n, const type& t, const weightAndVolume& wv) : mName(n), mType(t), mWeightAndVolume(wv) {}

    fastSpoiling(const name& n, const type& t, const Date& pd, const weightAndVolume& wv) : mName(n), mType(t), mProdDate(pd), mWeightAndVolume(wv) {}

    fastSpoiling(const name& n, const type& t, const Date& pd, const transport& tm, const weightAndVolume& wv)
        : mName(n), mType(t), mProdDate(pd), mTransportMeans(tm), mWeightAndVolume(wv) {}

    fastSpoiling(const name& n, const type& t, const Date& pd, const Date& ed, const weightAndVolume& wv)
        : mName(n), mType(t), mProdDate(pd), mExpirDate(ed), mWeightAndVolume(wv) {}

    fastSpoiling(const name& n, const type& t, const Date& pd, const Date& ed, const transport& tm, const weightAndVolume& wv)
        : mName(n), mType(t), mProdDate(pd), mExpirDate(ed), mTransportMeans(tm), mWeightAndVolume(wv) {}

    // Getters
    name getName() const { return mName; }
    type getType() const { return mType; }
    transport getTransportMeans() const { return mTransportMeans; }

    // Date Getters
    std::string getDateSlashed(void);
    std::string getDateHyphened(void);
    std::string getDateDotted(void);
    std::string getDateShortenedYear(void);
    std::string getDateVerbalizedMonth(void);
    std::string getDateVerbalizedDay(void);

    // Setters
    void setName(name n);
    void setType(type t);
    void setTransportMeans(transportMeans tm);

    // Element collection operations
    void searchForElement(const fastSpoiling& element);
    void addNewElement(const fastSpoiling& element);
    void modifyCollectionElement(fastSpoiling& element);
    void deleteElement(const fastSpoiling& element);
    bool elementInCollection(const fastSpoiling& element) const;
    int sizeOfCollection(void) const;

};