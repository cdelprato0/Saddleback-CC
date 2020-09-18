/************************************************************************************
 * AUTHOR	      :Chaz Del Prato
 * STUDENT ID     :382108
 * Assignment #15 :Sort Performance
 * CLASS	      :CS1D
 * SECTION	      :M/W 3:00 PM
 ************************************************************************************/

/************************************************************************************
 * Assignment #15
 * --------------
 *		This program will empirically examine the run time efficiency of the
 *	Quicksort. For the first part of the program there will be an Ordered, Random,
 *	and Reversed arrays with different pivot points such as, First, Middle, Random
 *	pivots. The Arrays sizes for the first part are 5,000  10,000 and 50,000. Each
 *	section will output the size of the array, the first five number of the array,
 *	and the counter that keeps track of the number of times the quick sort occurred.
 *	On part two, there will be comparison between a heap sort and a merge sort.
 *	the array sizes will be 50,000 and 75,000. It will use the random, ordered, and
 *	reversed arrays. It will output the same thing as part one. Part three will be
 *	using a RADIX sort to sort an array of strings. It will output the list of string
 *	after each pass in the radix sort.
 ************************************************************************************/
#include "Header.h"

//FIST PIVOT
void exchange(int& a, int& b)
  // Exchanges the values of the variables a and b.
  {
	   steps++;
    int t;
    t = a;
    a = b;
    b = t;
  }

void partition(int a[],       // Array to be sorted
               int first,     // first index of partition
               int last,      // last index of partition
               int& pivindex  // final position of pivot
              )

   // partitions the elements from first to last in
   // the array t so that all the elements less than
   // the first element are placed at the beginning
   // of the array and all the elements greater than
   // the first element are placed at the end of the
   // array. The original element appears between the
   // two partitions at the position indicated by
   // pivindex.

   {
    int pivot;
    int up,down;
    pivot = a[first];
    up = first;
    down = last;
    do
      {
          // scan for element > pivot from left
       while (a[up]<=pivot && up<last){
       	   steps++;

    	   up++;
       }
          // scan for element <= pivot from right
       while (a[down]>pivot){
       	   steps++;

    	   down--;
       }
          // exchange
       if (up<down) {
       	   steps++;
    	   exchange(a[up],a[down]);
       }

      }
    while (up<down);
          // put pivot in between partitions }
	   steps++;
    exchange(a[first],a[down]);
    pivindex = down;
   }


void quicksort(int t[],
               int first,
               int last)
   // Sorts the first to last elements of the
   // int array t using the quicksort method.
   // If there is only one element in the array
   // then nothing is done.  After partitioning
   // the elements into two sets, those less than
   // a pivotal element and these greater than the
   // pivotal element, quicksort is called
   // recursively to sort each set in turn.
  {
    int pivindex;
    if (first<last)
      {
    	   steps++;

        partition(t,first,last,pivindex);
        quicksort(t,first,pivindex-1);
        quicksort(t,pivindex+1,last);
      }
  }

