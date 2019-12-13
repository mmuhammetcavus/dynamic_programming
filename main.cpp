/*
Student Name:Muhammet Çavuş
Student Number: 2018400306
Project Number: 5
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;

using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
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
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m =(r+l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


int main(int argc, char* argv[]){
    auto start = high_resolution_clock::now();

    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    int size;
    inFile>>size;
    int limit;
    inFile>>limit;
    if(size==0 or limit==0) {
        outFile<<"0";
        return 0;
    }
    int p [size];
    long long int P [limit];
    for(int i=0; i<size; i++)
        inFile>>p[i];
    mergeSort(p,0,size-1);
    P[0]=p[0];
    long long int saved, temp;
    saved=0;
    outFile<<P[0]<<" ";
    for(int i=1; i<size; i++) {
        temp=P[i%limit];
        P[i%limit]+=p[i]+P[(i-1)%limit]-saved;
        if(i>=limit)
            saved=temp;
        outFile<<P[i%limit]<<" ";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << duration.count()<<" milliseconds" << endl;
    return 0;
}