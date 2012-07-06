#ifndef _UTIL_H
#define _UTIL_H

#include <stdint.h>
#include <map>
//#include <boost/intrusive/avl_set.hpp>

/* Old version:*/
int read_gate(const char* line, const std::map<uint64_t,uint64_t>& _map, uint64_t& id, uint64_t* inputs, char & tab, char & output, char & party, char & arity);

std::map<uint64_t,uint64_t> * load_map(FILE * map_file);//, uint64_t map_size);

/*
int read_gate(const char* line, const boost::intrusive::avl_set<std::pair<uint64_t,uint64_t> >& _map, uint64_t& id, uint64_t* inputs, char & tab, char & output, char & party, char & arity);

boost::intrusive::avl_set<std::pair<uint64_t,uint64_t> > * load_map(FILE * map_file, uint64_t map_size);
*/
template <typename T>
struct gate_key
{
  T input0,input1;
  char tab;
};

template <typename T>
bool gate_key_comp(struct gate_key<T> lhs, struct gate_key<T> rhs)
{
  if(lhs.input0 < rhs.input0) return true;
  else if(lhs.input0 == rhs.input0)
    {
      if(lhs.input1 < rhs.input1)
        {
          return true;
        }
      else if(lhs.input1 == rhs.input1)
        {
          return lhs.tab < rhs.tab;
        }
      else
        return false;
    }
  else
    return false;
  return false;
}


#endif
