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
include lib/CMakeFiles/lib.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/lib.dir/flags.make

lib/CMakeFiles/lib.dir/src/csv_file.cpp.o: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/src/csv_file.cpp.o: lib/src/csv_file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/lib.dir/src/csv_file.cpp.o"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/src/csv_file.cpp.o -c /home/recal/dev/github.com/csv_tools/lib/src/csv_file.cpp

lib/CMakeFiles/lib.dir/src/csv_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/src/csv_file.cpp.i"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recal/dev/github.com/csv_tools/lib/src/csv_file.cpp > CMakeFiles/lib.dir/src/csv_file.cpp.i

lib/CMakeFiles/lib.dir/src/csv_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/src/csv_file.cpp.s"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recal/dev/github.com/csv_tools/lib/src/csv_file.cpp -o CMakeFiles/lib.dir/src/csv_file.cpp.s

lib/CMakeFiles/lib.dir/src/csv_operations.cpp.o: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/src/csv_operations.cpp.o: lib/src/csv_operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/lib.dir/src/csv_operations.cpp.o"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/src/csv_operations.cpp.o -c /home/recal/dev/github.com/csv_tools/lib/src/csv_operations.cpp

lib/CMakeFiles/lib.dir/src/csv_operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/src/csv_operations.cpp.i"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recal/dev/github.com/csv_tools/lib/src/csv_operations.cpp > CMakeFiles/lib.dir/src/csv_operations.cpp.i

lib/CMakeFiles/lib.dir/src/csv_operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/src/csv_operations.cpp.s"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recal/dev/github.com/csv_tools/lib/src/csv_operations.cpp -o CMakeFiles/lib.dir/src/csv_operations.cpp.s

lib/CMakeFiles/lib.dir/src/matrix.cpp.o: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/src/matrix.cpp.o: lib/src/matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/CMakeFiles/lib.dir/src/matrix.cpp.o"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/src/matrix.cpp.o -c /home/recal/dev/github.com/csv_tools/lib/src/matrix.cpp

lib/CMakeFiles/lib.dir/src/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/src/matrix.cpp.i"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recal/dev/github.com/csv_tools/lib/src/matrix.cpp > CMakeFiles/lib.dir/src/matrix.cpp.i

lib/CMakeFiles/lib.dir/src/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/src/matrix.cpp.s"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recal/dev/github.com/csv_tools/lib/src/matrix.cpp -o CMakeFiles/lib.dir/src/matrix.cpp.s

lib/CMakeFiles/lib.dir/src/ml.cpp.o: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/src/ml.cpp.o: lib/src/ml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib/CMakeFiles/lib.dir/src/ml.cpp.o"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/src/ml.cpp.o -c /home/recal/dev/github.com/csv_tools/lib/src/ml.cpp

lib/CMakeFiles/lib.dir/src/ml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/src/ml.cpp.i"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recal/dev/github.com/csv_tools/lib/src/ml.cpp > CMakeFiles/lib.dir/src/ml.cpp.i

lib/CMakeFiles/lib.dir/src/ml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/src/ml.cpp.s"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recal/dev/github.com/csv_tools/lib/src/ml.cpp -o CMakeFiles/lib.dir/src/ml.cpp.s

lib/CMakeFiles/lib.dir/src/parameters.cpp.o: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/src/parameters.cpp.o: lib/src/parameters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object lib/CMakeFiles/lib.dir/src/parameters.cpp.o"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/src/parameters.cpp.o -c /home/recal/dev/github.com/csv_tools/lib/src/parameters.cpp

lib/CMakeFiles/lib.dir/src/parameters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/src/parameters.cpp.i"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recal/dev/github.com/csv_tools/lib/src/parameters.cpp > CMakeFiles/lib.dir/src/parameters.cpp.i

lib/CMakeFiles/lib.dir/src/parameters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/src/parameters.cpp.s"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recal/dev/github.com/csv_tools/lib/src/parameters.cpp -o CMakeFiles/lib.dir/src/parameters.cpp.s

