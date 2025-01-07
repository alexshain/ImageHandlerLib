#include "file_operations.h"

#include <iostream>
#include <fstream>

namespace file_ops {
    void readData(const std::string& file_path, std::vector<uint8_t>& data, Dimensions2D& dims) {
        if(file_path == "exit") exit(0);
        std::ifstream file(file_path, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Failed to open file!" + file_path);
        }

        // Чтение первых 16 байт (размеры массива)

        file.read(reinterpret_cast<char*>(&dims.x), sizeof(size_t));
        file.read(reinterpret_cast<char*>(&dims.y), sizeof(size_t));

        uint64_t total_elements = dims.x * dims.y;

        data.resize(total_elements);
        file.read(reinterpret_cast<char*>(data.data()), total_elements);
    }

    void writeData(const std::string& file_path, std::vector<uint8_t>& data, uint64_t x_size, uint64_t y_size) {
        if(file_path == "exit") exit(0);
        std::ofstream file(file_path, std::ios::binary);

        file.write(reinterpret_cast<char*>(&x_size), sizeof(uint64_t));
        if (!file) {
            throw std::runtime_error("Failed to open file!" + file_path);
        }
        file.write(reinterpret_cast<char*>(&y_size), sizeof(uint64_t));

        file.write(reinterpret_cast<char*>(data.data()), data.size());

        file.close();
        std::cout << "Успешная запись в файл!" << std::endl;
    }
}
