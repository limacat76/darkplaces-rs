### What is this?

The idea behind this project is to shrink and refactor LordHavoc's
Darkplaces codebase[1] (forked from the Xonotic's Gitlab[2]) in order
to be able to convert it into Rust[3].

The first phase is about removing all the build files from non windows
/  non linux / non SDL, because I want to be able to work on a minimal
set of files and without distractions. Also, for speed reasons, I will
only work in Visual Studio 2017 and with the SDL code.

If you want to play or modify xonotic or darkplaces this is not the
best repository :). If you want to play with compatibility of other
Quake implementations, well, I will try to see if I am able to do it
;). The plan is to have an 1:1 representation with data which is read
or sent via the network, but there might be speed bumps. 

For eventual engine Darkplaces/Xonotic updates and corrections you'd
better look at the Xonotic download and git pages, since this is an
hard fork based on a code freeze. :)

The rust code will be on a different repository and linked as a dll.
(Honestly this plan has yet to be defined).

[1] https://icculus.org/twilight/darkplaces/

[2] https://gitlab.com/xonotic/darkplaces

[3] https://www.rust-lang.org/

[4] https://www.xonotic.org/

### Strangulation Plan

#### General: Prepare the DP Engine

I need to split the DP Engine between the core game and a library.
Quake didn't need this complexity until now, but for good reasons
(unit testing and the eventual phase out of C code) I need to
start thinking in DLLs.

There will also be some major refactoring or moving around of macros,
headers and functions.

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

* Remove the inline call to C (with a specific #ifdef)
* Call the function on the C dll
* Call the function on the Rust dll
* Build Darkplaces
* Run Darkplaces

#### What about code that cannot be translated in Rust? (Platform Dependant Code)

* It will be wrapped in .dll or .so files

### Phases

This plan will change, but this is the initial lowdown.

* Basic "leaf" Code
* Core Logic
* Code Needing I/O
* 0.9 Release
* Remove unsafe pointers
* 1.0 Release
* Multithreaded logic for the game engine (?)
* 2.0 Release
* Add a Vulkan Renderer
* 3.0 Release

### Non conversion Wishlist

Add WASD to the menu keys, like a modern game. :)