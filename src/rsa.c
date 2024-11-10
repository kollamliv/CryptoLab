#include <stdio.h>
int gcd(int a, int b) {
while (b != 0) {
int temp = a % b;
a = b;
b = temp;
}
return a;
}
int find_e(int phi) {
for (int e = 2; e < phi; e++) {
if (gcd(e, phi) == 1) return e;
}
return 1;
}
int find_d(int e, int phi) {
int d = 1;
while ((e * d) % phi != 1) d++;
return d;
}
int mod_pow(int base, int exp, int mod) {
int result = 1;
for (int i = 0; i < exp; i++) result = (result * base) % mod;
return result;
}
int main() {
int p, q, M;
printf("Enter prime numbers p and q: ");
scanf("%d %d", &p, &q);
printf("Enter the number: ");
scanf("%d", &M);
int n = p * q;
int phi = (p - 1) * (q - 1);
int e = find_e(phi);
int d = find_d(e, phi);
int encrypted = mod_pow(M, e, n);
printf("Encrypted message: %d\n", encrypted);
int decrypted = mod_pow(encrypted, d, n);
printf("Decrypted message: %d\n", decrypted);
return 0;
}