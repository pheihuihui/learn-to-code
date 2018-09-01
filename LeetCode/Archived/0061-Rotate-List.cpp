 class Solution {
 public:
	 ListNode* rotateRight(ListNode* head, int k) {
		 if (head == nullptr || k == 0)
			 return head;
		 auto start = head;
		 auto end = head;
		 int len = 0;
		 while (head) {
			 len += 1;
			 if (head->next == nullptr)
				 end = head;
			 head = head->next;
		 }
		 int kk = k % len;
		 if (kk == 0)
			 return start;
		 else {
			 head = start;
			 for (int i = 0; i < len - kk - 1; i++)
				 head = head->next;
			 auto tail = head;
			 head = head->next;
			 tail->next = nullptr;
			 end->next = start;
			 return head;
		 }
	 }
 };