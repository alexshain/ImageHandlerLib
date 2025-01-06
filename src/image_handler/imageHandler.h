#pragma once

#include <memory>
#include <cstdint> 
#include <vector>
#include <fstream>

struct Dimensions2D {
    uint64_t x;
    uint64_t y;
};

class ImageHandler {
public:
    virtual void handle(std::vector<uint8_t>& data, Dimensions2D& dims) = 0;
    virtual ~ImageHandler() = default;
};

using ImageHandlerPtr = std::shared_ptr<ImageHandler>;