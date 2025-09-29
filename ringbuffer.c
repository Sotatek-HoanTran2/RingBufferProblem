#include <stdio.h>
#include "ringbuffer.h"

#define MAX_SIZE 100
static int buffer[MAX_SIZE];
static int capacity = 0; 
static int head = 0;
static int tail = 0;
static int count = 0;

//khởi tạo
void ringbuffer_init(int size) {
    if (size > MAX_SIZE) size = MAX_SIZE;
    capacity = size;
    head = 0;
    tail = 0;
    count = 0;
}

//thêm
int ringbuffer_add(int value) {
    if (ringbuffer_is_full()) {
        return -1; // buffer đầy
    }
    buffer[tail] = value;
    tail = (tail + 1) % capacity;
    count++;
    return 0;
}

//xóa
int ringbuffer_remove(int *value) {
    if (ringbuffer_is_empty()) {
        return -1; // buffer rỗng
    }
    *value = buffer[head];
    head = (head + 1) % capacity;
    count--;
    return 0;
}

//check full
int ringbuffer_is_full() {
    return (count == capacity);
}

//check empty
int ringbuffer_is_empty() {
    return (count == 0);
}

//size
int ringbuffer_size() {
    return count;
}
