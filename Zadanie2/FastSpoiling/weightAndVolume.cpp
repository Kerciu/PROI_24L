#include "weightAndVolume.h"
#include <iomanip>
#include <string>
#include <stdexcept>

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

const std::string weightAndVolume::correctWeightConverFact[] = { "miligram", "gram", "ounce", "decagram", "kilogram", "pounds", "tonne" };
const std::string weightAndVolume::correctVolumeConverFact[] = { "mililiter", "centiliter", "deciliter", "liter", "hectoliter", "kiloliter" };

// Private
weightAndVolume::WeightConversionFactor weightAndVolume::parseWeightUnits(const std::string& unitString) const {
    for (int i = 0; i < weightFactorCount; i++) {
        if (correctWeightConverFact[i] == unitString) {
            return static_cast<WeightConversionFactor>(i);
        }
    }
    throw std::invalid_argument("Invalid weight unit");
}

weightAndVolume::VolumeConversionFactor weightAndVolume::parseVolumeUnits(const std::string& unitString) const {
    for (int i = 0; i < volumeFactorCount; i++) {
        if (correctVolumeConverFact[i] == unitString) {
            return static_cast<VolumeConversionFactor>(i);
        }
    }
    throw std::invalid_argument("Invalid volume unit");
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

Weight weightAndVolume::getWeight(const std::string& unitString) const {
    WeightConversionFactor unit;
    try {
        unit = parseWeightUnits(unitString);
    }
    catch (const std::invalid_argument& e) {
        return -1;
    }
    return convertWeight(unit);
}

Volume weightAndVolume::getVolume() const {
    return mVolume;
}

Volume weightAndVolume::getVolume(const std::string& unitString) const {
    VolumeConversionFactor unit;
    try {
        unit = parseVolumeUnits(unitString);
    }
    catch (const std::invalid_argument& e) {
        return -1;
    }
    return convertVolume(unit);
}

std::string weightAndVolume::getWeightNVolume() const {
    return std::to_string(mWeight) + ' ' + correctWeightConverFact[4] + ", " + std::to_string(mVolume) + ' ' + correctVolumeConverFact[3];
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
    os << "Weight: " << wv.getWeight() << " kg's, Volume: " << wv.getVolume() << " liters\n";
    return os;
}

weightAndVolume& weightAndVolume::operator=(const weightAndVolume& other) {
    if (this == &other)
        return *this;

    mWeight = other.mWeight;
    mVolume = other.mVolume;

    return *this;
}
