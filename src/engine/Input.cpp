/** @file Input.cpp
 *  @brief Implementation of functions for the Input class.
 */

#include "Input.h"
#include "Core.h"
#include <SDL2/SDL.h>

namespace vita
{
    Input::Input()
    {
        /// Initialize the vectors.
        m_keyCodes = std::sr1::vector<bool>(112, false);
        m_keyCodesPressed = std::sr1::vector<bool>(112, false);
        m_keyCodesReleased = std::sr1::vector<bool>(112, false);
        m_mouseButtons = std::sr1::vector<bool>(5, false);
        m_mouseButtonsPressed = std::sr1::vector<bool>(5, false);
        m_mouseButtonsReleased = std::sr1::vector<bool>(5, false);
        /// Set the initial mouse motion to 0.
        m_mouseMotionX = 0;
        m_mouseMotionY = 0;
        m_event = { 0 };
    }

    void Input::ClearInput()
    {
        /// Set all keys and mouse buttons pressed or released to false.
        for (std::sr1::vector<bool>::iterator keyCodePressedIterator = m_keyCodesPressed.begin(); keyCodePressedIterator != m_keyCodesPressed.end(); keyCodePressedIterator++)
        {
            (*keyCodePressedIterator) = false;
        }

        for (std::sr1::vector<bool>::iterator keyCodeReleasedIterator = m_keyCodesReleased.begin(); keyCodeReleasedIterator != m_keyCodesReleased.end(); keyCodeReleasedIterator++)
        {
            (*keyCodeReleasedIterator) = false;
        }

        for (std::sr1::vector<bool>::iterator mouseButtonPressedIterator = m_mouseButtonsPressed.begin(); mouseButtonPressedIterator != m_mouseButtonsPressed.end(); mouseButtonPressedIterator++)
        {
            (*mouseButtonPressedIterator) = false;
        }

        for (std::sr1::vector<bool>::iterator mouseButtonReleasedIterator = m_mouseButtonsReleased.begin(); mouseButtonReleasedIterator != m_mouseButtonsReleased.end(); mouseButtonReleasedIterator++)
        {
            (*mouseButtonReleasedIterator) = false;
        }

        /// Set the mouse motion to 0.
        m_mouseMotionX = 0;
        m_mouseMotionY = 0;
    }

    bool Input::GetKey(int _keyCode)
    {
        return m_keyCodes.at(_keyCode);
    }

    bool Input::GetKeyPressed(int _keyCode)
    {
        return m_keyCodesPressed.at(_keyCode);
    }

    bool Input::GetKeyReleased(int _keyCode)
    {
        return m_keyCodesReleased.at(_keyCode);
    }

    bool Input::GetMouseButton(int _mouseButton)
    {
        return m_mouseButtons.at(_mouseButton);
    }

    bool Input::GetMouseButtonPressed(int _mouseButton)
    {
        return m_mouseButtonsPressed.at(_mouseButton);
    }

    bool Input::GetMouseButtonReleased(int _mouseButton)
    {
        return m_mouseButtonsReleased.at(_mouseButton);
    }

    int Input::GetMouseMotionX()
    {
        return m_mouseMotionX;
    }

    int Input::GetMouseMotionY()
    {
        return m_mouseMotionY;
    }

