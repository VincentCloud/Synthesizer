# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vincenthuang/JUCEProjects/Synthesizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vincenthuang/JUCEProjects/Synthesizer/build

# Include any dependencies generated for this target.
include CMakeFiles/Synthesizer_VST3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Synthesizer_VST3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Synthesizer_VST3.dir/flags.make

Synthesizer.vst3/Contents/./PkgInfo: /Users/vincenthuang/FRUT/cmake/data/PkgInfo
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Synthesizer.vst3/Contents/./PkgInfo"
	$(CMAKE_COMMAND) -E copy /Users/vincenthuang/FRUT/cmake/data/PkgInfo Synthesizer.vst3/Contents/./PkgInfo

CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.o: CMakeFiles/Synthesizer_VST3.dir/flags.make
CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.o: JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vincenthuang/JUCEProjects/Synthesizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.o -c /Users/vincenthuang/JUCEProjects/Synthesizer/build/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp

CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vincenthuang/JUCEProjects/Synthesizer/build/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp > CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.i

CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vincenthuang/JUCEProjects/Synthesizer/build/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp -o CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.s

# Object files for target Synthesizer_VST3
Synthesizer_VST3_OBJECTS = \
"CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.o"

# External object files for target Synthesizer_VST3
Synthesizer_VST3_EXTERNAL_OBJECTS =

Synthesizer.vst3/Contents/MacOS/Synthesizer: CMakeFiles/Synthesizer_VST3.dir/JuceLibraryCode/include_juce_audio_plugin_client_VST3.cpp.o
Synthesizer.vst3/Contents/MacOS/Synthesizer: CMakeFiles/Synthesizer_VST3.dir/build.make
Synthesizer.vst3/Contents/MacOS/Synthesizer: libSynthesizer.a
Synthesizer.vst3/Contents/MacOS/Synthesizer: CMakeFiles/Synthesizer_VST3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vincenthuang/JUCEProjects/Synthesizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX CFBundle shared module Synthesizer.vst3/Contents/MacOS/Synthesizer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Synthesizer_VST3.dir/link.txt --verbose=$(VERBOSE)
	/usr/local/Cellar/cmake/3.18.3/bin/cmake -DCMAKE_INSTALL_CONFIG_NAME=Debug -DCMAKE_INSTALL_COMPONENT=_install_Synthesizer_VST3_to_VST3_binary_location -P /Users/vincenthuang/JUCEProjects/Synthesizer/build/cmake_install.cmake

# Rule to build all files generated by this target.
CMakeFiles/Synthesizer_VST3.dir/build: Synthesizer.vst3/Contents/MacOS/Synthesizer
CMakeFiles/Synthesizer_VST3.dir/build: Synthesizer.vst3/Contents/./PkgInfo

.PHONY : CMakeFiles/Synthesizer_VST3.dir/build

CMakeFiles/Synthesizer_VST3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Synthesizer_VST3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Synthesizer_VST3.dir/clean

CMakeFiles/Synthesizer_VST3.dir/depend:
	cd /Users/vincenthuang/JUCEProjects/Synthesizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vincenthuang/JUCEProjects/Synthesizer /Users/vincenthuang/JUCEProjects/Synthesizer /Users/vincenthuang/JUCEProjects/Synthesizer/build /Users/vincenthuang/JUCEProjects/Synthesizer/build /Users/vincenthuang/JUCEProjects/Synthesizer/build/CMakeFiles/Synthesizer_VST3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Synthesizer_VST3.dir/depend

