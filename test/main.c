#include <stdio.h>
#include "mathutil.h"

int main(void) {
    printf("2 + 3 = %f\n", mu_add(2,3));
    printf("10 / 4 = %f\n", mu_div(10,4));
    return 0;
}
