#include <iostream>
#include <cassert>
using namespace std;



struct Node{

	int val;
	Node* next;

	Node() : val(0), next(nullptr) {}
	
	Node(int x) : val(x), next(nullptr) {}

	Node(int x, Node* nextAddr) : val(x), next(nextAddr) {}
	
};


class linkedList{
	private:
	Node* head;
	int length;

	public: 
		Node* addr;
		linkedList(){
			this->head = nullptr;
			this->addr = nullptr;
			this->length = 0;
		}

		void appendNode(int val){
			Node* node = new Node();
			node->val = val;
			if(head==nullptr){
				head = node;
				addr = head;
				this->length++;
				//tail = addr;
				return;
			}
			addr->next = node;
			addr = addr->next;
			this->length++;
			//tail = addr;
			
		}

		void insertNode(int val, int pos, Node* head){
			int count=0;
			assert(pos<=length && pos>=1);	
			Node* node = new Node();
			node->val = val;
			if(pos == 1){
				node->next = head;
				this->head = node;
				this->length++;
				return;
			}

			while(count<pos-2){
				head = head->next;
				count++;
			}
			
			node->next = head->next;
			head->next = node;
			this->length++;
		}

		
		void deleteNode(int val, Node* nextAddr){

		}

		void display(Node* nextAddr){

			while(nextAddr!=nullptr){
				if(nextAddr->next == nullptr){
					cout<<nextAddr->val;	
				}
				else{
					cout<<nextAddr->val<<"->";	
				}
				nextAddr = nextAddr->next;
				
			}
		}

		Node* reverseList(Node* head){
			Node *reversed = nullptr;
			while(head!=nullptr){
				reversed = reverse(head->val, reversed);
				head = head->next;
			}
			return reversed;
		}

		protected:	
		Node* reverse(int val, Node* reversedHead){
	        
	        if(reversedHead == nullptr){
	            reversedHead = new Node(val);
	            return reversedHead;
	        }

	        Node* newNode = new Node(val, reversedHead);
	        reversedHead = newNode;

	        return reversedHead;
    	}

    	public:
		Node* getHead(){
			return this->head;
		}

		int getLength(){
			return this->length;
		}
	

};


bool checkPalindrome(Node* head, Node* tail, int length){
	int count = 0;
	bool isPalindrome = false;
	if(length == 1){
		return true;
	}

	while(count<=((length/2))){
		if(head->val == tail->val){
			count++;
		}
		else{
			return isPalindrome;
		}
		head = head->next;
		tail = tail->next;

	}	

	isPalindrome = true;
	return isPalindrome;
	
}

int main(){
	linkedList* LL = new linkedList();
	LL->appendNode(1);
	LL->appendNode(2);
	LL->appendNode(2);
	LL->appendNode(3);

	Node* tail = LL->reverseList(LL->getHead());
	//LL->insertNode(0, 1, LL->getHead()); //Indexing from 1 for pos
	//LL->insertNode(4, 5, LL->getHead());

	LL->display(LL->getHead());
	cout<<endl;
	LL->display(tail);
	cout<<endl;
	cout<<checkPalindrome(LL->getHead(), tail, LL->getLength());


	return 0;
}