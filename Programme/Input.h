#ifndef INPUT_H
#define INPUT_H


//Classe qui va stocker les états des inputs
//cf event.cpp
class Input
{
    public:
    Input();

    bool m_left;
    bool m_right;
    bool m_up;
    bool m_down;
    bool m_space;
    bool m_quit;

};

#endif // INPUT_H
