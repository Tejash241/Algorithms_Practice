/* PROBLEM DESCRIPTION = https://leetcode.com/problems/add-two-numbers/?tab=Description
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* l){
	/* reverses a linked list in time complexity O(n),
		space complexity O(1) using 3 extra pointers
	*/
	struct ListNode* prev = NULL;
	struct ListNode* curr = l;
	struct ListNode* next;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

int getLinkedListLen(struct ListNode* l){
	int len = 0;
	while(l->next!=NULL){
		len ++;
		l = l->next;
	}
	return len+1;
}

struct ListNode* padLinkedList(struct ListNode* l, int toLen){
	int thisLen = 0;
	struct ListNode* tempNode = NULL;
	struct ListNode* newL = l;
	while(thisLen<toLen-1){
		if(newL->next==NULL){
			tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
			tempNode->val = 0;
			tempNode->next = NULL;
			newL->next = tempNode;
		}
		newL = newL->next;
		thisLen++;
	}
	return l;
}

void dispLinkedList(struct ListNode* l){
	/* displays the values of a linkedList
	   time complexity O(n), space complexity 0
	*/
	while(l!=NULL){
		printf("%d", l->val);
		l = l->next;
	}
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int lenL1 = getLinkedListLen(l1);
    int lenL2 = getLinkedListLen(l2);
    if(lenL1<lenL2){
    	l1 = padLinkedList(l1, lenL2);
    }
    else if(lenL2<lenL1){
    	//dispLinkedList(l2);
    	l2 = padLinkedList(l2, lenL1);
    	//dispLinkedList(l2);
    }
    struct ListNode* sum = NULL;
    struct ListNode* lastSum = (struct ListNode*)malloc(sizeof(struct ListNode));
    int sumx = 0, carry = 0;
    bool isPass = true;
    while(isPass){
		if(l1->next==NULL && l2->next==NULL){
            isPass = false;
            sumx = l1->val+l2->val+carry;
        }
		else if(l1->next==NULL){
			sumx = l2->val+carry;
        	l2 = l2->next;
		}
		else if(l2->next==NULL){
			sumx = l1->val+carry;
	    	l1 = l1->next;
		}
		else{
			sumx = l1->val+l2->val+carry;
	    	l1 = l1->next;
    	    l2 = l2->next;
		}
		if(sumx<=9){
			carry = 0;
		}
		else{
			carry = 1;
			sumx -= 10;
		}
		//printf("%d??%d\n", sumx, carry);
		struct ListNode* tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
		tempNode->val = sumx;
		tempNode->next = NULL;
		if(sum==NULL){
			sum = tempNode;
			lastSum = tempNode;
    	}
    	else{
    		lastSum->next = tempNode;
    		lastSum = tempNode;
    	}
    	if(!isPass && carry==1){
    	    struct ListNode* tempNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    	    tempNode->val = carry;
    	    tempNode->next = NULL;
    	    lastSum->next = tempNode;
    	}
    }
    return sum;
}