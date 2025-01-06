#include "circle.h"
#include "../file_operations.h"

#include <iostream>
#include <regex>

std::vector<uint8_t> Circle::getImage() {
    fillImageVector();
    return image_;
}

void Circle::fillImageVector() {
    for(size_t i = 0; i < resolution_; ++i) {
        image_[i] = 255;
        image_[(image_.size()-1) - i] = 255;
    }

    double pixel_size = SIZE_ / resolution_;
    for(size_t i = 1; i < resolution_ - 1; ++i) {
        for(size_t j = 0; j < resolution_; ++j) {
            size_t ind = i * resolution_ + j;
            if(isCircle(i * pixel_size, j * pixel_size)) {
                image_[ind] = 255;    
            } else {
                image_[ind] = 0;
            }
        }
    }
}

bool Circle::isCircle(double x, double y) {
    return pow(x-0.5, 2) + pow(y-0.5, 2) - pow(RADIUS_, 2) < 0;
}