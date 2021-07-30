#include<bits/stdc++.h>
using namespace std;

struct node{
	int a;
	node* next;
};

class link_list{
	public:
		node* head = NULL;
		void insertAtEnd(int x){
			node* new_node = new node;
			new_node->a = x;
			new_node->next = NULL;
			if(head == NULL){
				head = new_node;
				return;
			}
			node* temp =  head;
			while(temp->next){
				temp=temp->next;
			}
			temp->next = new_node;
		}
		
		int length(){
			int count =0;
			node* temp = head;
			while(temp){
				count++;
				temp= temp->next;
			}
			return count;
		}
		
		int firstEle(){
			if(head!=NULL){
				return head->a;
			}
			return -1;
		}
		int lastEle(){
			if(head!=NULL){
				node* temp = head;
				while(temp->next){
					temp=temp->next;
				}
				return temp->a;
			}
			return -1;
		}
		
		void update(link_list l2,link_list mid,link_list l3){
			node* temp1 = head;
			node* temp2 = l2.head;
			while(temp2){
				l2.head = l2.head->next;
				temp2->next = temp1->next;
				temp1->next = temp2;
				temp1 = temp2->next;
				temp2 = l2.head;
			}
			temp2 = mid.head;
			mid.head = mid.head->next;
			temp2->next = temp1->next;
			temp1->next = temp2;
			temp1 = temp2->next;
			temp2 = l3.head;
			while(temp2){
				l3.head = l3.head->next;
				temp2->next = temp1->next;
				temp1->next = temp2;
				temp1 = temp2->next;
				temp2 = l3.head;
			}
		}
		
		void print(){
			node* temp = head;
			while(temp){
				cout<<temp->a<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		void Delete(){
			
			while(head){
				node* temp = head;
				head = head->next;
				delete temp;
			}
		}
		
};

int main(){
	int n;
	cin>>n;
	link_list l1;
	for(int i=0;i<(2*n);i++){
		int x;
		cin>>x;
		l1.insertAtEnd(x);
	}
	
	link_list mid;
	int m = l1.firstEle() + l1.lastEle();
	mid.insertAtEnd(m);
	
	node* temp = l1.head;
	node* temp1 = l1.head->next;
	link_list l2,l3;
	for(int i=0; i<n-1;i++){
		int x1 =  temp->a + temp->next->next->a;
		temp = temp->next->next;
		int x2 =  temp1->a + temp1->next->next->a;
		temp1 = temp1->next->next;
		l2.insertAtEnd(x1);
		l3.insertAtEnd(x2);
	}
	l2.print();
	l3.print();
	mid.print();
	
	l1.update(l2,mid,l3);
	l1.print();
	cout<<l1.length()<<endl;
	l1.Delete();
}
