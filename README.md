# Dublelinkedlist
📌 Doubly Linked List Implementation in C++

This project demonstrates a basic implementation of a Doubly Linked List in C++ using dynamic memory allocation. The program provides a menu-driven interface that allows users to perform various operations on the linked list.

🚀 Features
Insert a node at the beginning
Insert a node at the end
Insert a node after a specific value (middle insertion)
Delete a node from the beginning
Delete a node from the end
Delete a node with a specific value (middle deletion)
Display the current list
🧠 Concepts Covered
Dynamic memory allocation using new and delete
Use of structures (struct node)
Pointer manipulation (previous and next)
Traversal of doubly linked lists
Menu-driven programming in C++
🛠️ How It Works

The program maintains two pointers:

head → points to the first node
last → points to the last node

Each node contains:

A pointer to the previous node
Data (integer)
A pointer to the next node

Users can interact with the program through a console-based menu to perform operations on the list.

▶️ Usage

Compile the program using a C++ compiler:

g++ filename.cpp -o dll

Run the executable:

./dll
Follow the on-screen menu to perform operations.
⚠️ Note

This is a basic educational implementation. Some functions may require improvements for:

Better memory handling
Edge case handling (e.g., empty list operations)
Code optimization and cleanup
📚 Purpose

This project is ideal for beginners learning data structures, especially linked lists, and helps build a strong foundation in pointer-based programming.
