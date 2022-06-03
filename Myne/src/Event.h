#pragma once

#include <functional>
#include <string>

enum class EventType{
    AppUpdate, AppTick, AppRenderer,
    KeyPressed, KeyReleased, 
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

//bitfield for casting and masking events
enum EventCategory{
    None = 0,
    EventCategoryInput = 1 << 1,
    EventCategoryKeyboard = 1 << 2,
    EventCategoryMouse = 1 << 3,
    EventCategoryMouseButton = 1 << 4,    
    EventCategoryApplication = 1 << 5
};

class Event{
    public: 
        //friend class x
        virtual EventType getEventType();
        //debug funct to get name of event
        virtual const char* getEventName();
        virtual int getFlags();
        virtual std::string toString();
    protected:
        bool handled = false;
    private:
        bool isCategory(EventCategory category);
};

class EventDispatcher{

};