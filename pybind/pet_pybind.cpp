#include <pybind11/pybind11.h>
#include "Pet.hpp"

namespace py = pybind11;



// in python, you  can import module with 
//   import Pet_pybind
//      or 
//   from Pet_pybind import *
//     all name in the double quotes can be imported to python
// [1] PYBIND11_MODULE macro create module "Pet_pybind"
// [2] The c++ class "Pet" is mapped to python class "Pet_py"
// [3] define constructor py::init<const std::string>
// [4] define methods of the class
// [5] define public variables of the class
// [6] define enum type and value of the class
PYBIND11_MODULE(Pet_pybind, m) {
    m.doc() = "This is the module docs." ;

    // class Pet    
    py::class_<Pet>( m, "Pet_py" )
        .def (py::init<const std::string &>()       )   // constructor
        .def ("SetName",        &Pet:: SetName      )   // map Pet::SetName to python: set_name 
        .def ("GetName",        &Pet:: GetName      )   // map Pet::GetName to python: get_name 
        .def ("CheckMessage",   &Pet:: CheckMessage )   // map Pet::CheckMessage to python: check_message 
        .def ("Step",           &Pet:: Step         )   // map Pet::Step to python: step 
        .def_readwrite ("name", &Pet:: name         ) ; // map internal variable



    // class InMessageA
    py::class_<InMessageA>( m, "InMessageA_py" )
        .def (py::init())  // constructor
        .def_readwrite ("msg",   &InMessageA::msg   )   // map variable msg
        .def_readwrite ("id",    &InMessageA::id    )   // map variable id
        .def_readwrite ("value", &InMessageA::value )   // map variable value
        .def_readwrite ("color", &InMessageA::color ) ; // map variable color

    // enum COLOR of class InMessageA
    py::enum_<InMessageA::COLOR>(m, "COLOR_py")
        .value("RED",   InMessageA::COLOR::RED   )
        .value("GREEN", InMessageA::COLOR::GREEN )
        .value("BLUE",  InMessageA::COLOR::BLUE  )
        .value("WHITE", InMessageA::COLOR::WHITE )
        .value("BLACK", InMessageA::COLOR::BLACK )
        .export_values();

    // class InMessageB
    py::class_<InMessageB>( m, "InMessageB_py" )
        .def (py::init()) // constructor
        .def_readwrite ("value", &InMessageB::value ) ;  // map variable value


    // class OutMessage
    py::class_<OutMessage>( m, "OutMessage_py" )
        .def (py::init()) // constructor
        .def_readwrite ("sum", &OutMessage::sum ) ;  // map variable value

}

