#include <stdio.h>
#include <stdlib.h>

int chkprime(int num) {

	if (num <= 1) return 0;
	if (num <= 3) return 1;
	if (num % 2 == 0 || num % 3 == 0) return 0;
	for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    } return 1;
}

int main() {
	int n;
	int flag = 0;                                                        //stores the size of array
	printf("Enter the size of array : ");
	scanf("%d", &n);
	
	int *mem;															//pointer to array
	mem = (int*)malloc(n*sizeof(int));                           		//allocate memory for array 
	
	printf("Enter the elements of array : ");							//storing data in array
	for(int i=0;i<n;i++) {
		scanf("%d", &mem[i]);	
	}
	
	int sum = 0;
	for(int i=0;i<n;i++) {
		if (chkprime(mem[i])) {
			sum += mem[i];
		}
		
 }	
	printf("Sum of the elements of array is %d",sum);			//iterating through array elemnts and adding the
	
}

