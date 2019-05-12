#include <stdio.h>

#include<conio.h>
int dong[8], cot[8], cheosac[15], cheohuyen[15], dem=0;

void print ()
{
int i;
printf("\n");
for (i=0; i<8; i++)
printf("\nBuoc %d: Tren dong %3d dat quan Hau o cot %d",i+1,i, dong[i]);
}

void thu(int i)
{
int j;
if (i<=7)
{	for (j=0; j<8; j++)
{
if (cot[j] == 1 && cheosac[i+j] ==1 && cheohuyen[i-j+7] == 1)
{
dong[i] = j; cot[j] = 0;
cheosac[i+j] = 0; cheohuyen[i-j+7] = 0;
thu(i+1);
cot[j] = 1; cheosac[i+j] = 1; cheohuyen[i-j+7] = 1;

}
}
}
else
{ print();dem++;
}
}

void tim()
{
int i, q;
for (i=0; i<8; i++)
{
cot[i] = 1;
dong[i] = -1;
}
for (i=0; i<15; i++)
{
cheosac[i] = 1;
cheohuyen[i] = 1;
}
thu(0);
printf("\n Tong so cach dat quan Hau: %d",dem);
}

int main()
{
tim();
getch();
return 0;
}
