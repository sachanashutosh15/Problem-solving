#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int val): data(val), left(nullptr), right(nullptr) {}
};

void postOrderTraversal_2st(Node *root) {
  if (root == nullptr) return;
  stack<Node*> st1, st2;
  st1.push(root);
  while(!st1.empty()) {
    Node *currNode = st1.top();
    st1.pop();
    if (currNode->left) st1.push(currNode->left);
    if (currNode->right) st1.push(currNode->right);
    st2.push(currNode);
  }
  while(!st2.empty()) {
    cout << st2.top()->data << " ";
    st2.pop();
  }
  cout << endl;
}

void postOrderTraversal_1st(Node *root) {
  if (root == nullptr) return;
  stack<Node*> st;
  Node *currNode = root;
  Node *lastVisited = nullptr;
  while(!st.empty() || currNode != nullptr) {
    if (currNode != nullptr) {
      st.push(currNode);
      currNode = currNode->left;
    } else {
      Node *peekNode = st.top();
      if (peekNode->right != nullptr && lastVisited != peekNode->right) {
        currNode = peekNode->right;
      } else {
        cout << peekNode->data << " ";
        lastVisited = st.top();
        st.pop();
      }
    }
  }
  cout << endl;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(7);
  root->left->left = new Node(3);
  root->left->right = new Node(4);
  root->left->right->left = new Node(5);
  root->left->right->right = new Node(6);
  postOrderTraversal_1st(root);
  delete root->left->right->right;
  delete root->left->right->left;
  delete root->left->right;
  delete root->left->left;
  delete root->right;
  delete root->left;
  delete root;
}
