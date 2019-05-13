#include<bits/stdc++.h>
using namespace std;

vector <int> a;
int T,n,c;
int sloution(int x){
        int cow = 1;
        int v = a[0];
        for(int i=0;i<n;i++){
            if(a[i] - v >= x){
                cow++;
                if(cow == c)
                    return true;
                v = a[i];
            }
        }
        return false;
    }
int cowsearch(){
    int bgin = a[0];
    int ed = a[n-1];
    int mid;
    while(bgin < ed){
        mid = (bgin+ed) / 2;
        if(sloution(mid)){
            bgin = mid+1;
        }
        else{
            ed = mid;
        }
    }
    return bgin-1;
}
int main(){
    freopen("test.txt", "r", stdin);
    cin >> T;
    int k;
    while(T--){
        cin >> n >> c;
        for(int i=0;i<n;i++){
            cin >> k;
            a.push_back(k);
        }
        sort(a.begin(), a.begin()+n);
        cout << cowsearch();

    }

    return 0;
}
