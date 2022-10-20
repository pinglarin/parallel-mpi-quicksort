#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the leftmost element as pivot
  int pivot = array[low];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// main function
int main(int argc, char *argv[]) {

    FILE *file = NULL;
    int number_of_elements;
    clock_t t;

    if (argc != 3)
    {
        printf("Desired number of arguments are not their "
               "in argv....\n");
        printf("2 files required first one input and "
               "second one output....\n");
        exit(-1);
    }

    // Opening the file
    file = fopen(argv[1], "r");

    // Printing Error message if any
    if (file == NULL)
    {
        printf("Error in opening file\n");
        exit(-1);
    }
    fscanf(file, "%d", &number_of_elements);
    printf("Number of Elements in the file is %d \n", number_of_elements);

    // Reading the rest elements in which
    // operation is being performed
    int data[number_of_elements];
    printf("Reading the array from the file.......\n");
    for (int i = 0; i < number_of_elements; i++)
    {
        fscanf(file, "%d", &data[i]);
    }
    fclose(file);
    file = NULL;
    t = clock();
    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array\n");
    printArray(data, n);

    // perform quicksort on data
    quickSort(data, 0, n - 1);

    t = clock() - t;

    file = fopen(argv[2], "w");

    if (file == NULL)
    {
        printf("Error in opening file... \n");
        exit(-1);
    }

    // Printing total number of elements
    // in the file
    fprintf(
        file,
        "Total number of Elements in the array : %d\n",
        number_of_elements);

    // Printing the value of array in the file
    for (int i = 0; i < number_of_elements; i++)
    {
        fprintf(file, "%d  ", data[i]);
    }

    // Closing the file
    fclose(file);
    printf("Sorted array in ascending order: \n");
    printArray(data, n);
    printf(
        "\n\nSequencial Quicksort %d ints: %f secs\n",
        number_of_elements,((float)t) / CLOCKS_PER_SEC);
}