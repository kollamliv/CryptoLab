#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#define buff 100
int main() {
int i, ci, pi, len = 0, k;
char key[buff], message[buff], ct[buff], pt[buff];
printf("Enter the plaintext message:\n");
fgets(message, buff, stdin);
message[strcspn(message, "\n")] = '\0';
printf("Enter the key (same length as the message):\n");
fgets(key, buff, stdin);
key[strcspn(key, "\n")] = '\0';
if (strlen(key) != strlen(message)) {
printf("Error: The key length must be the same as the plaintext message.\n");
return 1;
}
srand(time(0));
for (i = 0; message[i] != '\0'; i++) {
if (isalpha(message[i])) {
pt[len++] = (char)toupper(message[i]);
}
}
pt[len] = '\0';
for (i = 0; i < len; i++) {
if (!isalpha(key[i])) {
printf("Error: Key must contain only alphabetic characters.\n");
return 1;
}
key[i] = toupper(key[i]);
}
for (i = 0; i < len; i++) {
pi = pt[i] - 'A';
k = key[i] - 'A';
ci = pi ^ k;
ct[i] = (char)(ci + 'A');
}
ct[len] = '\0';
printf("The ciphertext is: %s\n", ct);
printf("The key is: %s\n", key);
return 0;
}
