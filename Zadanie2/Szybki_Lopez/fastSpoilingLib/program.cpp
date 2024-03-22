#include <iostream>
#include <cstdlib>
#include <string>
#include "Date.h"
#include "weightAndVolume.h"

struct programArguments {
    using Name = std::string;
    using Type = std::string;
    using Transport = std::string;
    using WeightAndVolume = weightAndVolume;

    Name name;
    Type type;
    Date prodDate;
    Date expirDate;
    Transport transportMeans;
    WeightAndVolume weightAndVolume;
};

programArguments parseArgs(int argc, char* argv[]) {
    programArguments args;

    if (argc != 12) {
        std::cerr << "Usage: " << argv[0] << " Name, Type, Date (day, month, year), Transport, Weight And Volume (in kilos and liters)\n";
        exit(1);
    }

    args.name = argv[1];
    args.type = argv[2];
    args.prodDate = Date(std::stoi(argv[3]), std::stoi(argv[4]), std::stoi(argv[5]));
    args.expirDate = Date(std::stoi(argv[6]), std::stoi(argv[7]), std::stoi(argv[8]));
    args.transport = argv[9];
    args.weightAndVolume = weightAndVolume(std::stod(argv[10]), std::stod(argv[11]));

    return args;
}

int main(int argc, char* argv[])
{
    programArguments args = parseArgs(argc, argv);
    return 0;
}