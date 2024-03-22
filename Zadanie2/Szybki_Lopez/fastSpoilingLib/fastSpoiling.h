#pragma once
#include <string>
#include "Date.h"
#include "weightAndVolume.h"
#include "fastSpoilingCollection.h"

class fastSpoiling {
    private:
    using Name = std::string;
    using Type = std::string;
    using Transport = std::string;
    using WeightAndVolume = weightAndVolume;
    using Weight = double;
    using Volume = double;

    Name mName;
    Type mType;
    Date mProdDate;
    Date mExpirdate;
    Transport mTransportMeans;
    WeightAndVolume mWeightAndVolume;

    friend class fastSpoilingCollection;

public:
    // Constructors
    fastSpoiling::fastSpoiling(const Name& n, const Type& t, const WeightAndVolume& wv)
        : mName(n), mType(t), mWeightAndVolume(wv) {}

    fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Date& pd, const WeightAndVolume& wv)
        : mName(n), mType(t), mProdDate(pd), mWeightAndVolume(wv) {}

    fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Date& pd, const Transport& tm, const WeightAndVolume& wv)
        : mName(n), mType(t), mProdDate(pd), mTransportMeans(tm), mWeightAndVolume(wv) {}

    fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Date& pd, const Date& ed, const WeightAndVolume& wv)
        : mName(n), mType(t), mProdDate(pd), mExpirDate(ed), mWeightAndVolume(wv) {}

    fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Date& pd, const Date& ed, const Transport& tm, const WeightAndVolume& wv)
        : mName(n), mType(t), mProdDate(pd), mExpirDate(ed), mTransportMeans(tm), mWeightAndVolume(wv) {}

    // Getters
    name getName() const;
    type getType() const;
    transport getTransportMeans() const;

    // Production Date Getters
    std::string fastSpoiling::getProductionDateSlashed() const;
    std::string fastSpoiling::getProductionDateHyphened() const;
    std::string fastSpoiling::getProductionDateDotted() const;
    std::string fastSpoiling::getProductionDateShortenedYear() const;
    std::string fastSpoiling::getProductionDateVerbalizedMonth() const;
    std::string fastSpoiling::getProductionDateVerbalizedDay() const;

    // Expiration Date Getters
    std::string fastSpoiling::getExpirationDateSlashed() const;
    std::string fastSpoiling::getExpirationDateHyphened() const;
    std::string fastSpoiling::getExpirationDateDotted() const;
    std::string fastSpoiling::getExpirationDateShortenedYear() const;
    std::string fastSpoiling::getExpirationDateVerbalizedMonth() const;
    std::string fastSpoiling::getExpirationDateVerbalizedDay() const;

    // Weight and Volume Getters
    Weight fastSpoiling::getWeight() const;
    Weight fastSpoiling::getWeight(const std::string& unitString) const;
    Volume fastSpoiling::getVolume() const;
    Volume fastSpoiling::getVolume(const std::string& unitString) const;

    // Setters
    void setName(Name n);
    void setType(Type t);
    void setTransportMeans(Transport tm);
};