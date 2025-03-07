#include <iostream>
using namespace std;
struct lagu
{
    string judul;
    string penyanyi;
    string Genre;
    int tahun;
    
};
lagu musik[100];
int jumlah_index = 0;
bool nama_lagu_ada(lagu musik[], string nama )
{
    for (int i = 0; i < jumlah_index; i++)
    {
        if (musik[i].judul == nama)
        {
            return true;
        }
    }
    return false;
}
void sorting(lagu musik[], int jumlah_index) {
    for (int i = 0; i < jumlah_index; i++) {
        for (int j = 0; j < jumlah_index - i -1; j++) {
            if (musik[j].judul > musik[j + 1].judul) {
                swap(musik[j], musik[j + 1]);
            }
        }
    }
}
void tambah_lagu(lagu musik[]) {
    string nama;
    bool found = false;
    int jumlah;

    cout << "Masukkan Jumlah lagu yang ingin diinput : " << endl;
    cin >> jumlah;
    cin.ignore();

   
    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan Judul Lagu : ";
        getline(cin, nama);

        if (nama_lagu_ada(musik, nama)) {
            cout << "Error! Nama lagu sudah ada di list. \n";
            i--;
            continue;
        }

        musik[jumlah_index].judul = nama;
        cout << "Masukkan Penyanyi : ";
        getline(cin, musik[jumlah_index].penyanyi);
        cout << "Masukkan Genre Lagu : ";
        getline(cin, musik[jumlah_index].Genre);
        cout << "Masukkan Tahun Lagu : ";
        cin >> musik[jumlah_index].tahun;
        cin.ignore(); 

        jumlah_index++;
    }
    
    sorting(musik, jumlah_index); 
}

void cari_lagu(lagu musik[], int jumlah_index) {

    sorting(musik, jumlah_index);

    string cari;
    cout << "Judul lagu yang ingin anda cari : ";
    getline(cin, cari);

    int awal = 0;
    int akhir = jumlah_index - 1;
    int tengah;
    bool found = false;

    while (found == false && awal <= akhir) {
        tengah = ((awal + akhir) / 2);
        if (musik[tengah].judul == cari) {
            cout << "Lagu ditemukan" << endl;
            cout << "Judul : " << musik[tengah].judul << endl;
            cout << "Penyanyi : " << musik[tengah].penyanyi << endl;
            cout << "Genre : " << musik[tengah].Genre << endl;
            cout << "Tahun : " << musik[tengah].tahun << endl;
            break;
        }
        else if (musik[tengah].judul > cari) {
            akhir = tengah - 1;

        }
        else {
            awal = tengah + 1;
        }
        cout << "Data tidak ditemukan" << endl;

    }
    
}
        

int main () {
    int pilihan;
    string jawaban;
    do {
    cout << "Playlist Lagu" << endl;
    for (int i = 0; i < jumlah_index; i++)
	{
		cout << i + 1 << ". " << musik[i].judul << " - " << musik[i].penyanyi << "(" << musik[i].tahun << ")" << endl;
	}
    cout << "===================" << endl;
    cout << "1. Tambah Lagu" << endl;
    cout << "2. Cari Lagu" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih Menu : ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        cout << endl;
        cout << "==============================================" << endl;
        tambah_lagu(musik);
    }
    else if (pilihan == 2) {
        cari_lagu(musik, jumlah_index);
    } else if (pilihan == 3) {
        return 0;
    }
    cout << "mau lanjut? = ";
    cin >> jawaban;
    } while (jawaban == "Y" || jawaban == "y" || jawaban == "ya");

    return 0;
} 