#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelwise(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        cout << curr->data << " ";

        if (curr->left != NULL) q.push (curr->left);

        if (curr->right != NULL) q.push (curr->right);
    }
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* temp = new Node;
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


int main() {
    Node* root = NULL;
    int choice, value;
    int n;
    int arr[100];


    while (true) {
        cout << "\n1. Insert an Array\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Level Order Traversal\n";
        cout << "6. Delete Node\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter size of array: ";
            cin >> n;
            cout << "Enter array elements: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
            }

            for (int i = 0; i < n; i++) {
                root = insert(root, arr[i]);
            }
            
            break;
        case 2:
            cout << "Preorder -> ";
            preorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Inorder -> ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder -> ";
            postorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Level Wise -> ";
            levelwise(root);
            cout << endl;
            break;
        case 6:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 7:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }
}