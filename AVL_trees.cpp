 #include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    int height;
};

int getHeight(node *root) {
    if (root == nullptr) return 0;
    return root->height;
}

int getBalance(node *root) {
    if (root == nullptr) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

node *createNode(int val) {
    node *NewNode = new node();
    NewNode->data = val;
    NewNode->left = nullptr;
    NewNode->right = nullptr;
    NewNode->height = 1;
    return NewNode;
}

// rotations
node *left(node *x) {
    node *y = x->right;
    node *T2 = y->left;

    // re-linking
    y->left = x;
    x->right = T2;
    
    // height balance (FIXED)
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

node *right(node *y) {
    node *x = y->left;
    node *T2 = x->right;
    
    // re-linking
    x->right = y;
    y->left = T2;
    
    // height updates
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return x;
}

node *insertNode(node *root, int val) {
    if (root == nullptr) {
        return createNode(val);
    }

    if (val < root->data) {
        root->left = insertNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = insertNode(root->right, val);
    }
    else return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && val < root->left->data) {
        return right(root);
    }
    if (balance > 1 && val > root->left->data) {
        root->left = left(root->left);
        return right(root);
    }
    if (balance < -1 && val > root->right->data) {
        return left(root); // FIXED: Was right(root)
    }
    if (balance < -1 && val < root->right->data) {
        root->right = right(root->right);
        return left(root);
    }
    
    return root;
}

node *findMin(node *root) {
    if (root == nullptr || root->left == nullptr)
        return root;
    return findMin(root->left);
}

node *dltNode(node *root, int val) {
    if (root == nullptr) return root;

    if (root->data > val) {
        root->left = dltNode(root->left, val); // FIXED: Added reassignment
    }
    else if (root->data < val) {
        root->right = dltNode(root->right, val); // FIXED: Added reassignment
    }
    else {
        if (root->left == nullptr || root->right == nullptr) {
            node *temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else {
                *root = *temp;
            }
            delete temp;
        }
        else {
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = dltNode(root->right, temp->data);
        }
    }

    if (root == nullptr) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return right(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = left(root->left);
        return right(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) { // FIXED: Was >= 0
        return left(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = right(root->right);
        return left(root);
    }

    return root;
}

void preorder(node *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {    
    node* root = nullptr;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    
    // Output should be: 30 20 10 25 40 50 
    preorder(root);
    
    return 0;
}