#include <iostream>
#include <string>
using namespace std;

struct Pasien {
    string nama;
    string jenis;
    int umur;
    int tingkatDarurat;
};

int main() {
    int n;
    cout << "Masukkan jumlah pasien: ";
    cin >> n;
    cin.ignore(); 

    // Membuat dynamic array untuk data pasien
    Pasien* antrean = new Pasien[n];

    for (int i = 0; i < n; i++) {
        cout << "\nPasien " << i + 1 << ":\n";
        cout << "Nama hewan: ";
        getline(cin, antrean[i].nama);
        cout << "Jenis hewan: ";
        getline(cin, antrean[i].jenis);
        cout << "Umur (tahun): ";
        cin >> antrean[i].umur;
        cout << "Tingkat darurat (1-5): ";
        cin >> antrean[i].tingkatDarurat;
        cin.ignore();
    }

    // Urutkan pasien berdasarkan tingkat darurat
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (antrean[j].tingkatDarurat > antrean[i].tingkatDarurat) {
                swap(antrean[i], antrean[j]);
            }
        }
    }

    // Tampilkan urutan pasien yang akan dilayani
    cout << "\n=== Urutan Pasien yang Dilayani ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << antrean[i].nama
             << " (" << antrean[i].umur << " tahun) - Darurat "
             << antrean[i].tingkatDarurat << endl;
    }

    delete[] antrean; 
    return 0;
}