lib/CMakeFiles/lib.dir/src/stats.cpp.o: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/src/stats.cpp.o: lib/src/stats.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object lib/CMakeFiles/lib.dir/src/stats.cpp.o"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/src/stats.cpp.o -c /home/recal/dev/github.com/csv_tools/lib/src/stats.cpp

lib/CMakeFiles/lib.dir/src/stats.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/src/stats.cpp.i"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recal/dev/github.com/csv_tools/lib/src/stats.cpp > CMakeFiles/lib.dir/src/stats.cpp.i

lib/CMakeFiles/lib.dir/src/stats.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/src/stats.cpp.s"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recal/dev/github.com/csv_tools/lib/src/stats.cpp -o CMakeFiles/lib.dir/src/stats.cpp.s

lib/CMakeFiles/lib.dir/src/string_operations.cpp.o: lib/CMakeFiles/lib.dir/flags.make
lib/CMakeFiles/lib.dir/src/string_operations.cpp.o: lib/src/string_operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object lib/CMakeFiles/lib.dir/src/string_operations.cpp.o"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lib.dir/src/string_operations.cpp.o -c /home/recal/dev/github.com/csv_tools/lib/src/string_operations.cpp

lib/CMakeFiles/lib.dir/src/string_operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/src/string_operations.cpp.i"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/recal/dev/github.com/csv_tools/lib/src/string_operations.cpp > CMakeFiles/lib.dir/src/string_operations.cpp.i

lib/CMakeFiles/lib.dir/src/string_operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/src/string_operations.cpp.s"
	cd /home/recal/dev/github.com/csv_tools/lib && g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/recal/dev/github.com/csv_tools/lib/src/string_operations.cpp -o CMakeFiles/lib.dir/src/string_operations.cpp.s

# Object files for target lib
lib_OBJECTS = \
"CMakeFiles/lib.dir/src/csv_file.cpp.o" \
"CMakeFiles/lib.dir/src/csv_operations.cpp.o" \
"CMakeFiles/lib.dir/src/matrix.cpp.o" \
"CMakeFiles/lib.dir/src/ml.cpp.o" \
"CMakeFiles/lib.dir/src/parameters.cpp.o" \
"CMakeFiles/lib.dir/src/stats.cpp.o" \
"CMakeFiles/lib.dir/src/string_operations.cpp.o"

# External object files for target lib
lib_EXTERNAL_OBJECTS =

lib/liblib.a: lib/CMakeFiles/lib.dir/src/csv_file.cpp.o
lib/liblib.a: lib/CMakeFiles/lib.dir/src/csv_operations.cpp.o
lib/liblib.a: lib/CMakeFiles/lib.dir/src/matrix.cpp.o
lib/liblib.a: lib/CMakeFiles/lib.dir/src/ml.cpp.o
lib/liblib.a: lib/CMakeFiles/lib.dir/src/parameters.cpp.o
lib/liblib.a: lib/CMakeFiles/lib.dir/src/stats.cpp.o
lib/liblib.a: lib/CMakeFiles/lib.dir/src/string_operations.cpp.o
lib/liblib.a: lib/CMakeFiles/lib.dir/build.make
lib/liblib.a: lib/CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/recal/dev/github.com/csv_tools/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library liblib.a"
	cd /home/recal/dev/github.com/csv_tools/lib && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean_target.cmake
	cd /home/recal/dev/github.com/csv_tools/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/lib.dir/build: lib/liblib.a

.PHONY : lib/CMakeFiles/lib.dir/build

lib/CMakeFiles/lib.dir/clean:
	cd /home/recal/dev/github.com/csv_tools/lib && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/lib.dir/clean

lib/CMakeFiles/lib.dir/depend:
	cd /home/recal/dev/github.com/csv_tools && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/recal/dev/github.com/csv_tools /home/recal/dev/github.com/csv_tools/lib /home/recal/dev/github.com/csv_tools /home/recal/dev/github.com/csv_tools/lib /home/recal/dev/github.com/csv_tools/lib/CMakeFiles/lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/lib.dir/depend

