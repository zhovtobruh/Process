cmake_minimum_required(VERSION 3.5)
project(LinuxProcess  LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF)


find_package(Boost COMPONENTS system thread  REQUIRED) 

set(CMAKE_SOURCE_DIR src)
set(SOURCE 
    ${CMAKE_SOURCE_DIR}/parent.cpp 
    ${CMAKE_SOURCE_DIR}/ParentProcess/ParentProcess.cpp
    ${CMAKE_SOURCE_DIR}/CmdParser/CmdParser.cpp
    ${CMAKE_SOURCE_DIR}/Writer/Writer.cpp
    )
set( INCLUDE_DIR ${CMAKE_SOURCE_DIR}/ParentProcess  
     ${CMAKE_SOURCE_DIR}/CmdParser ${CMAKE_SOURCE_DIR}/Writer)
add_executable(parent.x ${SOURCE})
target_include_directories(parent.x  PRIVATE ${Boost_INCLUDE_DIRS}  ${INCLUDE_DIR}) 
target_link_libraries(parent.x  boost_program_options boost_system boost_thread pthread)

set(SOURCE_CHILD 
    ${CMAKE_SOURCE_DIR}/child.cpp 
    ${CMAKE_SOURCE_DIR}/ChildProcess/ChildProcess.cpp 
    ${CMAKE_SOURCE_DIR}/Writer/Writer.cpp
    )
set( INCLUDE_DIR ${CMAKE_SOURCE_DIR}/ChildProcess ${CMAKE_SOURCE_DIR}/Writer)
add_executable(child.x ${SOURCE_CHILD})
target_include_directories(child.x  PRIVATE ${Boost_INCLUDE_DIRS}  ${INCLUDE_DIR}) 
