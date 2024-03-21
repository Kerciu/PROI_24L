#include <iostream>

struct programArguments {

};

programArguments parseArgs(int argc, char* argv[]) {
    programArguments args;

    if (argc != 7) {
        std::cerr << "Usage: " << argv[0] << " Name Type Date(YYYY-MM-DD) Transport Weight(in kilos) Volume(in liters)\n";
        exit(1);
    }

    args.name = argv[1];
    args.type = argv[2];
    args.date = argv[3];
    args.transport = argv[4];
    args.weight = std::stod(argv[5]);
    args.volume = std::stod(argv[6]);

    return args;
}

int main(int argc, char* argv[])
{
    programArguments args = parseArgs(argc, argv);
    return 0;
}
