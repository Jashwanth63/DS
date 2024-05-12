#include <iostream>

using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node() : val(0), next(NULL) {}
        Node(int val) : val(val),  next(NULL) {}
        Node(int val, Node* next) : val(val), next(next) {}
};


class MyLinkedList {
public:
    int length;
    Node* head;
    Node* tail;
    MyLinkedList(): length(0) {
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        if(length == 0 || index+1 > length){
            return -1;
        }
        if(index+1 == length){ //For tail
            return tail->val;
        }
        Node* temp = head;
        while(index--){ // For head and Middle
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* node=  new Node(val);
        if(!head){
            head = node;
            tail = node;
        }
        else{
            node->next = head;
            head = node;
        }
        length++;
    }
    
    void addAtTail(int val) {
        Node* node=  new Node(val);
        if(!tail){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if(index == length){ // Add at tail if index is equal to length
            addAtTail(val);
            return;
        }
        else if(index>length){
            return;
        }
        else{
            Node* temp = head;
            if(index == 0){
                addAtHead(val);
                return;
            }
            Node* node = new Node(val);
            for(int i=0; i<index-1; i++){
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
            length++;
        }  
    }
    
    void deleteAtIndex(int index) {
        Node* temp = head;
        if(index<=(length-1)){
            if(index == 0){
                head = temp->next;
                delete temp;
                length--;
                return;
            }
            Node* prev = temp;
            for(int i=0; i<index; i++){
                prev = temp;
                temp =  temp->next;
            }
            if(temp == tail){
               prev->next = temp->next;
               tail = prev;
               length--;
               return; 
            }
            prev->next = temp->next;
            delete temp;
            length--;
        }
    }
};


void display(Node* head){
    cout<<endl;
    while(head){
        cout<<head->val<<"->";
        head = head->next;
    }
}

 // Your MyLinkedList object will be instantiated and called as such:
 int main(){
    MyLinkedList* obj = new MyLinkedList();
    
     obj->addAtHead(1);
     obj->addAtTail(3);
     Node* head = obj->head;
     display(head);
     cout<< obj->get(2);
     obj->addAtIndex(1,2);
     display(head);
     obj->deleteAtIndex(2);
     display(head);
     return 0;
 }
 
 