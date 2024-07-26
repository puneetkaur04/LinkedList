/*
    Puneet Kaur
*/ 
#include "list_read.h"
#include "list_write.h"
#include <stdio.h>
#include <stdlib.h>

NODE * listAppend(LIST *pLIST, double key){

    // boundary case: deal with NULL list
    if (pLIST == NULL){
        // This should not happen, if called correctly.
        fprintf(stderr, "Error in listAppend: NULL list\n");
        return NULL;
    }

    // allocate memory for a new node. 
    NODE *pNODE = (NODE *)malloc(sizeof(NODE));

    // set the key field of the new node to the value of <KEY>
    pNODE->key = key;

    // boundary case: deal with empty list
    if(pLIST->head == NULL && pLIST->tail == NULL)
    {
        // This may happen.
        // set the head and list to the new node 
        pLIST->head = pNODE;
        pLIST->tail = pNODE;
    }else{
        // Append the new node after the current tail of the list.
        pLIST->tail->next = pNODE;
        // set the tail to the new node 
        pLIST->tail = pNODE;
    }
    
    printf("Node with key %f appended\n", key);
    //listPrint(stdout, pLIST);
    return pNODE;
}

NODE * listDelete(LIST *pLIST, double key){
    // this is the previous node 
    NODE *pNODE = NULL;
    NODE *temp = pLIST->head;

    // boundary case: deal with NULL list 
    if (pLIST == NULL){
        // This should not happen, if called correctly.
        fprintf(stderr, "Error in listDelete: NULL list\n");
        return NULL;
    }

    // Search for the first node on the list whose key field is equal to the value of <key>
    while (temp != NULL && temp->key != key) {
        // pNODE is set to the previous node (temp)
        pNODE = temp;
        // temp is set to the next node 
        temp = temp->next;
    }

    listSearch(pLIST, key);

    // if the node isn't found 
    if(temp == NULL){
        printf("There is no node with key %f in list\n", key);
        return NULL;
    } 
    
    // if the previous node is null
    if (pNODE == NULL) {
        // boundary case: deleting the first node 
        // set head to next when head is to be deleted 
        pLIST->head = temp->next;
    } else { 
        //when the head is not the one being deleted the previous is set the temp next
        pNODE->next = temp->next;
        // if the tail is deleted set the tail to the previous 
        // boundary case: deleting the last node
        if(pLIST->tail == temp){
            pLIST->tail = pNODE;
        }
    }

    //free the memory 
    //free(temp);

    printf("Node with key %f deleted\n", key);
    
    return temp;
}

NODE * listInsert(LIST *pLIST, double key){

    // allocate memory for a new node  
    NODE *pNODE = (NODE *)malloc(sizeof(NODE));

    // set the key field of the new node to the value of <KEY>
    pNODE->key = key;

    // boundary case: deal with NULL list
    if (pLIST == NULL){
        // This should not happen, if called correctly.
        fprintf(stderr, "Error in listInsert: NULL list\n");
        return NULL;
    } 

    // boundary case: deal with EMPTY list
    if (pLIST->head == NULL && pLIST->tail == NULL)
    {
        // set the next node to NULL
        pNODE->next = NULL; 
        // set the head and list to the new node 
        pLIST->head = pNODE;
        pLIST->tail = pNODE;
    } else{
        // Insert the new node at head of the list.
        pNODE->next = pLIST->head; // set the next node to the head of the node 
        pLIST->head = pNODE; // set the head / front of the list to the new node
    }

    printf("Node with key %f inserted\n", key);
    
    // return the node 
    return pNODE;
}

