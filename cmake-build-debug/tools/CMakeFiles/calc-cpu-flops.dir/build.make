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
include tools/CMakeFiles/calc-cpu-flops.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/calc-cpu-flops.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/calc-cpu-flops.dir/flags.make

tools/CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.o: tools/CMakeFiles/calc-cpu-flops.dir/flags.make
tools/CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.o: ../tools/calc-cpu-flops.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tools/CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.o"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.o -c /Users/wanglei/Desktop/gemm-optimizer/tools/calc-cpu-flops.c

tools/CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.i"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wanglei/Desktop/gemm-optimizer/tools/calc-cpu-flops.c > CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.i

tools/CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.s"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wanglei/Desktop/gemm-optimizer/tools/calc-cpu-flops.c -o CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.s

tools/CMakeFiles/calc-cpu-flops.dir/smtl.c.o: tools/CMakeFiles/calc-cpu-flops.dir/flags.make
tools/CMakeFiles/calc-cpu-flops.dir/smtl.c.o: ../tools/smtl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tools/CMakeFiles/calc-cpu-flops.dir/smtl.c.o"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/calc-cpu-flops.dir/smtl.c.o -c /Users/wanglei/Desktop/gemm-optimizer/tools/smtl.c

tools/CMakeFiles/calc-cpu-flops.dir/smtl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/calc-cpu-flops.dir/smtl.c.i"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wanglei/Desktop/gemm-optimizer/tools/smtl.c > CMakeFiles/calc-cpu-flops.dir/smtl.c.i

tools/CMakeFiles/calc-cpu-flops.dir/smtl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/calc-cpu-flops.dir/smtl.c.s"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wanglei/Desktop/gemm-optimizer/tools/smtl.c -o CMakeFiles/calc-cpu-flops.dir/smtl.c.s

# Object files for target calc-cpu-flops
calc__cpu__flops_OBJECTS = \
"CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.o" \
"CMakeFiles/calc-cpu-flops.dir/smtl.c.o"

# External object files for target calc-cpu-flops
calc__cpu__flops_EXTERNAL_OBJECTS =

tools/calc-cpu-flops: tools/CMakeFiles/calc-cpu-flops.dir/calc-cpu-flops.c.o
tools/calc-cpu-flops: tools/CMakeFiles/calc-cpu-flops.dir/smtl.c.o
tools/calc-cpu-flops: tools/CMakeFiles/calc-cpu-flops.dir/build.make
tools/calc-cpu-flops: ../lib/libfpkernel.a
tools/calc-cpu-flops: tools/CMakeFiles/calc-cpu-flops.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable calc-cpu-flops"
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calc-cpu-flops.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/calc-cpu-flops.dir/build: tools/calc-cpu-flops

.PHONY : tools/CMakeFiles/calc-cpu-flops.dir/build

tools/CMakeFiles/calc-cpu-flops.dir/clean:
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools && $(CMAKE_COMMAND) -P CMakeFiles/calc-cpu-flops.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/calc-cpu-flops.dir/clean

tools/CMakeFiles/calc-cpu-flops.dir/depend:
	cd /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wanglei/Desktop/gemm-optimizer /Users/wanglei/Desktop/gemm-optimizer/tools /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools /Users/wanglei/Desktop/gemm-optimizer/cmake-build-debug/tools/CMakeFiles/calc-cpu-flops.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/calc-cpu-flops.dir/depend

