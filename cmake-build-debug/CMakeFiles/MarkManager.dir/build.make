# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\shao_\CLionProjects\MarkManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\shao_\CLionProjects\MarkManager\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MarkManager.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MarkManager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MarkManager.dir/flags.make

CMakeFiles/MarkManager.dir/main.c.obj: CMakeFiles/MarkManager.dir/flags.make
CMakeFiles/MarkManager.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\shao_\CLionProjects\MarkManager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MarkManager.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\MarkManager.dir\main.c.obj   -c C:\Users\shao_\CLionProjects\MarkManager\main.c

CMakeFiles/MarkManager.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MarkManager.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\shao_\CLionProjects\MarkManager\main.c > CMakeFiles\MarkManager.dir\main.c.i

CMakeFiles/MarkManager.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MarkManager.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\shao_\CLionProjects\MarkManager\main.c -o CMakeFiles\MarkManager.dir\main.c.s

# Object files for target MarkManager
MarkManager_OBJECTS = \
"CMakeFiles/MarkManager.dir/main.c.obj"

# External object files for target MarkManager
MarkManager_EXTERNAL_OBJECTS =

MarkManager.exe: CMakeFiles/MarkManager.dir/main.c.obj
MarkManager.exe: CMakeFiles/MarkManager.dir/build.make
MarkManager.exe: CMakeFiles/MarkManager.dir/linklibs.rsp
MarkManager.exe: CMakeFiles/MarkManager.dir/objects1.rsp
MarkManager.exe: CMakeFiles/MarkManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\shao_\CLionProjects\MarkManager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable MarkManager.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MarkManager.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MarkManager.dir/build: MarkManager.exe

.PHONY : CMakeFiles/MarkManager.dir/build

CMakeFiles/MarkManager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MarkManager.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MarkManager.dir/clean

CMakeFiles/MarkManager.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\shao_\CLionProjects\MarkManager C:\Users\shao_\CLionProjects\MarkManager C:\Users\shao_\CLionProjects\MarkManager\cmake-build-debug C:\Users\shao_\CLionProjects\MarkManager\cmake-build-debug C:\Users\shao_\CLionProjects\MarkManager\cmake-build-debug\CMakeFiles\MarkManager.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MarkManager.dir/depend

