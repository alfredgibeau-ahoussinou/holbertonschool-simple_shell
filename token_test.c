#include <stdio.h>
#include <string.h>
#include <time.h>

void generate_token(char* token) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;
    time_t t;
    srand((unsigned) time(&t));

    for (i = 0; i < 64; i++) {
        int key = rand() % (int) (sizeof(charset) - 1);
        token[i] = charset[key];
    }

    token[i] = '\0';
}

int main() {
    char token[65];
    generate_token(token);
    printf("Generated Token: %s\n", token);

    return 0;
}