#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    string nama;
    string nim;
    Node* next;
};

// Define the Queue class
class Queue {
private:
    Node* front;
    Node* back;

public:
    // Constructor to initialize an empty queue
    Queue() {
        front = NULL;
        back = NULL;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Add a new element to the back of the queue
    void enqueue(string nama, string nim) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = NULL;

        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    // Remove the front element of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Count the number of elements in the queue
    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Clear all elements from the queue
    void clearQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Display all elements in the queue
    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Data antrian mahasiswa:" << endl;
            Node* current = front;
            int position = 1;
            while (current != NULL) {
                cout << position << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
                current = current->next;
                position++;
            }
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue("aldi", "2311102328");
    queue.enqueue("kakak", "2311102000");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.dequeue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;
    return 0;
}
