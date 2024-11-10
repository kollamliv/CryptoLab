#include<stdio.h>
#include<ctype.h>
int main()
{
int i,j,k;
int cvector[3],pvector[3],keys[3][3];
char key[10],message[3];
printf("Enter a 9 letter key");
scanf("%9s",key);
k=0;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
keys[i][j]=toupper(key[k])-'A';
k++;
}
}
printf("Enter a message of 3 letetr ");
scanf("%3s",message);
for(i=0;i<3;i++)
{
pvector[i]=toupper(message[i])-'A';
}
for(i=0;i<3;i++)
{cvector[i]=0;
for(j=0;j<3;j++)
{
cvector[i]+=keys[i][j]*pvector[j];
}
cvector[i]%=26;
}
printf("The cipher text is :");
for(i=0;i<3;i++)
{
printf("%c",(char)(cvector[i])+'A');
}
}