#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 100

// Function declarations
void arrayIndexComposition();
void traverse();
void insertSorted();
void insertUnsortedRemoveElement();
void mergeUnsorted();
void traverse2D();
void transpose2D();
void stackUsingArray();

int main() {
    int choice;
    
    do {
        printf("\n\n********** MENU **********");
        printf("\n1. Array Index Composition");
        printf("\n2. Traverse");
        printf("\n3. Insert Sorted");
        printf("\n4. Insert Unsorted and Remove Element");
        printf("\n5. Merge Unsorted");
        printf("\n6. Traverse 2D Array");
        printf("\n7. Transpose 2D Array");
        printf("\n8. Stack Using Array");
        printf("\n9. Exit");
        printf("\n\nEnter your choice (1-9): ");
        scanf("%d", &choice);

        switch(choice) {
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
                insertUnsortedRemoveElement();
                break;
            case 5:
                mergeUnsorted();
                break;
            case 6:
                traverse2D();
                break;
            case 7:
                transpose2D();
                break;
            case 8:
                stackUsingArray();
                break;
            case 9:
                printf("\nExiting the program. Goodbye!");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 9.");
        }

        printf("\n\nPress any key to continue...");
        getch(); // Wait for a key press before displaying the menu again

    } while(1); // Infinite loop to keep the program running until the user chooses to exit

    return 0;
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

void traverse() {
    int i, n, a[MAX];

    printf("\n ENTER ARRAY INDEX: ");
    scanf("%d", &n);

    printf("\n ENTER ELEMENTS OF AN ARRAY: \n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n\n ELEMENTS INSIDE THE ARRAY ARE: ");
    for (i = 1; i <= n; i++) {
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

    traverse();

    printf("\n ENTER VALUE TO INSERT: ");
    scanf("%d", &val);

    insertSorted();

    printf("\n NEW ELEMENTS OF ARRAY IN SORTED MANNER");
    traverse();

    printf("\n\n INPUT LOCATION INDEX TO INSERT: ");
    scanf("%d", &loc);

    printf("\n ENTER VALUE TO INSERT: ");
    scanf("%d", &val);

    insertUnsorted();

    printf("\n NEW ELEMENTS OF ARRAY IN SORTED MANNER");
    traverse();

    printf("\n\n ENTER LOCATION TO REMOVE ELEMENT: ");
    scanf("%d", &loc);

    detach();

    printf("\n NEW ELEMENTS OF ARRAY IN SORTED MANNER");
    traverse();

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

void displayStack(int stack[], int top) {
    int i;
    printf("\n\n\t\t ITEMS INSIDE THE STACK");
    for (i = top; i >= 0; i--)
        printf("\n\t\t\t %d", stack[i]);

    if (top == -1)
        printf("\n\n\t\t STACK EMPTY.");
}
