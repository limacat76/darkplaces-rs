### What is this?

The idea behind this project is to shrink LordHavoc's Darkplaces
codebase[1] (forked from the Xonotic Gitlab[2]) in order to be able to
convert it, function by function, into Rust[3].

The first phase is about removing all the build files from non windows
/  non linux / non SDL, because I want to be able to work on a minimal
set of files and without distractions. Also, for speed reasons, I will
only work in Visual Studio 2017 and with the SDL code.

If you want to play or modify xonotic or darkplaces this is not the
best repository :). For eventual engine updates you'd better look
at their download pages, since this version is based on a code
freeze. :)

The rust code will be on a different repository (To be defined).

[1] https://icculus.org/twilight/darkplaces/

[2] https://gitlab.com/xonotic/darkplaces

[3] https://www.rust-lang.org/

[4] https://www.xonotic.org/

### Strangulation Plan

#### General: Prepare the DP Engine

I need to split the DP Engine between the core game and a library.
Quake didn't need this complexity until now, but for good reasons
(unit testing and the eventual phase out of C code) it needs to
start thinking in DLLs.

#### Function Specific

* Move the function into the DLL
* Build and run

#### Prepare the Rust Function

* Create RS tests for the function (it should give the same result 
in C and RS)
* Create RS Benchmarks for the function (C and RS)
* Write the RS Code
* Make a C helper to invoke rust

#### Integrate the Rust Function

* Remove the call to C (make it so that with an #ifdef it calls rust)
* Build Darkplaces
* Run Darkplaces

### Phases

This plan will probably change, but this is the initial lowdown.

* Basic "leaf" Code
* Core Logic
* Code Needing I/O
* 1.0 Release
* Multithreaded logic for the game engine (?)
* 2.0 Release
* Add a Vulkan Renderer
* 3.0 Release

### Diary

2/7 
* first step is retarget the solution to Windows 10 SDK: success
* second step is to build and play the game: success
* created the public github

3/7
* began writing this readme file
* began removing the #if 0 pieces of code

### Non conversion Wishlist

Add WASD to the menu keys, like a modern game. :)