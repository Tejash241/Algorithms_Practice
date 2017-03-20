/* PROBLEM DESCRIPTION:https://leetcode.com/problems/multiply-strings/#/description
*/
char* reverseString(char* c, int currLen){
	char* revC = (char*)malloc((currLen+1)*sizeof(char));
	int i;
	for(i=currLen-1; i>=0; i--){
		revC[currLen-i-1] = c[i];
	}
	revC[currLen] = NULL;
	return revC;
}

int getStringLen(char* s){
    int i = 0;
    while(s[i]!=NULL){
        i++;
    }
    return i;
} 

int power(int a, int b){
	/* computes a to-the-power b
	*/
	if(b==1){
		return a;
	}
	else if(b<=0){
		return 1;
	}
	else{
		if(b%2==0){
			return power(a, b/2)*power(a, b/2);
		}
		else{
			return power(a,(int)b/2)*power(a,(int)b/2)*a;
		}
	}
}

char* longToString(long long a){
    if((int)a/10==0){
        char* c = (char*)malloc(2*sizeof(char));
        c[0] = a+'0';
        c[1] = NULL;
        return c;
    }
	char* c = (char*)malloc(221*sizeof(char)); // problem says max size of each number is 110, hence answer should not be more than 220 long
	int i = 0;
	while(a>0){
		c[i++] = a%10+'0';
	    a /= 10;
	}
	c[i] = NULL;
	return c;
}

char* multiply(char* num1, char* num2){
	int BASE = 10; // multiplication base 10
	int lenNum1 = getStringLen(num1);
	int lenNum2 = getStringLen(num2);
	char* x;
	char* y;
	int lenX = 0, lenY = 0; // always x*y where x>=y in length
	if(lenNum1>lenNum2){
		x = num1;
		y = num2;
		lenX = lenNum1;
		lenY = lenNum2;
	}    
	else{
		x = num2;
		y = num1;
		lenX = lenNum2;
		lenY = lenNum1;
	}
	x = reverseString(x, lenX);
	y = reverseString(y, lenY);
	//printf("%d%d%c", lenY, lenX, y[0]);
	int yIter, xIter, prod, carry=0; 
	char mcand, mux;
	long long ans = 0, tempAns = 0;
	char** allAns = 
	for(yIter=0; yIter<lenY; yIter++){
		mcand = y[yIter];
		tempAns = 0;
		for(xIter=0; xIter<lenX; xIter++){
			mux = x[xIter];
			prod = (mux-'0')*(mcand-'0')+carry;
			carry = (int)prod/BASE;
			prod %= 10;
			tempAns += prod*power(BASE, xIter);
			printf("%d\n", tempAns);
		}
		if(carry>0){
			tempAns += carry*power(BASE, xIter);
			carry = 0;
		}
		ans += tempAns*power(BASE, yIter);
	}
	//printf("%dasdf", ans);
	char* strAns = longToString(ans);
	return reverseString(strAns, getStringLen(strAns));
}