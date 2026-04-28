
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 20  
typedef struct {
    char buffer[size];
    int head;  
    int tail; 
    int count; 
} CircularBuffer;


void initBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}


int writeBuffer(CircularBuffer *cb, char data) {
    if (cb->count == size) {
        return 0;  
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % size; 
    cb->count++;
    return 1;
}


int readBuffer(CircularBuffer *cb, char *data) {
    if (cb->count == 0) {
        return 0;  
    }
    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % size; 
    cb->count--;
    return 1;
}

int main() {
    CircularBuffer myBuffer;
    initBuffer(&myBuffer);

    char name[100];
    char result[150];
    char suffix[] = " CE-ESY";

    
    printf("أدخل اسمك: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; 

   
    strcpy(result, name);
    strcat(result, suffix);

   
    printf("\nيتم تخزين البيانات\n");
    for (int i = 0; i < strlen(result); i++) {
        if (!writeBuffer(&myBuffer, result[i])) {
            printf(": المخزن ممتلئ %c\n", result[i]);
            break;
        }
    }

    
    printf("النتيجة المقروءة من المخزن: ");
    char c;
    while (readBuffer(&myBuffer, &c)) {
        printf("%c", c);
    }

   
    if (myBuffer.count == 0) {
        printf("\n\nالمخزن  فارغ .\n");
    }

    return 0;
}
