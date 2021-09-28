#include <iostream>
#include "bits/stdc++.h"

#include "Network.h"

int main() {
    Network net;
    std::ifstream test("test");
    std::vector<double> v(N), g(N);
    for (int i = 0; i < 500000; ++i) {
        for (int j = 0; j < N; ++j) test >> v[j];
        for (int j = 0; j < N; ++j) test >> g[j];
        net.Education(v, g);
    }
    std::cout << "GO" << std::endl;
    while (true) {
        double x, y, z;
        std::cin >> x >> y >> z;
        auto vt = net.Calc({x, y, z});
        for (auto e: vt) std::cout << e << ' ';
        std::cout << std::endl;
    }
}
