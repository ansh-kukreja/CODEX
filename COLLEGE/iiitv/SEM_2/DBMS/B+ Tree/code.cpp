#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 4;

class Node {
public:
    bool isLeaf;
    vector<int> keys;
    vector<Node*> children;
    Node* next;

    Node(bool leaf = false) {
        isLeaf = leaf;
        next = nullptr;
    }
};

class BPlusTree {
private:
    Node* root;

    Node* findLeaf(Node* curr, int key) {
        if (curr->isLeaf) return curr;

        int i = 0;
        while (i < curr->keys.size() && key >= curr->keys[i]) i++;

        return findLeaf(curr->children[i], key);
    }

    Node* findParent(Node* curr, Node* child) {
        if (curr == nullptr || curr->isLeaf) return nullptr;

        for (auto c : curr->children) {
            if (c == child) return curr;
        }

        for (auto c : curr->children) {
            Node* res = findParent(c, child);
            if (res != nullptr) return res;
        }

        return nullptr;
    }

    void insertSorted(vector<int>& keys, int key) {
        int i = 0;
        while (i < keys.size() && keys[i] < key) i++;
        keys.insert(keys.begin() + i, key);
    }

    int findKeyIndex(vector<int>& keys, int key) {
        for (int i = 0; i < keys.size(); i++) {
            if (keys[i] == key) return i;
        }
        return -1;
    }

    void insertInternal(int key, Node* curr, Node* child) {
        int i = 0;
        while (i < curr->keys.size() && key >= curr->keys[i]) i++;

        curr->keys.insert(curr->keys.begin() + i, key);
        curr->children.insert(curr->children.begin() + i + 1, child);

        if (curr->keys.size() > MAX) {
            int mid = MAX / 2;

            Node* newInternal = new Node(false);
            int upKey = curr->keys[mid];

            newInternal->keys.assign(curr->keys.begin() + mid + 1, curr->keys.end());
            curr->keys.resize(mid);

            newInternal->children.assign(curr->children.begin() + mid + 1, curr->children.end());
            curr->children.resize(mid + 1);

            if (curr == root) {
                Node* newRoot = new Node(false);
                newRoot->keys.push_back(upKey);
                newRoot->children.push_back(curr);
                newRoot->children.push_back(newInternal);
                root = newRoot;
            } else {
                Node* parent = findParent(root, curr);

                if (parent == nullptr) {
                    Node* newRoot = new Node(false);
                    newRoot->keys.push_back(upKey);
                    newRoot->children.push_back(curr);
                    newRoot->children.push_back(newInternal);
                    root = newRoot;
                } else {
                    insertInternal(upKey, parent, newInternal);
                }
            }
        }
    }

public:
    BPlusTree() {
        root = new Node(true);
    }

    void insert(int key) {
        Node* leaf = findLeaf(root, key);

        insertSorted(leaf->keys, key);

        if (leaf->keys.size() > MAX) {
            int mid = (MAX + 1) / 2;

            Node* newLeaf = new Node(true);

            newLeaf->keys.assign(leaf->keys.begin() + mid, leaf->keys.end());
            leaf->keys.resize(mid);

            newLeaf->next = leaf->next;
            leaf->next = newLeaf;

            int newKey = newLeaf->keys[0];

            if (leaf == root) {
                Node* newRoot = new Node(false);
                newRoot->keys.push_back(newKey);
                newRoot->children.push_back(leaf);
                newRoot->children.push_back(newLeaf);
                root = newRoot;
            } 
            else {
                Node* parent = findParent(root, leaf);

                if (parent == nullptr) {
                    Node* newRoot = new Node(false);
                    newRoot->keys.push_back(newKey);
                    newRoot->children.push_back(leaf);
                    newRoot->children.push_back(newLeaf);
                    root = newRoot;
                } else {
                    insertInternal(newKey, parent, newLeaf);
                }
            }
        }
    }

    void displayTree() {
        if (!root) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                Node* node = q.front();
                q.pop();

                cout << "[ ";
                for (int k : node->keys) cout << k << " ";
                cout << "] ";

                if (!node->isLeaf) {
                    for (auto c : node->children)
                        q.push(c);
                }
            }
            cout << endl;
        }
    }

    void remove(int key) {
        Node* leaf = findLeaf(root, key);

        int idx = findKeyIndex(leaf->keys, key);
        if (idx != -1) {
            leaf->keys.erase(leaf->keys.begin() + idx);
        }
    }

    void modify(int oldKey, int newKey) {
        remove(oldKey);
        insert(newKey);
    }
};

int main() {
    BPlusTree tree;

    for(int i = 1; i <= 50; i++) {
        tree.insert(i);
    }

    cout<<"\n-- B+ Tree --\n";
    tree.displayTree();

    for(int i = 51; i <= 55; i++) {
        tree.insert(i);
    }

    cout<<"\n-- After inserting 5 new userIds --\n";
    tree.displayTree();

    tree.modify(10, 1010);
    tree.modify(20, 2020);
    tree.modify(30, 3030);
    tree.modify(40, 4040);
    tree.modify(50, 5050);

    cout<<"\n-- After modifying 5 records --\n";
    tree.displayTree();

    tree.remove(1);
    tree.remove(2);
    tree.remove(3);
    tree.remove(4);
    tree.remove(5);

    cout<<"\n-- After deleting 5 records --\n";
    tree.displayTree();

    return 0;
}