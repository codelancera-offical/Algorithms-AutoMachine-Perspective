#include <stdio.h>

int add(int a, int b){
    int result = a + b;
    return result;
}

int main(){
    int x = 10;
    int y = 0;
    int z = add(x, y);

    int k = x / y;

    printf("z = %d\n", z);
    printf("k = %d\n", k);

    return 0;
}