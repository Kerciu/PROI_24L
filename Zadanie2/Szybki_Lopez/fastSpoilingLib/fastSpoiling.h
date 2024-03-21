#pragma once
#include <string>
#include "Date.h"

class fastSpoiling {
    private:

    name mName;
    type mType;
    Date mDate;
    transportMeans mTransportMeans;
    weightAndVolume mWeightAndVolume;

    public:
    // Constructors
    fastSpoiling(name n, type t, Date d, weightAndVolume wv) {
        this->mName = n;
        this->mType = t;
        this->mDate = d;
        this->mTransportMeans = "No known transport means";
        this->mWeightAndVolume = wv;
    }

    fastSpoiling(name n, type t, Date d, transportMeans tm, weightAndVolume wv) {
        this->mName = n;
        this->mType = t;
        this->mDate = d;
        this->mTransportMeans = tm;
        this->mWeightAndVolume = wv;
    }

    // Getters
    name getName(void) const;
    type getType(void) const;
    transportMeans getTransportMeans(void) const;

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

};