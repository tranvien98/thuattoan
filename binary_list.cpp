#include<bits/stdc++.h>
using namespace std;

int n,k,i;
int flag = -1;
vector<int> x;
//x la vector luu lai ket qua
// pre la i so 0 lien tiep
// deep la do dai chuoi( do sau cua cay)
void binary(int deep, int pre)
{
    // neu do sau == n thi in ra
    if( deep == n){
        if(--k == 0){
                flag = 0;
                for(int j=0;j<n;j++){
                    cout << x[j] << " ";
                }
                exit(0);
        }
        return;
    }
    if(pre+1 < i){
        x[deep] = 0;
        binary(deep+1, pre+1);
    }

    x[deep] = 1;
    binary(deep+1, 0);
}
int main(){
    cin >> n >> k  >> i;
    // tao vec tor
    x.resize(n);
    binary(0,0);
    if(flag == -1)
    {
        cout << "-1";
    }
    return 0;
}
