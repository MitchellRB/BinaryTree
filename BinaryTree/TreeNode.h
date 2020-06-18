#pragma once
class TreeNode
{
public:
	TreeNode(int _value);
	~TreeNode();

protected:
	int value;
	TreeNode* leftChild;
	TreeNode* rightChild;
};

