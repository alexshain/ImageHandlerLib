#pragma once 

#include "../file_operations.h"

#include <memory>
#include <cstdint> 
#include <vector>
#include <fstream>
#include <limits>  
#include <iostream> 

class StandardImage {
protected:
    std::vector<uint8_t> image_;
    int resolution_;
    const double SIZE_ = 1;

public:
    int getResolution();
    void setResolution(int resolution);

    virtual std::vector<uint8_t> getImage() = 0;
    virtual ~StandardImage() = default;

protected:
    virtual void fillImageVector() = 0;
};

using StandardImagePtr = std::shared_ptr<StandardImage>;