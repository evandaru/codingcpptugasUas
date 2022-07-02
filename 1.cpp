// ini menggunakan bahasa c++
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;
struct penyimpan
{
    string nama;
    int nominal;
};

int total;
struct penyimpan orang[100];
struct penyimpan temp;

int i = 0;
int j = 0;

void create()
{

    char ulang;
    do
    {
        system("cls");
        cout << "PENYIMPAN KE- " << i + 1 << endl;
        cout << "MASUKKAN NAMA      : ";
        cin >> orang[i].nama;
        cout << "MASUKKAN NOMINAL   : ";
        cin >> orang[i].nominal;
        i++;
        cout << "tambah data? [y/n]";
        cin >> ulang;
    } while (ulang == 'y');
}

void read()
{
    char cariSorting;
    string namaCari;
    int j = 0;
    system("cls");
    cout << "NO. nama      nominal   " << endl;
    total = 0;
    while (j < i)
    {
        cout << left << setw(4) << j + 1 << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
        total += orang[j].nominal;
        j++;
    }
    cout << "Total: " << total << endl;
    int a;
    int dataDitemukan;
    cout << "ketik 'c' untuk search, 's' untuk sort nama(masih gagal) dan 'k' kembali ";
    cin >> cariSorting;
    if (cariSorting == 'c')
    {
        cout << "cari nama/nominal: ";
        cin >> namaCari;
        system("cls");
        for (j = 0; j < i; j++)
        {
            if (namaCari == orang[j].nama || namaCari == to_string(orang[j].nominal))
            {
                // system("cls");
                dataDitemukan++;
                cout << left << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;

                // break;
            }
            // else if (namaCari != orang[j].nama)
            // {
            //     system("cls");
            //     cout << "data tidak ditemukan!";
            //     getch();
            //     break;
            // }
        }
        cout << "jumlah data ditemukan: " << dataDitemukan << endl;
        getch();
    }
    else if (cariSorting == 's')
    {
        char urut;
        cout << "urutkan berdasarkan (nominal : 'a' / nama : 'n' ) : ";
        cin >> urut;
        if (urut == 'a')
        {
            for (int a = 1; a < i; a++)
            {
                for (int b = 0; b < i - a; b++)
                {
                    if (orang[b].nama > orang[b + 1].nama)
                    {
                        temp.nama = orang[b].nama;
                        orang[b].nama = orang[b + 1].nama;
                        orang[b + 1].nama = temp.nama;

                        temp.nominal = orang[b].nominal;
                        orang[b].nominal = orang[b + 1].nominal;
                        orang[b + 1].nominal = temp.nominal;
                    }
                }
            }
            system("cls");
            cout << "hasil sorting" << endl;
            cout << "berdasarkan nama" << endl;
            cout << endl;
            cout << "NO. nama      nominal   " << endl;
            for (j = 0; j < i; j++)
            {
                cout << left << setw(4) << j + 1 << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
            }
            getch();
            system("cls");
            cout << "data teresimpan!";
            getch();
        }
        else if (urut == 'n')
        {
            for (int a = 1; a < i; a++)
            {
                for (int b = 0; b < i - a; b++)
                {
                    if (orang[b].nominal > orang[b + 1].nominal)
                    {
                        temp.nama = orang[b].nama;
                        orang[b].nama = orang[b + 1].nama;
                        orang[b + 1].nama = temp.nama;

                        temp.nominal = orang[b].nominal;
                        orang[b].nominal = orang[b + 1].nominal;
                        orang[b + 1].nominal = temp.nominal;
                    }
                }
            }
            system("cls");
            cout << "hasil sorting" << endl;
            cout << "berdasarkan Nominal" << endl;
            cout << endl;
            cout << "NO. nama      nominal   " << endl;
            for (j = 0; j < i; j++)
            {
                cout << left << setw(4) << j + 1 << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
            }
            getch();
            system("cls");
            cout << "data tersimpan!";
            getch();
        }

        // system("cls");
        // cout << "hasil sorting" << endl;
        // cout << endl;
        // cout << "NO. nama      nominal   " << endl;
        // for (j = 0; j < i; j++)
        // {
        //     cout << left << setw(4) << j + 1 << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
        // }
        // getch();
    }
}

void update()
{
    string ganti, pilihGanti;
    cout << "NO. nama      nominal   " << endl;
    for (j = 0; j < i; j++)
    {
        cout << left << setw(4) << j + 1 << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
        // total += orang[j].nominal;
    }
    cout << "data yang ingin di ganti (nominal/nama): ";
    cin >> pilihGanti;
    for (j = 0; j < i; j++)
    {
        if (pilihGanti == orang[j].nama || pilihGanti == to_string(orang[i].nominal))
        {
            cout << left << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
            cout << "ganti nama     : ";
            cin >> orang[j].nama;
            cout << "ganti nominal  : ";
            cin >> orang[j].nominal;
        }
    }
    // hasil ganti
    cout << "data sudah dirubah" << endl;
    for (j = 0; j < i; j++)
    {
        cout << left << setw(4) << j + 1 << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
        // total += orang[j].nominal;
    }
    getch();
}

void deletee()
{
    system("cls");
    cout << "NO. nama      nominal   " << endl;
    for (j = 0; j < i; j++)
    {
        cout << left << setw(4) << j + 1 << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
    }

    int hapus;
    cout << "masukkan angka yg ingin dihapus";
    cin >> hapus;
    for (j = hapus - 1; j < i; j++)
    {
        orang[j].nama = orang[j + 1].nama;
        orang[j].nominal = orang[j + 1].nominal;
    }
    for (j = 0; j < i; j++)
    {
        cout << left << setw(4) << j + 1 << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
    }
    system("cls");
    cout << "data berhasil dihapus!";
    getch();
}

void cetakTxt()
{
    system("cls");
    total = 0;
    string hasil = "Laporan_persewaan_" + to_string(time(NULL)) + ".txt";
    ofstream output(hasil);

    output << "Hasil Persewaan" << endl;
    for (int j = 0; j < i; j++)
    {
        output << left << setw(4) << j + 1 << setw(10) << orang[j].nama << setw(10) << orang[j].nominal << endl;
        total += orang[j].nominal;
    }
    output << "Total: " << total << endl;
    cout << "file :" << hasil << " telah berhasil dibuat!";
    getch();
}

void about()
{
    system("cls");
    char nama[100];
    ifstream input;
    input.open("about.txt");
    while (input)
    {
        input.getline(nama, sizeof(nama));
        cout << nama << endl;
    }
    getch();
}
int mainMenu, ulang;
int main()
{
    while (mainMenu != 9)
    {
        system("cls");
        cout << "Koperasi penyimpanan" << endl;
        cout << "1. buat data penyimpan" << endl;
        cout << "2. lihat data penyimpan" << endl;
        cout << "3. perbarui data penyimpan" << endl;
        cout << "4. hapus data penyimpan" << endl;
        cout << "5. cetak data menjadi .Txt" << endl;
        cout << "6. tentang kami" << endl;
        cout << "9. keluar" << endl;
        cout << "masukkan input: ";
        cin >> mainMenu;

        switch (mainMenu)
        {
        case 1:
            create();
            break;
        case 2:
            read();
            break;
        case 3:
            update();
            break;
        case 4:
            deletee();
            break;
        case 5:
            cetakTxt();
            break;
        case 6:
            about();
            break;
        case 9:
            system("cls");
            cout << "terima kasih telah menggunakan aplikasi ini";
            break;
        default:
            system("cls");
            cout << "input anda salah!";
            getch();
            break;
        }
    }

    return 0;
}
