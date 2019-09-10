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

#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <memory>
#include <string>

class TreeNode {
	public:
		TreeNode(const std::string &s = std::string()) :
			value(s), use(new std::size_t(1)) {}
		TreeNode(const TreeNode &node) :
			value(node.value), count(node.count),
			left(node.left), right(node.right), use(node.use) { ++*use; }
		TreeNode& operator=(const TreeNode &rhs);
		~TreeNode();
	private:
		std::string value;
		int count = 0;
		TreeNode *left = nullptr;
		TreeNode *right = nullptr;
		std::size_t *use = nullptr;
};

TreeNode&
TreeNode::operator=(const TreeNode &rhs)
{
	++*rhs.use;
	if (!--*use) {
		delete left;
		delete right;
		delete use;
	}
	value = rhs.value;
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	use = rhs.use;
	return *this;
}

TreeNode::~TreeNode()
{
	if (!--*use) {
		delete left;
		delete right;
		delete use;
	}
}

class BinStrTree {
	public:
	BinStrTree() : root(new TreeNode()), use(new std::size_t(1)) {}
	BinStrTree(const BinStrTree &bst) :
		root(bst.root), use(bst.use) { ++*use; }
	BinStrTree& operator=(const BinStrTree &rhs);
	~BinStrTree();
	private:
		TreeNode *root = nullptr;
		std::size_t *use = nullptr;
};

BinStrTree&
BinStrTree::operator=(const BinStrTree &rhs)
{
	++*rhs.use;
	if (!--*use) {
		delete root;
		delete use;
	}
	root = rhs.root;
	use = rhs.use;
	return *this;
}

BinStrTree::~BinStrTree()
{
	if (!--*use) {
		delete root;
		delete use;
	}
}
#endif
