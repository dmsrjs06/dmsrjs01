#include <stdio.h>
#define MAX 100

int main() {
    char str[MAX];
    int i = 0;
    int ch;
	
    while (i < MAX - 1) {
        ch = getchar();
        
        if (ch == EOF || ch == '\n')
            break;
            
        str[i++] = (char)ch;
    }
	
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}


	printf("%s", str);

	return 0;
}
