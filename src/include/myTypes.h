#ifndef MYTYPES_H
#define MYTYPES_H

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/map.hpp>

#include <chrono>



class Data;
class Defect;



namespace bi  = boost::interprocess;
using segment = bi::managed_shared_memory::segment_manager;

//==============================================================================
/*
// Ver:    ipc_string -> class Data -> vec<Data> -> map <int, Data>
// template <typename Type> using myAlloc = bi::allocator<Type, segment>;

using def_alloc  = bi::allocator<void, segment>;   
using char_allocator = bi::allocator<char, bi::managed_shared_memory::segment_manager>;
using ipc_string     = bi::basic_string<char, std::char_traits<char>, char_allocator>;                          // работает



using vecAllocator = bi::allocator<Data, bi::managed_shared_memory::segment_manager> ;

using vec = bi::vector<Data, vecAllocator>;

using ValueType = std::pair<const int, vec>;
using ShmemAllocator = bi::allocator<ValueType, bi::managed_shared_memory::segment_manager>;
using MyMap = bi::multimap<int, vec, std::less<int>, ShmemAllocator>;
*/

//==============================================================================
// Ver:    ipc_string -> class Data -> map <int, Data>

// для ips_string
using void_alloc     = bi::allocator<void, segment>;                                          // работает
using char_allocator = bi::allocator<char, bi::managed_shared_memory::segment_manager>;       // работает
using ipc_string     = bi::basic_string<char, std::char_traits<char>, char_allocator>;        // работает

// для класса Defect
// using defect_allocator  = bi::allocator<Defect, bi::managed_shared_memory::segment_manager> ;

// для определения вектора хранящего данные класса Defect
// using ipc_vector_Defect = bi::vector<Defect, bi::managed_shared_memory::segment_manager>;


// для класса Data
using data_allocator = bi::allocator<Data, bi::managed_shared_memory::segment_manager> ;      // работает

// для map   
using ValueType      = std::pair<const int, Data>;                                            // работает
using ShmemAllocator = bi::allocator<ValueType, bi::managed_shared_memory::segment_manager>;  // работает
using MyMap          = bi::multimap<int, Data, std::less<int>, ShmemAllocator>;               // работает

// === for definition vector < class Defect> ===
using defect_allocator  = boost::interprocess::allocator<Defect, bi::managed_shared_memory::segment_manager >;
using ipc_vector_Defect = boost::interprocess::vector<Defect, defect_allocator>;




# endif // MYTYPES_H