#include<bits/stdc++.h>

using namespace std;

int


int tinh(int i, int pre0)
{

    if(i==n) return 1;
    int &r = f[i]{pre0};
    if(r != -1) return r;
    r = 0;
    if(pre0<L) r+= tinh(i+1, pre0+1);
    r+= tinh(i+1,0);
    r = min(r,oo);
    return r;
}
int k;
void lankq(int i, int pre0){
if(i==n) return;
if(pre0 < L)
if(tinh(i+1,pre0+1) < k){
    k -= tinh(i+1,pre0);
}
else {
    cout << 0 << " ";
    lankq(i=1,pre0 =1 );
    return ;
}
    cout << 1 << " ";
    lankq(i+1,0);
}
int main(){

return 0;
}
