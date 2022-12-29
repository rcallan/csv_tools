#include <gtest/gtest.h>
#include "CsvFile.h"
#include "CsvOperations.h"

// todo - continue to add test for various operations

TEST(ArithTest, AddColumns)
{
    CsvFile::Ptr i1(new CsvFile(5,5));

    int count = 0;
    for (unsigned i = 0; i < i1->get_num_rows(); ++i) {
        for (unsigned j = 0; j < i1->get_num_columns(); ++j) {
            i1->values(i,j) = std::to_string(count++);
        }
    }

    auto op = std::plus<double>();

    std::vector<std::string> cols = {"1", "2"};

    CsvFile::PtrC o1 = csv_operations::perform_column_op(i1, op, cols);

    std::vector<std::string> expected = {"3.00", "13.00", "23.00", "33.00", "43.00"};

    for (unsigned i = 0; i < o1->get_num_rows(); ++i) {
        EXPECT_EQ(o1->values(i, 5), expected[i]);
    }
    
}