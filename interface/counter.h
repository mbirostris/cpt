#ifndef cpt_counter
#define cpt_counter

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



template <class T> 
class Counter{
  private:
      static int count;
  public:
    Counter(){
       count++;
    }  
    Counter(const Counter &c){
       if(this != &c){
            count++;
        }
    }   
    virtual ~Counter(){
       count--;
    }    
    static int GetCount() {
         return count;
    }
};
template<class T> int Counter<T>::count = 0; 

class counter : private Counter<int>{

    std::string inn;
    public:

    using Counter<int>::GetCount;
    counter(){inn = static_cast<std::ostringstream*>( &(std::ostringstream() << this->GetCount()) )->str();}
    const char* getInn() const {return inn.c_str();} 

};

#endif
