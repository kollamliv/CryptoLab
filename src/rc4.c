#include<stdio.h>
#include<string.h>
#define buff 100
int main()
{
int i,j,n,len,keylen;
char key[buff],plaintext[buff],message[buff];
unsigned char ciphertext[buff],s[256];
printf("Enter key");
scanf("%s",key);
printf("enter a message");
scanf("%s",message);
len=strlen(message);
for(i=0;i<256;i++)
{
s[i]=i;
}
for(j=i=0,keylen=strlen(key);i<256;i++)
{
j=(j+s[i]+key[i%keylen])%256;
unsigned char temp=s[i];
s[i]=s[j];
s[j]=temp;
}
for(n=i=j=0;n<len;n++)
{
i=(i+1)%256;
j=(j+s[i])%256;
unsigned char temp=s[i];
s[i]=s[j];
s[j]=temp;
ciphertext[n]=s[(s[i]+s[j])%256]^message[n];
}
ciphertext[len]='\0';
printf("cipher text (hex):");
for(i=0;i<len;i++)
{
printf("%02x",ciphertext[i]);
}for(i=0;i<256;i++)
{
s[i]=i;
}
for(j=i=0,keylen=strlen(key);i<256;i++)
{
j=(j+s[i]+key[i%keylen])%256;
unsigned char temp=s[i];
s[i]=s[j];
s[j]=temp;
}
for(n=i=j=0;n<len;n++)
{
i=(i+1)%256;
j=(j+s[i])%256;
unsigned char temp=s[i];
s[i]=s[j];
s[j]=temp;
plaintext[n]=s[(s[i]+s[j])%256]^ciphertext[n];
}
plaintext[len]='\0';
printf("Plaintext is:%s\n",plaintext);
return 0;
}