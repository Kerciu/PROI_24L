#include "Price.h"

Price::Price() : value(0), currency("XXX") { }
Price::Price(int val) : value(val), currency("XXX") { }
Price::Price(std::string curr) : value(0), currency(curr) { }
Price::Price(int val, std::string curr) : value(val), currency(curr) { }

int Price::splitToDecimal(void) { }
int Price::splitToIntiger(void) { }

int Price::parseCurrency(void) { }
int Price::getValue(void) { }
int Price::getValueInSmallestUnit(void) { }

void Price::setValue(int newValue) { }
void Price::setValue(float newValue) { }
void Price::setCurrency(std::string currencyCode) { }
void Price::showAvailableCurrencies() { }
