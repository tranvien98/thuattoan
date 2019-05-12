#include<bits/stdc++.h>

using namespace std;

int main() {
    long n, m;
    //freopen("test.txt","r",stdin);
    cin >> n >> m;
    long arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    long maxx = arr[0];
    for(int i=1;i<n;i++){
        if(maxx < arr[i])
            maxx = arr[i];
    }
    long beginn = 0;
    long endd = maxx;
    long mid = 0;
    long  h = 0;
    long cutted = 0;
    while(beginn <= endd){
        mid = (beginn+endd)/2;
        cutted = 0;
        for(int i=0;i<n;i++){
                if(arr[i]-mid>0){
                    cutted+=arr[i]-mid;
                }
        }
        if(cutted > m){
            beginn = mid + 1;
            if(mid>h){
                h=mid;
            }
        }
        else if(cutted < m){
            endd=mid-1;
        }
        else{
            h=mid;
            break;
        }
    }
    cout << h ;
    return 0;
}
