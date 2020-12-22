#include<stddef.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<assert.h>
#include "trading.h"


Queue queue_new(uint32_t size){

    Queue qu = {size, 0, 0, 0, {NULL}};
    return qu;
}
uint8_t queue_full(Queue *q){
    assert(q != NULL);
    return (q->count == q->size);
}

uint8_t queue_empty(Queue *q){
    assert(q != NULL);
    return (q->count == 0);

}
uint32_t queue_length(Queue *q) {
    assert(q != NULL);
    return q->count;
}

Queue* queue_add(Queue *q,char share_name[], char date[], int32_t price,int32_t quantity, Queue_Result *res) {
    assert(q != NULL);
    if (q->count < q->size){
        strcpy(q->d[q->tail].share_name,share_name);
        strcpy(q->d[q->tail].date,date);
        q->d[q->tail].price = price;
        q->d[q->tail].quantity = quantity;
        q->tail = (q->tail + 1) % q->size;
        ++q->count;
        res->status = QUEUE_OK;
    } else {
        res->status = QUEUE_FULL;
    }

    return q;
}
Queue* queue_delete(Queue *q, QueueResult *res){
    assert( q != NULL );

    if (q->count != 0){
        res->data = q->data[q->head];
        q->head = (q->head+1)%q->size;
        --q->count;
        res->status = QUEUE_OK;
    }else{
        res->status = QUEUE_EMPTY;
    }
    return q;
}

Queue* queue_lookup(Queue *q,char share_name[])
{

}



