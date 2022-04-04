#ifndef OUTMESSAGE_HPP
#define OUTMESSAGE_HPP

#include <iostream>


class OutMessage
{

    public:

    std::string msg ;
    int sum = {};


    OutMessage (int n = 1): sum{n}
    {}
    
} ;

#endif // OUTMESSAGE_HPP