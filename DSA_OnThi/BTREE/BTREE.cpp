#include <iostream>

struct BTreeNode {
    int numKeys;
    int keys[4];
    BTreeNode* children[5];
    bool isLeaf;

    BTreeNode() {
        numKeys = 0;
        for (int i = 0; i < 4; i++) {
            keys[i] = 0;
            children[i] = nullptr;
        }
        children[4] = nullptr;
        isLeaf = true;
    }
};

void preOrderTraversal(BTreeNode* root) {
    if (root != nullptr) {
        for (int i = 0; i < root->numKeys; i++) {
            std::cout << root->keys[i] << " ";
        }
        for (int i = 0; i <= root->numKeys; i++) {
            preOrderTraversal(root->children[i]);
        }
    }
}
void postOrderTraversal(BTreeNode* root) {
    if (root != nullptr) {
        for (int i = 0; i <= root->numKeys; i++) {
            postOrderTraversal(root->children[i]);
        }
        for (int i = 0; i < root->numKeys; i++) {
            std::cout << root->keys[i] << " ";
        }
    }
}
int main() {
    BTreeNode* root = new BTreeNode();
    root->keys[0] = 40;
    root->keys[1] = 70;
    root->numKeys = 2;

    BTreeNode* child1 = new BTreeNode();
    child1->keys[0] = 10;
    child1->keys[1] = 20;
    child1->keys[2] = 30;
    child1->numKeys = 3;

    BTreeNode* child2 = new BTreeNode();
    child2->keys[0] = 50;
    child2->keys[1] = 60;
    child2->numKeys = 2;

    BTreeNode* child3 = new BTreeNode();
    child3->keys[0] = 80;
    child3->keys[1] = 90;
    child3->keys[2] = 100;
    child3->numKeys = 3;

    root->children[0] = child1;
    root->children[1] = child2;
    root->children[2] = child3;

    postOrderTraversal(root);

    return 0;
}