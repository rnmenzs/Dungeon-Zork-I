#include <stdio.h>
#include <stdlib.h>

randomEvent(int num)
{
    
}

randomNum(int lower, int upper){
    int i;
    int num;

    for (i = 0; i < 1; i++){
        num = (rand() %(upper - lower + 1)) + lower;
        printf("%d ", num);
    }

    return num;
}