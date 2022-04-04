from Pet_pybind import *

pet = Pet_py("Tom")

print(f"initial name is {pet.GetName()}")

msg_a = InMessageA_py()
msg_b = InMessageB_py()
msg_o = OutMessage_py()

name = "Mark"
print(f"SetName({name})")
pet.SetName( name )
print(f"GetName() = {pet.GetName()}")


pet.CheckMessage( msg_a, msg_b);
msg_a.color = BLUE;
pet.CheckMessage( msg_a, msg_b);
msg_a.value = 17 ;
msg_b.value = 23 ;
pet.Step( msg_a, msg_b, msg_o);
print(f"msg_o.sum: expect = {msg_a.value + msg_b.value} , actual = {msg_o.sum}" ) ;





