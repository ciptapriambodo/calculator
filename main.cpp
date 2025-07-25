#include <iostream> // Untuk input/output
#include <limits>   // Untuk std::numeric_limits

// Menggunakan namespace standar secara keseluruhan.
// Ini berarti kita tidak perlu menulis 'std::' di depan setiap elemen dari namespace std.
using namespace std;

// --- Kelas Kalkulator ---
class Kalkulator {
    public:
      // Fungsi untuk menampilkan menu operasi
      void tampilkanMenu() {
        cout << "\n--- Kalkulator Sederhaa ---" << endl;
        cout << "1. Penjumlahan (+)" << endl;
        cout << "2. Pengurangan (-)" << endl;
        cout << "3. Perkalian (*)" << endl;
        cout << "4. Pembagian (/)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih operasi (1-5): ";
      }  

      // Fungsi untuk mendapatkan inpuut angka dari pengguna
      double dapatkanInputAngka(const string& prompt) {
        double angka;
        while(true) {
            cout << prompt;
            cin >> angka;
            if (cin.fail()) {
                cout << "Input tidak valid. Harap masukkan angka." << endl;
                cin.clear(); // Bersihkan flag error
                // Abaikan sisa input di buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                return angka;
            }
        }
      }

      // Fungsi untuk melakukan operasi berdasarkan pilihan pengguna
      void lakukanOperasi(int pilihan) {
        double angka1, angka2, hasil;

        switch (pilihan) {
        case 1:
            angka1 = dapatkanInputAngka("Masukkan angka pertama: ");
            angka2 = dapatkanInputAngka("Masukkan angka kedua: ");
            hasil = angka1 + angka2;
            //Menampilkan hasil penjumlahan
            cout << "Hasil: " << angka1 << " + " << angka2 << " = " << hasil << endl;
            break;

        case 2:
            angka1 = dapatkanInputAngka("Masukkan angka pertama: ");
            angka2 = dapatkanInputAngka("Masukkan angka kedua: ");
            //Menampilkan hasil pengurangan
            hasil = angka1 - angka2;
            cout << "Hasil: " << angka1 << " - " << angka2 << " = " << hasil << endl;
            break;
        
        case 3:
            angka1 = dapatkanInputAngka("Masukkan angka pertama: ");
            angka2 = dapatkanInputAngka("Masukkan angka kedua: ");
            //Menampilkan hasil perkalian
            hasil = angka1 * angka2;
            cout << "Hasil: " << angka1 << " * " << angka2 << " = " << hasil << endl;
            break;

        case 4:
            angka1 = dapatkanInputAngka("Masukkan angka pertama: ");
            angka2 = dapatkanInputAngka("Masukkan angka kedua: ");
            if (angka2 != 0) {
                hasil = angka1 / angka2;
                //Menampilkan hasil pembagian
                cout << "Hasil: " << angka1 << " / " << angka2 << " = " << hasil << endl;
            } else {
                cout << "Error: Tidak bisa membagi dengan nol!" << endl;
            }
            break;    
        
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }
      }

      // Fungsi uutama untuk menjalankan kalkulator dalam loop
      void jalankan() {
        int pilihan;
        do {
            tampilkanMenu();
            cin >> pilihan;

            // Validasi input pilihan menu
            if (cin.fail()) {
                cout << "Input tidak valid. Harap masukkan angka pilihan." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; // Lanjut ke iterasi berikutnya tanpa memproses pilihan
            }

            if (pilihan >= 1 && pilihan <= 4) {
                lakukanOperasi(pilihan);
            } else if (pilihan == 5) {
                cout << "Terima kasih telah menggunakan kalkulator ini. Sampai jumpa!" << endl;
            } else {
                cout << "Pilihan tidak valid. Silakan masukkan angka antara 1 dan 5." << endl;
            }

            // Abaikan sisa input di buffer setelah membaca 'pilihan'
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (pilihan !=5); // Loop akan terus berjalan selama pilihan bukan '5' (Keluar)
      }
    };

// --- Fungsi main ---
int main() {
    Kalkulator kalkulatorSaya; // Membuat objek dari kelas Kalkulator
    kalkulatorSaya.jalankan(); // Memanggil fungsi jalankan untuk memulai kalkulator

    return 0; // Menandakan program berakhir dengan sukses
}