#include <iostream>
#include <string>

using namespace std;

#define MAX_PESERTA 100

struct Peserta {
    string nama;
    string asalNegara;
    int umur;
    string posisi;
    string status;
};

Peserta peserta[MAX_PESERTA];
int jumlahPeserta = 0;

// Data peserta awal
int inisialisasiData() {
    Peserta dataAwal[] = {
        {"Kim Sujung", "Korea Selatan", 20, "Dance", "Eliminasi"},
        {"Koko Narai", "Jepang", 19, "Rap", "Lolos"},
        {"Choi Jungeun", "Korea Selatan", 18, "Vokal", "Lolos"},
        {"Nam Yuju", "Korea Selatan", 21, "Rap", "Eliminasi"}
    };

    int jumlahAwal = sizeof(dataAwal) / sizeof(dataAwal[0]);
    for (int i = 0; i < jumlahAwal; i++) {
        peserta[i] = dataAwal[i];
    }
    jumlahPeserta = jumlahAwal;
    return jumlahPeserta;
}

// Fungsi login
int login(int &role) {
    string username, nim;
    int attempts = 0;
    while (attempts < 3) {
        cout << "\nLogin Sistem" << endl;
        cout << "Masukkan Nama: ";
        cin >> username;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nim.length() == 3 && username != "admin") {
            role = 1; // User
            return 1;
        } else if (username == "admin" && nim == "000") {
            role = 2; // Admin
            return 1;
        }
        cout << "Login gagal! Coba lagi.\n";
        attempts++;
    }
    cout << "Terlalu banyak percobaan. Program berhenti.\n";
    return 0;
}

// Menampilkan peserta
int tampilkanPeserta() {
    if (jumlahPeserta == 0) {
        cout << "Tidak ada data peserta.\n";
        return 0;
    } else {
        cout << "\nDaftar Peserta I-LAND 2:\n";
        for (int i = 0; i < jumlahPeserta; i++) {
            cout << "Peserta ke-" << i + 1 << "\n";
            cout << "Nama: " << peserta[i].nama << "\n";
            cout << "Asal Negara: " << peserta[i].asalNegara << "\n";
            cout << "Umur: " << peserta[i].umur << "\n";
            cout << "Posisi: " << peserta[i].posisi << "\n";
            cout << "Status: " << peserta[i].status << "\n\n";
        }
        return jumlahPeserta;
    }
}

// Menambah peserta
int tambahPeserta() {
    if (jumlahPeserta >= MAX_PESERTA) {
        cout << "Kapasitas penuh! Tidak bisa menambah peserta lagi.\n";
        return 0;
    }
    
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, peserta[jumlahPeserta].nama);
    cout << "Masukkan Asal Negara: ";
    getline(cin, peserta[jumlahPeserta].asalNegara);
    cout << "Masukkan Umur: ";
    cin >> peserta[jumlahPeserta].umur;
    cin.ignore();
    cout << "Masukkan Posisi: ";
    getline(cin, peserta[jumlahPeserta].posisi);
    cout << "Masukkan Status: ";
    getline(cin, peserta[jumlahPeserta].status);
    
    jumlahPeserta++;
    cout << "Peserta berhasil ditambahkan!\n";
    return jumlahPeserta;
}

// Mengubah data peserta
int ubahPeserta() {
    int index;
    cout << "Masukkan nomor peserta yang akan diubah: ";
    cin >> index;
    cin.ignore();
    
    if (index < 1 || index > jumlahPeserta) {
        cout << "Nomor peserta tidak valid.\n";
        return 0;
    }
    
    cout << "Masukkan Nama baru: ";
    getline(cin, peserta[index - 1].nama);
    cout << "Masukkan Asal Negara baru: ";
    getline(cin, peserta[index - 1].asalNegara);
    cout << "Masukkan Umur baru: ";
    cin >> peserta[index - 1].umur;
    cin.ignore();
    cout << "Masukkan Posisi baru: ";
    getline(cin, peserta[index - 1].posisi);
    cout << "Masukkan Status baru: ";
    getline(cin, peserta[index - 1].status);
    
    cout << "Peserta berhasil diubah!\n";
    return 1;
}

// Menghapus peserta
int hapusPeserta() {
    int index;
    cout << "Masukkan nomor peserta yang akan dihapus: ";
    cin >> index;
    
    if (index < 1 || index > jumlahPeserta) {
        cout << "Nomor peserta tidak valid.\n";
        return 0;
    }

    for (int i = index - 1; i < jumlahPeserta - 1; i++) {
        peserta[i] = peserta[i + 1];
    }
    jumlahPeserta--;
    
    cout << "Peserta berhasil dihapus!\n";
    return jumlahPeserta;
}

// Fungsi utama
int main() {
    int dataTerisi = inisialisasiData();
    cout << "Data peserta telah diisi sebanyak " << dataTerisi << " peserta.\n";

    int role;
    do {
        if (!login(role)) continue;
        int pilihan;
        do {
            if (role == 2) { // Admin menu
                cout << "\nMenu Admin:\n";
                cout << "1. Tampilkan Peserta\n";
                cout << "2. Tambah Peserta\n";
                cout << "3. Ubah Peserta\n";
                cout << "4. Hapus Peserta\n";
                cout << "5. Kembali ke Menu Login\n";
                cout << "6. Keluar\n";
            } else { // User menu
                cout << "\nMenu User:\n";
                cout << "1. Tampilkan Peserta\n";
                cout << "2. Kembali ke Menu Login\n";
                cout << "3. Keluar\n";
            }
            cout << "Pilihan: ";
            cin >> pilihan;
            cin.ignore();

            if (pilihan == 1) {
                tampilkanPeserta();
            } else if (role == 2 && pilihan == 2) {
                tambahPeserta();
            } else if (role == 2 && pilihan == 3) {
                ubahPeserta();
            } else if (role == 2 && pilihan == 4) {
                hapusPeserta();
            } else if ((role == 2 && pilihan == 5) || (role == 1 && pilihan == 2)) {
                break;
            } else if ((role == 2 && pilihan == 6) || (role == 1 && pilihan == 3)) {
                cout << "Program selesai. Terimakasih banyak :) \n";
                return 0;
            } else {
                cout << "Pilihan tidak valid.\n";
            }
        } while (true);
    } while (true);

    return 0;
}
