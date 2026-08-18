# CS509 Assignment 3 - Buddy Repository

## Repository Overview

This repository contains the Double / Buddy work for CS509 Assignment 3.

### Buddy Members

| Entry Number | Role |
|---|---|
| CSM1016 | Buddy Member |
| CSM1043 | Buddy Member |

### Assignment 3 Buddy Algorithms

- Gradient Descent
- Maxflow-Mincut

The Minimum Spanning Tree (MST) task, consisting of Kruskal's and Prim's algorithms, is an individual task in Assignment 3 and is not part of this Buddy implementation.

---

## Assignment Mode

**Double / Buddy**

The assignment is completed by a pair of students and stored in one shared repository.

---

## Language and Environment

- Programming Language: C++
- C++ Standard: C++17
- Compiler: g++
- Compilation Flag: `-O2`
- Timing Unit: milliseconds (ms)

---

## Directory Structure

```text
CS509_CSM1016_CSM1043/
|
|-- README.md
|
|-- common_wrapper/
|   `-- wrapper.cpp
|
`-- assignment_03/
    |
    |-- src/
    |   |-- csr.h
    |   |-- csr.cpp
    |   |-- gradient_descent.h
    |   |-- gradient_descent.cpp
    |   |-- maxflow.h
    |   `-- maxflow.cpp
    |
    |-- driver/
    |   `-- assignment3_driver.cpp
    |
    `-- tests/
        |-- gd_01.txt
        |-- gd_02.txt
        |-- gd_03.txt
        |-- gd_04.txt
        |-- gd_05.txt
        |-- maxflow_10.txt
        |-- maxflow_100.txt
        |-- maxflow_1000.txt
        |-- maxflow_10000.txt
        `-- maxflow_50000.txt
```

### Folder Purpose

- `common_wrapper/` - Repository-level common wrapper.
- `assignment_03/src/` - Core Assignment 3 algorithm and CSR implementation files.
- `assignment_03/driver/` - Dedicated Assignment 3 driver.
- `assignment_03/tests/` - Assignment 3 input test files.
- `README.md` - Complete documentation, execution instructions, correctness information, and result tables.

---

# Assignment 3 - Buddy Work

## Objective

The Buddy portion of Assignment 3 consists of:

1. Gradient Descent
2. Maxflow-Mincut

The driver reads and validates the input file, prepares the required data structure, calls the selected algorithm, and prints the final result and algorithm execution time.

For graph algorithms, the input adjacency list is converted to CSR before the algorithm is called.

---

# 1. Gradient Descent

## Algorithm / Approach

Gradient Descent is implemented for a generic one-variable polynomial:

```text
f(x) = c0 + c1*x + c2*x^2 + ... + cd*x^d
```

The derivative is:

```text
f'(x) = c1 + 2*c2*x + 3*c3*x^2 + ... + d*cd*x^(d-1)
```

The update rule is:

```text
x_new = x - learning_rate * f'(x)
```

The algorithm stops when:

```text
|f'(x)| <= tolerance
```

or when the maximum number of iterations has been executed.

The same implementation supports all required polynomial degrees:

- Degree 2
- Degree 4
- Degree 6
- Degree 8
- Degree 10

The five objective functions are not implemented as separate hard-coded algorithms.

---

## Gradient Descent CSR Requirement

Gradient Descent does not use CSR.

The polynomial coefficients and optimization parameters are read directly from the input file.

---

## Gradient Descent Input Format

```text
DEGREE d
COEFFICIENTS c0 c1 c2 ... cd
INITIAL_X x0
LEARNING_RATE alpha
TOLERANCE epsilon
MAX_ITERATIONS n
```

The `COEFFICIENTS` line contains exactly `d + 1` floating-point values in ascending power order.

---

## Required Gradient Descent Tests

| File | Degree | Initial x | Learning Rate | Tolerance | Max Iterations | Expected x* |
|---|---:|---:|---:|---:|---:|---:|
| `gd_01.txt` | 2 | 0 | 0.10 | 1e-6 | 5,000 | 3 |
| `gd_02.txt` | 4 | 2 | 0.02 | 1e-6 | 10,000 | 0 |
| `gd_03.txt` | 6 | 2 | 0.02 | 1e-6 | 20,000 | 0 |
| `gd_04.txt` | 8 | 2 | 0.01 | 1e-8 | 50,000 | 0 |
| `gd_05.txt` | 10 | 2 | 0.005 | 1e-10 | 100,000 | 0 |

