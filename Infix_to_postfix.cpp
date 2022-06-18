#include<bits/stdc++.h>
#include <sstream>
#define        pb push_back 
#define        INF 1e9
using namespace std;



int presidence(char c) {
    if(c == '^') {
        return 3;
    }
    else if(c == '*' || c == '/') {
        return 2;
    }
    else if(c == '+' || c =='-') {
        return 1;
    }
    else {
        return -1;
    }
}


// infix to postfix ;



int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w",stdout);
    #endif 

    string s ;
    cin >> s ;
    s += ")" ;
    int ans =0 ;
    vector<string> stck ;
    string opt = "(";
    for(int i =0 ; i<s.length() ; i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
            int a = presidence(s[i]) ;
            int j = opt.size()-1 ;
            while(j>=0){
                int b = presidence(opt[j]) ;
                if(a<=b){
                    stck.pb(string (1,opt[j])) ;
                    opt.erase(opt.begin()+j) ;
                    j-- ;
                }
                else{
                    opt += s[i] ; break ;
                }
            }

        }                     
        else if(s[i] == ')' || s[i] == '('){

            if(s[i] == '(')
            {
                opt += "(" ;
            }
            else{
                int j = opt.size()-1 ;

                while(j>=0){
                    if(opt[j] == '('){
                        opt.erase(opt.begin()+j) ;
                        j-- ; break ;
                    }
                   else{
                    stck.pb(string (1,opt[j])) ;
                    opt.erase(opt.begin()+j) ;
                    j-- ;
                   }

                }

            }
        }
        else{
            string key = "";
            while(i<s.length()){
                 if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^'){
                    i-- ;break ;
                }                     
                else if(s[i] == ')' || s[i] == '('){
                    i-- ;break;
                }
                else
                {
                    key = key+s[i] ;
                    i++ ;
                }
            }
            stck.pb(key) ;
        }

    }


    cout << "PostFix = " ;
    for(auto it : stck) cout << it ;
    cout << endl ;

    // infix to postfix shesh 
    return 0;
}