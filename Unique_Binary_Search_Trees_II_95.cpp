//
// Created by Anh Le on 3/11/25.
//

#include <vector>
#include "TreeNode.h"
using namespace std;


vector<TreeNode*> gen_sub(int from, int to)
{
    vector<TreeNode*> rs;
    if (from > to)
    {
        rs.push_back(nullptr);
        return rs;
    }

    if (from == to)
    {
        TreeNode* node = new TreeNode(from);
        rs.push_back(node);
        return rs;
    }

    if (to - from == 1)
    {
        TreeNode* from_node = new TreeNode(from);
        TreeNode* to_node = new TreeNode(to);

        from_node->right = new TreeNode(to);
        to_node->left = new TreeNode(from);

        rs.push_back(from_node);
        rs.push_back(to_node);

        return rs;
    }

    for (int i = from; i <= to; i++)
    {
        vector<TreeNode*> left_side = gen_sub(from, i - 1);
        vector<TreeNode*> right_side = gen_sub(i + 1, to);
        for (TreeNode* left_branch : left_side)
        {
            for (TreeNode* right_branch : right_side)
            {
                TreeNode* node_i = new TreeNode(i);
                node_i->left = left_branch;
                node_i->right = right_branch;
                rs.push_back(node_i);
            }
        }
    }

    return rs;
}

vector<TreeNode*> generateTrees(int n)
{
    return gen_sub(1, n);
}
