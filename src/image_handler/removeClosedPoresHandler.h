#pragma once 

#include "imageHandler.h"
#include "../file_operations.h"

class RemoveClosedPoresHandler : public ImageHandler {
private: 
    std::vector<uint8_t> markers_;
    std::vector<uint8_t> unclosed_markers_;
    std::vector<uint8_t> image_;
    Dimensions2D dims_;
    const int dx_[4] = {0, 0, -1, 1}; 
    const int dy_[4] = {-1, 1, 0, 0}; 

public:
    void handle(std::vector<uint8_t>& data, Dimensions2D& dims) override;

private:
    bool isInBounds(int x, int y, int rows, int cols);
    void dfs(int x, int y, std::vector<bool>& visited, std::vector<std::pair<int, int>>& component, bool& touchesBoundary);
    void removeClosedPores(std::vector<uint8_t>& data);
};