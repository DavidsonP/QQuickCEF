# QQuickCEF

This is a project intended to support the CEF project inside of QT QML Components.
The target of the current project is to make an easy, seemless integration between QT and CEF while allowing the dynamic loading of
different CEF versions for future changes.

## Setup

1. Create build of CEF for windows like in the [CEF DOCS](https://chromiumembedded.github.io/cef/tutorial#windows-build-steps) (Make sure to make it dynamic compile runtime (/MD))
    * You can use [CEF](https://drive.google.com/file/d/1QK6pRAGeS7i27iVSUpdXzJ6Xmlbha9Wy/view?usp=sharing) that I already compiled with everything
2. Add Include Folder inside CEF to find refernces ($PWD/CEF/include)
    * The link I provided for the [CEF](https://drive.google.com/file/d/1QK6pRAGeS7i27iVSUpdXzJ6Xmlbha9Wy/view?usp=sharing) already has it
3. Define QT 5.15.2 Kit with MSVC 2019
4. Build the project
5. Put the CEF Binary in the output directory
6. Run 