#include "Product.h"
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

Product::Product()
    : mName("N/A"), mType("N/A"), mPrice(Price()), mProdDate(Date()), mExpirDate(Date()), mTransportMeans(Transport()), mWeightAndVolume(weightAndVolume(0, 0)) { }

Product::Product(const Name& n, const Type& t, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(Price()), mProdDate(Date()), mExpirDate(Date()), mTransportMeans(Transport()), mWeightAndVolume(wv) 
{
    if (semicolonInString(n) || semicolonInString(t)) throw std::out_of_range("There cannot be semicolons in string!");
}

Product::Product(const Name& n, const Type& t, const Price& p, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(Date()), mExpirDate(Date()), mTransportMeans(Transport()), mWeightAndVolume(wv)
{
    if (semicolonInString(n) || semicolonInString(t)) throw std::out_of_range("There cannot be semicolons in string!");
}

Product::Product(const Name& n, const Type& t, const Price& p, const Date& expDate, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(Date()), mExpirDate(expDate), mTransportMeans(Transport()), mWeightAndVolume(wv)
{
    if (semicolonInString(n) || semicolonInString(t)) throw std::out_of_range("There cannot be semicolons in string!");
}

Product::Product(const Name& n, const Type& t, const Price& p, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(Date()), mExpirDate(Date()), mTransportMeans(tm), mWeightAndVolume(wv)
{
    if (semicolonInString(n) || semicolonInString(t)) throw std::out_of_range("There cannot be semicolons in string!");
}

Product::Product(const Name& n, const Type& t, const Price& p, const Date& exd, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(Date()), mExpirDate(exd), mTransportMeans(tm), mWeightAndVolume(wv)
{
    if (semicolonInString(n) || semicolonInString(t)) throw std::out_of_range("There cannot be semicolons in string!");
}

Product::Product(const Name& n, const Type& t, const Price& p, const Date& pd, const Date& exd, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(pd), mExpirDate(exd), mTransportMeans(Transport()), mWeightAndVolume(wv)
{
    if (semicolonInString(n) || semicolonInString(t)) throw std::out_of_range("There cannot be semicolons in string!");
    if (pd > exd) {
        throw std::out_of_range("Expiration date cannot be less than production date!!!");
    }
}

Product::Product(const Name& n, const Type& t, const Date& prodDate, const Date& expDate, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(Price()), mProdDate(prodDate), mExpirDate(expDate), mTransportMeans(tm), mWeightAndVolume(wv) { }

Product::Product(const Name& n, const Type& t, const Price& p, const Date& pd, const Date& exd, const Transport& tm, const WeightAndVolume& wv)
    : mName(n), mType(t), mPrice(p), mProdDate(pd), mExpirDate(exd), mTransportMeans(tm), mWeightAndVolume(wv)
{
    if (pd > exd) {
        throw std::out_of_range("Expiration date cannot be less than production date!!!");
    }
}

//TODO MAKE A FUNCTION THAT SEEKS SEMICOLONS IN STRING DATAS
bool Product::semicolonInString(const std::string str) {
    for (const char& ch : str) {
        if (ch == ';') return true;
    }
    return false;
}

// Getters
Name Product::getName() const { return mName; }
Type Product::getType() const { return mType; }

Transport::Temperature Product::getTransportTemperature() const
{
    return mTransportMeans.getTemperature();
}

Transport::Packaging Product::getTransportPackaging() const
{
    return mTransportMeans.getPackaging();
}

Transport::Humidity Product::getTransportHumidity() const
{
    return mTransportMeans.getHumidity();
}

// Price getters
double Product::getPriceValue() { return mPrice.getValue(); }
std::string Product::getPriceCurrency() { return mPrice.getCurrency(); }
int Product::getPriceCurrencyCode() { return mPrice.getCurrencyCode(); }
std::string Product::getPriceCurrencyName() { return mPrice.getCurrencyName(); }

// Production Date Getters
std::string Product::getProductionDateSlashed() const { return mProdDate.slashOutput(); }
std::string Product::getProductionDateHyphened() const { return mProdDate.hyphenOutput(); }
std::string Product::getProductionDateDotted() const { return mProdDate.dotOutput(); }
std::string Product::getProductionDateShortenedYear() const { return mProdDate.shortenedYearOutput(); }
std::string Product::getProductionDateVerbalizedMonth() const { return mProdDate.verbalMonthOutput(); }
std::string Product::getProductionDateVerbalizedDay() const { return mProdDate.verbalDayOutput(); }

int Product::getProductionYear() const
{
    return mProdDate.getYear();
}

// Expiration Date Getters
std::string Product::getExpirationDateSlashed() const { return mExpirDate.slashOutput(); }
std::string Product::getExpirationDateHyphened() const { return mExpirDate.hyphenOutput(); }
std::string Product::getExpirationDateDotted() const { return mExpirDate.dotOutput(); }
std::string Product::getExpirationDateShortenedYear() const { return mExpirDate.shortenedYearOutput(); }
std::string Product::getExpirationDateVerbalizedMonth() const { return mExpirDate.verbalMonthOutput(); }
std::string Product::getExpirationDateVerbalizedDay() const { return mExpirDate.verbalDayOutput(); }

int Product::getExpirationYear() const
{
    return mExpirDate.getYear();
}

// Weight and Volume Getters
Weight Product::getWeight() const { return mWeightAndVolume.getWeight(); }
Weight Product::getWeight(const std::string& unitString) const { return mWeightAndVolume.getWeight(unitString); }
Volume Product::getVolume() const { return mWeightAndVolume.getVolume(); }
Volume Product::getVolume(const std::string& unitString) const { return mWeightAndVolume.getVolume(unitString); }

// Setters
void Product::setName(Name n) { mName = n; }
void Product::setType(Type t) { mType = t; }

void Product::setPriceValue(double newVal)
{
    mPrice.setValue(newVal);
}

void Product::setPriceCurrency(std::string newCurr)
{
    mPrice.setCurrency(newCurr);
}

// Transport Means Setters
void Product::setTransportTemperature(double t) { mTransportMeans.setTemperature(t); }
void Product::setTransportPackaging(std::string p) { mTransportMeans.setPackaging(p); }
void Product::setTransportHumidity(double h) { mTransportMeans.setHumidity(h); }

// Date Setters
void Product::setProductionDate(int d, int m, int y) {
    mProdDate.setDay(d);
    mProdDate.setMonth(m);
    mProdDate.setYear(y);
}

void Product::setExpirationDate(int d, int m, int y) {
    mExpirDate.setDay(d);
    mExpirDate.setMonth(m);
    mExpirDate.setYear(y);
}

// Weight and Volume Setters
void Product::setWeight(Weight w)
{
    mWeightAndVolume.setWeight(w);
}

void Product::setVolume(Volume v)
{
    mWeightAndVolume.setVolume(v);
}

// Operator Overloads
bool Product::operator==(const Product& other) const {
    return mName == other.mName && mType == other.mType && mPrice == other.mPrice && mProdDate == other.mProdDate &&
        mExpirDate == other.mExpirDate && mTransportMeans == other.mTransportMeans &&
        mWeightAndVolume == other.mWeightAndVolume;
}

std::ostream& operator<<(std::ostream& os, const Product& fs) {
    os << fs.mName << ';';
    os << fs.mType << ';';
    os << fs.mPrice.getValue() << ';';
    os << fs.mPrice.getCurrency() << ';';

    os << fs.mProdDate.getDay() << ';';
    os << fs.mProdDate.getMonthDigits() << ';';
    os << fs.mProdDate.getYear() << ';';
    os << fs.mExpirDate.getDay() << ';';
    os << fs.mExpirDate.getMonthDigits() << ';';
    os << fs.mExpirDate.getYear() << ';';
    
    os << fs.mTransportMeans << ';';
    os << fs.mWeightAndVolume << '\n';
    return os;
}

std::istream& operator>>(std::istream& is, Product& fs)
{
    std::string line;
    std::getline(is, line);

    std::istringstream iss(line);
    std::string name, type, price, curr, prodDateDay, prodDateMonth, prodDateYear, expirDateDay, expirDateMonth, expirDateYear, temp, pack, humid, weight, volume;
    std::getline(iss, name, ';');
    std::getline(iss, type, ';');
    std::getline(iss, price, ';');
    std::getline(iss, curr, ';');
    std::getline(iss, prodDateDay, ';');
    std::getline(iss, prodDateMonth, ';');
    std::getline(iss, prodDateYear, ';');
    std::getline(iss, expirDateDay, ';');
    std::getline(iss, expirDateMonth, ';');
    std::getline(iss, expirDateYear, ';');
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
    std::istringstream(prodDateDay) >> productionDate;
    std::istringstream(prodDateMonth) >> productionDate;
    std::istringstream(prodDateYear) >> productionDate;
    std::istringstream(expirDateDay) >> expirationDate;
    std::istringstream(expirDateMonth) >> expirationDate;
    std::istringstream(expirDateYear) >> expirationDate;
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