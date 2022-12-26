#include "base/single_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

void ret_func();

sln* create_sln() {
    return calloc(1, sizeof(sln));
}

sll* create_sll() {
    return calloc(1, sizeof(sll));
}

sln* sll_back(sll* sllist) {
    sln* tmp_sln = sllist->front;
    if (tmp_sln)
        while (tmp_sln->next != NULL) tmp_sln = tmp_sln->next;
    
    return tmp_sln;
}

void sll_add_back(sll* list, sln* node){
    node->next = NULL;
    if (sll_is_empty(list)) {
        list->front = node;
    } else {
        sll_back(list)->next = node;
    }
    list->length++;
}

void sll_add_front(sll* list, sln* node) {
    node->next = list->front;
    list->front = node;
    list->length++;
}

sln* sll_pop_front(sll* list) {
    sln* front_n = list->front;
    if (front_n) { // there is a front
        list->front = front_n->next;
        list->length--;
    }
    return front_n;
}

sln* sll_pop_back(sll* list) {
    sln* back_node = sll_back(list);
    if (list->length > 0) { // if length = 0, dont have to change the list
        list->length--;
        sln* tmp_node = list->front;
        if (tmp_node != back_node) { // if there is more than 1 node
            while (tmp_node->next != back_node) tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        } else { // if just 1 node, remove it, nothing left
            list->front = NULL;
        }
        
    }
    return back_node;
}

void sll_free(sll* list, void_free_func voidFreeFunc) {
    sln * tmpnode;
    if (voidFreeFunc != NULL)
        for (sln * curnode = list->front; curnode != NULL; curnode = tmpnode) {
            voidFreeFunc(curnode->data);
            tmpnode = curnode->next;
            free(curnode);
        }
    free(list);
}

//void_free_func *sll_free_constructor(void_free_func free_data) {
//    void ret_func(sll* list){
//        sln * tmpnode;
//        if (free_data != NULL)
//            for (sln * curnode = list->front; curnode != NULL; curnode = tmpnode) {
//                free_data(curnode->data);
//                tmpnode = curnode->next;
//                free(curnode);
//            }
//        free(list);
//    }
//    return &ret_func;
//}

