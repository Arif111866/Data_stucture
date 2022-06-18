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
const int mx = 100 ;
float stk[mx] ;
int stacksize =0 ;
void push(float value){
    if(stacksize == mx){
        cout << "Stack Overflow !\n" ;
        return ;
    }
    stk[stacksize] = value ;
    stacksize++ ;
    return ;
}
float pop() {
    if(stacksize == 0){
        cout << "StackUnderFlow !" << endl ;
    }
    stacksize--;
    return stk[stacksize] ;
}


void display(){
    int n = stacksize ;
    while(stacksize){
        stacksize-- ;
        cout<< stk[stacksize]<<" " ;
    }
    cout << endl ;
    stacksize = n ;
}

    
// evalution ..........

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

    for(int i =0 ; i < stck.size() ; i++){

        if(stck[i][0] == '+' || stck[i][0] == '-' || stck[i][0] == '*' || stck[i][0] == '/' || stck[i][0] == '^'){
            float a = pop() ;
            float b = pop() ;
            if(stck[i][0] == '+')
            {
                float value = b+a ;
                push(value) ;
            }
            else if(stck[i][0] == '-')
            {
                float value = b-a ;
                push(value) ;
            }
            else if(stck[i][0] == '*')
            {
                float value = b*a ;
                push(value) ;   
            }
            else if(stck[i][0] == '/')
            {
                float value = b/a ;
                push(value) ;
            }
            else if(stck[i][0] == '^'){
               float value = pow(b,a) ;
            }
        } 

        else{

            string key = stck[i] ;
            if(stck[i][0] >='A'){
                float aa ; 
                cout << "Enter value of " << stck[i][0] << endl ;
                cin >> aa ;
                push(aa) ;
            }
            else{
            float num  ;
            stringstream ss;  
            ss << key;  
            ss >> num;
            push(num) ;
            }
        }
    }
    cout << "Value = " ;
    display() ;

    return 0;
}