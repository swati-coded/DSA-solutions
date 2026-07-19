#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

void topView(Node *root) {
    if (root == NULL)
        return;

    map<int, int> top;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (top.find(hd) == top.end())
            top[hd] = curr->data;

        if (curr->left)
            q.push({curr->left, hd - 1});

        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    for (auto x : top)
        cout << x.second << " ";
}

}; /
