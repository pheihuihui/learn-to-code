 class Solution {
 public:
	 RandomListNode *copyRandomList(RandomListNode *head) {
		 if (head == nullptr)
			 return nullptr;
		 auto start = head;
		 vector<RandomListNode*> rps;
		 vector<RandomListNode*> tmp;
		 while (head) {
			 rps.push_back(head);
			 tmp.push_back(new RandomListNode(head->label));
			 head = head->next;
		 }
		 head = start;
		 while (head) {
			 int indexH = find(rps.begin(), rps.end(), head) - rps.begin();
			 int indexR = -1;
			 if (head->random != nullptr) {
				indexR = find(rps.begin(), rps.end(), head->random) - rps.begin();
				tmp[indexH]->random = tmp[indexR];
			 }
			 if (head->next)
				 tmp[indexH]->next = tmp[indexH + 1];
			 head = head->next;
		 }
		 return tmp[0];
	 }
 };

 //too slow