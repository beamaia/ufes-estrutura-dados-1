# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/125/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/125/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bea/ufes/earte-2020-1/ed1/aula01/2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bea/ufes/earte-2020-1/ed1/aula01/2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2.dir/flags.make

CMakeFiles/2.dir/aula1_2.c.o: CMakeFiles/2.dir/flags.make
CMakeFiles/2.dir/aula1_2.c.o: ../aula1_2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bea/ufes/earte-2020-1/ed1/aula01/2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/2.dir/aula1_2.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/2.dir/aula1_2.c.o   -c /home/bea/ufes/earte-2020-1/ed1/aula01/2/aula1_2.c

CMakeFiles/2.dir/aula1_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/2.dir/aula1_2.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bea/ufes/earte-2020-1/ed1/aula01/2/aula1_2.c > CMakeFiles/2.dir/aula1_2.c.i

CMakeFiles/2.dir/aula1_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/2.dir/aula1_2.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bea/ufes/earte-2020-1/ed1/aula01/2/aula1_2.c -o CMakeFiles/2.dir/aula1_2.c.s

# Object files for target 2
2_OBJECTS = \
"CMakeFiles/2.dir/aula1_2.c.o"

# External object files for target 2
2_EXTERNAL_OBJECTS =

2 : CMakeFiles/2.dir/aula1_2.c.o
2 : CMakeFiles/2.dir/build.make
2 : CMakeFiles/2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bea/ufes/earte-2020-1/ed1/aula01/2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2.dir/build: 2

.PHONY : CMakeFiles/2.dir/build

CMakeFiles/2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2.dir/clean

CMakeFiles/2.dir/depend:
	cd /home/bea/ufes/earte-2020-1/ed1/aula01/2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bea/ufes/earte-2020-1/ed1/aula01/2 /home/bea/ufes/earte-2020-1/ed1/aula01/2 /home/bea/ufes/earte-2020-1/ed1/aula01/2/cmake-build-debug /home/bea/ufes/earte-2020-1/ed1/aula01/2/cmake-build-debug /home/bea/ufes/earte-2020-1/ed1/aula01/2/cmake-build-debug/CMakeFiles/2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2.dir/depend

