### zone.h + zone.c

Use: Memory allocation and management
Group: Platform
Difficulty: 3
Layer: 1

* has platform dependent code? yes

* depends on:
** sys.h
** cmd.h
** render.h
** console.h
** thread.h

* is included from:
** filematch.c
** fs.c
** hmac.c
** lhnet.c
** thread_sdl.c

#### C Cleanup

* remove mem_bigendian and move it to the sound subsystem (S_INIT)
* remove MEMCLUMPING
* remove File Backed Malloc

#### Conversion to Rust

https://stackoverflow.com/questions/50188710/rust-function-that-allocates-memory-and-calls-a-c-callback-crashes
https://doc.rust-lang.org/std/boxed/struct.Box.html#method.into_raw
At 0.9 We will need to remove into_raw and from_raw

