//Stone Gulliksen
//CSE 310
#include <cstdlib>
#include <iostream>
#include <array>
#include <climits>
#include <chrono>
using namespace std;
using namespace std::chrono;

//Insert Sort Algorithm
void Insert_Sort(double Array[], int array_size)
{
    //Algorithm will start on second index and be declared as the key
    for (int j_index = 1; j_index <= array_size; j_index++)
    {
        int key = Array[j_index];
        //index prior to the algorithm will be declared int index
        int index = j_index - 1;
        //while loop with conditions that follow:
        // while - int index is greater then zero (to avoid a out of bounds error)
        // && while the value of index within the array is greater then the key(meaning while index is still unsorted
        while (index > 0 && Array[index] > key)
        {
            //index will make itself equal to the next index over and then continue down the array
            Array[index + 1] = Array[index];
            index--;
        }
        //At the end of the loop the next index after index will be declared the new key
        Array[index + 1] = key;
    }
}

// Selection Sort Algorithm
void Selection_Sort(double Array[], int array_size)
{
    int length = array_size;
    //loop that will go through the array starting at the first index
    for (int index = 0; index <= length - 1; index++)
    {
        //int index will will be the minimum
        int minimum = index;
        //for loop that will search the array for the minimum value and overwrite itself as it finds a smaller value
        for (int j_index = index + 1; j_index <= length; j_index++)
        {
            if (Array[j_index] < Array[minimum])
            {
                minimum = j_index;
            }
        }
        //Swap the found minimum value with the element
        double temp = Array[minimum];
        Array[minimum] = Array[index];
        Array[index] = temp;
    }
}

//Merge sort algorithm
void merge(double Array[], int left_index, int middle_index, int right_index)
{
    // created sub arrays contain the index of
    int n1 = middle_index - left_index + 2;
    int n2 = right_index - middle_index + 1;
    int* left_array = new int[n1];
    int* right_array = new int[n2];

    // Copy data to the left and right sub arrays
    for (int index = 1; index <= n1; index++)
    {
        left_array[index] = Array[left_index + index - 1];
    }
    for (int j_index = 1; j_index <= n2; j_index++)
    {
        right_array[j_index] = Array[middle_index + j_index];
    }

    left_array[n1] = INT_MAX;
    right_array[n2] = INT_MAX;

    int index = 1;
    int j_index = 1;

    //move the temp arrays back into the main array
    for (int k = left_index; k <= right_index; k++)
    {
        if (left_array[index] <= right_array[j_index])
        {
            Array[k] = left_array[index];
            index = index + 1;
        }
        else
        {
            Array[k] = right_array[j_index];
            j_index = j_index + 1;
        }
    }
}

//Merge sort contains recursive call to merge itself back together
void Merge_sort(double Array[], int left_index, int right_index)
{
    if (left_index < right_index)
    {
        int middle_index = ((left_index + right_index) / 2);
        Merge_sort(Array, left_index, middle_index);
        Merge_sort(Array, middle_index + 1, right_index );
        merge(Array, left_index, middle_index, right_index);
    }
}

//partition method is a recursive method used in quick sort
int partition(double Array[], int left_index, int right_index)
{
    // pivot takes the place of the last element in the array
    int pivot = Array[right_index];
    int index = (left_index - 1);
    int temp;
    //for loop goes through and checks if the element is smaller or equal to the pivot
    for (int j_index = left_index; j_index <= right_index - 1; j_index++)
    {
        if (Array[j_index] <= pivot)
        {
            //increment index of smaller element
            index++;
            temp = Array[index];
            Array[index] = Array[j_index];
            Array[j_index] = temp;
        }
    }
    temp = Array[index + 1];
    Array[index + 1] = Array[right_index];
    Array[right_index] = temp;
    return (index + 1);
}

//quick sort algorithm
void quickSort(double Array[], int left_index, int right_index)
{
    if (left_index < right_index)
    {
        int pivot = partition(Array, left_index, right_index);

        //Individually sorts elements within each field before and after the partition
        quickSort(Array, left_index, pivot - 1);
        quickSort(Array, pivot + 1, right_index);
    }
}

// Print method to print the array's ints onto the console
void printArray(double Array[], int array_size)
{
    for (int index = 1; index <= array_size; index++)
    {
        cout << (Array[index]) << " ";
        if (index % 10 == 0)
            cout << "\n";
    }
}

//main menu print method
void menu()
{
    cout << "\nOk! Which sorting method would you like to use\n";
    cout << "Press 1 for Insert Sort\n";
    cout << "Press 2 for Selection Sort\n";
    cout << "Press 3 for Merge Sort\n";
    cout << "Press 4 for Quick Sort\n";
    cout << "Press 5 to Exit\n";
    cout << "Press 6 to Restart and pick a new array size\n\n";

    cout << "Program will print the array unsorted first.\nIt will then sort it with the chosen method. ";
    cout << "(This depends if the print methods are commented out or not)\n\n";
}

int main()
{
    //User will select the array size
    int array_size;
    cout << "Hello welcome to program 2 for CSE 310\n";
    cout << "What size would you like the array to be?\n";
    cin >> array_size;
    double* array = new double[array_size];
    int choice = 0;
    while (choice != 5)
    {
        menu();
        cin >> choice;

        //Fill the array with random numbers
        for (int index = 0; index <= array_size; index++)
        {
            array[index] = rand() / double(RAND_MAX)*900.f + 100.f;
        }



        switch (choice)
        {
            case 1: //insert Sort
            {
                cout<<"\nPrinting array before being sorted\n";
                //printArray(array,array_size);
                cout<< "\nUsing Insertion Sort\n";
                auto start = high_resolution_clock::now();
                Insert_Sort(array, array_size);
                auto finish = high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;

                //printArray(array, array_size);
                cout<< "\nUsing Insertion Sort with array size: " << array_size;
                cout<<"\nRuntime is: " << elapsed.count() << " seconds\n";
                break;
            }

            case 2: //selection Sort
            {
                cout<<"\nPrinting array before being sorted\n";
                //printArray(array,array_size);
                cout<< "\nUsing Selection Sort\n";
                auto start = high_resolution_clock::now();
                Selection_Sort(array, array_size);
                auto finish = high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;

                //printArray(array, array_size);
                cout<< "\nUsing Selection Sort with array size: " << array_size;
                cout<<"\nRuntime is: " << elapsed.count() << " seconds\n";
                break;
            }

            case 3:
            {
                cout<<"\nPrinting array before being sorted\n";
                //printArray(array,array_size);
                cout<< "\nUsing Merge Sort\n";
                auto start = high_resolution_clock::now();
                Merge_sort(array,0, array_size);
                auto finish = high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;

                //printArray(array, array_size);
                cout<< "\nUsing Merge Sort with array size: " << array_size;
                cout<<"\nRuntime is: " << elapsed.count() << " seconds\n";

                break;
            }

            case 4: //Quick Sort
            {
                cout<<"\nPrinting array before being sorted\n";
                //printArray(array,array_size);
                cout<<"\nUsing Quick Sort\n";
                auto start = high_resolution_clock::now();
                quickSort(array, 0 , array_size);
                auto finish = high_resolution_clock::now();
                std::chrono::duration<double> elapsed = finish - start;

                //printArray(array, array_size);
                cout<<"\nUsing Quick Sort with array size: " << array_size;
                cout<<"\nRuntime is: " << elapsed.count() << " seconds\n";
                break;
            }

            case 5:
            {
                return 0;
                break;
            }

            case 6:
            {
                main();
                break;
            }

            default:
            {
                cout<<"\nNot valid input";
                break;
            }
        }
    }
    return 0;
}