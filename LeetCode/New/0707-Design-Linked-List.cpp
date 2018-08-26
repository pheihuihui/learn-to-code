class MyLinkedList {
public:
	MyLinkedList() {
		list = nullptr;
	}

	int get(int index) {
		int len = getLength();
		if (index < 0 || index > len - 1)
			return -1;
		else {
			ListNode* cur = list;
			for (int i = 0; i < index; i++)
				cur = cur->next;
			return cur->val;
		}
	}

	void addAtHead(int val) {
		ListNode *head = new ListNode(val);
		head->next = list;
		list = head;
	}

	void addAtTail(int val) {
		ListNode *tail = new ListNode(val);
		ListNode *tmp = getTail();
		tmp->next = tail;
	}

	void addAtIndex(int index, int val) {
		int len = getLength();
		if (index == 0)
			addAtHead(val);
		else if (index == len)
			addAtTail(val);
		else if (index < 0 || index > len)
			return;
		else {
			ListNode *cur = list;
			for (int i = 0; i < index - 1; i++)
				cur = cur->next;
			ListNode *nex = cur->next;
			ListNode *in = new ListNode(val);
			cur->next = in;
			in->next = nex;
		}
	}

	void deleteAtIndex(int index) {
		int len = getLength();
		if (index < 0 || index > len - 1)
			return;
		else {
			if (index == 0)
				list = list->next;
			else {
				ListNode *cur = list;
				for (int i = 0; i < index - 1; i++) {
					cur = cur->next;
				}
				cur->next = cur->next->next;
			}
		}
	}

private:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
	ListNode *list;
	ListNode *getTail() {
		ListNode *cur = list;
		while (cur->next != nullptr)
			cur = cur->next;
		return cur;
	}
	int getLength() {
		int res = 0;
		ListNode *cur = list;
		while (cur != nullptr) {
			res += 1;
			cur = cur->next;
		}
		return res;
	}
};