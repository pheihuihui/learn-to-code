 class Solution {
 public:
	 ListNode* removeElements(ListNode* head, int val) {
		 ListNode *res = new ListNode(0);
		 auto ret = res;
		 while (head) {
			 if (head->val != val) {
				 res->next = head;
				 head = head->next;
				 res = res->next;
			 }
			 else if (head->next != nullptr)
				 head = head->next;
			 else {
				 head = head->next;
				 res->next = nullptr;
			 }
		 }
		 return ret->next;
	 }
 };