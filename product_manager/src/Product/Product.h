#pragma once
#include <string>
#include "../Transport/Transport.h"
#include "../Date/Date.h"
#include "../Price/Price.h"
#include "../WeightAndVolume/weightAndVolume.h"

class Product {
private:
    using Name = std::string;
    using Type = std::string;
    using WeightAndVolume = weightAndVolume;
    using Weight = double;
    using Volume = double;

    Name mName;
    Type mType;
    Price mPrice;
    Date mProdDate;
    Date mExpirDate;
    Transport mTransportMeans;
    WeightAndVolume mWeightAndVolume;

    friend class ProductCollection;

public:
    // Constructors
    Product();
    Product(const Name& n, const Type& t, const WeightAndVolume& wv);
    Product(const Name& n, const Type& t, const Price&, const WeightAndVolume& wv);
    Product(const Name& n, const Type& t, const Price&, const Date& expDate, const WeightAndVolume& wv);
    Product(const Name& n, const Type& t, const Price&, const Transport& tm, const WeightAndVolume& wv);
    Product(const Name& n, const Type& t, const Price&, const Date& expDate, const Transport& tm, const WeightAndVolume& wv);
    Product(const Name& n, const Type& t, const Price&, const Date& prodDate, const Date& expDate, const WeightAndVolume& wv);
    Product(const Name& n, const Type& t, const Date& prodDate, const Date& expDate, const Transport& tm, const WeightAndVolume& wv);
    Product(const Name& n, const Type& t, const Price&, const Date& prodDate, const Date& expDate, const Transport& tm, const WeightAndVolume& wv);

    static bool semicolonInString(const std::string str);

    // Getters
    Name getName() const;
    Type getType() const;

    // Transport Parameters
    Transport::Temperature getTransportTemperature() const;
    Transport::Packaging getTransportPackaging() const;
    Transport::Humidity getTransportHumidity() const;

    // Price Getters
    double getPriceValue();
    std::string getPriceCurrency();
    int getPriceCurrencyCode();
    std::string getPriceCurrencyName();

    // Production Date Getters
    std::string getProductionDateSlashed() const;
    std::string getProductionDateHyphened() const;
    std::string getProductionDateDotted() const;
    std::string getProductionDateShortenedYear() const;
    std::string getProductionDateVerbalizedMonth() const;
    std::string getProductionDateVerbalizedDay() const;

    // Used for defining "N/A" Year
    int getProductionYear() const;

    // Expiration Date Getters
    std::string getExpirationDateSlashed() const;
    std::string getExpirationDateHyphened() const;
    std::string getExpirationDateDotted() const;
    std::string getExpirationDateShortenedYear() const;
    std::string getExpirationDateVerbalizedMonth() const;
    std::string getExpirationDateVerbalizedDay() const;

    // Used for defining "N/A" Year
    int getExpirationYear() const;

    // Weight and Volume Getters
    Weight getWeight() const;
    Weight getWeight(const std::string& unitString) const;
    Volume getVolume() const;
    Volume getVolume(const std::string& unitString) const;
    
    // Setters
    void setName(Name n);
    void setType(Type t);

    // Price Setters
    void setPriceValue(double newVal);
    void setPriceCurrency(std::string newCurr);

    // Transport Setters
    void setTransportTemperature(double t);
    void setTransportPackaging(std::string p);
    void setTransportHumidity(double h);

    // Date Setters
    void setProductionDate(int d, int m, int y);
    void setExpirationDate(int d, int m, int y);

    // Weight and Volume Setters
    void setWeight(Weight w);
    void setVolume(Volume w);

    // Operator overloads
    bool operator==(const Product& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Product& fs);
    friend std::istream& operator>>(std::istream& is, Product& fs);
};
