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
    ListNode* mergeTwoListsWithVal(ListNode* list1, ListNode* list2) {
        ListNode *node = nullptr;
        if(list1 == nullptr) {
			node = list2;
        } else if(list2 == nullptr) {
			node = list1;
        } else {
			ListNode *ptr;
			int l1Cnt = 0, l2Cnt = 0, mCnt = 0;
            while(list1 || list2) {
				int val = 0;
				if(!list1 && !list2) {
					break;
				} else if(!list1) {
					val = list2->val;
					list2 = list2->next;
				} else if(!list2) {
					val = list1->val;
					list1 = list1->next;
				} else if(list1->val <= list2->val) {
					val = list1->val;
					list1 = list1->next;
				} else {
					val = list2->val;
					list2 = list2->next;
				}
				//cout << "Merge-Value:" << val << endl;
				ListNode *n = new ListNode(val, nullptr);
				if(!node) {
					node = n;
					ptr = node;
				} else {
					ptr->next = n;
					ptr = ptr->next;
				}

            }
        }
		/*ListNode *p1 = node;
		while(p1) {
			cout << "Value:" << p1->val << endl;
			p1 = p1->next;
		}*/

		return node;
    }
    
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
			return list2;
        } else if(list2 == nullptr) {
			return list1;
        }

        ListNode *node = new ListNode(-1);
		ListNode *ptr = node;
		while(list1 && list2) {
			if(list1->val <= list2->val) {
				ptr->next = list1;
				ptr = list1;
				list1 = list1->next;
			} else {
				ptr->next = list2;
				ptr = list2;
				list2 = list2->next;
			}
		}

		if(list1) {
			ptr->next = list1;
		}

		if(list2) {
			ptr->next = list2;
		}
		/*ListNode *p1 = node;
		while(p1) {
			cout << "Value:" << p1->val << endl;
			p1 = p1->next;
		}*/

		return node->next;
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
	/*while(p1) {
		cout << "Value:" << p1->val << endl;
		p1 = p1->next;
	}

	p1 = list2;

	//display List 2
	while(p1) {
		cout << "Value:" << p1->val << endl;
		p1 = p1->next;
	}*/

	Solution s;
	ListNode *mList = s.mergeTwoLists(list1, list2);
	//display merge List
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
