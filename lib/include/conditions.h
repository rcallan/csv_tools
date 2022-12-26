//
//  coniditions.h
//

#ifndef ____coniditions__
#define ____coniditions__

#include <string>



class conditions
{
public:
    conditions() = default;
    conditions(std::string& parameter, std::string& comp_operator, double threshold)
        : m_parameter(parameter), m_comp_operator(comp_operator), m_threshold(threshold) { }
    
private:
    // possible parameters to filter on are date, time, open, high, low, and close

    std::string m_parameter {};
    std::string m_comp_operator {};
    double m_threshold {};
};

#endif /* defined(____coniditions__) */