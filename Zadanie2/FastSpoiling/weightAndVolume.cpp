#include "weightAndVolume.h"
#include <iomanip>
#include <string>
#include <stdexcept>
#include <map>

using Weight = double;
using Volume = double;

weightAndVolume::weightAndVolume(Weight w, Volume v) : mWeight(w), mVolume(v) { }

enum WeightConversionFactor {
    miligram = 1,
    gram = 1000,
    ounce = 28350,
    decagram = 10000,
    kilogram = 1000000,
    pounds = 453592,
    tonne = 1000000000,
    weightFactorCount
};

enum VolumeConversionFactor {
    mililiter = 1,
    centiliter = 10,
    deciliter = 100,
    liter = 1000,
    hectoliter = 10000,
    kiloliter = 1000000,
    volumeFactorCount
};

const std::map<std::string, WeightConversionFactor> weightConversionFactors = {
    {"miligram", WeightConversionFactor::miligram},
    {"gram", WeightConversionFactor::gram},
    {"ounce", WeightConversionFactor::ounce},
    {"decagram", WeightConversionFactor::decagram},
    {"kilogram", WeightConversionFactor::kilogram},
    {"pounds", WeightConversionFactor::pounds},
    {"tonne", WeightConversionFactor::tonne}
};

const std::map<std::string, VolumeConversionFactor> volumeConversionFactors = {
    {"mililiter", VolumeConversionFactor::mililiter},
    {"centiliter", VolumeConversionFactor::centiliter},
    {"deciliter", VolumeConversionFactor::deciliter},
    {"liter", VolumeConversionFactor::liter},
    {"hectoliter", VolumeConversionFactor::hectoliter},
    {"kiloliter", VolumeConversionFactor::kiloliter}
};

// Private
Weight weightAndVolume::getWeight(const std::string& unitString) const {
    if (weightConversionFactors.find(unitString) == weightConversionFactors.end()) {
        throw std::invalid_argument("Invalid weight unit");
    }
    WeightConversionFactor unit = static_cast<WeightConversionFactor>(weightConversionFactors.at(unitString));
    return convertWeight(unit);
}

Volume weightAndVolume::getVolume(const std::string& unitString) const {
    if (volumeConversionFactors.find(unitString) == volumeConversionFactors.end()) {
        throw std::invalid_argument("Invalid volume unit");
    }
    VolumeConversionFactor unit = static_cast<VolumeConversionFactor>(volumeConversionFactors.at(unitString));
    return convertVolume(unit);
}


Weight weightAndVolume::convertWeight(WeightConversionFactor toUnit) const {
    switch (toUnit) {
    case WeightConversionFactor::miligram:
        return mWeight * miligram / kilogram;
    case WeightConversionFactor::gram:
        return mWeight * gram / kilogram;
    case WeightConversionFactor::ounce:
        return mWeight * ounce / kilogram;
    case WeightConversionFactor::decagram:
        return mWeight * decagram / kilogram;
    case WeightConversionFactor::kilogram:
        return mWeight;
    case WeightConversionFactor::pounds:
        return mWeight * pounds / kilogram;
    case WeightConversionFactor::tonne:
        return mWeight * tonne / kilogram;
    default:
        throw std::invalid_argument("Invalid weight conversion unit");
    }
}

Volume weightAndVolume::convertVolume(VolumeConversionFactor toUnit) const {
    switch (toUnit) {
    case VolumeConversionFactor::mililiter:
        return mVolume * mililiter / liter;
    case VolumeConversionFactor::centiliter:
        return mVolume * centiliter / liter;
    case VolumeConversionFactor::deciliter:
        return mVolume * deciliter / liter;
    case VolumeConversionFactor::liter:
        return mVolume;
    case VolumeConversionFactor::hectoliter:
        return mVolume * hectoliter / liter;
    case VolumeConversionFactor::kiloliter:
        return mVolume * kiloliter / liter;
    default:
        throw std::invalid_argument("Invalid volume conversion unit");
    }
}

Weight weightAndVolume::getWeight() const {
    return mWeight;
}

Volume weightAndVolume::getVolume() const {
    return mVolume;
}

void weightAndVolume::setWeight(Weight w) {
    mWeight = w;
}

void weightAndVolume::setVolume(Volume v) {
    mVolume = v;
}

// Operator Overload
weightAndVolume weightAndVolume::operator+(const weightAndVolume& other) const {
    Weight newWeight = mWeight + other.mWeight;
    Volume newVolume = mVolume + other.mVolume;
    return weightAndVolume(newWeight, newVolume);
}

weightAndVolume weightAndVolume::operator-(const weightAndVolume& other) const {
    Weight newWeight = mWeight - other.mWeight;
    Volume newVolume = mVolume - other.mVolume;
    return weightAndVolume(newWeight, newVolume);
}

weightAndVolume weightAndVolume::operator*(double factor) const {
    Weight newWeight = mWeight * factor;
    Volume newVolume = mVolume * factor;
    return weightAndVolume(newWeight, newVolume);
}

bool weightAndVolume::operator==(const weightAndVolume& other) const {
    return mWeight == other.mWeight && mVolume == other.mVolume;
}

std::ostream& operator<<(std::ostream& os, const weightAndVolume& wv) {
    os << wv.getWeight() << ' ' << wv.getVolume();
    return os;
}

weightAndVolume& weightAndVolume::operator=(const weightAndVolume& other) {
    if (this == &other)
        return *this;

    mWeight = other.mWeight;
    mVolume = other.mVolume;

    return *this;
}
