#include "Tree.h"

Tree::Tree()
{
	m_root = nullptr;
}

Tree::~Tree()
{
	
}

//Add a node with the given value
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

//Get a pointer to the node with a given value
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

//Draw the entire tree
void Tree::draw()
{
	draw(m_root, 400, 40, 400);
}

//Recursively draw a node and its children
void Tree::draw(TreeNode* pNode, int x, int y, int spacing)
{
	int ySpacing = 60;
	spacing /= 2;
	if (pNode != nullptr)
	{
		if (pNode->hasLeft())
		{
			DrawLine(x, y, x - spacing, y + ySpacing, BLUE);
			draw(pNode->getLeft(), x - spacing, y + ySpacing, spacing);
		}
		if (pNode->hasRight())
		{
			DrawLine(x, y, x + spacing, y + ySpacing, BLUE);
			draw(pNode->getRight(), x + spacing, y + ySpacing, spacing);
		}
		pNode->draw(x, y);
	}
}

//Find the node with a given value
//Returns the node and its parent
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
