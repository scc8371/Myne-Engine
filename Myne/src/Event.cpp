#include "Event.h"

EventDispatcher::EventDispatcher(Event &event) : event(event){}

template<typename T>
bool EventDispatcher::Dispatch(eventFunct<T> function){

    //incorrect data type
    if(!T::GetStaticType){
        return false;
    }

    if(event.getEventType() == T::GetStaticType()){
        event.handled = function(*(T*)&event);
        return true;
    }
    return false;
}