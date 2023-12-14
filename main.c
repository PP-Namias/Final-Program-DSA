#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


#define MAX_SIZE 100

int array[MAX_SIZE];
int size = 0;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');
    getchar(); 
}

void displayMenu() {
    printf("********** MENU **********\n");
    printf("1. One-Dimensional Array\n");
    printf("2. Two-Dimensional Array\n");
    printf("3. Stack Using Array\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void displayMenu1D() {
    printf("********** MENU **********\n");
    printf("One-Dimensional Array Menu:\n");
    printf("1. Array Index Composition\n");
    printf("2. Traverse\n");
    printf("3. Insert Sorted\n");
    printf("4. Insert Unsorted and Remove Element\n");
    printf("5. Merge Unsorted\n");
    printf("0. Back\n");
    printf("Enter your choice: ");
}

void displayMenu2D() {
    printf("********** MENU **********\n");
    printf("Two-Dimensional Array Menu\n");
    printf("1. Traverse\n");
    printf("2. Transpose\n");
    printf("0. Back\n");
    printf("Enter your choice: ");
}

void displayArray() {
    printf("ELEMENTS INSIDE THE ARRAY ARE: { ");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

void arrayIndexComposition() {
    clearScreen();
    printf("[ Array Index Composition Has Been Selected ]\n");

    int index;

    printf("ENTER ARRAY INDEX: ");
    scanf("%d", &index);

    if (index < 0 || index >= MAX_SIZE) {
        printf("Invalid index. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }

    printf("\n ENTER ELEMENTS OF AN ARRAY [%d]: ", index);

    for (int i = 0; i <= index; ++i) {
        printf("\n ENTER ELEMENTS OF AN ARRAY [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    size = index + 1;
    displayArray();
}

void traverse() {
    clearScreen();
    printf("[ Traverse Has Been Selected ]\n");

    int elements;

    printf("ENTER ELEMENTS OF AN ARRAY: ");
    scanf("%d", &elements);

    if (elements <= 0 || elements > MAX_SIZE) {
        printf("Invalid number of elements. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    printf("\n ENTER ELEMENTS OF AN ARRAY [%d]: ", elements);

    for (int i = 0; i < elements; ++i) {
        printf("\n ENTER ELEMENTS OF AN ARRAY [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    size = elements;
    displayArray();
}

void insertSorted() {
    clearScreen();
    printf("[ Insert Sorted Has Been Selected ]\n");

    int index;
    int item;

    printf("ENTER ARRAY INDEX: ");
    scanf("%d", &index);

    if (index < 0 || index >= MAX_SIZE) {
        printf("Invalid index. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }

    printf("\n ENTER SORTED ELEMENTS OF AN ARRAY [%d]: ", index);

    for (int i = 0; i <= index; ++i) {
        printf("\n ENTER SORTED ELEMENTS OF AN ARRAY [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    size = index + 1;

    displayArray();

    printf("\n ENTER ITEM VALUE TO INSERT: ");
    scanf("%d", &item);

    int i = size - 1;

    while (i >= 0 && array[i] > item) {
        array[i + 1] = array[i];
        i--;
    }

    array[i + 1] = item;
    size++;

    displayArray();
}

void insertUnsortedAndRemoveElement() {
    clearScreen();
    printf("[ Insert Unsorted and Remove Element Has Been Selected ]\n");

    int index;

    printf("ENTER ARRAY INDEX: ");
    scanf("%d", &index);

    if (index < 0 || index >= MAX_SIZE) {
        printf("Invalid index. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }

    printf("\nENTER UN-SORTED ELEMENTS OF AN ARRAY [%d]: ", index);

    for (int i = 0; i <= index; ++i) {
        printf("\nENTER UN-SORTED ELEMENTS OF AN ARRAY [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    size = index + 1;
    displayArray();

    int valueToInsert;

    printf("\nENTER VALUE TO INSERT: ");
    scanf("%d", &valueToInsert);

    // Insert value while keeping the array sorted
    int i = size - 1;
    while (i >= 0 && array[i] > valueToInsert) {
        array[i + 1] = array[i];
        i--;
    }

    array[i + 1] = valueToInsert;
    size++;

    displayArray();

    printf("\nENTER LOCATION TO REMOVE ELEMENT: ");
    int locationToRemove;
    scanf("%d", &locationToRemove);

    // Remove element at the specified location
    if (locationToRemove >= 1 && locationToRemove <= size) {
        for (int j = locationToRemove - 1; j < size - 1; ++j) {
            array[j] = array[j + 1];
        }
        size--;

        displayArray();
    } else {
        printf("Invalid location to remove element.\n");
    }
}

void mergeUnsorted() {
    clearScreen();
    printf("[ Merge Unsorted Has Been Selected ]\n");

    int indexA, indexB;

    printf("ENTER ARRAY INDEX A: ");
    scanf("%d", &indexA);

    if (indexA < 0 || indexA >= MAX_SIZE) {
        printf("Invalid index for Array A. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }

    printf("\n ENTER ELEMENTS OF ARRAY A [%d]: ", indexA);

    for (int i = 0; i <= indexA; ++i) {
        printf("\n ENTER ELEMENTS OF ARRAY A [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    int sizeA = indexA + 1;
    displayArray();

    printf("\n ENTER ARRAY INDEX B: ");
    scanf("%d", &indexB);

    if (indexB < 0 || indexB >= MAX_SIZE) {
        printf("Invalid index for Array B. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }

    printf("\n ENTER ELEMENTS OF ARRAY B [%d]: ", indexB);

    for (int i = 0; i <= indexB; ++i) {
        printf("\n ENTER ELEMENTS OF ARRAY B [%d]: ", i + 1);
        scanf("%d", &array[sizeA + i]);
    }

    int sizeB = indexB + 1;
    size = sizeA + sizeB;

    displayArray();
}

void traverse2DArray() {
    clearScreen();
    printf("[ Traverse 2D Array Has Been Selected ]\n");

    int rows, columns;

    printf("ENTER NUMBER OF ROWS: ");
    scanf("%d", &rows);
    if (rows <= 0 || rows > MAX_SIZE) {
        printf("Invalid number of rows. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    printf("ENTER NUMBER OF COLUMNS: ");
    scanf("%d", &columns);

    if (columns <= 0 || columns > MAX_SIZE) {
        printf("Invalid number of columns. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    int twoDArray[MAX_SIZE][MAX_SIZE];

    printf("\n2-D ARRAY BEFORE TRAVERSING:\n");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("\t%d", twoDArray[i][j]);
        }
        printf("\n");
    }

    printf("\n2-D ARRAY AFTER TRAVERSING:\n");

    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            printf("\t%d", twoDArray[i][j]);
        }
        printf("\n");
    }

    pause();
}

void transpose2DArray() {
    clearScreen();
    printf("[ Transpose 2D Array Has Been Selected ]\n");

    int rows, columns;

    printf("ENTER NUMBER OF ROWS: ");
    scanf("%d", &rows);

    if (rows <= 0 || rows > MAX_SIZE) {
        printf("Invalid number of rows. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    printf("ENTER NUMBER OF COLUMNS: ");
    scanf("%d", &columns);

    if (columns <= 0 || columns > MAX_SIZE) {
        printf("Invalid number of columns. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    int twoDArray[MAX_SIZE][MAX_SIZE];

    printf("\nENTER ELEMENTS OF 2-D ARRAY:\n");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            scanf("%d", &twoDArray[i][j]);
        }
    }

    printf("\n2-D ARRAY BEFORE TRANSPOSING:\n");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("\t%d", twoDArray[i][j]);
        }
        printf("\n");
    }

    printf("\n2-D ARRAY AFTER TRANSPOSING:\n");

    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            printf("\t%d", twoDArray[i][j]);
        }
        printf("\n");
    }

    pause();
}

void stackUsingArray() {
    clearScreen();
    printf("[ Stack Using Array Has Been Selected ]\n");

    int stack[MAX_SIZE];
    int top = -1;
    int option, value;

    do {
        printf("\nSTACK USING ARRAY\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("\nENTER OPTION: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("INPUT VALUE: ");
                scanf("%d", &value);
                if (top == MAX_SIZE - 1) {
                    printf("Stack Overflow! Cannot push more elements.\n");
                } else {
                    top++;
                    stack[top] = value;
                    printf("VALUE INSERTED = { ");
                    for (int i = 0; i <= top; ++i) {
                        printf("%d", stack[i]);
                        if (i < top) {
                            printf(", ");
                        }
                    }
                    printf(" }\n");
                }
                break;
            case 2:
                if (top == -1) {
                    printf("Stack Underflow! Cannot pop from an empty stack.\n");
                } else {
                    printf("VALUE POPPED = { %d }\n", stack[top]);
                    top--;
                }
                break;
            case 3:
                if (top == -1) {
                    printf("The stack is empty.\n");
                } else {
                    printf("ITEMS INSIDE THE STACK: { ");
                    for (int i = 0; i <= top; ++i) {
                        printf("%d", stack[i]);
                        if (i < top) {
                            printf(", ");
                        }
                    }
                    printf(" }\n");
                }
                break;
            case 4:
                printf("\nExiting the stack program. Returning to the main menu.\n");
                break;
            default:
                printf("Invalid option. Please enter a number between 1 and 4.\n");
        }
    } while (option != 4);

    pause();
}

int main() {
    int choice;

    do {
        clearScreen();
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arrayIndexComposition();
                break;
            case 2:
                traverse();
                break;
            case 3:
                insertSorted();
                break;
            case 4:
                insertUnsortedAndRemoveElement();
                break;
            case 5:
                mergeUnsorted();
                break;
            case 6:
                traverse2DArray();
                break;
            case 7:
                transpose2DArray();
                break;
            case 8:
                stackUsingArray();
                break;
            case 9:
                printf("\nExiting the program! Thank you!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 9.\n");
                pause();
                break;
        }

    } while (choice != 9);

    return 0;
}










// 1-D Array Function Declarations
void arrayIndexComposition();
void traverse(int a[], int n);
void insertSorted();
void insertUnsortedRemoveElement();
void mergeUnsorted();
void traverse2D();
void transpose2D();
void mergeUnsortedArrays(int a[], int m, int b[], int n, int c[]);

// 2-D Array Function Declarations
void traverse2DArray(int a[MAX][MAX], int m, int n);
void transpose2DArray(int a[MAX][MAX], int b[MAX][MAX], int m, int n);

// issue function declarations
void insertUnsorted(int a[], int *n, int item);
void detach(int a[], int *n, int loc);

// Menu function declarations
void oneDimensionalArrayMenu();
void twoDimensionalArrayMenu();

// Stack function declarations
void stackUsingArray();
void pushStack(int stack[], int *top, int item);
void popStack(int stack[], int *top);
void displayStack(int stack[], int top);

// Main Menu

int main() {
    int choice;
    int a[MAX]; // Declare an array to be used in traverse function
    int n;      // Declare a variable to store the size of the array
    
    do {
        system("cls");
        printf("Main Menu\n");
        printf("1. One-Dimensional Array\n");
        printf("2. Two-Dimensional Array\n");
        printf("3. Stack Using Array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                oneDimensionalArrayMenu();
                break;
            case 2:
                twoDimensionalArrayMenu();
                break;
            case 3:
                stackUsingArray();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

// Selection Menu for One-Dimensional Array:

void oneDimensionalArrayMenu() {
    int choice;

    do {
        system("cls");
        printf("One-Dimensional Array Menu:\n");
        printf("1. Array Index Composition\n");
        printf("2. Traverse\n");
        printf("3. Insert Sorted\n");
        printf("4. Insert Unsorted and Remove Element\n");
        printf("5. Merge Unsorted\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arrayIndexComposition();
                break;
            case 2:
                traverse(a, n);
                break;
            case 3:
                insertSorted();
                break;
            case 4:
                insertUnsortedAndRemoveElement();
                break;
            case 5:
                mergeUnsorted();
                break;
            case 0:
                printf("Going back to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
}

// Selection Menu for Two-Dimensional Array:

void twoDimensionalArrayMenu() {
    int choice;

    do {
        system("cls");
        printf("Two-Dimensional Array Menu\n");
        printf("1. Traverse\n");
        printf("2. Transpose\n");
        printf("0. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                twoDimensionalArrayTraverse();
                break;
            case 2:
                twoDimensionalArrayTranspose();
                break;
            case 0:
                printf("Going back to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
}


















// Function definitions

void arrayIndexComposition() {
    int i, n, a[MAX];

    printf("\n ENTER ARRAY INDEX: ");
    scanf("%d", &n);

    printf("\n ENTER ELEMENTS OF AN ARRAY: ");
    for (i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i <= n; i++) {
        printf("\n ELEMENTS INSIDE THE ARRAY ARE: %d", a[i]);
    }
}

void traverse(int a[], int n) {
    int i;

    printf("\n ENTER ELEMENTS OF AN ARRAY: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n\n ELEMENTS INSIDE THE ARRAY ARE: ");
    for (i = 0; i < n; i++) {
        printf(" %d", a[i]);
    }
}

void insertSorted() {
    int i, n, a[MAX], item, restart;

    printf("\n ENTER ARRAY INDEX: ");
    scanf("%d", &n);

    printf("\n ENTER SORTED ELEMENTS OF AN ARRAY: \n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n\n ELEMENTS INSIDE THE ARRAY ARE: ");
    for (i = 1; i <= n; i++) {
        printf(" %d", a[i]);
    }

    printf("\n ENTER ITEM VALUE TO INSERT: ");
    scanf("%d", &item);

    insertSorted();

    printf("\n\n ELEMENTS AFTER INSERTION: ");
    for (i = 1; i <= n; i++) {
        printf(" %d", a[i]);
    }

    printf("\n\n PRESS 1 TO RESTART PROGRAM | PRESS ANY KEY TO TERMINATE PROGRAM:");
    scanf("%d", &restart);

    if (restart == 1) {
        arrayIndexComposition();  // Restarting with the first function
    } else {
        printf("\n PROGRAM TERMINATED!");
    }
}

void insertUnsortedRemoveElement() {
    int i, n, loc, val, restart, a[MAX];

    printf("\n ENTER ARRAY INDEX: ");
    scanf("%d", &n);

    printf("\n ENTER SORTED ELEMENTS OF AN ARRAY: \n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    traverse(a, n);

    printf("\n ENTER VALUE TO INSERT: ");
    scanf("%d", &val);

    insertSorted();

    printf("\n NEW ELEMENTS OF ARRAY IN SORTED MANNER");
    traverse(a, n);

    printf("\n\n INPUT LOCATION INDEX TO INSERT: ");
    scanf("%d", &loc);

    printf("\n ENTER VALUE TO INSERT: ");
    scanf("%d", &val);

    insertUnsorted(a, &n, val);

    printf("\n NEW ELEMENTS OF ARRAY IN SORTED MANNER");
    traverse(a, n);

    printf("\n\n ENTER LOCATION TO REMOVE ELEMENT: ");
    scanf("%d", &loc);

    detach(a, &n, loc);

    printf("\n NEW ELEMENTS OF ARRAY IN SORTED MANNER");
    traverse(a, n);

    printf("\n\n RESTART THE PROGRAM?");
    printf("\n PRESS 1 TO RESTART - INPUT ANY VALUE TO TERMINATE: ");
    scanf("%d", &restart);

    if (restart == 1) {
        arrayIndexComposition();  // Restarting with the first function
    } else {
        printf("\n\n PROGRAM TERMINATED!");
    }
}

void mergeUnsorted() {
    int a[MAX], b[MAX], c[MAX * 2], m, n, i;

    printf("\n ENTER ARRAY INDEX A: ");
    scanf("%d", &m);

    printf("\n ENTER ELEMENTS OF ARRAY A: \n");
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n ENTER ARRAY INDEX B: ");
    scanf("%d", &n);

    printf("\n ENTER ELEMENTS OF ARRAY B: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    mergeUnsortedArrays(a, m, b, n, c);

    printf("\n\n NEW ELEMENTS AFTER MERGING: ");
    for (i = 0; i < m + n; i++) {
        printf("\n %d", c[i]);
    }
}

void mergeUnsortedArrays(int a[], int m, int b[], int n, int c[]) {
    int i, j, k = 0;

    for (i = 0; i < m; i++) {
        c[i] = a[i];
    }

    for (j = m; j < m + n; j++) {
        c[j] = b[k];
        k = k + 1;
    }
}

void traverse2D() {
    int a[MAX][MAX], m, n, i, j;

    printf("\n ENTER NUMBER OF ROWS AND COLUMNS: ");
    scanf("%d %d", &m, &n);

    printf("\n INPUT ELEMENTS OF 2-D ARRAY:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("\n\n 2-D ARRAY BEFORE TRAVERSING:\n\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n\n");
    }

    traverse2DArray(a, m, n);

    printf("\n\n 2-D ARRAY AFTER TRAVERSING:\n\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n\n");
    }
    getch();
}

void traverse2DArray(int a[MAX][MAX], int m, int n) {
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = a[i][j];
        }
    }
}

void transpose2D() {
    int a[MAX][MAX], b[MAX][MAX], m, n, i, j;

    printf("\n ENTER NUMBER OF ROWS: ");
    scanf("%d", &m);

    printf("\n ENTER NUMBER OF COLUMNS: ");
    scanf("%d", &n);

    printf("\n ENTER ELEMENTS OF 2-D ARRAY: \n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("\n\n 2-D ARRAY BEFORE TRANSPOSING: \n\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%d", a[i][j]);
        }
        printf("\n\n");
    }

    transpose2DArray(a, b, m, n);

    printf("\n\n 2-D ARRAY AFTER TRANSPOSING: \n\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("\t%d", b[i][j]);
        }
        printf("\n\n");
    }
    getch();
}

void transpose2DArray(int a[MAX][MAX], int b[MAX][MAX], int m, int n) {
    int i, j;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            b[j][i] = a[i][j];
}

void stackUsingArray() {
    int choice;
    int stack[MAX], top = -1, item;

    do {
        printf("\n\n\t\t STACK USING ARRAY");

        printf("\n\t\t 1. PUSH");
        printf("\n\t\t 2. POP");
        printf("\n\t\t 3. DISPLAY");
        printf("\n\t\t 4. EXIT");

        printf("\n\n\t\t ENTER OPTION: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n\n\t\t INPUT VALUE: ");
                scanf("%d", &item);
                pushStack(stack, &top, item);
                break;
            case 2:
                popStack(stack, &top);
                break;
            case 3:
                displayStack(stack, top);
                break;
            case 4:
                printf("\nExiting the stack program. Returning to the main menu.");
                break;
            default:
                printf("\nInvalid option. Please try again.");
        }
    } while (choice != 4);
}

void pushStack(int stack[], int *top, int item) {
    if (*top == MAX - 1)
        printf("\n\n\t\t STACK IS FULL.");
    else {
        *top += 1;
        stack[*top] = item;
        printf("\n\n\t\t VALUE INSERTED = %d", item);
    }
}

void popStack(int stack[], int *top) {
    if (*top == -1)
        printf("\n\n\t\t STACK IS EMPTY.");
    else {
        int poppedItem = stack[*top];
        *top -= 1;
        printf("\n\n\t\t VALUE POPPED = %d", poppedItem);
    }
}

// Function to insert an element into an unsorted array
void insertUnsorted(int a[], int *n, int item) {
    if (*n == MAX - 1) {
        printf("\n\n\t\t ARRAY IS FULL. CANNOT INSERT ELEMENT.");
    } else {
        *n += 1;
        a[*n] = item;
        printf("\n\n\t\t VALUE INSERTED = %d", item);
    }
}

// Function to remove an element from an unsorted array
void detach(int a[], int *n, int loc) {
    if (*n == -1) {
        printf("\n\n\t\t ARRAY IS EMPTY. CANNOT REMOVE ELEMENT.");
    } else if (loc < 0 || loc > *n) {
        printf("\n\n\t\t INVALID LOCATION. CANNOT REMOVE ELEMENT.");
    } else {
        printf("\n\n\t\t VALUE REMOVED = %d", a[loc]);
        for (int i = loc; i < *n; i++) {
            a[i] = a[i + 1];
        }
        *n -= 1;
    }
}

// Function to display the elements of the stack
void displayStack(int stack[], int top) {
    if (top == -1) {
        printf("\n\n\t\t STACK EMPTY.");
    } else {
        int i;
        printf("\n\n\t\t ITEMS INSIDE THE STACK");
        for (i = top; i >= 0; i--) {
            printf("\n\t\t\t %d", stack[i]);
        }
    }
}


// Archived:

// Main Menu
// do {
    //     printf("\n\n********** MENU **********");
    //     printf("\n1. Array Index Composition");
    //     printf("\n2. Traverse");
    //     printf("\n3. Insert Sorted");
    //     printf("\n4. Insert Unsorted and Remove Element");
    //     printf("\n5. Merge Unsorted");
    //     printf("\n6. Traverse 2D Array");
    //     printf("\n7. Transpose 2D Array");
    //     printf("\n8. Stack Using Array");
    //     printf("\n9. Exit");
    //     printf("\n\nEnter your choice (1-9): ");
    //     scanf("%d", &choice);

    //     switch(choice) {
    //         case 1:
    //             arrayIndexComposition();
    //             break;
    //         case 2:
    //             traverse(a, n);
    //             break;
    //         case 3:
    //             insertSorted();
    //             break;
    //         case 4:
    //             insertUnsortedRemoveElement();
    //             break;
    //         case 5:
    //             mergeUnsorted();
    //             break;
    //         case 6:
    //             traverse2D();
    //             break;
    //         case 7:
    //             transpose2D();
    //             break;
    //         case 8:
    //             stackUsingArray();
    //             break;
    //         case 9:
    //             printf("\nExiting the program. Goodbye!");
    //             exit(0);
    //         default:
    //             printf("\nInvalid choice. Please enter a number between 1 and 9.");
    //     }

    //     printf("\n\nPress any key to continue...");
    //     getch(); // Wait for a key press before displaying the menu again

    // } while(1); // Infinite loop to keep the program running until the user chooses to exit