#include "BTree.h"
#include <iostream>


TreeNode* BTree::CreateTree()
{
    int num;
    std::cout << "please input a number" << std::endl;
    std::cin >> num;
    TreeNode *node = nullptr;
    node = InsertItem(node, num);
    while (true)
    {
        std::cin >> num;
        if (num == 0)
        {
            break;
        }
        InsertItem(node, num);
    }
    return node;
}

TreeNode* BTree::InsertItem(TreeNode *&root, int val)
{
    if (!root)
    {
        TreeNode *p = new TreeNode;
        p->val = val;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return root;
    }

    if (root->val > val)
    {
        InsertItem(root->lchild,val);
    }
    else
    {
        InsertItem(root->rchild, val);
    }
}

bool BTree::TraverseTree(TreeNode *root)
{
    if (!root)
    {
        return true;
    }
  
    TraverseTree(root->lchild);
    std::cout << root->val << "\t";
    TraverseTree(root->rchild);
  
}
