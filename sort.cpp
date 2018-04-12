#include "sort.h"

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}



void sortingManager(list_stud &list_manager) {
    int n = banyakStud(list_manager);

    if(n > 0) {
        // vector<int>manager (n);
        int manager[n];
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
        // sort(manager.begin(), manager.end());
        selectionSort(manager,n);
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