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
CMAKE_SOURCE_DIR = /home/satori/computer_graphic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/satori/computer_graphic/build

# Include any dependencies generated for this target.
include CMakeFiles/Bayes.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Bayes.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Bayes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bayes.dir/flags.make

CMakeFiles/Bayes.dir/main.cpp.o: CMakeFiles/Bayes.dir/flags.make
CMakeFiles/Bayes.dir/main.cpp.o: ../main.cpp
CMakeFiles/Bayes.dir/main.cpp.o: CMakeFiles/Bayes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/satori/computer_graphic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bayes.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Bayes.dir/main.cpp.o -MF CMakeFiles/Bayes.dir/main.cpp.o.d -o CMakeFiles/Bayes.dir/main.cpp.o -c /home/satori/computer_graphic/main.cpp

CMakeFiles/Bayes.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bayes.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/satori/computer_graphic/main.cpp > CMakeFiles/Bayes.dir/main.cpp.i

CMakeFiles/Bayes.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bayes.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/satori/computer_graphic/main.cpp -o CMakeFiles/Bayes.dir/main.cpp.s

CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.o: CMakeFiles/Bayes.dir/flags.make
CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.o: ../Renderer/ShaderProgram.cpp
CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.o: CMakeFiles/Bayes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/satori/computer_graphic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.o -MF CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.o.d -o CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.o -c /home/satori/computer_graphic/Renderer/ShaderProgram.cpp

CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/satori/computer_graphic/Renderer/ShaderProgram.cpp > CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.i

CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/satori/computer_graphic/Renderer/ShaderProgram.cpp -o CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.s

CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.o: CMakeFiles/Bayes.dir/flags.make
CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.o: ../Renderer/Texture2D.cpp
CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.o: CMakeFiles/Bayes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/satori/computer_graphic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.o -MF CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.o.d -o CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.o -c /home/satori/computer_graphic/Renderer/Texture2D.cpp

CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/satori/computer_graphic/Renderer/Texture2D.cpp > CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.i

CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/satori/computer_graphic/Renderer/Texture2D.cpp -o CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.s

CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.o: CMakeFiles/Bayes.dir/flags.make
CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.o: ../Resourses/ResourseManager.cpp
CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.o: CMakeFiles/Bayes.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/satori/computer_graphic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.o -MF CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.o.d -o CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.o -c /home/satori/computer_graphic/Resourses/ResourseManager.cpp

CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/satori/computer_graphic/Resourses/ResourseManager.cpp > CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.i

CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/satori/computer_graphic/Resourses/ResourseManager.cpp -o CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.s

# Object files for target Bayes
Bayes_OBJECTS = \
"CMakeFiles/Bayes.dir/main.cpp.o" \
"CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.o" \
"CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.o" \
"CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.o"

# External object files for target Bayes
Bayes_EXTERNAL_OBJECTS =

bin/Bayes: CMakeFiles/Bayes.dir/main.cpp.o
bin/Bayes: CMakeFiles/Bayes.dir/Renderer/ShaderProgram.cpp.o
bin/Bayes: CMakeFiles/Bayes.dir/Renderer/Texture2D.cpp.o
bin/Bayes: CMakeFiles/Bayes.dir/Resourses/ResourseManager.cpp.o
bin/Bayes: CMakeFiles/Bayes.dir/build.make
bin/Bayes: external/glfw/src/libglfw3.a
bin/Bayes: external/glad/libglad.a
bin/Bayes: /usr/lib/x86_64-linux-gnu/librt.a
bin/Bayes: /usr/lib/x86_64-linux-gnu/libm.so
bin/Bayes: CMakeFiles/Bayes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/satori/computer_graphic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bin/Bayes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bayes.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E copy_directory /home/satori/computer_graphic/res /home/satori/computer_graphic/build/bin/res

# Rule to build all files generated by this target.
CMakeFiles/Bayes.dir/build: bin/Bayes
.PHONY : CMakeFiles/Bayes.dir/build

CMakeFiles/Bayes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bayes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bayes.dir/clean

CMakeFiles/Bayes.dir/depend:
	cd /home/satori/computer_graphic/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/satori/computer_graphic /home/satori/computer_graphic /home/satori/computer_graphic/build /home/satori/computer_graphic/build /home/satori/computer_graphic/build/CMakeFiles/Bayes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bayes.dir/depend

