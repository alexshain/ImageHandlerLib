#pragma once 

#include "standardImage.h"

class SinusoidalChannel : public StandardImage {
private:
    const double WIDTH_ = 0.2;
    const double T_ = 1;
    const double A_ = 0.1;

public:
    std::vector<uint8_t> getImage() override;

private:
    void fillImageVector() override;
    bool isSinusoidalChannel(double x, double y); 
};