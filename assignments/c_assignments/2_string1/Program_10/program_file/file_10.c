/*
	Name: Reverse string
	Author: Avinash N
	Date: 19 November 2016
	Description: This program will reverse the given source string
			and returns the new reversed string.
*/

#include<stdio.h>
#include<stdlib.h>
#include "mystring.h"

#define MAX_STRING_LENGTH 128

int main()
{
	char *src_str;
	char *rev_str;

	src_str = (char *) malloc(MAX_STRING_LENGTH);
	rev_str = (char *) malloc(MAX_STRING_LENGTH);

	printf("Enter the string:\n");
	fgets(src_str, MAX_STRING_LENGTH, stdin);

	if ((!(str_cmp(rev_str, src_str)))) {
		printf("Entered string is palindrome\n");
	} else {
		printf("Entered string is not palindrome\n");
	}

	free(src_str);
	free(rev_str);

	return 0;
}
