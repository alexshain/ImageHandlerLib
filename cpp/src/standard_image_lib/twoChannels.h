#pragma once 

#include "standardImage.h"

class TwoChannels : public StandardImage {
private:
    int first_width_;
    int second_width_;

public:
    std::vector<uint8_t> getImage() override;
    void setWidths(int first_width, int second_width);

private:
    void fillImageVector() override;
    bool isChannels(double y); 
    void normalizeValues();
};