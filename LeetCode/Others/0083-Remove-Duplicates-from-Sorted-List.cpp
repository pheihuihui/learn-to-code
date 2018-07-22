struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* res = head;
		while (res) {
			ListNode* nex = res->next;
			while (nex) {
				if (nex->val == res->val)
					nex = nex->next;
				else
					break;
			}
			res->next = nex;
			res = nex;
		}
		return head;
	}
};