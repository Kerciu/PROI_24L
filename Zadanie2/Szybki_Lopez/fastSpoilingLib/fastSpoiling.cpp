#include "fastSpoiling.h"

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

name fastSpoiling::getName(void) const {}
type fastSpoiling::getType(void) const {}
transportMeans fastSpoiling::getTransportMeans(void) const {}
weight fastSpoiling::getWeight(void) const {}
volume fastSpoiling::getVolume(void) const {}
std::string fastSpoiling::getWeightNVolume(void) {}