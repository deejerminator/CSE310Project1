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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment1.dir/flags.make

CMakeFiles/Assignment1.dir/main.cpp.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw/cmake-build-debug/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Assignment1.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Assignment1.dir/main.cpp.o -c /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw/main.cpp

CMakeFiles/Assignment1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw/main.cpp > CMakeFiles/Assignment1.dir/main.cpp.i

CMakeFiles/Assignment1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw/main.cpp -o CMakeFiles/Assignment1.dir/main.cpp.s

CMakeFiles/Assignment1.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/Assignment1.dir/main.cpp.o.requires

CMakeFiles/Assignment1.dir/main.cpp.o.provides: CMakeFiles/Assignment1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Assignment1.dir/build.make CMakeFiles/Assignment1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Assignment1.dir/main.cpp.o.provides

CMakeFiles/Assignment1.dir/main.cpp.o.provides.build: CMakeFiles/Assignment1.dir/main.cpp.o

# Object files for target Assignment1
Assignment1_OBJECTS = \
"CMakeFiles/Assignment1.dir/main.cpp.o"

# External object files for target Assignment1
Assignment1_EXTERNAL_OBJECTS =

Assignment1: CMakeFiles/Assignment1.dir/main.cpp.o
Assignment1: CMakeFiles/Assignment1.dir/build.make
Assignment1: CMakeFiles/Assignment1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Assignment1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment1.dir/build: Assignment1
.PHONY : CMakeFiles/Assignment1.dir/build

CMakeFiles/Assignment1.dir/requires: CMakeFiles/Assignment1.dir/main.cpp.o.requires
.PHONY : CMakeFiles/Assignment1.dir/requires

CMakeFiles/Assignment1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment1.dir/clean

CMakeFiles/Assignment1.dir/depend:
	cd /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw/cmake-build-debug /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw/cmake-build-debug /afs/asu.edu/users/j/j/n/jjnavar3/tmp/tmp.avTMbUxQaw/cmake-build-debug/CMakeFiles/Assignment1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment1.dir/depend

