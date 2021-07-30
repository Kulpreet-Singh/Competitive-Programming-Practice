#include<bits/stdc++.h>
using namespace std;

struct pro{
	int id;
	int at;
	int bt;
};

bool comp(pro a, pro b){
	if(a.at == b.at){
		if(a.id < b.id){
			return true;
		}
	}
	if(a.at < b.at){
		return true;
	}
	return false;
}

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



vector<int> roundRobin(pro *arr, int n,int tq =1){
	vector<int> v;
	int t = arr[0].at;
	int i=0;
	while(i<n){
		while(i<n && t >= arr[i].at){
			node *temp = new node;
			temp->id = arr[i].id;
			temp->at = arr[i].at;
			temp->bt = arr[i].bt;
			insert(temp);
			i++;
		}
//		while(!q.empty()){
//			pro curr = q.front();
//			q.pop();
//			curr.bt-= tq;
//			v.push_back(curr.id);
		node* curr = head;
		while(head != NULL){
			curr->bt--;
			v.push_back(curr->id);
			t++;
			
			while(i<n && t >= arr[i].at){
				node *temp = new node;
				temp->id = arr[i].id;
				temp->at = arr[i].at;
				temp->bt = arr[i].bt;
				insert(temp);
				i++;
			}
			
			if(curr->bt == 0){
				node* temp1 = curr;
				curr = curr->next;
				Delete(temp1);
			}
			else{
				curr=curr->next;
			}
			
		}
		t++;
	}
	return v;
}

int main(){
	int n;
	cin>>n;
	pro *arr = new pro[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].id>>arr[i].at>>arr[i].bt;
	}
	sort(arr,arr+n,comp);
//	for(int i=0;i<n;i++){
//		cout<<arr[i].id<<" "<<arr[i].at<<" "<<arr[i].bt<<endl;
//	}
	int tq =1;
	vector<int> v = roundRobin(arr,n,tq);
	vector<int>::iterator itr;
	for( itr = v.begin();itr!=v.end();itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
}
