#include<bits/stdc++.h>
#include <sstream>
using namespace std ;

const int mx =100 ;
string expression = "( " ;
map<string , int > mp ;
string stak = "" ;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w",stdout);
    #endif 

    mp["+"] = 1 ;
    mp["-"] = 2 ;
    mp["*"] = 3 ;
    mp["/"] = 4 ;
    mp["^"] = 5 ;

    string s ;
    getline(cin , s) ;
    s += " )" ;

    stringstream linestream(s) ;
    string ward ;
    bool bol = true ;
    while(linestream >> ward){
        if(mp[ward]){
            
        }
        else {
            
        }
    }

    cout << stak << endl ;
  

    return 0;

}