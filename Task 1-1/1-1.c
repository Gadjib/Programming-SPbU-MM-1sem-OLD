#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* a, int* b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

bool test1(){
	int a = 10;
	int b = 20;
	
	swap(&a, &b);

	if (a == 20 && b == 10){
		return true;
	} else {
		return false;
	}
}

bool test2(){
	int a = 20;
	int b = 20;
	
	swap(&a, &b);

	if (a == 20 && b == 20){
		return true;
	} else {
		return false;
	}
}

bool test3(){
	int a = 0;
	int b = 20;
	
	swap(&a, &b);

	if (a == 20 && b == 0){
		return true;
	} else {
		return false;
	}
}

bool test4(){
	int a = 0;
	int b = 0;
	
	swap(&a, &b);

	if (a == 0 && b == 0){
		return true;
	} else {
		return false;
	}
}

int main(){
	int a, b;
	//scanf("%d", &a);
	//scanf("%d", &b);

	if (test1() && test2() && test3() && test4()){
		printf("Tests passed\n");
	} else {
		printf("Tests failed\n");
	}

	//printf("%i\n", a);
	//printf("%i\n", b);
}