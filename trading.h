#ifndef TRADING_H_INCLUDED
#define TRADING_H_INCLUDED

#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>
#include "appconst.h"


typedef struct _queue_ Queue;
typedef struct _queueResult_ Queue_Result;
typedef struct _data_ Data;

struct _queue_
{
	int32_t size;
	int32_t count;
	int32_t head;
	int32_t tail;
    Data d[Total_shares];

};

struct _data_
{
    char share_name[25];
    char date[10];
    int32_t price;
    int32_t quantity;

};

struct _queueResult_
{
    Data data;
    int32_t status;
};


Queue queue_new (uint32_t size);
uint8_t queue_full(Queue *q);
uint8_t queue_empty(Queue *q);
Queue* queue_add(Queue *q,char name[], char date[], int32_t prize,int32_t quantity, QueueResult *res);
Queue* queue_delete(Queue *q, QueueResult *res);
uint32_t queue_length(Queue *q);




#endif // TRADING_H_INCLUDED
