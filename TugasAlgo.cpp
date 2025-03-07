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
    int i = 0;

    cout << "Masukkan Jumlah lagu yang ingin diinput : " << endl;
    cin >> jumlah;
    cin.ignore();

    do {
        cout << "Masukkan Judul Lagu : ";
        cin >> musik[jumlah_index].judul;
        if (nama_lagu_ada(musik, nama)) {
            cout << "Error Nama lagu udah ada di list" << endl;
            system("pause");
    
        }
    } while (nama_lagu_ada(musik, musik[jumlah_index].judul));
    
    musik[jumlah_index].tahun = jumlah_index + 1;
    while (i < jumlah) {
        cout << "Masukkan Penyanyi : ";
        cin >> musik[jumlah_index].penyanyi;
        cout << "Masukkan Genre Lagu : ";
        cin >> musik[jumlah_index].Genre;
        cout << "Masukkan Tahun Lagu : ";
        cin >> musik[jumlah_index].tahun;
        i++;
        
    } jumlah_index++;
}

void cari_lagu(lagu musik[]) {
    int awal = 0;
    int akhir = jumlah_index - 1;
    int tengah;
    bool found = false;
    string cari;
    cout << "Judul lagu yang ingin anda cari : " << endl;
    cin >> cari;
    while (!found && (awal <= akhir)) {
        tengah = (awal + akhir) / 2;
        if (musik[tengah].judul == cari) {
            found = true;
        }
        else if (musik[tengah].judul > cari) {
            akhir = tengah - 1;

        }
        else {
            awal = tengah + 1;
        }
    }
    if (found) {
        cout << "Lagu ditemukan" << endl;
        cout << "Penyanyi : " << tengah + 1 << endl;
        cout << "judul : " << musik[tengah].judul << endl;
        system("pause");
    }
    else {
        cout << "Judul dengan nama lagu " << cari << " dalam menu tidak ditemukan " << endl;

    }
}

int main () {
    int pilihan;
    string jawaban;
    do {
    cout << "Playlist Lagu" << endl;
    cout << "===================" << endl;
    cout << "1. Tambah Lagu" << endl;
    cout << "2. Cari Lagu" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih Menu : ";
    cin >> pilihan;
    if (pilihan == 1) {
        cout << endl;
        cout << "=============================================================" << endl;
        tambah_lagu(musik);
    }
    else if (pilihan == 2) {
        cari_lagu(musik);
    }
    cout << "mau lanjut? = ";
    cin >> jawaban;
    } while (jawaban == "Y" || jawaban == "y" || jawaban == "ya");

    return 0;
} 
