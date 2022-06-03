#include "MouseEvent.h"

MouseMovedEvent::MouseMovedEvent(Vector2 position) : position(position)
{
    x = position.x();
    y = position.y();
}

MouseScrolledEvent::MouseScrolledEvent(GLfloat xOffset, GLfloat yOffset) 
: xOffset(xOffset), yOffset(yOffset){}

MouseButtonEvent::MouseButtonEvent(int button) : button(button){}

MouseButtonPressedEvent::MouseButtonPressedEvent(int button) : MouseButtonEvent(button){}

MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button) : MouseButtonEvent(button){}
        
       
std::string MouseMovedEvent::toString() const{
    std::string msg = "MouseMovedEvent: " + std::to_string(x) + ", " + std::to_string(y);
    std::cout << 
    msg << 
    std::endl; 

    return msg;
}

std::string MouseScrolledEvent::toString() const{
    std::string msg = "MouseScrolledEvent: X offset: " + std::to_string(xOffset) + ", Y offset: " + std::to_string(yOffset);
    std::cout << 
    msg << 
    std::endl; 

    return msg;
}

std::string MouseButtonPressedEvent::toString() const{
    std::string msg = "MouseButtonPressedEvent: " + std::to_string(button); 
    std::cout << 
    msg << 
    std::endl; 

    return msg;
}

std::string MouseButtonReleasedEvent::toString() const{
    std::string msg = "MouseButtonReleasedEvent: " + std::to_string(button); 
    std::cout << 
    msg << 
    std::endl; 

    return msg;
}
