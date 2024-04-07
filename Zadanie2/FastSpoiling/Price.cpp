#include "Price.h"
#include <string>
#include <utility>
#include <stdexcept>
#include <unordered_map>

Price::Price() : mValue(0), mCurrency("XXX") { }
Price::Price(int val) : mValue(val), mCurrency("XXX") { }
Price::Price(std::string curr) : mValue(0), mCurrency(curr) { }
Price::Price(int val, std::string curr) : mValue(val), mCurrency(curr) { }

enum class CurrencyCode : int {
    AED = 784, // United Arab Emirates dirham
    AFN = 971, // Afghan afghani
    ALL = 8, // Albanian lek
    AMD = 51, // Armenian dram
    ANG = 532, // Netherlands Antillean guilder
    AOA = 973, // Angolan kwanza
    ARS = 32, // Argentine peso
    AUD = 36, // Australian dollar
    AWG = 533, // Aruban florin
    AZN = 944, // Azerbaijani manat
    BAM = 977, // Bosnia and Herzegovina convertible mark
    BBD = 52, // Barbados dollar
    BDT = 50, // Bangladeshi taka
    BGN = 975, // Bulgarian lev
    BHD = 48, // Bahraini dinar
    BIF = 108, // Burundian franc
    BMD = 60, // Bermudian dollar
    BND = 96, // Brunei dollar
    BOB = 68, // Boliviano
    BOV = 984, // Bolivian Mvdol (funds code)
    BRL = 986, // Brazilian real
    BSD = 44, // Bahamian dollar
    BTN = 64, // Bhutanese ngultrum
    BWP = 72, // Botswana pula
    BYN = 933, // Belarusian ruble
    BZD = 84, // Belize dollar
    CAD = 124, // Canadian dollar
    CDF = 976, // Congolese franc
    CHE = 947, // WIR euro (complementary currency)
    CHF = 756, // Swiss franc
    CHW = 948, // WIR franc (complementary currency)
    CLF = 990, // Unidad de Fomento (funds code)
    CLP = 152, // Chilean peso
    COP = 170, // Colombian peso
    COU = 970, // Unidad de Valor Real (UVR) (funds code)
    CRC = 188, // Costa Rican colon
    CUC = 931, // Cuban convertible peso
    CUP = 192, // Cuban peso
    CVE = 132, // Cape Verdean escudo
    CZK = 203, // Czech koruna
    DJF = 262, // Djiboutian franc
    DKK = 208, // Danish krone
    DOP = 214, // Dominican peso
    DZD = 12, // Algerian dinar
    EGP = 818, // Egyptian pound
    ERN = 232, // Eritrean nakfa
    ETB = 230, // Ethiopian birr
    EUR = 978, // Euro
    FJD = 242, // Fiji dollar
    FKP = 238, // Falkland Islands pound
    GBP = 826, // Pound sterling
    GEL = 981, // Georgian lari
    GHS = 936, // Ghanaian cedi
    GIP = 292, // Gibraltar pound
    GMD = 270, // Gambian dalasi
    GNF = 324, // Guinean franc
    GTQ = 320, // Guatemalan quetzal
    GYD = 328, // Guyanese dollar
    HKD = 344, // Hong Kong dollar
    HNL = 340, // Honduran lempira
    HRK = 191, // Croatian kuna
    HTG = 332, // Haitian gourde
    HUF = 348, // Hungarian forint
    IDR = 360, // Indonesian rupiah
    ILS = 376, // Israeli new shekel
    INR = 356, // Indian rupee
    IQD = 368, // Iraqi dinar
    IRR = 364, // Iranian rial
    ISK = 352, // Icelandic króna (plural: krónur)
    JMD = 388, // Jamaican dollar
    JOD = 400, // Jordanian dinar
    JPY = 392, // Japanese yen
    KES = 404, // Kenyan shilling
    KGS = 417, // Kyrgyzstani som
    KHR = 116, // Cambodian riel
    KMF = 174, // Comoro franc
    KPW = 408, // North Korean won
    KRW = 410, // South Korean won
    KWD = 414, // Kuwaiti dinar
    KYD = 136, // Cayman Islands dollar
    KZT = 398, // Kazakhstani tenge
    LAK = 418, // Lao kip
    LBP = 422, // Lebanese pound
    LKR = 144, // Sri Lankan rupee
    LRD = 430, // Liberian dollar
    LSL = 426, // Lesotho loti
    LYD = 434, // Libyan dinar
    MAD = 504, // Moroccan dirham
    MDL = 498, // Moldovan leu
    MGA = 969, // Malagasy ariary
    MKD = 807, // Macedonian denar
    MMK = 104, // Myanmar kyat
    MNT = 496, // Mongolian tögrög
    MOP = 446, // Macanese pataca
    MRU = 929, // Mauritanian ouguiya
    MUR = 480, // Mauritian rupee
    MVR = 462, // Maldivian rufiyaa
    MWK = 454, // Malawian kwacha
    MXN = 484, // Mexican peso
    MXV = 979, // Mexican Unidad de Inversion (UDI) (funds code)
    MYR = 458, // Malaysian ringgit
    MZN = 943, // Mozambican metical
    NAD = 516, // Namibian dollar
    NGN = 566, // Nigerian naira
    NIO = 558, // Nicaraguan córdoba
    NOK = 578, // Norwegian krone
    NPR = 524, // Nepalese rupee
    NZD = 554, // New Zealand dollar
    OMR = 512, // Omani rial
    PAB = 590, // Panamanian balboa
    PEN = 604, // Peruvian sol
    PGK = 598, // Papua New Guinean kina
    PHP = 608, // Philippine peso
    PKR = 586, // Pakistani rupee
    PLN = 985, // Polish złoty
    PYG = 600, // Paraguayan guaraní
    QAR = 634, // Qatari riyal
    RON = 946, // Romanian leu
    RSD = 941, // Serbian dinar
    CNY = 156, // Renminbi
    RUB = 643, // Russian ruble
    RWF = 646, // Rwandan franc
    SAR = 682, // Saudi riyal
    SBD = 90, // Solomon Islands dollar
    SCR = 690, // Seychelles rupee
    SDG = 938, // Sudanese pound
    SEK = 752, // Swedish krona (plural: kronor)
    SGD = 702, // Singapore dollar
    SHP = 654, // Saint Helena pound
    SLL = 694, // Sierra Leonean leone
    SLE = 925, // Sierra Leonean leone
    SOS = 706, // Somali shilling
    SRD = 968, // Surinamese dollar
    SSP = 728, // South Sudanese pound
    STN = 930, // São Tomé and Príncipe dobra
    SVC = 222, // Salvadoran colón
    SYP = 760, // Syrian pound
    SZL = 748, // Swazi lilangeni
    THB = 764, // Thai baht
    TJS = 972, // Tajikistani somoni
    TMT = 934, // Turkmenistan manat
    TND = 788, // Tunisian dinar
    TOP = 776, // Tongan paʻanga
    TRY = 949, // Turkish lira
    TTD = 780, // Trinidad and Tobago dollar
    TWD = 901, // New Taiwan dollar
    TZS = 834, // Tanzanian shilling
    UAH = 980, // Ukrainian hryvnia
    UGX = 800, // Ugandan shilling
    USD = 840, // United States dollar
    USN = 997, // United States dollar (next day) (funds code)
    UYI = 940, // Uruguay Peso en Unidades Indexadas (URUIURUI) (funds code)
    UYU = 858, // Uruguayan peso
    UYW = 927, // Unidad previsional
    UZS = 860, // Uzbekistan som
    VED = 926, // Venezuelan bolívar digital
    VES = 928, // Venezuelan bolívar soberano
    VND = 704, // Vietnamese đồng
    VUV = 548, // Vanuatu vatu
    WST = 882, // Samoan tala
    XAF = 950, // CFA franc BEAC
    XAG = 961, // Silver (one troy ounce)
    XAU = 959, // Gold (one troy ounce)
    XBA = 955, // European Composite Unit (EURCO) (bond market unit)
    XBB = 956, // European Monetary Unit (E.M.U.-6) (bond market unit)
    XBC = 957, // European Unit of Account 9 (E.U.A.-9) (bond market unit)
    XBD = 958, // European Unit of Account 17 (E.U.A.-17) (bond market unit)
    XCD = 951, // East Caribbean dollar
    XDR = 960, // Special drawing rights
    XOF = 952, // CFA franc BCEAO
    XPD = 964, // Palladium (one troy ounce)
    XPF = 953, // CFP franc (franc Pacifique)
    XPT = 962, // Platinum (one troy ounce)
    XSU = 994, // SUCRE
    XTS = 963, // Code reserved for testing
    XUA = 965, // ADB Unit of Account
    XXX = 999, // No currency
    YER = 886, // Yemeni rial
    ZAR = 710, // South African rand
    ZMW = 967, // Zambian kwacha
    ZWL = 932 // Zimbabwean dollar
};
std::unordered_map<std::string, CurrencyCode> currencyMap = {
    {"AED", CurrencyCode::AED},
    {"AFN", CurrencyCode::AFN},
    {"ALL", CurrencyCode::ALL},
    {"AMD", CurrencyCode::AMD},
    {"ANG", CurrencyCode::ANG},
    {"AOA", CurrencyCode::AOA},
    {"ARS", CurrencyCode::ARS},
    {"AUD", CurrencyCode::AUD},
    {"AWG", CurrencyCode::AWG},
    {"AZN", CurrencyCode::AZN},
    {"BAM", CurrencyCode::BAM},
    {"BBD", CurrencyCode::BBD},
    {"BDT", CurrencyCode::BDT},
    {"BGN", CurrencyCode::BGN},
    {"BHD", CurrencyCode::BHD},
    {"BIF", CurrencyCode::BIF},
    {"BMD", CurrencyCode::BMD},
    {"BND", CurrencyCode::BND},
    {"BOB", CurrencyCode::BOB},
    {"BOV", CurrencyCode::BOV},
    {"BRL", CurrencyCode::BRL},
    {"BSD", CurrencyCode::BSD},
    {"BTN", CurrencyCode::BTN},
    {"BWP", CurrencyCode::BWP},
    {"BYN", CurrencyCode::BYN},
    {"BZD", CurrencyCode::BZD},
    {"CAD", CurrencyCode::CAD},
    {"CDF", CurrencyCode::CDF},
    {"CHE", CurrencyCode::CHE},
    {"CHF", CurrencyCode::CHF},
    {"CHW", CurrencyCode::CHW},
    {"CLF", CurrencyCode::CLF},
    {"CLP", CurrencyCode::CLP},
    {"CNY", CurrencyCode::CNY},
    {"COP", CurrencyCode::COP},
    {"COU", CurrencyCode::COU},
    {"CRC", CurrencyCode::CRC},
    {"CUC", CurrencyCode::CUC},
    {"CUP", CurrencyCode::CUP},
    {"CVE", CurrencyCode::CVE},
    {"CZK", CurrencyCode::CZK},
    {"DJF", CurrencyCode::DJF},
    {"DKK", CurrencyCode::DKK},
    {"DOP", CurrencyCode::DOP},
    {"DZD", CurrencyCode::DZD},
    {"EGP", CurrencyCode::EGP},
    {"ERN", CurrencyCode::ERN},
    {"ETB", CurrencyCode::ETB},
    {"EUR", CurrencyCode::EUR},
    {"FJD", CurrencyCode::FJD},
    {"FKP", CurrencyCode::FKP},
    {"GBP", CurrencyCode::GBP},
    {"GEL", CurrencyCode::GEL},
    {"GHS", CurrencyCode::GHS},
    {"GIP", CurrencyCode::GIP},
    {"GMD", CurrencyCode::GMD},
    {"GNF", CurrencyCode::GNF},
    {"GTQ", CurrencyCode::GTQ},
    {"GYD", CurrencyCode::GYD},
    {"HKD", CurrencyCode::HKD},
    {"HNL", CurrencyCode::HNL},
    {"HRK", CurrencyCode::HRK},
    {"HTG", CurrencyCode::HTG},
    {"HUF", CurrencyCode::HUF},
    {"IDR", CurrencyCode::IDR},
    {"ILS", CurrencyCode::ILS},
    {"INR", CurrencyCode::INR},
    {"IQD", CurrencyCode::IQD},
    {"IRR", CurrencyCode::IRR},
    {"ISK", CurrencyCode::ISK},
    {"JMD", CurrencyCode::JMD},
    {"JOD", CurrencyCode::JOD},
    {"JPY", CurrencyCode::JPY},
    {"KES", CurrencyCode::KES},
    {"KGS", CurrencyCode::KGS},
    {"KHR", CurrencyCode::KHR},
    {"KMF", CurrencyCode::KMF},
    {"KPW", CurrencyCode::KPW},
    {"KRW", CurrencyCode::KRW},
    {"KWD", CurrencyCode::KWD},
    {"KYD", CurrencyCode::KYD},
    {"KZT", CurrencyCode::KZT},
    {"LAK", CurrencyCode::LAK},
    {"LBP", CurrencyCode::LBP},
    {"LKR", CurrencyCode::LKR},
    {"LRD", CurrencyCode::LRD},
    {"LSL", CurrencyCode::LSL},
    {"LYD", CurrencyCode::LYD},
    {"MAD", CurrencyCode::MAD},
    {"MDL", CurrencyCode::MDL},
    {"MGA", CurrencyCode::MGA},
    {"MKD", CurrencyCode::MKD},
    {"MMK", CurrencyCode::MMK},
    {"MNT", CurrencyCode::MNT},
    {"MOP", CurrencyCode::MOP},
    {"MRU", CurrencyCode::MRU},
    {"MUR", CurrencyCode::MUR},
    {"MVR", CurrencyCode::MVR},
    {"MWK", CurrencyCode::MWK},
    {"MXN", CurrencyCode::MXN},
    {"MXV", CurrencyCode::MXV},
    {"MYR", CurrencyCode::MYR},
    {"MZN", CurrencyCode::MZN},
    {"NAD", CurrencyCode::NAD},
    {"NGN", CurrencyCode::NGN},
    {"NIO", CurrencyCode::NIO},
    {"NOK", CurrencyCode::NOK},
    {"NPR", CurrencyCode::NPR},
    {"NZD", CurrencyCode::NZD},
    {"OMR", CurrencyCode::OMR},
    {"PAB", CurrencyCode::PAB},
    {"PEN", CurrencyCode::PEN},
    {"PGK", CurrencyCode::PGK},
    {"PHP", CurrencyCode::PHP},
    {"PKR", CurrencyCode::PKR},
    {"PLN", CurrencyCode::PLN},
    {"PYG", CurrencyCode::PYG},
    {"QAR", CurrencyCode::QAR},
    {"RON", CurrencyCode::RON},
    {"RSD", CurrencyCode::RSD},
    {"RUB", CurrencyCode::RUB},
    {"RWF", CurrencyCode::RWF},
    {"SAR", CurrencyCode::SAR},
    {"SBD", CurrencyCode::SBD},
    {"SCR", CurrencyCode::SCR},
    {"SDG", CurrencyCode::SDG},
    {"SEK", CurrencyCode::SEK},
    {"SGD", CurrencyCode::SGD},
    {"SHP", CurrencyCode::SHP},
    {"SLL", CurrencyCode::SLL},
    {"SOS", CurrencyCode::SOS},
    {"SRD", CurrencyCode::SRD},
    {"SSP", CurrencyCode::SSP},
    {"STN", CurrencyCode::STN},
    {"SVC", CurrencyCode::SVC},
    {"SYP", CurrencyCode::SYP},
    {"SZL", CurrencyCode::SZL},
    {"THB", CurrencyCode::THB},
    {"TJS", CurrencyCode::TJS},
    {"TMT", CurrencyCode::TMT},
    {"TND", CurrencyCode::TND},
    {"TOP", CurrencyCode::TOP},
    {"TRY", CurrencyCode::TRY},
    {"TTD", CurrencyCode::TTD},
    {"TWD", CurrencyCode::TWD},
    {"TZS", CurrencyCode::TZS},
    {"UAH", CurrencyCode::UAH},
    {"UGX", CurrencyCode::UGX},
    {"USD", CurrencyCode::USD},
    {"USN", CurrencyCode::USN},
    {"UYI", CurrencyCode::UYI},
    {"UYU", CurrencyCode::UYU},
    {"UYW", CurrencyCode::UYW},
    {"UZS", CurrencyCode::UZS},
    {"VED", CurrencyCode::VED},
    {"VES", CurrencyCode::VES},
    {"VND", CurrencyCode::VND},
    {"VUV", CurrencyCode::VUV},
    {"WST", CurrencyCode::WST},
    {"XAF", CurrencyCode::XAF},
    {"XAG", CurrencyCode::XAG},
    {"XAU", CurrencyCode::XAU},
    {"XBA", CurrencyCode::XBA},
    {"XBB", CurrencyCode::XBB},
    {"XBC", CurrencyCode::XBC},
    {"XBD", CurrencyCode::XBD},
    {"XCD", CurrencyCode::XCD},
    {"XDR", CurrencyCode::XDR},
    {"XOF", CurrencyCode::XOF},
    {"XPD", CurrencyCode::XPD},
    {"XPF", CurrencyCode::XPF},
    {"XPT", CurrencyCode::XPT},
    {"XSU", CurrencyCode::XSU},
    {"XTS", CurrencyCode::XTS},
    {"XUA", CurrencyCode::XUA},
    {"XXX", CurrencyCode::XXX},
    {"YER", CurrencyCode::YER},
    {"ZAR", CurrencyCode::ZAR},
    {"ZMW", CurrencyCode::ZMW},
    {"ZWL", CurrencyCode::ZWL}
};
std::unordered_map<CurrencyCode, double> exchangeRates = {
    {CurrencyCode::AED, 3.67},   // United Arab Emirates dirham
    {CurrencyCode::AFN, 77.11},  // Afghan afghani
    {CurrencyCode::ALL, 102.5},  // Albanian lek
    {CurrencyCode::AMD, 481.5},  // Armenian dram
    {CurrencyCode::ANG, 1.79},   // Netherlands Antillean guilder
    {CurrencyCode::AOA, 560.89}, // Angolan kwanza
    {CurrencyCode::ARS, 101.46}, // Argentine peso
    {CurrencyCode::AUD, 1.29},   // Australian dollar
    {CurrencyCode::AWG, 1.79},   // Aruban florin
    {CurrencyCode::AZN, 1.70},   // Azerbaijani manat
    {CurrencyCode::BAM, 1.67},   // Bosnia and Herzegovina convertible mark
    {CurrencyCode::BBD, 2.00},   // Barbadian dollar
    {CurrencyCode::BDT, 84.87},  // Bangladeshi taka
    {CurrencyCode::BGN, 1.67},   // Bulgarian lev
    {CurrencyCode::BHD, 0.38},   // Bahraini dinar
    {CurrencyCode::BIF, 1985.86},// Burundian franc
    {CurrencyCode::BMD, 1.00},   // Bermudian dollar
    {CurrencyCode::BND, 1.35},   // Brunei dollar
    {CurrencyCode::BOB, 6.90},   // Bolivian boliviano
    {CurrencyCode::BRL, 5.58},   // Brazilian real
    {CurrencyCode::BSD, 1.00},   // Bahamian dollar
    {CurrencyCode::BTN, 73.82},  // Bhutanese ngultrum
    {CurrencyCode::BWP, 11.65},  // Botswana pula
    {CurrencyCode::BYN, 2.50},   // Belarusian ruble
    {CurrencyCode::BZD, 2.00},   // Belize dollar
    {CurrencyCode::CAD, 1.24},   // Canadian dollar
    {CurrencyCode::CDF, 1981.79},// Congolese franc
    {CurrencyCode::CHF, 0.93},   // Swiss franc
    {CurrencyCode::CLP, 818.08},  // Chilean peso
    {CurrencyCode::CNY, 6.37},   // Chinese yuan
    {CurrencyCode::COP, 3876.94},// Colombian peso
    {CurrencyCode::CRC, 631.63}, // Costa Rican colón
    {CurrencyCode::CUC, 1.00},   // Cuban convertible peso
    {CurrencyCode::CUP, 25.00},  // Cuban peso
    {CurrencyCode::CVE, 93.88},  // Cape Verdean escudo
    {CurrencyCode::CZK, 21.67},  // Czech koruna
    {CurrencyCode::DJF, 177.72}, // Djiboutian franc
    {CurrencyCode::DKK, 6.25},   // Danish krone
    {CurrencyCode::DOP, 56.34},  // Dominican peso
    {CurrencyCode::DZD, 139.78}, // Algerian dinar
    {CurrencyCode::EGP, 15.68},  // Egyptian pound
    {CurrencyCode::ERN, 15.00},  // Eritrean nakfa
    {CurrencyCode::ETB, 53.47},  // Ethiopian birr
    {CurrencyCode::EUR, 0.82},   // Euro
    {CurrencyCode::FJD, 2.07},   // Fijian dollar
    {CurrencyCode::FKP, 0.72},   // Falkland Islands pound
    {CurrencyCode::GBP, 0.72},   // British pound sterling
    {CurrencyCode::GEL, 3.15},   // Georgian lari
    {CurrencyCode::GHS, 6.98},   // Ghanaian cedi
    {CurrencyCode::GIP, 0.72},   // Gibraltar pound
    {CurrencyCode::GMD, 51.21},  // Gambian dalasi
    {CurrencyCode::GNF, 10234.50},// Guinean franc
    {CurrencyCode::GTQ, 7.76},   // Guatemalan quetzal
    {CurrencyCode::GYD, 208.51}, // Guyanaese dollar
    {CurrencyCode::HKD, 7.79},   // Hong Kong dollar
    {CurrencyCode::HNL, 24.11},  // Honduran lempira
    {CurrencyCode::HRK, 6.33},   // Croatian kuna
    {CurrencyCode::HTG, 100.34}, // Haitian gourde
    {CurrencyCode::HUF, 312.86}, // Hungarian forint
    {CurrencyCode::IDR, 14488.29},// Indonesian rupiah
    {CurrencyCode::ILS, 3.27},   // Israeli new shekel
    {CurrencyCode::INR, 75.23},  // Indian rupee
    {CurrencyCode::IQD, 1458.86},// Iraqi dinar
    {CurrencyCode::IRR, 42000.0},// Iranian rial
    {CurrencyCode::ISK, 127.17}, // Icelandic króna
    {CurrencyCode::JMD, 152.52}, // Jamaican dollar
    {CurrencyCode::JOD, 0.71},   // Jordanian dinar
    {CurrencyCode::JPY, 110.95}, // Japanese yen
    {CurrencyCode::KES, 114.91}, // Kenyan shilling
    {CurrencyCode::KGS, 84.77},  // Kyrgyzstani som
    {CurrencyCode::KHR, 4081.82},// Cambodian riel
    {CurrencyCode::KMF, 411.15}, // Comorian franc
    {CurrencyCode::KRW, 1181.53},// South Korean won
    {CurrencyCode::KWD, 0.30},   // Kuwaiti dinar
    {CurrencyCode::KYD, 0.83},   // Cayman Islands dollar
    {CurrencyCode::KZT, 423.45}, // Kazakhstani tenge
    {CurrencyCode::LAK, 9871.43},// Lao kip
    {CurrencyCode::LBP, 1508.44},// Lebanese pound
    {CurrencyCode::LKR, 204.71}, // Sri Lankan rupee
    {CurrencyCode::LRD, 171.79}, // Liberian dollar
    {CurrencyCode::LSL, 15.20},  // Lesotho loti
    {CurrencyCode::LYD, 4.48},   // Libyan dinar
    {CurrencyCode::MAD, 8.97},   // Moroccan dirham
    {CurrencyCode::MDL, 17.86},  // Moldovan leu
    {CurrencyCode::MGA, 4093.49},// Malagasy ariary
    {CurrencyCode::MKD, 50.81},  // Macedonian denar
    {CurrencyCode::MMK, 1668.86},// Burmese kyat
    {CurrencyCode::MNT, 2843.21},// Mongolian tögrög
    {CurrencyCode::MOP, 8.02},   // Macanese pataca
    {CurrencyCode::MRU, 36.37},  // Mauritanian ouguiya
    {CurrencyCode::MUR, 42.97},  // Mauritian rupee
    {CurrencyCode::MVR, 15.42},  // Maldivian rufiyaa
    {CurrencyCode::MWK, 807.27}, // Malawian kwacha
    {CurrencyCode::MXN, 21.40},  // Mexican peso
    {CurrencyCode::MYR, 4.16},   // Malaysian ringgit
    {CurrencyCode::MZN, 80.61},  // Mozambican metical
    {CurrencyCode::NAD, 15.20},  // Namibian dollar
    {CurrencyCode::NGN, 420.00}, // Nigerian naira
    {CurrencyCode::NIO, 34.88},  // Nicaraguan córdoba
    {CurrencyCode::NOK, 8.42},   // Norwegian krone
    {CurrencyCode::NPR, 122.34}, // Nepalese rupee
    {CurrencyCode::NZD, 1.39},   // New Zealand dollar
    {CurrencyCode::OMR, 0.39},   // Omani rial
    {CurrencyCode::PAB, 1.00},   // Panamanian balboa
    {CurrencyCode::PEN, 4.13},   // Peruvian sol
    {CurrencyCode::PGK, 3.49},   // Papua New Guinean kina
    {CurrencyCode::PHP, 48.08},  // Philippine peso
    {CurrencyCode::PKR, 179.67}, // Pakistani rupee
    {CurrencyCode::PLN, 3.90},   // Polish złoty
    {CurrencyCode::PYG, 6803.57},// Paraguayan guaraní
    {CurrencyCode::QAR, 3.64},   // Qatari riyal
    {CurrencyCode::RON, 4.00},   // Romanian leu
    {CurrencyCode::RSD, 98.76},  // Serbian dinar
    {CurrencyCode::RUB, 73.43},  // Russian ruble
    {CurrencyCode::RWF, 1017.39},// Rwandan franc
    {CurrencyCode::SAR, 3.75},   // Saudi riyal
    {CurrencyCode::SBD, 8.03},   // Solomon Islands dollar
    {CurrencyCode::SCR, 18.68},  // Seychellois rupee
    {CurrencyCode::SDG, 442.00}, // Sudanese pound
    {CurrencyCode::SEK, 8.91},   // Swedish krona
    {CurrencyCode::SGD, 1.35},   // Singapore dollar
    {CurrencyCode::SHP, 0.72},   // Saint Helena pound
    {CurrencyCode::SLL, 10423.39},// Sierra Leonean leone
    {CurrencyCode::SOS, 579.01}, // Somali shilling
    {CurrencyCode::SRD, 21.65},  // Surinamese dollar
    {CurrencyCode::SSP, 177.79}, // South Sudanese pound
    {CurrencyCode::STN, 20.53},  // São Tomé and Príncipe dobra
    {CurrencyCode::SYP, 2567.47},// Syrian pound
    {CurrencyCode::SZL, 15.20},  // Swazi lilangeni
    {CurrencyCode::THB, 32.15},  // Thai baht
    {CurrencyCode::TJS, 11.30},  // Tajikistani somoni
    {CurrencyCode::TMT, 3.50},   // Turkmenistan manat
    {CurrencyCode::TND, 3.12},   // Tunisian dinar
    {CurrencyCode::TOP, 2.28},   // Tongan paʻanga
    {CurrencyCode::TRY, 13.27},  // Turkish lira
    {CurrencyCode::TTD, 6.79},   // Trinidad and Tobago dollar
    {CurrencyCode::TWD, 27.92},  // New Taiwan dollar
    {CurrencyCode::TZS, 2318.52},// Tanzanian shilling
    {CurrencyCode::UAH, 27.75},  // Ukrainian hryvnia
    {CurrencyCode::UGX, 3567.36},// Ugandan shilling
    {CurrencyCode::USD, 1.00},   // United States dollar
    {CurrencyCode::UYU, 44.04},  // Uruguayan peso
    {CurrencyCode::UZS, 10970.21},// Uzbekistani soʻm
    {CurrencyCode::VES, 3534470.14},// Venezuelan bolívar soberano
    {CurrencyCode::VND, 22994.14},// Vietnamese đồng
    {CurrencyCode::VUV, 109.92}, // Vanuatu vatu
    {CurrencyCode::WST, 2.51},   // Samoan tālā
    {CurrencyCode::XAF, 567.60}, // Central African CFA franc
    {CurrencyCode::XCD, 2.70},   // East Caribbean dollar
    {CurrencyCode::XDR, 0.70},   // Special Drawing Rights
    {CurrencyCode::XOF, 567.60}, // West African CFA franc
    {CurrencyCode::XPF, 100.53}, // CFP franc
    {CurrencyCode::YER, 250.35}, // Yemeni rial
    {CurrencyCode::ZAR, 15.20},  // South African rand
    {CurrencyCode::ZMW, 23.64},  // Zambian kwacha
    {CurrencyCode::ZWL, 322.00}, // Zimbabwean dollar
};

