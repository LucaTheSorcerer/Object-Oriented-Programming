# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = "/Users/lulu/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/231.8109.222/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/lulu/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/231.8109.222/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/L1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/L1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/L1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/L1.dir/flags.make

CMakeFiles/L1.dir/main.cpp.o: CMakeFiles/L1.dir/flags.make
CMakeFiles/L1.dir/main.cpp.o: /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/main.cpp
CMakeFiles/L1.dir/main.cpp.o: CMakeFiles/L1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/L1.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/L1.dir/main.cpp.o -MF CMakeFiles/L1.dir/main.cpp.o.d -o CMakeFiles/L1.dir/main.cpp.o -c /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/main.cpp

CMakeFiles/L1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L1.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/main.cpp > CMakeFiles/L1.dir/main.cpp.i

CMakeFiles/L1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L1.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/main.cpp -o CMakeFiles/L1.dir/main.cpp.s

# Object files for target L1
L1_OBJECTS = \
"CMakeFiles/L1.dir/main.cpp.o"

# External object files for target L1
L1_EXTERNAL_OBJECTS =

L1: CMakeFiles/L1.dir/main.cpp.o
L1: CMakeFiles/L1.dir/build.make
L1: CMakeFiles/L1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable L1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/L1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/L1.dir/build: L1
.PHONY : CMakeFiles/L1.dir/build

CMakeFiles/L1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/L1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/L1.dir/clean

CMakeFiles/L1.dir/depend:
	cd /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1 /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1 /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/cmake-build-debug /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/cmake-build-debug /Users/lulu/UBB/Semestrul_II/Object-Oriented-Programming/Laborator/L1/cmake-build-debug/CMakeFiles/L1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/L1.dir/depend

