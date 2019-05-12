#include<bits/stdc++.h>
// sap xep theo co so
using namespace std;
int getMax(int a[],int n){
    int mx=a[0];
for(int i=1;i<n;i++){
    if(a[i]>mx)
    {
        mx = a[i];
    }
}
return mx;
}
void countSort(int a[],int exp,int n){
    int output[n];
    int dem[10] = {0};
    for(int i=0;i<n;i++){
        dem[(a[i]/exp)%10]++;
    }
    for(int i=1;i<n;i++){
        dem[i]+=dem[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[dem[(a[i]/exp)%10]-1] = a[i];

        dem[(a[i]/exp)%10]--;
        cout << dem[(a[i]/exp)%10];
    }
    for(int i=0;i<n;i++){

        a[i] = output[i];

    }
}
void radixSort(int a[],int n){
    int mx = getMax(a,n);
    for(int exp=1;exp<mx;exp*=10){
        countSort(a,exp,n);
    }
}
int main()
{
 int n;
 cin >> n;
 int a[n];
 for(int i=0;i<n;i++){
    cin >> a[i];
 }
 radixSort(a,n);
 for(int i=0;i<n;i++){
    //cout << a[i] << " ";
 }
}
