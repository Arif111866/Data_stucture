#include<bits/stdc++.h>
#define        e "\n"
using namespace std ;
const int nl = -999999 ; 
const int mx = 1e4 ;
int arr[mx+1] ;

void insertion(int value){
	int cnode = 1 ;
	while(true){
		if(arr[cnode] == nl){ arr[cnode] = value ; return ;}
		if(arr[cnode]>value){
			cnode = 2*cnode ;
		}else{
			cnode =(2*cnode)+1 ;
		}
	}
}
int search_value(int value ){
	int cnode = 1 ;
	while(true){
		if(arr[cnode] == nl) break ;
		if(arr[cnode] == value){ return cnode ;}
		if(arr[cnode]>value){
			cnode = 2*cnode ;
		}else{
			cnode =(2*cnode)+1 ;
		}
	}
	return nl ;
}

void mem(){
	for(int i =0 ; i<= mx ; i++) arr[i] = nl ;
}
void display(int size)
{
	for(int i =0 ; i <= 4*size ; i++)
    {
    	if(arr[i] != nl) cout << i << " " << arr[i] << e ;
    }
}
void tree_display(int size){
	int  x= 1 ;
	int sp = 32 ; int b = 1 , ans = 0;
	for(int i=1 ; i<= 4*size ; i++)
	{	
		for(int k =0 ; k<sp-(b*2) ; k++) cout << " ";
		int n = x ;
		while(n)
		{
			if(arr[i] != nl ){
				cout << arr[i]<<"  " ;
				
				n--;
			} i++ ;
		}i--; x = (x*2) ; b++ ;
		cout << endl ;
		ans += x ;
		if(ans>size) return ;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r", stdin);
    //freopen("Output.txt","w",stdout);
    #endif 
    int n ;
    cin >> n ;
    mem() ;
    for(int i =0 ; i<n ; i++)
    {
    	int x ; cin >> x ;
    	insertion(x) ;
    }
    display(n) ;
    tree_display(n) ;
}
