#include <string>

class weightAndVolume {
    private:

    using weight = double;
    using volume = double;

    weight mWeight;
    volume mVolume;

    enum WeightConversionFactor;
    enum VolumeConversionFactor;

    WeightConversionFactor parseWeightUnits(const std::string& unitString) const;
    VolumeConversionFactor parseVolumeUnits(const std::string& unitString) const;
    weight convertWeight(WeightConversionFactor toUnit) const;
    volume convertVolume(VolumeConversionFactor toUnit) const; 

    public:
    weightAndVolume(weight w, volume v) {
        this->mWeight = w;
        this->mVolume = v;
    }

    // Getters
    weight getWeight(void) const;
    weight getWeight(const std::string& unitString) const;
    volume getVolume(void);
    volume getVolume(const std::string& unitString) const;

};