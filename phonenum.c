// 1002 Phone Numbers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int curWordN, i;
	char temp[100], callN[105];
	char *words[50000];
	
	char *solutions[50000];

	char convert[10][3] = {{'i', 'j', '0'}, {'a', 'b', 'c'}, {'d', 'e', 'f'},
		{'g', 'h', '0'}, {'k', 'l', '0'}, {'m', 'n', '0'}, {'p', 'r', 's'},
		{'t', 'u', 'v'}, {'w', 'x', 'y'}, {'o', 'q', 'z'}};
	

	while (1) {
		scanf("%s", callN);

		if (callN[0] == '-' && callN[1] == '1') {
			return;
		}
		
		scanf("%d", &curWordN);
		
		for (i = 0; i < curWordN; i++) { 
			scanf("%s", temp);
			words[i] = strdup(temp);
		}

		for (i = 0; i < strlen(callN); i++) {
			int curDigit = callN[i] - '0';
			char letters[3];
			letters[0] = convert[curDigit][0];
			letters[1] = convert[curDigit][1];
			letters[2] = convert[curDigit][2];
			int lengthLetters = strlen(letters);
			printf("letters for %d are %s\n", curDigit, letters);	
			
			

		}			
	}
}
