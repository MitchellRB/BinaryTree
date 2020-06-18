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