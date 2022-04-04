#ifndef PET_HPP
#define PET_HPP

#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "InMessageA.hpp"
#include "InMessageB.hpp"
#include "OutMessage.hpp"

class Pet
{

    public:
    std::string name ;

    Pet (const std::string & name): name (name) {}

    void SetName ( std::string & name ) ;

    std::string GetName () ;

    // print msg_a.color
    void CheckMessage(InMessageA msg_a, InMessageB msg_b);

    // msg_o.sum = msg_a.value + msg_b.value
    void Step(InMessageA msg_a, InMessageB msg_b, OutMessage & msg_o);



} ;

#endif // PET_HPP