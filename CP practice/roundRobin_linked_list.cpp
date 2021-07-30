#include<bits/stdc++.h>
using namespace std;

struct node{
	int id;
	int at;
	int bt;
	node *next;
};
node* head = NULL;
void insert(node* temp){
	if(head == NULL){
		head = temp;
		temp->next = head;
		return;
	}
	node *temp1 = head;
	while(temp1->next != head){
		temp1 = temp1->next;
	}
	temp->next = temp1->next;
	temp1->next = temp; 
}

void Delete(node *temp){
	if(temp == head){
		node* temp1 = head;
		while(temp1->next != head){
			temp1 = temp1->next;
		}
		if(temp1 == head){
			head = NULL;
		}
		else{
			temp1->next = temp->next;
			head = temp->next;
		}
		delete temp;
		return;
	}
	node* prev = head;
	node* curr = head->next;
	while(temp != curr){
		prev = curr;
		curr = curr->next;
		if(curr == head){
			break;
		}	
	}
	if(curr != head){
		prev->next = curr->next;
		delete curr;
	}
	
	
}

vector<int> roundRobin(){
	int t=0;
	int f =0;
	vector<int> v;
	node* temp = head;
	while(head!=NULL){
		f=0;
		while(temp->next!=head){
			if(temp->at <=t){
				break;
			}
			temp = temp->next;
		}
		if(temp->at<=t){
			v.push_back(temp->id);
			temp->bt--;
			f=1;
			if(temp->bt == 0){
				node* curr = temp;
				temp = temp->next;
				Delete(curr);
			}
			else{
				temp = temp->next;
			}
			t++;
		}
		else{
			temp = temp->next;
		}
		if(f ==0){
			t++;
		}
	}
	return v;
}

int main(){
	int n;
	cin>>n;
	head = NULL;
	int id,at,bt;
	for(int i=0;i<n;i++){
		node *temp = new node;
		cin>>id>>at>>bt;
		temp->id = id;
		temp->at = at;
		temp->bt = bt;
		insert(temp);
	}
	
//	node* temp = head;
//	while(temp->next!=head){
//		cout<<temp->id<<" "<<temp->at<<" "<<temp->bt<<endl;
//		temp = temp->next; 
//	}
//	cout<<temp->id<<" "<<temp->at<<" "<<temp->bt<<endl;
//	while(head!=NULL){
//		
//	
//	Delete(head);
//	
//	temp = head;
//	while(head!=NULL && temp->next!=head){
//		cout<<temp->id<<" "<<temp->at<<" "<<temp->bt<<endl;
//		temp = temp->next; 
//	}
//	if(head!=NULL)
//	cout<<temp->id<<" "<<temp->at<<" "<<temp->bt<<endl;
//	}
	vector<int> v = roundRobin();
	vector<int>::iterator itr;
	for( itr = v.begin();itr!=v.end();itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
}
