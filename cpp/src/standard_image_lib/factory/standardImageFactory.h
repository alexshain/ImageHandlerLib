#pragma once

#include <unordered_map>
#include <string>

#include "standardImageCreator.h"

class StandardImageFactory {
private:
    std::unordered_map<std::string, AbstactStandardImageCreatorPtr> creators;
public:
    StandardImageFactory();
    StandardImagePtr create(const std::string& name) const;
};