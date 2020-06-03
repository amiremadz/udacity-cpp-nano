#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*)malloc(sizeof(int));
    printf("address=%p, value=%d\n", p, *p);

    return 0;
}
