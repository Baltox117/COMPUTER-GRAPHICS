# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\COMPUTER-GRAPHICS\Pract-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Pract_2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Pract_2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Pract_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pract_2.dir/flags.make

CMakeFiles/Pract_2.dir/src/main.c.obj: CMakeFiles/Pract_2.dir/flags.make
CMakeFiles/Pract_2.dir/src/main.c.obj: CMakeFiles/Pract_2.dir/includes_C.rsp
CMakeFiles/Pract_2.dir/src/main.c.obj: C:/COMPUTER-GRAPHICS/Pract-2/src/main.c
CMakeFiles/Pract_2.dir/src/main.c.obj: CMakeFiles/Pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Pract_2.dir/src/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pract_2.dir/src/main.c.obj -MF CMakeFiles\Pract_2.dir\src\main.c.obj.d -o CMakeFiles\Pract_2.dir\src\main.c.obj -c C:\COMPUTER-GRAPHICS\Pract-2\src\main.c

CMakeFiles/Pract_2.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pract_2.dir/src/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\COMPUTER-GRAPHICS\Pract-2\src\main.c > CMakeFiles\Pract_2.dir\src\main.c.i

CMakeFiles/Pract_2.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pract_2.dir/src/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\COMPUTER-GRAPHICS\Pract-2\src\main.c -o CMakeFiles\Pract_2.dir\src\main.c.s

CMakeFiles/Pract_2.dir/src/triangle.c.obj: CMakeFiles/Pract_2.dir/flags.make
CMakeFiles/Pract_2.dir/src/triangle.c.obj: CMakeFiles/Pract_2.dir/includes_C.rsp
CMakeFiles/Pract_2.dir/src/triangle.c.obj: C:/COMPUTER-GRAPHICS/Pract-2/src/triangle.c
CMakeFiles/Pract_2.dir/src/triangle.c.obj: CMakeFiles/Pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Pract_2.dir/src/triangle.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pract_2.dir/src/triangle.c.obj -MF CMakeFiles\Pract_2.dir\src\triangle.c.obj.d -o CMakeFiles\Pract_2.dir\src\triangle.c.obj -c C:\COMPUTER-GRAPHICS\Pract-2\src\triangle.c

CMakeFiles/Pract_2.dir/src/triangle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pract_2.dir/src/triangle.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\COMPUTER-GRAPHICS\Pract-2\src\triangle.c > CMakeFiles\Pract_2.dir\src\triangle.c.i

CMakeFiles/Pract_2.dir/src/triangle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pract_2.dir/src/triangle.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\COMPUTER-GRAPHICS\Pract-2\src\triangle.c -o CMakeFiles\Pract_2.dir\src\triangle.c.s

CMakeFiles/Pract_2.dir/src/vector.c.obj: CMakeFiles/Pract_2.dir/flags.make
CMakeFiles/Pract_2.dir/src/vector.c.obj: CMakeFiles/Pract_2.dir/includes_C.rsp
CMakeFiles/Pract_2.dir/src/vector.c.obj: C:/COMPUTER-GRAPHICS/Pract-2/src/vector.c
CMakeFiles/Pract_2.dir/src/vector.c.obj: CMakeFiles/Pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Pract_2.dir/src/vector.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pract_2.dir/src/vector.c.obj -MF CMakeFiles\Pract_2.dir\src\vector.c.obj.d -o CMakeFiles\Pract_2.dir\src\vector.c.obj -c C:\COMPUTER-GRAPHICS\Pract-2\src\vector.c

CMakeFiles/Pract_2.dir/src/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pract_2.dir/src/vector.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\COMPUTER-GRAPHICS\Pract-2\src\vector.c > CMakeFiles\Pract_2.dir\src\vector.c.i

CMakeFiles/Pract_2.dir/src/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pract_2.dir/src/vector.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\COMPUTER-GRAPHICS\Pract-2\src\vector.c -o CMakeFiles\Pract_2.dir\src\vector.c.s

CMakeFiles/Pract_2.dir/src/mesh.c.obj: CMakeFiles/Pract_2.dir/flags.make
CMakeFiles/Pract_2.dir/src/mesh.c.obj: CMakeFiles/Pract_2.dir/includes_C.rsp
CMakeFiles/Pract_2.dir/src/mesh.c.obj: C:/COMPUTER-GRAPHICS/Pract-2/src/mesh.c
CMakeFiles/Pract_2.dir/src/mesh.c.obj: CMakeFiles/Pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Pract_2.dir/src/mesh.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pract_2.dir/src/mesh.c.obj -MF CMakeFiles\Pract_2.dir\src\mesh.c.obj.d -o CMakeFiles\Pract_2.dir\src\mesh.c.obj -c C:\COMPUTER-GRAPHICS\Pract-2\src\mesh.c

CMakeFiles/Pract_2.dir/src/mesh.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pract_2.dir/src/mesh.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\COMPUTER-GRAPHICS\Pract-2\src\mesh.c > CMakeFiles\Pract_2.dir\src\mesh.c.i