---

# 2. Maxflow-Mincut

## Algorithm / Approach

Maxflow-Mincut operates on a directed graph with positive edge capacities.

The input graph is initially represented as an adjacency list.

Before the algorithm is called:

```text
Adjacency List -> CSR
```

The CSR conversion is preprocessing and is excluded from the reported algorithm execution time.

Dinic's algorithm is used to compute the maximum flow.

After the maximum flow is computed, the final residual graph is used to determine the vertices reachable from the source.

These vertices form the source side of the minimum cut.

The original CSR edges crossing from the source side to the sink side form the reported cut edges.

Correctness is checked using:

```text
Maximum Flow = Minimum Cut Capacity
```

---

## CSR Representation

The graph is converted into Compressed Sparse Row (CSR) format before the Maxflow-Mincut algorithm is timed.

The CSR representation consists of:

```text
row_ptr
col_idx
values
```

where:

- `row_ptr` stores the beginning and ending positions of each vertex's adjacency range.
- `col_idx` stores neighbouring vertex IDs.
- `values` stores edge capacities.

The adjacency-list-to-CSR conversion is completed before the timer starts.

---

## Maxflow-Mincut Input Format

```text
V E
u0 degree neighbor1 capacity1 neighbor2 capacity2 ...
u1 degree neighbor1 capacity1 neighbor2 capacity2 ...
...
u(V-1) degree ...
SOURCE s
SINK t
```

Where:

- `V` = number of vertices.
- `E` = number of directed capacity edges.
- Each neighbour is followed by the capacity of that directed edge.
- Only outgoing edges are listed in the input.
- Reverse residual edges are created internally.
- Source and sink must be valid and different.
- Required capacities are positive integers.

---

## Required Maxflow-Mincut Tests

| File | Vertices | Edges | Graph Type |
|---|---:|---:|---|
| `maxflow_10.txt` | 10 | 10 | Directed, sparse |
| `maxflow_100.txt` | 100 | 196 | Directed, sparse |
| `maxflow_1000.txt` | 1,000 | 1,996 | Directed, sparse |
| `maxflow_10000.txt` | 10,000 | 19,996 | Directed, sparse |
| `maxflow_50000.txt` | 50,000 | 99,996 | Directed, sparse |

The Assignment 3 specification also lists `maxflow_100000.txt` as optional.

---

# Source Files

| File | Purpose |
|---|---|
| `assignment_03/src/csr.h` | CSR data structure and function declarations |
| `assignment_03/src/csr.cpp` | CSR construction and related implementation |
| `assignment_03/src/gradient_descent.h` | Gradient Descent declarations |
| `assignment_03/src/gradient_descent.cpp` | Gradient Descent implementation |
| `assignment_03/src/maxflow.h` | Maxflow-Mincut declarations |
| `assignment_03/src/maxflow.cpp` | Dinic's Maxflow-Mincut implementation |
| `assignment_03/driver/assignment3_driver.cpp` | Assignment 3 input handling, execution and timing |
| `common_wrapper/wrapper.cpp` | Common repository-level wrapper |

---

# Compilation

## Assignment 3

From the repository root:

```bash
g++ -std=c++17 -O2 assignment_03/src/csr.cpp assignment_03/src/gradient_descent.cpp assignment_03/src/maxflow.cpp assignment_03/driver/assignment3_driver.cpp -o assignment_03.exe
```

## Common Wrapper

```bash
g++ -std=c++17 -O2 common_wrapper/wrapper.cpp -o wrapper.exe
```

---

# Direct Execution

## Gradient Descent

```bash
assignment_03.exe gd assignment_03/tests/gd_01.txt
```

## Maxflow-Mincut

```bash
assignment_03.exe maxflow assignment_03/tests/maxflow_10.txt
```

---

# Common Wrapper

Run the common wrapper using:

```bash
wrapper.exe
```

The wrapper provides options to:

1. Compile Assignment 3.
2. Run Gradient Descent on one test.
3. Run all Gradient Descent tests.
4. Run Maxflow-Mincut on one test.
5. Run all Maxflow-Mincut tests.
6. Compile and run all Assignment 3 tests.
0. Exit.

