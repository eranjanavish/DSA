# Queue Management System (C)

A queue management system implemented using a doubly linked list in C.

## Features
- Priority queue handling
- Normal queue handling
- Missed customer queue
- Smart serving logic

## How It Works
- Priority customers are served first
- Then up to 2 normal customers
- Then missed customers

## Compilation

```bash
gcc main.c queue.c -o queue