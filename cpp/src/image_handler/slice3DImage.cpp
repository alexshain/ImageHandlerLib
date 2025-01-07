#include "slice3DImage.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <regex>

void Slice3DImage::read3DData(const std::string& file_path) {
    std::ifstream file(file_path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file!" + file_path);
    }

    // Чтение первых 24 байт (размеры массива)
    file.read(reinterpret_cast<char*>(&dims_), sizeof(Dimensions3D));

    uint64_t total_elements = dims_.x * dims_.y * dims_.z;

    data_.resize(total_elements);
    file.read(reinterpret_cast<char*>(data_.data()), total_elements);
}

Dimensions3D Slice3DImage::getDims() const {
    return dims_;
}

std::vector<uint8_t> Slice3DImage::getSlice(int number_of_layer) const {
    if (number_of_layer > dims_.z - 1 || number_of_layer < 0) {
        throw std::runtime_error("Incorrect layer number value!");
    } 

    size_t start = dims_.x * dims_.y * number_of_layer;
    size_t end = dims_.x * dims_.y * (number_of_layer+1);

    std::vector<uint8_t> layer;
    for (size_t i = start; i != end; ++i) {
        layer.push_back(data_[i]);
    }
    return layer;
}