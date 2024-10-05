/*

________________________________SUM_ROOT_TO_LEAF_NUMBERS________________________________

You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. 
Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children.


Example 1:
	Input: root = [1,2,3]
	Output: 25
	Explanation:
	The root-to-leaf path 1->2 represents the number 12.
	The root-to-leaf path 1->3 represents the number 13.
	Therefore, sum = 12 + 13 = 25.

Example 2:
	Input: root = [4,9,0,5,1]
	Output: 1026
	Explanation:
	The root-to-leaf path 4->9->5 represents the number 495.
	The root-to-leaf path 4->9->1 represents the number 491.
	The root-to-leaf path 4->0 represents the number 40.
	Therefore, sum = 495 + 491 + 40 = 1026.


Constraints:
	The number of nodes in the tree is in the range [1, 1000].
	0 <= Node.val <= 9
	The depth of the tree will not exceed 10.


*/



// Definition for a binary tree node:

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 
class Solution {
public:
	void sumNumbers_AUX(TreeNode* current_node, int* sum, int current_number) {
		if ((current_node->left == nullptr) && (current_node->right == nullptr)) {
			int temp = current_number;
			temp *= 10;
			temp += current_node->val;
			*sum += temp;
			return;
		}

		current_number *= 10;
		current_number += current_node->val;
		if (current_node->left) {
			sumNumbers_AUX(current_node->left, sum, current_number);
		}
		if (current_node->right) {
			sumNumbers_AUX(current_node->right, sum, current_number);
		}
	}

	int sumNumbers(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int sum = 0;
		int current_number = 0;
		sumNumbers_AUX(root, &sum, current_number);
	
		return sum;
	}
};