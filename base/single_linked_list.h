#ifndef LIST_SLL_H_
#define LIST_SLL_H_

#include "void.h"

/**
 * @brief Một node của danh sách liên kết đơn 
 * 
 */
typedef struct single_linked_node {
    struct single_linked_node * next;
    void * data;
} sln;

/**
 * @brief Cấu trúc danh sách liên kết đơn. 
 * Không được phép sửa đổi length trong quá trình sử dụng 
*/
typedef struct single_linked_list {
    sln * front;
    long length; 
} sll;

/**
 * @brief Duyệt toàn bộ sllist. 
 * tmpnode : con trỏ đến sln hiện tại.
 * Example : Tính tổng của một danh sách l.kết đơn gồm toàn int.
 * sll_traverse(x, list){
 *      sum += *((int*)(x->data))
 * }
 * 
 */
#define sll_traverse(tmpnode, sllist) \
    for (sln * tmpnode = sllist->front; tmpnode != NULL; tmpnode = tmpnode->next)

#define sll_is_empty(sllist) \
    (sllist->front == NULL)

/**
 * @brief Create an empty single linked list
 * 
 * @return sll* : pointer to the list
 */
sll * create_sll();

/**
 * @brief Create a single linked node
 * 
 * @return sln* : pointer to new node
 */
sln * create_sln();

/**
 * @brief Get last node of a list
 * @param  sllist : single linked list
 * @return last node in sllist, null if list empty
*/
sln* sll_back(sll* sllist);

/**
 * @brief Add a node to the end of list
 * @param list : single linked list
 * @param node : single linked node to add
 */
void sll_add_back(sll* list, sln* node);

/**
 * @brief Add a node to the front of list
 * @param list : single linked list
 * @param node : single linked node to add
 */
void sll_add_front(sll* list, sln* node);

/**
 * @brief get the first element in list, remove it 
 * @param list 
*/
sln* sll_pop_front(sll* list);

/**
 * @brief get the first element in list, remove it
 * @param list
*/
sln* sll_pop_back(sll* list);

/**
 * @brief Free a single linked list
 * @param list : A sll that need freeing
 * @param void_free_data : Function that free the data, pass null pointer to not free the data 
*/
void sll_free(sll* list, void (*void_free_data)(void*));

///**
// * @note This function is unavailable at the time of defined due to the lack of `defining function during
// * runtime` or `nested function`
// * @brief Construct a function to free sll
// * @param free_data A function pointer how to free data in sll
// * @return A function to free whole sll
// */
//void_free_func * sll_free_constructor(void_free_func free_data);

/**
 * @brief You must define this function to use sll_free_all
 */
void sll_free_data(void* data);

/**
 * @brief Free all list
 * @param list sll
 * @note You must define sll_free_data, or else the data will not be freed
 */
void sll_free_all(sll* list);

#endif  // LIST_SLL_H_