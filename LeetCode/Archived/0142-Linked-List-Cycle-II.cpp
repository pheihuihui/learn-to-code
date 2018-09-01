class Solution {
public:
	ListNode * detectCycle(ListNode *head) {
		vector<ListNode *> nodes;
		while (head != nullptr) {
			if (find(nodes.begin(), nodes.end(), head) != nodes.end())
				return head;
			else {
				nodes.push_back(head);
				head = head->next;
			}
		}
		return nullptr;
	}
};

//too slow