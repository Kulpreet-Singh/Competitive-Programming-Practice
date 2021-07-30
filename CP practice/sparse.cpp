#include<iostream>
using namespace std;

struct item{
	int i;
	int j;
	int x;
};

item* create(int m,int n,int o){
	int x,k=0;
	item *a= new item[o];
	cout<<"Enter the elements:";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>x;
			if(x!=0){
				a[k].i=i;
				a[k].j=j;
				a[k].x=x;
				k++;	
			}
		}
	}
	return a;
}
void display(item a[],int m,int n){
	int k=0;
	cout<<"\nThe sparse matrix is:\n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==a[k].i && j==a[k].j){
				cout<<a[k].x<<" ";
				k++;
			}
			else{
				cout<<"0 ";
			}
			
		}
		cout<<endl;
	}
}

void swap(item &a,item &b){
//	int temp;
//	temp = a.i;
//	a.i=b.i;
//	b.i=temp;
//	temp = a.x;
//	a.x=b.x;
//	b.x=temp;
//	temp = a.j;
//	a.j=b.j;
//	b.j=temp;
	item temp;
	temp=a;
	a=b;
	b=temp;
}

item* transpose(item a[],int o){
	item* b=new item[o];
	
	for(int i=0;i<o;i++){
		b[i].i=a[i].j;
		b[i].j=a[i].i;
		b[i].x=a[i].x;	
	}
	for(int i=0;i<o-1;i++){
		for(int j=0;j<o-i-1;j++){
			if(b[j].i>b[j+1].i){
				swap(b[j],b[j+1]);
			}
			else if(b[j].i==b[j+1].i){
				if(b[j].j>b[j+1].j){
					swap(b[j],b[j+1]);
				}
			}
		}
	}
	cout<<"transposed successfully";
	return b;
}

item* product(item a[],item b[], int m,int n,int k,int l,int y){
	if(n==k){
		item* c= new item[m*l];
		b=transpose(b,y);
		int temp=k;
		k=l;
		l=temp;
		int add=0;
		int p=0;//a array counter
		int q=0;//b array counter
		int r=0;//c array counter
		int f=0;//flag
		int inj,ini;
		for(int i=0;i<m;i++){
			while(a[p].i==i){
				    q=0;
				for(int j=0;j<k;j++){
					
					while(b[q].i==j){
						if(a[p].j==b[q].j){
							add+=a[i].x*b[j].x;
							f=1;
							inj=b[q].i;
							ini=a[p].i;
						}
						q++;
					}
					
					
					
				}
				p++; 
				
			}
			if(f==1){
						c[r].x=add;
						c[r].i=ini;
						c[r].j=inj;
						r++;
						f=0;
						add=0;
					}
				
		}
		return c;
	}
	else{
		cout<<"\nDimensions don't match";
	}
	
}
int main(){
	int m,n,o,m1,n1,o1;
	cout<<"Enter the size of the sparse matrix:";
	cin>>m>>n;
	cout<<"Enter the number of elements:";
	cin>>o;
	item *a=create(m,n,o);
	display(a,m,n);
	cout<<"Enter the size of the sparse matrix:";
	cin>>m1>>n1;
	cout<<"Enter the number of elements:";
	cin>>o1;
	item *b=create(m1,n1,o1);
	display(b,m1,n1);
	item *c=product(a,b,m,n,m1,n1,o1);
	display(c,m,n1);
	
	return 0;
}
/*OUTPUT
Enter the size of the sparse matrix:10 10
Enter the number of elements:12
Enter the elements:0 0 0 5 0 0 0 5 0 0
0 0 0 0 0 5 0 0 0 0
0 0 0 0 5 0 0 0 0 0
0 0 5 0 0 0 0 0 0 0
0 0 0 0 0 0 5 0 0 0
0 0 0 0 5 0 0 0 0 0
5 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 5 0
0 5 0 0 0 0 0 0 0 0
0 0 5 0 0 0 0 0 0 5

The sparse matrix is:
0 0 0 5 0 0 0 5 0 0
0 0 0 0 0 5 0 0 0 0
0 0 0 0 5 0 0 0 0 0
0 0 5 0 0 0 0 0 0 0
0 0 0 0 0 0 5 0 0 0
0 0 0 0 5 0 0 0 0 0
5 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 5 0
0 5 0 0 0 0 0 0 0 0
0 0 5 0 0 0 0 0 0 5
Enter the size of the sparse matrix:10 3
Enter the number of elements:6
Enter the elements:0 4 0
0 0 0
0 0 4
0 0 0
4 0 0
0 0 0
0 4 0
0 0 0
4 0 0
0 0 4

The sparse matrix is:
0 4 0
0 0 0
0 0 4
0 0 0
4 0 0
0 0 0
0 4 0
0 0 0
4 0 0
0 0 4
transposed successfully
The sparse matrix is:
0 0 0
0 0 0
20 0 0
0 0 20
0 20 0
20 0 0
0 20 0
20 0 0
0 0 0
0 0 40
*/

