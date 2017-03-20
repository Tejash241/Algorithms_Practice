/* PROBLEM DESCRIPTION:https://leetcode.com/problems/add-binary/?tab=Description
*/
char* reverseString(char* c, int currLen){
	/* reverses a string of length n (returns new string)
	   time complexity O(n) and space complexity O(n)
	*/
	char* revC = (char*)malloc((currLen+1)*sizeof(char));
	int i;
	for(i=currLen-1; i>=0; i--){
		revC[currLen-i-1] = c[i];
	}
	revC[currLen] = NULL;
	return revC;
}

char* padString(char* c, int currLen, int toLen){
	int diff = toLen-currLen;
	char* newC = (char*)malloc(toLen*sizeof(char));
	int i = 0, j = 0;
	for(i=0; i<diff; i++){
		newC[i] = '0';
	}
	for(j=i; j<toLen; j++){
		newC[j] = c[j-i];
	}
	return newC;
}

int getStringLen(char* s){
    int i = 0;
    while(s[i]!=NULL){
        i++;
    }
    return i;
}   

char* addBinary(char* a, char* b){
	int lenA = getStringLen(a);
	int lenB = getStringLen(b);
	if(lenA>lenB){
		b = padString(b, lenB, lenA);
		//printf("todkl%c", b[1]);
	}
	else if(lenB>lenA){
		a = padString(a, lenA, lenB);
		lenA = lenB;
	}
	a = reverseString(a, lenA);
	b = reverseString(b, lenA);
	int i = 0, carry = 0, sumx;
	char* sum = (char*)malloc((lenA+1)*sizeof(char));
	for(i=0; i<lenA; i++){
		if(a[i]=='1' && b[i]=='1'){
		    if(carry==1){
		        sumx = 1;
		    }
		    else{
			    sumx = 0;
		    }
			sum[i] = sumx+'0';
			carry = 1;
		}
		else{
			sumx = (a[i]-'0')+(b[i]-'0')+carry;
			if(sumx==2){
			    sumx = 0;
			    carry = 1;
			}
			else{
			    carry = 0;
			}
			sum[i] = sumx+'0';
		}
	}
	if(carry==1){
		sum[i] = '1';
		lenA ++;
	}
    //printf("%d%d%c",getStringLen(sum), lenA, sum[88]);
	return reverseString(sum, lenA);
}