/* Function to print an array */
void printArray(int arr[], long size)
{
    long i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void reverseArray( int array[], long arraylength )
{
    for (long i = 0; i < (arraylength / 2); i++) {
        long double temporary = array[i];
        array[i] = array[(arraylength - 1) - i];
        array[(arraylength - 1) - i] = temporary;
    }
}

//RANDOM PIVOT
int randomPartition(int* arr, int start, int end)
{
    srand(time(NULL));
    int pivotIdx = start + rand() % (end-start+1);
    int pivot = arr[pivotIdx];
    swap(arr[pivotIdx], arr[end]); // move pivot element to the end
    pivotIdx = end;
    int i = start -1;

    for(int j=start; j<=end-1; j++)
    {
    	steps++;
        if(arr[j] <= pivot)
        {
        	steps++;
            i = i+1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[pivotIdx]);
    return i+1;
}

void randomQuickSort(int* arr, int start, int end)
{
    if(start < end) {
    	steps++;
        int mid = randomPartition(arr, start, end);
        randomQuickSort(arr, start, mid-1);
        randomQuickSort(arr, mid+1, end);
    }
}

//MIDDLE PIVOT
void swap(int a[], int i, int j)
{
	steps++;
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

/* sort arr[left]...arr[right] into increasing order */
void midQuickSort(int a[], int left_index, int right_index)
{
	int left, right, pivot;
	if(left_index >= right_index) return;

	left = left_index;
	right = right_index;

        // pivot selection
	pivot = a[(left_index + right_index) /2];

        // partition
	while(left <= right) {
		steps++;

		while(a[left] < pivot) {
			steps++;
			left++;
		}

		while(a[right] > pivot) right--;
		if(left <= right) {
			swap(a,left,right);
			left++; right--;
			steps++;
		}
	}

        // recursion
	midQuickSort(a,left_index,right);
	midQuickSort(a,left,right_index);
}

//MERGE SORT
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
        steps++;
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
        steps++;
    }
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
            steps++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            steps++;
        }
        k++;
        steps++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        steps++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        steps++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        steps++;
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
        steps++;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
        steps++;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        steps++;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
    	steps++;
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void print(int *a,int sz) {
	for(int i = 0; i < sz; i++)
		cout << a[i] << " ";
	cout << endl;
}

//RADIX SORT
size_t getMax(string arr[], int n){
    size_t max = arr[0].size();
    for (int i = 1; i < n; i++){
        if (arr[i].size()>max)
            max = arr[i].size();
    }

    return max;
}

void countSort(string a[], int size, size_t k){
    string *b = NULL; int *c = NULL;
    b = new string[size];
    c = new int[257];

    for (int i = 0; i <257; i++){
        c[i] = 0;
    }

    for (int j = 0; j <size; j++){
        c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;
    }

    for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
    }

    cout << "\n\nPrinting String: \n"
    		"------------------\n";
    for (int l = 0; l < size; l++){
        a[l] = b[l];
    	printf("    %s", b[l].c_str());
    }

    // avold memory leak
    delete[] b;
    delete[] c;
}

void radixSort(string b[], int r){
    size_t max = getMax(b, r);
    for (size_t digit = max; digit > 0; digit--){
        countSort(b, r, digit - 1);
    }

}

