# <img src="https://cdn-icons-png.flaticon.com/512/6132/6132227.png" alt="C++ Logo" width="50"/> C++ Object-Oriented Programming Exercises

A curated collection of C++ exercises designed to master the principles of Object-Oriented Programming (OOP). This series covers class creation, memory management, operator overloading, and more.

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Author](https://img.shields.io/badge/Author-Youssef%20Lagmouch-red.svg)]()

---

## 📚 Table of Contents

- [Exercise 1: The `Point` Class](#-exercise-1-the-point-class)
- [Exercise 2: Product & Store Management](#-exercise-2-product--store-management)
- [Exercise 3: Polynomial Manipulation](#-exercise-3-polynomial-manipulation)
- [How to Compile & Run](#-how-to-compile--run)
- [Author](#-author)

---

## 📐 Exercise 1: The `Point` Class

**Objective:** Create a `Point` class to model a 2D point with complete functionality.

### 📋 Tasks
- [ ] Create a `Point` class with two private attributes: `x` and `y`.
- [ ] Implement a default constructor, an initialization constructor, and a copy constructor.
- [ ] Implement getter and setter methods for the attributes.
- [ ] In the `main()` function, create three `Point` objects.
- [ ] Add a method that returns the point's coordinates as a string.
- [ ] Add a method to calculate the distance between two points.

---

## 🛒 Exercise 2: Product & Store Management

**Objective:** Implement a `Product` class and a `Magasin` (Store) class to manage a collection of products with dynamic memory.

### 📋 Tasks

#### For the `Product` Class:
- [ ] Add a static attribute `TVA` (VAT) to the class.
- [ ] Add a static method to modify the `TVA`.
- [ ] Add a method to calculate the price including tax (`prix TTC`).

#### For the `Magasin` (Store) Class:
- [ ] Create a `Magasin` class containing a dynamic array of `Product` objects.
- [ ] Implement methods to:
    - [ ] Add a product.
    - [ ] Delete a product.
    - [ ] Modify a product.
- [ ] Implement a method to calculate the total sum of all TVA.

---

## 🧮 Exercise 3: Polynomial Manipulation

**Objective:** Create a `Polynome` class to represent and perform mathematical operations on polynomials.

### 📋 Class Definition
- [ ] Define a class `Polynome` with a `float * poly` pointer and an `int deg` for the degree.

### 📋 Tasks
- [ ] **Constructor:** Implement a constructor for the class.
- [ ] **Operator Overloading:** Overload operators for polynomial operations (e.g., `+`, `-`, `*`).
- [ ] **Polynomial Operations:** Implement methods for polynomial arithmetic.
- [ ] **Friend Function:** Use a friend function to handle the display of the polynomial.
- [ ] **`main()` Function:** Implement all functionalities and demonstrate them in the `main()` function.

---

## 🚀 How to Compile & Run

Each exercise is in its own directory. To compile and run, use a C++ compiler like g++.

**Example for Exercise 1:**
```bash
# Navigate to the exercise directory
cd exercise_1_point

# Compile the source files
g++ -std=c++17 -o main main.cpp Point.cpp

# Run the executable
./main
```
*Note: Ensure your compiler supports C++17 or a later standard.*

---

## ✍️ Author

**Youssef Lagmouch**

Thank you for checking out my C++ exercises. Feel free to connect or provide feedback
