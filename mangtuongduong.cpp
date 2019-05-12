
#include<bits/stdc++.h>
// mangtuongduong
using namespace std;
bool areSimilar(vector<int> a,vector<int> b) {
    int lena=a.size();
    int lenb=b.size();
    if(lena!=lenb) return false;
    std::vector<int> res;
    for(int i=0;i<lena;i++)
        res.push_back(a[i]-b[i]);
    int count=0;
    int tmp=0;
    int j;
     for(int i=0;i<lena;i++){
        if(res[i]!=0){
            tmp = res[i];
            break;
            j=i;
        }
    }
      for(int i=j+1;i<lena;i++){
        if(res[i]!=0 ){
            if(res[i]!=(-tmp))
                return false;
        }
    }
    for(int i=0;i<lena;i++){
        if(res[i]!=0){
            count++;
            
        }
    }
    if(count == 2 || count == 0) return true;
    return false;
}
int main(){
	
}