// Driver program to test above functions
int main()
{
//OUTPUT - Will output the header and a description of the output
cout << "**************************************************************************\n"
		"* PROGRAMMED BY  : Chaz Del Prato                                        *\n"
		"* ASSIGNMENT #15 : Sort Performance                                      *\n"
		"* CLASS          : CS1D                                                  *\n"
		"* SECTION        : MW 3:00p                                              *\n"
		"--------------------------------------------------------------------------\n"
		"* Description   :                                                        *\n"
		"*   This program has three parts to the output. In the first output, it  *\n"
		"* will be outputting the use of a quick sort. The arrays sizes used are  *\n"
		"* 5,000  10,000 and 50,000. Starting with the first pivot It will use the*\n"
		"* Random, Ordered, and Reversed arrays to display                        *\n"
		"* the size, the first 5 numbers of each array and the count of executions*\n"
		"* Then it will got to the Random pivot and output the same, and then to  *\n"
		"* the Middle pivot and output the same. In part TWO, It will be comparing*\n"
		"* Merge Sort and Heap Sort. The arrays sizes used is 50,000 and 75,000.  *\n"
		"* It will output the same information as it did for part one. The Third  *\n"
		"* part of the program will be using the RADIX sort. The radix sort will  *\n"
		"* be taking a list of strings and sorting them. It will output the       *\n"
		"* current list after each pass of the radix sort until it is sorted.     *\n"
		"**************************************************************************\n\n";

	int size1 = 5000;
	int size2 = 10000;
	int size3 = 50000;
	int size4 = 50000;
	int size5 = 75000;
    int arr1[size1];
    int arr2[size2];
    int arr3[size3];
    int arr4[size4];
    int arr5[size5];
    int temp;

    string data[10] = {"acdes", "asdsd", "ksjtr", "kerpt", "absqa",
    		      "zabaa", "rkdsb", "qqqqq", "kdfaa", "zedsd "};


    //RANDOM ORDER ARRAY
    for(int i = 0; i < size1; i++) {
    	temp = rand() % size1 + 1;
    	arr1[i] = temp; //I believe this should be array[j]=i
    }
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    quicksort(arr1, 0, n1-1);

    cout << "**********************\n"
    		"* PART 1 - QUICKSORT *\n"
    		"**********************\n";
    cout << "***RANDOM ORDER ARRAY (First Pivot)***\n"
    	 << "Size: " << size1 << endl;
    cout << "Sorted Array: ";
    printArray(arr1, 5);
    cout << "Counter: " << steps << endl << endl;
    steps = 0;


    for(int i = 0; i < size2; i++) {
    	temp = rand() % size2 + 1;
    	arr2[i] = temp; //I believe this should be array[j]=i
    }
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    quicksort(arr2, 0, n2-1);
	 cout << "Size: " << size2 << endl;
	 cout << "Array: ";
	 printArray(arr2, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;


	 for(int i = 0; i < size3; i++) {
    	temp = rand() % size3 + 1;
    	arr3[i] = temp; //I believe this should be array[j]=i
    }
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    quicksort(arr3, 0, n3-1);
	 cout << "Size: " << size3 << endl;
	 cout << "Array: ";
	 printArray(arr3, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;


	 //ORDERDED ARRAY
	 quicksort(arr1, 0, n1-1);
	 cout << "***ORDERED ARRAY (First Pivot)***\n";
	 cout << "Size: " << size1 << endl;
	 cout << "Array: ";
	 printArray(arr1, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 quicksort(arr2, 0, n2-1);
	 cout << "Size: " << size2 << endl;
	 cout << "Array: ";
	 printArray(arr2, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 quicksort(arr3, 0, n3-1);
	 cout << "Size: " << size3 << endl;
	 cout << "Array: ";
	 printArray(arr3, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;


	 //REVERSE ORDERDED ARRAY
	 reverseArray(arr1, size1);
	 quicksort(arr1, 0, n1-1);
	 cout << "***REVERSE ORDERED ARRAY (First Pivot)***\n";
	 cout << "Size: " << size1 << endl;
	 cout << "Array: ";
	 printArray(arr1, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 reverseArray(arr2, size2);
	 quicksort(arr2, 0, n2-1);
	 cout << "Size: " << size2 << endl;
	 cout << "Array: ";
	 printArray(arr2, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 //reverseArray(arr3, size3);
	 quicksort(arr3, 0, n3-1);
	 cout << "Size: " << size3 << endl;
	 cout << "Array: ";
	 printArray(arr3, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;



	//RANDOM ORDER ARRAY
	for(int i = 0; i < size1; i++) {
		temp = rand() % size1 + 1;
		arr1[i] = temp; //I believe this should be array[j]=i
	}
	randomQuickSort(arr1, 0, n1 - 1);

	cout << "***RANDOM ORDER ARRAY (Random Pivot)***\n"
		 << "Size: " << size1 << endl;
	cout << "Sorted Array: ";
	printArray(arr1, 5);
	cout << "Counter: " << steps << endl << endl;
	steps = 0;


	for(int i = 0; i < size2; i++) {
		temp = rand() % size2 + 1;
		arr2[i] = temp; //I believe this should be array[j]=i
	}
	randomQuickSort(arr2, 0, n2-1);
	 cout << "Size: " << size2 << endl;
	 cout << "Array: ";
	 printArray(arr2, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;


	 for(int i = 0; i < size3; i++) {
		temp = rand() % size3 + 1;
		arr3[i] = temp; //I believe this should be array[j]=i
	}
	 randomQuickSort(arr3, 0, n3-1);
	 cout << "Size: " << size3 << endl;
	 cout << "Array: ";
	 printArray(arr3, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 //ORDERDED ARRAY
	 randomQuickSort(arr1, 0, n1-1);
	 cout << "***ORDERED ARRAY (Random Pivot)***\n";
	 cout << "Size: " << size1 << endl;
	 cout << "Array: ";
	 printArray(arr1, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 randomQuickSort(arr2, 0, n2-1);
	 cout << "Size: " << size2 << endl;
	 cout << "Array: ";
	 printArray(arr2, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 randomQuickSort(arr3, 0, n3-1);
	 cout << "Size: " << size3 << endl;
	 cout << "Array: ";
	 printArray(arr3, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 //REVERSE ORDERDED ARRAY
	 reverseArray(arr1, size1);
	 randomQuickSort(arr1, 0, n1-1);
	 cout << "***REVERSE ORDERED ARRAY (Random Pivot)***\n";
	 cout << "Size: " << size1 << endl;
	 cout << "Array: ";
	 printArray(arr1, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 reverseArray(arr2, size2);
	 randomQuickSort(arr2, 0, n2-1);
	 cout << "Size: " << size2 << endl;
	 cout << "Array: ";
	 printArray(arr2, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 reverseArray(arr3, size3);
	 randomQuickSort(arr3, 0, n3-1);
	 cout << "Size: " << size3 << endl;
	 cout << "Array: ";
	 printArray(arr3, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	//RANDOM ORDER ARRAY
	for(int i = 0; i < size1; i++) {
		temp = rand() % size1 + 1;
		arr1[i] = temp; //I believe this should be array[j]=i
	}
	midQuickSort(arr1, 0, n1-1);

	cout << "***RANDOM ORDER ARRAY (Middle Pivot)***\n"
		 << "Size: " << size1 << endl;
	cout << "Sorted Array: ";
	printArray(arr1, 5);
	cout << "Counter: " << steps << endl << endl;
	steps = 0;


	for(int i = 0; i < size2; i++) {
		temp = rand() % size2 + 1;
		arr2[i] = temp; //I believe this should be array[j]=i
	}
	midQuickSort(arr2, 0, n2-1);
	 cout << "Size: " << size2 << endl;
	 cout << "Array: ";
	 printArray(arr2, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;


	 for(int i = 0; i < size3; i++) {
		temp = rand() % size3 + 1;
		arr3[i] = temp; //I believe this should be array[j]=i
	}
	 midQuickSort(arr3, 0, n3-1);
	 cout << "Size: " << size3 << endl;
	 cout << "Array: ";
	 printArray(arr3, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 //ORDERDED ARRAY
	 midQuickSort(arr1, 0, n1-1);
	 cout << "***ORDERED ARRAY (Middle Pivot)***\n";
	 cout << "Size: " << size1 << endl;
	 cout << "Array: ";
	 printArray(arr1, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 midQuickSort(arr2, 0, n2-1);
	 cout << "Size: " << size2 << endl;
	 cout << "Array: ";
	 printArray(arr2, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 midQuickSort(arr3, 0, n3-1);
	 cout << "Size: " << size3 << endl;
	 cout << "Array: ";
	 printArray(arr3, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 //REVERSE ORDERDED ARRAY
	 reverseArray(arr1, size1);
	 midQuickSort(arr1, 0, n1-1);
	 cout << "***REVERSE ORDERED ARRAY (Middle Pivot)***\n";
	 cout << "Size: " << size1 << endl;
	 cout << "Array: ";
	 printArray(arr1, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 reverseArray(arr2, size2);
	 midQuickSort(arr2, 0, n2-1);
	 cout << "Size: " << size2 << endl;
	 cout << "Array: ";
	 printArray(arr2, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 reverseArray(arr3, size3);
	 midQuickSort(arr3, 0, n3-1);
	 cout << "Size: " << size3 << endl;
	 cout << "Array: ";
	 printArray(arr3, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	cout << "***********************************\n"
			"* PART 2 - HEAP SORT / MERGE SORT *\n"
			"***********************************\n";
	//RANDOM ORDER ARRAY
	for(int i = 0; i < size4; i++) {
		temp = rand() % size4 + 1;
		arr4[i] = temp; //I believe this should be array[j]=i
	}
	int n4 = sizeof(arr4)/sizeof(arr4[0]);
	mergeSort(arr4, 0, n4-1);

	cout << "***RANDOM ORDER ARRAY (Merge Sort)***\n"
		 << "Size: " << size4 << endl;
	cout << "Sorted Array: ";
	printArray(arr4, 5);
	cout << "Counter: " << steps << endl << endl;
	steps = 0;



	for(int i = 0; i < size5; i++) {
		temp = rand() % size5 + 1;
		arr5[i] = temp; //I believe this should be array[j]=i
	}
	int n5 = sizeof(arr1)/sizeof(arr1[0]);
	mergeSort(arr5, 0, n5-1);
	 cout << "Size: " << size5 << endl;
	 cout << "Array: ";
	 printArray(arr5, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;



	 //ORDERDED ARRAY
	 mergeSort(arr4, 0, n4-1);
	 cout << "***ORDERED ARRAY (Merge Sort)***\n";
	 cout << "Size: " << size4 << endl;
	 cout << "Array: ";
	 printArray(arr4, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 mergeSort(arr5, 0, n5-1);
	 cout << "Size: " << size5 << endl;
	 cout << "Array: ";
	 printArray(arr5, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 //REVERSE ORDERDED ARRAY
	 reverseArray(arr4, size4);
	 mergeSort(arr4, 0, n4-1);
	 cout << "***REVERSE ORDERED ARRAY (Merge Sort)***\n";
	 cout << "Size: " << size4 << endl;
	 cout << "Array: ";
	 printArray(arr4, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 reverseArray(arr5, size5);
	 mergeSort(arr5, 0, n5-1);
	 cout << "Size: " << size5 << endl;
	 cout << "Array: ";
	 printArray(arr5, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;


	//RANDOM ORDER ARRAY
	for(int i = 0; i < size4; i++) {
		temp = rand() % size4 + 1;
		arr4[i] = temp; //I believe this should be array[j]=i
	}
	heapSort(arr4, size4);

	cout << "***RANDOM ORDER ARRAY (Heap Sort)***\n"
		 << "Size: " << size4 << endl;
	cout << "Sorted Array: ";
	printArray(arr4, 5);
	cout << "Counter: " << steps << endl << endl;
	steps = 0;


	for(int i = 0; i < size5; i++) {
		temp = rand() % size5 + 1;
		arr5[i] = temp; //I believe this should be array[j]=i
	}
	heapSort(arr5, size5);
	 cout << "Size: " << size5 << endl;
	 cout << "Array: ";
	 printArray(arr5, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 //ORDERDED ARRAY
	 heapSort(arr4, size4);
	 cout << "***ORDERED ARRAY (Heap Sort)***\n";
	 cout << "Size: " << size4 << endl;
	 cout << "Array: ";
	 printArray(arr4, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 heapSort(arr5, size5);
	 cout << "Size: " << size5 << endl;
	 cout << "Array: ";
	 printArray(arr5, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 //REVERSE ORDERDED ARRAY
	 reverseArray(arr4, size4);
	 heapSort(arr4, size4);
	 cout << "***REVERSE ORDERED ARRAY (Heap Sort)***\n";
	 cout << "Size: " << size4 << endl;
	 cout << "Array: ";
	 printArray(arr4, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;

	 reverseArray(arr5, size5);
	 heapSort(arr5, size5);
	 cout << "Size: " << size5 << endl;
	 cout << "Array: ";
	 printArray(arr5, 5);
	 cout << "Counter: " << steps << endl << endl;
	 steps = 0;


	 //Part 3 Radix Sort
	cout << "**************************\n"
			"* PART 3 - RADIX SORTING *\n"
			"**************************";

	 radixSort(data, (int)(sizeof(data) / sizeof(data[0])));

	 return 0;
}
