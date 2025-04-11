//posttest1

#include <iostream>
#include <limits>

using namespace std;

// Fungsi untuk login
bool login() {
    string nama, inputNama;
    string nim, inputNim;
    
    cout << "\n===== LOGIN =====" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, inputNama);
    cout << "Masukkan NIM: ";
    cin >> inputNim;
    
    int attempts = 2; // Sudah satu kali mencoba di atas
    while ((inputNim.length() != 3 || !isdigit(inputNim[0]) || !isdigit(inputNim[1]) || !isdigit(inputNim[2])) && attempts > 0) {
        cout << "NIM harus 3 digit terakhir. Coba lagi: ";
        cin >> inputNim;
        attempts--;
    }
    
    if (attempts == 0 && (inputNim.length() != 3 || !isdigit(inputNim[0]) || !isdigit(inputNim[1]) || !isdigit(inputNim[2]))) {
        cout << "Kesempatan habis. Program berhenti." << endl;
        return false;
    }
    return true;
}

// Fungsi konversi suhu
int konversiSuhu() {
    int pilihan;
    double suhu;
    
    do {
        cout << "\n===== MENU KONVERSI SUHU =====" << endl;
        cout << "1. Celcius -> Fahrenheit, Reamur, Kelvin" << endl;
        cout << "2. Fahrenheit -> Celcius, Reamur, Kelvin" << endl;
        cout << "3. Reamur -> Celcius, Fahrenheit, Kelvin" << endl;
        cout << "4. Kelvin -> Celcius, Fahrenheit, Reamur" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        if (pilihan == 5) {
            cout << "Program selesai." << endl;
            break;
        }
        
        cout << "Masukkan suhu: ";
        cin >> suhu;
        
        switch (pilihan) {
            case 1:
                cout << "Fahrenheit: " << (suhu * 9/5) + 32 << endl;
                cout << "Reamur: " << suhu * 4/5 << endl;
                cout << "Kelvin: " << suhu + 273.15 << endl;
                break;
            case 2:
                cout << "Celcius: " << (suhu - 32) * 5/9 << endl;
                cout << "Reamur: " << (suhu - 32) * 4/9 << endl;
                cout << "Kelvin: " << (suhu - 32) * 5/9 + 273.15 << endl;
                break;
            case 3:
                cout << "Celcius: " << suhu * 5/4 << endl;
                cout << "Fahrenheit: " << (suhu * 9/4) + 32 << endl;
                cout << "Kelvin: " << (suhu * 5/4) + 273.15 << endl;
                break;
            case 4:
                cout << "Celcius: " << suhu - 273.15 << endl;
                cout << "Fahrenheit: " << (suhu - 273.15) * 9/5 + 32 << endl;
                cout << "Reamur: " << (suhu - 273.15) * 4/5 << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
                break;
        }
    } while (true);
}

int main() {
    if (login()) {
        konversiSuhu();
    }
    return 0;
}
