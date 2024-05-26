#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> items; // Stack elemanlarını tutmak için vektör kullanılıyor
public:
    void push(int item) { // Stack'e eleman ekler
        items.push_back(item);
    }

    void pop() { // Stack'ten eleman çıkarır
        if (!items.empty()) {
            items.pop_back();
        }
        else {
            cout << "Yigin bos!" << endl;
        }
    }

    void clear() { // Stack'i temizler
        items.clear();
    }

    void display() { // Stack'teki elemanları gösterir
        for (int i = items.size() - 1; i >= 0; i--) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    int size() { // Stack'teki eleman sayısını döner
        return items.size();
    }
};

#include <iostream>
#include <list>
using namespace std;

class Queue {
private:
    list<int> items; // Queue elemanlarını tutmak için list kullanılıyor
public:
    void enqueue(int item) { // Queue'ya eleman ekler
        items.push_back(item);
    }

    void dequeue() { // Queue'dan eleman çıkarır
        if (!items.empty()) {
            items.pop_front();
        }
        else {
            cout << "Kuyruk bos!" << endl;
        }
    }

    void clear() { // Queue'yu temizler
        items.clear();
    }

    void display() { // Queue'daki elemanları gösterir
        for (auto item : items) {
            cout << item << " ";
        }
        cout << endl;
    }

    int size() { // Queue'daki eleman sayısını döner
        return items.size();
    }
};

#include <iostream>
using namespace std;

struct Node {
    int data; // Node'un veri kısmı
    Node* next; // Sonraki Node'u işaret eden pointer
};

class SinglyLinkedList {
private:
    Node* head; // Listenin başını işaret eden pointer
public:
    SinglyLinkedList() : head(nullptr) {}

    void add_to_start(int data) { // Listenin başına eleman ekler
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void add_to_end(int data) { // Listenin sonuna eleman ekler
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove_from_start() { // Listenin başından eleman çıkarır
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            cout << "Liste bos!" << endl;
        }
    }

    void remove_from_end() { // Listenin sonundan eleman çıkarır
        if (head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            }
            else {
                Node* current = head;
                while (current->next->next != nullptr) {
                    current = current->next;
                }
                delete current->next;
                current->next = nullptr;
            }
        }
        else {
            cout << "Liste bos!" << endl;
        }
    }

    void clear() { // Listeyi temizler
        while (head != nullptr) {
            remove_from_start();
        }
    }