bool validateCurrency(std::string curr) {
    return ((currencyMap.find(curr) == currencyMap.end()));
}

std::pair<int, int> Price::splitToIntegerAndDecimal() const
{
	int integerPart;
	int decimalPart;
	integerPart = mValue / 100;
	decimalPart = mValue % 100;

	return std::make_pair(integerPart, decimalPart);
}

int Price::parseCurrency(void) { return 0; }

float Price::getValue(void) const { return 0; }

int Price::getValueBiggestUnit(void) const
{
	std::pair<int, int> Pair = splitToIntegerAndDecimal();
	return Pair.first;
}

int Price::getValueSmallestUnit(void) const
{ 
	std::pair<int, int> Pair = splitToIntegerAndDecimal();
	return Pair.second;
}

std::string Price::getCurrency(void) const
{
    return mCurrency;
}

int Price::getCurrencyCode(void) const
{
    if (validateCurrency(mCurrency)) {
        throw std::out_of_range(("No value named ", mCurrency));
        return -1;
    }
    CurrencyCode curr = currencyMap[mCurrency];
    return static_cast<int>(curr);
}

std::string Price::getCurrencyName(void) const
{
    if (!validateCurrency(mCurrency)) {
        throw std::out_of_range("Unknown currency");
    }
    CurrencyCode code = currencyMap[mCurrency];
        switch (static_cast<int>(code)) {
        case static_cast<int>(CurrencyCode::AED): return "United Arab Emirates dirham";
        case static_cast<int>(CurrencyCode::AFN): return "Afghan afghani";
        case static_cast<int>(CurrencyCode::ALL): return "Albanian lek";
        case static_cast<int>(CurrencyCode::AMD): return "Armenian dram";
        case static_cast<int>(CurrencyCode::ANG): return "Netherlands Antillean guilder";
        case static_cast<int>(CurrencyCode::AOA): return "Angolan kwanza";
        case static_cast<int>(CurrencyCode::ARS): return "Argentine peso";
        case static_cast<int>(CurrencyCode::AUD): return "Australian dollar";
        case static_cast<int>(CurrencyCode::AWG): return "Aruban florin";
        case static_cast<int>(CurrencyCode::AZN): return "Azerbaijani manat";
        case static_cast<int>(CurrencyCode::BAM): return "Bosnia and Herzegovina convertible mark";
        case static_cast<int>(CurrencyCode::BBD): return "Barbados dollar";
        case static_cast<int>(CurrencyCode::BDT): return "Bangladeshi taka";
        case static_cast<int>(CurrencyCode::BGN): return "Bulgarian lev";
        case static_cast<int>(CurrencyCode::BHD): return "Bahraini dinar";
        case static_cast<int>(CurrencyCode::BIF): return "Burundian franc";
        case static_cast<int>(CurrencyCode::BMD): return "Bermudian dollar";
        case static_cast<int>(CurrencyCode::BND): return "Brunei dollar";
        case static_cast<int>(CurrencyCode::BOB): return "Bolivian boliviano";
        case static_cast<int>(CurrencyCode::BRL): return "Brazilian real";
        case static_cast<int>(CurrencyCode::BSD): return "Bahamian dollar";
        case static_cast<int>(CurrencyCode::BTN): return "Bhutanese ngultrum";
        case static_cast<int>(CurrencyCode::BWP): return "Botswana pula";
        case static_cast<int>(CurrencyCode::BYN): return "Belarusian ruble";
        case static_cast<int>(CurrencyCode::BZD): return "Belize dollar";
        case static_cast<int>(CurrencyCode::CAD): return "Canadian dollar";
        case static_cast<int>(CurrencyCode::CDF): return "Congolese franc";
        case static_cast<int>(CurrencyCode::CHE): return "WIR euro (complementary currency)";
        case static_cast<int>(CurrencyCode::CHF): return "Swiss franc";
        case static_cast<int>(CurrencyCode::CHW): return "WIR franc (complementary currency)";
        case static_cast<int>(CurrencyCode::CLF): return "Unidad de Fomento (funds code)";
        case static_cast<int>(CurrencyCode::CLP): return "Chilean peso";
        case static_cast<int>(CurrencyCode::COP): return "Colombian peso";
        case static_cast<int>(CurrencyCode::COU): return "Unidad de Valor Real (UVR) (funds code)";
        case static_cast<int>(CurrencyCode::CRC): return "Costa Rican colon";
        case static_cast<int>(CurrencyCode::CUC): return "Cuban convertible peso";
        case static_cast<int>(CurrencyCode::CUP): return "Cuban peso";
        case static_cast<int>(CurrencyCode::CVE): return "Cape Verdean escudo";
        case static_cast<int>(CurrencyCode::CZK): return "Czech koruna";
        case static_cast<int>(CurrencyCode::DJF): return "Djiboutian franc";
        case static_cast<int>(CurrencyCode::DKK): return "Danish krone";
        case static_cast<int>(CurrencyCode::DOP): return "Dominican peso";
        case static_cast<int>(CurrencyCode::DZD): return "Algerian dinar";
        case static_cast<int>(CurrencyCode::EGP): return "Egyptian pound";
        case static_cast<int>(CurrencyCode::ERN): return "Eritrean nakfa";
        case static_cast<int>(CurrencyCode::ETB): return "Ethiopian birr";
        case static_cast<int>(CurrencyCode::EUR): return "Euro";
        case static_cast<int>(CurrencyCode::FJD): return "Fiji dollar";
        case static_cast<int>(CurrencyCode::FKP): return "Falkland Islands pound";
        case static_cast<int>(CurrencyCode::GBP): return "Pound sterling";
        case static_cast<int>(CurrencyCode::GEL): return "Georgian lari";
        case static_cast<int>(CurrencyCode::GHS): return "Ghanaian cedi";
        case static_cast<int>(CurrencyCode::GIP): return "Gibraltar pound";
        case static_cast<int>(CurrencyCode::GMD): return "Gambian dalasi";
        case static_cast<int>(CurrencyCode::GNF): return "Guinean franc";
        case static_cast<int>(CurrencyCode::GTQ): return "Guatemalan quetzal";
        case static_cast<int>(CurrencyCode::GYD): return "Guyanese dollar";
        case static_cast<int>(CurrencyCode::HKD): return "Hong Kong dollar";
        case static_cast<int>(CurrencyCode::HNL): return "Honduran lempira";
        case static_cast<int>(CurrencyCode::HRK): return "Croatian kuna";
        case static_cast<int>(CurrencyCode::HTG): return "Haitian gourde";
        case static_cast<int>(CurrencyCode::HUF): return "Hungarian forint";
        case static_cast<int>(CurrencyCode::IDR): return "Indonesian rupiah";
        case static_cast<int>(CurrencyCode::ILS): return "Israeli new shekel";
        case static_cast<int>(CurrencyCode::INR): return "Indian rupee";
        case static_cast<int>(CurrencyCode::IQD): return "Iraqi dinar";
        case static_cast<int>(CurrencyCode::IRR): return "Iranian rial";
        case static_cast<int>(CurrencyCode::ISK): return "Icelandic króna (plural: kronur)";
        case static_cast<int>(CurrencyCode::JMD): return "Jamaican dollar";
        case static_cast<int>(CurrencyCode::JOD): return "Jordanian dinar";
        case static_cast<int>(CurrencyCode::JPY): return "Japanese yen";
        case static_cast<int>(CurrencyCode::KES): return "Kenyan shilling";
        case static_cast<int>(CurrencyCode::KGS): return "Kyrgyzstani som";
        case static_cast<int>(CurrencyCode::KHR): return "Cambodian riel";
        case static_cast<int>(CurrencyCode::KMF): return "Comoro franc";
        case static_cast<int>(CurrencyCode::KPW): return "North Korean won";
        case static_cast<int>(CurrencyCode::KRW): return "South Korean won";
        case static_cast<int>(CurrencyCode::KWD): return "Kuwaiti dinar";
        case static_cast<int>(CurrencyCode::KYD): return "Cayman Islands dollar";
        case static_cast<int>(CurrencyCode::KZT): return "Kazakhstani tenge";
        case static_cast<int>(CurrencyCode::LAK): return "Lao kip";
        case static_cast<int>(CurrencyCode::LBP): return "Lebanese pound";
        case static_cast<int>(CurrencyCode::LKR): return "Sri Lankan rupee";
        case static_cast<int>(CurrencyCode::LRD): return "Liberian dollar";
        case static_cast<int>(CurrencyCode::LSL): return "Lesotho loti";
        case static_cast<int>(CurrencyCode::LYD): return "Libyan dinar";
        case static_cast<int>(CurrencyCode::MAD): return "Moroccan dirham";
        case static_cast<int>(CurrencyCode::MDL): return "Moldovan leu";
        case static_cast<int>(CurrencyCode::MGA): return "Malagasy ariary";
        case static_cast<int>(CurrencyCode::MKD): return "Macedonian denar";
        case static_cast<int>(CurrencyCode::MMK): return "Myanmar kyat";
        case static_cast<int>(CurrencyCode::MNT): return "Mongolian togrog";
        case static_cast<int>(CurrencyCode::MOP): return "Macanese pataca";
        case static_cast<int>(CurrencyCode::MRU): return "Mauritanian ouguiya";
        case static_cast<int>(CurrencyCode::MUR): return "Mauritian rupee";
        case static_cast<int>(CurrencyCode::MVR): return "Maldivian rufiyaa";
        case static_cast<int>(CurrencyCode::MWK): return "Malawian kwacha";
        case static_cast<int>(CurrencyCode::MXN): return "Mexican peso";
        case static_cast<int>(CurrencyCode::MXV): return "Mexican Unidad de Inversion (UDI) (funds code)";
        case static_cast<int>(CurrencyCode::MYR): return "Malaysian ringgit";
        case static_cast<int>(CurrencyCode::MZN): return "Mozambican metical";
        case static_cast<int>(CurrencyCode::NAD): return "Namibian dollar";
        case static_cast<int>(CurrencyCode::NGN): return "Nigerian naira";
        case static_cast<int>(CurrencyCode::NIO): return "Nicaraguan cordoba";
        case static_cast<int>(CurrencyCode::NOK): return "Norwegian krone";
        case static_cast<int>(CurrencyCode::NPR): return "Nepalese rupee";
        case static_cast<int>(CurrencyCode::NZD): return "New Zealand dollar";
        case static_cast<int>(CurrencyCode::OMR): return "Omani rial";
        case static_cast<int>(CurrencyCode::PAB): return "Panamanian balboa";
        case static_cast<int>(CurrencyCode::PEN): return "Peruvian sol";
        case static_cast<int>(CurrencyCode::PGK): return "Papua New Guinean kina";
        case static_cast<int>(CurrencyCode::PHP): return "Philippine peso";
        case static_cast<int>(CurrencyCode::PKR): return "Pakistani rupee";
        case static_cast<int>(CurrencyCode::PLN): return "Polish zloty";
        case static_cast<int>(CurrencyCode::PYG): return "Paraguayan guaraní";
        case static_cast<int>(CurrencyCode::QAR): return "Qatari riyal";
        case static_cast<int>(CurrencyCode::RON): return "Romanian leu";
        case static_cast<int>(CurrencyCode::RSD): return "Serbian dinar";
        case static_cast<int>(CurrencyCode::CNY): return "Renminbi";
        case static_cast<int>(CurrencyCode::RUB): return "Russian ruble";
        case static_cast<int>(CurrencyCode::RWF): return "Rwandan franc";
        case static_cast<int>(CurrencyCode::SAR): return "Saudi riyal";
        case static_cast<int>(CurrencyCode::SBD): return "Solomon Islands dollar";
        case static_cast<int>(CurrencyCode::SCR): return "Seychelles rupee";
        case static_cast<int>(CurrencyCode::SDG): return "Sudanese pound";
        case static_cast<int>(CurrencyCode::SEK): return "Swedish krona (plural: kronor)";
        case static_cast<int>(CurrencyCode::SGD): return "Singapore dollar";
        case static_cast<int>(CurrencyCode::SHP): return "Saint Helena pound";
        case static_cast<int>(CurrencyCode::SLL): return "Sierra Leonean leone";
        case static_cast<int>(CurrencyCode::SLE): return "Sierra Leonean leone";
        case static_cast<int>(CurrencyCode::SOS): return "Somali shilling";
        case static_cast<int>(CurrencyCode::SRD): return "Surinamese dollar";
        case static_cast<int>(CurrencyCode::SSP): return "South Sudanese pound";
        case static_cast<int>(CurrencyCode::STN): return "Sao Tome and Príncipe dobra";
        case static_cast<int>(CurrencyCode::SVC): return "Salvadoran colón";
        case static_cast<int>(CurrencyCode::SYP): return "Syrian pound";
        case static_cast<int>(CurrencyCode::SZL): return "Swazi lilangeni";
        case static_cast<int>(CurrencyCode::THB): return "Thai baht";
        case static_cast<int>(CurrencyCode::TJS): return "Tajikistani somoni";
        case static_cast<int>(CurrencyCode::TMT): return "Turkmenistan manat";
        case static_cast<int>(CurrencyCode::TND): return "Tunisian dinar";
        case static_cast<int>(CurrencyCode::TOP): return "Tongan pa anga";
        case static_cast<int>(CurrencyCode::TRY): return "Turkish lira";
        case static_cast<int>(CurrencyCode::TTD): return "Trinidad and Tobago dollar";
        case static_cast<int>(CurrencyCode::TWD): return "New Taiwan dollar";
        case static_cast<int>(CurrencyCode::TZS): return "Tanzanian shilling";
        case static_cast<int>(CurrencyCode::UAH): return "Ukrainian hryvnia";
        case static_cast<int>(CurrencyCode::UGX): return "Ugandan shilling";
        case static_cast<int>(CurrencyCode::USD): return "United States dollar";
        case static_cast<int>(CurrencyCode::USN): return "United States dollar (next day) (funds code)";
        case static_cast<int>(CurrencyCode::UYI): return "Uruguay Peso en Unidades Indexadas (URUIURUI) (funds code)";
        case static_cast<int>(CurrencyCode::UYU): return "Uruguayan peso";
        case static_cast<int>(CurrencyCode::UYW): return "Unidad previsional";
        case static_cast<int>(CurrencyCode::UZS): return "Uzbekistan som";
        case static_cast<int>(CurrencyCode::VED): return "Venezuelan bolívar digital";
        case static_cast<int>(CurrencyCode::VES): return "Venezuelan bolívar soberano";
        case static_cast<int>(CurrencyCode::VND): return "Vietnamese dong";
        case static_cast<int>(CurrencyCode::VUV): return "Vanuatu vatu";
        case static_cast<int>(CurrencyCode::WST): return "Samoan tala";
        case static_cast<int>(CurrencyCode::XAF): return "CFA franc BEAC";
        case static_cast<int>(CurrencyCode::XAG): return "Silver (one troy ounce)";
        case static_cast<int>(CurrencyCode::XAU): return "Gold (one troy ounce)";
        case static_cast<int>(CurrencyCode::XBA): return "European Composite Unit (EURCO) (bond market unit)";
        case static_cast<int>(CurrencyCode::XBB): return "European Monetary Unit (E.M.U.-6) (bond market unit)";
        case static_cast<int>(CurrencyCode::XBC): return "European Unit of Account 9 (E.U.A.-9) (bond market unit)";
        case static_cast<int>(CurrencyCode::XBD): return "European Unit of Account 17 (E.U.A.-17) (bond market unit)";
        case static_cast<int>(CurrencyCode::XCD): return "East Caribbean dollar";
        case static_cast<int>(CurrencyCode::XDR): return "Special drawing rights";
        case static_cast<int>(CurrencyCode::XOF): return "CFA franc BCEAO";
        case static_cast<int>(CurrencyCode::XPD): return "Palladium (one troy ounce)";
        case static_cast<int>(CurrencyCode::XPF): return "CFP franc (franc Pacifique)";
        case static_cast<int>(CurrencyCode::XPT): return "Platinum (one troy ounce)";
        case static_cast<int>(CurrencyCode::XSU): return "SUCRE";
        case static_cast<int>(CurrencyCode::XTS): return "Code reserved for testing";
        case static_cast<int>(CurrencyCode::XUA): return "ADB Unit of Account";
        case static_cast<int>(CurrencyCode::XXX): return "No currency";
        case static_cast<int>(CurrencyCode::YER): return "Yemeni rial";
        case static_cast<int>(CurrencyCode::ZAR): return "South African rand";
        case static_cast<int>(CurrencyCode::ZMW): return "Zambian kwacha";
        case static_cast<int>(CurrencyCode::ZWL): return "Zimbabwean dollar";
        default: return "Unknown currency";
        }
}

void Price::setValue(int newValue) { }
void Price::setValue(float newValue) { }
void Price::setCurrency(std::string currencyCode) { }
void Price::showAvailableCurrencies() const { }
