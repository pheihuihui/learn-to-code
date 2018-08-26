//faster
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *one = onestep(head);
		ListNode *two = twostep(head);
		while (two != nullptr) {
			one = onestep(one);
			two = twostep(two);
			if (one == two)
				return true;
		}
		return false;
	}
private:
	ListNode *twostep(ListNode *head) {
		if (head == nullptr)
			return nullptr;
		else if (head->next == nullptr)
			return nullptr;
		else
			return head->next->next;
	}
	ListNode *onestep(ListNode *head) {
		if (head == nullptr)
			return nullptr;
		else
			return head->next;
	}
};