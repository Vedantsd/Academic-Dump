#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool lthread;
    bool rthread;
};

Node* root = nullptr;
Node* dummy = nullptr;

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->lthread = newNode->rthread = true;
    return newNode;
}

Node* inorderSuccessor(Node* node) {
    if (node->rthread) return node->right;
    node = node->right;
    while (!node->lthread) node = node->left;
    return node;
}

Node* inorderPredecessor(Node* node) {
    if (node->lthread) return node->left;
    node = node->left;
    while (!node->rthread) node = node->right;
    return node;
}

Node* caseA(Node* root, Node* parent, Node* ptr) {
    if (parent == nullptr) {
        root = nullptr;
    } else if (ptr == parent->left) {
        parent->lthread = true;
        parent->left = ptr->left;
    } else {
        parent->rthread = true;
        parent->right = ptr->right;
    }
    delete ptr;
    return root;
}

Node* caseB(Node* root, Node* parent, Node* ptr) {
    Node* child;
    if (!ptr->lthread) child = ptr->left;
    else child = ptr->right;

    if (parent == nullptr) {
        root = child;
    } else if (ptr == parent->left) {
        parent->left = child;
    } else {
        parent->right = child;
    }

    Node* s = inorderSuccessor(ptr);
    Node* p = inorderPredecessor(ptr);

    if (!ptr->lthread) p->right = s;
    else {
        if (!ptr->rthread) s->left = p;
    }

    delete ptr;
    return root;
}

Node* caseC(Node* root, Node* parent, Node* ptr) {
    Node* parsucc = ptr;
    Node* succ = ptr->right;

    while (!succ->lthread) {
        parsucc = succ;
        succ = succ->left;
    }

    ptr->data = succ->data;

    if (succ->lthread && succ->rthread) root = caseA(root, parsucc, succ);
    else root = caseB(root, parsucc, succ);

    return root;
}

void inorderRecursive(Node* node) {
    if (node == nullptr || node == dummy) return;
    if (!node->lthread) inorderRecursive(node->left);
    cout << node->data << " ";
    if (!node->rthread) inorderRecursive(node->right);
}

void preorderRecursive(Node* node) {
    if (node == nullptr || node == dummy) return;
    cout << node->data << " ";
    if (!node->lthread) preorderRecursive(node->left);
    if (!node->rthread) preorderRecursive(node->right);
}

void postorderRecursive(Node* node) {
    if (node == nullptr || node == dummy) return;
    if (!node->lthread) postorderRecursive(node->left);
    if (!node->rthread) postorderRecursive(node->right);
    cout << node->data << " ";
}

void initialize() {
    dummy = createNode(-1);
    dummy->left = dummy;
    dummy->right = dummy;
    dummy->lthread = false;
    root = dummy;
}

void insert(int data) {
    Node* newNode = createNode(data);

    if (root == dummy) {
        root = newNode;
        newNode->left = dummy;
        newNode->right = dummy;
        dummy->left = root;
        dummy->lthread = false;
        return;
    }

    Node* parent = nullptr;
    Node* current = root;

    while (current != dummy) {
        parent = current;
        if (data < current->data) {
            if (!current->lthread) current = current->left;
            else break;
        } else if (data > current->data) {
            if (!current->rthread) current = current->right;
            else break;
        } else {
            cout << "Duplicate key" << endl;
            delete newNode;
            return;
        }
    }

    if (data < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->lthread = false;
        parent->left = newNode;
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rthread = false;
        parent->right = newNode;
    }
}

void deleteNode(int data) {
    Node* parent = nullptr;
    Node* ptr = root;
    bool found = false;

    while (ptr != dummy) {
        if (data == ptr->data) {
            found = true;
            break;
        }
        parent = ptr;
        if (data < ptr->data) {
            if (!ptr->lthread) ptr = ptr->left;
            else break;
        } else {
            if (!ptr->rthread) ptr = ptr->right;
            else break;
        }
    }

    if (!found) {
        cout << "Node not found" << endl;
        return;
    }

    if (ptr->lthread && ptr->rthread) {
        root = caseA(root, parent, ptr);
    } else if (!ptr->lthread && !ptr->rthread) {
        root = caseC(root, parent, ptr);
    } else {
        root = caseB(root, parent, ptr);
    }

    if (root == nullptr) {
        root = dummy;
        dummy->left = dummy;
        dummy->lthread = false;
    }

    cout << "Node deleted" << endl;
}

void inorderNonRecursive() {
    if (root == dummy) {
        cout << "Tree is empty" << endl;
        return;
    }

    Node* current = root;
    while (!current->lthread) current = current->left;

    while (current != dummy) {
        cout << current->data << " ";
        current = inorderSuccessor(current);
    }
    cout << endl;
}

void preorderNonRecursive() {
    if (root == dummy) {
        cout << "Tree is empty" << endl;
        return;
    }

    Node* current = root;
    while (current != dummy) {
        cout << current->data << " ";
        if (!current->lthread) current = current->left;
        else if (!current->rthread) current = current->right;
        else {
            while (current != dummy && current->rthread) current = current->right;
            if (current != dummy) current = current->right;
        }
    }
    cout << endl;
}

void postorderNonRecursive() {
    if (root == dummy) {
        cout << "Tree is empty" << endl;
        return;
    }

    stack<Node*> s;
    Node* current = root;
    Node* lastVisited = nullptr;

    while (!s.empty() || current != dummy) {
        if (current != dummy && !current->lthread) {
            s.push(current);
            current = current->left;
        } else {
            if (current == dummy && !s.empty()) current = s.top();

            if (current->rthread || current->right == dummy || current->right == lastVisited) {
                cout << current->data << " ";
                lastVisited = current;
                if (!s.empty()) s.pop();
                current = dummy;
            } else {
                s.push(current);
                current = current->right;
            }
        }
    }
    cout << endl;
}

void inorderRec() {
    if (root == dummy) {
        cout << "Tree is empty" << endl;
        return;
    }
    inorderRecursive(root);
    cout << endl;
}

void preorderRec() {
    if (root == dummy) {
        cout << "Tree is empty" << endl;
        return;
    }
    preorderRecursive(root);
    cout << endl;
}

void postorderRec() {
    if (root == dummy) {
        cout << "Tree is empty" << endl;
        return;
    }
    postorderRecursive(root);
    cout << endl;
}

bool search(int data) {
    Node* current = root;
    while (current != dummy) {
        if (data == current->data) return true;
        else if (data < current->data) {
            if (!current->lthread) current = current->left;
            else return false;
        } else {
            if (!current->rthread) current = current->right;
            else return false;
        }
    }
    return false;
}

int main() {
    initialize();
    int choice, value;

    do {
        cout << "\n1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Inorder Non-Recursive" << endl;
        cout << "4. Preorder Non-Recursive" << endl;
        cout << "5. Postorder Non-Recursive" << endl;
        cout << "6. Inorder Recursive" << endl;
        cout << "7. Preorder Recursive" << endl;
        cout << "8. Postorder Recursive" << endl;
        cout << "9. Search" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                deleteNode(value);
                break;
            case 3:
                inorderNonRecursive();
                break;
            case 4:
                preorderNonRecursive();
                break;
            case 5:
                postorderNonRecursive();
                break;
            case 6:
                inorderRec();
                break;
            case 7:
                preorderRec();
                break;
            case 8:
                postorderRec();
                break;
            case 9:
                cout << "Enter value: ";
                cin >> value;
                if (search(value)) cout << "Found" << endl;
                else cout << "Not found" << endl;
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}