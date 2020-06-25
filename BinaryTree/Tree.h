#pragma once
#include "TreeNode.h"
class Tree
{
public:
	Tree();
	~Tree();

	bool isEmpty() { return (m_root == nullptr); };

	void insert(int value);

	void remove(int value);

	TreeNode* find(int value);

	void draw(Vector2 offset, TreeNode* selected = nullptr);

protected:
	TreeNode* m_root;

	void findNode(int value, TreeNode*& outNode, TreeNode*& outParent);

	void draw(TreeNode* pNode,int x, int y, int spacing, TreeNode* selected);

	void recursiveDelete(TreeNode* node);
};
