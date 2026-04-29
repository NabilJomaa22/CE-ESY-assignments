# Circular Buffer Project

A simple implementation of a **Circular Buffer** (Ring Buffer) in C.  
The program reads a user's name, appends the string `"CE-ESY"`, stores it in a circular buffer, then reads it back and verifies that the buffer becomes empty.  
Two buffer sizes are tested – one smaller and one larger than the input string – to demonstrate proper handling of **overflow** and **underflow** conditions.

## Files

- `main.c` – Contains the entire implementation including:
  - `CircularBuffer` structure  
  - `init`, `isFull`, `isEmpty`, `write`, `read` functions  
  - `runTest` helper to test different capacities  
  - `main` function that prompts the user and runs the tests.

## How to Compile and Run

1. **Compile** using any C compiler (e.g., `gcc`):
   ```bash
   gcc -o circular_buffer main.c
