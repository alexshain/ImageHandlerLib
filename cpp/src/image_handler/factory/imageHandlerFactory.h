#pragma once

#include <unordered_map>
#include <string>

#include "imageHandlerCreator.h"

class ImageHandlerFactory {
private:
    std::unordered_map<std::string, AbstractImageHandlerCreatorPtr> creators;
public:
    ImageHandlerFactory();
    ImageHandlerPtr create(const std::string& name) const;
};