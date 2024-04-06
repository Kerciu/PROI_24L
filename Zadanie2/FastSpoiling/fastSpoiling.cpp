#include "fastSpoiling.h"
#include "Date.h"
#include "Transport.h"
#include "weightAndVolume.h"
#include <iomanip>
#include <ostream>
#include <sstream>

using Name = std::string;
using Type = std::string;
using WeightAndVolume = weightAndVolume;
using Weight = double;
using Volume = double;

fastSpoiling::fastSpoiling()
    : mName("N/A"), mType("N/A"), mProdDate(Date()), mExpirDate(Date()), mTransportMeans(Transport()), mWeightAndVolume(weightAndVolume(0, 0)) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const WeightAndVolume& wv)
    : mName(n), mType(t), mProdDate(Date(1, 1, 1)), mExpirDate(Date(2, 1, 1)), mTransportMeans(Transport()), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Date& expDate, const WeightAndVolume& wv)
    : mName(n), mType(t), mProdDate(Date(1, 1, 1)), mExpirDate(expDate), mTransportMeans(Transport()), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mProdDate(Date(1, 1, 1)), mExpirDate(Date(2, 1, 1)), mTransportMeans(tm), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Date& exd, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mProdDate(Date(1, 1, 1)), mExpirDate(exd), mTransportMeans(tm), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Date& pd, const Date& exd, const WeightAndVolume& wv)
    : mName(n), mType(t), mProdDate(pd), mExpirDate(exd), mTransportMeans(Transport()), mWeightAndVolume(wv)
{
    if (pd > exd) {
        throw std::out_of_range("Expiration date cannot be less than production date!!!");
    }
}

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Date& pd, const Date& exd, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mProdDate(pd), mExpirDate(exd), mTransportMeans(tm), mWeightAndVolume(wv)
{
    if (pd > exd) {
        throw std::out_of_range("Expiration date cannot be less than production date!!!");
    }
}

// Getters
Name fastSpoiling::getName() const { return mName; }
Type fastSpoiling::getType() const { return mType; }

Transport::Temperature fastSpoiling::getTransportTemperature() const
{
    return mTransportMeans.getTemperature();
}

Transport::Packaging fastSpoiling::getTransportPackaging() const
{
    return mTransportMeans.getPackaging();
}

Transport::Humidity fastSpoiling::getTransportHumidity() const
{
    return mTransportMeans.getHumidity();
}

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

// Transport Means Setters
void fastSpoiling::setTransportTemperature(double t) { mTransportMeans.setTemperature(t); }
void fastSpoiling::setTransportPackaging(std::string p) { mTransportMeans.setPackaging(p); }
void fastSpoiling::setTransportHumidity(double h) { mTransportMeans.setHumidity(h); }

// Date Setters
void fastSpoiling::setProductionDate(int d, int m, int y) {
    mProdDate.setDay(d);
    mProdDate.setMonth(m);
    mProdDate.setYear(y);
}

void fastSpoiling::setExpirationDate(int d, int m, int y) {
    mExpirDate.setDay(d);
    mExpirDate.setMonth(m);
    mExpirDate.setYear(y);
}

// Weight and Volume Setters
void fastSpoiling::setWeight(Weight w)
{
    mWeightAndVolume.setWeight(w);
}

void fastSpoiling::setVolume(Volume v)
{
    mWeightAndVolume.setVolume(v);
}

// Operator Overloads
bool fastSpoiling::operator==(const fastSpoiling& other) const {
    return mName == other.mName && mType == other.mType && mProdDate == other.mProdDate &&
        mExpirDate == other.mExpirDate && mTransportMeans == other.mTransportMeans &&
        mWeightAndVolume == other.mWeightAndVolume;
}

std::ostream& operator<<(std::ostream& os, const fastSpoiling& fs) {
    os << fs.mName << ' ';
    os << fs.mType << ' ';
    
    if (fs.mProdDate.getYear() == 1) {
        os << "N/A ";
    }
    else {
        os << fs.mProdDate.slashOutput() << ' ';
    }

    if (fs.mExpirDate.getYear() == 1) {
        os << "N/A ";
    }
    else {
        os << fs.mExpirDate.slashOutput() << ' ';
    }
    
    os << fs.mTransportMeans << ' ';
    os << fs.mWeightAndVolume << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, fastSpoiling& fs)
{
    std::string name, type, prodDate, expirDate, packaging;
    double temp, humid, weight, volume;

    is >> fs.mName >> fs.mType >> fs.mProdDate >> fs.mExpirDate >> fs.mTransportMeans >> fs.mWeightAndVolume;

    return is;
}