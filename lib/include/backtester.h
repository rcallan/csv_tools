//
//  backtester.h
//

#ifndef ____backtester__
#define ____backtester__

#include "CsvFile.h"
#include "conditions.h"



namespace backtester {
    unsigned number_of_events(CsvFile::Ptr historical_data, conditions conds);
}

#endif /* defined(____backtester__) */