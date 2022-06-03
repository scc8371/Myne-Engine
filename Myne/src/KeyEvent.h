#pragma once
#include "Event.h"

class KeyEvent : public Event{
    public:
    int getKeyCode() const {return keycode; }

    EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
    KeyEvent(int keycode);
    int keycode;
};

class KeyPressedEvent : public KeyEvent{
    public:
    KeyPressedEvent(int keycode, int repeatNum);
    int getRepeatCount() const {return repeatCount; }
    std::string toString() const override;

    EVENT_CLASS_TYPE(KeyPressed)
    private:
    int repeatCount;   
};

class KeyReleasedEvent : public KeyEvent{
    public:
        KeyReleasedEvent(int keycode);

        std::string toString() const override;

        EVENT_CLASS_TYPE(KeyReleased)
};