#include "fastSpoiling.h"
#include "../Date/Date.h"
#include "../Transport/Transport.h"
#include "../WeightAndVolume/weightAndVolume.h"
#include <iomanip>
#include <ostream>
#include <sstream>

using Name = std::string;
using Type = std::string;
using WeightAndVolume = weightAndVolume;
using Weight = double;
using Volume = double;

fastSpoiling::fastSpoiling()
    : mName("N/A"), mType("N/A"), mPrice(Price()), mProdDate(Date()), mExpirDate(Date()), mTransportMeans(Transport()), mWeightAndVolume(weightAndVolume(0, 0)) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(Price()), mProdDate(Date()), mExpirDate(Date()), mTransportMeans(Transport()), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Price& p, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(Date()), mExpirDate(Date()), mTransportMeans(Transport()), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Price& p, const Date& expDate, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(Date()), mExpirDate(expDate), mTransportMeans(Transport()), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Price& p, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(Date()), mExpirDate(Date()), mTransportMeans(tm), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Price& p, const Date& exd, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(Date()), mExpirDate(exd), mTransportMeans(tm), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Price& p, const Date& pd, const Date& exd, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(pd), mExpirDate(exd), mTransportMeans(Transport()), mWeightAndVolume(wv)
{
    if (pd > exd) {
        throw std::out_of_range("Expiration date cannot be less than production date!!!");
    }
}

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Date& prodDate, const Date& expDate, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(Price()), mProdDate(prodDate), mExpirDate(expDate), mTransportMeans(tm), mWeightAndVolume(wv) { }

fastSpoiling::fastSpoiling(const Name& n, const Type& t, const Price& p, const Date& pd, const Date& exd, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(pd), mExpirDate(exd), mTransportMeans(tm), mWeightAndVolume(wv)
{
    if (pd > exd) {
        throw std::out_of_range("Expiration date cannot be less than production date!!!");
    }
}

//TODO MAKE A FUNCTION THAT SEEKS SEMICOLONS IN STRING DATAS

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

// Price getters
double fastSpoiling::getPriceValue() { return mPrice.getValue(); }
std::string fastSpoiling::getPriceCurrency() { return mPrice.getCurrency(); }
int fastSpoiling::getPriceCurrencyCode() { return mPrice.getCurrencyCode(); }
std::string fastSpoiling::getPriceCurrencyName() { return mPrice.getCurrencyName(); }

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

void fastSpoiling::setPriceValue(double newVal)
{
    mPrice.setValue(newVal);
}

void fastSpoiling::setPriceCurrency(std::string newCurr)
{
    mPrice.setCurrency(newCurr);
}

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
    os << fs.mName << ';';
    os << fs.mType << ';';
    
    if (fs.mProdDate.getYear() == 1) {
        os << "N/A;";
    }
    else {
        os << fs.mProdDate.slashOutput() << ';';
    }

    if (fs.mExpirDate.getYear() == 1) {
        os << "N/A;";
    }
    else {
        os << fs.mExpirDate.slashOutput() << ';';
    }
    
    os << fs.mTransportMeans << ';';
    os << fs.mWeightAndVolume << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, fastSpoiling& fs)
{
    std::string line;
    std::getline(is, line);

    std::istringstream iss(line);
    std::string name, type, price, curr, prodDate, expirDate, temp, pack, humid, weight, volume;
    std::getline(iss, name, ';');
    std::getline(iss, type, ';');
    std::getline(iss, price, ';');
    std::getline(iss, curr, ';');
    std::getline(iss, prodDate, ';');
    std::getline(iss, expirDate, ';');
    std::getline(iss, temp, ';');
    std::getline(iss, pack, ';');
    std::getline(iss, humid, ';');
    std::getline(iss, weight, ';');
    std::getline(iss, volume, '\n');

    fs.mName = name;
    fs.mType = type;

    Price priceClass;
    std::istringstream(price) >> priceClass;
    std::istringstream(curr) >> priceClass;
    fs.mPrice = priceClass;

    Date productionDate;
    Date expirationDate;
    std::istringstream(prodDate) >> productionDate;
    std::istringstream(expirDate) >> expirationDate;
    fs.mProdDate = productionDate;
    fs.mExpirDate = expirationDate;

    Transport transport;
    std::istringstream(temp) >> transport;
    transport.setPackaging(pack);
    std::istringstream(humid) >> transport;
    fs.mTransportMeans = transport;

    WeightAndVolume weightAndVolume;
    std::istringstream(weight) >> weightAndVolume;
    std::istringstream(volume) >> weightAndVolume;
    fs.mWeightAndVolume = weightAndVolume;

    return is;
}