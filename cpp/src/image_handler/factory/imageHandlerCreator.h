#pragma once

#include "../imageHandler.h"

class AbstractImageHandlerCreator {
public:
    virtual ImageHandlerPtr create() = 0;
};

template<class T>
class ImageHandlerCreator : public AbstractImageHandlerCreator {
public:
    ImageHandlerPtr create() override { return std::make_shared<T>(); }
};

using AbstractImageHandlerCreatorPtr = std::shared_ptr<AbstractImageHandlerCreator>;