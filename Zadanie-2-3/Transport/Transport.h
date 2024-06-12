#pragma once
#include <string>

class Transport
{
public:
	using Temperature = double;
	using Humidity = double;
	using Packaging = std::string;

	private:
	Temperature mTemperature;
	Humidity mHumidity;
	Packaging mPackaging;

	bool validateTemperature(Temperature t) const;
	bool validateHumidity(Humidity h) const;

public:
	Transport();
	Transport(Packaging p);
	Transport(Temperature t, Packaging);
	Transport(Temperature t, Packaging p, Humidity h);

	Temperature getTemperature() const;
	Packaging getPackaging() const;
	Humidity getHumidity() const;

	void setTemperature(Temperature t);
	void setPackaging(Packaging p);
	void setHumidity(Humidity h);
	bool operator==(const Transport& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Transport& transport);
	friend std::istream& operator>>(std::istream& is, Transport& transport);
};

