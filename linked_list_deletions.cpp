
#include <iostream>
using namespace std;

class Node{
    public :
     int data ;
     Node*next ;
     
     Node (int data1 ){
        data = data1;
        next = NULL;
     }
};
//deletion of head from linked list
Node*delete_head (Node*head){
    if ( head == NULL) return NULL;
    Node*temp = head ;
    head = head->next ;
    delete temp ;
    return head ;
}
//deletion of the tail node from linked list
Node*delete_tail (Node*head){
    if ( head == NULL || head->next == NULL) return NULL ;
    Node*temp = head;
    while( temp->next->next != NULL){
        temp = temp->next;
    }
delete temp->next;
temp->next = nullptr;
return head ;
}
//delete any node from linked list
Node*delete_kth (Node*head , int k){
    if (head == NULL) return NULL;
    if (k==1){
        // call delete head function
        delete_head ;
    }
    int count = 0;
    Node*temp = head;
    Node*prev = NULL;
    while(temp != NULL){
        count++;
        if (count == k){
            prev->next = prev->next->next;
            delete (temp);
            break;
        }
        prev = temp ;
        temp = temp->next;
    }
    return head;
}
void print_linked_list(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main(){
     Node*head = new Node(10);
    head->next = new Node(40);
    head->next->next = new Node(20);
    head->next->next->next = new Node(50);
    head->next->next->next->next = new Node(30);

    delete_kth(head , 2);
    print_linked_list(head);
    return 0;
    
}


