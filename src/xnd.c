#include <stdio.h>
#include <string.h>
int main() {
char msg[100];
int key, len;
printf("Enter a string: ");
fgets(msg, sizeof(msg), stdin);
msg[strcspn(msg, "\n")] = '\0';
printf("Enter an integer key (e.g., 127): ");
scanf("%d", &key);
len = strlen(msg);
int x_r[len], a_r[len];
for (int i = 0; i < len; i++) {
x_r[i] = msg[i] ^ key;
a_r[i] = msg[i] & key;
}
printf("Original string: %s\n", msg);
printf("XOR with %d results:\n", key);
for (int i = 0; i < len; i++) {
printf("%d ", x_r[i]);
}
printf("\nAND with %d results:\n", key);
for (int i = 0; i < len; i++) {
printf("%d ", a_r[i]);
}
return 0;
}
