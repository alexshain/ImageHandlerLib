#include "consoleApplicationImageOperation.h"
#include "standard_image_lib/factory/standardImageFactory.h"
#include "standard_image_lib/standardImage.h"
#include "standard_image_lib/twoChannels.h"
#include "image_handler/factory/imageHandlerFactory.h"
#include "image_handler/cutOutAreaHandler.h"

#include <iostream>

void callConsoleApplication() {
    while(true) {
        std::cout << "Enter action (-a - add walls, -g - get subregion, -s - get slice," << std::endl; 
        std::cout << " -r - remove pores, -s_i - standard images, exit - terminate the program): ";
        std::string str;
        processRequest(str);
    }
}

void processRequest(std::string& str) {
    ImageHandlerFactory factory;
    ImageHandlerPtr im_handler = nullptr;
    while(true) {
        std::cin >> str;
        if(str == "exit") {
            exit(0);
        }
        if(str == "-s_i") {
            callStandardImageLib();
            break;
        }
        if(str == "-s") {
            callSlice();
            break;
        }
        im_handler = factory.create(str);
        if(im_handler == nullptr) {
            std::getline(std::cin, str);
            std::cout << "Incorrect request entered, please try again" << std::endl;
        }
        else {
            callImageHandler(im_handler);
            break;
        }
    }
}
 
void callSlice() {
    Slice3DImage slice;
    initializeMediumData(slice);

    std::cout << "Enter the layer number (a number from 0 to " << slice.getDims().z - 1 << "): ";
    std::vector<uint8_t> layer;
    fillSlicedLayer(slice, layer);

    callWriteFromFileOps(layer, slice.getDims().x, slice.getDims().y);
}

void initializeMediumData(Slice3DImage& slice) {
    std::cout << "Enter the path to the 3D image: " << std::endl;
    std::string input_string;
    while (true) {
        std::cin >> input_string;
        try {
            slice.read3DData(input_string);
            break;
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void fillSlicedLayer(const Slice3DImage& slice, std::vector<uint8_t>& layer) {
    int number_of_layer;
    while(true) {
        std::cin >> number_of_layer;
        if(std::cin.fail()) {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            std::cout << "Input error! Please enter a valid number: ";
        } else if (number_of_layer > slice.getDims().z - 1 || number_of_layer < 0) {
            std::cout << "Incorrect layer number value!" << std::endl;
            std::cout << "Try something else!" << std::endl;
        } else {
            layer = slice.getSlice(number_of_layer);
            break;
        }
    }
}

void callImageHandler(ImageHandlerPtr im_handler) {
    if (typeid(*im_handler) == typeid(CutOutAreaHandler)) {
        std::cout << "Module under development";
    } else {
        Dimensions2D dims;
        std::vector<uint8_t> data;
        callReadFromFileOps(data, dims);
        im_handler->handle(data, dims);
        callWriteFromFileOps(data, dims.x, dims.y);
    }
}

void callStandardImageLib() {
    std::cout << "Enter the name of the library function (c - circle, s - sinusoidal_channel, t - two_channels): ";
    StandardImageFactory factory;
    StandardImagePtr standard_image;
    createStandardImage(factory, standard_image);

    std::vector<uint8_t> image;

    int resolution = getResolution();
    standard_image->setResolution(resolution);

    if (typeid(*standard_image) == typeid(TwoChannels)) {
        int first_width;
        int second_width;
        setWidths(standard_image, first_width, second_width);

        auto two_channels = std::dynamic_pointer_cast<TwoChannels>(standard_image);
        two_channels->setWidths(first_width, second_width);
        image = two_channels->getImage();
    } else {
        image = standard_image->getImage();
    }
    callWriteFromFileOps(image, resolution, resolution);
}

void createStandardImage(const StandardImageFactory& factory, StandardImagePtr& standard_image) {
    while(true) {
        std::string str;
        std::cin >> str;
        try {
            standard_image = factory.create(str);
            break;
        } catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
            std::cout << "Enter the name of the library function (c - circle, s - sinusoidal_channel, t - two_channels): ";
        }
    }
}

int getResolution() {
    int resolution;
    std::cout << "Enter the resolution (in pixels): " << std::endl;
    while(true) {
        std::cin >> resolution;
        if(std::cin.fail() || resolution < 1) {
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
            std::cout << "Input error! Please enter a valid number: ";
        } else {
            break;
        }
    }
    return resolution;
}

void callReadFromFileOps(std::vector<uint8_t>& data, Dimensions2D& dims) {
    std::cout << "Enter the path to image: " << std::endl;
        std::string input_string;
        while (true) {
            std::cin >> input_string;
            try {
                file_ops::readData(input_string, data, dims);
                break;
            } catch(const std::exception& e) {
                std::cerr << e.what() << std::endl;
                std::cout << "Enter the path to image: " << std::endl;
            }
    }
}

void callWriteFromFileOps(std::vector<uint8_t>& data, uint64_t x_size, uint64_t y_size) {
    std::string input_string;
    std::cout << "Enter the path and file name to write data to: " << std::endl;
        while (true) {
            std::cin >> input_string;
            try {
                file_ops::writeData(input_string, data, x_size, y_size);
                break;
            } catch(const std::exception& e) {
                std::cerr << e.what() << std::endl;
                std::cout << "Enter the path and file name to write data to: " << std::endl;
            }
        }
}

void setWidths(StandardImagePtr& standard_image, int& first_width, int& second_width) {
    std::cout << "The width of the first channel in pixels (" << 0 << " < width1 < " << standard_image->getResolution()/2 << "): ";
    std::cin >> first_width;
    std::cout << "The width of the second channel in pixels (" << 0 << " < width2 < " << standard_image->getResolution()/2 << "): ";
    std::cin >> second_width;
}