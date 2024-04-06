#include "Transport.h"
#include <stdexcept>
#include <iomanip>
#include <string>
#include <iostream>

Transport::Transport() : mTemperature(21.0), mPackaging("No information"), mHumidity(50) { }

Transport::Transport(Packaging p) : mTemperature(21.0), mPackaging(p), mHumidity(50) { }

Transport::Transport(Temperature t, Packaging p) : mTemperature(t), mPackaging(p), mHumidity(50) { }

Transport::Transport(Temperature t, Packaging p, Humidity h) : mTemperature(t), mPackaging(p), mHumidity(h) { }

bool Transport::validateTemperature(Temperature t) const {
	return (t > -270.0 && t < 150);
}

bool Transport::validateHumidity(Humidity h) const {
	return (h > 0 && h <= 100);
}

Transport::Temperature Transport::getTemperature() const {
	return mTemperature;
}

Transport::Packaging Transport::getPackaging() const {
	return mPackaging;
}

Transport::Humidity Transport::getHumidity() const {
	return mHumidity;
}

void Transport::setTemperature(Temperature t) {
	validateTemperature(t) ? mTemperature = t : 0;
}

void Transport::setPackaging(Packaging p) {
	mPackaging = p;
}

void Transport::setHumidity(Humidity h) {
	validateHumidity(h) ? mHumidity = h : mHumidity = 50;
}

// Operator overloading

bool Transport::operator==(const Transport& other) const {
	return mTemperature == other.mTemperature && mPackaging == other.mPackaging && mHumidity == other.mHumidity;
}

std::ostream& operator<<(std::ostream& os, const Transport& transport) {
	os << transport.getTemperature() << ';' << transport.getPackaging() << ';' << transport.getHumidity();
	return os;
}

std::istream& operator>>(std::istream& is, Transport& transport)
{
	Transport::Temperature temp;
	Transport::Packaging pack;
	Transport::Humidity humid;

	std::string tempStr, packStr, humidStr;
	is >> tempStr >> packStr >> humidStr;

	try {
		temp = std::stod(tempStr);
		pack = packStr;
		humid = std::stod(humidStr);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return is;
	}

	transport.setTemperature(temp);
	transport.setPackaging(pack);
	transport.setHumidity(humid);

	return is;
}
