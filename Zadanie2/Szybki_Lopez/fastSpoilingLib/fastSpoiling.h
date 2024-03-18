#pragma once
#include <string>
#include "Date.h"

class fastSpoiling {
    private:
    using name = std::string;
    using type = std::string;
    using transportMeans = std::string;
    using weight = double;
    using volume = double;

    name mName;
    type mType;
    Date mDate;
    transportMeans mTransportMeans;
    weight mWeight;
    volume mVolume;

    public:
    // Constructors
    fastSpoiling(name n, type t, Date d, weight w, volume v) {
        this->mName = n;
        this->mType = t;
        this->mDate = d;
        this->mTransportMeans = "No known transport means";
        this->mWeight = w;
        this->mVolume = v;
    }

    fastSpoiling(name n, type t, Date d, transportMeans tm, weight w, volume v) {
        this->mName = n;
        this->mType = t;
        this->mDate = d;
        this->mTransportMeans = tm;
        this->mWeight = w;
        this->mVolume = v;
    }

    // Getters
    name getName(void) const;
    type getType(void) const;
    transportMeans getTransportMeans(void) const;
    weight getWeight(void) const;
    volume getVolume(void) const;
    std::string getWeightNVolume(void) const;

    // Date Getters
    std::string getDateRandomFormat(void);
    std::string getDateSlashed(void);
    std::string getDateHyphened(void);
    std::string getDateDotted(void);
    std::string getDateShortenedYear(void);
    std::string getDateVerbalizedMonth(void);
    std::string getDateVerbalizedDay(void);

    // Setters
    void setName(name n);
    void setType(type t);
    void setDate(int d, int m, int y);
    void setTransportMeans(transportMeans tm);
    void setWeight(weight w);
    void setVolume(volume v);

};