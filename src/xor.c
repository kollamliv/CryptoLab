#include <stdio.h>
#include <string.h>
int main() {
char message[100];
int i, len, key;
printf("Enter a message: ");
fgets(message, sizeof(message), stdin);
message[strcspn(message, "\n")] = '\0';  
printf("Enter an integer key for XOR operation: ");
scanf("%d", &key);
len = strlen(message);
int xor[len];
for (i = 0; i < len; i++) {
xor[i] = message[i] ^ key;
}
printf("XOR-ed result:\n");
for (i = 0; i < len; i++) {
printf("%c", xor[i]);
}
return 0;
}
