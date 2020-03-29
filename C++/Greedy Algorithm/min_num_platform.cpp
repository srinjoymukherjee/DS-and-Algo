/*
Given arrival and departure times of all trains that reach a railway station. 
Your task is to find the minimum number of platforms required for the railway station 
so that no train waits.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int num_of_platform(int*, int*, int);

int main()
{
    int num_of_trains = 6;
    // int* arr = new int[num_of_trains];
    // int* dep = new int[num_of_trains];
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

    cout<<num_of_platform(arr, dep, num_of_trains)<<endl;
}

int num_of_platform(int* arr, int* dep, int num_of_trains)
{
    int i = 0, j = 0;
    int p_count = 0;
    int max_count = 0;

    //Sort the arrival times
    sort(arr, arr + num_of_trains);

    //sort depurture times
    sort(arr, arr + num_of_trains);

    //For every arrival, before depurture, we need a platform.
    //So if we arrange arrival and depurture times in assending order,
    //every arrival will add one more platform count
    //and every depurture will minus one platform from count
    while(i < num_of_trains && j < num_of_trains)
    {
        if(arr[i] <= dep[j])
        {
            p_count++;
            i++;
            max_count = max_count < p_count ? p_count : max_count;
        }
        else
        {
            p_count--;
            j++;
        }        
    }

    return max_count;
}