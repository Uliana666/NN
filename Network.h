#ifndef NN_ILOVEYOU_NETWORK_H
#define NN_ILOVEYOU_NETWORK_H

#include "const.h"
#include "AbstractActivationFunction.h"
#include "random"


struct Network {
    std::vector<int> sizes = {N, K, K, N};
    std::vector<std::vector<double>> w[K - 1];
    std::vector<double> input[K], output[K];
    std::vector<AbstractActivationFunction *> function;

    Network();

    std::vector<double> Calc(std::vector<double> data);

    void Education(std::vector<double> data, std::vector<double> test);
};


#endif
