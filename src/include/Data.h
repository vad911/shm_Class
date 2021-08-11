#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <iostream>

#include "myTypes.h"  // определяю свои типы


class Defect{

   public:
   int size;
   int width;
   
   ipc_string URL_address;

   Defect(void_alloc alloc) : URL_address(alloc) {}
};



class Data {
   public:
   int X;
   int Y;
   
   ipc_string Label;
   
 //  ipc_vector_Defect def;

   ipc_vector_Defect defects;   // vector with class Defect

   Data(void_alloc alloc) : Label(alloc) , defects(alloc)   /*, defects(alloc)*/ {}

    
};


 class Object{

  public:

  Object(void_alloc alloc) : data(alloc) {}

  Data data;

  void show(){

    std::cout << "\nData.x: " << data.X;
    std::cout << "\nData.y: " << data.Y;
    std::cout << "\nData.label: " << data.Label;

    auto itb =   data.defects.begin();
    auto ite =   data.defects.end();
    std::cout << "\nDefects: ";
    for (auto& item : data.defects)
    {
       std::cout << "\nsize: " << item.size;
       std::cout << "\nwidth: " << item.width;
       std::cout << "\nURL_address: " << item.URL_address;
    }

  }



 };




#endif // DATA_H