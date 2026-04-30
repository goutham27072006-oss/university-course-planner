# university-course-planner
Here’s a **clean, ready-to-use content** for your PPT based on your *Student Record Management System (Linked List in C)* 👇

---

# 🎓 **1. Project Title**

**Student Record Management System using Linked List in C**

---

# ❗ **2. Problem Statement**

Managing student records manually (on paper or simple files) is inefficient, time-consuming, and error-prone.
There is a need for a system that allows easy **creation, modification, deletion, and retrieval** of student data in a structured and efficient way.

---

# 🌍 **3. Real-world Application**

* College student database systems
* School record management
* Library user records
* Employee management systems
* Any application requiring dynamic data storage

👉 Especially useful where **data size changes frequently**

---

# 🧩 **4. Data Structure Used**

**Singly Linked List**

### Why Linked List?

* Dynamic memory allocation (no fixed size)
* Efficient insertion and deletion
* No memory wastage compared to arrays

### Structure Used:

```c
struct Student {
    int id;
    char name[50];
    float marks;
    struct Student* next;
};
```

---

# 🏗️ **5. System Design**

The system is **menu-driven** and consists of the following modules:

* Add Student (Create)
* Delete Student (Delete)
* Update Student (Update)
* Search Student (Read specific)
* Display Students (Read all)

### Flow:

User Input → Menu → Function Call → Linked List Operation → Output

---

# ⚙️ **6. Algorithm**

### ➤ Add Student

1. Create a new node using `malloc`
2. Take input (ID, Name, Marks)
3. Insert node at beginning
4. Update head pointer

---

### ➤ Delete Student

1. Take ID as input
2. Traverse list
3. Find matching node
4. Adjust links
5. Free memory

---

### ➤ Update Student

1. Input ID
2. Search node
3. Modify name and marks

---

### ➤ Search Student

1. Input ID
2. Traverse list
3. If found → display
4. Else → not found

---

### ➤ Display Students

1. Traverse from head
2. Print all nodes

---

# 💻 **7. Implementation**

* Language: **C**
* Concepts used:

  * `struct`
  * `malloc()` and `free()`
  * Functions (modular design)
  * Menu-driven interface

### Key Functions:

* `addStudent()`
* `deleteStudent()`
* `updateStudent()`
* `searchStudent()`
* `displayStudents()`

---

# 🖥️ **8. Demo Output**

```
--- STUDENT MANAGEMENT SYSTEM ---
1. Add Student
2. Delete Student
3. Update Student
4. Search Student
5. Display Students
6. Exit

Enter choice: 1
Enter ID: 101
Enter Name: Rahul
Enter Marks: 85

Student Added Successfully

Enter choice: 5
ID: 101 | Name: Rahul | Marks: 85.00
```

---

# ✅ **9. Conclusion**

* Successfully implemented a **menu-driven CRUD system**
* Demonstrated use of **linked list and dynamic memory**
* Efficient for managing dynamic datasets
* Easy to expand with more features



