#include <iostream> //Header ini digunakan untuk mengakses fungsi-fungsi dasar input/output (I/O) dalam C++. 
                    // misal: cout, cin 
using namespace std; //digunakan agar di depan kode tidak perlu mengetik 'std::'

//pengimplementasian materi struct
struct warga { //untuk menggabungkan beberapa tipe data agar menjadi satu kesatuan 
    //pengimplementasian materi array
    char nama[50];
    char kepalaKeluarga[50]; 
    char nik[50];
    int noRumah;
    warga *next; //pointer yang digunakan untuk pembentukan linked list
};

//pengimplementasian materi linked list
warga *awal=NULL, *akhir=NULL, *bantu, *baru; //variabel-variabel yang digunakan untuk mengatur linked list


void inputDatawarga(){ //fungsi yang digunakan untuk memasukkan data-data warga
                       //fungsi akan berjalan apabila ia dipanggil
    baru = new warga;
    baru->next = NULL; //simpul
    cout << endl;
    cout << "Nama                    : ";
    cin.ignore();
    cin.getline (baru->nama, 50); //agar bisa mengetik nama lebih dari satu kata
    cout << "Nama Kepala Keluarga    : ";
    cin.getline (baru->kepalaKeluarga, 50); //agar bisa mengetik nama lebih dari satu kata
    cout << "Nomor NIK berdasar KK   : ";
    cin.getline(baru->nik, 50); 
    cout << "Nomor Rumah             : ";
    cin >> baru->noRumah;
    //pengkondisian yang digunakan untuk menambahkan elemen baru ke dalam linked list
    if (awal==NULL){ //jika linked list kosong, maka elemen baru akan menjadi elemen pertama
                     //(awal dan akhir elemen sama)
        awal = akhir = baru; //awal dan akhir akan menunjuk ke elemen 'baru'
    }
    else { //jika linked list tidak kosong, maka elemen baru akan ditambahkan di akhir linked list
           //sehingga variabel 'akhir' akan diperbarui
        akhir->next = baru; //elemen 'akhir' menunjuk ke elemen 'baru' dgn pointer next
        akhir = baru;
    }
}

void outputData (){ //fungsi yang digunakan untuk menampilkan data yang telah dimasukkan sebelumnya
                    //fungsi akan berjalan apabila ia dipanggil
    bantu=awal; //menginisialisai pointer 'bantu' menunjuk ke elemen pertama linked list (awal)
    while (bantu != NULL){ //akan berjalan sealam 'bantu' tidak menunjuk ke 'NULL'
                           //perulangan ini akan terus berjalan selama masih ada eleemn yg hrs ditampilkan
    cout << " " << endl;
    cout << "Nama                  : " << bantu->nama << endl;
    cout << "Nama Kepala Keluarga  : " << bantu->kepalaKeluarga << endl;
    cout << "Nomor NIK berdasar KK : " << bantu->nik << endl;
    cout << "Nomor Rumah           : " << bantu->noRumah << endl;
    cout << " " << endl;
    bantu = bantu->next;//menggerakkan pointer bantu ke elemen berikutnya pd linked list
                        //sehingga pada iterasi selanjutnya, data dr elemen selanjutnya akan ditampilkan
    }
}

void displayDataMessage() { //fungsi untuk menampilkan pesan ketika data berhasil ditampilkan
    cout << "Data Warga berhasil ditampilkan!" << endl;
}

int main (){
    int pilihan, jumlahData;
    //variabel 'pilihan' untuk menyimpan pilihan menu
    //variabel 'jumlahData' untuk menyimpan jumlah data yang ingin dimasukkan
    //memastikan saat program dimulai kembali, linked list kosong dan siap menerima data baru
    bantu = awal; //Menginisialisasi pointer bantu untuk menunjuk ke elemen pertama dalam linked list, yaitu awal.
    while (bantu != NULL){ //perulangan yg akan terus berjalan selama masih ada elemen dalam linked list
    baru = bantu; //pointer 'baru' menunjuk ke elemen yg ditunjuk oleh 'bantu'
    bantu = bantu->next;//pemindahan pinter 'baru' ke elemen selanjutnya
    delete baru;//menghapus elemen yg ditunjuk pointer 'baru'
    }
    
    do{ //perulangan yang digunakan untuk menjalankan pernyataan berulang kali berdasarkan kondisi tertentu
        //akan diulang selama kondisi yang ditentukan benar.
        //untuk menampilkan menu pilihan
        cout << " " << endl;
        cout << " " << endl;
        cout << "~~~~~~~~~~ DATA WARGA RT 03 ~~~~~~~~~~" << endl;
        cout << " " << endl;
        cout << "Menu :" << endl;
        cout << "1. Input data warga" << endl;
        cout << "2. Output data warga" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        switch (pilihan){ //digunakan untuk menyeleksi satu dari banyaknya kode blok yg akan dijalankan/dieksekusi
            case 1 :
            cout << "Jumlah data yang ingin dimasukkan: ";
            cin >> jumlahData;
            for (int i= 0; i < jumlahData; i++){ //perulangan untuk memasukkan data sesuai jumlah yang diinginkan
            cout << " " << endl;
            cout << "Data Warga ke-" << i+1;
            inputDatawarga();//pemanggilan fungsi untuk nmemasukkan data-data
            } 
            break;
            case 2 : 
            if (awal == NULL){ //kondisi jika blm ada data yang dimasukkan tetapi pengguna memilih menu ke-2
                cout << "Tidak ada data tersedia" << endl;
            }
            else { //jika sudah ada data yg dimasukkan dan pengguna memilih menu ke-2
                outputData(); //pemanggilan fungsi untuk menampilkan data-data
                displayDataMessage(); //pemanggilan fungsi untuk menampilkan pesan jika data berhasil tertampil
            }
            break;
            default : //jika pengguna memilih menu ke-3 maka program akan berhenti/selesai
            cout << "Program Selesai";
            break;
        }
    }while (pilihan <= 2); //jika pilihan yg dipilih tdk trdpt dlm jumlah pilihan (misal: 3) maka program selesai.

    return 0;
}




