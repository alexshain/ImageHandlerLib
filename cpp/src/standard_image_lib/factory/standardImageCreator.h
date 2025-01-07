#pragma once

#include "../standardImage.h"

class AbstactStandardImageCreator {
public:
    virtual StandardImagePtr create() = 0;
};

template <class T>
class StandardImageCreator : public AbstactStandardImageCreator {
public:
    StandardImagePtr create() {return std::make_shared<T>();}
};

using AbstactStandardImageCreatorPtr = std::shared_ptr<AbstactStandardImageCreator>;