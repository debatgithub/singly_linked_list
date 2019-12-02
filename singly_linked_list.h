#ifndef __INCLUDE_SINGLY_LINKED_LIST_H__
#define __INCLUDE_SINGLY_LINKED_LIST_H__
#include <iostream>
typedef enum e_singly_linked_list_error { SLL_CANT_FIND_NODE = -4, SLL_INSERT_POSITION_UNREACHABLE = -3, SLL_CANT_DELETE_NODE = -2, SLL_CANT_DELETE_AT_POSITION = -1, SLL_SUCCESS } SLL_ERROR; 
#include "list_node.h"
template <class T>
class singly_linked_list {
    public:
        singly_linked_list<T>() { head = NULL; };
        singly_linked_list<T>(list_node<T> *x) { head = x; head->set_next(NULL ); };
        ~singly_linked_list<T>() { };
        void append_node(list_node<T> *x) {
            list_node<T> * q = NULL;

            if (head == NULL) {
                head = x;
                head->set_next(NULL);
            }
            else {
                list_node<T> * p = head;
                while (p->get_next() != NULL)
                    p = p->get_next();
                p->set_next(x);
                x->set_next(NULL);
            }
        };
        void insert_node_at_head(list_node<T> *x)  {
            list_node<T> * temp = head;
            head = x;
            head->set_next(temp);
        };
        SLL_ERROR insert_node_at_position(list_node<T> *x, int k) {
            list_node<T> * q = head;
            list_node<T> * p = NULL;
            int i;
            if (k == 0) {
                this->insert_node_at_head(x);
                return SLL_SUCCESS;
            }
            for (i = 0; i < k; i++) 
            {
        
                if (q->get_next() != NULL) { 
                    p = q;
                    q = q->get_next();
                }
                else 
                    break;
            }
            if (i == k) {
                p->set_next(x);
                x->set_next(q);
                return SLL_SUCCESS;
            }
            else 
                return SLL_INSERT_POSITION_UNREACHABLE;
        };

        SLL_ERROR delete_node(list_node<T> *x) {
            list_node<T> * q = head;
            list_node<T> * p = NULL;
            int match_found = 0;
            while (1) {
                if (q->is_equal(x)) {
                    match_found = 1;
                    break;
                }
                if (q->get_next() != NULL) { 
                    p = q;
                    q = q->get_next();
                }
                else 
                    break;
            }
            if (match_found == 1) {
                if (p == NULL) /* match is at the head */ 
                    head = head->get_next();
                else 
                    p->set_next(q->get_next()); /* q gets deleted */
                return SLL_SUCCESS;
            }
            else 
                return SLL_CANT_DELETE_NODE;
       };

 
        SLL_ERROR delete_node_at_position(int x ) {
            list_node<T> * q = head;
            list_node<T> * p = NULL;
            int i;
 
            if (x == 0) { /* match is at the head */
                head = head->get_next();
                return SLL_SUCCESS;
            }
            for (i = 0; i < x; i++) { 
    
                if (q->get_next() != NULL) { 
                    p = q;
                    q = q->get_next();
                }
                else 
                    break;
           }
           if (i == x) {
                p->set_next(q->get_next()); /* q gets deleted */
                return SLL_SUCCESS;
           }
           else 
               return SLL_CANT_DELETE_AT_POSITION;
        };

       list_node<T> * search_node(list_node<T> *x, SLL_ERROR * p_sll_error) {
            list_node<T> * p = head;
            int match_found = 0;
            while (1) {
                if (p->is_equal(x) == true) {
                    match_found = 1;
                    break;
                 }
                 if (p->get_next() != NULL) 
                     p = p->get_next();
                 else 
                     break;
            }
            if (match_found == 1) {
                if (p_sll_error != NULL) 
                    *p_sll_error = SLL_SUCCESS;
                return p;
            }
            else {
                if (p_sll_error != NULL)
                    *p_sll_error = SLL_CANT_FIND_NODE;
                return NULL;
            }
        };
        void print_list() {
            list_node<T> * p = head;
            while (p != NULL) {
                p->print_node();
                std::cout << " ";
                p = p->get_next();
                std::cout << std::endl;
            }
               
        };
    protected:
        list_node<T> * head;
       
};
#endif // __INCLUDE_SINGLY_LINKED_LIST_H__




     
