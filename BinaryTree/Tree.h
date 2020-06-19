#pragma once
#include "TreeNode.h"
class Tree
{
public:
	Tree();
	~Tree();

	bool isEmpty() { return (m_root != nullptr); };

	void insert(int value);

	TreeNode* find(int value);

protected:
	TreeNode* m_root;

	void findNode(int value, TreeNode*& outNode, TreeNode*& outParent);
};
