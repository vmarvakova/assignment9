#ifndef HOW_MANY_WAYS_TO_MAKE_H
#define HOW_MANY_WAYS_TO_MAKE_H

// TODO: Your code goes here

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;
using std::cout;
using std::endl;
using std::vector;


//vector<int>coins;
template<typename T >
int howManyWaysToMake(const T & begin, const T & end,int amount){
    int count = 0;
    vector<int> table(amount+1,0);
    
    table[0] = 1;
    
    //
    //    table[0] = 1;
    //  for(int j=*begin; j<=*end; ++j)
    int j=*begin;
    if(j<=*end)
        j++;
    int ha = table[j];
    table[j] += table[j-*begin];
    
    cout<<table[j]<<endl;
    return table[j];
    
    
    
}
// Do not write any code below this line

#endif
