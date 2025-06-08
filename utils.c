#include <string.h>

// Remove newline character from string
void removeNewLine(char *string) {
	string[strlen(string)-1] = '\0';
}

void parsingString(char **string, char *seperator, int colum) {
	char *temp = strtok(*string, seperator);
	for(int x = 1; x < colum; x++) {
		temp = strtok(NULL, seperator);
	}
	*string = temp;
}
