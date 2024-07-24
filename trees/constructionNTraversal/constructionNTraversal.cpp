#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node (int val): data(val) {
    left = nullptr;
    right = nullptr;
  }
};

vector<vector<int>> levels;

void preOrderTraversal(Node *node) {
  if (node == nullptr) {
    return;
  }
  cout << node->data << " ";
  preOrderTraversal(node->left);
  preOrderTraversal(node->right);
}

void inOrderTraversal(Node *node) {
  if (node == nullptr) {
    return;
  }
  inOrderTraversal(node->left);
  cout << node->data << " ";
  inOrderTraversal(node->right);
}

void postOrderTraversal(Node *node) {
  if (node == nullptr) {
    return;
  }
  postOrderTraversal(node->left);
  postOrderTraversal(node->right);
  cout << node->data << " ";
}

void levelOrderTraversal(Node *node) {
  if (node == nullptr) return;
  queue<Node*> q;
  q.push(node);
  while(!q.empty()) {
    int n = q.size();
    vector<int> level;
    for (int i = 0; i < n; i++) {
      Node *currNode = q.front();
      q.pop();
      if (currNode->left != nullptr) q.push(currNode->left);
      if (currNode->right != nullptr) q.push(currNode->right);
      level.push_back(currNode->data);
    }
    levels.push_back(level);
  }
}

int main() {
  Node *root = new Node(5);
  root->left = new Node(6);
  root->right = new Node(7);
  root->left->left = new Node(8);
  root->left->right = new Node(9);
  root->left->right->left = new Node(10);
  cout << "PreOrder: ";
  preOrderTraversal(root);
    cout << endl;
  cout << "InOrder: ";
  inOrderTraversal(root);
    cout << endl;
  cout << "PostOrder: ";
  postOrderTraversal(root);
    cout << endl;
  cout << "LevelOrder: ";
  levelOrderTraversal(root);
  for (int i = 0; i < levels.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < levels[i].size(); j++) {
      cout << levels[i][j] << " ";
    }
    cout << "] ";
  }
    cout << endl;

  delete root->left->right->left;
  delete root->left->right;
  delete root->left->left;
  delete root->right;
  delete root->left;
  delete root;
}
