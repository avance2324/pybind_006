#ifndef INMESSAGEA_HPP
#define INMESSAGEA_HPP

#include <iostream>



class InMessageA
{



    public:

    enum COLOR {RED, GREEN, BLUE, WHITE, BLACK};

    std::string msg ;
    int id;
    int value ;
    COLOR color ;

    InMessageA () {
        this->msg = "InMessageA" ;
        this->color = WHITE ;
        this->id = 0 ;
        this->value = 0.0 ;
    }


} ;

#endif // INMESSAGEA_HPP