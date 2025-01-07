#pragma once 

#include "imageHandler.h"
#include "../file_operations.h"

class AddWallsHandler : public ImageHandler {
public:
    void handle(std::vector<uint8_t>& data, Dimensions2D& dims) override;
};