// bai 1 loco
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    //freopen("test.txt","r",stdin);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        cout << floor(log(m)/log(2)) << endl;
    }

    return 0;
}


