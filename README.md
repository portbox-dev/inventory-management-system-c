# Inventory Management System in C

A console-based Inventory Management System developed in the **C programming language**.

This project is designed to manage product information such as product ID, name, price, and quantity. It also uses **file handling** to save inventory data in a human-readable text file (`inventory.txt`) so that the data can be loaded again when the program is restarted.

---

## 📌 Project Overview

The Inventory Management System provides a simple way to manage products through a menu-driven console interface.

The program allows the user to:

- Add products
- View all products in the inventory
- Update product information
- Remove products
- Search for a product using its ID
- Automatically generate product IDs
- Save inventory data to a text file
- Load previously saved inventory data
- Validate user input
- Prevent negative prices and quantities

The inventory can contain a maximum of **50 products**.

---

## ✨ Features

### 1. Add Products

Users can add one or multiple products at a time.

For every product, the program stores:

- Product ID
- Product Name
- Product Price
- Product Quantity

Product IDs are automatically generated starting from **101**.

---

### 2. Check Inventory

The user can view all products currently stored in the inventory.

Example:

```text
==================== INVENTORY ====================
ID              Name            Price           Quantity
101             T-Shirt         Rs.499.00       20
102             Jeans           Rs.999.00       10
103             Shoes           Rs.1499.00      5
```

---

### 3. Update Product

Products can be updated using their Product ID.

The user can update:

- Product Name
- Product Price
- Product Quantity

---

### 4. Remove Products

Products can be removed using their Product ID.

The program shifts the remaining products in the array so that the inventory remains properly organized.

The user can remove multiple products in a single operation.

---

### 5. Search Product

The program allows the user to search for a product using its Product ID.

If the product is found, its complete details are displayed.

Example:

```text
Item Found!
--- Product Details ---
Product ID : 101
Product Name : T-Shirt
Product Price : Rs.499.00
Product Quantity : 20
```

---

### 6. Automatic Product IDs

The program automatically generates product IDs.

The starting ID is:

```text
101
```

After adding a product, the next available ID is automatically increased.

The `nextid` value is also saved in the text file so that product IDs continue correctly after restarting the program.

---

### 7. File Handling

The program uses a text file named:

```text
inventory.txt
```

The file is used to permanently store inventory information.

When the program starts:

```text
loadData()
```

loads previously saved information from the file.

After adding, updating, or removing products:

```text
saveData()
```

saves the latest inventory information.

---

## 💾 Data Storage

The inventory data is stored in a human-readable format.

Example `inventory.txt`:

```text
Count : 3
NextID : 104

ID : 101
Name : T-Shirt
Quantity : 20
Price : 499.00

ID : 102
Name : Jeans
Quantity : 10
Price : 999.00

ID : 103
Name : Shoes
Quantity : 5
Price : 1499.00
```

This format allows both the **C program** and a **human user** to understand the stored information.

The file is automatically created when the program saves inventory data.

---

## 🖥️ Program Menu

The program provides the following menu:

```text
1) Check Inventory
2) Update Inventory
3) Add Item
4) Remove Items
5) Search Item by ID
6) Exit
```

---

## 🧠 C Programming Concepts Used

This project demonstrates several important concepts of C programming:

### Structures

A `struct Product` is used to group product-related information.

```c
struct Product
{
    int id;
    char name[50];
    int qty;
    float price;
};
```

### Arrays

An array of structures is used to store multiple products.

```c
struct Product inventory[MAX_PRODUCTS];
```

The maximum number of products is defined using:

```c
#define MAX_PRODUCTS 50
```

### Functions

The program is divided into multiple functions to keep the code organized.

Functions include:

- `add()`
- `check()`
- `update()`
- `rem()`
- `search()`
- `findProduct()`
- `loadData()`
- `saveData()`
- `clearInputBuffer()`

### Pointers

Pointers are used when functions need to modify variables such as:

- `count`
- `nextid`

For example:

```c
add(inventory, &count, &nextid);
```

### File Handling

The program uses C file-handling functions such as:

```c
fopen()
fscanf()
fprintf()
fclose()
```

The file is opened in:

- `"r"` mode for reading
- `"w"` mode for writing

### Input Validation

The program checks whether the user enters the expected type of input.

For example:

```c
if (scanf("%d", &choice) != 1)
```

This prevents invalid input from repeatedly causing the program to get stuck in an input loop.

The program also prevents:

