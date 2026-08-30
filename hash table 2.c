#include <stdio.h>

#define SIZE 10

struct HashTable
{
    int key;
    int frequency;
};

struct HashTable table[SIZE];

void initialize()
{
    int i;

    for(i = 0; i < SIZE; i++)
    {
        table[i].key = -1;
        table[i].frequency = 0;
    }
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashFunction(key);

    while(table[index].key != -1 && table[index].key != key)
    {
        index = (index + 1) % SIZE;
    }

    if(table[index].key == key)
    {
        table[index].frequency++;
    }
    else
    {
        table[index].key = key;
        table[index].frequency = 1;
    }
}

void display()
{
    int i;

    printf("\nFrequency of each element:\n");

    for(i = 0; i < SIZE; i++)
    {
        if(table[i].key != -1)
        {
            printf("%d -> %d\n",
                   table[i].key,
                   table[i].frequency);
        }
    }
}

int main()
{
    int n, i;
    int a[100];

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }

    display();

    return 0;
}
