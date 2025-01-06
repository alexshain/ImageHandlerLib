#pragma once

#include "image_handler/imageHandler.h"

#include <vector>
#include <string>
#include <cstdint>

namespace file_ops {
    void readData(const std::string& file_path, std::vector<uint8_t>& data, Dimensions2D& dims);
    void writeData(const std::string& file_path, std::vector<uint8_t>& data, uint64_t x_size, uint64_t y_size);
}
