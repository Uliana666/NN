#ifndef NN_ILOVEYOU_ABSTRACTACTIVATIONFUNCTION_H
#define NN_ILOVEYOU_ABSTRACTACTIVATIONFUNCTION_H

#include <iostream>
#include <vector>
struct AbstractActivationFunction {
    virtual std::vector<double> forward_prop(std::vector<double> data) = 0;
    virtual std::vector<double> backward_prop(std::vector<double> data) = 0;
};

#endif
