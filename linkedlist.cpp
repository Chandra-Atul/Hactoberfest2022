#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		
		//constructor
		
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
		
		//destructor
		~Node(){
			int value = this->data;
			//memory free
			if(this->next != NULL){
				delete next;
				this->next = NULL;
			}
		cout<<"memory free for node with data: "<<value<<endl;
		}
};


void InsertAtHead(Node* &head, int d){
	//new node create
	Node* temp = new Node(d);
	temp->next = head;
	head = temp;
}

void InsertAtTail(Node* &tail, int d){
	//create a node
	Node *temp = new Node(d);	
	tail->next = temp;
	tail = tail->next;
}

void InsertAtPosition(Node* &head, Node* &tail ,int position, int d){
	//insert at start
	if(position	== 1){
		InsertAtHead(head,d);
		return;
	}
	Node *temp = head;
	int count = 1;
	while(count<position-1){
		temp= temp->next;
		count++;
	}
	//insert at last position;
	if(temp->next == NULL){
		InsertAtTail(tail,d);
		return;
	}
		
	Node* NodeToInsert = new Node(d);
	
	NodeToInsert->next = temp->next;
	
	temp->next = NodeToInsert;
}


void deleteNode(int position, Node* &head){
	
	//deleting first or start node
	if(position == 1){
		Node *temp = head;
		head = head->next;
		//memory free of start node
		temp->next = NULL;
		delete temp;
		
	}else{
		//deleting any middle or last node
		Node *curr = head;
		Node *prev = NULL;
		
		int count = 1;
		while(count<position){
			prev = curr;
			curr = curr->next;
			count++;
		}
		
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
//	Node* temp = head;
//	int count = 1;
//	while(count != position){
//		temp = temp->next;
//		count++;
//	}
//	temp->next =
}


void print(Node* &head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";	
		temp = temp->next;
	}
	cout<<endl;
}
Node* reverse(Node* &head){

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;

}

int main(){
	
	//create a new node
	Node* node1 = new Node(10);
	
//	cout<<node1->data<<endl;
	
//	cout<<node1->next<<endl;
	
	//head pointing to node1
	Node* head = node1;
	Node* tail = node1;
	
	// print(head);
	
	/*

	
	InsertAtHead(head,12);
	
	print(head);
	
	InsertAtHead(head,15);
	print(head);
	
	*/
	
	
	InsertAtTail(tail,12);
	print(head);
	
	InsertAtTail(tail,16);
	print(head);
	
	
	InsertAtPosition(head,tail,3,22);
	print(head);
	
	InsertAtPosition(head,tail,1,57);
	print(head);
	
	// deleteNode(1,head);
	// print(head);
	
	// cout<<"head "<<head->data<<endl;
	// cout<<"tail "<<tail->data<<endl;

	Node* newHead = reverse(head);

	print(newHead);
	
	
	return 0;
}
