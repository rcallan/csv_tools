# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/recal/dev/github.com/csv_tools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/recal/dev/github.com/csv_tools

# Include any dependencies generated for this target.
include csvtools/showcsv/CMakeFiles/showcsv.dir/depend.make

# Include the progress variables for this target.
include csvtools/showcsv/CMakeFiles/showcsv.dir/progress.make

# Include the compile flags for this target's objects.
include csvtools/showcsv/CMakeFiles/showcsv.dir/flags.make

csvtools/showcsv/CMakeFiles/showcsv.dir/showcsv.cpp.o: csvtools/showcsv/CMakeFiles/showcsv.dir/flags.make
csvtools/showcsv/CMakeFiles/showcsv.dir/showcsv.cpp.o: csvtools/showcsv/showcsv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object csvtools/showcsv/CMakeFiles/showcsv.dir/showcsv.cpp.o"
	cd /home/recal/dev/github.com/csv_tools/csvtools/showcsv && g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/showcsv.dir/showcsv.cpp.o -c /home/recal/dev/github.com/csv_tools/csvtools/showcsv/showcsv.cpp

csvtools/showcsv/CMakeFiles/showcsv.dir/showcsv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/showcsv.dir/showcsv.cpp.i"
	cd /home/recal/dev/github.com/csv_tools/csvtools/showcsv && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recal/dev/github.com/csv_tools/csvtools/showcsv/showcsv.cpp > CMakeFiles/showcsv.dir/showcsv.cpp.i

csvtools/showcsv/CMakeFiles/showcsv.dir/showcsv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/showcsv.dir/showcsv.cpp.s"
	cd /home/recal/dev/github.com/csv_tools/csvtools/showcsv && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recal/dev/github.com/csv_tools/csvtools/showcsv/showcsv.cpp -o CMakeFiles/showcsv.dir/showcsv.cpp.s

# Object files for target showcsv
showcsv_OBJECTS = \
"CMakeFiles/showcsv.dir/showcsv.cpp.o"

# External object files for target showcsv
showcsv_EXTERNAL_OBJECTS =

csvtools/showcsv/showcsv: csvtools/showcsv/CMakeFiles/showcsv.dir/showcsv.cpp.o
csvtools/showcsv/showcsv: csvtools/showcsv/CMakeFiles/showcsv.dir/build.make
csvtools/showcsv/showcsv: lib/liblib.a
csvtools/showcsv/showcsv: csvtools/showcsv/CMakeFiles/showcsv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable showcsv"
	cd /home/recal/dev/github.com/csv_tools/csvtools/showcsv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/showcsv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
csvtools/showcsv/CMakeFiles/showcsv.dir/build: csvtools/showcsv/showcsv

.PHONY : csvtools/showcsv/CMakeFiles/showcsv.dir/build

csvtools/showcsv/CMakeFiles/showcsv.dir/clean:
	cd /home/recal/dev/github.com/csv_tools/csvtools/showcsv && $(CMAKE_COMMAND) -P CMakeFiles/showcsv.dir/cmake_clean.cmake
.PHONY : csvtools/showcsv/CMakeFiles/showcsv.dir/clean

csvtools/showcsv/CMakeFiles/showcsv.dir/depend:
	cd /home/recal/dev/github.com/csv_tools && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/recal/dev/github.com/csv_tools /home/recal/dev/github.com/csv_tools/csvtools/showcsv /home/recal/dev/github.com/csv_tools /home/recal/dev/github.com/csv_tools/csvtools/showcsv /home/recal/dev/github.com/csv_tools/csvtools/showcsv/CMakeFiles/showcsv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : csvtools/showcsv/CMakeFiles/showcsv.dir/depend