CMakeFiles/Pract_2.dir/src/mesh.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pract_2.dir/src/mesh.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\COMPUTER-GRAPHICS\Pract-2\src\mesh.c -o CMakeFiles\Pract_2.dir\src\mesh.c.s

CMakeFiles/Pract_2.dir/src/display.c.obj: CMakeFiles/Pract_2.dir/flags.make
CMakeFiles/Pract_2.dir/src/display.c.obj: CMakeFiles/Pract_2.dir/includes_C.rsp
CMakeFiles/Pract_2.dir/src/display.c.obj: C:/COMPUTER-GRAPHICS/Pract-2/src/display.c
CMakeFiles/Pract_2.dir/src/display.c.obj: CMakeFiles/Pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Pract_2.dir/src/display.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pract_2.dir/src/display.c.obj -MF CMakeFiles\Pract_2.dir\src\display.c.obj.d -o CMakeFiles\Pract_2.dir\src\display.c.obj -c C:\COMPUTER-GRAPHICS\Pract-2\src\display.c

CMakeFiles/Pract_2.dir/src/display.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pract_2.dir/src/display.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\COMPUTER-GRAPHICS\Pract-2\src\display.c > CMakeFiles\Pract_2.dir\src\display.c.i

CMakeFiles/Pract_2.dir/src/display.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pract_2.dir/src/display.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\COMPUTER-GRAPHICS\Pract-2\src\display.c -o CMakeFiles\Pract_2.dir\src\display.c.s

CMakeFiles/Pract_2.dir/src/array.c.obj: CMakeFiles/Pract_2.dir/flags.make
CMakeFiles/Pract_2.dir/src/array.c.obj: CMakeFiles/Pract_2.dir/includes_C.rsp
CMakeFiles/Pract_2.dir/src/array.c.obj: C:/COMPUTER-GRAPHICS/Pract-2/src/array.c
CMakeFiles/Pract_2.dir/src/array.c.obj: CMakeFiles/Pract_2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Pract_2.dir/src/array.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Pract_2.dir/src/array.c.obj -MF CMakeFiles\Pract_2.dir\src\array.c.obj.d -o CMakeFiles\Pract_2.dir\src\array.c.obj -c C:\COMPUTER-GRAPHICS\Pract-2\src\array.c

CMakeFiles/Pract_2.dir/src/array.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Pract_2.dir/src/array.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\COMPUTER-GRAPHICS\Pract-2\src\array.c > CMakeFiles\Pract_2.dir\src\array.c.i

CMakeFiles/Pract_2.dir/src/array.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Pract_2.dir/src/array.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\COMPUTER-GRAPHICS\Pract-2\src\array.c -o CMakeFiles\Pract_2.dir\src\array.c.s

# Object files for target Pract_2
Pract_2_OBJECTS = \
"CMakeFiles/Pract_2.dir/src/main.c.obj" \
"CMakeFiles/Pract_2.dir/src/triangle.c.obj" \
"CMakeFiles/Pract_2.dir/src/vector.c.obj" \
"CMakeFiles/Pract_2.dir/src/mesh.c.obj" \
"CMakeFiles/Pract_2.dir/src/display.c.obj" \
"CMakeFiles/Pract_2.dir/src/array.c.obj"

# External object files for target Pract_2
Pract_2_EXTERNAL_OBJECTS =

Pract_2.exe: CMakeFiles/Pract_2.dir/src/main.c.obj
Pract_2.exe: CMakeFiles/Pract_2.dir/src/triangle.c.obj
Pract_2.exe: CMakeFiles/Pract_2.dir/src/vector.c.obj
Pract_2.exe: CMakeFiles/Pract_2.dir/src/mesh.c.obj
Pract_2.exe: CMakeFiles/Pract_2.dir/src/display.c.obj
Pract_2.exe: CMakeFiles/Pract_2.dir/src/array.c.obj
Pract_2.exe: CMakeFiles/Pract_2.dir/build.make
Pract_2.exe: C:/COMPUTER-GRAPHICS/SDL2-2.30.7/x86_64-w64-mingw32/lib/libSDL2main.a
Pract_2.exe: C:/COMPUTER-GRAPHICS/SDL2-2.30.7/x86_64-w64-mingw32/lib/libSDL2.dll.a
Pract_2.exe: CMakeFiles/Pract_2.dir/linkLibs.rsp
Pract_2.exe: CMakeFiles/Pract_2.dir/objects1.rsp
Pract_2.exe: CMakeFiles/Pract_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable Pract_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Pract_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pract_2.dir/build: Pract_2.exe
.PHONY : CMakeFiles/Pract_2.dir/build

CMakeFiles/Pract_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Pract_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Pract_2.dir/clean

CMakeFiles/Pract_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\COMPUTER-GRAPHICS\Pract-2 C:\COMPUTER-GRAPHICS\Pract-2 C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug C:\COMPUTER-GRAPHICS\Pract-2\cmake-build-debug\CMakeFiles\Pract_2.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Pract_2.dir/depend

