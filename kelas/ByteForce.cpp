// Kode C++ untuk Mengurutkan File Berdasarkan Nama dengan Merge Sort
#include <iostream>
#include <vector>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;
using namespace std;

// Fungsi untuk melakukan Merge
void merge(vector<string>& files, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> leftArr(n1);
    vector<string> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = files[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = files[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            files[k] = leftArr[i];
            i++;
        } else {
            files[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        files[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        files[k] = rightArr[j];
        j++;
        k++;
    }
}

// Fungsi utama Merge Sort
void mergeSort(vector<string>& files, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(files, left, mid);
        mergeSort(files, mid + 1, right);
        merge(files, left, mid, right);
    }
}

int main() {
    string path = "./"; // Ganti dengan path folder yang ingin diurutkan
    vector<string> fileNames;

    // Membaca file dalam direktori
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry.status())) {
            fileNames.push_back(entry.path().filename().string());
        }
    }

    // Jika ada file dalam direktori
    if (!fileNames.empty()) {
        cout << "File sebelum diurutkan:\n";
        for (const auto& file : fileNames) {
            cout << file << endl;
        }

        // Mengurutkan file dengan Merge Sort
        mergeSort(fileNames, 0, fileNames.size() - 1);

        cout << "\nFile setelah diurutkan:\n";
        for (const auto& file : fileNames) {
            cout << file << endl;
        }
    } else {
        cout << "Tidak ada file dalam folder ini.\n";
    }

    return 0;
}

// Kode C++ untuk Mencari File Berdasarkan Nama dengan Interpolation Search
#include <iostream>
#include <vector>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;
using namespace std;

// Fungsi Interpolation Search
int interpolationSearch(vector<string>& files, string target) {
    int low = 0, high = files.size() - 1;

    while (low <= high && target >= files[low] && target <= files[high]) {
        // Estimasi posisi menggunakan rumus interpolasi
        int pos = low + ((double)(high - low) / (files[high].compare(files[low]))) * (target.compare(files[low]));

        // Jika ditemukan
        if (files[pos] == target)
            return pos;

        // Jika target lebih besar, cari di kanan
        if (files[pos] < target)
            low = pos + 1;
        // Jika target lebih kecil, cari di kiri
        else
            high = pos - 1;
    }
    return -1; // Tidak ditemukan
}

int main() {
    string path = "./"; // Ganti dengan folder yang ingin dipindai
    vector<string> fileNames;

    // Membaca file dalam direktori
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry.status())) {
            fileNames.push_back(entry.path().filename().string());
        }
    }

    // Jika ada file dalam direktori
    if (!fileNames.empty()) {
        // Mengurutkan file sebelum melakukan Interpolation Search
        sort(fileNames.begin(), fileNames.end());

        cout << "File dalam folder:\n";
        for (const auto& file : fileNames) {
            cout << file << endl;
        }

        string searchFile;
        cout << "\nMasukkan nama file yang ingin dicari: ";
        cin >> searchFile;

        // Mencari file dengan Interpolation Search
        int index = interpolationSearch(fileNames, searchFile);

        if (index != -1) {
            cout << "File '" << searchFile << "' ditemukan pada indeks " << index << ".\n";
        } else {
            cout << "File '" << searchFile << "' tidak ditemukan.\n";
        }
    } else {
        cout << "Tidak ada file dalam folder ini.\n";
    }

    return 0;
}