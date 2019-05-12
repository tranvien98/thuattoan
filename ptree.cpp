#include<bits/stdc++.h>

using namespace std;

int plantTree(int a[],int n)
{
 int i=a[n-1];
 int k=n-2;
 int countn = 1;
 int songay = a[n-1]+1;
 while(k>=0){
    i = a[k];
    if(countn + i + 1> songay){
    songay = countn + i + 1;

    }
    countn++;
    k--;
 }

    return songay+1;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
    cin >> a[i];
    }
    sort(a,a+n);

    cout << plantTree(a,n);
    return 0;
}
