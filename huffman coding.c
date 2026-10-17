
#include <stdio.h>
#include <stdlib.h>

#define N 9

// Structure for a Huffman tree node
struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(char ch, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Find the index of the minimum frequency node
int findMin(struct Node* nodes[], int size) {
    int min = 0;
int i;
    for ( i = 1; i < size; i++) {
        if (nodes[i]->freq < nodes[min]->freq)
            min = i;
    }

    return min;
}

// Generate and print Huffman codes
void printCodes(struct Node* root, int code[], int top,
                long long *totalBits) {
    if (root == NULL)
        return;

    // Leaf node represents a character
    if (root->left == NULL && root->right == NULL) {
        printf("%c\t%d\t", root->ch, root->freq);
int i;
        for ( i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\t%d\n", top);

        *totalBits += (long long)root->freq * top;
        return;
    }

    // Left branch = 0
    if (root->left != NULL) {
        code[top] = 0;
        printCodes(root->left, code, top + 1, totalBits);
    }

    // Right branch = 1
    if (root->right != NULL) {
        code[top] = 1;
        printCodes(root->right, code, top + 1, totalBits);
    }
}

// Build the Huffman tree using the greedy approach
struct Node* buildHuffman(char letters[], int freq[], int n) {
    struct Node* nodes[2 * N];
    int size = n;
int i;
    for ( i = 0; i < n; i++)
        nodes[i] = createNode(letters[i], freq[i]);

    while (size > 1) {
        // Find two nodes with minimum frequencies
        int i = findMin(nodes, size);
        struct Node* left = nodes[i];

        nodes[i] = nodes[size - 1];
        size--;

        int j = findMin(nodes, size);
        struct Node* right = nodes[j];

        nodes[j] = nodes[size - 1];
        size--;

        // Combine the two minimum nodes
        struct Node* parent =
            createNode('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        nodes[size++] = parent;
    }

    return nodes[0];
}

int main(void) {
    char letters[N] = {'a', 'c', 'd', 'e', 'o',
                       'm', 's', 't', 'u'};

    int freq[N] = {20, 11, 2, 10, 15, 8, 10, 22, 2};

    int code[100];
    long long totalBits = 0;

    struct Node* root = buildHuffman(letters, freq, N);

    printf("Letter\tFreq\tCode\tLength\n");
    printf("--------------------------------\n");

    printCodes(root, code, 0, &totalBits);

    // Frequencies are in hundreds
    totalBits *= 100;

    printf("--------------------------------\n");
    printf("Total characters = 10000\n");
    printf("Total bits       = %lld\n", totalBits);
    printf("Total bytes      = %lld\n", totalBits / 8);
    printf("Average bits/char = %.2f\n",
           (double)totalBits / 10000);

    return 0;
}

