#include <stdio.h>
int greater(int *a, int *b) {

	if (*a > *b) {
	return *a; 
	}
	else return *b;
}

int main() {
	int fno, sno;
	printf("Enter a number : ");
	scanf("%d", &fno);
	printf("Enter another number : ");
	scanf("%d", &sno);
	int res = greater(&fno,&sno);
	printf("The greater number is : %d", res);
}
