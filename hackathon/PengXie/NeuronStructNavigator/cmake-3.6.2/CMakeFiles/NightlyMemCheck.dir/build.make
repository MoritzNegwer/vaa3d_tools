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

# Utility rule file for NightlyMemCheck.

# Include the progress variables for this target.
include CMakeFiles/NightlyMemCheck.dir/progress.make

CMakeFiles/NightlyMemCheck:
	/bin/ctest -D NightlyMemCheck

NightlyMemCheck: CMakeFiles/NightlyMemCheck
NightlyMemCheck: CMakeFiles/NightlyMemCheck.dir/build.make

.PHONY : NightlyMemCheck

# Rule to build all files generated by this target.
CMakeFiles/NightlyMemCheck.dir/build: NightlyMemCheck

.PHONY : CMakeFiles/NightlyMemCheck.dir/build

CMakeFiles/NightlyMemCheck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NightlyMemCheck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NightlyMemCheck.dir/clean

CMakeFiles/NightlyMemCheck.dir/depend:
	cd /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2 /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2 /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2 /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2 /local1/vaa3d_test/vaa3d_tools/hackathon/MK/NeuronStructNavigator/cmake-3.6.2/CMakeFiles/NightlyMemCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NightlyMemCheck.dir/depend

