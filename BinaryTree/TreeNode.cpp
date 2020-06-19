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

void TreeNode::draw(int x, int y)
{
	DrawCircle(x, y, 10, BLACK);
	DrawText(std::to_string(m_value).c_str(), x - 6, y - 4, 12, RED);
}
