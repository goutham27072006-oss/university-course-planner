🎓 1. Project Title

University Course Planner using Graph (Adjacency Matrix) in C 

❗ 2. Problem Statement

Planning course sequences manually is difficult when multiple prerequisites are involved. Students may take courses in the wrong order, leading to academic issues.

There is a need for a system that:

Manages courses efficiently
Defines prerequisite relationships
Automatically generates a valid semester-wise plan

🌍 3. Real-world Application
University course scheduling systems
Academic advising tools
Curriculum planning software
Online learning platforms
Certification pathway planners

👉 Especially useful when courses have dependencies (prerequisites)

🧩 4. Data Structures Used
Graph (Adjacency Matrix Representation)
Each course = Vertex (Node)
Each prerequisite = Directed Edge
Why Graph?
Naturally models dependencies
Supports ordering using algorithms like Topological Sort
Efficient for prerequisite validation
Structures Used:
typedef struct {
    int id;
    char name[50];
    int active;
} Course;
int adj[MAX][MAX];      // Adjacency matrix
int indegree[MAX];      // Number of prerequisites

🏗️ 5. System Design

The system is menu-driven and includes:

Add Course
Update Course
Delete Course
List Courses
Add Prerequisite
Generate Semester Plan
Flow:

User Input → Menu → Graph Operation → Topological Sort → Semester Output

⚙️ 6. Algorithm
➤ Add Course
Input course ID and name
Check for duplicate ID
Insert into course list
Initialize adjacency row
➤ Delete Course
Input course ID
Mark course as inactive
Remove all edges related to it
➤ Add Prerequisite
Input prerequisite course ID (u)
Input dependent course ID (v)
Add edge: u → v
Increase indegree of v
➤ Topological Sort (Kahn’s Algorithm)
Find all courses with indegree = 0
Add them to queue
Remove from queue one by one
Reduce indegree of neighbors
Repeat until queue is empty
If all courses processed → valid order
Else → cycle exists
➤ Semester Planning
Use topological order
Assign semester = 1 for all courses
For each edge u → v:
semester[v] = semester[u] + 1 (if greater)
Group courses by semester

💻 7. Implementation
Language: C
Concepts used:
struct
Arrays (Adjacency Matrix)
Graph algorithms
Topological Sorting
Queue (array-based)
Menu-driven program
Key Functions:
addCourse()
updateCourse()
deleteCourse()
addPrerequisite()
topologicalSort()
semesterPlanner()

🖥️ 8. Demo Output
--- COURSE PLANNER SYSTEM ---
1. Add Course
2. Update Course
3. Delete Course
4. List Courses
5. Add Prerequisite
6. Semester Planner
7. Exit

Enter choice: 1
Enter course ID: 101
Enter course name: Math
Course added.

Enter choice: 1
Enter course ID: 102
Enter course name: Physics
Course added.

Enter choice: 5
Enter prerequisite course ID: 101
Enter dependent course ID: 102
Prerequisite added.

Enter choice: 6

Semester Plan:
Semester 1: Math
Semester 2: Physics

✅ 9. Conclusion
Successfully implemented a graph-based course planner
Demonstrated use of topological sorting for dependency resolution
Efficiently generates valid semester schedules
Helps avoid invalid course sequences

