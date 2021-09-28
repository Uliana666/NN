#ifndef NN_ILOVEYOU_FUNCTIONS_H
#define NN_ILOVEYOU_FUNCTIONS_H


#include "AbstractActivationFunction.h"
#include <iostream>
#include <vector>

struct Sigmoid : public AbstractActivationFunction{
    std::vector<double> forward_prop(std::vector<double> data) override;
    std::vector<double> backward_prop(std::vector<double> data) override;
};
class Softmax : public AbstractActivationFunction{
    std::vector<double> forward_prop(std::vector<double> data) override;
    std::vector<double> backward_prop(std::vector<double> data, std::vector<double> dE);
};


#endif
