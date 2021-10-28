//
// Created by wmespindula on 28/10/2021.
//

#include <stddef.h>
#include <malloc.h>
#include "linkedlist.h"


Node *findTail(LinkedList linkedList) {
    Node *current = linkedList.head;
    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}

Node *findPreviousElement(LinkedList linkedList, u_int pos) {
    Node *current = linkedList.head;
    if (pos != 0) {
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
        }
        return current;
    } else {
        return NULL;
    }
}

Node *findElement(LinkedList linkedList, u_int pos) {
    if (pos == 0) {
        return linkedList.head;
    } else {
        return findPreviousElement(linkedList, pos)->next;
    }
}

Node *newLlElement(double data) {
    Node *pElement = (Node *) malloc(sizeof(Node));
    pElement->data = data;

    return pElement;
}

bool classic_insertTail(LinkedList *linkedList, double data) {
    if (linkedList->head == NULL) {
        vanilla_insertHead(linkedList, data);
    } else {
        Node *pElement = newLlElement(data);
        Node *tailElement = findTail(*linkedList);
        tailElement->next = pElement;
    }

    linkedList->size++;

    return true;
}


bool vanilla_insertAt(LinkedList *linkedList, double data, u_int pos) {
    if (pos < linkedList->size) {
        if (pos == 0) {
            return vanilla_insertHead(linkedList, data);
        } else {
            Node *preElementAt = findPreviousElement(*linkedList, pos);
            Node *elementAt = preElementAt->next;

            Node *newElement = newLlElement(data);
            preElementAt->next = newElement;
            newElement->next = elementAt;

            linkedList->size++;

            return true;
        }
    } else {
        return false;
    }
}

bool vanilla_insertHead(LinkedList *linkedList, double data) {
    Node *newElement = newLlElement(data);
    Node *head = linkedList->head;

    if (head != NULL) {
        newElement->next = head;
    }

    linkedList->head = newElement;
    linkedList->size++;

    return true;
}

Node *vanilla_get(LinkedList linkedList, u_int pos) {
    if (pos < linkedList.size) {
        return findElement(linkedList, pos);
    }
    return NULL;
}

Node *vanilla_getFirst(LinkedList linkedList) {
    return linkedList.head;
}

Node *vanilla_getLast(LinkedList linkedList) {
    return findTail(linkedList);
}

void vanilla_print(LinkedList linkedList) {
    Node *current = linkedList.head;
    while (current != NULL) {
        printf("%f| -> ", current->data);
        current = current->next;
        if (current == NULL) {
            printf("NULL| \n");
        }
    }
}

bool vanilla_delete(LinkedList *linkedList, u_int pos) {
    return true;
}

