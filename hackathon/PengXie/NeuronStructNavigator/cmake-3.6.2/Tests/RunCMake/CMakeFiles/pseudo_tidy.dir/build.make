# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Bootstrap.cmk/cmake

# The command to remove a file.
RM = /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Bootstrap.cmk/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2

# Include any dependencies generated for this target.
include Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/depend.make

# Include the progress variables for this target.
include Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/flags.make

Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o: Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/flags.make
Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o: Tests/RunCMake/pseudo_tidy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o"
	cd /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake && /bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o   -c /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake/pseudo_tidy.c

Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.i"
	cd /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake && /bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake/pseudo_tidy.c > CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.i

Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.s"
	cd /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake && /bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake/pseudo_tidy.c -o CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.s

Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o.requires:

.PHONY : Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o.requires

Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o.provides: Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o.requires
	$(MAKE) -f Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/build.make Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o.provides.build
.PHONY : Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o.provides

Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o.provides.build: Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o


# Object files for target pseudo_tidy
pseudo_tidy_OBJECTS = \
"CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o"

# External object files for target pseudo_tidy
pseudo_tidy_EXTERNAL_OBJECTS =

Tests/RunCMake/pseudo_tidy: Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o
Tests/RunCMake/pseudo_tidy: Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/build.make
Tests/RunCMake/pseudo_tidy: Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable pseudo_tidy"
	cd /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pseudo_tidy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/build: Tests/RunCMake/pseudo_tidy

.PHONY : Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/build

Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/requires: Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/pseudo_tidy.c.o.requires

.PHONY : Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/requires

Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/clean:
	cd /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake && $(CMAKE_COMMAND) -P CMakeFiles/pseudo_tidy.dir/cmake_clean.cmake
.PHONY : Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/clean

Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/depend:
	cd /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2 /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2 /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/RunCMake/CMakeFiles/pseudo_tidy.dir/depend

