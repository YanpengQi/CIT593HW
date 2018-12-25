#include <stdio.h>

int main () {
	char name[100];
	double hw1, hw2, hw3, hw4, midterm, final; 

	printf("Welcome to CIT 593\n");

	printf("Please enter your name, you hw1,hw2,hw3,hw4 scores(out of 100) and\n");
	printf("your midterm grade, your expected final exam grade:\n");

	scanf("%s %lf %lf %lf %lf %lf %lf", name, &hw1, &hw2, &hw3, &hw4, &midterm, &final);

	double hw_ave = (hw1 + hw2 + hw3 + hw4) / 4;
	double final_ave = hw_ave * 0.6 + midterm * 0.2 + final * 0.2;

	printf("Name: %s\n", name);
	printf("\tHW Average\t\t: %.2lf%%\n", hw_ave);
	printf("\tMidterm Grade\t\t: %.2lf%%\n", midterm);
	printf("\tFinal Exam Grade\t: %.2lf%%\n", final);
	printf("\tFinal Average\t\t: %.2lf%%\n", final_ave);
	return 0;
}