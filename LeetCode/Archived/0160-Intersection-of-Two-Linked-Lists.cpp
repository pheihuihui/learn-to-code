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