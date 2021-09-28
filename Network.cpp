#include "Network.h"
#include "const.h"
#include "Functions.h"
#include <iostream>
#include <random>
#include <utility>

std::mt19937 gen(777);
std::uniform_real_distribution<> dis(0.0, 0.5);
Sigmoid sigm;

Network::Network() {
    w[0].resize(N), w[1].resize(K), w[2].resize(K);
    for (auto &e: w[0]) e.resize(K);
    for (auto &e: w[1]) e.resize(K);
    for (auto &e: w[2]) e.resize(N);
    for (auto &i: w)
        for (auto &j: i)
            for (double &k: j)
                k = 1. * dis(gen);
    for (int i = 0; i < K; ++i)
        function.push_back(&sigm);
}

using namespace std;

std::vector<double> Network::Calc(std::vector<double> data) {
    for (int i = 0; i < K - 1; ++i) {
        input[i] = data;
        data = function[i]->forward_prop(data);
        output[i] = data;
        std::vector<double> in(sizes[i + 1], 0.l);
        for (size_t j = 0; j < data.size(); ++j)
            for (int k = 0; k < sizes[i + 1]; ++k) {
                in[k] += data[j] * w[i][j][k];
            }
        data = in;
    }
    input[K - 1] = data;
    return function[K - 1]->forward_prop(data);
}

void Network::Education(std::vector<double> data, std::vector<double> test) {
    output[K - 1] = Calc(std::move(data));
    std::cout << output[K - 1][0] << ' ' << output[K - 1][1] << ' ' << output[K - 1][2] << ' ' << std::endl;
    std::vector<double> lay;
    lay.reserve(N);
    for (int i = 0; i < N; ++i) lay.push_back(output[K - 1][i] - test[i]);
    for (int i = K - 2; i >= 0; --i) {
        lay = function[i + 1]->backward_prop(input[i + 1], lay);
        std::vector<double> lay2(sizes[i], 0.l);
        for (int j = 0; j < sizes[i]; ++j)
            for (int k = 0; k < sizes[i + 1]; ++k)
                lay2[j] += lay[k] * w[i][j][k];
        for (int j = 0; j < sizes[i]; ++j)
            for (int k = 0; k < sizes[i + 1]; ++k)
                w[i][j][k] -= n * lay[k] * output[i][j];
        lay = lay2;
    }
}
