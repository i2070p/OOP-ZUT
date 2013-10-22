#include <stdlib.h>
#include <time.h>
#include <iostream>

#define _for(a) for(int i=0; i<a;i++)

using namespace std;

void Merge(int *A, int left, int mid, int right){
     int *tmp=new int[(right-left)+1];
     int i=left, j=mid+1, k=0;     
     while (i<=mid && j<=right) if (A[i]<=A[j]) tmp[k++]=A[i++]; else tmp[k++]=A[j++];     
     while (i<=mid) tmp[k++]=A[i++];
     while (j<=right) tmp[k++]=A[j++];
     for (int k=0; k<=right-left; k++) A[k+left] = tmp[k];
}
 
void MergeSort(int *A, int left, int right){
     if (left<right) {
        int mid=(left+right)/2;
        MergeSort(A, left, mid);
        MergeSort(A, mid+1, right);         
        Merge(A, left, mid, right);
     }
}

int main(int argc, char *argv[])
{
	srand(time(0));
	int *a = new int[10];
	
	_for(10) a[i]=rand()%1000;
	_for(10) cout << a[i] << ", ";
	
	MergeSort(a,0,9);
	
	cout << "_____________________\n";
	
	_for(10) cout << a[i] << ", ";   
	
	getchar();
  return EXIT_SUCCESS;
}
