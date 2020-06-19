#include "Tree.h"

Tree::Tree()
{
	m_root = nullptr;
}

Tree::~Tree()
{
	if (m_root != nullptr)	recursiveDelete(m_root);
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

//Remove the node with the given value from the tree
void Tree::remove(int value)
{
	TreeNode* target;
	TreeNode* parent;

	findNode(value, target, parent);

	if (target == nullptr)
	{
		return;
	}

	if (target->hasLeft() && target->hasRight())
	{
		//Get the smallest number from the right subtree
		TreeNode* lowRight = target->getRight();
		while (lowRight->hasLeft())
		{
			lowRight = lowRight->getLeft();
		}

		int temp = lowRight->getValue();

		remove(temp);

		target->setValue(temp);
		return;
	}
	else if (target->hasLeft())
	{
		if (parent != nullptr)
		{
			if (parent->getLeft() == target)
			{
				parent->setLeft(target->getLeft());
			}
			if (parent->getRight() == target)
			{
				parent->setRight(target->getLeft());
			}
		}
		else
		{
			m_root = target->getLeft();
		}
		delete target;
		return;
	}
	else if (target->hasRight())
	{
		if (parent != nullptr)
		{
			if (parent->getLeft() == target)
			{
				parent->setLeft(target->getRight());
			}
			if (parent->getRight() == target)
			{
				parent->setRight(target->getRight());
			}
		}
		else
		{
			m_root = target->getRight();
		}
		delete target;
		return;
	}
	else
	{
		if (parent != nullptr)
		{
			if (parent->getLeft() == target)
			{
				parent->setLeft(nullptr);
			}
			if (parent->getRight() == target)
			{
				parent->setRight(nullptr);
			}
		}
		else
		{
			m_root = nullptr;
		}
		delete target;
		return;
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
void Tree::draw(TreeNode* selected)
{
	draw(m_root, 400, 40, 400, selected);
}

//Recursively draw a node and its children
void Tree::draw(TreeNode* pNode, int x, int y, int spacing, TreeNode* selected)
{
	int ySpacing = 60;
	spacing /= 2;
	if (pNode != nullptr)
	{
		if (pNode->hasLeft())
		{
			DrawLine(x, y, x - spacing, y + ySpacing, BLUE);
			draw(pNode->getLeft(), x - spacing, y + ySpacing, spacing, selected);
		}
		if (pNode->hasRight())
		{
			DrawLine(x, y, x + spacing, y + ySpacing, BLUE);
			draw(pNode->getRight(), x + spacing, y + ySpacing, spacing, selected);
		}
		pNode->draw(x, y, selected);
	}
}

void Tree::recursiveDelete(TreeNode* node)
{
	if (node->hasLeft())
	{
		recursiveDelete(node->getLeft());
		node->setLeft(nullptr);
	}
	if (node->hasRight())
	{
		recursiveDelete(node->getRight());
		node->setRight(nullptr);
	}
	delete node;
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
