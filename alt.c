#include <stdio.h>
#include <string.h>

int main(void){
    short testCases;
    scanf("%hi", &testCases);
    while(testCases--){ 
        short nodes;
        scanf("%hi", &nodes);
        int bst[nodes], index = 0, counter = 0;
        //insert node values in array at 'index'
        for(index = 0; index < nodes; index++){
            scanf("%d", &bst[index]);
        }
        //search for -1's (nulls) in array, and increment 'counter'
        for(index = 0; index < nodes; index++){
            if (bst[index] == -1)
                counter++;
        }
        //check if bst is an avl tree
        (nodes % 4 < counter) ? printf("F\n") : printf("T\n");
        memset(bst, 0, sizeof(int) * nodes);
    }
    return 0;
}
