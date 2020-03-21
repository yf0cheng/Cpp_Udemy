// Section 12
// Challenge

/* Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes
  
  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.
  
  The function should return a pointer to the newly allocated array.
  
  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.
    
  For example,
  
  Below is the output from the following code which would be in main:
  
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print(array1,5);
    
    cout << "Array 2: " ;
    print(array2,3);
    
    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);
   
   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
*/
  
#include <iostream>

using namespace std;

void print (int [], const size_t);
void print2 (const int *const, size_t); // a ptr to an array is still a varial, type is the array type which is int here. Array is not a type. array is just an address.
//int * apply_all(int [], const size_t, int [], const size_t);
int * apply_all(const int *const arr1, const size_t arr1_size, const int *const arr2, const size_t arr2_size);
//int * apply_all(const int *const , const size_t , const int *const , const size_t );

int main() {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};
    
    cout << "Array 1: " ;
    print2(array1,array1_size);
    
    cout << "Array 2: " ;
    print2(array2,array2_size);
    
    int *results = apply_all(array1, array1_size, array2, array2_size); // declare a ptr results and initial the value from the return value of apply_all func.
    constexpr size_t results_size {array1_size * array2_size};

    cout << "Result: " ;
    print2(results, results_size);
    
    cout << endl;
    
    delete [] results;

    return 0;
}

void print (int array[], const size_t array_size){
    cout << "[ ";
    for (size_t i {0}; i<array_size; i++){
        cout<< array[i] << " ";
    }
    cout<<"]"<<endl;
}

//int * apply_all(int array1[], const size_t array1_size, int array2[], const size_t array2_size){
int * apply_all(const int *const array1, const size_t array1_size, const int *const array2, const size_t array2_size){
    int *array_ptr {nullptr};
    array_ptr = new int [array1_size*array2_size];
    size_t k {0};
    for (size_t i {0}; i<array2_size; i++){
        for (size_t j {0}; j<array1_size; j++){
/* method 1*/
//            *(array_ptr+  k) = array1[j]*array2[i];
//            k++;
/*method 2*/
            array_ptr[k++] = array1[j]*array2[i];
        }
    }
    return array_ptr;
}

void print2 (const int *const arr, size_t size){
    cout << "[ ";
    for (size_t i {0}; i<size; i++){
        cout<< arr[i] << " ";
    }
    cout<<"]"<<endl;
}