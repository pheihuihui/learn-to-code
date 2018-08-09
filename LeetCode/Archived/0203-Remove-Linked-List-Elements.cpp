class Solution {
public:
	ListNode * removeElements(ListNode* head, int val) {
		if (head == NULL)
			return NULL;
		while (head->val == val) {
			if (head->next != NULL)
				head = head->next;
			else {
				head = NULL;
				break;
			}
		}
		ListNode *res = head;
		while (head) {
			ListNode *tmp = head;
			while (tmp->next) {
				if (tmp->next->val == val)
					tmp->next = tmp->next->next;
				else
					break;
			}
			head = tmp->next;
		}
		return res;
	}
};