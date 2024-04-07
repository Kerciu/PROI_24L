#pragma once
#include <string>
#include <utility>
#include <stdexcept>
#include <unordered_map>

class Price
{
private:
	int mValue;
    // User gives currency code and it translates using enum
    // Price (
	std::string mCurrency;
	std::pair<int, int> splitToIntegerAndDecimal(void) const;

    int parseCurrency(void);

public:
    Price();
    Price(int val);
    Price(std::string curr);
    Price(int value, std::string currency);

	float getValue(void) const;
    int getValueBiggestUnit(void) const;
    int getValueSmallestUnit(void) const;
    std::string getCurrency(void) const;
    int getCurrencyCode(void) const;
    std::string getCurrencyName(void) const;

    void setValue(int newValue);
    void setValue(float newValue);
    void setCurrency(std::string currencyCode);
    void showAvailableCurrencies() const;
};

