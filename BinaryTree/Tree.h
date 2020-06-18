#pragma once
#include "TreeNode.h"
class Tree
{
public:
	Tree();
	~Tree();

	bool isEmpty() { return (m_root != nullptr); };

	void insert(int value);

protected:
	TreeNode* m_root;
};

