#include<iostream>
#include<string.h>
using namespace std;
void addnum(int a[],int b[]){
int total[20] = {0};
int temp;
int carry = 0;
int dot;
for (int i=0;i<20;i++){
    temp = a[i] + b[i] + carry;
    total[i] = temp % 10;
    carry = temp / 10;
}
for(int i=19;i>=0;i--){
    if(total[i] !=0){
        dot = i;
        break;
    }
}
for(int i=dot;i>=0;i--){
    cout << total[i];
}
}
int main()
{
    char a1[20],a2[20];
    cin >> a1 >> a2;
    int b1[20] = {0};
    int b2[20] = {0};
    int len1 = strlen(a1);
    int len2 = strlen(a2);
    for (int i=len1-1;i>=0;i--)
    {
        b1[len1-i-1] = a1[i] - 48;
    }
     for (int i=len2-1;i>=0;i--)
    {
        b2[len2-i-1] = a2[i] - 48;
    }

    addnum(b1,b2);
    return 0;
}
