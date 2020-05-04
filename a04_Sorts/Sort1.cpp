#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Movie {
    int rank;
    string title;
    float grossSales;
    int yearReleased;

    //bool operator  > (const Movie & data) const;
};

//bool Movie :: operator  > (const Movie & data) const
//{
//  return (this -> rank > data.rank);
//}

const int ARRSIZE = 1000;
int LoopCount = 0;

// function prototypes
void copyArray(const Movie arr1[], Movie arr2[]);

void printArray(const Movie arr[], ofstream & txtOut);

void readCSV(const string fileName, Movie arr[]);

void shellSort(Movie arr[], int n);

void radixSort(Movie arr[], int n);

Movie getMax(Movie arr[], int n);

void countSort(Movie arr[], int n, int exp);
void selectionSort(Movie arr[], int n);
void insertionSort(Movie arr[], int n);
void bubbleSort(Movie arr[], int n);
void heapSort(Movie arr[], int n);
void quickSort(Movie arr[], int low, int high);
void mergeSort(Movie arr[], int l, int r);

int main() {
    Movie unsortedArr[ARRSIZE];
    Movie sortedArr[ARRSIZE];
    string cStr;
    ofstream txtOut;
    txtOut.open("Sorts.txt");

    readCSV("TopGrossingMovies.csv", unsortedArr);
    copyArray(unsortedArr, sortedArr);
    txtOut << "Beginning Shell Sort" << endl;
    printArray(sortedArr, txtOut);
    LoopCount = 0;
    shellSort(sortedArr, ARRSIZE);
    printArray(sortedArr , txtOut);
    txtOut << "Loop Count For Shell Sort:" << LoopCount << endl;
    txtOut << endl;

    copyArray(unsortedArr, sortedArr);
    txtOut << "Beginning Radix Sort" << endl;
    printArray(sortedArr, txtOut);
    LoopCount = 0;
    radixSort(sortedArr, ARRSIZE);
    printArray(sortedArr, txtOut);
    txtOut << "Loop Count For Radix Sort:" << LoopCount << endl;
    txtOut << endl;

    copyArray(unsortedArr, sortedArr);
    txtOut << "Beginning Selection Sort" << endl;
    printArray(sortedArr, txtOut);
    LoopCount = 0;
    selectionSort(sortedArr, ARRSIZE);
    printArray(sortedArr, txtOut);
    txtOut << "Loop Count For Selection Sort:" << LoopCount << endl;
    txtOut << endl;

    copyArray(unsortedArr, sortedArr);
    txtOut << "Beginning Insertion Sort" << endl;
    printArray(sortedArr, txtOut);
    LoopCount = 0;
    insertionSort(sortedArr, ARRSIZE);
    printArray(sortedArr, txtOut);
    txtOut << "Loop Count For Insertion Sort:" << LoopCount << endl;
    txtOut << endl;

    copyArray(unsortedArr, sortedArr);
    txtOut << "Beginning Bubble Sort" << endl;
    printArray(sortedArr, txtOut);
    LoopCount = 0;
    bubbleSort(sortedArr, ARRSIZE);
    printArray(sortedArr, txtOut);
    txtOut << "Loop Count For Bubble Sort:" << LoopCount << endl;
    txtOut << endl;

    copyArray(unsortedArr, sortedArr);
    txtOut << "Beginning Heap Sort" << endl;
    printArray(sortedArr, txtOut);
    LoopCount = 0;
    heapSort(sortedArr, ARRSIZE);
    printArray(sortedArr, txtOut);
    txtOut << "Loop Count For Heap Sort:" << LoopCount << endl;
    txtOut << endl;

    copyArray(unsortedArr, sortedArr);
    txtOut << "Beginning Quick Sort" << endl;
    printArray(sortedArr, txtOut);
    LoopCount = 0;
    quickSort(sortedArr, 0, ARRSIZE - 1);
    printArray(sortedArr, txtOut);
    txtOut << "Loop Count For Quick Sort:" << LoopCount << endl;
    txtOut << endl;

    copyArray(unsortedArr, sortedArr);
    txtOut << "Beginning Merge Sort" << endl;
    printArray(sortedArr, txtOut);
    LoopCount = 0;
    mergeSort(sortedArr, 0, ARRSIZE - 1);
    printArray(sortedArr, txtOut);
    txtOut << "Loop Count For Merge Sort:" << LoopCount << endl;
    txtOut << endl;

    txtOut.close();

    cout << "Press any Key to continue" << endl;
    cin >> cStr;

    return 0;
}

