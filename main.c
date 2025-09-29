#include <stdio.h>
#include "ringbuffer.h"

int main(void) {
    ringbuffer_init(5); 

    ringbuffer_add(10);
    ringbuffer_add(20);
    ringbuffer_add(30);

    printf("size = %d\n", ringbuffer_size()); // 3

    int v;
    if (ringbuffer_remove(&v) == 0) {
        printf("removed %d\n", v); // 10
    }

    printf("size = %d\n", ringbuffer_size()); // 2
    return 0;
}