- Negative prices
- Negative quantities
- Invalid menu choices
- Invalid product IDs
- Adding more than 50 products

---

## 📂 Project Structure

```text
inventory-management-system-c/
│
├── inventory_management.c
└── README.md
```

When the program is executed and data is saved, it creates:

```text
inventory.txt
```

So the runtime environment can contain:

```text
inventory-management-system-c/
│
├── inventory_management.c
├── README.md
└── inventory.txt
```

`inventory.txt` is generated by the program and stores the current inventory data.

---

## ⚙️ Requirements

To compile and run this project, you need:

- A C compiler
- GCC, Clang, or another standard C compiler
- A terminal or command prompt

---

## ▶️ How to Compile

If you are using GCC:

```bash
gcc inventory_management.c -o inventory
```

---

## ▶️ How to Run

### Windows

```bash
inventory.exe
```

### Linux / macOS

```bash
./inventory
```

---

## 🔄 How Data Persistence Works

The program uses two functions for file-based data persistence.

### `loadData()`

When the program starts, it attempts to open:

```text
inventory.txt
```

If the file exists, the saved product information is loaded into the inventory array.

If the file does not exist, the program starts with:

```text
Count = 0
Next ID = 101
```

---

### `saveData()`

After operations that modify the inventory, the program saves the updated information to:

```text
inventory.txt
```

The program saves:

- Total product count
- Next product ID
- Product ID
- Product name
- Product quantity
- Product price

The data is written in a human-readable format.

---

## 🛡️ Input Validation

The program contains input validation to make the program more reliable.

Examples include:

- Checking whether menu input is a number
- Checking whether product IDs are valid numbers
- Checking whether quantities are valid whole numbers
- Checking whether prices are valid numbers
- Preventing negative prices
- Preventing negative quantities
- Preventing the inventory from exceeding 50 products
- Handling invalid product IDs during removal and searching

The program also uses:

```c
clearInputBuffer()
```

to remove unwanted characters remaining in the input buffer.

---

## 📊 Maximum Capacity

The inventory has a maximum capacity of:

```text
50 products
```

This value is controlled by:

```c
#define MAX_PRODUCTS 50
```

The starting product ID is controlled by:

```c
#define STARTING_ID 101
```

Using constants makes these values easier to modify in the future.

---

## 🧩 Main Functions

| Function | Purpose |
|---|---|
| `main()` | Controls the main menu and program flow |
| `add()` | Adds one or more products |
| `check()` | Displays all products |
| `update()` | Updates product information |
| `rem()` | Removes products |
| `search()` | Searches for a product by ID |
| `findProduct()` | Finds the array position of a product |
| `loadData()` | Loads saved data from `inventory.txt` |
| `saveData()` | Saves inventory data to `inventory.txt` |
| `clearInputBuffer()` | Clears unwanted input from the input buffer |

---

## 🔍 Example Workflow

A typical workflow could be:

```text
Start Program
      ↓
Load inventory.txt
      ↓
Display Menu
      ↓
Add Product
      ↓
Save Data
      ↓
Check Inventory
      ↓
Update Product
      ↓
Save Data
      ↓
Search Product
      ↓
Remove Product
      ↓
Save Data
      ↓
Exit
```

---

## 🎯 Learning Objectives

This project was created to practice applying C programming concepts to a small real-world style application.

The main learning objectives were:

- Understanding structures
- Working with arrays of structures
- Creating modular functions
- Using pointers
- Passing arrays and variables to functions
- Searching data
- Manipulating array elements
- Reading and writing files
- Creating persistent data storage
- Handling user input
- Validating user input
- Building a menu-driven application

---

## 🚀 Possible Future Improvements

The current project is intentionally built as a simple C console application.

Possible future improvements include:

- Sorting products by ID, name, price, or quantity
- Searching products by name
- Low-stock warnings
- Product categories
- Better tabular formatting
- Separate functions for different types of reports
- Sales and billing functionality
- More advanced file/data management
- Improved user interface

---

## 📌 Current Limitations

- Maximum of 50 products
- Console-based interface
- Inventory is stored in a local text file
- Product information is managed using a fixed-size array
- No graphical user interface
- No database is used

---

## 👨‍💻 Author

**Neil Singh**

Inventory Management System - C Programming Project

---

## 📜 Project Purpose

This project was developed as a practical C programming project to understand how fundamental programming concepts can be combined to create a functional inventory management application.

**Built with C ❤️**
