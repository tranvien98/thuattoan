#include<bits/stdc++.h>
using namespace std;
int n,w;
int a[20];
int sum;
int Try(int i){
    int weigh = w + a[i];
    int sum = 0;
    while(sum < weigh){
        sum += a[i];
    }
}
int main(){
    int sum = 0;
    int dem = 0;
    cin >> n >> M;
    for(int i=0;i<n;i++){
        cin >> a[i] ;
        sum += a[i];
    }


    return 0;
}
