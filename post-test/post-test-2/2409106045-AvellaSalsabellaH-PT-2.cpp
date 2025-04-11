// postteat 2

#include <iostream>
#include <string>
#include <limits> 

using namespace std;

#define MAX_PESERTA 30

struct Peserta {
    string nama;
    int umur;
    string negara;
    string posisi;
    string status;
};

Peserta peserta[MAX_PESERTA] = {
    {"Sujung", 19, "Korea", "Dance", "eliminasi"},
    {"Koko", 19, "Jepang", "Rap", "aktif"},
    {"Jungeun", 18, "Korea", "Vokal", "aktif"},
    {"Jiyoon", 20, "Korea", "Vokal", "aktif"},
    {"Mai", 21, "Jepang", "Vokal", "aktif"},
    {"Fuko", 21, "Jepang", "Vokal", "eliminasi"},
    {"Jeemin", 20, "Korea", "Dance", "aktif"},
    {"Yuju", 18, "Korea", "Rap", "eliminasi"},
    {"Juwon", 21, "Korea", "Dance", "eliminasi"}
};

int voting[MAX_PESERTA] = {0};
int jumlahPeserta = 9; // Data peserta awal

string login() {
    string username, password;
    cout << "\n=== LOGIN ===\n";
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    
    if (username == "admin" && password == "admin123") {
        return "admin";
    }
    return "user";
}

int lihatPeserta() {
    if (jumlahPeserta == 0) {
        cout << "Belum ada peserta.\n";
    } else {
        for (int i = 0; i < jumlahPeserta; i++) {
            cout << i + 1 << ". " << peserta[i].nama << ", " << peserta[i].umur << ", "
                 << peserta[i].negara << ", " << peserta[i].posisi << ", " << peserta[i].status << endl;
        }
    }
    return 0;
}

int tambahPeserta() {
    if (jumlahPeserta < MAX_PESERTA) {
        cin.ignore();
        cout << "Masukkan nama: ";
        getline(cin, peserta[jumlahPeserta].nama);
        cout << "Masukkan umur: ";
        cin >> peserta[jumlahPeserta].umur;
        cin.ignore();
        cout << "Masukkan asal negara: ";
        getline(cin, peserta[jumlahPeserta].negara);
        cout << "Masukkan posisi: ";
        getline(cin, peserta[jumlahPeserta].posisi);
        cout << "Masukkan status (aktif/eliminasi): ";
        getline(cin, peserta[jumlahPeserta].status);
        voting[jumlahPeserta] = 0;
        jumlahPeserta++;
        cout << "Peserta berhasil ditambahkan!\n";
    } else {
        cout << "Kapasitas peserta penuh!\n";
    }
    return 0;
}

int ubahPeserta() {
    lihatPeserta();
    int indeks;
    cout << "Masukkan nomor peserta yang akan diubah: ";
    cin >> indeks;
    if (indeks > 0 && indeks <= jumlahPeserta) {
        cin.ignore();
        cout << "Masukkan nama baru: ";
        getline(cin, peserta[indeks - 1].nama);
        cout << "Masukkan umur baru: ";
        cin >> peserta[indeks - 1].umur;
        cin.ignore();
        cout << "Masukkan negara baru: ";
        getline(cin, peserta[indeks - 1].negara);
        cout << "Masukkan posisi baru: ";
        getline(cin, peserta[indeks - 1].posisi);
        cout << "Masukkan status baru: ";
        getline(cin, peserta[indeks - 1].status);
        cout << "Peserta berhasil diubah!\n";
    } else {
        cout << "Nomor peserta tidak valid!\n";
    }
    return 0;
}

int hapusPeserta() {
    lihatPeserta();
    int indeks;
    cout << "Masukkan nomor peserta yang akan dihapus: ";
    cin >> indeks;
    if (indeks > 0 && indeks <= jumlahPeserta) {
        for (int i = indeks - 1; i < jumlahPeserta - 1; i++) {
            peserta[i] = peserta[i + 1];
            voting[i] = voting[i + 1];
        }
        jumlahPeserta--;
        cout << "Peserta berhasil dihapus!\n";
    } else {
        cout << "Nomor peserta tidak valid!\n";
    }
    return 0;
}

int vote() {
    lihatPeserta();
    int indeks;
    cout << "Masukkan nomor peserta yang ingin Anda vote: ";
    cin >> indeks;
    if (indeks > 0 && indeks <= jumlahPeserta) {
        voting[indeks - 1]++;
        cout << "Voting berhasil!\n";
    } else {
        cout << "Peserta tidak ditemukan!\n";
    }
    return 0;
}

int lihatVotingUser() {
    cout << "Peserta yang telah Anda vote:\n";
    for (int i = 0; i < jumlahPeserta; i++) {
        if (voting[i] > 0) {
            cout << peserta[i].nama << ": " << voting[i] << " vote" << endl;
        }
    }
    return 0;
}

int lihatVotingAdmin() {
    cout << "Hasil voting seluruh peserta:\n";
    for (int i = 0; i < jumlahPeserta; i++) {
        cout << peserta[i].nama << ": " << voting[i] << " vote" << endl;
    }
    return 0;
}

int menuAdmin() {
    int pilihan;
    do {
        cout << "\n=== MENU ADMIN ===\n";
        cout << "1. Lihat Peserta\n2. Tambah Peserta\n3. Ubah Peserta\n4. Hapus Peserta\n";
        cout << "5. Lihat Voting (Admin)\n6. Logout\n7. Keluar Program\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: lihatPeserta(); break;
            case 2: tambahPeserta(); break;
            case 3: ubahPeserta(); break;
            case 4: hapusPeserta(); break;
            case 5: lihatVotingAdmin(); break;
            case 6: return 1;
            case 7: return 2;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

int menuUser() {
    int pilihan;
    do {
        cout << "\n=== MENU USER ===\n";
        cout << "1. Lihat Peserta\n2. Vote Peserta\n3. Lihat Voting Anda\n4. Logout\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: lihatPeserta(); break;
            case 2: vote(); break;
            case 3: lihatVotingUser(); break;
            case 4: return 1;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (true);
}

int main() {
    while (true) {
        string role = login();
        int result = (role == "admin") ? menuAdmin() : menuUser();
        if (result == 2) break;
    }
    cout << "Program selesai.\n";
    return 0;
}


