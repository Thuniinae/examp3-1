# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/ee6470/exam1/exam1-p3-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/ee6470/exam1/exam1-p3-1/build

# Include any dependencies generated for this target.
include CMakeFiles/module.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/module.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/module.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/module.dir/flags.make

CMakeFiles/module.dir/main.cpp.o: CMakeFiles/module.dir/flags.make
CMakeFiles/module.dir/main.cpp.o: ../main.cpp
CMakeFiles/module.dir/main.cpp.o: CMakeFiles/module.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/ee6470/exam1/exam1-p3-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/module.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/module.dir/main.cpp.o -MF CMakeFiles/module.dir/main.cpp.o.d -o CMakeFiles/module.dir/main.cpp.o -c /home/user/ee6470/exam1/exam1-p3-1/main.cpp

CMakeFiles/module.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/module.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/ee6470/exam1/exam1-p3-1/main.cpp > CMakeFiles/module.dir/main.cpp.i

CMakeFiles/module.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/module.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/ee6470/exam1/exam1-p3-1/main.cpp -o CMakeFiles/module.dir/main.cpp.s

# Object files for target module
module_OBJECTS = \
"CMakeFiles/module.dir/main.cpp.o"

# External object files for target module
module_EXTERNAL_OBJECTS =

module: CMakeFiles/module.dir/main.cpp.o
module: CMakeFiles/module.dir/build.make
module: /opt/systemc/lib/libsystemc.so.2.3.3
module: CMakeFiles/module.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/ee6470/exam1/exam1-p3-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable module"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/module.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/module.dir/build: module
.PHONY : CMakeFiles/module.dir/build

CMakeFiles/module.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/module.dir/cmake_clean.cmake
.PHONY : CMakeFiles/module.dir/clean

CMakeFiles/module.dir/depend:
	cd /home/user/ee6470/exam1/exam1-p3-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/ee6470/exam1/exam1-p3-1 /home/user/ee6470/exam1/exam1-p3-1 /home/user/ee6470/exam1/exam1-p3-1/build /home/user/ee6470/exam1/exam1-p3-1/build /home/user/ee6470/exam1/exam1-p3-1/build/CMakeFiles/module.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/module.dir/depend
