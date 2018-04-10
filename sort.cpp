#include "sort.h"



void sortingManager(list_stud &list_manager) {
    int n = banyakStud(list_manager);

    if(n > 0) {
        vector<int>manager (n);

        // Menasignment Nilai kepada Vector
        adr_stud P = list_manager.first;
        int i = 0;
        while(P != NULL) {
            string id = P->info.id;
            manager[i] = atoi(id.c_str());            
            i++;
            P = P->next;
        }
        // melakukan sorting
        sort(manager.begin(), manager.end());
        // output data
        P = list_manager.first;
        i = 0;
        while(P != NULL) {
            // cout << manager[i] << " ";
            adr_stud Q = search_stud(list_manager, to_string(manager[i]));
            cout << "#" << i+1 << " " << Q->info.id << "  "<<Q->info.nama << endl;
            i++;
            P = P->next;
        }
    } else {
        cout << "Empty Data" << endl;
    }

    cout << " " << endl;
    cout << "   [PRESS ANY KEY TO CONTINUE]" << endl;
    cin.ignore();
    cin.get();  
};