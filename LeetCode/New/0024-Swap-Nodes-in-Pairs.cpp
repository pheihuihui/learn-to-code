class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		} else {
			ListNode* tail = head->next->next;
			ListNode* node = head->next;
			node->next = head;
			node->next->next = swapPairs(tail);
			return node;
		}
	}
};