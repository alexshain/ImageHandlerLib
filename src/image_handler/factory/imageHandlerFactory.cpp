#include "imageHandlerFactory.h"
#include "../addWallsHandler.h"
#include "../cutOutAreaHandler.h"
#include "../removeClosedPoresHandler.h"
#include <stdexcept>

ImageHandlerPtr ImageHandlerFactory::create(const std::string &name) const {
    if(creators.find(name) != creators.end()) {
        return creators.at(name)->create();
    } else {
        return nullptr;
    }
}

ImageHandlerFactory::ImageHandlerFactory() {
    creators.emplace("-a", std::make_shared<ImageHandlerCreator<AddWallsHandler>>());
    creators.emplace("-g", std::make_shared<ImageHandlerCreator<CutOutAreaHandler>>());
    creators.emplace("-r", std::make_shared<ImageHandlerCreator<RemoveClosedPoresHandler>>());
}