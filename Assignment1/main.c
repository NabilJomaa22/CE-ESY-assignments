#include <stdio.h>
#include <string.h>

#define SMALL_SIZE  5
#define LARGE_SIZE 50

typedef struct {
    char buffer[LARGE_SIZE]; 
    int head;
    int tail;
    int count;
    int capacity;            
} CircularBuffer;


void init(CircularBuffer *cb, int cap) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
    cb->capacity = cap;
}

int isFull(const CircularBuffer *cb) {
    return cb->count == cb->capacity;
}

int isEmpty(const CircularBuffer *cb) {
    return cb->count == 0;
}

void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Buffer Overflow\n");
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % cb->capacity;
    cb->count++;
}

char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Buffer Underflow\n");
        return '\0';
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % cb->capacity;
    cb->count--;
    return data;
}

void runTest(int cap, const char *text) {
    CircularBuffer cb;
    init(&cb, cap);

    printf("Buffer size %d: \"", cap);
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (isFull(&cb)) {
            write(&cb, text[i]);  
            break;
        }
        write(&cb, text[i]);
    }

    while (!isEmpty(&cb)) {
        putchar(read(&cb));
    }
    printf("\"  %s\n", isEmpty(&cb) ? "Empty" : "Not empty");
}

int main() {
    char name[50];
    printf("Enter your name: ");
    scanf("%49s", name);

    char combined[100];
    snprintf(combined, sizeof(combined), "%sCE-ESY", name);

    // تجربة حجمين
    runTest(SMALL_SIZE, combined);   
    runTest(LARGE_SIZE, combined);   

    return 0;
}