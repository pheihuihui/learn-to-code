class Solution {
public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL)
			return NULL;
		else {
			ListNode *tmpA = headA;
			while (tmpA) {
				ListNode *tmpB = headB;
				while (tmpB) {
					if (tmpB == tmpA)
						return tmpA;
					else
						tmpB = tmpB->next;
				}
				tmpA = tmpA->next;
			}
		}
		return NULL;
	}
};

//too too slow

 class Solution {
 public:
	 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		 int aa = getLength(headA);
		 int bb = getLength(headB);
		 ListNode *res;
		 if (aa == bb)
			 res = getInter(headA, headB);
		 else {
			 if (aa > bb) {
				 for (int i = 0; i < aa - bb; i++)
					 headA = headA->next;
			 }
			 else if (aa < bb) {
				 for (int i = 0; i < bb - aa; i++)
					 headB = headB->next;
			 }
			 res = getInter(headA, headB);
		 }
		 return res;
	 }
 private:
	 int getLength(ListNode *head) {
		 int res = 0;
		 while (head) {
			 res += 1;
			 head = head->next;
		 }
		 return res;
	 }
	 ListNode *getInter(ListNode *headA, ListNode *headB) {
		 auto tmpa = headA;
		 auto tmpb = headB;
		 while (tmpa != nullptr && tmpb != nullptr) {
			 if (tmpa == tmpb)
				 return tmpa;
			 else {
				 tmpa = tmpa->next;
				 tmpb = tmpb->next;
			 }
		 }
		 return nullptr;
	 }
 };