// Soal2.cpp
// Author: Ariel Ahnaf Kusuma
// NIM: 103112400050
// Deskripsi: Program ini mengimplementasikan dll 
// yg diinput oleh user itu ganjil atau genap.
 
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int v): data(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList(): head(nullptr) {}
    ~DoublyLinkedList(){
        Node* cur = head;
        while(cur){
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    void insertEnd(int val){
        Node* node = new Node(val);
        if(!head){
            head = node;
            return;
        }
        Node* cur = head;
        while(cur->next) cur = cur->next;
        cur->next = node;
        node->prev = cur;
    }

    void deleteLast(){
        if(!head) return;
        if(!head->next){
            delete head;
            head = nullptr;
            return;
        }
        Node* cur = head;
        while(cur->next) cur = cur->next;
        cur->prev->next = nullptr;
        delete cur;
    }

    void viewFront(){
        if(!head){
            cout << endl;
            return;
        }
        Node* cur = head;
        bool first = true;
        while(cur){
            if(!first) cout << " ";
            cout << cur->data;
            first = false;
            cur = cur->next;
        }
        cout << endl;
    }

    void reverseInPlace(){
        if(!head) return;
        Node* cur = head;
        Node* temp = nullptr;
        while(cur){
            temp = cur->prev;
            cur->prev = cur->next;
            cur->next = temp;
            cur = cur->prev;
        }
        if(temp) head = temp->prev;
    }
};

int main(){
    DoublyLinkedList dll;
    int choice;
    do{
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> choice;
        switch(choice){
            case 1: {
                cout << "Masukkan nilai: ";
                int v; cin >> v;
                dll.insertEnd(v);
                break;
            }
            case 2:
                dll.deleteLast();
                break;
            case 3:
                dll.viewFront();
                break;
            case 4:
                dll.reverseInPlace();
                cout << "List setelah di-reverse: ";
                dll.viewFront();
                break;
            case 0:
                break;
            default:
                break;
        }
    } while(choice != 0);

    return 0;
}
