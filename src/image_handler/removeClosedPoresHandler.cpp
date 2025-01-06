#include "removeClosedPoresHandler.h"
#include "../file_operations.h"

#include <iostream>

void RemoveClosedPoresHandler::handle(std::vector<uint8_t>& data, Dimensions2D& dims) {
    dims_ = dims;
    removeClosedPores(data);
}

bool RemoveClosedPoresHandler::isInBounds(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

void RemoveClosedPoresHandler::dfs(int x, int y, std::vector<bool>& visited, std::vector<std::pair<int, int>>& component, bool& touchesBoundary) {
    int rows = dims_.x;
    int cols = dims_.y;

    int ind = x * cols + y;
    visited[ind] = true;
    component.push_back({x, y});

    if (x == 0 || y == 0 || x == rows - 1 || y == cols - 1) {
        touchesBoundary = true;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx_[i];
        int ny = y + dy_[i];
        int ind = nx * cols + ny;
        if (isInBounds(nx, ny, rows, cols) && image_[ind] == 0 && !visited[ind]) {
            dfs(nx, ny, visited, component, touchesBoundary);
        }
    }
}

void RemoveClosedPoresHandler::removeClosedPores(std::vector<uint8_t>& data) {
    int rows = dims_.x;
    int cols = dims_.y;

    std::vector<bool> visited(rows * cols, false);

    image_ = data;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int ind = i * cols + j;
            if (data[ind] == 0 && !visited[ind]) {
                std::vector<std::pair<int, int>> component;
                bool touchesBoundary = false;

                dfs(i, j, visited, component, touchesBoundary);

                if (!touchesBoundary) {
                    for (auto& pixel : component) {
                        int ind = pixel.first * cols + pixel.second;
                        data[ind] = 255;
                    }
                }
            }
        }
    }
}