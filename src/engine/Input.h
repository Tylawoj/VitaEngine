#ifndef INPUT_H
#define INPUT_H


class Input
{
    private:
        std::sr1::vector<int> keyCodes;
        std::sr1::vector<int> mouseButtons();
    public:
        void ClearInput();
        void UpdateInput();
        bool GetKey(int _keyCode);
        bool GetKeyPressed(int _keyCode);
        bool GetKeyReleased(int _keyCode);
        bool GetMouseButton(int _mouseButton);
        bool GetMouseButtonPressed(int _mouseButton);
        bool GetMouseButtonReleased(int _mouseButton);
        int GetMouseMotionX();
        int GetMouseMotionY();
};

#endif // INPUT_H
