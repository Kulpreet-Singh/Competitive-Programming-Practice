arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}

store the values of arr and dep in a struct train
sort on the basis of arrival time
count = 1;
for(i=0;i<n;i++){
	j=0
	while(j<count)
	{
		if i-j>=0 && i+1<n && departure time of the i-j train < arrival time i+1
			break;
		
		j++;
	}	
	if(j==count){
		count++;
	}
}
return count;



// loop in a linked list

node* ptr1 = head;
node* ptr2 = head;
bool flag = 0;
while(ptr1!=NULL && ptr!=NULL){
	ptr1 = ptr1->next;
	if(ptr2->next !=NULL)
		ptr2 = ptr2->next->next;
	if(ptr1 == ptr2){
		flag = 1;
		break;
	}
}

if(flag == 1){
	cout<<"Loop exists"<<endl;
}
