#include <stdio.h>
#include <string.h>
#define MAX_TEXT_LENGTH 100
#define MAX_PATTERN_LENGTH 10
#define ALPHABET_SIZE 128

int horspool(char text[], int textLength, char pattern[], int patternLength) 
{
    	int shiftTable[ALPHABET_SIZE];
    	int i, j;
    	for (i = 0; i < ALPHABET_SIZE; i++)
{
        		shiftTable[i] = patternLength;
    	}
for (i = 0; i < patternLength - 1; i++) 
{
        		shiftTable[int(pattern[i])] = patternLength - 1 - i;
    	}
i = patternLength - 1;
   	while (i < textLength)
{
       		 j = 0;
        		while (j < patternLength && text[i - j] == pattern[patternLength - 1 - j]) 
{
            			j++;
        		}
        		if (j == patternLength) 
{
            			return i - patternLength + 1; 
        		}
        		i += shiftTable[int(text[i])];
    	}
return -1; // Pattern not found
}
int main() 
{
    	char text[MAX_TEXT_LENGTH];
    	char pattern[MAX_PATTERN_LENGTH];
    	int textLength, patternLength;
    	int matchIndex;
printf("Enter the text: ");
    	fgets(text, sizeof(text), stdin);
    	textLength = strlen(text);
    	if (text[textLength - 1] == '\n')
{
        		text[textLength - 1] = '\0'; 
        		textLength--;
    	}
    	printf("Enter the pattern: ");
    	fgets(pattern, sizeof(pattern), stdin);
    	patternLength = strlen(pattern);
    	if (pattern[patternLength - 1] == '\n')
{
        		pattern[patternLength - 1] = '\0'; 
        		patternLength--;
    	}
matchIndex = horspool(text, textLength, pattern, patternLength);
    	if (matchIndex != -1) 
{
       		printf("Pattern found at index %d\n", matchIndex);
    	} 
else 
{
        		printf("Pattern not found\n");
    	}
return 0;
}
