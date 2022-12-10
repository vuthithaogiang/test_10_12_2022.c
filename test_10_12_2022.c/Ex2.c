
#include<stdio.h>
#include<stdlib.h>

#define SIZE 20


void getInterest(float* interest, int size, float capital, float rate);

void showInterest(float* interest, int size);

void calculateSum(float* interest, int size, float* sum, int *sizeOfSum, float capitalSum);

void showResult(float* interest, float* sum, int size);

int main() {
	float capitalSum; 
	float rate;
	int numberOfYear;
	printf("\nEnter capital sum: ");
	scanf("%f", &capitalSum);

	printf("\nEnter rate of interest: ");
	scanf("%f", &rate);

	printf("\nEnyter number of year: ");
	scanf("%d", &numberOfYear);

	if (numberOfYear > 0) {

		float* interestCaculation = (float*)malloc(numberOfYear * sizeof(float));

		float* sum = (float*)malloc(numberOfYear * sizeof(float));

		getInterest(interestCaculation, numberOfYear, capitalSum, rate);

		showInterest(interestCaculation, numberOfYear);

		int sizeOfSum = 0;

		calculateSum(interestCaculation, numberOfYear, sum, &sizeOfSum, capitalSum);

		
		showResult(interestCaculation, sum, numberOfYear);

	}
	else {

		printf("\nPlease enter number of year > 0!");
	}


	puts(" ");

	

	return 0;
}

void getInterest(float* interest, int size, float capital, float rate) {
	float sum = capital;
	for (int i = 0; i < size; i++) {

		interest[i] = sum * rate / 100;
		sum += interest[i];

	}
	puts(" ");
}

void showInterest(float* interest, int size) {

	printf("\n%-10s%-20s\n", "Year", "Interes");

	for (int i = 0; i < size; i++) {

		printf("%-10d%-20.4f\n", i + 1, interest[i]);

	}
}

void calculateSum(float* interest, int size, float* sum, int* sizeOfSum, float capitalSum) {

	float caculateSum = capitalSum;
	

	for (int i = 0; i < size; i++) {

		caculateSum += interest[i];

		sum[(*sizeOfSum)++] = caculateSum;
		
	}
}


void showResult(float* interest, float* sum, int size) {

	printf("\n%-10s%-20s%-20s\n", "Year", "Interest", "Sum");

	for (int i = 0; i < size; i++) {
		printf("%-10d%-20.4f%-20.4f\n", i + 1, interest[i], sum[i]);

	}
	puts(" ");
}