void readCSV(const string fileName, Movie arr[]) {
    Movie m;
    ifstream fileIn;
    string cStr;
    int i = 0;

    fileIn.open(fileName);

    while (getline(fileIn, cStr, ',')) {
        m.rank = stoi(cStr);
        getline(fileIn, cStr, ',');
        m.title = cStr;
        getline(fileIn, cStr, ',');
        m.grossSales = stof(cStr);
        getline(fileIn, cStr, '\n');
        m.yearReleased = stoi(cStr);
        arr[i] = m;
        i++;
    }

    fileIn.close();
}

void copyArray(const Movie arr1[], Movie arr2[]) {
    for (int i = 0; i < ARRSIZE; i++) {
        arr2[i] = arr1[i];
    }
}

void printArray(const Movie arr[], ofstream & txtOut) {
    // print first 5 records
    for (int i = 0; i < 5; i++) {
        txtOut << i << " " << arr[i].rank << " " << arr[i].title << " ";
        txtOut << arr[i].grossSales << " " << arr[i].yearReleased << endl;
    }

    // print last 5 records
    for (int i = (ARRSIZE - 5); i < ARRSIZE; i++) {
        txtOut << i << " " << arr[i].rank << " " << arr[i].title << " ";
        txtOut << arr[i].grossSales << " " << arr[i].yearReleased << endl;
    }
}

void shellSort(Movie arr[], int n) {
    Movie temp;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].rank > temp.rank; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
            LoopCount++;
        }
    }
}

void radixSort(Movie arr[], int n) {
    Movie m = getMax(arr, n);

    for (int exp = 1; m.rank / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

void swap(Movie *xp, Movie *yp) {
    Movie temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

Movie getMax(Movie arr[], int n) {
    Movie max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].rank > max.rank) {
            max = arr[i];
        }
    }

    return max;
}

void countSort(Movie arr[], int n, int exp) {
    Movie output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++) {
        count[(arr[i].rank / exp) % 10]++;
        LoopCount++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        LoopCount++;
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[ (arr[i].rank/exp)%10 ] - 1] = arr[i];
        count[ (arr[i].rank/exp)%10 ]--;
        LoopCount++;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void heapify(Movie arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].rank > arr[largest].rank)
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r].rank > arr[largest].rank)
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        LoopCount++;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void selectionSort(Movie arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].rank < arr[min_idx].rank)
                min_idx = j;
            LoopCount++;
        }

        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(Movie arr[], int n) {
    Movie key;
    int i, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].rank > key.rank) {
            arr[j + 1] = arr[j];
            j = j - 1;
            LoopCount++;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(Movie arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].rank > arr[j + 1].rank) {
                swap(&arr[j], &arr[j + 1]);
            }
            LoopCount++;
        }
}

// main function to do heap sort
void heapSort(Movie arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        LoopCount++;
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        LoopCount++;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int partition(Movie arr[], int low, int high) {
    Movie pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j].rank < pivot.rank) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
        LoopCount++;
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(Movie arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
        LoopCount++;
    }
}

void merge(Movie arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    Movie L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
//        LoopCount++;
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
//        LoopCount++;
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].rank <= R[j].rank) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        LoopCount++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        LoopCount++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        LoopCount++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(Movie arr[], int l, int r) {
    LoopCount++;
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
