#pragma once

#include "Card.h"

class TreeNode {

public:
    Card DiscardedCard;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Card card);
};

