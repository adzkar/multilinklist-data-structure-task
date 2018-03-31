#include "ui.h"

using namespace std;

int main(){


    // membuat list terlebih dahulu
    list_stud list_manager;
    list_class list_karyawan;

    // membuat list
    createListStud(list_manager);
    createListClass(list_karyawan);

    int x;
    do {
        x = menuUtama();
        switch(x) {
            case 1 : {
                cout << " " << endl;
                tambahManager(list_manager);
            }
                break;
            case 2 : {
                cout << " " << endl;
                tambahKaryawan(list_karyawan);
            } 
                break;
            case 3 : {
                managerPilihKaryawan(list_manager, list_karyawan);
            }
                break;
            case 4 : {
                karyawanPilihManager(list_karyawan, list_manager);
            }
                break;
            case 7 : {
                updateDataManager(list_manager);
            }
                break;
            case 8 : {
                updateDataKaryawan(list_karyawan);
            }
                break;
            case 9 : {
                lihatManager(list_manager);
            }
                break;
            case 10 : {
                lihatKaryawan(list_karyawan);
            }
                break;
            case 11 : {
                karyawanByManager(list_manager);
            }
                break;
            case 12 : {
                managerByKaryawan(list_karyawan);
            }
                break;
            case 13 : {
                banyakManagerKaryawan(list_manager, list_karyawan);    
            }
                break;
            default: {
                    x = menuUtama();
            }
                break;
        }
    } while(x != 14);


    return 0;
};