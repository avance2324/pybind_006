#include "Pet.hpp"

void Pet::SetName ( std::string &name ){
        this->name = name ;
}

std::string Pet::GetName ( ) {
        return this->name ; 
}


void Pet::CheckMessage(InMessageA msg_a, InMessageB msg_b){

        printf("msg_a.color = %d \n", msg_a.color);

}


void Pet::Step(InMessageA msg_a, InMessageB msg_b, OutMessage & msg_o){
        msg_o.sum = msg_a.value + msg_b.value ; 

}