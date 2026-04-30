#include <stdio.h>
#include <string.h>

#define SIZE 10

char buffer[SIZE];
int head = 0;
int tail = 0;
int count = 0;

// تحقق من الفراغ
int isEmpty() {
    return (count == 0);
}

// تحقق من الامتلاء
int isFull() {
    return (count == SIZE);
}

// إدخال عنصر
void enqueue(char c) {
    if (isFull()) {
        printf("Buffer Overflow! Skipping '%c'\n", c);
        return;
    }

    buffer[tail] = c;
    tail = (tail + 1) % SIZE;
    count++;
}

// إزالة عنصر
char dequeue() {
    if (isEmpty()) {
        return '\0';
    }

    char val = buffer[head];
    head = (head + 1) % SIZE;
    count--;

    return val;
}

int main() {
    char name[100];
    char text[120];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    strcpy(text, name);
    strcat(text, " CE-ESY");

    printf("\nStored Text: %s\n", text);
    printf("Buffer Capacity: %d\n\n", SIZE);

    printf("Writing...\n");
    for (int i = 0; i < strlen(text); i++) {
        enqueue(text[i]);
    }

    printf("\nReading...\nResult: ");
    while (!isEmpty()) {
        printf("%c", dequeue());
    }

    printf("\n");

    return 0;
}        return '\0';
    }

    char val = buffer[head];
    head = (head + 1) % SIZE;
    count--;

    return val;
}

int main() {
    char name[100];
    char text[120];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    strcpy(text, name);
    strcat(text, " CE-ESY");

    printf("\nStored Text: %s\n", text);
    printf("Buffer Capacity: %d\n\n", SIZE);

    printf("Writing...\n");
    for (int i = 0; i < strlen(text); i++) {
        enqueue(text[i]);
    }

    printf("\nReading...\nResult: ");
    while (!isEmpty()) {
        printf("%c", dequeue());
    }

    printf("\n");

    return 0;
}
