#include "Tree.h"

Tree::Tree()
{
	m_root = nullptr;
}

Tree::~Tree()
{
	
}

void Tree::insert(int value)
{
	if (isEmpty())
	{
		m_root = new TreeNode(value);
		return;
	}

	TreeNode* current = m_root;
	TreeNode* previous = nullptr;

	while (current != nullptr)
	{
		if (value < current->getValue())
		{
			previous = current;
			current = current->getLeft();
		}

		else if (value > current->getValue())
		{
			previous = current;
			current = current->getRight();
		}

		else if (value = current->getValue())
		{
			return;
		}
	}

	if (value < previous->getValue())
	{
		previous->setLeft(new TreeNode(value));
	}
	else
	{
		previous->setRight(new TreeNode(value));
	}
}

TreeNode* Tree::find(int value)
{
	TreeNode* current = m_root;
	while (current != nullptr)
	{
		if (value == current->getValue())
		{
			break;
		}
		else if (value > current->getValue())
		{
			current = current->getRight();
		}
		else if (value < current->getValue())
		{
			current = current->getLeft();
		}
	}
	return current;
}

void Tree::findNode(int value, TreeNode*& outNode, TreeNode*& outParent)
{
	outNode = m_root;
	outParent = nullptr;
	while (outNode != nullptr)
	{
		if (value == outNode->getValue())
		{
			break;
		}
		else if (value > outNode->getValue())
		{
			outParent = outNode;
			outNode = outNode->getRight();
		}
		else if (value < outNode->getValue())
		{
			outParent = outNode;
			outNode = outNode->getLeft();
		}
	}
}
