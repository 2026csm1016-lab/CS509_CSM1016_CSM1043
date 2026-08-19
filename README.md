# CS509 Assignment 3 - Buddy Repository

## Repository Overview

This repository contains the Buddy/Double work for CS509 Assignment 3.

The Assignment 3 Buddy algorithms implemented in this repository are:

- Gradient Descent
- Maxflow-Mincut

MST (Kruskal and Prim) is an individual task in the Assignment 3 specification and is not part of this Buddy implementation.

---

## Buddy Details

| Field | Information |
|---|---|
| Student | Harshita Mahor |
| Entry Number | 2026CSM1016 |
| Buddy | Sejal |
| Buddy Entry Number | 2026CSM1043 |
| Assignment | CS509 Assignment 3 |
| Mode | Double / Buddy |
| Language | C++ |
| Standard | C++17 |
| Compiler | g++ |

---

## Important CSR Note

The Assignment 3 specification requires graph algorithms to use CSR and states that the CSR conversion function from a previous assignment should be called rather than copied.

For this repository, a fresh CSR implementation has been created because this Buddy/repository setup is new.

This is a deliberate project decision and should be confirmed with the TA/instructor before final submission if the "do not copy previous CSR" rule is interpreted strictly.

Gradient Descent does not use CSR.

---

## Language and Environment

- Language: C++
- Standard: C++17
- Compiler: g++
- Recommended optimization flag for timing: `-O2`

---

## Directory Structure

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

---

# Assignment 3 - Buddy Mode

## Gradient Descent

A generic one-variable polynomial is represented as:

    f(x) = c0 + c1*x + c2*x^2 + ... + cd*x^d

The derivative is evaluated from the coefficient array.

The update rule is:

    x_new = x - learning_rate * f'(x)

The algorithm stops when:

    |f'(x)| <= tolerance

or when the maximum iteration limit is reached.

The same implementation supports polynomial degrees:

- 2
- 4
- 6
- 8
- 10

---

## Maxflow-Mincut

The input graph is a directed capacity adjacency list.

The driver converts the graph to CSR before timing begins.

Dinic's algorithm is used to compute the maximum flow.

The final residual graph is used to find the vertices reachable from the source. These vertices form the source side of the minimum cut.

Original CSR edges crossing from the source side to the sink side are reported as cut edges.

---

# Input Formats

## Gradient Descent

    DEGREE d
    COEFFICIENTS c0 c1 c2 ... cd
    INITIAL_X x0
    LEARNING_RATE alpha
    TOLERANCE epsilon
    MAX_ITERATIONS n

---

## Maxflow-Mincut

    V E
    u0 degree neighbor1 capacity1 neighbor2 capacity2 ...
    ...
    u(V-1) degree ...
    SOURCE s
    SINK t

Only outgoing edges are listed.

Reverse residual edges are created internally by the Maxflow-Mincut implementation.

---

# Required Gradient Descent Tests

| File | Degree | Initial x | Learning Rate | Tolerance | Max Iterations | Expected x* |
|---|---:|---:|---:|---:|---:|---:|
| `gd_01.txt` | 2 | 0 | 0.10 | 1e-6 | 5,000 | 3 |
| `gd_02.txt` | 4 | 2 | 0.02 | 1e-6 | 10,000 | 0 |
| `gd_03.txt` | 6 | 2 | 0.02 | 1e-6 | 20,000 | 0 |
| `gd_04.txt` | 8 | 2 | 0.01 | 1e-8 | 50,000 | 0 |
| `gd_05.txt` | 10 | 2 | 0.005 | 1e-10 | 100,000 | 0 |

---

# Required Maxflow Tests

| File | Vertices | Edges | Graph Type |
|---|---:|---:|---|
| `maxflow_10.txt` | 10 | 10 | Directed, sparse |
| `maxflow_100.txt` | 100 | 196 | Directed, sparse |
| `maxflow_1000.txt` | 1,000 | 1,996 | Directed, sparse |
| `maxflow_10000.txt` | 10,000 | 19,996 | Directed, sparse |
| `maxflow_50000.txt` | 50,000 | 99,996 | Directed, sparse |

The Assignment 3 specification also lists `maxflow_100000.txt` as optional.

---

# Compilation

Compile Assignment 3 from the repository root:

    g++ -std=c++17 -O2 assignment_03/src/csr.cpp assignment_03/src/gradient_descent.cpp assignment_03/src/maxflow.cpp assignment_03/driver/assignment3_driver.cpp -o assignment_03.exe

---

# Direct Execution

## Gradient Descent

    .\assignment_03.exe gd assignment_03/tests/gd_01.txt

    .\assignment_03.exe gd assignment_03/tests/gd_02.txt

    .\assignment_03.exe gd assignment_03/tests/gd_03.txt

    .\assignment_03.exe gd assignment_03/tests/gd_04.txt

    .\assignment_03.exe gd assignment_03/tests/gd_05.txt

---

