#pragma once
#include "Event.h"

class AppTickEvent : public Event{
    public:
        AppTickEvent(){}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppUpdateEvent : public Event{
    public:
        AppUpdateEvent(){}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppRenderEvent : public Event{
    public:
        AppRenderEvent(){}

        EVENT_CLASS_TYPE(AppRenderer)
        EVENT_CLASS_CATEGORY(EventCategoryApplication);
};
