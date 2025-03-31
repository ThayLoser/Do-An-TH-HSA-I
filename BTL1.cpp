#include<iostream>
using namespace std;

// Merge Sort #8
void merge(int *arr,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int*L1=new int[n1];
    int*L2=new int[n2];
    for(int i=0;i<n1;i++){
        *(L1+i)=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        *(L2+i)=arr[mid+i+1];
    }
    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(*(L1+i)>*(L2+j)){
            *(arr+k)=*(L2+j);
            j++;
        }else{
            *(arr+k)=*(L1+i);
            i++;
    
        }
        k++;
    }
    while(i<n1){
        *(arr+k)=*(L1+i);
        k++;
        i++;
    }
    while(j<n2){
        *(arr+k)=*(L2+j);
        k++;
        j++;
    }
    delete[] L1;
    delete[] L2;
    }
     void mergesor(int*arr,int left,int right){
        if(left>=right)return;
    int mid=left+(right-left)/2;
    mergesor(arr,left,mid);
    mergesor(arr,mid+1,right);
    merge(arr,left,mid,right);
    
     }
    // Shaker Sort #5
    void shakerSort(int*arr,int size){
        int left,right,k,i;
        left=0;
        right=size-1;
        k=size-1;
        while(left<right){
            for( i=right;i>left;i--){
                if(*(arr+i)<*(arr+i-1)){
                swap(*(arr+i),*(arr+i-1));
            k=i;   
            }
            }
            left=k; 
            for(i=left;i<right;i++){
                if(*(arr+i)>*(arr+i+1)){
                    swap(*(arr+i),*(arr+i+1));
                k=i;   
                }
            }
            right=k;
        }
    }
    // BinaryInsertion Sort #3
    int binarySearch(int*arr,int left,int right,int x){
        if (left > right)
        return left;

        int mid=left+(right-left)/2;
        if(*(arr+mid)==x)return mid+1;
        else if(*(arr+mid)>x)return binarySearch(arr,left,mid-1,x);
        else return binarySearch(arr,mid+1,right,x);
    }
    void BinaryInsertionSort(int*arr,int size){
        int i,j,loc,selection;
        for(i=1;i<size;i++){
            selection=*(arr+i);
            j=i-1;
            loc=binarySearch(arr,0,j,selection);
            while(j>=loc){
                *(arr+j+1)=*(arr+j);
                j--;   
            }
            *(arr+j+1)=selection;
        }
    }

 
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //mergesor(arr, 0, size - 1);
    //BinaryInsertionSort(arr,size);
    //shakerSort(arr,size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}