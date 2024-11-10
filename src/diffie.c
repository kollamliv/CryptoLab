#include <stdio.h>
int power(int base, int expo, int mod) {
int result = 1;
for (int i = 0; i < expo; i++) {
result = (result * base) % mod;
}
return result;
}
int main() {
int prime, gpowermod, aseca, bseca;
printf("Enter a prime number: ");
scanf("%d", &prime);
printf("Enter a base (primitive root modulo %d): ", prime);
scanf("%d", &gpowermod);
printf("Enter Alice's secret key: ");
scanf("%d", &aseca);
printf("Enter Bob's secret key: ");
scanf("%d", &bseca);
int A = power(gpowermod, aseca, prime);
int B = power(gpowermod, bseca, prime);
printf("The public key of Alice is %d\n", A);
printf("The public key of Bob is %d\n", B);
int calseca = power(B, aseca, prime);
int calsecb = power(A, bseca, prime);
printf("Calculated Secret key of Alice is: %d\n", calseca);
printf("Calculated Secret key of Bob is: %d\n", calsecb);
return 0;
}
