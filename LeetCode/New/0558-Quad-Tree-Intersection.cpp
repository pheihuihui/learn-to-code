class Solution {
public:
	Node* intersect(Node* quadTree1, Node* quadTree2) {
		if (quadTree1->isLeaf && !quadTree1->val)
			return quadTree2;
		else if (quadTree2->isLeaf && !quadTree2->val)
			return quadTree1;
		else if (quadTree1->isLeaf && quadTree1->val)
			return quadTree1;
		else if (quadTree2->isLeaf && quadTree2->val)
			return quadTree2;
		else {
			Node* res = new Node();
			res->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
			res->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
			res->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
			res->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
			if (res->bottomLeft->isLeaf && res->bottomRight->isLeaf && res->topLeft->isLeaf && res->topRight->isLeaf) {
				if (res->bottomLeft->val && res->bottomRight->val && res->topLeft->val && res->topRight->val) {
					res->isLeaf = true;
					res->val = true;
					res->bottomLeft = nullptr;
					res->bottomRight = nullptr;
					res->topLeft = nullptr;
					res->topRight = nullptr;
				}
				else if (!res->bottomLeft->val && !res->bottomRight->val && !res->topLeft->val && !res->topRight->val) {
					res->isLeaf = true;
					res->val = false;
					res->bottomLeft = nullptr;
					res->bottomRight = nullptr;
					res->topLeft = nullptr;
					res->topRight = nullptr;
				}
				else {
					res->isLeaf = false;
					res->val = false;
				}
			}
			else {
				res->isLeaf = false;
				res->val = false;
			}
			return res;
		}
	}
};