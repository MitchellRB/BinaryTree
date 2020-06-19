#include "TreeNode.h"
#include <string>

TreeNode::TreeNode(int value)
{
	m_value = value;
	m_left = nullptr;
	m_right = nullptr;
}

TreeNode::~TreeNode()
{

}

void TreeNode::draw(int x, int y, TreeNode* selected)
{
	if (selected == this)
	{
		DrawCircle(x, y, 15, YELLOW);
	}
	else
	{
		DrawCircle(x, y, 15, BLACK);
	}

	DrawText(std::to_string(m_value).c_str(), x - 6, y - 6, 12, RED);
}
