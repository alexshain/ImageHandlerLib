#pragma once 

#include "imageHandler.h"

class CutOutAreaHandler : public ImageHandler {
public:
    void handle(std::vector<uint8_t>& data, Dimensions2D& dims) override;
};