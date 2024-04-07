#pragma once
#include <string>
#include <utility>
#include <stdexcept>
#include <unordered_map>

class Price
{
private:
	double mValue;
    // User gives currency code and it translates using enum
    // Price (
	std::string mCurrency;

    bool validatePrice(double p) const;
    bool validateCurrency(std::string cur) const;

public:
    Price();
    Price(double val);
    Price(std::string curr);
    Price(double value, std::string currency);

	double getValue(void) const;
    std::string getCurrency(void) const;
    int getCurrencyCode(void) const;
    std::string getCurrencyName(void) const;

    void setValue(double newValue);
    void setCurrency(std::string currencyCode);
    void showAvailableCurrencies() const;
    void showAvailableCurrenciesShortAndCode() const;

    Price operator+(const Price& other);
    Price operator-(const Price& other);
    Price operator*(const Price& other);
    bool operator<(const Price& other);
    bool operator==(const Price& other);
    Price operator=(const Price& other);
    friend std::ostream& operator<<(std::ostream& os, const Price& p);
    friend std::istream& operator>>(std::istream& is, const Price& p);
    friend std::fstream& operator<<(std::fstream& fs, const Price& p);
    friend std::fstream& operator>>(std::fstream& fs, const Price& p);
};

