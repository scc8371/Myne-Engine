#pragma once

#include "Event.h"
#include "Vector2.h"

class MouseMovedEvent : public Event{
    public:
        MouseMovedEvent(Vector2 position);

        std::string toString() const override;

        //getters and setters for x and y values
        GLfloat getX() const {return x;}
        GLfloat getY() const {return y;}

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        Vector2 position;     
        float x, y;  
};

class MouseScrolledEvent : public Event{
    public:
        MouseScrolledEvent(GLfloat xOffset, GLfloat yOffset);
        std::string toString() const override;

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
    float xOffset, yOffset;
};

class MouseButtonEvent : public Event{
    public:
        int getButton() const {return button;}
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    protected:
        MouseButtonEvent(int button);
        int button;
};

class MouseButtonPressedEvent : public MouseButtonEvent{
    public:
        MouseButtonPressedEvent(int button);

        std::string toString() const override;

        EVENT_CLASS_TYPE(MouseButtonPressed)  
};

class MouseButtonReleasedEvent : public MouseButtonEvent{
    public: 
        MouseButtonReleasedEvent(int button);
        std::string toString() const override;

        EVENT_CLASS_TYPE(MouseButtonReleased)
};