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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mateusz/Desktop/C++/sfml-calc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mateusz/Desktop/C++/sfml-calc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sfml_calc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sfml_calc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfml_calc.dir/flags.make

CMakeFiles/sfml_calc.dir/main.cpp.o: CMakeFiles/sfml_calc.dir/flags.make
CMakeFiles/sfml_calc.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mateusz/Desktop/C++/sfml-calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfml_calc.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sfml_calc.dir/main.cpp.o -c /Users/mateusz/Desktop/C++/sfml-calc/main.cpp

CMakeFiles/sfml_calc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml_calc.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mateusz/Desktop/C++/sfml-calc/main.cpp > CMakeFiles/sfml_calc.dir/main.cpp.i

CMakeFiles/sfml_calc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml_calc.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mateusz/Desktop/C++/sfml-calc/main.cpp -o CMakeFiles/sfml_calc.dir/main.cpp.s

# Object files for target sfml_calc
sfml_calc_OBJECTS = \
"CMakeFiles/sfml_calc.dir/main.cpp.o"

# External object files for target sfml_calc
sfml_calc_EXTERNAL_OBJECTS =

sfml_calc: CMakeFiles/sfml_calc.dir/main.cpp.o
sfml_calc: CMakeFiles/sfml_calc.dir/build.make
sfml_calc: /usr/local/lib/libsfml-graphics.2.5.1.dylib
sfml_calc: /usr/local/lib/libsfml-window.2.5.1.dylib
sfml_calc: /usr/local/lib/libsfml-system.2.5.1.dylib
sfml_calc: CMakeFiles/sfml_calc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mateusz/Desktop/C++/sfml-calc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sfml_calc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml_calc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfml_calc.dir/build: sfml_calc

.PHONY : CMakeFiles/sfml_calc.dir/build

CMakeFiles/sfml_calc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfml_calc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfml_calc.dir/clean

CMakeFiles/sfml_calc.dir/depend:
	cd /Users/mateusz/Desktop/C++/sfml-calc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mateusz/Desktop/C++/sfml-calc /Users/mateusz/Desktop/C++/sfml-calc /Users/mateusz/Desktop/C++/sfml-calc/cmake-build-debug /Users/mateusz/Desktop/C++/sfml-calc/cmake-build-debug /Users/mateusz/Desktop/C++/sfml-calc/cmake-build-debug/CMakeFiles/sfml_calc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfml_calc.dir/depend

