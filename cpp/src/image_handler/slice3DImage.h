#pragma once 

#include "../file_operations.h"

#include "imageHandler.h"
#include <limits>
#include <string>
#include <cstdint> 

struct Dimensions3D {
    uint64_t x;
    uint64_t y;
    uint64_t z;
};

class Slice3DImage {
private:
    Dimensions3D dims_;
    std::vector<uint8_t> data_;

public:
    std::vector<uint8_t> getSlice(int number_of_layer) const;
    Dimensions3D getDims() const;
    void read3DData(const std::string& file_path);
};