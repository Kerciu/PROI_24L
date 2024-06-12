#pragma once
#include <string>

class weightAndVolume {
public:
    using Weight = double;
    using Volume = double;

private:
    Weight mWeight;
    Volume mVolume;
    
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
    Weight convertWeight(WeightConversionFactor toUnit) const;
    Volume convertVolume(VolumeConversionFactor toUnit) const;

    static const std::string correctWeightConverFact[7];
    static const std::string correctVolumeConverFact[6];

    bool validateWeight(Weight w) const;
    bool validateVolume(Volume v) const;

public:
    weightAndVolume();
    weightAndVolume(Weight w, Volume v);

    // Getters
    Weight getWeight() const;
    Weight getWeight(const std::string& unitString) const;
    Volume getVolume() const;
    Volume getVolume(const std::string& unitString) const;

    // Setters
    void setWeight(Weight w);
    void setVolume(Volume v);
    
    weightAndVolume operator+(const weightAndVolume& other) const;
    weightAndVolume operator-(const weightAndVolume& other) const;
    weightAndVolume operator*(double factor) const;
    bool operator==(const weightAndVolume& other) const;
    friend std::ostream& operator<<(std::ostream& os, const weightAndVolume& wv);
    friend std::istream& operator>>(std::istream& is, weightAndVolume& wv);
    weightAndVolume& operator=(const weightAndVolume& other);
};
