#include <iostream>
#include<conio.h>
#include<stdlib.h>

#define MAX_SIZE 12

using namespace std;

void merge_sort(int, int);
void merge_array(int, int, int, int);

int arr_sort[MAX_SIZE] = {12, 10, 45, 23, -78, 45, 123, 56, 98, 41, 90, 50};

int main() {
    int i;

    cout << "Simple C++ Merge Sort Example - Functions and Array\n";
 
    cout << "\nOriginal Data   :";
    for (i = 0; i < MAX_SIZE; i++) {
        cout << "\t" << arr_sort[i];
    }
			// 0 , 11
    merge_sort(0, MAX_SIZE - 1);

    cout << "\n\nSorted Data :";
    for (i = 0; i < MAX_SIZE; i++) {
        cout << "\t" << arr_sort[i];
    }

    getch();

}
				// 0 , 11
void merge_sort(int lo, int hi) {
    int mid;

    if (lo < hi) {
      mid = (lo + hi) / 2;
        merge_sort(lo, mid);
        merge_sort(mid + 1, hi);
        
		// Merging two arrays
        merge_array(lo, mid, mid + 1, hi);
    }
}
			//   	lo		mid		 mid+1		hi
void merge_array(int a_lo, int a_hi, int b_lo, int b_hi) {
    int temp[50];
    int leftIdx = a_lo, rightIdx = b_lo, tmpIdx = 0;

    while (leftIdx <= a_hi && rightIdx <= b_hi) {
        if (arr_sort[leftIdx] < arr_sort[rightIdx])
            temp[tmpIdx++] = arr_sort[leftIdx++];
        else
            temp[tmpIdx++] = arr_sort[rightIdx++];
    }

    //Copy the remaining elements in left-half to temporary array
    while (leftIdx <= a_hi)
        temp[tmpIdx++] = arr_sort[leftIdx++];
    
	//Copy the remaining elements in right-half to temporary array
    while (rightIdx <= b_hi)
        temp[tmpIdx++] = arr_sort[rightIdx++];
	
	//copy the contents of temporary array (temp[]) back to the original array (arr_sort[])
	for (int oriIdx = a_lo, tempIdx = 0; oriIdx <= b_hi; oriIdx++, tempIdx++)
        arr_sort[oriIdx] = temp[tempIdx];
}

