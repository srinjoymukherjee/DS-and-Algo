/*
C++ program to find maximum
subarray size, such that all
subarrays of that size have
sum less than K
*/

#include <iostream>

using namespace std;

int* prefixSum(int arr[], int size){
        int* prefSum = new int[size + 1];
        prefSum[0] = 0;

        for(int idx = 1; idx < size + 1; idx++){
                prefSum[idx] = arr[idx - 1] + prefSum[idx - 1];
        }

        return prefSum;
}

int maxSubSearch(int* prefSum, int key, int size){
        int left = 1, right = size, mid = -1, res = 0;
        bool lessSub = true;

        while(left <= right){
                mid = (left + right)/2;
                for(int idx = mid; idx <= size; idx++){
                        if(prefSum[idx] - prefSum[idx - mid] > key){
                                lessSub = false;
                                break;
                        }
                }
                if(lessSub){
                        res = mid;
                        left = mid + 1;
                }else{
                        right = mid - 1;
                }
        }

        return res;
}

int maxSubSize(int arr[], int size, int key){
        int* prefSum = prefixSum(arr, size);
        int res = maxSubSearch(prefSum, key, size);
        delete prefSum;
        prefSum = nullptr;
        return res;
}

int main(){
        int arr[] = {1, 2, 10, 4};
        int key = 0;
        cout<<"Provide the Key:"<<endl;
        cin>>key;
        int size = sizeof(arr)/sizeof(int);

        cout<<"Max Sub Array Size with sum less than: "<<key<<" is "<<maxSubSize(arr, size, key)<<endl;

        return 0;
}
