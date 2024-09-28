
/***************************************************************************************************************
Author: Aarav Subberwal
Date: 20/09/2024

Program to visually showcase different sorting methods!

"Footprints of the greatest minds are considerred sacred"
****************************************************************************************************************/
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

void wait(double wait_time_seconds)
{ // Wait(this many seconds) function
    auto wait_duration = std::chrono::duration<double>(wait_time_seconds);
    std::this_thread::sleep_for(wait_duration);
}
void printstuff(std::vector<int> arr)
{
    std::cout << "\033[2J\033[1;1H";
    std::string line = "";
    for (int a = 0; a < arr.size(); a++)
    {
        for (int b = 0; b < arr[a]; b++)
        {
            line += "# ";
        }
        std::cout << line << "\n";
        line.clear();
    }
    wait(0.1);
}
void bubble_sort(std::vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag++;
            }
        }
        printstuff(arr);
        if (flag == 0)
        {
            break;
        }
        else
        {
            flag = 0;
        }
    }
}
void selection_sort(std::vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                printstuff(arr);
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
void insertionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printstuff(arr);
    }
}
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        printstuff(arr);
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Wrapper function to make it easier to call
void mergeSort(std::vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

int main()
{
    std::vector<int> arr = {7, 23, 12, 4, 29, 15, 1, 19, 9, 26, 3, 17, 30, 11, 24, 6, 21, 14, 28, 8, 25, 2, 18, 10,
                            5, 22, 16, 27, 13, 20};

    std::cout << "\033[H\n\nTime for Bubble sort Bitch"; // clears out the terminal
    wait(2);
    bubble_sort(arr);

    std::cout << "\033[2J\033[1;1H\nNow time for some selection sort";
    wait(2);
    selection_sort(arr);

    std::cout << "\033[2J\033[1;1H\nNow time for some insertion sort";
    wait(2);
    insertionSort(arr);

    std::cout << "\033[2J\033[1;1H\nNow time for some Merge sort";
    wait(2);
    mergeSort(arr);

    return 0;
}