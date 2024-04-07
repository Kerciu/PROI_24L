#pragma once
#include <string>
#include "../Transport/Transport.h"
#include "../Date/Date.h"
#include "../WeightAndVolume/weightAndVolume.h"

class fastSpoiling {
private:
    using Name = std::string;
    using Type = std::string;
    using WeightAndVolume = weightAndVolume;
    using Weight = double;
    using Volume = double;

    Name mName;
    Type mType;
    Date mProdDate;
    Date mExpirDate;
    Transport mTransportMeans;
    WeightAndVolume mWeightAndVolume;

    friend class fastSpoilingCollection;

public:
    // Constructors
    fastSpoiling();
    fastSpoiling(const Name& n, const Type& t, const WeightAndVolume& wv);
    fastSpoiling(const Name& n, const Type& t, const Date& expDate, const WeightAndVolume& wv);
    fastSpoiling(const Name& n, const Type& t, const Transport& tm, const WeightAndVolume& wv);
    fastSpoiling(const Name& n, const Type& t, const Date& expDate, const Transport& tm, const WeightAndVolume& wv);
    fastSpoiling(const Name& n, const Type& t, const Date& prodDate, const Date& expDate, const WeightAndVolume& wv);
    fastSpoiling(const Name& n, const Type& t, const Date& prodDate, const Date& expDate, const Transport& tm, const WeightAndVolume& wv);

    // Getters
    Name getName() const;
    Type getType() const;

    // Transport Parameters
    Transport::Temperature getTransportTemperature() const;
    Transport::Packaging getTransportPackaging() const;
    Transport::Humidity getTransportHumidity() const;

    // Production Date Getters
    std::string getProductionDateSlashed() const;
    std::string getProductionDateHyphened() const;
    std::string getProductionDateDotted() const;
    std::string getProductionDateShortenedYear() const;
    std::string getProductionDateVerbalizedMonth() const;
    std::string getProductionDateVerbalizedDay() const;

    // Expiration Date Getters
    std::string getExpirationDateSlashed() const;
    std::string getExpirationDateHyphened() const;
    std::string getExpirationDateDotted() const;
    std::string getExpirationDateShortenedYear() const;
    std::string getExpirationDateVerbalizedMonth() const;
    std::string getExpirationDateVerbalizedDay() const;

    // Weight and Volume Getters
    Weight getWeight() const;
    Weight getWeight(const std::string& unitString) const;
    Volume getVolume() const;
    Volume getVolume(const std::string& unitString) const;

    // Setters
    void setName(Name n);
    void setType(Type t);

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
    bool operator==(const fastSpoiling& other) const;
    friend std::ostream& operator<<(std::ostream& os, const fastSpoiling& fs);
    friend std::istream& operator>>(std::istream& is, fastSpoiling& fs);
};
