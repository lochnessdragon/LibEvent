#pragma once

#include <vector>
#include <functional>

namespace LibEvent {
    template<typename T>
    class EventDispatcher {
    private:
        std::vector<std::function<bool(const T&)>> subscribers;

    public:
        void subscribe(bool(*subscriberFunc)(const T&)) {
            this->subscribers.push_back(std::bind(subscriberFunc, std::placeholders::_1));
        };

        void subscribe(std::function<bool(const T&)> subscriberFunc) {
            this->subscribers.push_back(subscriberFunc);
        };

        void dispatch(const T& data) {
            bool shouldContinue = true;
            size_t index = 0;

            while(shouldContinue && index < subscribers.size()) {
                auto subscriberFunc = subscribers.at(index);
                shouldContinue = subscriberFunc(data);
                index++;
            }
        };

    };
}

#define EVENT_CLASS_FUNCTION(function) [this](auto&&... arguments) -> decltype(auto) { return this->function(std::forward<decltype(arguments)>(arguments)...); }