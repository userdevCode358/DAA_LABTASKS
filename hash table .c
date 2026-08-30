#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

void initialize()
{
    int i;

    for(i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key)
{
    if(key < 0)
        key = -key;

    return key % SIZE;
}

int search(int key)
{
    int index = hashFunction(key);
    int i = 0;

    while(i < SIZE)
    {
        int pos = (index + i) % SIZE;

        if(hashTable[pos] == -1)
            return 0;

        if(hashTable[pos] == key)
            return 1;

        i++;
    }

    return 0;
}

void insert(int key)
{
    int index = hashFunction(key);
    int i = 0;

    while(i < SIZE)
    {
        int pos = (index + i) % SIZE;

        if(hashTable[pos] == -1)
        {
            hashTable[pos] = key;
            return;
        }

        i++;
    }
}

int main()
{
    int n, T, i;
    int a[100];

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target T: ");
    scanf("%d", &T);

    for(i = 0; i < n; i++)
    {
        int needed = T - a[i];

        if(search(needed))
        {
            printf("Two elements found: %d and %d\n",
                   needed, a[i]);
            return 0;
        }

        insert(a[i]);
    }

    printf("No two elements have sum equal to %d\n", T);

    return 0;
}
