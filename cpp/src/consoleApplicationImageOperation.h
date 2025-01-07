#pragma once

#include "image_handler/imageHandler.h"
#include "image_handler/slice3DImage.h"
#include "standard_image_lib/factory/standardImageFactory.h" 

void callConsoleApplication();
void processRequest(std::string& str);
void callStandardImageLib();
void callImageHandler(ImageHandlerPtr im_handler);
void callSlice();
void fillSlicedLayer(const Slice3DImage& slice, std::vector<uint8_t>& layer);
void callWriteFromFileOps(std::vector<uint8_t>& data, uint64_t x_size, uint64_t y_size);
void initializeMediumData(Slice3DImage& slice);
void setWidths(StandardImagePtr& standard_image, int& first_width, int& second_width);
void callReadFromFileOps(std::vector<uint8_t>& data, Dimensions2D& dims);
void createStandardImage(const StandardImageFactory& factory, StandardImagePtr& standard_image);
int getResolution();