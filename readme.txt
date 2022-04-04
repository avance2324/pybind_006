Overview 
=========================================
  1) use pybind to create a python module (.so) for C/C++ code.
  2) import the created python module in python program test.py
  3) the cpp code contains several classes
  4) the pet_pybind.cpp map member of class, enum inside class to python
  
  
Structure
=========================================
<this_dir>
  |
  |-- Pet/
  |     |
  |     |-- src/
  |     |     |
  |     |     |-- main.cpp  // test
  |     |     |
  |     |     |-- Pet.cpp  // class definition
  |     |     |
  |     |     |-- InMessageA.cpp  // class for input A
  |     |     |
  |     |     |-- InMessageB.cpp  // class for input B
  |     |     |  
  |     |     +-- OutMessage.cpp  // class for output  
  |     |  
  |     +-- include/
  |           |
  |           |-- Pet.hpp  // test
  |           |
  |           |-- InMessage.hpp  // test
  |           |
  |           |-- InMessageB.hpp  // test
  |           |
  |           +-- OutMessage.hpp  // test
  |     
  |-- pybind/
  |     |
  |     |-- Pet_pybind.cpp
  |     |
  |     |-- CMakeLists.txt
  |     |
  |     |-- build
  | 
  |-- test/
  |     |
  |     +-- test_pybind.py
  |
  |-- readme.txt
  |     
  |-- <scripts>




Explanation
=========================================
1.  main.cpp
    c source code, define function some_fn(), to be called by python

2.  main_pybind.cpp
    - include pybind11/pybind11.h
    - create python module from C function with macro PYBIND11_MODULE

3.  CMakeLists.txt
    - include pybind11/pybind11Config.cmake
    - create shared library based on src/*.c and bind/*.c

4.  test.py 
    - import generated python module
       from build.my_module import some_fn_python_name as fn
    - run function
       print(f"{fn(13.2, 11)}")



How to 
=========================================
1.  test Pet cpp code with cmake
    ----------------------------
    cd Pet
    . run_cmake.scr

2.  test Pet cpp code with bazel
    ----------------------------
    cd Pet
    . run_bazel.scr

3.  build python module with cmake
    ------------------------------
    cd pybind
    . build_cmake.scr

4.  build python module with bazel
    ------------------------------
    . .envrc
    . build.scr

5.  test python module with bazel
    -----------------------------
    . .envrc
    cd test
    . run.scr

6.  build + test python module
    --------------------------
    . .envrc
    . run.scr






Question/Notes
=========================================
1.  How can I know where is the file pybind11.h located?
    <= locate  pybind11.h l


2.  what is the difference between ctype and pybind approach?
    1) pybind
    ----------
        - build python module share library from source and bind code 
        - import python module python program
        - the share library contains the pybind code 

    2) ctype
    ----------
        - build shared library from source code
        - in python code, load the shared library with ctype.cdll.LoadLibrary(*.so)
        - call function by testlib.my_func()

3.  how to create launch.json for debuging C/C++ file
    3.1) rename .vscode/launch.json if any
    3.2) click Run and Debug 
    3.3) create a launch.json file
    3.4) C++ (GDB/LLDB)
    3.5) change the generate launch.json as follows: 
            "program": "/home/fjxvn4/Python3/Python-3.7.6/bin/python3",
            "args": ["${workspaceFolder}/test.py"],

4.  how to create launch.json for debuging python file
    4.1) rename .vscode/launch.json if any
    4.2) click Run and Debug 
    4.3) create a launch.json file
    4.4) python

5.  how to import the generated module if it is located in different directory?
    5.1) assume following Structure 
         <dir>/
           |
           |-- build/
           |     |
           |     +-- my_module.cpython-37m-x86_64-linux-gnu.so
           |
           +-- test.py
    5.2) add following code in test.py
            import build.my_module
            from build.my_module import some_fn_python_name as fn  
            ...
            print(f"{build.my_module.__doc__}")
            print(f"{fn(13.2, 11)}")
    5.3) another option is to export PYTHONPATH

6.  can I debug C and Python together?
    No, because they use different debugger
    6.1  if you want to debug python, 
          cd  .vscode/
          ln -s launch_python.json launch.json
          
    6.2  if you want to debug c, 
          cd  .vscode/
          ln -s launch_c.json launch.json

7.  how to debug the c code ?
    7.1  . build.scr
    7.2  code .
    7.3  cd .vscode
    7.4  ln -s launch_c.json launch.jso
    7.5  set breakpoint in c code and F5

8.  how to debug the c code ?
    8.1  . build.scr
    8.2  code .
    8.3  cd .vscode
    8.4  ln -s launch_python.json launch.json
    8.5  set breakpoint in c code and F5
  
9.  when I import the module Pet_pybind, I got error: undefined symbol: _ZN3Pet7GetNameB5cxx11Ev
    <= The reason is in the CMakeLists.txt 
       The source file ../Pet/src/Pet.cpp is set to variable SRC_FILES,
       but actually ${SRC} is used pybind11_add_module(Pet_pybind ${SRC} ${BIND}

10. How to quickly check if generate module works or not?
    <= after generate .so file do following :
       cd pybind/build/
       python3 
       import  Pet_pybind

11. In pet_pybind.cpp, the macro PYBIND11_MODULE create module "Pet_pybind".
    The CMakeLists.txt should build a target with the same name "Pet_pybind", 
    so that python can find the module in specific dir

12. how to quickly switch between debugging c and python?
    1) switchy launch.json
        - you create different launch_c.json and launch_py.json
        - when debug python, ln -s launch_py.json launch.json
        - when debug c, ln -s launch_c.json launch.json

    2) switch by using different workspace
        - create .vscode/launch.json for c in 005_multi_class
        - create .vscode/launch.json for python in 005_multi_class/test
        - when debug c, set 005_multi_class as workspace
        - when debug py, set 005_multi_class/test as workspace

13. how to quickly create environment for bazel
    1) in 006_multi_class_bazel, create empty file WORKSPACE
    2) in the directory where you want build, create BUILD by copy 
       from bazel/
       create BUILD here:
        006_multi_class_bazel/
            pybind/
              +- BUILD     <= build Pet_pybind.*.so
            Pet/
              +- BUILD     <= build library Pet, test          
    3) edit following BUILD files
        006_multi_class_bazel/Pet/BUILD    -> cc_binary + cc_library
        006_multi_class_bazel/pybind/BUILD

14. to build python module with bazel and pybind, you need 
    1) set WORKSPACE                => see WORKSPACE
    2) export  PYTHON_BIN_PATH      => see .envrc
    3) pybind/BUILD file use rule pybind_extension

15. how does BUILD work?
    <= see comments in pybind/BUILD