#include "Pet.hpp"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"

int main(){
    

    std::string name;

    InMessageA msg_a;
    InMessageB msg_b;
    OutMessage msg_o;

    Pet pet("Tom");

    std::cout << "initial name is :" << pet.GetName() << std::endl ;


    name = "Mark";
    printf("SetName(%s) \n", name.c_str());
    pet.SetName(name);
    std::string s_name = pet.GetName() ;
    printf("GetName() = %s \n", s_name.c_str()) ;  

    pet.CheckMessage( msg_a, msg_b);
    msg_a.color = msg_a.BLUE;
    pet.CheckMessage( msg_a, msg_b);

    msg_a.value = 10 ;
    msg_b.value = 23 ;

    pet.Step( msg_a, msg_b, msg_o);
    printf("msg_o.sum: expect = %d , actual = %d\n", msg_a.value + msg_b.value, msg_o.sum ) ;

}