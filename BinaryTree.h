#pragma once



#include "LinkedDiscardPile.h"
#include "TreeNode.h"

class BinaryTree {

private:

    TreeNode* root;

public:

    BinaryTree();
    ~BinaryTree();
    void InsertFromLinkedList(LinkedDiscardPile list);
    TreeNode* InsertRecursive(TreeNode* node, Card card);
    void FindHighestLowestCard(LinkedDiscardPile list);

};
