#include <iostream>
#include <cmath>
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

void BubbleSortJudul(Song arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].judul > arr[j + 1].judul) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void InsertionSortPeringkat(Song arr[], int n) {
    for (int i = 1; i < n; ++i) {
        Song key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].peringkat > key.peringkat) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void SelectionSortPeringkat(Song arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].peringkat > arr[max_idx].peringkat) {
                max_idx = j;
            }
        }
        swap(arr[i], arr[max_idx]);
    }
}

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

void LihatChartAscJudul() {
    if (peringkatchart == 0) {
        cout << "Tidak ada Peringkat" << endl;
    }
    else {
        cout << "Chart Terurut Ascending:" << endl;
        BubbleSortJudul(chart, peringkatchart);
        for (int i = 0; i < peringkatchart; i++) {
            cout << "Judul: " << chart[i].judul << ", Artist: " << chart[i].artist << ", Peringkat: " << chart[i].peringkat << endl;
            cout << "Info Album: " << endl;
            cout << "Nama Album: " << chart[i].infoAlbum->namaAlbum << endl;
            cout << "Nama Artist Album: " << chart[i].infoAlbum->artist << endl;
            cout << "Tahun Rilis Album: " << chart[i].infoAlbum->tahun << endl;
        }
    }
}

void LihatChartAscPeringkat() {
    if (peringkatchart == 0) {
        cout << "Tidak ada Peringkat" << endl;
    }
    else {
        cout << "Chart Terurut Ascending berdasarkan Peringkat:" << endl;
        Song chartCopy[10];
        for (int i = 0; i < peringkatchart; ++i) {
            chartCopy[i] = chart[i];
        }
        InsertionSortPeringkat(chartCopy, peringkatchart);
        for (int i = 0; i < peringkatchart; i++) {
            cout << "Judul: " << chartCopy[i].judul << ", Artist: " << chartCopy[i].artist << ", Peringkat: " << chartCopy[i].peringkat << endl;
            cout << "Info Album: " << endl;
            cout << "Nama Album: " << chartCopy[i].infoAlbum->namaAlbum << endl;
            cout << "Nama Artist Album: " << chartCopy[i].infoAlbum->artist << endl;
            cout << "Tahun Rilis Album: " << chartCopy[i].infoAlbum->tahun << endl;
        }
    }
}

void LihatChartDescPeringkat() {
    if (peringkatchart == 0) {
        cout << "Tidak ada Peringkat" << endl;
    }
    else {
        cout << "Chart Terurut Descending:" << endl;
        SelectionSortPeringkat(chart, peringkatchart);
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
    cin.ignore();

    cout << "Nomor yang dipilih: " << nomor << ", Jumlah peringkatchart: " << peringkatchart << endl;

    if (nomor >= 1 && nomor <= peringkatchart) {
        
        delete chart[nomor - 1].infoAlbum;
        
        for (int i = nomor - 1; i < peringkatchart - 1; i++) {
            chart[i] = chart[i + 1];
        }

        for (int i = nomor - 1; i < peringkatchart - 1; i++) {
            chart[i].infoAlbum = chart[i + 1].infoAlbum;
        }

        if (nomor < peringkatchart) {
            for (int i = nomor - 1; i < peringkatchart - 1; i++) {
                chart[i].peringkat--;
            }
        }

        peringkatchart--;
        cout << "Peringkat Lagu dihapus." << endl;

        for (int i = 0; i < peringkatchart; i++) {
            cout << "Judul: " << chart[i].judul << ", Artist: " << chart[i].artist << ", Peringkat: " << chart[i].peringkat << endl;
            cout << "Info Album: " << endl;
            cout << "Nama Album: " << chart[i].infoAlbum->namaAlbum << endl;
            cout << "Nama Artist Album: " << chart[i].infoAlbum->artist << endl;
            cout << "Tahun Rilis Album: " << chart[i].infoAlbum->tahun << endl;
        }
    } else {
        cout << "Peringkat invalid." << endl;
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

int BinarySearchAscending(Song arr[], int n, int peringkat) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].peringkat == peringkat) {
            return mid;
        } else if (arr[mid].peringkat < peringkat) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}

int InterpolationSearchDescending(Song arr[], int n, int peringkat) {
    int low = 0, high = n - 1;
    while (low <= high && peringkat <= arr[low].peringkat && peringkat >= arr[high].peringkat) {
        
        int pos = low + ((double)(high - low) / (arr[low].peringkat - arr[high].peringkat)) * (arr[low].peringkat - peringkat);

        if (pos < low)
            pos = low;
        else if (pos > high)
            pos = high;
    
        if (arr[pos].peringkat == peringkat) {
            return pos;
        } else if (arr[pos].peringkat < peringkat) { 
            high = pos - 1;
        } else { 
            low = pos + 1;
        }
    }
    return -1; 
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
        cout << "2. Update Chart" << endl;
        cout << "3. Hapus Peringkat" << endl;
        cout << "4. Lihat Chart Judul Secara Ascending" << endl;
        cout << "5. Lihat Chart Peringkat Terurut Secara Descending" << endl;
        cout << "6. Lihat Chart Peringkat Terurut Secara Ascending" << endl;
        cout << "7. Cari Lagu dengan Binary Search Ascending" << endl;
        cout << "8. Cari Lagu dengan Interpolation Search Descending" << endl;
        cout << "9. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();
        if (pilihan == '1') {
            TambahLagu();
        } else if (pilihan == '2') {
            UpdateChart();
        } else if (pilihan == '3') {
            HapusPeringkat();
        } else if (pilihan == '4') {
            LihatChartAscJudul();
        } else if (pilihan == '5') {
            LihatChartDescPeringkat();
        } else if (pilihan == '6') {
            LihatChartAscPeringkat();
        } else if (pilihan == '7') {
            int peringkatDicari;
            cout << "Masukkan peringkat lagu yang ingin dicari: ";
            cin >> peringkatDicari;
            int indexBinary = BinarySearchAscending(chart, peringkatchart, peringkatDicari);
            if (indexBinary != -1) {
                cout << "Lagu dengan peringkat " << peringkatDicari << " ditemukan pada indeks: " << indexBinary << endl;
            } else {
                cout << "Lagu dengan peringkat " << peringkatDicari << " tidak ditemukan." << endl;
            }
        } else if (pilihan == '8') {
            int peringkatDicari;
            cout << "Masukkan peringkat lagu yang ingin dicari: ";
            cin >> peringkatDicari;
            int indexInterpolation = InterpolationSearchDescending(chart, peringkatchart, peringkatDicari);
            if (indexInterpolation != -1) {
                cout << "Lagu dengan peringkat " << peringkatDicari << " ditemukan pada indeks: " << indexInterpolation << endl;
            } else {
                cout << "Lagu dengan peringkat " << peringkatDicari << " tidak ditemukan." << endl;
            }
        } else if (pilihan == '9') {
            cout << "Keluar dari program." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
    return 0;
}
