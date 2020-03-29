/*
Given a set of n jobs where each job i has a deadline di >=1 and profit pi>=0. 
Only one job can be scheduled at a time. 
Each job takes 1 unit of time to complete. 
We earn the profit if and only if the job is completed by its deadline. 
The task is to find the subset of jobs that maximizes profit.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct job_struct  
{
    int job_id;
    int deadline;
    int profit;
} job_type;

int calc_profit(int*, int*, int*, int); 

int main()
{    
    int job_id_list[] = {1, 2, 3, 4, 5};
    int deadline_list[] = {2, 1, 2, 1, 3};
    int profit_list[] = {100, 19, 27, 25, 15};
    int num_of_jobs = 5;

    cout<<"Max Profit = " 
        << calc_profit(job_id_list, deadline_list, profit_list, num_of_jobs)
        << endl;

    return 0;
}

int calc_profit(int* job_id_list, int* deadline_list, int* profit_list, int num_of_jobs)
{
    vector<job_type> job_list;
    int profit = 0;

    while(num_of_jobs--)
    {
        job_type job;
        job.job_id = job_id_list[num_of_jobs];
        job.deadline = deadline_list[num_of_jobs];
        job.profit = profit_list[num_of_jobs];

        job_list.push_back(job);
    } 

    //Get Max deadline
    int max_deadline = (*max_element(job_list.begin(), job_list.end(), 
                            [](job_type j1, job_type j2){
                                return j1.deadline < j2.deadline;
                            }
                        )).deadline;

    //Sort the job array as per the profit
    sort(job_list.begin(), job_list.end(), 
            [](job_type j1, job_type j2){
                return j1.profit > j2.profit;    
            }
        );

    int *job_slot = new int[max_deadline + 1];

    //Place unassign value in every timeslot
    for(int i = 0; i <= max_deadline; i++)
        job_slot[i] = -1;

    for(auto job : job_list)
    {
        // cout<<job.job_id<<","<<job.deadline<<","<<job.profit<<endl;
        int deadline = job.deadline;
        
        //Check whether any timeslot less than the 
        //current deadline is available
        while(deadline-- > 0)
        {
            //If any of the timeslots is available,
            //assign the job in the timeslot 
            //and add the profit
            if(job_slot[deadline] == -1)
            {
                //Assign jobid in timeslots
                job_slot[deadline] = job.job_id;
                profit += job.profit;
                break;
            }
        }        
    }

    return profit;
}