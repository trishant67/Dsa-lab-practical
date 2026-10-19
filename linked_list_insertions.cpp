#include <iostream>
using namespace std;

class node{
    public :
     int data;
     node*next;
     node( int data1 ){
        data = data1 ;
        next = NULL;
     }
};
node*insert_at_head (node*head , int value){
    node*temp = new node(value);
    temp = temp->next;
    return temp;
}
node*insert_at_tail( node*head , int value){
    if( head == NULL) return new node(value);
    node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next ;
    }
    temp->next = new node(value);
    return head;
}
void print_linked_list( node*head){
    node*temp = head ;
    while (temp!=NULL){
        cout << temp->data << endl;
        temp=temp->next;
    }
}
node*insert_at_K_position( node*head , int value , int k){
    if ( k==1) return insert_at_head(head , value);
    node*temp = head ;
    int count = 0;
    node*prev = NULL;
    while(temp!=NULL){
        count++;
        if (count == k-1){
            node*newNode = new node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
     node*head = new node(10);
    head->next = new node(40);
    head->next->next = new node(20);
    head->next->next->next = new node(50);
    head->next->next->next->next = new node(30);

    head = insert_at_K_position( head , 100 , 3);
    print_linked_list(head);
    return 0;
    
}