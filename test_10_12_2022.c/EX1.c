// test_10_12_2022.c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdio.h>

unsigned long long factorial(unsigned int n);

int main() {

	unsigned int number;

	printf("\nEnter number (1-100): ");
	scanf("%d", &number);

	if (number < 1 || number > 100) {
		printf("\nPlease enter value number 1 - 100.");
	}
	else {
		unsigned long long result = factorial(number);
		printf("\nFn = %llu", result);

	}

	puts(" ");
	return 0;
}

unsigned long long factorial(unsigned int n) {

	if (n < 2) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}
