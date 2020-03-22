#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *next;
};

node* push(node* head, int data){
    node* nw = new node();

    nw->data = data;
    nw->next = head;
    return head = nw;
}
void print(node* cur){
    //if(cur==NULL)cout<<"hel\n";
    while(cur!=NULL){
        cout<<(cur->data)<<" ";
        cur = cur->next;
        //cout<<"a";
    }
    cout<<"\n";
}
int main(){
    node *head;
    head=NULL;
    int n; cin>>n;
    int data;
    for(int i=0; i<n; i++){
        cin>>data;
        head = push(head,data);
    }
    print(head);
}