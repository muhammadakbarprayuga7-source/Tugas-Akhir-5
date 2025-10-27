#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

bool search(Node* root, int value) {
    if (root == nullptr)
        return false;
    if (root->data == value)
        return true;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

int main() {
    Node* root = nullptr;
    int pilihan, angka;

    do {
        cout << "\n=== Binary Search Tree ===\n";
        cout << "1. Insert\n";
        cout << "2. Tampilkan (Inorder)\n";
        cout << "3. Cari Data\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> angka;
                root = insert(root, angka);
                break;
            case 2:
                cout << "Isi BST (Inorder): ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Masukkan angka yang dicari: ";
                cin >> angka;
                if (search(root, angka))
                    cout << "Data ditemukan!\n";
                else
                    cout << "Data tidak ditemukan!\n";
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}

