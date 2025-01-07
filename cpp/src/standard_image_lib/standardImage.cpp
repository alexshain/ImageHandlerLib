#include "standardImage.h"

#include <regex>
#include <iostream>

void StandardImage::setResolution(int resolution) {
    resolution_ = resolution;
    image_.resize(resolution_ * resolution_);
}

int StandardImage::getResolution() {
    return resolution_;
}