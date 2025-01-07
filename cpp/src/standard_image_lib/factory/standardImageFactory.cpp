#include "standardImageFactory.h"
#include "../circle.h"
#include "../sinusoidalChannel.h"
#include "../twoChannels.h"

StandardImagePtr StandardImageFactory::create(const std::string& name) const {
    if(creators.find(name) != creators.end()) {
        return creators.at(name)->create();
    } else {
        throw std::runtime_error("There is no such figure!");
    }
}

StandardImageFactory::StandardImageFactory() {
    creators.emplace("c", std::make_shared<StandardImageCreator<Circle>>());
    creators.emplace("s", std::make_shared<StandardImageCreator<SinusoidalChannel>>());
    creators.emplace("t", std::make_shared<StandardImageCreator<TwoChannels>>());
}