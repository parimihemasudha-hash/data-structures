Library Management System
Overview

The Library Management System is a simple console-based application developed in C. It allows users to manage book records using file handling. The program stores book information in a binary file and provides options to add, display, update, and delete books.

Features
Add new books
Display all book records
Update existing book details
Delete book records
Store data permanently using files
Technologies Used
Programming Language: C
File Handling: Binary Files (books.dat)
Compiler: GCC / MinGW
Book Structure

Each book record contains:

Book ID
Book Name
Author Name
Price
struct Book
{
    int id;
    char name[50];
    char author[50];
    float price;
};
Functions
1. Add Book

Allows the user to enter book details and saves them into books.dat.

2. Display Books

Reads all book records from the file and displays them on the screen.

3. Update Book

Searches for a book using its ID and updates its details.

4. Delete Book

Deletes a book record by copying all records except the selected one into a temporary file.

File Used
File Name	Purpose
books.dat	Stores book records
temp.dat	Temporary file used during deletion
Menu Options
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. Display Books
3. Update Book
4. Delete Book
5. Exit
How to Compile

Using GCC:

gcc library.c -o library
How to Run

Windows:

library.exe

Linux/Mac:

./library
Sample Output
===== LIBRARY MANAGEMENT SYSTEM =====

1. Add Book
2. Display Books
3. Update Book
4. Delete Book
5. Exit

Enter your choice: 1

Enter Book ID: 101
Enter Book Name: C Programming
Enter Author Name: Dennis Ritchie
Enter Price: 450

Book added successfully!
Advantages
Easy to use menu-driven interface
Permanent storage using file handling
Simple implementation of CRUD operations
Suitable for beginners learning C programming
Future Enhancements
Search book by ID or name
Issue and return books
User login system
Book availability status
Graphical User Interface (GUI)
Database connectivity (MySQL)
