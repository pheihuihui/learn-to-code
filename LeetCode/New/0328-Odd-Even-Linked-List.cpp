 class Solution {
 public:
	 ListNode* oddEvenList(ListNode* head) {
		 ListNode *odd = new ListNode(0);
		 ListNode *eve = new ListNode(0);
		 auto odd2 = odd;
		 auto eve2 = eve;
		 while (head) {
			 odd->next = head;
			 odd = odd->next;
			 head = head->next;
			 if (head) {
				 eve->next = head;
				 eve = eve->next;
				 head = head->next;
			 }
			 else {
				 eve->next = nullptr;
				 head = nullptr;
			 }
		 }
		 odd->next = eve2->next;
		 return odd2->next;
	 }
 };