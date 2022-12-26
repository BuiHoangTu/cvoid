#ifndef BASE_VOID_H_
#define BASE_VOID_H_

/**
 * @brief extent void utilities
 * 
 */

#include <stdio.h>

/**
 * @brief swap 2 pointers
 * 
 */
#define void_swap(v1, v2) \
    do { \
        void tmp_v = (v1); \
        (v1) = (v2); \
        (v2) = tmp_v; \
    } while (0)

/**
 * Định nghĩa hàm nhận vào một con trỏ và không trả về gì cả.
 * Mục đích : Thay thế trong các hàm phức tạp
 */
typedef void void_free_func(void*)  ;

#endif  // BASE_VOID_H_