#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) {
            return l2;
        } else if(l2 == nullptr) {
            return l1;
        }

        ListNode *sumList =  new ListNode(-1);
        ListNode *ptr = sumList;
        int carry = 0;
        while(l1 || l2) {
			int sum = 0;
            if(l1) {
                sum += l1->val;
            } 

			if(l2) {
                sum += l2->val;
            }

			//cout << "sum:" << sum << endl;
			sum += carry;
            if(sum >= 10) {
                carry = sum/10;
                sum = sum%10;
            }

            ListNode *n = new ListNode(sum, nullptr);
            ptr->next = n;
            ptr = n;

            if(l1)
                l1 = l1->next;

            if(l2)
                l2 = l2->next;
        }

		if(carry > 0) {
            ListNode *n = new ListNode(carry, nullptr);
            ptr->next = n;
            ptr = n;

		}

        return sumList->next;
    }
};

int main() {
	ListNode *list1 = nullptr;
	ListNode *list2 = nullptr;

	ListNode *ptr1, *ptr2;
	for(int i = 0; i < 5; i++) {
		ListNode *l1 = new ListNode(i*2, nullptr);
		if(list1 == nullptr) {
			//cout<< "empty list" << endl;
			list1 = l1;
			ptr1 = list1;
			//cout << ptr1 << list1 << endl;
			//cout << l1->val << "," << endl;
		} else {
			//cout << l1->val << endl;
			ptr1->next = l1;
			ptr1 = ptr1->next;
			//printf("address:%p, %p\n", l1, ptr1);
		}
		
		ListNode *l2 = new ListNode(i+3, nullptr);
		if(list2 == nullptr) {
			//cout<< "empty list" << endl;
			list2 = l2;
			ptr2 = list2;
			//cout << ptr2 << list2 << endl;
			//cout << l2->val << "," << endl;
		} else {
			//cout << l2->val << endl;
			ptr2->next = l2;
			ptr2 = ptr2->next;
			//printf("address:%p, %p\n", l2, ptr2);
		}
	}

	ListNode *p1 = list1;

	//display List 1
	cout << "List 1" << endl;
	while(p1) {
		cout << "Value:" << p1->val << endl;
		p1 = p1->next;
	}

	p1 = list2;

	//display List 2
	cout << "List 2" << endl;
	while(p1) {
		cout << "Value:" << p1->val << endl;
		p1 = p1->next;
	}

	Solution s;
	ListNode *mList = s.addTwoNumbers(list1, list2);
	//display sum List
	cout << "Sum List" << endl;
	p1 = mList;
	while(p1) {
		cout << "Value:" << p1->val << endl;
		p1 = p1->next;
	}


	//fee list1
	p1 = list1;
	while(p1) {
		ListNode *l = p1;
		//cout << "Freeing a node of value:" << l->val << endl;
		p1 = p1->next;
		free(l);
	}

	//fee list2
	p1 = list2;
	while(p1) {
		ListNode *l = p1;
		//cout << "Freeing a node of value:" << l->val << endl;
		p1 = p1->next;
		free(l);
	}
	
	//fee mList
	p1 = mList;
	while(p1) {
		ListNode *l = p1;
		//cout << "Freeing a node of value:" << l->val << endl;
		p1 = p1->next;
		free(l);
	}

	return 0;
}
