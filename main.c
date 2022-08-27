#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "header.h"

int main(int argc, const char* argv[]) {
    int* arr_for_num = NULL;
    int num = 86540000;

    int num_of_num = num_convert(&arr_for_num, num);

    for (int a = 0; a < num_of_num; a++) {
        printf("arr_for_num[%d] = %d\n", a, arr_for_num[a]);
    }

    //proetection of fool===========================================
    if (num_of_num == -1) printf("protection of fool; ERROR: -1\n");
    //==============================================================

    return 0;
}