#include <iostream>
#include <fstream>
#include "polyline.h"
#include "projection.h"

using namespace std;
using namespace projection;

Polyline read(std::string const& filename) {
    ifstream f{filename};
    if (!f.is_open()) {
        cerr << "File opening failed";
        return {};
    }
    Polyline polyline;
    for (Point p; f >> p; ) {
        polyline.push_back(move(p));
    }
    return polyline;
}

int main(int argc, char* argv[]) {
    if (argc > 4) {
        std::string filename = argv[1];
        Point point{
            std::stod(argv[2]),
            std::stod(argv[3]),
            std::stod(argv[4])
        };
        auto polyline = read(filename);
        auto projections = find(polyline, point);
        cout << projections.size() << '\n';
        for (auto const& p: projections) {
            cout << p << '\n';
        }
    }
    return 0;
}
