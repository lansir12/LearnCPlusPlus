#pragma once

struct TreeNode
{
    int val;//存放数据
    TreeNode *lchild;//存放左孩子指针
    TreeNode *rchild;//存放右孩子指针
};

class BTree
{
public:
    BTree() {};
    ~BTree() {};
    TreeNode* CreateTree();
    TreeNode* InsertItem(TreeNode *&root, int val);
    bool TraverseTree(TreeNode *root);

};