# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree/build

# Include any dependencies generated for this target.
include CMakeFiles/linearizationSanityCheck.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linearizationSanityCheck.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linearizationSanityCheck.dir/flags.make

CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o: CMakeFiles/linearizationSanityCheck.dir/flags.make
CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o: ../linearizationSanityCheck.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o -c /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree/linearizationSanityCheck.cpp

CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree/linearizationSanityCheck.cpp > CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.i

CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree/linearizationSanityCheck.cpp -o CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.s

CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o.requires:
.PHONY : CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o.requires

CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o.provides: CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o.requires
	$(MAKE) -f CMakeFiles/linearizationSanityCheck.dir/build.make CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o.provides.build
.PHONY : CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o.provides

CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o.provides.build: CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o

# Object files for target linearizationSanityCheck
linearizationSanityCheck_OBJECTS = \
"CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o"

# External object files for target linearizationSanityCheck
linearizationSanityCheck_EXTERNAL_OBJECTS =

linearizationSanityCheck: CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o
linearizationSanityCheck: CMakeFiles/linearizationSanityCheck.dir/build.make
linearizationSanityCheck: liblinearizationLib.a
linearizationSanityCheck: CMakeFiles/linearizationSanityCheck.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable linearizationSanityCheck"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linearizationSanityCheck.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linearizationSanityCheck.dir/build: linearizationSanityCheck
.PHONY : CMakeFiles/linearizationSanityCheck.dir/build

CMakeFiles/linearizationSanityCheck.dir/requires: CMakeFiles/linearizationSanityCheck.dir/linearizationSanityCheck.cpp.o.requires
.PHONY : CMakeFiles/linearizationSanityCheck.dir/requires

CMakeFiles/linearizationSanityCheck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linearizationSanityCheck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linearizationSanityCheck.dir/clean

CMakeFiles/linearizationSanityCheck.dir/depend:
	cd /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree/build /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree/build /home/ubuntu/workspace/Ecs122BPrev/final-project/Ukkonen-SuffixTree/build/CMakeFiles/linearizationSanityCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linearizationSanityCheck.dir/depend

