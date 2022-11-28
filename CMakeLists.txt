cmake_minimum_required(VERSION 3.8)

project(WhereIsTheMoon)

set(SOURCES_CPP
  main.cpp
  mainwindow.cpp
  gridscene.cpp
  graphicsviewzoom.cpp
  options.cpp
  mainwindow.ui
)

set(SOURCES_H
  mainwindow.h
  gridscene.h
  graphicsviewzoom.h
  options.h
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH /home/hugo/Qt/5.15.2/gcc_64)

add_library(my_compiler_flags INTERFACE)
target_compile_features(my_compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(my_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-O2;-Wno-conversion-null;-Wno-pragmas;-Wno-trigraphs;-no-pie;-Wformat;-Wformat-security;>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED Core Gui Widgets Xml Concurrent Network PrintSupport)

add_subdirectory(aaplus)

add_executable(${PROJECT_NAME} ${SOURCES_CPP})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR/aaplus}")

target_link_libraries(${PROJECT_NAME} z pthread Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Widgets Qt5::Xml Qt5::Concurrent Qt5::Network Qt5::PrintSupport
    my_compiler_flags aaplus-static)

