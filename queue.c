/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (!q) return NULL;

    q->size = 0;
    q->head = NULL;
    q->tail = NULL;

    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if(!q) return;

    /* How about freeing the list elements? */
    list_ele_t *elem = q->head;
    list_ele_t *tmp;
    while (elem)
    {
        tmp = elem->next;
        free(elem);
        elem = tmp;
    }

    /* Free queue structure */
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    /* What should you do if the q is NULL? */
    if (!q) return false;

    list_ele_t *newh;
    newh = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if(!newh) return false;

    newh->value = v;
    newh->next = q->head;
    q->head = newh;
    if(!q->tail) q->tail = newh;
    q->size++;

    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    if(!q) return false;
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    list_ele_t *newt;
    newt = malloc(sizeof(list_ele_t));
    /* What if malloc returned NULL? */
    if(!newt) return false;

    newt->value = v;
    newt->next = NULL;
    if(q->tail) {
      q->tail->next = newt;
      q->tail = newt;
    } else {
      q->head = newt;
      q->tail = newt;
    }
    q->size++;

    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    /* You need to fix up this code. */
    if (!q) return false;
    if(!q->head) return false;

    list_ele_t *tmph;
    tmph = q->head;
    q->head = q->head->next;
    if(!q->head) q->tail = NULL;
    if (vp) *vp = tmph->value;
    free(tmph);
    q->size--;

    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if(!q) return 0;
    return q->size;
}

/*
  Reverse elements in queue.

  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if (!q) return;
    if (!q->head) return;

    list_ele_t *curr, *prev, *tmp;
    prev = NULL;
    curr = q->head;

    // exchange head & tail ptr in queue
    tmp = q->head;
    q->head = q->tail;
    q->tail = tmp;

    // reverse elems
    while (curr)
    {
      tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
    }
}

