
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

static int queue[MAX], head = -1, tail = -1;

int full() {
    return ((tail + 1) % MAX) == head;
}


int empty() {
    return (head == -1) && (tail == -1) ;
}


void enqueue(int v) {

    if(full()) return;
    
    if(empty()) {
        head = 0;
        tail = 0;
    }
    
    queue[tail] = v;
    tail = (tail + 1) % MAX;
}


int dequeue() {
    int t;
    
    if(empty()) return;

    t = queue[head];
    
    if(head == tail) {
        head = -1;
        tail = -1;
    }
    else {
        head = (head + 1) % MAX;
    }

    return t;
}

int main() {
    int i, x;
    for(i = 0; i < MAX; i++) {
        enqueue(i);
    }

    printf(" %d", full());

    for(i = 0; i < MAX; i++) {
        x = dequeue();
        printf(" %d", x);
    }

    printf(" %d", empty());

    return 0;
}