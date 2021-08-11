# ================              pro_shm  ( Shared memory)    =========================
cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# default to Release build (it's what most people will use, except cegui devs)
#=====================set kind of build: Debug  +++++++====================== 
if (NOT CMAKE_BUILD_TYPE)
    set( CMAKE_BUILD_TYPE Debug CACHE STRING "Sets the configuration to build (Release, Debug, etc...)")
endif()
#============================================================================


#sets names for aplication
set (PROJECT_NAME_CREATE  shm_create)
set (PROJECT_NAME_READER  shm_reader)




#set name for project
project(${PROJECT_NAME_CREATE}  )

project(${PROJECT_NAME_READER}  )



# add some flags for build
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lrt")





# make application
add_executable(
                 ${PROJECT_NAME_CREATE}
                 src/source/writer.cpp

                 src/include/Data.h
                 src/include/myTypes.h
              )


              # make application


add_executable(
                ${PROJECT_NAME_READER}
                src/source/reader.cpp

                src/include/Data.h
                src/include/myTypes.h
              )




# Сначала указываем таргет  - add_executable
# затем                     - target_compile_features
# иначе будет ошибка
# add_executable defines a target, but on your code you define a target after trying to compile it.
# just change the position of those two lines:
# first define the target
# link the library.
# like this
#            add_executable(OpenCV_Basics ${SOURCE_FILES})
#            target_link_libraries(OpenCV_Basics )





# не у всех работает 17 стандарт тогда применяют функцию  
# target_compile_features  см ниже
target_compile_features(${PROJECT_NAME_CREATE}   PRIVATE cxx_std_17)

target_compile_features(${PROJECT_NAME_READER}   PRIVATE cxx_std_17)



#make include for include directories
target_include_directories(
	                           ${PROJECT_NAME_CREATE} PRIVATE
                               "src/include"
                           )


target_include_directories(
                            ${PROJECT_NAME_READER} PRIVATE
                            "src/include"
                          )

	

#============  boost [1]================================
# lib boost
# https://github.com/boostorg/boost
  set(Boost_USE_STATIC_LIBS        ON) # only find static libs
  set(Boost_USE_MULTITHREADED      ON)
  set(Boost_USE_STATIC_RUNTIME    OFF)
  find_package(Boost REQUIRED)
if(Boost_FOUND)
  message("!!!Boost  is Found!!!")
  include_directories(${Boost_INCLUDE_DIRS})
  
# main target ${PROJECT_NAME}
    target_link_libraries( ${PROJECT_NAME_CREATE}  ${Boost_LIBRARIES})
    
    target_link_libraries(${PROJECT_NAME_CREATE} PUBLIC pthread)  
    target_link_libraries(${PROJECT_NAME_CREATE} PUBLIC rt)
 
    target_link_libraries( ${PROJECT_NAME_READER}  ${Boost_LIBRARIES})
    
    target_link_libraries(${PROJECT_NAME_READER} PUBLIC pthread)  
    target_link_libraries(${PROJECT_NAME_READER} PUBLIC rt)
 



endif(Boost_FOUND)
#============  boost [2]================================




#============   gtest [1]================================
# lib gtest - lib for testing functions
# https://github.com/google/googletest

find_package(GTest REQUIRED)
if(GTest_FOUND)
  message("!!!Gtest  is Found!!!")
# Build googletest
# add_subdirectory(external/googletest)
# add_subdirectory(external/libstorage/external/googletest)

# Link test target against gtest libraries
  target_link_libraries(${PROJECT_NAME_CREATE}   PRIVATE gtest gtest_main)
 
  target_link_libraries(${PROJECT_NAME_READER}   PRIVATE gtest gtest_main)
endif(GTest_FOUND)
#============  gtest [2]================================


#============  nlohmann_json [1]========================
# nlohmann_json - work with json files parse from json and pack in json
# https://github.com/nlohmann/json
find_package (nlohmann_json 3.9 REQUIRED)
if(nlohmann_json_FOUND)
  message("!!!nlohmann_json  is Found!!!")
# find_package (nlohmann_json 3.9 REQUIRED)
# add_subdirectory(external/json)
# target_link_libraries( ${TEST_PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json )
target_link_libraries( ${PROJECT_NAME_CREATE}  PRIVATE nlohmann_json::nlohmann_json )
target_link_libraries( ${PROJECT_NAME_READER}  PRIVATE nlohmann_json::nlohmann_json )

endif(nlohmann_json_FOUND)
#============  nlohmann_json [2]========================


#============  OpenCV [1]===============================
# OpenCV - lib for computer Vision
# https://github.com/opencv/opencv
# https://github.com/opencv/opencv_contrib 

  find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
  message("!!!OpenCV is Found!!!")
  include_directories(${OpenCV_INCLUDE_DIRS})
# message("OpenCV_INCLUDE_DIRS =:  ${OpenCV_INCLUDE_DIRS} ")
# use with  PRIVATE options, or you get error
  target_link_libraries(${PROJECT_NAME_CREATE}  PRIVATE ${OpenCV_LIBS})
  target_link_libraries(${PROJECT_NAME_READER}  PRIVATE ${OpenCV_LIBS})
  

# message("OpenCV_LIBS =:  ${OpenCV_LIBS} ")
endif(OpenCV_FOUND)
#============  OpenCV [2]===============================


#============  glog [1]===============================
# lib glog - Google Logging Library 
# https://github.com/google/glog.git - 


  find_package(GFLAGS REQUIRED) 
  include_directories(${GFLAGS_INCLUDE_DIRS})

  find_package (glog REQUIRED)
if(glog_FOUND)
  message("!!!glog is Found!!!")
# add_subdirectory(external/glog)
 target_link_libraries (${PROJECT_NAME_CREATE}    PRIVATE glog::glog)
 target_link_libraries (${PROJECT_NAME_READER}    PRIVATE glog::glog)
 
endif(glog_FOUND)
#============  glog [2]===============================


#============================= storage [1]====================================
# storage  - libstorage - inner lib for work with shared memory
# https://github.com/tmk-org/libstorage

# add_subdirectory(external/libstorage)
# target_link_libraries(${PROJECT_NAME}  PRIVATE storage)
#============================= storage [2]====================================
