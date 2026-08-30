#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void initialize()
{
    int i;

    for(i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key)
{
    int index = key % SIZE;
    int i;

    for(i = 0; i < SIZE; i++)
    {
        int newIndex = (index + i * i) % SIZE;

        if(hashTable[newIndex] == -1)
        {
            hashTable[newIndex] = key;
            return;
        }
    }

    printf("Hash table is full or insertion not possible\n");
}

void display()
{
    int i;

    printf("\nHash Table:\n");

    for(i = 0; i < SIZE; i++)
    {
        if(hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    int n, i, key;

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
