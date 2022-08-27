#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include "header.h"

int num_convert(int** arr_for_num, int num) {

	//exception=====================================
	if (num == 0) {
		*arr_for_num = malloc(sizeof(*arr_for_num));
		arr_for_num[0][0] = 0;
		return 1;
	}
	//==============================================

	//how many char is in the number
	int iter = 0;
	int var = num;

	while (var >= 1) {
		var = (int)var / 10;
		iter++;
	}

	if (iter > 8) return -1;//protection of fool
	//==============================

	//set num for opperation==========
	int opp = 0;
	{
		if (iter == 1) opp = 1;
		if (iter == 2) opp = 10;
		if (iter == 3) opp = 100;
		if (iter == 4) opp = 1000;
		if (iter == 5) opp = 10000;
		if (iter == 6) opp = 100000;
		if (iter == 7) opp = 1000000;
		if (iter == 8) opp = 10000000;
	}
	//================================

	//separate char==========================================
	{
		*arr_for_num = malloc(sizeof(*arr_for_num) * iter);//allocate	memory for array

		int i = 0;//incrementable variable
		int opperation = opp;//decrementable variable(/10)
		int new_num = num;//num copy
		int num_to_arr = 0;//current char to arr from number

		while (i < iter) {
			num_to_arr = (int)(new_num / opperation);
			*((*arr_for_num) + i) = num_to_arr;

			new_num = new_num - (arr_for_num[0][i] * opperation);
			num = new_num;

			opperation /= 10;

			i++;
		}
	}
	//=========================================================

	return iter;
}
