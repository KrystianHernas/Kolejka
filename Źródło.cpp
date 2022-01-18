#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Node {
public:
	int data;
	Node* left, * right;
	Node(int d) {
		data = d;
		left = right = NULL;
	}
};
class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}
			return root;
		}
	}
	void levelOrder(Node* root) {
		std::queue<Node*> q;
		Node* n = root;
		std::vector<int> exit;

		while (n != NULL) {
			std::cout << n->data << ' ';

			if (n->left != NULL) q.push(n->left);
			if (n->right != NULL) q.push(n->right);
			if (!q.empty()) {
				n = q.front();
				q.pop();
			}
			else {
				n = NULL;
			}
		}
		for (int i = 0; i < exit.size(); i++) {
			std::cout << exit[i] << ' ';
		}
	}


};
int main() {
	Solution myTree;
	Node* root = NULL;
	int T, data;
	std::cin >> T;
	while (T-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}
	myTree.levelOrder(root);
	return 0;
}
