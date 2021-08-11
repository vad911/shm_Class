

#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

#include "Data.h"
#include <iomanip> // for put_time()




int main(int argc, char *argv[])
{
 


  // удалитель shared memory
  struct shm_remove
  {
       // we turn off this struct  for while
       //  shm_remove() {/* shared_memory_object::remove("MySharedMemory"); }
       // ~shm_remove() { shared_memory_object::remove("MySharedMemory"); }
  };

  // made object for auto removing shared memory
  shm_remove  remover;

  
  //Open already created shared memory object.
  bi::managed_shared_memory shm (bi::open_only, "MySharedMemory");



// ====================== Читаем структуру map<int, vec<int>> из памяти ========
      // имя объекта которое ищется

      std::string nameObject = "MyOBJ"; 
      
      Object* pObj;       

     // MyMap* pMap;
         
      
      size_t isExist_map = 0;
    

    //  std::pair< MyMap* ,std::size_t> ret_Data = shm.find<MyMap>(nameMap_data.c_str());
     std::pair< Object* ,std::size_t> ret_Data = shm.find<Object>(nameObject.c_str());
            

      // pVec = ret_Data.first;
      isExist_map = ret_Data.second;
      // =======================================================================
      std::cout << "\n We start to check data class ...";

      if (isExist_map == 1) { 
      std::cout <<"\n!!!Map is found: ";
      pObj = ret_Data.first;
      pObj->show();
        
      }
        
      

 
      else{
        std::cout << "\nI can't find string in shared memory";
        std::cout <<"\nRead string size from shared memory: " << isExist_map << std::endl;
      }


      
      
      // закончили проверку

      // =======================================================================

    
  
  return 0;
}



