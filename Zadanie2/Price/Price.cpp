#include "Price.h"
#include <string>
#include <iostream>
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
std::unordered_map<CurrencyCode, std::string> currencyName = {
    { CurrencyCode::AED, "United Arab Emirates dirham" },
    { CurrencyCode::AFN, "Afghan afghani" },
    { CurrencyCode::ALL, "Albanian lek" },
    { CurrencyCode::AMD, "Armenian dram" },
    { CurrencyCode::ANG, "Netherlands Antillean guilder" },
    { CurrencyCode::AOA, "Angolan kwanza" },
    { CurrencyCode::ARS, "Argentine peso" },
    { CurrencyCode::AUD, "Australian dollar" },
    { CurrencyCode::AWG, "Aruban florin" },
    { CurrencyCode::AZN, "Azerbaijani manat" },
    { CurrencyCode::BAM, "Bosnia and Herzegovina convertible mark" },
    { CurrencyCode::BBD, "Barbados dollar" },
    { CurrencyCode::BDT, "Bangladeshi taka" },
    { CurrencyCode::BGN, "Bulgarian lev" },
    { CurrencyCode::BHD, "Bahraini dinar" },
    { CurrencyCode::BIF, "Burundian franc" },
    { CurrencyCode::BMD, "Bermudian dollar" },
    { CurrencyCode::BND, "Brunei dollar" },
    { CurrencyCode::BOB, "Bolivian boliviano" },
    { CurrencyCode::BRL, "Brazilian real" },
    { CurrencyCode::BSD, "Bahamian dollar" },
    { CurrencyCode::BTN, "Bhutanese ngultrum" },
    { CurrencyCode::BWP, "Botswana pula" },
    { CurrencyCode::BYN, "Belarusian ruble" },
    { CurrencyCode::BZD, "Belize dollar" },
    { CurrencyCode::CAD, "Canadian dollar" },
    { CurrencyCode::CDF, "Congolese franc" },
    { CurrencyCode::CHE, "WIR euro (complementary currency)" },
    { CurrencyCode::CHF, "Swiss franc" },
    { CurrencyCode::CHW, "WIR franc (complementary currency)" },
    { CurrencyCode::CLF, "Unidad de Fomento (funds code)" },
    { CurrencyCode::CLP, "Chilean peso" },
    { CurrencyCode::COP, "Colombian peso" },
    { CurrencyCode::COU, "Unidad de Valor Real (UVR) (funds code)" },
    { CurrencyCode::CRC, "Costa Rican colon" },
    { CurrencyCode::CUC, "Cuban convertible peso" },
    { CurrencyCode::CUP, "Cuban peso" },
    { CurrencyCode::CVE, "Cape Verdean escudo" },
    { CurrencyCode::CZK, "Czech koruna" },
    { CurrencyCode::DJF, "Djiboutian franc" },
    { CurrencyCode::DKK, "Danish krone" },
    { CurrencyCode::DOP, "Dominican peso" },
    { CurrencyCode::DZD, "Algerian dinar" },
    { CurrencyCode::EGP, "Egyptian pound" },
    { CurrencyCode::ERN, "Eritrean nakfa" },
    { CurrencyCode::ETB, "Ethiopian birr" },
    { CurrencyCode::EUR, "Euro" },
    { CurrencyCode::FJD, "Fiji dollar" },
    { CurrencyCode::FKP, "Falkland Islands pound" },
    { CurrencyCode::GBP, "Pound sterling" },
    { CurrencyCode::GEL, "Georgian lari" },
    { CurrencyCode::GHS, "Ghanaian cedi" },
    { CurrencyCode::GIP, "Gibraltar pound" },
    { CurrencyCode::GMD, "Gambian dalasi" },
    { CurrencyCode::GNF, "Guinean franc" },
    { CurrencyCode::GTQ, "Guatemalan quetzal" },
    { CurrencyCode::GYD, "Guyanese dollar" },
    { CurrencyCode::HKD, "Hong Kong dollar" },
    { CurrencyCode::HNL, "Honduran lempira" },
    { CurrencyCode::HRK, "Croatian kuna" },
    { CurrencyCode::HTG, "Haitian gourde" },
    { CurrencyCode::HUF, "Hungarian forint" },
    { CurrencyCode::IDR, "Indonesian rupiah" },
    { CurrencyCode::ILS, "Israeli new shekel" },
    { CurrencyCode::INR, "Indian rupee" },
    { CurrencyCode::IQD, "Iraqi dinar" },
    { CurrencyCode::IRR, "Iranian rial" },
    { CurrencyCode::ISK, "Icelandic króna (plural: kronur)" },
    { CurrencyCode::JMD, "Jamaican dollar" },
    { CurrencyCode::JOD, "Jordanian dinar" },
    { CurrencyCode::JPY, "Japanese yen" },
    { CurrencyCode::KES, "Kenyan shilling" },
    { CurrencyCode::KGS, "Kyrgyzstani som" },
    { CurrencyCode::KHR, "Cambodian riel" },
    { CurrencyCode::KMF, "Comoro franc" },
    { CurrencyCode::KPW, "North Korean won" },
    { CurrencyCode::KRW, "South Korean won" },
    { CurrencyCode::KWD, "Kuwaiti dinar" },
    { CurrencyCode::KYD, "Cayman Islands dollar" },
    { CurrencyCode::KZT, "Kazakhstani tenge" },
    { CurrencyCode::LAK, "Lao kip" },
    { CurrencyCode::LBP, "Lebanese pound" },
    { CurrencyCode::LKR, "Sri Lankan rupee" },
    { CurrencyCode::LRD, "Liberian dollar" },
    { CurrencyCode::LSL, "Lesotho loti" },
    { CurrencyCode::LYD, "Libyan dinar" },
    { CurrencyCode::MAD, "Moroccan dirham" },
    { CurrencyCode::MDL, "Moldovan leu" },
    { CurrencyCode::MGA, "Malagasy ariary" },
    { CurrencyCode::MKD, "Macedonian denar" },
    { CurrencyCode::MMK, "Myanmar kyat" },
    { CurrencyCode::MNT, "Mongolian togrog" },
    { CurrencyCode::MOP, "Macanese pataca" },
    { CurrencyCode::MRU, "Mauritanian ouguiya" },
    { CurrencyCode::MUR, "Mauritian rupee" },
    { CurrencyCode::MVR, "Maldivian rufiyaa" },
    { CurrencyCode::MWK, "Malawian kwacha" },
    { CurrencyCode::MXN, "Mexican peso" },
    { CurrencyCode::MXV, "Mexican Unidad de Inversion (UDI) (funds code)" },
    { CurrencyCode::MYR, "Malaysian ringgit" },
    { CurrencyCode::MZN, "Mozambican metical" },
    { CurrencyCode::NAD, "Namibian dollar" },
    { CurrencyCode::NGN, "Nigerian naira" },
    { CurrencyCode::NIO, "Nicaraguan cordoba" },
    { CurrencyCode::NOK, "Norwegian krone" },
    { CurrencyCode::NPR, "Nepalese rupee" },
    { CurrencyCode::NZD, "New Zealand dollar" },
    { CurrencyCode::OMR, "Omani rial" },
    { CurrencyCode::PAB, "Panamanian balboa" },
    { CurrencyCode::PEN, "Peruvian sol" },
    { CurrencyCode::PGK, "Papua New Guinean kina" },
    { CurrencyCode::PHP, "Philippine peso" },
    { CurrencyCode::PKR, "Pakistani rupee" },
    { CurrencyCode::PLN, "Polish zloty" },
    { CurrencyCode::PYG, "Paraguayan guaraní" },
    { CurrencyCode::QAR, "Qatari riyal" },
    { CurrencyCode::RON, "Romanian leu" },
    { CurrencyCode::RSD, "Serbian dinar" },
    { CurrencyCode::CNY, "Renminbi" },
    { CurrencyCode::RUB, "Russian ruble" },
    { CurrencyCode::RWF, "Rwandan franc" },
    { CurrencyCode::SAR, "Saudi riyal" },
    { CurrencyCode::SBD, "Solomon Islands dollar" },
    { CurrencyCode::SCR, "Seychelles rupee" },
    { CurrencyCode::SDG, "Sudanese pound" },
    { CurrencyCode::SEK, "Swedish krona (plural: kronor)" },
    { CurrencyCode::SGD, "Singapore dollar" },
    { CurrencyCode::SHP, "Saint Helena pound" },
    { CurrencyCode::SLL, "Sierra Leonean leone" },
    { CurrencyCode::SLE, "Sierra Leonean leone" },
    { CurrencyCode::SOS, "Somali shilling" },
    { CurrencyCode::SRD, "Surinamese dollar" },
    { CurrencyCode::SSP, "South Sudanese pound" },
    { CurrencyCode::STN, "Sao Tome and Príncipe dobra" },
    { CurrencyCode::SVC, "Salvadoran colón" },
    { CurrencyCode::SYP, "Syrian pound" },
    { CurrencyCode::SZL, "Swazi lilangeni" },
    { CurrencyCode::THB, "Thai baht" },
    { CurrencyCode::TJS, "Tajikistani somoni" },
    { CurrencyCode::TMT, "Turkmenistan manat" },
    { CurrencyCode::TND, "Tunisian dinar" },
    { CurrencyCode::TOP, "Tongan pa anga" },
    { CurrencyCode::TRY, "Turkish lira" },
    { CurrencyCode::TTD, "Trinidad and Tobago dollar" },
    { CurrencyCode::TWD, "New Taiwan dollar" },
    { CurrencyCode::TZS, "Tanzanian shilling" },
    { CurrencyCode::UAH, "Ukrainian hryvnia" },
    { CurrencyCode::UGX, "Ugandan shilling" },
    { CurrencyCode::USD, "United States dollar" },
    { CurrencyCode::USN, "United States dollar (next day) (funds code)" },
    { CurrencyCode::UYI, "Uruguay Peso en Unidades Indexadas (URUIURUI) (funds code)" },
    { CurrencyCode::UYU, "Uruguayan peso" },
    { CurrencyCode::UYW, "Unidad previsional" },
    { CurrencyCode::UZS, "Uzbekistan som" },
    { CurrencyCode::VED, "Venezuelan bolívar digital" },
    { CurrencyCode::VES, "Venezuelan bolívar soberano" },
    { CurrencyCode::VND, "Vietnamese dong" },
    { CurrencyCode::VUV, "Vanuatu vatu" },
    { CurrencyCode::WST, "Samoan tala" },
    { CurrencyCode::XAF, "CFA franc BEAC" },
    { CurrencyCode::XAG, "Silver (one troy ounce)" },
    { CurrencyCode::XAU, "Gold (one troy ounce)" },
    { CurrencyCode::XBA, "European Composite Unit (EURCO) (bond market unit)" },
    { CurrencyCode::XBB, "European Monetary Unit (E.M.U.-6) (bond market unit)" },
    { CurrencyCode::XBC, "European Unit of Account 9 (E.U.A.-9) (bond market unit)" },
    { CurrencyCode::XBD, "European Unit of Account 17 (E.U.A.-17) (bond market unit)" },
    { CurrencyCode::XCD, "East Caribbean dollar" },
    { CurrencyCode::XDR, "Special drawing rights" },
    { CurrencyCode::XOF, "CFA franc BCEAO" },
    { CurrencyCode::XPD, "Palladium (one troy ounce)" },
    { CurrencyCode::XPF, "CFP franc (franc Pacifique)" },
    { CurrencyCode::XPT, "Platinum (one troy ounce)" },
    { CurrencyCode::XSU, "SUCRE" },
    { CurrencyCode::XTS, "Code reserved for testing" },
    { CurrencyCode::XUA, "ADB Unit of Account" },
    { CurrencyCode::XXX, "No currency" },
    { CurrencyCode::YER, "Yemeni rial" },
    { CurrencyCode::ZAR, "South African rand" },
    { CurrencyCode::ZMW, "Zambian kwacha" },
    { CurrencyCode::ZWL, "Zimbabwean dollar" }
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

double Price::getValue(void) const { return (double) mValue / 100; }

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
    std::string nameCurr = currencyName[code];

    return nameCurr;
}

void Price::setValue(int newValue)
{
    
}

void Price::setValue(float newValue)
{

}

void Price::setCurrency(std::string currencyCode)
{

}

void Price::showAvailableCurrencies() const
{
    for (const auto& keyValue : currencyName)
    {
        std::cout << keyValue.second << std::endl;
    }
}

void Price::showAvailableCurrenciesShortAndCode() const
{
    for (const auto& keyValue : currencyMap)
    {
        std::cout << keyValue.first << ' ' << static_cast<int>(keyValue.second) << std::endl;
    }
}