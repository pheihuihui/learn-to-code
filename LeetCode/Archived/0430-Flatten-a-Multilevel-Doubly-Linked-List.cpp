 class Solution {
 public:
	 Node* flatten(Node* head) {
		 auto res = head;
		 while (head) {
			 if (head->child != nullptr && head->next == nullptr) {
				 head->next = head->child;
				 head->child = nullptr;
				 head->next->prev = head;
			 }
			 else if(head->child != nullptr) {
				 auto start = head;
				 auto next = head->next;
				 flatten(head->child);
				 auto chil = start->child;
				 while (chil->next)
					 chil = chil->next;
				 chil->next = next;
				 next->prev = chil;
				 start->next = start->child;
				 start->child = nullptr;
				 start->next->prev = start;
			 }
			 head = head->next;
		 }
		 return res;
	 }
 };