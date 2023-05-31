# Hermes
16-bit realmode operating system



# Abilities
- input and output from the user
- basic string and memory libraries
- basic memory allocation
- basic fat12 file system and read capabilites
- hopefully in the future i will write a library to actually write to the floppy drive

# Memory allocation
The memory allocation is really crude and can be used with the function malloc(); defined in memory.h
It is more of an arena allocation method where the arena begins at an address where memory is free and just increments
a pointer to allocate that memory into the arena
- thinking about having the ability to create multiple arenas so you could free up some and keep others occupied
- has a basic free function just resets the allocation pointer does not write over the memory

# Draw backs
- as a 16-bit operating system it does not have paging, linear memory mapping, memory virtualization, task scheduling and task handling
if the program you write crashes the entire operating system crashes
- it really isn't an operating system just a standalone program that has just enough capabilties to run a super simple program
- there is no kernel you handle the memory and if you write over memory that is being used for bios functions or even files loaded into memory it will crash

# Major Functions
- malloc(); defined in memory.h
- getc();
- putc();
- puts(); 

# Where is main
- main is located in boot/stage2

# How to run and Compile
- There should be a make file inside where main is to compile main and its other libraries
- In the src folder there should be another make file that will assemble and format the floppy drive
- To run you need qemu-i386
