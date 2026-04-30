#include <stdio.h>
#include <string.h>

#define MAX 50
#define MAX_NAME 50

typedef struct {
    int id;
    char name[MAX_NAME];
    int active;
} Course;

Course courses[MAX];
int adj[MAX][MAX];
int indegree[MAX];
int n = 0;

int findCourseIndex(int id) {
    for (int i = 0; i < n; i++) {
        if (courses[i].active && courses[i].id == id) return i;
    }
    return -1;
}

void addCourse(int id, char name[]) {
    if (findCourseIndex(id) != -1) {
        printf("Course ID already exists.\n");
        return;
    }
    courses[n].id = id;
    strcpy(courses[n].name, name);
    courses[n].active = 1;
    for (int i = 0; i < MAX; i++) adj[n][i] = 0;
    n++;
    printf("Course added.\n");
}

void updateCourse(int id, char name[]) {
    int idx = findCourseIndex(id);
    if (idx == -1) {
        printf("Course not found.\n");
        return;
    }
    strcpy(courses[idx].name, name);
    printf("Course updated.\n");
}

void deleteCourse(int id) {
    int idx = findCourseIndex(id);
    if (idx == -1) {
        printf("Course not found.\n");
        return;
    }
    courses[idx].active = 0;
    for (int i = 0; i < n; i++) {
        adj[idx][i] = 0;
        adj[i][idx] = 0;
    }
    printf("Course deleted.\n");
}

void listCourses() {
    printf("\nCourses:\n");
    for (int i = 0; i < n; i++) {
        if (courses[i].active)
            printf("ID: %d  Name: %s\n", courses[i].id, courses[i].name);
    }
}

void addPrerequisite(int prereqId, int courseId) {
    int u = findCourseIndex(prereqId);
    int v = findCourseIndex(courseId);
    if (u == -1 || v == -1) {
        printf("Invalid course ID.\n");
        return;
    }
    if (!adj[u][v]) {
        adj[u][v] = 1;
        indegree[v]++;
    }
    printf("Prerequisite added.\n");
}

int topologicalSort(int order[]) {
    int tempIndegree[MAX];
    int queue[MAX], front = 0, rear = 0, count = 0;

    for (int i = 0; i < n; i++) tempIndegree[i] = indegree[i];

    for (int i = 0; i < n; i++) {
        if (courses[i].active && tempIndegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int u = queue[front++];
        order[count++] = u;

        for (int v = 0; v < n; v++) {
            if (courses[v].active && adj[u][v]) {
                tempIndegree[v]--;
                if (tempIndegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    return count == n;
}

void semesterPlanner() {
    int order[MAX];
    if (!topologicalSort(order)) {
        printf("Cycle detected. Semester plan not possible.\n");
        return;
    }

    int semester[MAX];
    for (int i = 0; i < MAX; i++) semester[i] = 1;

    for (int i = 0; i < n; i++) {
        int u = order[i];
        for (int v = 0; v < n; v++) {
            if (courses[v].active && adj[u][v]) {
                if (semester[v] < semester[u] + 1)
                    semester[v] = semester[u] + 1;
            }
        }
    }

    printf("\nSemester Plan:\n");
    for (int s = 1; s <= n; s++) {
        int found = 0;
        printf("Semester %d: ", s);
        for (int i = 0; i < n; i++) {
            if (courses[i].active && semester[i] == s) {
                printf("%s ", courses[i].name);
                found = 1;
            }
        }
        if (found) printf("\n");
    }
}

int main() {
    int choice, id, prereq;
    char name[MAX_NAME];

    while (1) {
        printf("\n1.Add Course\n2.Update Course\n3.Delete Course\n4.List Courses\n5.Add Prerequisite\n6.Semester Planner\n7.Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter course ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter course name: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0;
                addCourse(id, name);
                break;
            case 2:
                printf("Enter course ID: ");
                scanf("%d", &id);
                getchar();
                printf("Enter new course name: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0;
                updateCourse(id, name);
                break;
            case 3:
                printf("Enter course ID: ");
                scanf("%d", &id);
                deleteCourse(id);
                break;
            case 4:
                listCourses();
                break;
            case 5:
                printf("Enter prerequisite course ID: ");
                scanf("%d", &prereq);
                printf("Enter dependent course ID: ");
                scanf("%d", &id);
                addPrerequisite(prereq, id);
                break;
            case 6:
                semesterPlanner();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
