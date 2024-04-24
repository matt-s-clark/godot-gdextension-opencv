# Godot GDExtension for OpenCV

This project is currently only being worked on for a Windows x64 environment. For any other environment types, you will need to update your SCons parameters as necessary and copy in the relevant libraries.

For a basic example of how to create a GDExtension, see the Godot documentation: https://docs.godotengine.org/en/4.2/tutorials/scripting/gdextension/gdextension_cpp_example.html#

For great videos on GDExtensions with C++, take a look at Mosen Zare's YouTube Tutorials: https://www.youtube.com/playlist?list=PLhixpuPeRv9aDdsZbhTpsXguYRvMgyVQ-

Please be aware that OpenCV may contain patents that require licensing or credit. Please do your own research before using it in a commercial scenario.

If you're not already on the Godot Discord channel I recommend you go and join it.

## Prequisites

You will need to install the following (version numbers are the ones I have working correctly):

- Godot 4.2.2
- OpenCV 4.9.0

## Windows (x64)

You will need to manually copy the OpenCV files into the `src` folder of this project and make sure `SConstruct` references everything correctly. Pay particular attention to the following lines:

    env.Append(CPPPATH=["src/", "src/opencv2/include"])
    env.Append(LIBPATH=['src/opencv2/x64/vc16/lib'])
    env.Append(LIBS=['opencv_world490', 'opencv_world490d'])

Make sure you include the `godot-cpp` git submodule:

    git submodule update --init

If a basic init doesn't work, you may need to do the following in the project root folder:

    git submodule add -b 4.2 https://github.com/godotengine/godot-cpp
    cd godot-cpp
    git submodule update --init

### Compilation and Running

To compile, make sure you are in the project root folder:

    scons platform=windows

To clean your build folder, use the `--clean` argument, i.e.

    scons platform=windows --clean

Run the extension from Godot. It is best to run Godot from the command line to capture any potential error messages that would normally be missed. For example, C++ `cout` only outputs to the command line and not the Godot terminal.

Follow the Godot C++ [GDExtension tutorial](https://docs.godotengine.org/en/4.2/tutorials/scripting/gdextension/gdextension_cpp_example.html#) for details on how to test the `GDExample` component.
