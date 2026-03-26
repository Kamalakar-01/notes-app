#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

vector<int> fillbox(int apples, const vector<int> &capacity)
{
    vector<int> filled(capacity.size(), 0);

    int i;
    int cyclesum = 0;
    for(int cap : capacity)
         cyclesum += cap;

    int fullcycles = apples / cyclesum;
    int remaining = apples % cyclesum;

    //filling the full cycle
    for(i = 0; i < capacity.size(); i++)
    {
        filled[i] += fullcycles * capacity[i];
    }

    //filling the remaining
    for(i = 0; i < capacity.size(); i++)
    {
        if(remaining <= 0)
            break;

        int fill = min(capacity[i], remaining);
        filled[i] += fill;
        remaining -= fill;
    }

    return filled;
}

int main()
{
    int apples;
    cout<<"Enter the n value: ";
    cin>>apples;

    vector<int> capacity = {10, 15, 7, 5};

    vector<int> result = fillbox(apples, capacity);


    for(int i = 0; i < result.size(); i++)
    {
        cout<<"Box "<<i+1<<":"<<result[i]<<endl;
    }

    return 0;
}
