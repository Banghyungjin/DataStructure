# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Bangh\CLionProjects\Josephus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Bangh\CLionProjects\Josephus\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Josephus.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Josephus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Josephus.dir/flags.make

CMakeFiles/Josephus.dir/josephus.cpp.obj: CMakeFiles/Josephus.dir/flags.make
CMakeFiles/Josephus.dir/josephus.cpp.obj: ../josephus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Bangh\CLionProjects\Josephus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Josephus.dir/josephus.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Josephus.dir\josephus.cpp.obj -c C:\Users\Bangh\CLionProjects\Josephus\josephus.cpp

CMakeFiles/Josephus.dir/josephus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Josephus.dir/josephus.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Bangh\CLionProjects\Josephus\josephus.cpp > CMakeFiles\Josephus.dir\josephus.cpp.i

CMakeFiles/Josephus.dir/josephus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Josephus.dir/josephus.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Bangh\CLionProjects\Josephus\josephus.cpp -o CMakeFiles\Josephus.dir\josephus.cpp.s

# Object files for target Josephus
Josephus_OBJECTS = \
"CMakeFiles/Josephus.dir/josephus.cpp.obj"

# External object files for target Josephus
Josephus_EXTERNAL_OBJECTS =

Josephus.exe: CMakeFiles/Josephus.dir/josephus.cpp.obj
Josephus.exe: CMakeFiles/Josephus.dir/build.make
Josephus.exe: CMakeFiles/Josephus.dir/linklibs.rsp
Josephus.exe: CMakeFiles/Josephus.dir/objects1.rsp
Josephus.exe: CMakeFiles/Josephus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Bangh\CLionProjects\Josephus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Josephus.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Josephus.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Josephus.dir/build: Josephus.exe

.PHONY : CMakeFiles/Josephus.dir/build

CMakeFiles/Josephus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Josephus.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Josephus.dir/clean

CMakeFiles/Josephus.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Bangh\CLionProjects\Josephus C:\Users\Bangh\CLionProjects\Josephus C:\Users\Bangh\CLionProjects\Josephus\cmake-build-debug C:\Users\Bangh\CLionProjects\Josephus\cmake-build-debug C:\Users\Bangh\CLionProjects\Josephus\cmake-build-debug\CMakeFiles\Josephus.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Josephus.dir/depend

