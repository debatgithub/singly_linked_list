#include <iostream>
#include "list_node.h"
#include "singly_linked_list.h"
int main (void );
#define LIST_MAX 9
int list_vals[LIST_MAX] = { 0, 1, 2, 3, 5, 8, 13, 21, 34 };
int main (void ) 
{

    singly_linked_list<int> * p_sll = new singly_linked_list<int>();
    list_node<int> *p_node;
    list_node<int> *q_node;
    SLL_ERROR sll_e;

    if (p_sll == NULL) {
        std::cout << "Singly linked list constructor failed" << std::endl;
        return 1;
    }
    std::cout << "Singly linked list constructor passed" << std::endl;
 
    for (int i = 0; i < LIST_MAX; i++) {
        std::cout << list_vals[i] << std::endl;
        p_node = new list_node<int>(list_vals[i]);
        if (p_node != NULL)
            p_sll->append_node(p_node);
        else
            std::cout << "List node creation failed" << std::endl;
    }
    std::cout << "Singly linked list append_node() passed" << std::endl;
 
    p_sll->print_list();

    p_node = new list_node<int>(13);
    q_node = p_sll->search_node(p_node, &sll_e);
    if (sll_e == SLL_SUCCESS) {
         std::cout << "Singly linked list search_node() passed" << std::endl; 
         sll_e = p_sll->delete_node(p_node);
    }
    else
         std::cout << "Singly linked list search_node() failed" << std::endl;
    p_sll->print_list();
     
    std::cout << std::endl;
    delete p_sll;
    return 0;

   
}


        
