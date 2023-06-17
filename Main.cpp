//Judul : Manajemen Keuangan
//      : Muhammad Dyaka Faiz Yuhendra
//      : Kosan, 15 Juni 2023
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;


//Kamus
//penamaan variabel
    fstream file,file2,file3;

    class manajemen{
    public:
        //data
        int withdraw;
        int deposito;
        int jmlUang;
        int jipuk;
        string catat;

        //method
        void depo();
        void with();
        void displayJml();
        void outputCatatan();
    };
    manajemen manage;

    //Fungsi tambah uang
    void manajemen::depo(){
        cout << "Masukkan jumlah uang masuk : "; cin >> deposito;
        cin.ignore();
        cout << "Catatan : ";getline(cin,catat);
        cout << endl;
        cout << endl;
    }

    //Fungsi cek sisa uang


    //Fungsi mengambil uang
    void manajemen::with(){
        cout << "Masukkan Jumlah Ambil : ";cin >> manage.withdraw;
        cin.ignore();
        cout << "Catatan : ";getline(cin,manage.catat);
        cout << endl;
        cout << endl;
    }

    void manajemen::displayJml(){
        int total,total3;
        int hasil = 0;
        string line,line3;

        file.open("duitIn.txt"); //membuka file
        while (getline(file, line)) {
            int line2 = stoi(line); //merubah string ke integer
            total = total + line2;
         }
        file3.open("duitOut.txt");
        while(getline(file3,line3)){
            int line4 = stoi(line3);
            if(line4 > 0)
            total3 = total3 + line4;
        }
        hasil = total - total3;
        file3.close();
        file.close();
         cout << total;
    }

    void addRecord();
    void withdraw();
    void showAll();
    void table();
//Deskripsi
int main(){
int jmlUang;

    int option;

     while(1){
        system("cls");
        cout << " === Catatan Keuangan=== \n";
        cout << "1. Deposito \n";
        cout << "2. Withdraw\n";
        cout << "3. Jumlah Uang\n";
        cout << "4. Keluar/Exit\n";
        cout << "========================\n";
        cout << "Masukkan nomor opsi[1-4]: ";
        cin >> option;

        switch(option){
            case 1:{
                manage.depo();
                addRecord();
                cout << "Tekan sembarang untuk kembali ke menu";
                getch();
                break;
            }
            case 2:{
                withdraw();
                cout << "Tekan sembarang untuk kembali ke menu";
                getch();
                break;
            }
            case 3:{
                table();
                cout << "Tekan sembarang untuk kembali ke menu";
                getch();
                break;
            }
            case 4: {
                exit(0);
            }
            default:{
                cout<<"Opsi pilihan tidak ada, Tekan sembarang untuk kembali ke menu ...";
                break;
            }
        }
     }
    return 0;
}
void table(){
    system("cls");
    cout << endl;
    showAll();
    cout << endl;
    cout << "Jumlah uang : ";
    manage.displayJml();
    cout << endl << endl;
};

void showAll(){
    string line,line2,line3;
        file2.open("catatan.txt"); //membuka file
        file.open("duitIn.txt"); //membuka file
         while (getline(file2, line2) && getline(file, line)) {
            cout << line2 << " : " << line << endl;
         }
        file2.close();
        file.close();
}

void addRecord(){
    file.open("duitIn.txt",ios::app);
    file << manage.deposito << endl;
    file.close();
    file2.open("catatan.txt",ios::app);
    file2 << " + " << manage.catat << endl;
    file2.close();
    cout << "Data telah berhasil ditambahkan!\n";
    cout << endl << endl;
}

void withdraw(){
        int total;
        string line;
        manage.with();
            file3.open("duitOut.txt",ios::app); //membuka file
                file3 << manage.withdraw << endl;
        file3.close();
            file2.open("catatan.txt",ios::app);
                file2 << " - " << manage.catat << endl;
        file2.close();
}
