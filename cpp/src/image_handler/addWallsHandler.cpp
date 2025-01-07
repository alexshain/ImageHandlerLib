#include "addWallsHandler.h"

#include <iostream>

void AddWallsHandler::handle(std::vector<uint8_t>& data, Dimensions2D& dims) {
    dims.y += 2;
    std::vector<uint8_t> new_data(dims.x * dims.y);

    for(size_t i = 0; i < dims.x; ++i){
        new_data[i*dims.y] = 255;
        new_data[i*dims.y + dims.y - 1] = 255;
    }

    data = new_data;
}