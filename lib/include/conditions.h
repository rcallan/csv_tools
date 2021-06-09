//
//  coniditions.h
//

#ifndef ____coniditions__
#define ____coniditions__

#include <string>

using namespace std;

class conditions
{
public:
    conditions();
    conditions(string parameter, string comp_operator, double threshold);
    
    // possible parameters to filter on are date, time, open, high, low, and close
    
    string parameter;
    string comp_operator;
    double threshold;
};

conditions::conditions() : threshold(0.0) { }

conditions::conditions(string parameter_, string comp_operator_, double threshold_) : 
    parameter(parameter_), comp_operator(comp_operator_), threshold(threshold_) { }

#endif /* defined(____coniditions__) */