#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

void reverse_string(char *str, int s, int e) 
{
	if (s > (e + 1) / 2) {
		return;
	}
	else {
		str[e - s] = str[s];
		reverse_string(str, s + 1, strlen(str) - 1);
	}
} 

int main() 
{
	char str[100]; 

	printf("Enter any string:"); 
	scanf("%s", str); 

	reverse_string(str, 0, strlen(str) - 1); 
	printf("\nReversed String is: %s", str); 
	return 0;
}