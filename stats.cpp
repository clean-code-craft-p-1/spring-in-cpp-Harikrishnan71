#include "stats.h"
#include<cmath>
#include<bits/stdc++.h>
#include<vector>
template <class T> Statistics::Stats<>::Stats(){}
template <class T> Statistics::Stats<T,T,T>::Stats(T average,T max,T min):average(average),max(max),min(min){}
template <class T> Stats Statistics::ComputeStatistics(const std::vector<T>& value) 
{
    //Implement statistics here
    Stats<T> x;
    if (value.size()==0)
    {
        x.average =NAN;
        x.max =NAN;
        x.min =NAN;
    }
    else
    {
        x.max = *max_element(value.begin(),value.end());
        x.min = *max_element(value.begin(),value.end());
        x.average = (accumulate(value.begin(),value.end(),0))/value.size();
    
    }
    return x;
}
        
        

