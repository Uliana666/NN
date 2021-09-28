
#include "Functions.h"
#include "const.h"
#include "cmath"

double fun(double x) {
    return 1. / (1. + exp(-Alpha * 2. * x));
}

std::vector<double> Sigmoid::forward_prop(std::vector<double> data) {
    std::vector<double> res;
    res.reserve(data.size());
    for (auto e: data)
        res.push_back(fun(e));
    return res;
}

/*std::vector<double> Sigmoid::backward_prop(std::vector<double> data) {
    std::vector<double> res;
    res.reserve(data.size());
    for (auto e: data)
        res.push_back(2. * Alpha * fun(e) * (1. - fun(e)));
    return res;
}*/

std::vector<double> Sigmoid::backward_prop(std::vector<double> data, std::vector<double> dE) {
    for (int i = 0; i < data.size(); ++i)
        dE[i] *= 2. * Alpha * fun(data[i]) * (1. - fun(data[i]));
    return dE;
}

std::vector<double> Softmax::forward_prop(std::vector<double> data) {
    std::vector<double> res;
    double sm = 0;
    for (auto e: data)
        sm += exp(e);
    res.reserve(data.size());
    for (auto e: data) res.push_back(exp(e) / sm);
    return res;
}

std::vector<double> Softmax::backward_prop(std::vector<double> data, std::vector<double> dE) {
    std::vector<double> res;
    double sm = 0;
    for (auto e: data) sm += exp(e);
    for (size_t i = 0; i < dE.size(); ++i) {
        res.push_back(0);
        for (size_t k = 0; k < dE.size(); ++k) {
            if (i != k)
                res.back() += -dE[k] * exp(data[k]) * exp(data[i]) / sm / sm;
            else
                res.back() += dE[k] * exp(data[k]) * (sm - exp(data[k])) / sm / sm;
        }
    }
    return res;
}