
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>


#include <iostream>
#include "Data.h"
#include "myTypes.h"







int main ()
{

  std::cout << "\n start programm ...";

   //Remove shared memory on construction and destruction
   struct shm_remove
   {
      shm_remove() { bi::shared_memory_object::remove("MySharedMemory"); }
     ~shm_remove() { bi::shared_memory_object::remove("MySharedMemory"); }
   } remover;

   //Create shared memory
   bi::managed_shared_memory shm(bi::create_only,"MySharedMemory", 65536);

  // init alocator: alloc_inst 
  void_alloc  alloc_inst {shm.get_segment_manager()};

// MyMap* mymap = shm.construct<MyMap>("MyMap")(std::less<int>(),alloc_inst);
Object* pObj = shm.construct<Object>("MyOBJ")(alloc_inst);

pObj->data.X = 15;
pObj->data.Y = 21;
pObj->data.Label = "intesrest Obj";



Defect def00(alloc_inst);
def00.URL_address = "/mnt/source00";
def00.size = 152;
def00.width = 501;

Defect def01(alloc_inst);
def01.URL_address  = "unreal";
def01.size  = 800;
def01.width = 2;


//1. сразу положим в вектор
pObj->data.defects.emplace_back(def00);
pObj->data.defects.emplace_back(def01);


// 2. создадим вектор 
/*
ipc_vector_Defect vec_def(alloc_inst); 
vec_def.emplace_back(def00);
vec_def.emplace_back(def01);


// положим в вектор (присвоением) 
pObj->data.defects = vec_def;
*/








   //==========================================================================

  std::cout << "\n server in RAM ...";
  std::cout << "\n press any key to unload server ...";
  int wait_val;
  std::cin >> wait_val;


  std::cout << "\n end programm ..." << std::endl;
   return 0;
}