    void Input::UpdateInput()
    {
        while (SDL_PollEvent(&m_event))
        {
            /// Check the event type.
            switch (m_event.type)
            {
                /// If the user quits the window, this means that the core must stop.
                case SDL_QUIT:
                    m_core.lock()->Stop();
                    break;
                /// Check for key presses.
                case SDL_KEYDOWN:
                    switch(m_event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            m_keyCodes.at(0) = true;
                            m_keyCodesPressed.at(0) = true;
                            break;
                        case SDLK_F1:
                            m_keyCodes.at(1) = true;
                            m_keyCodesPressed.at(1) = true;
                            break;
                        case SDLK_F2:
                            m_keyCodes.at(2) = true;
                            m_keyCodesPressed.at(2) = true;
                            break;
                        case SDLK_F3:
                            m_keyCodes.at(3) = true;
                            m_keyCodesPressed.at(3) = true;
                            break;
                        case SDLK_F4:
                            m_keyCodes.at(4) = true;
                            m_keyCodesPressed.at(4) = true;
                            break;
                        case SDLK_F5:
                            m_keyCodes.at(5) = true;
                            m_keyCodesPressed.at(5) = true;
                            break;
                        case SDLK_F6:
                            m_keyCodes.at(6) = true;
                            m_keyCodesPressed.at(6) = true;
                            break;
                        case SDLK_F7:
                            m_keyCodes.at(7) = true;
                            m_keyCodesPressed.at(7) = true;
                            break;
                        case SDLK_F8:
                            m_keyCodes.at(8) = true;
                            m_keyCodesPressed.at(8) = true;
                            break;
                        case SDLK_F9:
                            m_keyCodes.at(9) = true;
                            m_keyCodesPressed.at(9) = true;
                            break;
                        case SDLK_F10:
                            m_keyCodes.at(10) = true;
                            m_keyCodesPressed.at(10) = true;
                            break;
                        case SDLK_F11:
                            m_keyCodes.at(11) = true;
                            m_keyCodesPressed.at(11) = true;
                            break;
                        case SDLK_F12:
                            m_keyCodes.at(12) = true;
                            m_keyCodesPressed.at(12) = true;
                            break;
                        case SDLK_BACKQUOTE:
                            m_keyCodes.at(13) = true;
                            m_keyCodesPressed.at(13) = true;
                            break;
                        case SDLK_EXCLAIM:
                            m_keyCodes.at(14) = true;
                            m_keyCodesPressed.at(14) = true;
                            break;
                        case SDLK_AT:
                            m_keyCodes.at(15) = true;
                            m_keyCodesPressed.at(15) = true;
                            break;
                        case SDLK_HASH:
                            m_keyCodes.at(16) = true;
                            m_keyCodesPressed.at(16) = true;
                            break;
                        case SDLK_DOLLAR:
                            m_keyCodes.at(17) = true;
                            m_keyCodesPressed.at(17) = true;
                            break;
                        case SDLK_PERCENT:
                            m_keyCodes.at(18) = true;
                            m_keyCodesPressed.at(18) = true;
                            break;
                        case SDLK_CARET:
                            m_keyCodes.at(19) = true;
                            m_keyCodesPressed.at(19) = true;
                            break;
                        case SDLK_AMPERSAND:
                            m_keyCodes.at(20) = true;
                            m_keyCodesPressed.at(20) = true;
                            break;
                        case SDLK_ASTERISK:
                            m_keyCodes.at(21) = true;
                            m_keyCodesPressed.at(21) = true;
                            break;
                        case SDLK_LEFTPAREN:
                            m_keyCodes.at(22) = true;
                            m_keyCodesPressed.at(22) = true;
                            break;
                        case SDLK_RIGHTPAREN:
                            m_keyCodes.at(23) = true;
                            m_keyCodesPressed.at(23) = true;
                            break;
                        case SDLK_UNDERSCORE:
                            m_keyCodes.at(24) = true;
                            m_keyCodesPressed.at(24) = true;
                            break;
                        case SDLK_EQUALS:
                            m_keyCodes.at(25) = true;
                            m_keyCodesPressed.at(25) = true;
                            break;
                        case SDLK_BACKSPACE:
                            m_keyCodes.at(26) = true;
                            m_keyCodesPressed.at(26) = true;
                            break;
                        case SDLK_1:
                            m_keyCodes.at(27) = true;
                            m_keyCodesPressed.at(27) = true;
                            break;
                        case SDLK_2:
                            m_keyCodes.at(28) = true;
                            m_keyCodesPressed.at(28) = true;
                            break;
                        case SDLK_3:
                            m_keyCodes.at(29) = true;
                            m_keyCodesPressed.at(29) = true;
                            break;
                        case SDLK_4:
                            m_keyCodes.at(30) = true;
                            m_keyCodesPressed.at(30) = true;
                            break;
                        case SDLK_5:
                            m_keyCodes.at(31) = true;
                            m_keyCodesPressed.at(31) = true;
                            break;
                        case SDLK_6:
                            m_keyCodes.at(32) = true;
                            m_keyCodesPressed.at(32) = true;
                            break;
                        case SDLK_7:
                            m_keyCodes.at(33) = true;
                            m_keyCodesPressed.at(33) = true;
                            break;
                        case SDLK_8:
                            m_keyCodes.at(34) = true;
                            m_keyCodesPressed.at(34) = true;
                            break;
                        case SDLK_9:
                            m_keyCodes.at(35) = true;
                            m_keyCodesPressed.at(35) = true;
                            break;
                        case SDLK_0:
                            m_keyCodes.at(36) = true;
                            m_keyCodesPressed.at(36) = true;
                            break;
                        case SDLK_TAB:
                            m_keyCodes.at(37) = true;
                            m_keyCodesPressed.at(37) = true;
                            break;
                        case SDLK_q:
                            m_keyCodes.at(38) = true;
                            m_keyCodesPressed.at(38) = true;
                            break;
                        case SDLK_w:
                            m_keyCodes.at(39) = true;
                            m_keyCodesPressed.at(39) = true;
                            break;
                        case SDLK_e:
                            m_keyCodes.at(40) = true;
                            m_keyCodesPressed.at(40) = true;
                            break;
                        case SDLK_r:
                            m_keyCodes.at(41) = true;
                            m_keyCodesPressed.at(41) = true;
                            break;
                        case SDLK_t:
                            m_keyCodes.at(42) = true;
                            m_keyCodesPressed.at(42) = true;
                            break;
                        case SDLK_y:
                            m_keyCodes.at(43) = true;
                            m_keyCodesPressed.at(43) = true;
                            break;
                        case SDLK_u:
                            m_keyCodes.at(44) = true;
                            m_keyCodesPressed.at(44) = true;
                            break;
                        case SDLK_i:
                            m_keyCodes.at(45) = true;
                            m_keyCodesPressed.at(45) = true;
                            break;
                        case SDLK_o:
                            m_keyCodes.at(46) = true;
                            m_keyCodesPressed.at(46) = true;
                            break;
                        case SDLK_p:
                            m_keyCodes.at(47) = true;
                            m_keyCodesPressed.at(47) = true;
                            break;
                        case SDLK_LEFTBRACKET:
                            m_keyCodes.at(48) = true;
                            m_keyCodesPressed.at(48) = true;
                            break;
                        case SDLK_RIGHTBRACKET:
                            m_keyCodes.at(49) = true;
                            m_keyCodesPressed.at(49) = true;
                            break;
                        case SDLK_BACKSLASH:
                            m_keyCodes.at(50) = true;
                            m_keyCodesPressed.at(50) = true;
                            break;
                        case SDLK_CAPSLOCK:
                            m_keyCodes.at(51) = true;
                            m_keyCodesPressed.at(51) = true;
                            break;
                        case SDLK_a:
                            m_keyCodes.at(52) = true;
                            m_keyCodesPressed.at(52) = true;
                            break;
                        case SDLK_s:
                            m_keyCodes.at(53) = true;
                            m_keyCodesPressed.at(53) = true;
                            break;
                        case SDLK_d:
                            m_keyCodes.at(54) = true;
                            m_keyCodesPressed.at(54) = true;
                            break;
                        case SDLK_f:
                            m_keyCodes.at(55) = true;
                            m_keyCodesPressed.at(55) = true;
                            break;
                        case SDLK_g:
                            m_keyCodes.at(56) = true;
                            m_keyCodesPressed.at(56) = true;
                            break;
                        case SDLK_h:
                            m_keyCodes.at(57) = true;
                            m_keyCodesPressed.at(57) = true;
                            break;
                        case SDLK_j:
                            m_keyCodes.at(58) = true;
                            m_keyCodesPressed.at(58) = true;
                            break;
                        case SDLK_k:
                            m_keyCodes.at(59) = true;
                            m_keyCodesPressed.at(59) = true;
                            break;
                        case SDLK_l:
                            m_keyCodes.at(60) = true;
                            m_keyCodesPressed.at(60) = true;
                            break;
                        case SDLK_SEMICOLON:
                            m_keyCodes.at(61) = true;
                            m_keyCodesPressed.at(61) = true;
                            break;
                        case SDLK_COLON:
                            m_keyCodes.at(62) = true;
                            m_keyCodesPressed.at(62) = true;
                            break;
                        case SDLK_QUOTE:
                            m_keyCodes.at(63) = true;
                            m_keyCodesPressed.at(63) = true;
                            break;
                        case SDLK_QUOTEDBL:
                            m_keyCodes.at(64) = true;
                            m_keyCodesPressed.at(64) = true;
                            break;
                        case SDLK_RETURN:
                            m_keyCodes.at(65) = true;
                            m_keyCodesPressed.at(65) = true;
                            break;
                        case SDLK_LSHIFT:
                            m_keyCodes.at(66) = true;
                            m_keyCodesPressed.at(66) = true;
                            break;
                        case SDLK_z:
                            m_keyCodes.at(67) = true;
                            m_keyCodesPressed.at(67) = true;
                            break;
                        case SDLK_x:
                            m_keyCodes.at(68) = true;
                            m_keyCodesPressed.at(68) = true;
                            break;
                        case SDLK_c:
                            m_keyCodes.at(69) = true;
                            m_keyCodesPressed.at(69) = true;
                            break;
                        case SDLK_v:
                            m_keyCodes.at(70) = true;
                            m_keyCodesPressed.at(70) = true;
                            break;
                        case SDLK_b:
                            m_keyCodes.at(71) = true;
                            m_keyCodesPressed.at(71) = true;
                            break;
                        case SDLK_n:
                            m_keyCodes.at(72) = true;
                            m_keyCodesPressed.at(72) = true;
                            break;
                        case SDLK_m:
                            m_keyCodes.at(73) = true;
                            m_keyCodesPressed.at(73) = true;
                            break;
                        case SDLK_COMMA:
                            m_keyCodes.at(74) = true;
                            m_keyCodesPressed.at(74) = true;
                            break;
                        case SDLK_LESS:
                            m_keyCodes.at(75) = true;
                            m_keyCodesPressed.at(75) = true;
                            break;
                        case SDLK_PERIOD:
                            m_keyCodes.at(76) = true;
                            m_keyCodesPressed.at(76) = true;
                            break;
                        case SDLK_GREATER:
                            m_keyCodes.at(77) = true;
                            m_keyCodesPressed.at(77) = true;
                            break;
                        case SDLK_SLASH:
                            m_keyCodes.at(78) = true;
                            m_keyCodesPressed.at(78) = true;
                            break;
                        case SDLK_QUESTION:
                            m_keyCodes.at(79) = true;
                            m_keyCodesPressed.at(79) = true;
                            break;
                        case SDLK_RSHIFT:
                            m_keyCodes.at(80) = true;
                            m_keyCodesPressed.at(80) = true;
                            break;
                        case SDLK_UP:
                            m_keyCodes.at(81) = true;
                            m_keyCodesPressed.at(81) = true;
                            break;
                        case SDLK_LCTRL:
                            m_keyCodes.at(82) = true;
                            m_keyCodesPressed.at(82) = true;
                            break;
                        case SDLK_LALT:
                            m_keyCodes.at(83) = true;
                            m_keyCodesPressed.at(83) = true;
                            break;
                        case SDLK_SPACE:
                            m_keyCodes.at(84) = true;
                            m_keyCodesPressed.at(84) = true;
                            break;
                        case SDLK_RALT:
                            m_keyCodes.at(85) = true;
                            m_keyCodesPressed.at(85) = true;
                            break;
                        case SDLK_RCTRL:
                            m_keyCodes.at(86) = true;
                            m_keyCodesPressed.at(86) = true;
                            break;
                        case SDLK_LEFT:
                            m_keyCodes.at(87) = true;
                            m_keyCodesPressed.at(87) = true;
                            break;
                        case SDLK_DOWN:
                            m_keyCodes.at(88) = true;
                            m_keyCodesPressed.at(88) = true;
                            break;
                        case SDLK_RIGHT:
                            m_keyCodes.at(89) = true;
                            m_keyCodesPressed.at(89) = true;
                            break;
                        case SDLK_PAUSE:
                            m_keyCodes.at(90) = true;
                            m_keyCodesPressed.at(90) = true;
                            break;
                        case SDLK_INSERT:
                            m_keyCodes.at(91) = true;
                            m_keyCodesPressed.at(91) = true;
                            break;
                        case SDLK_HOME:
                            m_keyCodes.at(92) = true;
                            m_keyCodesPressed.at(92) = true;
                            break;
                        case SDLK_PAGEUP:
                            m_keyCodes.at(93) = true;
                            m_keyCodesPressed.at(93) = true;
                            break;
                        case SDLK_DELETE:
                            m_keyCodes.at(94) = true;
                            m_keyCodesPressed.at(94) = true;
                            break;
                        case SDLK_END:
                            m_keyCodes.at(95) = true;
                            m_keyCodesPressed.at(95) = true;
                            break;
                        case SDLK_PAGEDOWN:
                            m_keyCodes.at(96) = true;
                            m_keyCodesPressed.at(96) = true;
                            break;
                        case SDLK_KP_DIVIDE:
                            m_keyCodes.at(97) = true;
                            m_keyCodesPressed.at(97) = true;
                            break;
                        case SDLK_KP_MULTIPLY:
                            m_keyCodes.at(98) = true;
                            m_keyCodesPressed.at(98) = true;
                            break;
                        case SDLK_KP_MINUS:
                            m_keyCodes.at(99) = true;
                            m_keyCodesPressed.at(99) = true;
                            break;
                        case SDLK_KP_7:
                            m_keyCodes.at(100) = true;
                            m_keyCodesPressed.at(100) = true;
                            break;
                        case SDLK_KP_8:
                            m_keyCodes.at(101) = true;
                            m_keyCodesPressed.at(101) = true;
                            break;
                        case SDLK_KP_9:
                            m_keyCodes.at(102) = true;
                            m_keyCodesPressed.at(102) = true;
                            break;
                        case SDLK_KP_4:
                            m_keyCodes.at(103) = true;
                            m_keyCodesPressed.at(103) = true;
                            break;
                        case SDLK_KP_5:
                            m_keyCodes.at(104) = true;
                            m_keyCodesPressed.at(104) = true;
                            break;
                        case SDLK_KP_6:
                            m_keyCodes.at(105) = true;
                            m_keyCodesPressed.at(105) = true;
                            break;
                        case SDLK_KP_1:
                            m_keyCodes.at(106) = true;
                            m_keyCodesPressed.at(106) = true;
                            break;
                        case SDLK_KP_2:
                            m_keyCodes.at(107) = true;
                            m_keyCodesPressed.at(107) = true;
                            break;
                        case SDLK_KP_3:
                            m_keyCodes.at(108) = true;
                            m_keyCodesPressed.at(108) = true;
                            break;
                        case SDLK_KP_0:
                            m_keyCodes.at(109) = true;
                            m_keyCodesPressed.at(109) = true;
                            break;
                        case SDLK_KP_PLUS:
                            m_keyCodes.at(110) = true;
                            m_keyCodesPressed.at(110) = true;
                            break;
                        case SDLK_KP_ENTER:
                            m_keyCodes.at(111) = true;
                            m_keyCodesPressed.at(111) = true;
                            break;
                        default:
                            break;
                    }
                    break;
                /// Check for key releases.
                case SDL_KEYUP:
                    switch(m_event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            m_keyCodes.at(0) = false;
                            m_keyCodesReleased.at(0) = true;
                            break;
                        case SDLK_F1:
                            m_keyCodes.at(1) = false;
                            m_keyCodesReleased.at(1) = true;
                            break;
                        case SDLK_F2:
                            m_keyCodes.at(2) = false;
                            m_keyCodesReleased.at(2) = true;
                            break;
                        case SDLK_F3:
                            m_keyCodes.at(3) = false;
                            m_keyCodesReleased.at(3) = true;
                            break;
                        case SDLK_F4:
                            m_keyCodes.at(4) = false;
                            m_keyCodesReleased.at(4) = true;
                            break;
                        case SDLK_F5:
                            m_keyCodes.at(5) = false;
                            m_keyCodesReleased.at(5) = true;
                            break;
                        case SDLK_F6:
                            m_keyCodes.at(6) = false;
                            m_keyCodesReleased.at(6) = true;
                            break;
                        case SDLK_F7:
                            m_keyCodes.at(7) = false;
                            m_keyCodesReleased.at(7) = true;
                            break;
                        case SDLK_F8:
                            m_keyCodes.at(8) = false;
                            m_keyCodesReleased.at(8) = true;
                            break;
                        case SDLK_F9:
                            m_keyCodes.at(9) = false;
                            m_keyCodesReleased.at(9) = true;
                            break;
                        case SDLK_F10:
                            m_keyCodes.at(10) = false;
                            m_keyCodesReleased.at(10) = true;
                            break;
                        case SDLK_F11:
                            m_keyCodes.at(11) = false;
                            m_keyCodesReleased.at(11) = true;
                            break;
                        case SDLK_F12:
                            m_keyCodes.at(12) = false;
                            m_keyCodesReleased.at(12) = true;
                            break;
                        case SDLK_BACKQUOTE:
                            m_keyCodes.at(13) = false;
                            m_keyCodesReleased.at(13) = true;
                            break;
                        case SDLK_EXCLAIM:
                            m_keyCodes.at(14) = false;
                            m_keyCodesReleased.at(14) = true;
                            break;
                        case SDLK_AT:
                            m_keyCodes.at(15) = false;
                            m_keyCodesReleased.at(15) = true;
                            break;
                        case SDLK_HASH:
                            m_keyCodes.at(16) = false;
                            m_keyCodesReleased.at(16) = true;
                            break;
                        case SDLK_DOLLAR:
                            m_keyCodes.at(17) = false;
                            m_keyCodesReleased.at(17) = true;
                            break;
                        case SDLK_PERCENT:
                            m_keyCodes.at(18) = false;
                            m_keyCodesReleased.at(18) = true;
                            break;
                        case SDLK_CARET:
                            m_keyCodes.at(19) = false;
                            m_keyCodesReleased.at(19) = true;
                            break;
                        case SDLK_AMPERSAND:
                            m_keyCodes.at(20) = false;
                            m_keyCodesReleased.at(20) = true;
                            break;
                        case SDLK_ASTERISK:
                            m_keyCodes.at(21) = false;
                            m_keyCodesReleased.at(21) = true;
                            break;
                        case SDLK_LEFTPAREN:
                            m_keyCodes.at(22) = false;
                            m_keyCodesReleased.at(22) = true;
                            break;
                        case SDLK_RIGHTPAREN:
                            m_keyCodes.at(23) = false;
                            m_keyCodesReleased.at(23) = true;
                            break;
                        case SDLK_UNDERSCORE:
                            m_keyCodes.at(24) = false;
                            m_keyCodesReleased.at(24) = true;
                            break;
                        case SDLK_EQUALS:
                            m_keyCodes.at(25) = false;
                            m_keyCodesReleased.at(25) = true;
                            break;
                        case SDLK_BACKSPACE:
                            m_keyCodes.at(26) = false;
                            m_keyCodesReleased.at(26) = true;
                            break;
                        case SDLK_1:
                            m_keyCodes.at(27) = false;
                            m_keyCodesReleased.at(27) = true;
                            break;
                        case SDLK_2:
                            m_keyCodes.at(28) = false;
                            m_keyCodesReleased.at(28) = true;
                            break;
                        case SDLK_3:
                            m_keyCodes.at(29) = false;
                            m_keyCodesReleased.at(29) = true;
                            break;
                        case SDLK_4:
                            m_keyCodes.at(30) = false;
                            m_keyCodesReleased.at(30) = true;
                            break;
                        case SDLK_5:
                            m_keyCodes.at(31) = false;
                            m_keyCodesReleased.at(31) = true;
                            break;
                        case SDLK_6:
                            m_keyCodes.at(32) = false;
                            m_keyCodesReleased.at(32) = true;
                            break;
                        case SDLK_7:
                            m_keyCodes.at(33) = false;
                            m_keyCodesReleased.at(33) = true;
                            break;
                        case SDLK_8:
                            m_keyCodes.at(34) = false;
                            m_keyCodesReleased.at(34) = true;
                            break;
                        case SDLK_9:
                            m_keyCodes.at(35) = false;
                            m_keyCodesReleased.at(35) = true;
                            break;
                        case SDLK_0:
                            m_keyCodes.at(36) = false;
                            m_keyCodesReleased.at(36) = true;
                            break;
                        case SDLK_TAB:
                            m_keyCodes.at(37) = false;
                            m_keyCodesReleased.at(37) = true;
                            break;
                        case SDLK_q:
                            m_keyCodes.at(38) = false;
                            m_keyCodesReleased.at(38) = true;
                            break;
                        case SDLK_w:
                            m_keyCodes.at(39) = false;
                            m_keyCodesReleased.at(39) = true;
                            break;
                        case SDLK_e:
                            m_keyCodes.at(40) = false;
                            m_keyCodesReleased.at(40) = true;
                            break;
                        case SDLK_r:
                            m_keyCodes.at(41) = false;
                            m_keyCodesReleased.at(41) = true;
                            break;
                        case SDLK_t:
                            m_keyCodes.at(42) = false;
                            m_keyCodesReleased.at(42) = true;
                            break;
                        case SDLK_y:
                            m_keyCodes.at(43) = false;
                            m_keyCodesReleased.at(43) = true;
                            break;
                        case SDLK_u:
                            m_keyCodes.at(44) = false;
                            m_keyCodesReleased.at(44) = true;
                            break;
                        case SDLK_i:
                            m_keyCodes.at(45) = false;
                            m_keyCodesReleased.at(45) = true;
                            break;
                        case SDLK_o:
                            m_keyCodes.at(46) = false;
                            m_keyCodesReleased.at(46) = true;
                            break;
                        case SDLK_p:
                            m_keyCodes.at(47) = false;
                            m_keyCodesReleased.at(47) = true;
                            break;
                        case SDLK_LEFTBRACKET:
                            m_keyCodes.at(48) = false;
                            m_keyCodesReleased.at(48) = true;
                            break;
                        case SDLK_RIGHTBRACKET:
                            m_keyCodes.at(49) = false;
                            m_keyCodesReleased.at(49) = true;
                            break;
                        case SDLK_BACKSLASH:
                            m_keyCodes.at(50) = false;
                            m_keyCodesReleased.at(50) = true;
                            break;
                        case SDLK_CAPSLOCK:
                            m_keyCodes.at(51) = false;
                            m_keyCodesReleased.at(51) = true;
                            break;
                        case SDLK_a:
                            m_keyCodes.at(52) = false;
                            m_keyCodesReleased.at(52) = true;
                            break;
                        case SDLK_s:
                            m_keyCodes.at(53) = false;
                            m_keyCodesReleased.at(53) = true;
                            break;
                        case SDLK_d:
                            m_keyCodes.at(54) = false;
                            m_keyCodesReleased.at(54) = true;
                            break;
                        case SDLK_f:
                            m_keyCodes.at(55) = false;
                            m_keyCodesReleased.at(55) = true;
                            break;
                        case SDLK_g:
                            m_keyCodes.at(56) = false;
                            m_keyCodesReleased.at(56) = true;
                            break;
                        case SDLK_h:
                            m_keyCodes.at(57) = false;
                            m_keyCodesReleased.at(57) = true;
                            break;
                        case SDLK_j:
                            m_keyCodes.at(58) = false;
                            m_keyCodesReleased.at(58) = true;
                            break;
                        case SDLK_k:
                            m_keyCodes.at(59) = false;
                            m_keyCodesReleased.at(59) = true;
                            break;
                        case SDLK_l:
                            m_keyCodes.at(60) = false;
                            m_keyCodesReleased.at(60) = true;
                            break;
                        case SDLK_SEMICOLON:
                            m_keyCodes.at(61) = false;
                            m_keyCodesReleased.at(61) = true;
                            break;
                        case SDLK_COLON:
                            m_keyCodes.at(62) = false;
                            m_keyCodesReleased.at(62) = true;
                            break;
                        case SDLK_QUOTE:
                            m_keyCodes.at(63) = false;
                            m_keyCodesReleased.at(63) = true;
                            break;
                        case SDLK_QUOTEDBL:
                            m_keyCodes.at(64) = false;
                            m_keyCodesReleased.at(64) = true;
                            break;
                        case SDLK_RETURN:
                            m_keyCodes.at(65) = false;
                            m_keyCodesReleased.at(65) = true;
                            break;
                        case SDLK_LSHIFT:
                            m_keyCodes.at(66) = false;
                            m_keyCodesReleased.at(66) = true;
                            break;
                        case SDLK_z:
                            m_keyCodes.at(67) = false;
                            m_keyCodesReleased.at(67) = true;
                            break;
                        case SDLK_x:
                            m_keyCodes.at(68) = false;
                            m_keyCodesReleased.at(68) = true;
                            break;
                        case SDLK_c:
                            m_keyCodes.at(69) = false;
                            m_keyCodesReleased.at(69) = true;
                            break;
                        case SDLK_v:
                            m_keyCodes.at(70) = false;
                            m_keyCodesReleased.at(70) = true;
                            break;
                        case SDLK_b:
                            m_keyCodes.at(71) = false;
                            m_keyCodesReleased.at(71) = true;
                            break;
                        case SDLK_n:
                            m_keyCodes.at(72) = false;
                            m_keyCodesReleased.at(72) = true;
                            break;
                        case SDLK_m:
                            m_keyCodes.at(73) = false;
                            m_keyCodesReleased.at(73) = true;
                            break;
                        case SDLK_COMMA:
                            m_keyCodes.at(74) = false;
                            m_keyCodesReleased.at(74) = true;
                            break;
                        case SDLK_LESS:
                            m_keyCodes.at(75) = false;
                            m_keyCodesReleased.at(75) = true;
                            break;
                        case SDLK_PERIOD:
                            m_keyCodes.at(76) = false;
                            m_keyCodesReleased.at(76) = true;
                            break;
                        case SDLK_GREATER:
                            m_keyCodes.at(77) = false;
                            m_keyCodesReleased.at(77) = true;
                            break;
                        case SDLK_SLASH:
                            m_keyCodes.at(78) = false;
                            m_keyCodesReleased.at(78) = true;
                            break;
                        case SDLK_QUESTION:
                            m_keyCodes.at(79) = false;
                            m_keyCodesReleased.at(79) = true;
                            break;
                        case SDLK_RSHIFT:
                            m_keyCodes.at(80) = false;
                            m_keyCodesReleased.at(80) = true;
                            break;
                        case SDLK_UP:
                            m_keyCodes.at(81) = false;
                            m_keyCodesReleased.at(81) = true;
                            break;
                        case SDLK_LCTRL:
                            m_keyCodes.at(82) = false;
                            m_keyCodesReleased.at(82) = true;
                            break;
                        case SDLK_LALT:
                            m_keyCodes.at(83) = false;
                            m_keyCodesReleased.at(83) = true;
                            break;
                        case SDLK_SPACE:
                            m_keyCodes.at(84) = false;
                            m_keyCodesReleased.at(84) = true;
                            break;
                        case SDLK_RALT:
                            m_keyCodes.at(85) = false;
                            m_keyCodesReleased.at(85) = true;
                            break;
                        case SDLK_RCTRL:
                            m_keyCodes.at(86) = false;
                            m_keyCodesReleased.at(86) = true;
                            break;
                        case SDLK_LEFT:
                            m_keyCodes.at(87) = false;
                            m_keyCodesReleased.at(87) = true;
                            break;
                        case SDLK_DOWN:
                            m_keyCodes.at(88) = false;
                            m_keyCodesReleased.at(88) = true;
                            break;
                        case SDLK_RIGHT:
                            m_keyCodes.at(89) = false;
                            m_keyCodesReleased.at(89) = true;
                            break;
                        case SDLK_PAUSE:
                            m_keyCodes.at(90) = false;
                            m_keyCodesReleased.at(90) = true;
                            break;
                        case SDLK_INSERT:
                            m_keyCodes.at(91) = false;
                            m_keyCodesReleased.at(91) = true;
                            break;
                        case SDLK_HOME:
                            m_keyCodes.at(92) = false;
                            m_keyCodesReleased.at(92) = true;
                            break;
                        case SDLK_PAGEUP:
                            m_keyCodes.at(93) = false;
                            m_keyCodesReleased.at(93) = true;
                            break;
                        case SDLK_DELETE:
                            m_keyCodes.at(94) = false;
                            m_keyCodesReleased.at(94) = true;
                            break;
                        case SDLK_END:
                            m_keyCodes.at(95) = false;
                            m_keyCodesReleased.at(95) = true;
                            break;
                        case SDLK_PAGEDOWN:
                            m_keyCodes.at(96) = false;
                            m_keyCodesReleased.at(96) = true;
                            break;
                        case SDLK_KP_DIVIDE:
                            m_keyCodes.at(97) = false;
                            m_keyCodesReleased.at(97) = true;
                            break;
                        case SDLK_KP_MULTIPLY:
                            m_keyCodes.at(98) = false;
                            m_keyCodesReleased.at(98) = true;
                            break;
                        case SDLK_KP_MINUS:
                            m_keyCodes.at(99) = false;
                            m_keyCodesReleased.at(99) = true;
                            break;
                        case SDLK_KP_7:
                            m_keyCodes.at(100) = false;
                            m_keyCodesReleased.at(100) = true;
                            break;
                        case SDLK_KP_8:
                            m_keyCodes.at(101) = false;
                            m_keyCodesReleased.at(101) = true;
                            break;
                        case SDLK_KP_9:
                            m_keyCodes.at(102) = false;
                            m_keyCodesReleased.at(102) = true;
                            break;
                        case SDLK_KP_4:
                            m_keyCodes.at(103) = false;
                            m_keyCodesReleased.at(103) = true;
                            break;
                        case SDLK_KP_5:
                            m_keyCodes.at(104) = false;
                            m_keyCodesReleased.at(104) = true;
                            break;
                        case SDLK_KP_6:
                            m_keyCodes.at(105) = false;
                            m_keyCodesReleased.at(105) = true;
                            break;
                        case SDLK_KP_1:
                            m_keyCodes.at(106) = false;
                            m_keyCodesReleased.at(106) = true;
                            break;
                        case SDLK_KP_2:
                            m_keyCodes.at(107) = false;
                            m_keyCodesReleased.at(107) = true;
                            break;
                        case SDLK_KP_3:
                            m_keyCodes.at(108) = false;
                            m_keyCodesReleased.at(108) = true;
                            break;
                        case SDLK_KP_0:
                            m_keyCodes.at(109) = false;
                            m_keyCodesReleased.at(109) = true;
                            break;
                        case SDLK_KP_PLUS:
                            m_keyCodes.at(110) = false;
                            m_keyCodesReleased.at(110) = true;
                            break;
                        case SDLK_KP_ENTER:
                            m_keyCodes.at(111) = false;
                            m_keyCodesReleased.at(111) = true;
                            break;
                        default:
                            break;
                    }
                    break;
                /// Check for mouse button presses.
                case SDL_MOUSEBUTTONDOWN:
                    switch(m_event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            m_mouseButtons.at(0) = true;
                            m_mouseButtonsPressed.at(0) = true;
                            break;
                        case SDL_BUTTON_RIGHT:
                            m_mouseButtons.at(1) = true;
                            m_mouseButtonsPressed.at(1) = true;
                            break;
                        case SDL_BUTTON_MIDDLE:
                            m_mouseButtons.at(2) = true;
                            m_mouseButtonsPressed.at(2) = true;
                            break;
                        case SDL_BUTTON_X1:
                            m_mouseButtons.at(3) = true;
                            m_mouseButtonsPressed.at(3) = true;
                            break;
                        case SDL_BUTTON_X2:
                            m_mouseButtons.at(4) = true;
                            m_mouseButtonsPressed.at(4) = true;
                            break;
                    }
                    break;
                /// Check for mouse button releases.
                case SDL_MOUSEBUTTONUP:
                    switch(m_event.button.button)
                    {
                        case SDL_BUTTON_LEFT:
                            m_mouseButtons.at(0) = false;
                            m_mouseButtonsReleased.at(0) = true;
                            break;
                        case SDL_BUTTON_RIGHT:
                            m_mouseButtons.at(1) = false;
                            m_mouseButtonsReleased.at(1) = true;
                            break;
                        case SDL_BUTTON_MIDDLE:
                            m_mouseButtons.at(2) = false;
                            m_mouseButtonsReleased.at(2) = true;
                            break;
                        case SDL_BUTTON_X1:
                            m_mouseButtons.at(3) = false;
                            m_mouseButtonsReleased.at(3) = true;
                            break;
                        case SDL_BUTTON_X2:
                            m_mouseButtons.at(4) = false;
                            m_mouseButtonsReleased.at(4) = true;
                            break;
                    }
                    break;
                /// Check for mouse movements.
                case SDL_MOUSEMOTION:
                    m_mouseMotionX = m_event.motion.x;
                    m_mouseMotionY = m_event.motion.y;
                    break;

                default:
                    break;
            }
        }
    }
}