The common wrapper invokes the dedicated Assignment 3 driver.

---

# Input Validation

## Gradient Descent

The implementation checks for invalid input including:

- Invalid polynomial degree.
- Incorrect number of coefficients.
- Non-positive learning rate.
- Non-positive tolerance.
- Non-positive maximum iteration count.
- Invalid or missing input files.

## Maxflow-Mincut

The implementation checks for invalid input including:

- Invalid source vertex.
- Invalid sink vertex.
- Source equal to sink.
- Negative capacities.
- Invalid or missing input files.

---

# Timing Methodology

Only the execution time of the algorithm itself is reported.

The timer starts immediately before the algorithm call and stops immediately after the algorithm finishes.

The following operations are outside the timed region:

- File reading.
- Input parsing.
- Input validation.
- Adjacency-list construction.
- Adjacency-list-to-CSR conversion.
- Output formatting.
- Output printing.
- File writing.

For Maxflow-Mincut, the CSR representation is already prepared before the timer starts.

For Maxflow-Mincut, initialization of the residual network from the prepared CSR is part of the timed algorithm execution.

Minimum-cut extraction from the final residual graph is also part of the measured Maxflow-Mincut algorithm section.

### Compiler

```text
g++
```

### Compilation Flags

```text
-std=c++17 -O2
```

### Timing Unit

```text
milliseconds (ms)
```

### Timing Method

The algorithm execution is measured using C++ timing facilities immediately around the algorithm call.

For very fast inputs, repeated runs may be used and the average algorithm time may be reported, provided the number of runs is documented.

---

# Gradient Descent Results

The following are the observed results from the current implementation.

| Mode | Test File | Input Type | Input Size | Expected Output | Actual Output | Algorithm Time |
|---|---|---|---|---|---|---:|
| Double | `gd_01.txt` | Polynomial | Degree 2 | x* = 3 | x = 2.9999995063, f(x) = 0.0000000000, Iterations = 70, Converged = true | 0.0000000000 ms |
| Double | `gd_02.txt` | Polynomial | Degree 4 | x* = 0 | x = 0.0000002379, f(x) = 0.0000000000, Iterations = 180, Converged = true | 0.0000000000 ms |
| Double | `gd_03.txt` | Polynomial | Degree 6 | x* = 0 | x = 0.0000004835, f(x) = 0.0000000000, Iterations = 349, Converged = true | 0.0000000000 ms |
| Double | `gd_04.txt` | Polynomial | Degree 8 | x* = 0 | x = 0.0000000050, f(x) = 0.0000000000, Iterations = 948, Converged = true | 0.0000000000 ms |
| Double | `gd_05.txt` | Polynomial | Degree 10 | x* = 0 | x = 0.0000000000, f(x) = 0.0000000000, Iterations = 2364, Converged = true | 0.0000000000 ms |

All five required Gradient Descent tests converged successfully.

---

# Maxflow-Mincut Results

The following results were obtained from the current implementation.

| Mode | Test File | Input Type | Input Size | Expected Output | Actual Output | Algorithm Time |
|---|---|---|---|---|---|---:|
| Double | `maxflow_10.txt` | Directed adjacency list converted to CSR | V = 10, E = 10 | Maximum flow = minimum cut capacity | Maximum flow = 23, Minimum cut capacity = 23 | 0.017 ms |
| Double | `maxflow_100.txt` | Directed adjacency list converted to CSR | V = 100, E = 196 | Maximum flow = minimum cut capacity | Maximum flow = 20, Minimum cut capacity = 20 | 0.083 ms |
| Double | `maxflow_1000.txt` | Directed adjacency list converted to CSR | V = 1,000, E = 1,996 | Maximum flow = minimum cut capacity | Maximum flow = 20, Minimum cut capacity = 20 | 0.313 ms |
| Double | `maxflow_10000.txt` | Directed adjacency list converted to CSR | V = 10,000, E = 19,996 | Maximum flow = minimum cut capacity | Maximum flow = 20, Minimum cut capacity = 20 | 0.313 ms |
| Double | `maxflow_50000.txt` | Directed adjacency list converted to CSR | V = 50,000, E = 99,996 | Maximum flow = minimum cut capacity | Maximum flow = 20, Minimum cut capacity = 20 | 10.892 ms |

All five Maxflow-Mincut tests satisfy:

