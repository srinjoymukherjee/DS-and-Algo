/*
Given a fraction, find recurring sequence of digits if exists, 
otherwise print “No recurring sequence”.

Examples:
Input  : Numerator = 8, Denominator = 3
Output : Recurring sequence is 6 
Explanation : 8/3 = 2.66666666.......  
*/
#include<bits/stdc++.h>

using namespace std;

string repeating_fraction(int, int);

int main(){
    int numerator = 333;
    int denominator = 106;
    string retVal = repeating_fraction(numerator, denominator);

    if(retVal != "")
    {
        cout<<retVal<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    
    return 0;
}

string repeating_fraction( int numerator, int denominator)
{
    bool isFraction = false;
    unordered_set<int> fraction;
    string retVal = "";

    while(true)
    {
        if(numerator < denominator)
        {
            numerator = numerator * 10;
            isFraction = true;
        }

        int floor = numerator/denominator;
        int remainder = numerator % denominator;

        if(isFraction)
        {
            if(retVal.empty())
                retVal += to_string(0);
            
            if(retVal.find(".") == string::npos)
                retVal += ".";

            if(fraction.find(floor) != fraction.end())
            {
                string base_val = retVal.substr(0,(retVal.find(".") - 0));
                string frac_val = retVal.substr((retVal.find(".") + 1), retVal.size() - 1);
                retVal.empty();
                retVal = base_val + ".(" + frac_val +")";
                break;
            }
            fraction.insert(floor);   
        }
        
        retVal += to_string(floor);

        if(remainder == 0)
        {
            break;
        }
        numerator = remainder;
    }
    
    return retVal;
}