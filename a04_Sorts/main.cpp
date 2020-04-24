#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Movie
{
  int rank;
  string title;
  float grossSales;
  int yearReleased;
};

const int ARRSIZE = 1000;
void copyArray(const Movie arr1[], Movie arr2[]);
void printArray(const Movie arr[]);
void readCSV(const string fileName, Movie arr[]);

int main() {
  Movie unsortedArr[ARRSIZE];
  Movie sortedArr[ARRSIZE];

  readCSV("TopGrossingMovies.csv", unsortedArr);
  copyArray(unsortedArr, sortedArr);
  printArray(sortedArr);

  return 0;
}

void readCSV(const string fileName, Movie arr[])
{
  Movie m;
  ifstream fileIn;
  string cStr;
  int i = 0;

  fileIn.open(fileName);

  while(getline(fileIn, cStr, ','))
  {
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
  cout << "Records read: " << i << endl;
}

void copyArray(const Movie arr1[], Movie arr2[])
{
  for (int i=0; i<ARRSIZE; i++)
  {
      arr2[i] = arr1[i];
  }
}

void printArray(const Movie arr[])
{
  // print first 5 records
  for (int i=0; i<5; i++)
  {
      cout << arr[i].title << endl;
  }

  // print last 5 records
  for (int i=(ARRSIZE-5); i<ARRSIZE; i++)
  {
      cout << arr[i].title << endl;
  }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};

    for (i =0; i < n; i++)
    {
        count[(arr[i]/exp)%10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i + 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

int shellSort(int arr[], int n)
{
    for ( int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for(j = i; j>= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m/exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for(i = 0; i< n -1; i++)
    {
        min_idx = i;
        for(j = i +1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }

        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i -1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n)
{
    int i,j;
    for ( i = 0; i < n -1; i++)

    for(j = 0; j < n - i - 1; j++)
    {
        if(arr[j] > arr[j+1])
        {
            swap(&arr[j], &arr[j+1]);
        }
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
