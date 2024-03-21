#include "weightAndVolume.h"

weightAndVolume::weightAndVolume(weight w, volume v) {
    mWeight = w;
    mVolume = v;
}

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

// Private
WeightConversionFactor weightAndVolume::parseWeightUnits(const std::string& unitString) const {
    for (int i = 0; i < weightFactorCount; i++) {
        if (correctWeightConverFact[i] == unitString) {
            return static_cast<WeightConversionFactor>(i);
        }
    }
    return static_cast<WeightConversionFactor>(-1);
}

VolumeConversionFactor weightAndVolume::parseVolumeUnits(const std::string& unitString) const {
    for (int i = 0; i < volumeFactorCount; i++) {
        if (correctVolumeConverFact[i] == unitString) {
            return static_cast<VolumeConversionFactor>(i);
        }
    }
    return static_cast<VolumeConversionFactor>(-1);
}

weight weightAndVolume::convertWeight(WeightConversionFactor toUnit) const {
        switch (toUnit) {
            case miligram:
                return mWeightInKilograms * miligram / kilogram;
            case gram:
                return mWeightInKilograms * gram / kilogram;
            case ounce:
                return mWeightInKilograms * ounce / kilogram;
            case decagram:
                return mWeightInKilograms * decagram / kilogram;
            case kilogram:
                return mWeightInKilograms;
            case pounds:
                return mWeightInKilograms * pounds / kilogram;
            case tonne:
                return mWeightInKilograms * tonne / kilogram;
            default:
                throw std::invalid_argument("Invalid weight conversion unit");
        }
    }

volume weightAndVolume::convertVolume(VolumeConversionFactor toUnit) const {
        switch (toUnit) {
            case mililiter:
                return mVolumeInLiters * mililiter / liter;
            case centiliter:
                return mVolumeInLiters * centiliter / liter;
            case deciliter:
                return mVolumeInLiters * deciliter / liter;
            case liter:
                return mVolumeInLiters;
            case hectoliter:
                return mVolumeInLiters * hectoliter / liter;
            case kiloliter:
                return mVolumeInLiters * kiloliter / liter;
            default:
                throw std::invalid_argument("Invalid volume conversion unit");
        }
    }

const std::string correctWeightConverFact[7] = {"miligrams", "grams", "ounces", "decagrams", "kilograms" "poundss", "tonnes"};
const std::string correctVolumeConverFact[6] = {"mililiters", "centiliters", "deciliters", "liters", "hectoliters", "kiloliters"};

weight weightAndVolume::getWeight(void) const {
    return mWeight;
}

weight weightAndVolume::getWeight(const std::string& unitString) const {
    WeightConversionFactor unit = parseWeightUnits(unitString);
    return (unit != weightFactorCount) ? convertWeight(unit) : -1;
}

volume weightAndVolume::getVolume(void) const {
    return mVolume;
}

volume weightAndVolume::getVolume(const std::string& unitString) const {
    VolumeConversionFactor unit = parseVolumeUnits(unitString);
    return (unit != volumeFactorCount) ? convertVolume(unit) : -1;
}

std::string weightAndVolume::getWeightNVolume(void) {
    return std::to_string(mWeight) + ' ' + correctWeightConverFact[4] + ", " + std::to_string(mVolume) + ' ' + correctVolumeConverFact[3];
}

void weightAndVolume::setWeight(weight w) {
    mWeight = w;
}

void weightAndVolume::setVolume(volume v) {
    mVolume = v;
}