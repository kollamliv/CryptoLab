#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100
int main()
{
int i,len,pi,ci;
char ct[max],pt[max],message[max];
int key;
printf("Enter  a message ");
scanf("%s",message);
printf("Enter a key");
scanf("%d",&key);
len=0;
for(i=0;message[i]!='\0';i++)
{
if(isalpha(message[i]))
{
pt[len++]=(char)toupper(message[i]);
}
}
pt[len]='\0';
for(i=0;i<len;i++)
{
pi=pt[i]-'A';
ci=(pi+key)%26;
ct[i]=(char)ci+'A';
}
ct[len]='\0';
printf("The ecrypted message is %s",ct);
}