 class Solution {
 public:
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 ListNode *res = new ListNode(l1->val + l2->val);
		 if (l1->next != nullptr && l2->next != nullptr)
			 res->next = addTwoNumbers(l1->next, l2->next);
		 else if (l1->next == nullptr)
			 res->next = l2->next;
		 else if (l2->next == nullptr)
			 res->next = l1->next;
		 auto tmp = res;
		 while (tmp) {
			 if (tmp->val >= 10) {
				 if (tmp->next) {
					 tmp->next->val += 1;
					 tmp->val -= 10;
				 }
				 else {
					 tmp->val -= 10;
					 tmp->next = new ListNode(1);
				 }
				 tmp = tmp->next;
			 }
			 else
				 tmp = tmp->next;
		 }
		 return res;
	 }
 };