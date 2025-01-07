#pragma once 

#include <cmath>
#include "standardImage.h"

class Circle : public StandardImage {
private: 
    const double RADIUS_ = 0.25;

public:
    std::vector<uint8_t> getImage() override;
    
private:
    void fillImageVector() override;
    bool isCircle(double x, double y);
};