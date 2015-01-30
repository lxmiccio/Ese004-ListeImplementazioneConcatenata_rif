#include <stdlib.h>
#include ".\linkedListRef.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtBeginning(LLElement **first, int key)
{
    int allocationError = -1;
    LLElement *elementToInsert = (LLElement*)malloc(sizeof(LLElement));
    if(elementToInsert != NULL)
    {
        allocationError = 0;
        elementToInsert->key = key;
        elementToInsert->next = *first;
        *first = elementToInsert;
    }
    return allocationError;
}

/*
 * Inserts the new key at the end of the list.
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtEnd(LLElement **first, int key)
{
    int allocationError = -1;
    LLElement *elementToInsert = (LLElement*)malloc(sizeof(LLElement)), **temporary = first;
    if(elementToInsert != NULL)
    {
        allocationError = 0;
        while(*temporary != NULL)
            temporary = &((*temporary)->next);
        elementToInsert->key = key;
        elementToInsert->next = NULL;
        *temporary = elementToInsert;
    }
    return allocationError;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Return -1 if memory allocation fails.
 */
int LLInsertAtPosition(LLElement **first, int key, int position)
{
    int allocationError = -1;
    if(position >= 0 && position < LLSize(*first))
    {
        int counter;
        LLElement *elementToInsert = (LLElement*)malloc(sizeof(LLElement)), **temporary = first;
        if(elementToInsert != NULL)
        {
            allocationError = 0;
            for(counter = 0; counter < position; counter++)
                temporary = &((*temporary)->next);
            elementToInsert->key = key;
            elementToInsert->next = *temporary;
            *temporary = elementToInsert;
        }
    }
    return allocationError;
}

/*
 * Returns the size of the list.
 */
int LLSize(LLElement *first)
{
    int size;
    for(size = 0; first != NULL; size++)
        first = first->next;
    return size;
}

/*
 * Gives the key at the specified position. * 
 * 
 * Returns 0 on success.
 * Returns -1 if there is no key at the specified position
 */ 
int LLGetKey(LLElement *first, int position, int *key)
{
    int foundKey = -1;
    if(first != NULL && position >= 0 && position < LLSize(first))
    {
        foundKey = 0;
        int counter;
        for(counter = 0; counter < position; counter++)
            first = first->next; 
        *key = first->key;
    }   
    return foundKey;
}

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement *first, int key, int startPosition, int *position)
{
    int foundKey = -1;
    *position = -1;
    if(first != NULL && startPosition >= 0 && startPosition < LLSize(first))
    {
        int counter;
        for(counter = 0; counter < startPosition; counter++)
            first = first->next;
        for(; first != NULL && foundKey != 0; counter++)
        {
            if(first->key == key)
            {
                foundKey = 0;
                *position = counter;
            }         
            first = first->next;
        }
    }
    return foundKey;
}

/*
 * Remove the first element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveFirst(LLElement **first)
{
    int emptyList = -1;
    if(*first != NULL)
    {
        emptyList = 0;
        LLElement *elementToDelete = *first;
        *first = (*first)->next;
        free(elementToDelete);
    }
    return emptyList;
}

/*
 * Remove the last element of the list.
 * 
 * Returns 0 on success.
 * Returns -1 in csae of empty list.
 */
int LLRemoveLast(LLElement **first)
{
    int emptyList = -1;
    if(*first != NULL)
    {
        emptyList = 0;
        LLElement **elementToDelete = first;
        while((*elementToDelete)->next != NULL)
            elementToDelete = &((*elementToDelete)->next);
        *elementToDelete = NULL;
        free(*elementToDelete);
    }
    return emptyList;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns 0 on success.
 * Returns -1 in case it does not exist any element at the specified position
 */
int LLRemoveAtPosition(LLElement **first, int position)
{
    int existingElement = -1;
    if(*first != NULL && position >= 0 && position < LLSize(*first))
    {
        existingElement = 0;
        int counter;
        LLElement *elementToDelete, **temporary = first;
        for(counter = 0; counter < position; counter++)
            temporary = &((*temporary)->next);
        elementToDelete = *temporary;
        if((*temporary)->next != NULL)
            *temporary = (*temporary)->next;
        free(elementToDelete);
    }
    return existingElement;   
}

/*
 * Empties the list.
 * Returns 0 on success.
 * Return -1 in case of emtpy list. 
 */
int LLEmptyList(LLElement **first)
{
    int emptyList = -1;
    LLElement *elementToDelete;
    if(*first != NULL)
    {
        emptyList = 0;
        while(*first != NULL)
        {
            elementToDelete = *first;
            *first = (*first)->next;
            free(elementToDelete);
        }
    }
    return emptyList;
}