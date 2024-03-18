#include "fastSpoiling.h"

fastSpoiling::fastSpoiling(const name& n, const type& t, const Date& d, weight w, volume v) {
    mName = n;
    mType = t;
    mDate = d;
    mTransportMeans = "No known transport means";
    mWeight = w;
    mVolume = v;
}

fastSpoiling::fastSpoiling(name n, type t, Date d, transportMeans tm, weight w, volume v) {
    mName = n;
    mType = t;
    mDate = d;
    mTransportMeans = tm;
    mWeight = w;
    mVolume = v;
}

name fastSpoiling::getName(void) const { return mName; }
type fastSpoiling::getType(void) const { return mType; }
transportMeans fastSpoiling::getTransportMeans(void) const { return mTransportMeans;}
weight fastSpoiling::getWeight(void) const { return mWeight; }
volume fastSpoiling::getVolume(void) const { return mVolume; }
std::string fastSpoiling::getWeightNVolume(void) {
    return std::to_string(mWeight) + " kg ," + std::to_string(mVolume) + " m^3";
}

// Date Getters
std::string fastSpoiling::getRandomDateFormat() {}

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
void fastSpoiling::setDate(int d, int m, int y) { mDate = Date(d, m, y); }
void fastSpoiling::setTransportMeans(transportMeans tm) { mType = t; }
void fastSpoiling::setWeight(weight w) { mWeight = w; }
void fastSpoiling::setVolume(volume v) { mVolume = v; }
