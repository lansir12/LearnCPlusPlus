#pragma once

struct TreeNode
{
    int val;//�������
    TreeNode *lchild;//�������ָ��
    TreeNode *rchild;//����Һ���ָ��
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