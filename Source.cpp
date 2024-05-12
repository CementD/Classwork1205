#include <iostream>
#include <initializer_list>
using namespace std;

template<class T>
struct Node {
    T value;
    Node* next;
    ~Node() {
        cout << "\ndestroyed\n";
    }
};

template<class T>
class LinkedList {
    Node<T>* head = nullptr;

public:
    LinkedList(initializer_list<T> values) {
        for (const T& value : values) {
            add(value);
        }
    }

    void add(const T& value) {
        Node<T>* newNode = new Node<T>;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    void print() const {
        Node<T>* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->value << " next node address: " << tmp->next << endl;
            tmp = tmp->next;
        }
    }

    void deleteFirst() {
        if (head == nullptr)
            return;
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
        cout << "First element is destroyed." << endl;
    }

    Node<T>* searchNode(const T& value) {
        Node<T>* tmp = head;
        while (tmp != nullptr) {
            if (tmp->value == value) {
                return tmp;
            }
            tmp = tmp->next;
        }
        return nullptr;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* tmp = head->next;
            delete head;
            head = tmp;
        }
    }
};

int main() {
    LinkedList<int> list{ 3, 2, 1, 0 };
    list.print();
    list.deleteFirst();
    list.print();

    Node<int>* node = list.searchNode(2);
    if (node != nullptr) {
        cout << "Node found with value: " << node->value << endl;
    }
    else {
        cout << "Node not found." << endl;
    }

    return 0;
}