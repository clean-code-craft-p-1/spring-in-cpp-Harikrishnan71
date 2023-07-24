#include "stats.h"
#include<cmath>
#include<bits/stdc++.h>
#include<vector>
Stats Statistics::ComputeStatistics(const std::vector<double>& value) 
{
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


void EmailAlert::sendAlert()
{
    emailSent = true;
}

void LEDAlert::sendAlert()
{
    ledGlows = true;
}

StatsAlerter::StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters)
{
    this->maxThreshold = maxThreshold;

    for(unsigned int i = 0; i < alerters.size(); i++)
    {
        this->alerters.push_back(alerters[i]);
    }
    
} 

void StatsAlerter::checkAndAlert(const std::vector<double>& val)
{
    auto computeMax = Statistics::ComputeStatistics(val);
    if(computeMax.max > maxThreshold)
    {
        for(unsigned int i = 0; i < alerters.size(); i++)
        {
            //send sendAlert for all the alerters classes
            alerters[i]->sendAlert();
        }
    }
}
        

