#include "Event.h"

class KeyEvent{
    public:
    int getKeyCode() const {return keycode; }

    //event class category goes here

    protected:
    KeyEvent(int keycode);
    int keycode;
};

class KeyPressedEvent : public KeyEvent{
    public:
    KeyPressedEvent(int keycode, int repeatNum);

    private:
    int repeatCount;
};