# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wanglei/Desktop/gemm-optimizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug

# Include any dependencies generated for this target.
include gallery/CMakeFiles/0.baseline.dir/depend.make

# Include the progress variables for this target.
include gallery/CMakeFiles/0.baseline.dir/progress.make

# Include the compile flags for this target's objects.
include gallery/CMakeFiles/0.baseline.dir/flags.make

gallery/CMakeFiles/0.baseline.dir/0.baseline.c.o: gallery/CMakeFiles/0.baseline.dir/flags.make
gallery/CMakeFiles/0.baseline.dir/0.baseline.c.o: ../gallery/0.baseline.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object gallery/CMakeFiles/0.baseline.dir/0.baseline.c.o"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/gallery && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/0.baseline.dir/0.baseline.c.o -c /Users/wanglei/Desktop/gemm-optimizer/gallery/0.baseline.c

gallery/CMakeFiles/0.baseline.dir/0.baseline.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/0.baseline.dir/0.baseline.c.i"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/gallery && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wanglei/Desktop/gemm-optimizer/gallery/0.baseline.c > CMakeFiles/0.baseline.dir/0.baseline.c.i

gallery/CMakeFiles/0.baseline.dir/0.baseline.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/0.baseline.dir/0.baseline.c.s"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/gallery && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wanglei/Desktop/gemm-optimizer/gallery/0.baseline.c -o CMakeFiles/0.baseline.dir/0.baseline.c.s

# Object files for target 0.baseline
0_baseline_OBJECTS = \
"CMakeFiles/0.baseline.dir/0.baseline.c.o"

# External object files for target 0.baseline
0_baseline_EXTERNAL_OBJECTS =

gallery/0.baseline: gallery/CMakeFiles/0.baseline.dir/0.baseline.c.o
gallery/0.baseline: gallery/CMakeFiles/0.baseline.dir/build.make
gallery/0.baseline: ../lib/libgallery_utils.a
gallery/0.baseline: gallery/CMakeFiles/0.baseline.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 0.baseline"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/gallery && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/0.baseline.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gallery/CMakeFiles/0.baseline.dir/build: gallery/0.baseline

.PHONY : gallery/CMakeFiles/0.baseline.dir/build

gallery/CMakeFiles/0.baseline.dir/clean:
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/gallery && $(CMAKE_COMMAND) -P CMakeFiles/0.baseline.dir/cmake_clean.cmake
.PHONY : gallery/CMakeFiles/0.baseline.dir/clean

gallery/CMakeFiles/0.baseline.dir/depend:
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wanglei/Desktop/gemm-optimizer /Users/wanglei/Desktop/gemm-optimizer/gallery /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/gallery /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/gallery/CMakeFiles/0.baseline.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gallery/CMakeFiles/0.baseline.dir/depend

