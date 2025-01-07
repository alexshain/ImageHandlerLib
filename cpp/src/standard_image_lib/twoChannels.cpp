#include "twoChannels.h"

#include <iostream>

std::vector<uint8_t> TwoChannels::getImage() {
    normalizeValues();
    fillImageVector();
    return image_;
}

void TwoChannels::setWidths(int first_width, int second_width) {
    first_width_ = first_width;
    second_width_ = second_width;
}

void TwoChannels::fillImageVector() {
    double pixel_size = SIZE_ / resolution_;
    for(size_t i = 0; i < resolution_; ++i) {
        for(size_t j = 0; j < resolution_; ++j) {
            size_t ind = i * resolution_ + j;
            if(isChannels(i)) {
                image_[ind] = 255;    
            } else {
                image_[ind] = 0;
            }
        }
    }
}

bool TwoChannels::isChannels(double y) {
    bool is_upper_breed = 3*resolution_/4 + first_width_/2 <= y;
    bool is_middle_breed = (3*resolution_/4 - first_width_/2 > y) && (resolution_/4 + second_width_/2 < y);
    bool is_down_breed = resolution_/4 - second_width_/2 > y;
    return is_upper_breed || is_middle_breed || is_down_breed;
}

void TwoChannels::normalizeValues() {
    int half_of_resolution = resolution_/2;
    if(first_width_ >= half_of_resolution) {
        first_width_ = half_of_resolution - 1;
    }
    if(second_width_ >= half_of_resolution) {
        second_width_ = half_of_resolution - 1;
    }
    if(first_width_ <= 0) {
        first_width_ = 1;
    }
    if(second_width_ <= 0) {
        second_width_ = 1;
    }
}