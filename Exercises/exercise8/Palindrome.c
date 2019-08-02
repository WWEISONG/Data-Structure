/*a. The pseudo algorithm
	isPalindrom(word):
		// first part is input and output
		Input: array word[0..n-1] of chars
		Output: true if word palindrom, false otherwise

		// second part is core procedure of program
		i = 0; j = n -1
		while i < j do
			if word[i] != word[j] then
				return false
			end if
			i = i + 1, j = j - 1
		end while
		return ture

b. Time complexity analysis:
	Number of iterations is n / 2
	Time complexity of body of loop O(1)
	--> total time complexity is O(n/2 * 1) = O(n)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isPalindrom(char word[], int len);

int main(int argc, char *argv[])
{
	if (argc == 2){
		if (isPalindrom(argv[1], strlen(argv[1]))){
			printf("Yes, it is\n");
		}else{
			printf("No, it is not\n");
		}
	}

	return EXIT_SUCCESS;
}

int isPalindrom(char word[], int len)
{
	int i = 0, j = len - 1, result = 1;
	while (i < j && result)
	{
		if (word[i] != word[j]){
			result = 0;
		}
		i++;
		j--;
	}
	return result;
}