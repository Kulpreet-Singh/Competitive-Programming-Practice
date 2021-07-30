int smallestSuperSequenceR(char *a, int len1, char *b, int len2) { 
    if(len1==0){
        return len2;
    }
    if(len2==0){
        len1;
    }
	if(a[0]==b[0]){
    	return 1+smallestSuperSequenceR(a+1,len1-1,b+1,len2-1);
	}
    else{
        return 1+min(smallestSuperSequenceR(a+1,len1-1,b,len2),smallestSuperSequenceR(a,len1,b+1,len2-1));
    }
}

int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    char* a = new char[len1+1];
    char* b = new char[len2+1];
    for(int i=0;i<=len1;i++){
        a[i] = str1[i];
    }
    for(int i=0;i<=len2;i++){
        b[i] = str2[i];
    }
    return smallestSuperSequenceR(a,len1,b,len2);
    
    
}
