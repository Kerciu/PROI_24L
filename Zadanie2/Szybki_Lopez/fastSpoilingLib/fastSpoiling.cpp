#include "fastSpoiling.h"

fastSpoiling(name n, type t, weightAndVolume wv) {
    this->mName = n;
    this->mType = t;
    this->mTransportMeans = "No known transport means";
    this->mWeightAndVolume = wv;
}

fastSpoiling(name n, type t, Date pd, weightAndVolume wv) {
    this->mName = n;
    this->mType = t;
    this->mProdDate = pd;
    this->mWeightAndVolume = wv;
}

fastSpoiling(name n, type t, Date pd, transportMeans tm, weightAndVolume wv) {
    this->mName = n;
    this->mType = t;
    this->mProdDate = pd;
    this->mTransportMeans = tm;
    this->mWeightAndVolume = wv;
}

fastSpoiling(name n, type t, Date pd, Date ed, weightAndVolume wv) {
    this->mName = n;
    this->mType = t;
    this->mProdDate = pd;
    this->mExpirDate = ed;
    this->mTransportMeans = "No known transport means";
    this->mWeightAndVolume = wv;
}

fastSpoiling(name n, type t, Date pd, Date ed, transportMeans tm, weightAndVolume wv) {
    this->mName = n;
    this->mType = t;
    this->mProdDate = pd;
    this->mExpirDate = ed;
    this->mTransportMeans = tm;
    this->mWeightAndVolume = wv;
}

name fastSpoiling::getName(void) const { return mName; }
type fastSpoiling::getType(void) const { return mType; }
transportMeans fastSpoiling::getTransportMeans(void) const { return mTransportMeans;}

// Date Getters
std::string fastSpoiling::getDateSlashed() {
    return mDate.slashOutput();
}
std::string fastSpoiling::getDateHyphened() {
    return mDate.hyphenOutput();
}
std::string fastSpoiling::getDateDotted() {
    return mDate.dotOutput();
}
std::string fastSpoiling::getDateShortenedYear() {
    return mDate.shortenedYearOutput();
}
std::string fastSpoiling::getDateVerbalizedMonth() {
    return mDate.verbalMonthOutput();
}
std::string fastSpoiling::getDateVerbalizedDay() {
    return mDate.verbalDayOutput()
}

// Setters
void fastSpoiling::setName(name n) { mName = n; }
void fastSpoiling::setType(type t) { mType = t; }
void fastSpoiling::setTransportMeans(transportMeans tm) { mType = t; }
