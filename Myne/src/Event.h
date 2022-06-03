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

//macro for event types. Returns the type and name of an event
#define EVENT_CLASS_TYPE(type)  static EventType getStaticType(){return EventType::##type;}\
                                virtual EventType getEventType() const override {return getStaticType();}\
                                virtual const char* getEventName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category)  virtual int getFlags() const override {return category;}

class Event{
    public: 
        friend class EventDispatcher;
        
        virtual EventType getEventType() const = 0;
        //debug funct to get name of event
        virtual const char* getEventName() const = 0;
        virtual int getFlags() const = 0;
        virtual std::string toString() const {return getEventName();}
    protected:
        bool handled = false;
    private:
        bool isCategory(EventCategory category);
};

class EventDispatcher{
    template<typename T>
    using eventFunct = std::function<bool(t&)>;

    public:
        EventDispatcher(Event& event);

        template<typename T>
        bool Dispatch(eventFunct<T> funct);

    private:
        Event& event;
};