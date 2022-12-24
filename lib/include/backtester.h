//
//  backtester.h
//

#ifndef ____backtester__
#define ____backtester__

#include "CsvFile.h"
#include "conditions.h"

using namespace std;

namespace backtester {
    unsigned number_of_events(csv_file::Ptr historical_data, conditions conds);
}

#endif /* defined(____backtester__) */