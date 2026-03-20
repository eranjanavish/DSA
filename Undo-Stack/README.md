# Undo Token System — Stack Module

## Overview
This module implements the Undo Token System for the
Government Office Queue Management System using a
Dynamic Stack (Singly Linked List based).

The stack acts as a verification checkpoint between
the Priority Queue and the Service Counter. Every token
dequeued from the waiting queue is pushed to this stack
where staff can confirm or decline it before it reaches
the counter. Declined tokens remain in the stack and
can be reviewed at the end of the day.

---

## Data Structure
**Dynamic Stack — Singly Linked List**

Each node in the stack holds a pointer to a full token
object. The stack grows and shrinks dynamically using
malloc and free — no fixed size limit.

---

## Files

| File | Description |
|---|---|
| `undo_stack.h` | Header file — structs and prototypes |
| `undo_stack.c` | Implementation file — all functions |

---

## Functions

| Function | Description |
|---|---|
| `initialize_stack()` | Initializes the stack at office opening |
| `create_node()` | Creates a new stack node |
| `is_empty()` | Checks if stack is empty |
| `push()` | Pushes token onto stack after dequeue |
| `pop()` | Removes and returns top token |
| `peek()` | Returns top token without removing |
| `display_stack()` | Displays all rejected tokens |
| `stack_size()` | Returns number of tokens in stack |
| `clear_stack()` | Clears stack at end of day |
| `run_undo_menu()` | Main menu for counter operator |

---

## Position in System

```
Token Generator
      ↓
Priority Queue / Normal Queue
      ↓
UNDO STACK  ← This Module
      ↓
Service Counter
```

---

## How It Works

```
1. Token issued at reception
2. Token enters Priority or Normal Queue
3. Counter operator opens Undo Stack menu
4. System dequeues next token automatically
5. Token pushed to stack
6. Staff sees full token details
7. Confirm → token sent to counter
   Decline → token stays in stack as rejected
8. End of day → display all rejected → clear stack
```

---

## How to Connect

### Include Header
```c
#include "Undo_Stack/undo_stack.h"
```

### Initialize
```c
struct stack undo_stack;
initialize_stack(&undo_stack);
```

### Run Menu (Case 2 in main.c)
```c
run_undo_menu(&undo_stack,
              &list,
              counter_head,
              counter_count);
```

### Display Rejected (Case 4 in main.c)
```c
display_stack(&undo_stack);
```

### End of Day (Case 5 in main.c)
```c
display_stack(&undo_stack);
clear_stack(&undo_stack);
```

---

## Dependencies

| Header | From | Purpose |
|---|---|---|
| `token.h` | Token Generator | Token struct |
| `queue.h` | Queue Module | DEQUEUE() ENQUEUE() IS_EMPTY() |
| `counter.h` | Counter Management | assignToken() |

---


## Compile Command

```bash
gcc main.c Token_Generator/token.c Queue/queue.c Counter/counter.c Undo_Stack/undo_stack.c -o system
./system
```

---

## Author
**Madush**
Government Office Queue Management System
