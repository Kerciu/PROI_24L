#include "fastSpoiling.h"
#include "Date.h"

using Name = std::string;
using Type = std::string;
using Transport = std::string;
using WeightAndVolume = weightAndVolume;
using Weight = double;
using Volume = double;

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
Name fastSpoiling::getName() const { return mName; }
Type fastSpoiling::getType() const { return mType; }
Transport fastSpoiling::getTransportMeans() const { return mTransportMeans;}

// Production Date Getters
std::string fastSpoiling::getProductionDateSlashed() const { return mProdDate.slashOutput(); }
std::string fastSpoiling::getProductionDateHyphened() const { return mProdDate.hyphenOutput(); }
std::string fastSpoiling::getProductionDateDotted() const { return mProdDate.dotOutput(); }
std::string fastSpoiling::getProductionDateShortenedYear() const { return mProdDate.shortenedYearOutput(); }
std::string fastSpoiling::getProductionDateVerbalizedMonth() const { return mProdDate.verbalMonthOutput(); }
std::string fastSpoiling::getProductionDateVerbalizedDay() const { return mProdDate.verbalDayOutput(); }

// Expiration Date Getters
std::string fastSpoiling::getExpirationDateSlashed() const { return mExpirDate.slashOutput(); }
std::string fastSpoiling::getExpirationDateHyphened() const { return mExpirDate.hyphenOutput(); }
std::string fastSpoiling::getExpirationDateDotted() const { return mExpirDate.dotOutput(); }
std::string fastSpoiling::getExpirationDateShortenedYear() const { return mExpirDate.shortenedYearOutput(); }
std::string fastSpoiling::getExpirationDateVerbalizedMonth() const { return mExpirDate.verbalMonthOutput(); }
std::string fastSpoiling::getExpirationDateVerbalizedDay() const { return mExpirDate.verbalDayOutput(); }

// Weight and Volume Getters
Weight fastSpoiling::getWeight() const { return mWeightAndVolume.getWeight(); }
Weight fastSpoiling::getWeight(const std::string& unitString) const { return mWeightAndVolume.getWeight(unitString); }
Volume fastSpoiling::getVolume() const { return mWeightAndVolume.getVolume(); }
Volume fastSpoiling::getVolume(const std::string& unitString) const { return mWeightAndVolume.getVolume(unitString); }

// Setters
void fastSpoiling::setName(Name n) { mName = n; }
void fastSpoiling::setType(Type t) { mType = t; }
void fastSpoiling::setTransportMeans(Transport tm) { mType = t; }