## Maxflow-Mincut

    .\assignment_03.exe maxflow assignment_03/tests/maxflow_10.txt

    .\assignment_03.exe maxflow assignment_03/tests/maxflow_100.txt

    .\assignment_03.exe maxflow assignment_03/tests/maxflow_1000.txt

    .\assignment_03.exe maxflow assignment_03/tests/maxflow_10000.txt

    .\assignment_03.exe maxflow assignment_03/tests/maxflow_50000.txt

---

# Common Wrapper

The repository contains a common wrapper:

    common_wrapper/wrapper.cpp

The wrapper can:

- compile Assignment 3
- run one Gradient Descent test
- run all Gradient Descent tests
- run one Maxflow-Mincut test
- run all Maxflow-Mincut tests
- compile and run all Assignment 3 tests

Compile the wrapper using:

    g++ -std=c++17 -O2 common_wrapper/wrapper.cpp -o wrapper.exe

Run:

    .\wrapper.exe

The common wrapper is maintained separately from the Assignment 3 implementation.

Future assignments can extend the common wrapper without modifying the Assignment 3 source files or driver.

---

# Timing Methodology

Only algorithm execution time is measured.

The following are outside the timed region:

- file reading
- input parsing
- input validation
- adjacency-list construction
- CSR conversion
- output formatting
- result printing
- file writing

For Maxflow-Mincut:

    Adjacency List
          |
          v
    CSR Conversion
          |
          v
    Timer Starts
          |
          v
    Dinic's Algorithm
          |
          v
    Timer Stops

CSR conversion is therefore excluded from the reported Maxflow-Mincut execution time.

For Gradient Descent, the timer measures only the Gradient Descent algorithm execution.

---

# Gradient Descent Results

| Test Case | Degree | Final x | Final f(x) | Iterations | Converged | Execution Time (ms) |
|---|---:|---:|---:|---:|---|---:|
| `gd_01.txt` | 2 | 2.9999995063 | 0.0000000000 | 70 | true | 0.0000000000 |
| `gd_02.txt` | 4 | 0.0000002379 | 0.0000000000 | 180 | true | 0.0000000000 |
| `gd_03.txt` | 6 | 0.0000004835 | 0.0000000000 | 349 | true | 0.0000000000 |
| `gd_04.txt` | 8 | 0.0000000050 | 0.0000000000 | 948 | true | 0.0000000000 |
| `gd_05.txt` | 10 | 0.0000000000 | 0.0000000000 | 2364 | true | 0.0000000000 |

All five Gradient Descent tests converged successfully.

---

# Maxflow-Mincut Results

| Test Case | Vertices | Edges | Maximum Flow | Minimum Cut Capacity | Execution Time (ms) |
|---|---:|---:|---:|---:|---:|
| `maxflow_10.txt` | 10 | 10 | 23 | 23 | 0.000 |
| `maxflow_100.txt` | 100 | 196 | 20 | 20 | 4.028 |
| `maxflow_1000.txt` | 1,000 | 1,996 | 20 | 20 | 0.000 |
| `maxflow_10000.txt` | 10,000 | 19,996 | 20 | 20 | 2.502 |
| `maxflow_50000.txt` | 50,000 | 99,996 | 20 | 20 | 19.891 |

For every completed Maxflow-Mincut test:

    Maximum Flow = Minimum Cut Capacity

Therefore, the max-flow/min-cut correctness condition is satisfied for all completed tests.

---

# Correctness Checks

## Gradient Descent

The following are checked:

- expected minimum
- final value of `x`
- final function value
- convergence status
- maximum iteration limit

All five required Gradient Descent tests converged successfully.

---

## Maxflow-Mincut

The maximum-flow/minimum-cut condition is checked:

    Maximum Flow = Minimum Cut Capacity

| Test Case | Maximum Flow | Minimum Cut Capacity | Status |
|---|---:|---:|---|
| `maxflow_10.txt` | 23 | 23 | PASS |
| `maxflow_100.txt` | 20 | 20 | PASS |
| `maxflow_1000.txt` | 20 | 20 | PASS |
| `maxflow_10000.txt` | 20 | 20 | PASS |
| `maxflow_50000.txt` | 20 | 20 | PASS |

---

# Complexity

## Gradient Descent

For polynomial degree `d` and `I` iterations:

    Time Complexity: O(d × I)

Space complexity:

    O(d)

---

## Maxflow-Mincut

The implementation uses Dinic's algorithm.

The general worst-case complexity is:

    O(V²E)

Practical performance depends on graph structure and capacities.

---

## CSR Conversion

CSR construction is preprocessing.

Its complexity is:

    O(V + E)

CSR conversion is excluded from the reported algorithm execution time.

---

# Assignment 3 Observations

- Gradient Descent supports polynomial degrees 2, 4, 6, 8 and 10.
- All five Gradient Descent tests converged successfully.
- Maxflow-Mincut uses Dinic's algorithm.
- Maxflow-Mincut uses CSR after the input graph has been prepared.
- CSR conversion is outside the timed region.
- All five completed Maxflow-Mincut tests satisfy Maximum Flow = Minimum Cut Capacity.
- The largest completed Maxflow-Mincut test contains 50,000 vertices.
- The latest recorded execution time for `maxflow_50000.txt` is 19.891 ms.
- The current Gradient Descent runs report extremely small execution times of 0.0000000000 ms.

