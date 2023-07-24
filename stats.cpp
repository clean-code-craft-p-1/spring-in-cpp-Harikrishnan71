#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& value) {
    //Implement statistics here
    Stats x;
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
        
        

