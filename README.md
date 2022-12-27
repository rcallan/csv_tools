
#### Purpose of project

The tools included in this package allow you to manipulate, display, modify, and retrieve basic
stats about your data. We would like to add other tools that could be relevant for securities trading such as a
back tester and possibly execution and risk tools

#### Building the project

To build this on linux, please open the command line/terminal, navigate to a directory that you would like to build the project in,
and execute the following commands to build the project and create the necessary executable files

```
mkdir build && cd build
cmake .. -B .
make
sudo make install
```

You can then navigate to `bin/`, which is located in the top level directory of this project to use the executables

#### Usage and examples

There is more information [here](usage.md) on how to use the tools, as well as some examples