```text
Maximum Flow = Minimum Cut Capacity
```

---

# Correctness Verification

## Gradient Descent

| Test File | Expected x* | Actual x | Converged | Status |
|---|---:|---:|---|---|
| `gd_01.txt` | 3 | 2.9999995063 | true | PASS |
| `gd_02.txt` | 0 | 0.0000002379 | true | PASS |
| `gd_03.txt` | 0 | 0.0000004835 | true | PASS |
| `gd_04.txt` | 0 | 0.0000000050 | true | PASS |
| `gd_05.txt` | 0 | 0.0000000000 | true | PASS |

## Maxflow-Mincut

| Test File | Maximum Flow | Minimum Cut Capacity | Status |
|---|---:|---:|---|
| `maxflow_10.txt` | 23 | 23 | PASS |
| `maxflow_100.txt` | 20 | 20 | PASS |
| `maxflow_1000.txt` | 20 | 20 | PASS |
| `maxflow_10000.txt` | 20 | 20 | PASS |
| `maxflow_50000.txt` | 20 | 20 | PASS |

---

# Complexity

## Gradient Descent

For a polynomial of degree `d`, polynomial and derivative evaluation require:

```text
O(d)
```

work per iteration.

For `I` iterations, the total algorithm complexity is:

```text
O(d * I)
```

The coefficient array requires:

```text
O(d)
```

space.

## Maxflow-Mincut

Dinic's algorithm is used for maximum flow.

For a general directed graph, the worst-case complexity is:

```text
O(V^2 * E)
```

where:

- `V` = number of vertices.
- `E` = number of directed edges.

Practical execution time depends on graph structure and the residual network.

## CSR Conversion

For a graph with `V` vertices and `E` stored adjacency entries, adjacency-list-to-CSR conversion requires:

```text
O(V + E)
```

time.

CSR conversion is preprocessing and is excluded from the reported algorithm execution time.

---

# Result Summary

## Gradient Descent

| Test | Status | Iterations | Execution Time |
|---|---|---:|---:|
| `gd_01.txt` | PASS | 70 | 0.0000000000 ms |
| `gd_02.txt` | PASS | 180 | 0.0000000000 ms |
| `gd_03.txt` | PASS | 349 | 0.0000000000 ms |
| `gd_04.txt` | PASS | 948 | 0.0000000000 ms |
| `gd_05.txt` | PASS | 2364 | 0.0000000000 ms |

## Maxflow-Mincut

| Test | Vertices | Edges | Maximum Flow | Minimum Cut Capacity | Execution Time | Status |
|---|---:|---:|---:|---:|---:|---|
| `maxflow_10.txt` | 10 | 10 | 23 | 23 | 0.017 ms | PASS |
| `maxflow_100.txt` | 100 | 196 | 20 | 20 | 0.083 ms | PASS |
| `maxflow_1000.txt` | 1,000 | 1,996 | 20 | 20 | 0.313 ms | PASS |
| `maxflow_10000.txt` | 10,000 | 19,996 | 20 | 20 | 0.313 ms | PASS |
| `maxflow_50000.txt` | 50,000 | 99,996 | 20 | 20 | 10.892 ms | PASS |

---

# Test File Naming Convention

## Gradient Descent

```text
gd_01.txt
gd_02.txt
gd_03.txt
gd_04.txt
gd_05.txt
```

## Maxflow-Mincut

```text
maxflow_10.txt
maxflow_100.txt
maxflow_1000.txt
maxflow_10000.txt
maxflow_50000.txt
```

Optional:

```text
maxflow_100000.txt
```

---

# Timing Observations

## Gradient Descent

The current Gradient Descent tests are extremely fast and report:

```text
0.0000000000 ms
```

for all five tests.

## Maxflow-Mincut

| Test File | Execution Time |
|---|---:|
| `maxflow_10.txt` | 0.017 ms |
| `maxflow_100.txt` | 0.083 ms |
| `maxflow_1000.txt` | 0.313 ms |
| `maxflow_10000.txt` | 0.313 ms |
| `maxflow_50000.txt` | 10.892 ms |

---

# References

- CS509 Assignment 3 Specification.
- CS509 Lab Work Guidelines.
- CS509 Assignment 1 Guidelines and Repository Conventions.
- CS509 Assignment 2 Guidelines and Repository Conventions.
