#include <iostream>
#include "BTree.h"

using namespace std;

int main()
{
    cout << "begin main" << endl;
    BTree tree;
    TreeNode *node = tree.CreateTree();
    tree.TraverseTree(node);
    cout << "end main" << endl;
    return 0;
}