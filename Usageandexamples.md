## Usage and examples

The `csvcolumnselector` tool can be used to select particular columns for
output. The following input options should be provided to use this tool.

```
--path
--output_path
--columns
```

Example:

```
./csvcolumnselector --path "values.csv" --output_path "newvalues.csv" --columns 3,4
```

The `csvjointool` utility can be used to perform inner and outer joins on two data
sets. The following input options should be provided to use this tool.

```
--path
--path2
--output_path
--columns_to_join_on
--operation, available arguments are outer_join and inner_join
```

Note: This tool assumes the columns of each data set are in the same order.

Example:

```
./csvjointool --path "join_values1.csv" --path2 "join_values2.csv" --output_path "newvalues2.csv" --columns_to_join_on 2,1 --operation outer_join
```

The `csvstatistics` tool can be used to show simple statistics (minimum, maximum, median, and
average) of whichever columns are selected. The following input options should be provided
to use this tool.

```
--path
--columns
```

Example:

```
./csvstatistics --path "values.csv" --columns 2,3
```

The `csvarith` tool can be used to perform addition, subtraction, multiplication,
and division on two columns. The result of whichever operation you
choose will be saved as an additional column in the output. The following input
options should be provided to use this tool.

```
--path
--output_path
--columns
--operator
```

Example:

```
./csvarith --path "values.csv" --output_path "newvalues.csv" --columns 2,3 --operator addition
```

Finally, the `showcsv` tool can be used to print csv file values to the command line. The only input
options that should be provided to use this tool is the path, by using the `--path` option.

You can also use the `--help` option if you are unsure how to use any of the tools.


