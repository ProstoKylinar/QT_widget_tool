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
CMAKE_SOURCE_DIR = /home/vboxuser/Desktop/Home-21/home21

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vboxuser/Desktop/Home-21/home21

# Include any dependencies generated for this target.
include CMakeFiles/home21.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/home21.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/home21.dir/flags.make

CMakeFiles/home21.dir/main.cpp.o: CMakeFiles/home21.dir/flags.make
CMakeFiles/home21.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/Desktop/Home-21/home21/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/home21.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/home21.dir/main.cpp.o -c /home/vboxuser/Desktop/Home-21/home21/main.cpp

CMakeFiles/home21.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/home21.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vboxuser/Desktop/Home-21/home21/main.cpp > CMakeFiles/home21.dir/main.cpp.i

CMakeFiles/home21.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/home21.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vboxuser/Desktop/Home-21/home21/main.cpp -o CMakeFiles/home21.dir/main.cpp.s

# Object files for target home21
home21_OBJECTS = \
"CMakeFiles/home21.dir/main.cpp.o"

# External object files for target home21
home21_EXTERNAL_OBJECTS =

home21: CMakeFiles/home21.dir/main.cpp.o
home21: CMakeFiles/home21.dir/build.make
home21: CMakeFiles/home21.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vboxuser/Desktop/Home-21/home21/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable home21"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/home21.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/home21.dir/build: home21

.PHONY : CMakeFiles/home21.dir/build

CMakeFiles/home21.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/home21.dir/cmake_clean.cmake
.PHONY : CMakeFiles/home21.dir/clean

CMakeFiles/home21.dir/depend:
	cd /home/vboxuser/Desktop/Home-21/home21 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vboxuser/Desktop/Home-21/home21 /home/vboxuser/Desktop/Home-21/home21 /home/vboxuser/Desktop/Home-21/home21 /home/vboxuser/Desktop/Home-21/home21 /home/vboxuser/Desktop/Home-21/home21/CMakeFiles/home21.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/home21.dir/depend

