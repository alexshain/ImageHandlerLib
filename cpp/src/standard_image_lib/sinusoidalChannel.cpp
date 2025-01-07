#define _USE_MATH_DEFINES

#include "sinusoidalChannel.h"
#include "../file_operations.h"

#include <iostream>
#include <cmath>

std::vector<uint8_t> SinusoidalChannel::getImage() {
    fillImageVector();

    return image_;
}

void SinusoidalChannel::fillImageVector() {
    double pixel_size = SIZE_ / resolution_;
    for(size_t i = 0; i < resolution_; ++i) {
        for(size_t j = 0; j < resolution_; ++j) {
            size_t ind = i * resolution_ + j;
            if(isSinusoidalChannel(j * pixel_size, i * pixel_size)) {
                image_[ind] = 255;    
            } else {
                image_[ind] = 0;
            }
        }
    }
}

bool SinusoidalChannel::isSinusoidalChannel(double x, double y) {
    bool is_upper_wall = A_*sin(2*M_PI * x / T_) + SIZE_/2 + WIDTH_/2 < y;
    bool is_down_wall = A_*sin(2*M_PI * x / T_) + SIZE_/2 - WIDTH_/2 > y;
    return is_upper_wall || is_down_wall;
}