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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/twittumz/Desktop/git/PETest/PETest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/twittumz/Desktop/git/PETest/PETest/build

# Include any dependencies generated for this target.
include CMakeFiles/PETest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PETest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PETest.dir/flags.make

CMakeFiles/PETest.dir/main.cpp.o: CMakeFiles/PETest.dir/flags.make
CMakeFiles/PETest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/twittumz/Desktop/git/PETest/PETest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PETest.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PETest.dir/main.cpp.o -c /home/twittumz/Desktop/git/PETest/PETest/main.cpp

CMakeFiles/PETest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PETest.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/twittumz/Desktop/git/PETest/PETest/main.cpp > CMakeFiles/PETest.dir/main.cpp.i

CMakeFiles/PETest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PETest.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/twittumz/Desktop/git/PETest/PETest/main.cpp -o CMakeFiles/PETest.dir/main.cpp.s

CMakeFiles/PETest.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PETest.dir/main.cpp.o.requires

CMakeFiles/PETest.dir/main.cpp.o.provides: CMakeFiles/PETest.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PETest.dir/build.make CMakeFiles/PETest.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PETest.dir/main.cpp.o.provides

CMakeFiles/PETest.dir/main.cpp.o.provides.build: CMakeFiles/PETest.dir/main.cpp.o


CMakeFiles/PETest.dir/camera.cpp.o: CMakeFiles/PETest.dir/flags.make
CMakeFiles/PETest.dir/camera.cpp.o: ../camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/twittumz/Desktop/git/PETest/PETest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PETest.dir/camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PETest.dir/camera.cpp.o -c /home/twittumz/Desktop/git/PETest/PETest/camera.cpp

CMakeFiles/PETest.dir/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PETest.dir/camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/twittumz/Desktop/git/PETest/PETest/camera.cpp > CMakeFiles/PETest.dir/camera.cpp.i

CMakeFiles/PETest.dir/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PETest.dir/camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/twittumz/Desktop/git/PETest/PETest/camera.cpp -o CMakeFiles/PETest.dir/camera.cpp.s

CMakeFiles/PETest.dir/camera.cpp.o.requires:

.PHONY : CMakeFiles/PETest.dir/camera.cpp.o.requires

CMakeFiles/PETest.dir/camera.cpp.o.provides: CMakeFiles/PETest.dir/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/PETest.dir/build.make CMakeFiles/PETest.dir/camera.cpp.o.provides.build
.PHONY : CMakeFiles/PETest.dir/camera.cpp.o.provides

CMakeFiles/PETest.dir/camera.cpp.o.provides.build: CMakeFiles/PETest.dir/camera.cpp.o


# Object files for target PETest
PETest_OBJECTS = \
"CMakeFiles/PETest.dir/main.cpp.o" \
"CMakeFiles/PETest.dir/camera.cpp.o"

# External object files for target PETest
PETest_EXTERNAL_OBJECTS =

PETest: CMakeFiles/PETest.dir/main.cpp.o
PETest: CMakeFiles/PETest.dir/camera.cpp.o
PETest: CMakeFiles/PETest.dir/build.make
PETest: /usr/lib64/libSOIL.so
PETest: /usr/lib64/libGLU.so
PETest: /usr/lib64/libGL.so
PETest: /usr/lib64/libfreetype.so
PETest: CMakeFiles/PETest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/twittumz/Desktop/git/PETest/PETest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PETest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PETest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PETest.dir/build: PETest

.PHONY : CMakeFiles/PETest.dir/build

CMakeFiles/PETest.dir/requires: CMakeFiles/PETest.dir/main.cpp.o.requires
CMakeFiles/PETest.dir/requires: CMakeFiles/PETest.dir/camera.cpp.o.requires

.PHONY : CMakeFiles/PETest.dir/requires

CMakeFiles/PETest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PETest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PETest.dir/clean

CMakeFiles/PETest.dir/depend:
	cd /home/twittumz/Desktop/git/PETest/PETest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/twittumz/Desktop/git/PETest/PETest /home/twittumz/Desktop/git/PETest/PETest /home/twittumz/Desktop/git/PETest/PETest/build /home/twittumz/Desktop/git/PETest/PETest/build /home/twittumz/Desktop/git/PETest/PETest/build/CMakeFiles/PETest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PETest.dir/depend

