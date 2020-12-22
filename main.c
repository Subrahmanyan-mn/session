#include <stdio.h>
#include <stdlib.h>
#include "trading.h"
#include <stdint.h>
#include <assert.h>

void test_empty() {
    Queue qu = queue_new(5);
    Queue *q = &qu;
    assert(queue_empty(q));
}
void test_add() {
    Queue qu = queue_new(5);
    Queue *q = &qu;
    QueueResult res;

    q = queue_add(q,"walmart","01-01-2020",200, 30, &res);
    q = queue_add(q,"bigbazar","01-01-2020",250, 20, &res);
    q = queue_add(q,"bigbasket","01-01-2020",150, 10, &res);
    q = queue_add(q,"byjus","01-01-2020",500, 40, &res);
    q = queue_add(q,"amazon","01-01-2020",100, 10, &res);
    assert(queue_length(q) == 5);
    assert(qu.d[0].price==120);
    assert(queue_full(q));
}


int main()
{
    test_empty();
    test_add();
    return 0;
}
