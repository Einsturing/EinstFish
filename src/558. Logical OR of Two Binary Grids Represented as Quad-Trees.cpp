//难度-中等
//模拟递归
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        if (quadTree1->isLeaf)
        {
            if (quadTree1->val)
                return new Node(1, 1);
            return new Node(quadTree2->val, quadTree2->isLeaf, quadTree2->topLeft, quadTree2->topRight, quadTree2->bottomLeft, quadTree2->bottomRight);
        }
        if (quadTree2->isLeaf)
            return intersect(quadTree2, quadTree1);
        Node *l1 = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node *l2 = intersect(quadTree1->topRight, quadTree2->topRight);
        Node *l3 = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node *l4 = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if (l1->isLeaf && l2->isLeaf && l3->isLeaf && l4->isLeaf && l1->val == l2->val && l1->val == l3->val && l1->val == l4->val)
            return new Node(l1->val, 1);
        return new Node(0, 0, l1, l2, l3, l4);
    }
};