#include<bits/stdc++.h>
// kiem tra xau
using namespace std;
int check(string str){
        stack <char> S;
        int len = str.length();
        for(int j=0;j<len;j++){
            if(str[j]=='{'||str[j]=='['||str[j]=='('){
                S.push(str[j]);
            }
            else if(str[j] == ')'){
                if(S.empty())
                {
                   return 0;
                }
                else if(S.top() == '('){
                            S.pop();
                        }
                else return 0;
            }
            else if(str[j] == ']'){
                if(S.empty()){
                    return 0;
                }
                else if(S.top() == '[')
                {
                    S.pop();
                }
                else return 0;
                }
            else if(str[j] == '}')
            {
                    if(S.empty()){
                    return 0;
                }
                else if(S.top() == '{')
                {
                    S.pop();
                }
                else return 0;
                }

            }

        if(!S.empty()){
            return 0;
        }
        return 1;
    }
int main()
{
    int n;
    cin >> n;
    string a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
  for(int i=0;i<n;i++){
      cout << check(a[i]) << endl;
    }
}
