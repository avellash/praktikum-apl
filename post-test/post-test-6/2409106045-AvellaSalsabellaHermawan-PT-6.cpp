//pt6

#include <iostream>
#include <string>
using namespace std;

#define MAX_PESERTA 40

struct Peserta {
    string nama;
    string asalNegara;
    int umur;
    string posisi;
    string status;
};

// Prosedur menu
void tampilkanMenuAdmin() {
    cout << "\nMenu Admin:\n"
         << "1. Tampilkan Peserta\n"
         << "2. Tambah Peserta\n"
         << "3. Ubah Peserta\n"
         << "4. Hapus Peserta\n"
         << "5. Kembali ke Menu Login\n"
         << "6. Keluar\n"
         << "7. Lihat Total Peserta\n"
         << "8. Ubah Status Peserta\n"
         << "9. Menu Sorting\n";
}

void tampilkanMenuUser() {
    cout << "\nMenu User:\n"
         << "1. Tampilkan Peserta\n"
         << "2. Kembali ke Menu Login\n"
         << "3. Keluar\n";
}

// Inisialisasi data
int inisialisasiData(Peserta peserta[], int &jumlahPeserta) {
    Peserta dataAwal[] = {
        {"Kim Sujung", "Korea Selatan", 20, "Dance", "Eliminasi"},
        {"Narai Koko", "Jepang", 19, "Rap", "Lolos"},
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

// Fungsi tambahan dengan address-of operator
void hitungTotalPeserta(int &jumlah) {
    cout << "\nTotal peserta saat ini adalah: " << jumlah << endl;
}

// Fungsi tambahan dengan dereference operator
void ubahStatus(Peserta *p, string statusBaru) {
    p->status = statusBaru;
    cout << "Status peserta berhasil diubah menjadi: " << p->status << endl;
}

// Sorting
void bubbleSortNama(Peserta peserta[], int jumlahPeserta) {
    for (int i = 0; i < jumlahPeserta - 1; i++) {
        for (int j = 0; j < jumlahPeserta - i - 1; j++) {
            if (peserta[j].nama > peserta[j + 1].nama) {
                swap(peserta[j], peserta[j + 1]);
            }
        }
    }
}

void selectionSortUmur(Peserta peserta[], int jumlahPeserta) {
    for (int i = 0; i < jumlahPeserta - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < jumlahPeserta; j++) {
            if (peserta[j].umur > peserta[maxIdx].umur) {
                maxIdx = j;
            }
        }
        swap(peserta[i], peserta[maxIdx]);
    }
}

void insertionSortNegara(Peserta peserta[], int jumlahPeserta) {
    for (int i = 1; i < jumlahPeserta; i++) {
        Peserta key = peserta[i];
        int j = i - 1;
        while (j >= 0 && peserta[j].asalNegara > key.asalNegara) {
            peserta[j + 1] = peserta[j];
            j--;
        }
        peserta[j + 1] = key;
    }
}

// Login
int login(int &role) {
    string username, nim;
    int attempts = 0;
    while (attempts < 3) {
        cout << "\nLogin Sistem\nMasukkan Nama: ";
        cin >> username;
        cout << "Masukkan NIM: ";
        cin >> nim;

        if (nim.length() == 3 && username != "admin") {
            role = 1;
            return 1;
        } else if (username == "admin" && nim == "000") {
            role = 2;
            return 1;
        }
        cout << "Login gagal! Coba lagi.\n";
        attempts++;
    }
    cout << "Terlalu banyak percobaan. Program berhenti.\n";
    return 0;
}

// Tampilkan peserta
int tampilkanPeserta(const Peserta peserta[], int jumlahPeserta) {
    if (jumlahPeserta == 0) {
        cout << "Tidak ada data peserta.\n";
        return 0;
    }
    cout << "\nDaftar Peserta I-LAND 2:\n";
    for (int i = 0; i < jumlahPeserta; i++) {
        cout << "Peserta ke-" << i + 1 << "\n"
             << "Nama: " << peserta[i].nama << "\n"
             << "Asal Negara: " << peserta[i].asalNegara << "\n"
             << "Umur: " << peserta[i].umur << "\n"
             << "Posisi: " << peserta[i].posisi << "\n"
             << "Status: " << peserta[i].status << "\n\n";
    }
    return jumlahPeserta;
}

// Tambah peserta
int tambahPeserta(Peserta peserta[], int &jumlahPeserta) {
    if (jumlahPeserta >= MAX_PESERTA) {
        cout << "Sudah penuh! Tidak bisa menambah peserta lagi.\n";
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

// Ubah peserta
int ubahPeserta(Peserta peserta[], int jumlahPeserta) {
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

// Hapus peserta
int hapusPeserta(Peserta peserta[], int &jumlahPeserta) {
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

// Main program
int main() {
    Peserta peserta[MAX_PESERTA];
    int jumlahPeserta = 0;
    inisialisasiData(peserta, jumlahPeserta);

    int role;
    do {
        if (!login(role)) break;

        int pilihan;
        do {
            if (role == 2) tampilkanMenuAdmin();
            else tampilkanMenuUser();

            cout << "Pilihan: ";
            cin >> pilihan;
            cin.ignore();

            if (pilihan == 1) {
                tampilkanPeserta(peserta, jumlahPeserta);
            } else if (role == 2 && pilihan == 2) {
                tambahPeserta(peserta, jumlahPeserta);
            } else if (role == 2 && pilihan == 3) {
                ubahPeserta(peserta, jumlahPeserta);
            } else if (role == 2 && pilihan == 4) {
                hapusPeserta(peserta, jumlahPeserta);
            } else if ((role == 2 && pilihan == 5) || (role == 1 && pilihan == 2)) {
                break;
            } else if ((role == 2 && pilihan == 6) || (role == 1 && pilihan == 3)) {
                cout << "Program selesai. Terimakasih banyak :)\n";
                return 0;
            } else if (role == 2 && pilihan == 7) {
                hitungTotalPeserta(jumlahPeserta); 
            } else if (role == 2 && pilihan == 8) {
                int idx;
                cout << "Masukkan nomor peserta yang ingin diubah statusnya: ";
                cin >> idx;
                cin.ignore();
                if (idx >= 1 && idx <= jumlahPeserta) {
                    string statusBaru;
                    cout << "Masukkan status baru: ";
                    getline(cin, statusBaru);
                    ubahStatus(&peserta[idx - 1], statusBaru); 
                } else {
                    cout << "Nomor peserta tidak valid.\n";
                }
            } else if (role == 2 && pilihan == 9) {
                int opsiSort;
                cout << "\nMenu Sorting:\n"
                     << "1. Urutkan Nama (A-Z)\n"
                     << "2. Urutkan Umur (Tertua - Termuda)\n"
                     << "3. Urutkan Asal Negara (A-Z)\n"
                     << "Pilihan: ";
                cin >> opsiSort;

                if (opsiSort == 1) {
                    bubbleSortNama(peserta, jumlahPeserta);
                    cout << "Peserta berhasil diurutkan berdasarkan nama (A-Z).\n";
                } else if (opsiSort == 2) {
                    selectionSortUmur(peserta, jumlahPeserta);
                    cout << "Peserta berhasil diurutkan berdasarkan umur (Tertua - Termuda).\n";
                } else if (opsiSort == 3) {
                    insertionSortNegara(peserta, jumlahPeserta);
                    cout << "Peserta berhasil diurutkan berdasarkan asal negara (A-Z).\n";
                } else {
                    cout << "Pilihan sorting tidak valid.\n";
                }
            } else {
                cout << "Pilihan tidak valid.\n";
            }
        } while (true);
    } while (true);

    return 0;
}

