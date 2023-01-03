
#### Purpose of project

The tools included in this repository allow you to manipulate, display, modify, and retrieve basic stats about your data. We 
would like to add other tools that could be relevant for securities trading such as a back tester and possibly execution 
and risk tools

#### Building the project

When cloning this repo, please use the following commands

```
git clone --recurse-submodules https://github.com/rcallan/csv_tools
./vcpkg/bootstrap-vcpkg.sh
```

To build and install this on linux, please navigate to the top level directory for this repo and execute the following commands

```
mkdir build && cd build
cmake .. -B .
sudo cmake --build . --target install
```

You can then navigate to `bin/`, which is located in the top level directory of this project to use the executables

#### Usage and examples

There is more information [here](usage.md) on how to use the tools, as well as some examples


