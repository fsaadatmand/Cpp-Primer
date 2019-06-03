/*
 * Exercise 13.28: Given the following classes, implement a default constructor
 * and the necessary copy-control members.
 *
 * 	(a) class TreeNode {
 *		private:
 *			std::string value;
 *			int count;
 *			TreNode *left;
 *			TreeNode *right;
 *		};
 *
 * 	(b) class BinStrTree {
 * 			private:
 * 			TreeNode *root;
 * 		};
 *
 * By Faisal Saadatmand
 */

#include <iostream>
#include <memory>
#include <string>

class TreeNode {
	public:
		TreeNode() = default;
		TreeNode(const TreeNode &rhs);
		TreeNode& operator=(const TreeNode &);
		~TreeNode();
	private:
		std::string value;
		int count = 0;
		TreeNode *left = nullptr;
		TreeNode *right = nullptr;
		std::size_t *use_left = nullptr;
		std::size_t *use_right = nullptr;
};

TreeNode&
TreeNode::operator=(const TreeNode &rhs)
{
	if (rhs.left)        // left node not a nullptr
		++*rhs.use_left;
	if (--*use_left == 0)
		delete left;
	left = rhs.left;
	use_left = rhs.use_left;

	if (rhs.right)       // right node not a nullptr
		++*rhs.use_right;
	if (--*use_right == 0)
		delete right;
	right = rhs.right;
	use_right = rhs.use_right;

	value = rhs.value;
	count = rhs.count;
	return *this;
}

TreeNode::~TreeNode()
{
	if (left && --*use_left == 0) {
		delete left;
		delete use_left;
	}
	if (right && --*use_right == 0) {
		delete right;
		delete use_right;
	}
}

// pointerlink copy-control
class BinStrTree {
	public:
		BinStrTree() : root(new TreeNode()), use(new std::size_t(1)) {}
		BinStrTree(const BinStrTree &rhs) :
			root(rhs.root), use(rhs.use) { ++*use; }
		BinStrTree& operator=(const BinStrTree &);
		~BinStrTree();
		TreeNode* get_root() { return root; }
	private:
		TreeNode *root;
		std::size_t *use;
};

BinStrTree&
BinStrTree::operator=(const BinStrTree &rhs)
{
	++*rhs.use;
	if (--*use == 0) {
		delete root;
		delete use;
	}
	root = rhs.root;
	use = rhs.use;
	return *this;
}

BinStrTree::~BinStrTree()
{
	if (--*use == 0) {
		delete root;
		delete use;
	}
}

BinStrTree addTree(BinStrTree p, const std::string &w)
{
	return p;
}

int main()
{
	BinStrTree myTree;
	addTree(myTree, "book");
		std::cout << &myTree << '\n';
	return 0;
}
