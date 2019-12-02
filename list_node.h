#ifndef __INCLUDE_LIST_NODE_H__
#define __INCLUDE_LIST_NODE_H__
#include <iostream>
#include "node.h" 
template <class T>
class list_node : public node<T>
{
    
public:
    list_node<T>() : node<T>() { next = NULL; };
    list_node<T>(T n) : node<T>(n) { next = NULL; };
    list_node<T> * get_next(void ) { return next; };
    void set_next(list_node<T> * _next) { next = _next; }
    bool is_equal(list_node<T> * x) { 
        if (x->get_data() != this->get_data())
            return false;
        else
            return true;
   };
protected:
    list_node * next;
 

};
#endif // __INCLUDE_LIST_NODE_H__
