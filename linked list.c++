#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int data ;
    struct node *link ;
};
void inserting(struct node *head , int position , int data)
{
    int c= 0;
    while(head != NULL)
    {
        c++ ; 
        if(c==position)
        { 
        struct node *tem =(struct node*)malloc(sizeof(struct node)) ;
        tem-> data = data ;
        tem->link = head->link ;
        head->link = tem ; 
         break ;
        }
        head = head->link ;
    }
}
void deletion(struct node *head , int position)
{
    int c =0 ;
    while(head != NULL)
    {
        c++ ;
        if(c == position-1)
        {
            head->link = head->link->link ;
        }
        head = head->link ;
    }
}
void print(struct node *head)
{
    while(head != NULL)
    {
        cout << head->data << " " ;
        head = head->link ; 
    }
    cout << endl ;
}
int main(){

    struct node *head =(struct node*)malloc(sizeof(struct node)) ;
    struct node *prt = NULL ;
    head->data = 3 ;
    head->link = NULL ;   
    prt = head ;
    for(int i=1 ; i<5; i++)
    {
        struct node *c =(struct node*)malloc(sizeof(struct node)) ;
        c->data = i+3 ;
        c->link = NULL ;
        head->link = c ;
        head = head->link ;
    }
    head = prt ;
    print(head) ;
    inserting(head , 2 , 0) ;
    print(head) ;
    deletion(head , 2) ;
    print(head) ;
}   
