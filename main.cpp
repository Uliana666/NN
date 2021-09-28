#include <iostream>
#include "bits/stdc++.h"

#include "Network.h"

using namespace std;

int main() {
    Network net;
    std::ifstream test("test");
    for (int i = 0; i < 500000; ++i) {
        std::vector<double> v, g;
        double x;
        for (int j = 1; j < K; ++j) test >> x, v.push_back(x);
        for (int j = 1; j < K; ++j) test >> x, g.push_back(x);
        //for (auto e: v) cout << e << ' ';
        //cout << endl;
        //for (auto e: g) cout << e << ' ';
        //cout << endl;
        net.Education(v, g);
        //auto vt = net.Calc(v);
        //for (auto e: vt) std::cout << e << ' ';
        //std::cout << std::endl;
    }
    std::cout << "GO" << std::endl;
    while (true) {
        double x, y, z;
        std::cin >> x >> y >> z;
        auto v = net.Calc({x, y, z});
        for (auto e: v) std::cout << e << ' ';
        std::cout << std::endl;
    }
}
