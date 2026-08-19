#include <stdio.h>

void moveDisk(char from, char to, int disk)
{
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

int main()
{
    int n, i;
    char source = 'A', auxiliary = 'B', destination = 'C';
    char temp;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        temp = destination;
        destination = auxiliary;
        auxiliary = temp;
    }

    int totalMoves = (1 << n) - 1;

    for (i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
            moveDisk(source, destination, 1);
        else if (i % 3 == 2)
            moveDisk(source, auxiliary, 2);
        else
            moveDisk(auxiliary, destination, 1);
    }

    return 0;
}
