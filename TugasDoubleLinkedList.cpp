#include <iostream>
using namespace std;

struct Node
{
    string judul;
    string penulis;
    Node* next;
    Node* prev;
};

 struct Node* buatnode(string judul, string penulis){
    Node* newNode = new Node{judul,penulis, NULL, NULL};
    return newNode;
}

void sisipnodedepan(Node** head, string judul, string penulis) {
    Node* newNode = buatnode(judul, penulis);
    newNode->next = *head;
    if(*head != NULL) {
        (*head)->prev = newNode;

    }
    *head = newNode;
}

void sisipnodebelakang(Node** head, string judul, string penulis) {
    Node* newNode = buatnode(judul, penulis);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* bantu = *head;
    while(bantu->next != NULL){
        bantu = bantu->next;
    }
    bantu->next = newNode;
    newNode->prev = bantu;
}

Node* searching(Node* head, string judul) {
    Node* bantu = head;
    while(bantu != NULL){
        if(bantu-> judul == judul) {
            return bantu;
        }
        bantu = bantu->next;
     }
     return NULL;
     
}

void sisipnodetengah(Node* nodekiri, string judul, string penulis) {
    if(nodekiri == NULL){
        cout << "Node tidak ada" << endl;
    }
    Node* newNode = buatnode(judul, penulis);
    newNode->next = nodekiri->next;
    newNode->prev = nodekiri;

    if(nodekiri->next != NULL) {
        nodekiri->next->prev = newNode;
    }
    nodekiri->next = newNode;
}

void hapusnodedepan(Node** head){

    if(*head == NULL){
        cout << "List Kosong" << endl;
        return;
    }

    Node* bantu = *head;
    *head = (*head)->next;
    if(*head != NULL){
        (*head)->prev = NULL;
    }
    delete bantu;

}

void hapusnodebelakang(Node** head){

    if(*head == NULL){
        cout << "List Kosong" << endl;
        return;
    }
    Node* bantu = *head;
    while(bantu->next != NULL){
        bantu = bantu->next;
    }
    if(bantu->prev !=NULL)
    {
        bantu->prev->next = NULL;
    }else{
        *head = NULL;
    }
    delete bantu;

}

void hapusnodetengah(Node** head, string key){
    if(*head == NULL){
        cout << "List Kosong" << endl;
        return;

    }
    Node* bantu = *head;
    while(bantu != NULL && bantu->judul != key){
        bantu = bantu->next;
    }
    if(bantu == NULL){
        cout << "Buku ga ketemu!" << endl;
        return;
    }
    if(bantu->prev != NULL) {
        bantu->prev->next = bantu->next;
    }else{
        *head = bantu->next;
    }
    if(bantu->next != NULL){
        bantu->next->prev = bantu->prev;
    }
    delete bantu;
    cout << "Buku " << key << " Berhasil Dihapus" << endl; 
}
void printdaridepan(Node* head){

    if(head == NULL){
        cout << "Node nya ga ada!" << endl;
    }
    Node* bantu = head;
    cout << "Daftar Buku : " << endl;
    while(bantu != NULL){
        cout << "Buku : " << bantu->judul << endl;
        cout << "Penulis : " << bantu->penulis << endl << endl;
        bantu = bantu->next;
    }
}

void printdaribelakang(Node* head){

    if(head == NULL){
        cout << "Node nya ga ada!" << endl;
        return;
    }
    Node* bantu = head;
    while(bantu->next != NULL){ // buat jalan ke ujung list
        bantu = bantu->next;
    }
    while(bantu != NULL){ // buat jalan dari belakang ke depan

        cout << " Buku : " << bantu->judul << ", Penulis : " << bantu->penulis << endl;  
        bantu= bantu->prev;
    }
    cout << endl;
}

main() {
    Node* head = NULL;
    int pilihan;
    string judul, penulis;
    char lanjut = 'y';

    do {
    cout << "== Menu Manajemen Toko Buku ==" << endl;
    cout << "Selamat datang di toko buku" << endl;
    cout << "1. Tambah Buku di Depan" << endl;
    cout << "2. Tambah Buku di Belakang" << endl;
    cout << "3. Hapus Buku berdasarkan Judul" << endl;
    cout << "4. Tampilkan Daftar Buku" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore();

    switch (pilihan) {
            case 1:
                cout << "Masukkan Judul: ";
                getline(cin, judul);
                cout << "Masukkan Penulis: ";
                getline(cin, penulis);
                sisipnodedepan(&head, judul, penulis);
                break;

            case 2:
                cout << "Masukkan Judul: ";
                getline(cin, judul);
                cout << "Masukkan Penulis: ";
                getline(cin, penulis);
                sisipnodebelakang(&head, judul, penulis);
                break;

            case 3:
                cout << "Masukkan Judul Buku yang akan dihapus: ";
                getline(cin, judul);
                hapusnodetengah(&head, judul);
                break;

            case 4:
                printdaridepan(head);
                break;

            case 5:
                cout << "Terima kasih telah menggunakan Menu Manajemen ini!" << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

        cout << "Kembali ke menu? (y/n): ";
        cin >> lanjut;
        cin.ignore();
    } while (lanjut == 'y' || lanjut == 'Y');

    cout << "Terima kasih telah menggunakan Menu Manajemen ini! " << endl;
    return 0;
}





