#include <iostream>
using namespace std ;

class Node {
    public :
    int data ;
    Node * next ;

    public :
    Node( int value){
    data = value ;
    next = nullptr ;
}
};
// solution using pointers
int Kth_largest( Node*head , int k){
    // count the number of nodes
    int count = 0;
    Node*temp = head;
    while(temp != NULL){
        count ++;
        temp= temp ->next ;
    }
    // base case
    if( k<=0 || k>count){
        cout << "Invalid" ;
        return -1 ;
    }
    //reverse sorting of node data
    for( Node*i =head ; i!=NULL ; i= i->next){
        for( Node*j = i->next ; j!=NULL ; j= j->next){
            if ( i->data > j->data){
                int tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
    //traverse to the Kth node
    temp = head;
    for( int i=1 ; i<k ; i++){
        temp = temp->next;
    }
    return temp->data;
}

int main(){
    
   Node*head = new Node(10);
    head->next = new Node(40);
    head->next->next = new Node(20);
    head->next->next->next = new Node(50);
    head->next->next->next->next = new Node(30);
    
    Kth_largest(head , 3);


}