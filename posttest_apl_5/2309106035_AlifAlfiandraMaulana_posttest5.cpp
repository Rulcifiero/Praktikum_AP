#include <iostream>
using namespace std;

struct Album {
    string namaAlbum;
    string artist;
    int tahun;
};

struct Song {
    string judul;
    string artist;
    int peringkat;
    Album* infoAlbum;
};

Song chart[10];
int peringkatchart = 0;
bool loginBerhasil = false;

void TambahLagu() {
    if (peringkatchart < 10) {
        Song* lagubaru = &chart[peringkatchart];
        cout << "Masukkan judul lagu baru: ";
        getline(cin, (*lagubaru).judul);
        cout << "Masukkan nama Artist: ";
        getline(cin, (*lagubaru).artist);
        cout << "Masukkan peringkat lagu: ";
        while (!(cin >> (*lagubaru).peringkat)) { 
            cin.clear(); 
            while (cin.get() != '\n');
            cout << "Masukkan peringkat dalam bentuk angka." << endl;
            cout << "Masukkan peringkat lagu: ";
        }
        cin.ignore();
        (*lagubaru).infoAlbum = new Album;
        cout << "Masukkan nama album: ";
        getline(cin, (*((*lagubaru).infoAlbum)).namaAlbum);
        cout << "Masukkan nama artis: ";
        getline(cin, (*((*lagubaru).infoAlbum)).artist);
        cout << "Masukkan tahun rilis album: ";
        while (!(cin >> (*((*lagubaru).infoAlbum)).tahun)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Masukkan Tahun dalam bentuk angka." << endl;
            cout << "Masukkan Tahun: ";
        }
        cin.ignore(); 
        peringkatchart++;
        cout << "Lagu sudah ditambah." << endl;
    }
    else {
        cout << "Chart sudah penuh" << endl;
    }
}

void LihatChart() {
    if (peringkatchart == 0) {
        cout << "Tidak ada Peringkat" << endl;
    }
    else {
        cout << "Chart:" << endl;
        for (int i = 0; i < peringkatchart; i++) {
            cout << "Judul: " << chart[i].judul << ", Artist: " << chart[i].artist << ", Peringkat: " << chart[i].peringkat << endl;
            cout << "Info Album: " << endl;
            cout << "Nama Album: " << chart[i].infoAlbum->namaAlbum << endl;
            cout << "Nama Artist Album: " << chart[i].infoAlbum->artist << endl;
            cout << "Tahun Rilis Album: " << chart[i].infoAlbum->tahun << endl;
        }
    }
}

void UpdateChart() {
    int nomor;
    cout << "Masukkan peringkat lagu yang ingin diupdate: ";
    cin >> nomor;
    cin.ignore();

    if (nomor >= 1 && nomor <= peringkatchart) {
        Song* lagu = &chart[nomor - 1];
        cout << "Masukkan judul lagu baru: ";
        getline(cin, (*lagu).judul);
        cout << "Masukkan nama Artist baru: ";
        getline(cin, (*lagu).artist);
        cout << "Masukkan peringkat baru: ";
        while (!(cin >> (*lagu).peringkat)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Masukkan peringkat dalam bentuk angka." << endl;
            cout << "Masukkan peringkat baru: ";
        }
        cin.ignore(); 
        cout << "Masukkan nama album baru: ";
        getline(cin, (*((*lagu).infoAlbum)).namaAlbum);
        cout << "Masukkan nama artis album baru: ";
        getline(cin, (*((*lagu).infoAlbum)).artist);
        cout << "Masukkan tahun rilis album baru: ";
        while (!(cin >> (*((*lagu).infoAlbum)).tahun)) {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Masukkan tahun rilis album dalam bentuk angka." << endl;
            cout << "Masukkan tahun rilis album baru: ";
        }
        cin.ignore(); 
        cout << "Peringkat berhasil diupdate." << endl;
    } else {
        cout << "Peringkat tidak valid." << endl;
    }
}

void HapusPeringkat() {
    int nomor;
    cout << "Masukkan nomor peringkat Lagu yang ingin dihapus: ";
    cin >> nomor;
    if (nomor >= 1 && nomor <= peringkatchart) {
        delete chart[nomor - 1].infoAlbum;
        for (int i = nomor - 1; i < peringkatchart - 1; i++) {
            chart[i] = chart[i + 1];
        }
        peringkatchart--;
        cout << "Peringkat Lagu dihapus." << endl;
    } else {
        cout << "Peringkat invalid." << endl;
    }
}


void CetakTerbalik(int index) {
    if (peringkatchart == 0) {
        cout << "Tidak ada Peringkat" << endl;
        return;
    }
    if (index >= 0) {
        cout << "Judul: " << chart[index].judul << ", Artist: " << chart[index].artist << ", Peringkat: " << chart[index].peringkat << endl;
        CetakTerbalik(index - 1);
    }
}

void Login() {
    string Nama, nama_alif = "Alif Alfiandra";
    int nim, nim_alif = 35;
    for (int i = 0; i < 3; i++) {
        cout << "Masukkan Nama anda: ";
        getline(cin, Nama);
        cout << "Masukkan NIM anda (2 digit terakhir): ";
        cin >> nim;
        cin.ignore();
        if (Nama == nama_alif && nim == nim_alif) {
            cout << "Login berhasil!" << endl;
            loginBerhasil = true;
            return;
        } else {
            cout << "login salah" << endl;
            if (i == 2) {
                cout << "Percobaan melebihi batas" << endl;
                return;
            }
        }
    }
}

int main() {
    Login();
    if (!loginBerhasil) {
        return 0;
    }
    
    char pilihan;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah Lagu" << endl;
        cout << "2. Lihat Chart" << endl;
        cout << "3. Update Chart" << endl;
        cout << "4. Hapus Peringkat" << endl;
        cout << "5. Cetak Chart Terbalik" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();
        if (pilihan == '1') {
            TambahLagu();
        } else if (pilihan == '2') {
            LihatChart();
        } else if (pilihan == '3') {
            UpdateChart();
        } else if (pilihan == '4') {
            HapusPeringkat();
       } else if (pilihan == '5') {
            CetakTerbalik(peringkatchart - 1);
        } else if (pilihan == '6') {
            cout << "Keluar dari program." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
    return 0;
}
