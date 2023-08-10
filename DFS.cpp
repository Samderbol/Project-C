#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* dfs(Node* root, int target) {
    // �����ǰ�ڵ�Ϊ�գ����ؿ�ָ��
    if (root == nullptr) {
        return nullptr;
    }

    // �����ǰ�ڵ��ֵ����Ŀ��ֵ�����ص�ǰ�ڵ�
    if (root->value == target) {
        return root;
    }

    // �ݹ�����������в���Ŀ��ڵ�
    Node* leftResult = dfs(root->left, target);
    if (leftResult != nullptr) {
        return leftResult;
    }

    // �ݹ�����������в���Ŀ��ڵ�
    Node* rightResult = dfs(root->right, target);
    if (rightResult != nullptr) {
        return rightResult;
    }

    // �������������û���ҵ�Ŀ��ڵ㣬���ؿ�ָ��
    return nullptr;
}

int main() {
    // ����������
    Node* root = new Node{ 1, nullptr, nullptr };
    root->left = new Node{ 2, nullptr, nullptr };
    root->right = new Node{ 3, nullptr, nullptr };
    root->left->left = new Node{ 4, nullptr, nullptr };
    root->left->right = new Node{ 5, nullptr, nullptr };

    // ʹ��DFS�㷨���ҽڵ�ֵΪ4�Ľڵ�
    Node* result = dfs(root, 4);

    // ������
    if (result != nullptr) {
        std::cout << "�ҵ��˽ڵ�ֵΪ4�Ľڵ�" << std::endl;
    }
    else {
        std::cout << "δ�ҵ��ڵ�ֵΪ4�Ľڵ�" << std::endl;
    }

    return 0;
}