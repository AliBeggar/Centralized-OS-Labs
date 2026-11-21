# Operating Systems 1 & 2 (SYS1 / SYS2) - Linux C Homelabs

A comprehensive collection of low-level systems programming labs and exercises written in **C** on **Linux**, developed for the **Operating Systems 1 (`SYS1`)** and **Operating Systems 2 (`SYS2`)** coursework at the **École Nationale Supérieure d'Informatique (ESI)**.

## Overview

This repository bridges theoretical centralized operating system concepts with practical UNIX/Linux kernel interfaces and system calls. The labs span two semesters—progressing from process lifecycle management, synchronization, and System V IPC (`SYS1`) to virtual memory management, disk scheduling, and UNIX file systems (`SYS2`).

## Curriculum & Lab Modules

### Part I: Operating Systems 1 (`SYS1`)
*Course Code: `SYS1` | Credits: 5 | Coefficient: 5*

1. **UNIX/Linux Process Management & Scheduling**
   - Process creation, hierarchy trees, and termination (`fork()`, `getpid()`, `getppid()`, `wait()`, `waitpid()`).
   - Program image replacement via the `exec*()` system call family and multi-stage compilation pipelines.
   - Process Control Blocks (PCB), state transitions, and CPU scheduling policies (FCFS, SJF, Round-Robin, Priority, Multilevel Queues).

2. **Mutual Exclusion, Synchronization & System V IPC**
   - Implementing critical sections and synchronization using Dijkstra's Semaphores (`P`/`V` primitives).
   - Classical concurrency problems: **Rendezvous** ($2$, $3$, and $n$ processes), **Readers–Writers** (arbitrary and FIFO access), **Producer–Consumer** (single, bounded, and dynamic buffers), and resource allocation.
   - **UNIX System V IPC**: Shared memory segments (`shmget`, `shmat`, `shmdt`, `shmctl`), semaphore sets (`semget`, `semop`, `semctl`), and shell IPC inspection (`ipcs`, `ipcrm`).
   - High-level synchronization with **Monitors** and **Deadlock** prevention/avoidance/detection.

3. **Program Execution & Link Editing**
   - Static and dynamic linking workflows, ELF object module formats, and shared library creation on Linux.

---

### Part II: Operating Systems 2 (`SYS2`)
*Course Code: `SYS2` | Credits: 4 | Coefficient: 4*

4. **Main & Virtual Memory Management**
   - Contiguous memory allocation (fixed/variable partitions, fragmentation, compaction, and swapping).
   - Address translation mechanisms: **Paging** (multi-level, inverted page tables, TLB), **Segmentation**, and segmented paging.
   - **Demand Paging** & Page Replacement algorithms (`FIFO`, `OPT`, `LRU`, `Second Chance`, `LFU`, `Aging`, `NRU`) and thrashing control (Working Set, PFF).

5. **Secondary Storage & RAID**
   - Disk I/O performance modeling and disk head scheduling algorithms (`FCFS`, `SSTF`, `SCAN`, `C-SCAN`, `LOOK`, `C-LOOK`).
   - Storage redundancy architectures (`RAID 0`, `1`, `5`, `6`, `01`, `10`, `50`).

6. **File Management Systems (SGF)**
   - Low-level file operations, file descriptors, directory structures, and contiguous vs. non-contiguous block allocation.
   - **UNIX/Linux File Systems (`ext2`/`ext3`, System V)**: Inodes, directory entries, logical volume layout, hard vs. symbolic links, and POSIX permissions (`chmod`, UID/GID).

## Repository Structure

```text
.
├── SYS1/
│   ├── 01-processes-and-trees/      # fork(), process hierarchies, signal handling
│   ├── 02-exec-and-wait/            # exec*(), wait() macros, multi-process pipelines
│   ├── 03-semaphores-sync/          # Rendezvous, Readers-Writers, Producer-Consumer
│   ├── 04-system-v-ipc/             # Shared memory (shm*) and semaphore sets (sem*)
│   └── 05-linking-and-elf/          # Static/dynamic linking and shared libraries
├── SYS2/
│   ├── 01-memory-management/        # Page replacement & virtual memory simulations
│   ├── 02-disk-scheduling/          # Disk I/O scheduling & RAID simulations
│   └── 03-unix-filesystem/          # File descriptors, inodes, links, and permissions
├── Makefile
└── README.md
