#include <iostream>
#include <string>
using namespace std;

// Struct nilai
struct Nilai {
    float absen, nilai_tugas, uts, uas, akhir;
    char huruf;
};

// Struct mahasiswa
struct Mahasiswa {
    string npm, nama;
    Nilai nilai;
};

Mahasiswa mhs[20];
int total = 0;

// Fungsi hitung nilai akhir
float hitungAkhir(float a, float t, float uts, float uas) {
    return (0.1*a) + (0.2*t) + (0.3*uts) + (0.4*uas);
}

// Fungsi nilai huruf
char hitungHuruf(float na) {
    if(na > 80) return 'A';
    else if(na > 70) return 'B';
    else if(na > 60) return 'C';
    else return 'D';
}

// Cari index berdasarkan NPM
int cariNPM(string npm) {
    for(int i=0; i<total; i++) {
        if(mhs[i].npm == npm) return i;
    }
    return -1;
}

// Menu Input
void input() {
    system("cls");
    if(total >= 20) {
        cout << "Data penuh!\n";
        return;
    }
    
    cout << "NPM: "; cin >> mhs[total].npm;
    
    // Cek duplikat
    if(cariNPM(mhs[total].npm) != -1) {
        cout << "NPM sudah ada!\n";
        return;
    }
    
    cout << "Nama: ";
    cin.ignore();
    getline(cin, mhs[total].nama);
    cout << "Absen: "; cin >> mhs[total].nilai.absen;
    cout << "Tugas: "; cin >> mhs[total].nilai.nilai_tugas;
    cout << "UTS: "; cin >> mhs[total].nilai.uts;
    cout << "UAS: "; cin >> mhs[total].nilai.uas;
    
    // Hitung otomatis
    mhs[total].nilai.akhir = hitungAkhir(mhs[total].nilai.absen, 
                                         mhs[total].nilai.nilai_tugas,
                                         mhs[total].nilai.uts, 
                                         mhs[total].nilai.uas);
    mhs[total].nilai.huruf = hitungHuruf(mhs[total].nilai.akhir);
    
    total++;
    cout << "Data berhasil ditambah!\n";
}

// Menu Tampil
void tampil() {
    system("cls");
    if(total == 0) {
        cout << "Tidak ada data!\n";
        return;
    }
    
    cout << "========================================\n";
    for(int i=0; i<total; i++) {
        cout << "NPM: " << mhs[i].npm << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "Absen: " << mhs[i].nilai.absen << endl;
        cout << "Tugas: " << mhs[i].nilai.nilai_tugas << endl;
        cout << "UTS: " << mhs[i].nilai.uts << endl;
        cout << "UAS: " << mhs[i].nilai.uas << endl;
        cout << "Nilai Akhir: " << mhs[i].nilai.akhir << endl;
        cout << "Nilai Huruf: " << mhs[i].nilai.huruf << endl;
        cout << "========================================\n";
    }
}

// Menu Edit
void edit() {
    system("cls");
    string npm;
    cout << "Masukkan NPM: "; cin >> npm;
    
    int idx = cariNPM(npm);
    if(idx == -1) {
        cout << "Data tidak ditemukan!\n";
        return;
    }
    
    cout << "Data ditemukan. Masukkan data baru:\n";
    cout << "Nama: "; cin >> mhs[idx].nama;
    cout << "Absen: "; cin >> mhs[idx].nilai.absen;
    cout << "Nilai Tugas: "; cin >> mhs[idx].nilai.nilai_tugas;
    cout << "UTS: "; cin >> mhs[idx].nilai.uts;
    cout << "UAS: "; cin >> mhs[idx].nilai.uas;
    
    mhs[idx].nilai.akhir = hitungAkhir(mhs[idx].nilai.absen,
                                       mhs[idx].nilai.nilai_tugas,
                                       mhs[idx].nilai.uts,
                                       mhs[idx].nilai.uas);
    mhs[idx].nilai.huruf = hitungHuruf(mhs[idx].nilai.akhir);
    
    cout << "Data berhasil diupdate!\n";
}

// Menu Hapus
void hapus() {
    system("cls");
    string npm;
    cout << "Masukkan NPM: "; cin >> npm;
    
    int idx = cariNPM(npm);
    if(idx == -1) {
        cout << "Data tidak ditemukan!\n";
        return;
    }
    
    // Geser data
    for(int i=idx; i<total-1; i++) {
        mhs[i] = mhs[i+1];
    }
    total--;
    cout << "Data berhasil dihapus!\n";
}

int main() {
    char pilih;
    
    do {
        system("cls");
        cout << "PROGRAM NILAI MAHASISWA\n";
        cout << "1. Input Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Edit Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih: "; cin >> pilih;
        
        switch(pilih) {
            case '1': input(); break;
            case '2': tampil(); break;
            case '3': edit(); break;
            case '4': hapus(); break;
            case '5': cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan salah!\n";
        }
        
        if(pilih != '5') {
            cout << "\nTekan enter untuk lanjut...";
            cin.ignore();
            cin.get();
        }
        
    } while(pilih != '5');
    
    return 0;
}