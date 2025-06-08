#include <string.h>

// Remove newline character from string
void removeNewLine(char *string) {
	string[strlen(string)-1] = '\0';
}
