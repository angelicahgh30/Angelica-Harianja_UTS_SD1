/*
Nama  : Angelica Happy Grace Harianja
NIM   : 241401130
Soal  : Harry dan Koleksi Film Tengah Malam
*/

#include <iostream>
#include <string>
using namespace std;

// Struktur node Linked List
struct Node {
    string judul;
    int tahun;
    int rating;
    Node *next;
};

// Pointer head & tail global
Node *head = NULL;
Node *tail = NULL;

// Tambah di depan
void insertFirst(string judul, int tahun, int rating) {
    Node *newNode = new Node;
    newNode->judul = judul;
    newNode->tahun = tahun;
    newNode->rating = rating;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Tambah di belakang
void insertLast(string judul, int tahun, int rating) {
    Node *newNode = new Node;
    newNode->judul = judul;
    newNode->tahun = tahun;
    newNode->rating = rating;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Tambah di tengah (setelah film tertentu)
void insertAfter(string target, string judul, int tahun, int rating) {
    if (head == NULL) {
        cout << "Daftar film masih kosong, tambah dulu di depan!\n";
        return;
    }

    Node *p = head;
    while (p != NULL && p->judul != target) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Film \"" << target << "\" tidak ditemukan!\n";
        return;
    }

    Node *newNode = new Node;
    newNode->judul = judul;
    newNode->tahun = tahun;
    newNode->rating = rating;
    newNode->next = p->next;
    p->next = newNode;

    if (p == tail) tail = newNode;
}

// Hapus film berdasarkan judul
void deleteFilm(string target) {
    if (head == NULL) {
        cout << "Daftar film kosong!\n";
        return;
    }

    if (head->judul == target) {
        Node *hapus = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete hapus;
        cout << "Film \"" << target << "\" berhasil dihapus.\n";
        return;
    }

    Node *p = head;
    while (p->next != NULL && p->next->judul != target) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Film \"" << target << "\" tidak ditemukan.\n";
    } else {
        Node *hapus = p->next;
        p->next = hapus->next;
        if (hapus == tail) tail = p;
        delete hapus;
        cout << "Film \"" << target << "\" berhasil dihapus.\n";
    }
}

// Cetak daftar film
void printList() {
    if (head == NULL) {
        cout << "Daftar film kosong.\n";
        return;
    }

    Node *temp = head;
    int total = 0;
    while (temp != NULL) {
        cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
        temp = temp->next;
        total++;
    }

    cout << "\nTotal film tersisa: " << total << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah film awal: ";
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        string judul;
        int tahun, rating;

        cout << "\nFilm " << i << ":\n";
        cout << "Judul: ";
        getline(cin, judul);
        cout << "Tahun: ";
        cin >> tahun;
        cout << "Rating: ";
        cin >> rating;
        cin.ignore();

        insertLast(judul, tahun, rating);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    cin.ignore();

    if (hapus == 'y' || hapus == 'Y') {
        string target;
        cout << "Masukkan judul film yang sudah ditonton: ";
        getline(cin, target);
        deleteFilm(target);
    }

    cout << "\nDaftar Film Saat Ini:\n";
    printList();

    return 0;
}
