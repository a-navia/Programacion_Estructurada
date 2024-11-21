#include <stdio.h>
#include "Variable.h"

void usaUnion() {
    union Variable var;
    var.i = 81;
    printf("    var.i: %d\n", var.i);
    var.f = 9.13;
    printf("    var.f: %.2f\n", var.f);
    var.c = 'A';
    printf("    var.c: %c\n", var.c);
    printf("    var.i: %d\n", var.i);
}