#include <stdio.h>
#include <stdlib.h>
#define heightRight(bst,b) (((bst)>(b))?(bst):(b))

int getHeight(int bst[], int, int);

int main(void) {
    short testCases;
    scanf("%hi", &testCases);
    while(testCases--){
        short nodes;
        scanf("%hi", &nodes);
        int bst[nodes], index = 0, isAVL = 1;
        for(index = 0; index < nodes; index++){
            scanf("%d", &bst[index]);
        }
        for(int index = 1; index < nodes/2; index += 2){
            int heightLeft = getHeight(bst, index, nodes);
            int heightRight = getHeight(bst, index + 1, nodes);
            if(abs(heightRight - heightLeft) > 1){
                isAVL = 0;
                break;
            }
        }
        isAVL ? printf("T\n") : printf("F\n");
    }
    return 0;
}

int getHeight(int bst[], int index, int nodes) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    if(rightChild < nodes)
        return bst[index] == -1 ? 0 : 1 +
            heightRight(getHeight(bst, rightChild, nodes), getHeight(bst, leftChild, nodes));

    if(leftChild < nodes)
        return bst[index] == -1 ? 0 : 1 + getHeight(bst, leftChild, nodes);

    return bst[index] == -1 ? 0 : 1;
}
