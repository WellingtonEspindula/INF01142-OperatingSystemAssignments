//
// Created by wmespindula on 28/10/2021.
//

#ifndef LOCALITY_STUDY_LINKEDLIST_H
#define LOCALITY_STUDY_LINKEDLIST_H

#include <sys/types.h>
#include <stdbool.h>

enum LinkedListType {
    VANILLA,
    MEMORY_POOL
};

typedef struct LlElement {
    double data;
    struct LlElement *next;
} LlElement;

typedef struct LinkedList {
    size_t size;
    LlElement *head;

    /**
    * Append data to the tail of the Linked List
    * @param linkedList
    * @param data
    */
    bool (*insert)(struct LinkedList *, double);

    /**
    * Inserts data into the given position of the Linked List
    * @param linkedList
    * @param data
    * @param pos
    */
    bool (*insertAt)(struct LinkedList *, double, u_int);

    /**
    * Inserts data into the Linked List's Head
    * @param linkedList
    * @param data
    */
    bool (*insertHead)(struct LinkedList *, double);

    /**
    * Get Element at Linked List position
    * @param *linkedList
    * @return
    */
    LlElement *(*get)(struct LinkedList, u_int);

    /**
    * Get First Element (Head) at Linked List
    * @param *linkedList
    * @param pos
    * @return
    */
    LlElement *(*getFirst)(struct LinkedList);

    /**
    * Get Last Element (Tail) at Linked List
    * @param *linkedList
    * @return
    */
    LlElement *(*getLast)(struct LinkedList);

    /**
    * Delete data from given a position
    * @param linkedList
    * @param pos
    */
    bool (*delete)(struct LinkedList *, u_int);

    void (*print)(struct LinkedList);

} LinkedList;

/*
 * --------------------------
 * VANILLA LINKED LIST METHODS
 * ---------------------------
 * */

bool vanilla_insert(LinkedList *linkedList, double data);

bool vanilla_insertAt(LinkedList *linkedList, double data, u_int pos);

bool vanilla_insertHead(LinkedList *linkedList, double data);

bool vanilla_delete(LinkedList *linkedList, u_int pos);

LlElement *vanilla_get(LinkedList linkedList, u_int pos);

LlElement *vanilla_getFirst(LinkedList linkedList);

LlElement *vanilla_getLast(LinkedList linkedList);

void vanilla_print(LinkedList linkedList);

static LinkedList vanilla_initLinkedList();

/*
 * --------------------------
 * MEMORY POOL LINKED LIST METHODS
 * ---------------------------
 * */

bool mp_insert(LinkedList *linkedList, double data);

bool mp_insertAt(LinkedList *linkedList, double data, u_int pos);

bool mp_insertHead(LinkedList *linkedList, double data);

bool mp_delete(LinkedList *linkedList, u_int pos);

LlElement *mp_get(LinkedList linkedList, u_int pos);

LlElement *mp_getFirst(LinkedList linkedList);

LlElement *mp_getLast(LinkedList linkedList);

void mp_print(LinkedList linkedList);

static LinkedList mp_initLinkedList();

/*
 * --------------------------
 * COMMON LINKED LIST METHODS
 * ---------------------------
 * */


static LinkedList initLinkedList(enum LinkedListType type) {
    if (type == VANILLA) {
        return vanilla_initLinkedList();
    } else if (type == MEMORY_POOL) {
      return mp_initLinkedList();
    } else {
        LinkedList ll = {};
        return ll;
    }
}

static LinkedList vanilla_initLinkedList() {
    LinkedList ll = {
            .size = 0,
            .head = NULL,
            .insert = vanilla_insert,
            .insertHead = vanilla_insertHead,
            .insertAt = vanilla_insertAt,
            .get = vanilla_get,
            .getFirst = vanilla_getFirst,
            .getLast = vanilla_getLast,
            .print = vanilla_print
    };
    return ll;
}

static LinkedList mp_initLinkedList() {
    LinkedList ll = {
            .size = 0,
            .head = NULL,
            .insert = mp_insert,
            .insertHead = mp_insertHead,
            .insertAt = mp_insertAt,
            .get = mp_get,
            .getFirst = mp_getFirst,
            .getLast = mp_getLast,
            .print = mp_print
    };
    return ll;
}

/**
 * Get Element Data at Linked List position
 * @param *linkedList
 * @param pos
 * @return
 */
inline double getData(LinkedList linkedList, u_int pos) {
    return vanilla_get(linkedList, pos)->data;
}


#endif //LOCALITY_STUDY_LINKEDLIST_H