    void display() { // Listedeki elemanları gösterir
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int size() { // Listedeki eleman sayısını döner
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

#include <iostream>
using namespace std;

struct TreeNode {
    int data; // Ağacın düğümünün veri kısmı
    TreeNode* left; // Sol alt düğümü işaret eden pointer
    TreeNode* right; // Sağ alt düğümü işaret eden pointer
};

class BinaryTree {
private:
    TreeNode* root; // Ağacın kök düğümünü işaret eden pointer

    void addHelper(TreeNode*& node, int data) { // Yardımcı fonksiyon: Ağaca eleman ekler
        if (node == nullptr) {
            node = new TreeNode();
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
        }
        else if (data < node->data) {
            addHelper(node->left, data);
        }
        else {
            addHelper(node->right, data);
        }
    }

    void inOrderHelper(TreeNode* node) { // Yardımcı fonksiyon: Ağacı in-order dolaşır
        if (node != nullptr) {
            inOrderHelper(node->left);
            cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }

    void preOrderHelper(TreeNode* node) { // Yardımcı fonksiyon: Ağacı pre-order dolaşır
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    void postOrderHelper(TreeNode* node) { // Yardımcı fonksiyon: Ağacı post-order dolaşır
        if (node != nullptr) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            cout << node->data << " ";
        }
    }

    void clearHelper(TreeNode*& node) { // Yardımcı fonksiyon: Ağacı temizler
        if (node != nullptr) {
            clearHelper(node->left);
            clearHelper(node->right);
            delete node;
            node = nullptr;
        }
    }

    int sizeHelper(TreeNode* node) { // Yardımcı fonksiyon: Ağacın boyutunu hesaplar
        if (node == nullptr) {
            return 0;
        }
        else {
            return 1 + sizeHelper(node->left) + sizeHelper(node->right);
        }
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    TreeNode* removeHelper(TreeNode* node, int data) {
        if (node == nullptr) return node;

        if (data < node->data) {
            node->left = removeHelper(node->left, data);
        }
        else if (data > node->data) {
            node->right = removeHelper(node->right, data);
        }
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeHelper(node->right, temp->data);
        }
        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    void add(int data) { // Ağaca eleman ekler
        addHelper(root, data);
    }

    void remove(int data) { // Ağaçtan eleman siler
        root = removeHelper(root, data);
    }

    void inOrder() { // Ağacı in-order dolaşır ve elemanları gösterir
        inOrderHelper(root);
        cout << endl;
    }

    void preOrder() { // Ağacı pre-order dolaşır ve elemanları gösterir
        preOrderHelper(root);
        cout << endl;
    }

    void postOrder() { // Ağacı post-order dolaşır ve elemanları gösterir
        postOrderHelper(root);
        cout << endl;
    }

    void clear() { // Ağacı temizler
        clearHelper(root);
    }

    int size() { // Ağacın boyutunu döner
        return sizeHelper(root);
    }
};

#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<vector<int>> table; // Hash tablosunu tutmak için vektörlerin vektörü
    int size; // Hash tablosunun boyutu
public:
    HashTable(int size) : size(size) {
        table.resize(size);
    }

    int hashFunction(int key) { // Hash fonksiyonu
        return key % size;
    }

    void insert(int key) { // Hash tablosuna eleman ekler
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) { // Hash tablosundan eleman siler
        int index = hashFunction(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == key) {
                chain.erase(it);
                return;
            }
        }
        cout << "Eleman bulunamadi!" << endl;
    }

    void display() { // Hash tablosundaki elemanları gösterir
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            for (int j : table[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void clear() { // Hash tablosunu temizler
        for (auto& chain : table) {
            chain.clear();
        }
    }
};

#include <iostream>
using namespace std;

void stackMenu() {
    Stack stack;
    int choice, value;
    while (true) {
        cout << "Yigin icin islem seciniz:\n";
        cout << "1- Yigina eleman ekle\n";
        cout << "2- Yigindan eleman cikar\n";
        cout << "3- Yigini temizle\n";
        cout << "4- Yigindaki elemanlari goster\n";
        cout << "5- Yigindaki eleman sayisini goster\n";
        cout << "6- Ana menuye geri don\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Eklenecek elemani giriniz: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.clear();
            break;
        case 4:
            stack.display();
            break;
        case 5:
            cout << "Yigindaki eleman sayisi: " << stack.size() << endl;
            break;
        case 6:
            return;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    }
}

void queueMenu() {
    Queue queue;
    int choice, value;
    while (true) {
        cout << "Kuyruk icin islem seciniz:\n";
        cout << "1- Kuyruga eleman ekle\n";
        cout << "2- Kuyruktan eleman cikar\n";
        cout << "3- Kuyrugu temizle\n";
        cout << "4- Kuyruktaki elemanlari goster\n";
        cout << "5- Kuyruktaki eleman sayisini goster\n";
        cout << "6- Ana menuye geri don\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Eklenecek elemani giriniz: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.clear();
            break;
        case 4:
            queue.display();
            break;
        case 5:
            cout << "Kuyruktaki eleman sayisi: " << queue.size() << endl;
            break;
        case 6:
            return;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    }
}

void listMenu() {
    SinglyLinkedList list;
    int choice, value;
    while (true) {
        cout << "Bagli Liste icin islem seciniz:\n";
        cout << "1- Listeye eleman ekle\n";
        cout << "2- Listeden eleman cikar\n";
        cout << "3- Listeyi temizle\n";
        cout << "4- Listedeki elemanlari goster\n";
        cout << "5- Listedeki eleman sayisini goster\n";
        cout << "6- Ana menuye geri don\n";
        cin >> choice;

        switch (choice) {
        case 1:
            int sub_choice;
            cout << "Eklenme turunu seciniz:\n";
            cout << "1- Araya eleman ekle\n";
            cout << "2- Sona eleman ekle\n";
            cout << "3- Liste islemlerine geri don\n";
            cin >> sub_choice;

            if (sub_choice == 1) {
                cout << "Eklenecek elemani giriniz: ";
                cin >> value;
                list.add_to_start(value);
            }
            else if (sub_choice == 2)
            {
                cout << "Eklenecek elemani giriniz: ";
                cin >> value;
                list.add_to_end(value);
            }
            else if (sub_choice == 3)
            {
                // Return to main menu
                break;
            }
            else {
                cout << "Gecersiz secim!" << endl;
            }
            break;
        case 2:
            cout << "Cikarma turunu seciniz:\n";
            cout << "1- Aradan eleman cikar\n";
            cout << "2- Sondan eleman cikar\n";
            cout << "3- Liste islemlerine geri don\n";
            cin >> sub_choice;
            if (sub_choice == 1) {
                list.remove_from_start();
            }
            else if (sub_choice == 2) {
                list.remove_from_end();
            }
            else if (sub_choice == 3) {
                // Return to main menu
                break;
            }
            else {
                cout << "Gecersiz secim!" << endl;
            }
            break;
        case 3:
            list.clear();
            break;
        case 4:
            list.display();
            break;
        case 5:
            cout << "Listedeki eleman sayisi: " << list.size() << endl;
            break;
        case 6:
            return;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    }
}


void treeMenu() {
    BinaryTree tree;
    int choice, value;
    while (true) {
        cout << "Ikili Agac icin islem seciniz:\n";
        cout << "1- Agaca eleman ekle\n";
        cout << "2- Agactan eleman cikar\n";
        cout << "3- Agaci temizle\n";
        cout << "4- Agactaki eleman sayisini goster\n";
        cout << "5- Agaci InOrder dolasarak elemanlari goster\n";
        cout << "6- Agaci PreOrder dolasarak elemanlari goster\n";
        cout << "7- Agaci PostOrder dolasarak elemanlari goster\n";
        cout << "8- Ana menuye geri don\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Eklenecek elemani giriniz: ";
            cin >> value;
            tree.add(value);
            cout << "Yeni eleman eklenmistir ";
            break;
        case 2:
            cout << "Silinecek elemani giriniz: ";
            cin >> value;
            tree.remove(value);
            cout << "Eleman silme islemi gerceklesmistir: ";
            break;
        case 3:
            tree.clear();
            break;
        case 4:
            cout << "Agactaki eleman sayisi: " << tree.size() << endl;
            break;
        case 5:
            tree.inOrder();
            break;
        case 6:
            tree.preOrder();
            break;
        case 7:
            tree.postOrder();
            break;
        case 8:
            return;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    }
}

// Hash Table menu function
void hashTableMenu() {
    HashTable* table = nullptr;
    int choice, value;

    while (true) {
        cout << "Cirpilanma (Hash Tablosu) icin islem seciniz:\n";
        cout << "1- Tabloya Eleman Ekle\n";
        cout << "2- Tablodan Eleman Sil\n";
        cout << "3- Tabloyu Temizle\n";
        cout << "4- Tabloyu Goster\n";
        cout << "5- Ana menuye geri don\n";
        cin >> choice;

        switch (choice) {
        case 1:
            if (table == nullptr) {
                int size;
                cout << "Hash Tablo boyutunu giriniz: ";
                cin >> size;
                table = new HashTable(size);
            }
            cout << "Eklenecek elemani giriniz: ";
            cin >> value;
            table->insert(value);
            break;
        case 2:
            if (table != nullptr) {
                cout << "Silinecek elemani giriniz: ";
                cin >> value;
                table->remove(value);
            }
            else {
                cout << "Oncelikle tablo olusturulmali!" << endl;
            }
            break;
        case 3:
            if (table != nullptr) {
                table->clear();
            }
            else {
                cout << "Oncelikle tablo olusturulmali!" << endl;
            }
            break;
        case 4:
            if (table != nullptr) {
                table->display();
            }
            else {
                cout << "Oncelikle tablo olusturulmali!" << endl;
            }
            break;
        case 5:
            delete table;
            return;
        default:
            cout << "Gecersiz secim!" << endl;
        }
    }
}


int main() {
    int choice;
    while (true) {
        cout << "Yapmak istediginiz uygulamayi seciniz:\n";
        cout << "1- Yigin Uygulamasi\n";
        cout << "2- Kuyruk Uygulamasi\n";
        cout << "3- Tek Yonlu Bagli Liste Uygulamasi\n";
        cout << "4- Ikili Agac Uygulamasi\n";
        cout << "5- Cirpilama Uygulamasi\n";
        cout << "6- Programdan Cikis\n";
        cin >> choice;

        switch (choice) {
        case 1:
            stackMenu(); // Stack uygulaması
            break;
        case 2:
            queueMenu(); // Queue uygulaması
            break;
        case 3:
            listMenu(); // Tek yönlü bağlı liste uygulaması
            break;
        case 4:
            treeMenu(); // İkili ağaç uygulaması
            break;
        case 5:
            hashTableMenu(); // Hash tablosu uygulaması
            break;
        case 6:
            cout << "Program sonlandiriliyor...\n";
            return 0; // Programdan çıkış
        default:
            cout << "Gecersiz secim!" << endl;
        }
    }
}