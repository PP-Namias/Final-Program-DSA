/*
 * Group 4
 *  Title	: Data Structures and Algorithms Final Program
 *  Author  : @PP-Namias, @Kurosawa-Z, @27Ronan, @Meixii and @RensuGitHub
 *  Date	: December 15, 2023
 * 
 *  Members :
 *  Valencia, Ronan Renz
 *  Fungo, Gian
 *  Capalac, Garvy
 *  Llanes, Kevin 
 *  Namias, Jhon Keneth
 * 
 *  https://github.com/PP-Namias/Final-Program-DSA
*/

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

void clearArray() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        array[i] = 0; 
    }
}

void pause() {
    printf("Press any key to continue...\n");
    getchar();
    getchar();
}

void displayMenu() {
    printf("********** MENU **********\n");
    printf("[ 1 ] One-Dimensional Array\n");
    printf("[ 2 ] Two-Dimensional Array\n");
    printf("[ 3 ] Stack Using Array\n");
    printf("[ 0 ] Exit\n");
    printf("Enter your choice: ");
}

void displayMenu1D() {
    int choice;

    clearScreen();

    do {
        printf("********** MENU **********\n");
        printf("One-Dimensional Array Menu:\n");
        printf("[ 1 ] Array Index Composition\n");
        printf("[ 2 ] Traverse\n");
        printf("[ 3 ] Insert Sorted\n");
        printf("[ 4 ] Insert Unsorted and Remove Element\n");
        printf("[ 5 ] Merge Unsorted\n");
        printf("[ 0 ] Back\n");
        printf("Enter your choice: ");

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
            case 0:
                printf("\nExiting the program! Thank you!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 9.\n");
                pause();
                break;
        }
    } while (choice != 0);
    clearScreen();

}

void displayMenu2D() {
    int choice;

    clearScreen();
    
    do {
        printf("********** MENU **********\n");
        printf("Two-Dimensional Array Menu\n");
        printf("[ 1 ] Traverse\n");
        printf("[ 2 ] Transpose\n");
        printf("[ 0 ] Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse2DArray();
                break;
            case 2:
                transpose2DArray();
                break;
            case 0:
                printf("Going back to Main Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
    clearScreen();

}

void displayArray() {
    printf("\n ELEMENTS INSIDE THE ARRAY ARE: { ");
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" }\n\n ");
}

void arrayIndexComposition() {
    clearScreen();
    printf("[ Array Index Composition Has Been Selected ]\n");

    int index;

    printf(" ENTER ARRAY INDEX: ");
    scanf("%d", &index);

    if (index < 0 || index >= MAX_SIZE) {
        printf(" Invalid index. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }


    for (int i = 0; i <= index - 1; ++i) {
        printf("\n ENTER ELEMENTS OF AN ARRAY [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    size = index;
    displayArray();

    pause();
    
    clearArray();

    clearScreen();
}

void traverse() {
    clearScreen();
    printf("[ Traverse Has Been Selected ]\n");

    int elements;

    printf(" ENTER ELEMENTS OF AN ARRAY: ");
    scanf("%d", &elements);

    if (elements <= 0 || elements > MAX_SIZE) {
        printf(" Invalid number of elements. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    for (int i = 0; i < elements; ++i) {
        printf("\n ENTER ELEMENTS OF AN ARRAY [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    size = elements;
    displayArray();

    pause();

    clearArray();

    clearScreen();
}

void insertSorted() {
    clearScreen();
    printf("[ Insert Sorted Has Been Selected ]\n");

    int index;
    int item;

    printf(" ENTER ARRAY INDEX: ");
    scanf("%d", &index);

    if (index < 0 || index >= MAX_SIZE) {
        printf(" Invalid index. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }

    for (int i = 0; i <= index - 1; ++i) {
        printf("\n ENTER SORTED ELEMENTS OF AN ARRAY [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    size = index;

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

    pause();
    
    clearArray();

    clearScreen();
}

void insertUnsortedAndRemoveElement() {
    clearScreen();
    printf("[ Insert Unsorted and Remove Element Has Been Selected ]\n");

    int index;

    printf(" ENTER ARRAY INDEX: ");
    scanf("%d", &index);

    if (index < 0 || index >= MAX_SIZE) {
        printf(" Invalid index. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }

    for (int i = 0; i <= index -1; ++i) {
        printf("\n ENTER UN-SORTED ELEMENTS OF AN ARRAY [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    size = index;
    displayArray();

    int valueToInsert;

    printf("\n ENTER VALUE TO INSERT: ");
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

    printf("\n ENTER LOCATION TO REMOVE ELEMENT: ");
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
        printf(" Invalid location to remove element.\n");
    }

    pause();

    clearArray();

    clearScreen();
}

void mergeUnsorted() {
    clearScreen();
    printf("[ Merge Unsorted Has Been Selected ]\n");

    int indexA, indexB;

    printf(" ENTER ARRAY INDEX A: ");
    scanf("%d", &indexA);

    if (indexA < 0 || indexA >= MAX_SIZE) {
        printf(" Invalid index for Array A. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }

    for (int i = 0; i <= indexA - 1; ++i) {
        printf("\n ENTER ELEMENTS OF ARRAY A [%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    int sizeA = indexA;
    displayArray();

    printf("\n ENTER ARRAY INDEX B: ");
    scanf("%d", &indexB);

    if (indexB < 0 || indexB >= MAX_SIZE) {
        printf(" Invalid index for Array B. Please choose a valid index between 0 and %d.\n", MAX_SIZE - 1);
        return;
    }

    for (int i = 0; i <= indexB - 1; ++i) {
        printf("\n ENTER ELEMENTS OF ARRAY B [%d]: ", i + 1);
        scanf("%d", &array[sizeA + i]);
    }

    int sizeB = indexB;
    size = sizeA + sizeB;

    displayArray();

    pause();

    clearArray();

    clearScreen();
}

void traverse2DArray() {
    clearScreen();
    printf("[ Traverse 2D Array Has Been Selected ]\n");

    int rows, columns;

    printf(" ENTER NUMBER OF ROWS: ");
    scanf("%d", &rows);

    if (rows <= 0 || rows > MAX_SIZE) {
        printf(" Invalid number of rows. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    printf(" ENTER NUMBER OF COLUMNS: ");
    scanf("%d", &columns);

    if (columns <= 0 || columns > MAX_SIZE) {
        printf(" Invalid number of columns. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    int twoDArray[MAX_SIZE][MAX_SIZE];

    printf("\n ENTER ELEMENTS OF 2-D ARRAY:\n");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            scanf("%d", &twoDArray[i][j]);
        }
    }

    printf("\n 2-D ARRAY BEFORE TRAVERSING:\n");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("\t%d", twoDArray[i][j]);
        }
        printf("\n");
    }

    printf("\n 2-D ARRAY AFTER TRAVERSING:\n");

    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            printf("\t%d", twoDArray[i][j]);
        }
        printf("\n");
    }

    pause();

    clearArray();

    clearScreen();
}

void transpose2DArray() {
    clearScreen();
    printf("[ Transpose 2D Array Has Been Selected ]\n");

    int rows, columns;

    printf(" ENTER NUMBER OF ROWS: ");
    scanf("%d", &rows);

    if (rows <= 0 || rows > MAX_SIZE) {
        printf(" Invalid number of rows. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    printf(" ENTER NUMBER OF COLUMNS: ");
    scanf("%d", &columns);

    if (columns <= 0 || columns > MAX_SIZE) {
        printf(" Invalid number of columns. Please enter a number between 1 and %d.\n", MAX_SIZE);
        return;
    }

    int twoDArray[MAX_SIZE][MAX_SIZE];

    printf("\n ENTER ELEMENTS OF 2-D ARRAY:\n");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            scanf("%d", &twoDArray[i][j]);
        }
    }

    printf("\n 2-D ARRAY BEFORE TRANSPOSING:\n");

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("\t%d", twoDArray[i][j]);
        }
        printf("\n");
    }

    printf("\n 2-D ARRAY AFTER TRANSPOSING:\n");

    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            printf("\t%d", twoDArray[i][j]);
        }
        printf("\n");
    }

    pause();

    clearArray();

    clearScreen();
}

void stackUsingArray() {
    clearScreen();
    printf("[ Stack Using Array Has Been Selected ]\n");

    int stack[MAX_SIZE];
    int top = -1;
    int option, value;

    do {
        printf("\nSTACK USING ARRAY\n");
        printf(" [ 1 ] PUSH\n");
        printf(" [ 2 ] POP\n");
        printf(" [ 3 ] DISPLAY\n");
        printf(" [ 0 ] EXIT\n");
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
                    printf("VALUE INSERTED [%d] = { ", value);
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
                    printf("VALUE POPPED = [%d]\n", stack[top]);
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
            case 0:
                printf("\nExiting the stack program. Returning to the main menu.\n");
                break;
            default:
                printf("Invalid option. Please enter a number between 1 - 3 and 0.\n");
        }
    } while (option != 0);

    pause();
}

int main() {
    int choice;

    do {
        clearArray();
        clearScreen();
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu1D();
                break;
            case 2:
                displayMenu2D();
                break;
            case 3:
                stackUsingArray();
                break;
            case 0:
                printf("\nExiting the program! Thank you!\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 9.\n");
                pause();
                break;
        }

    } while (choice != 0);

    return 0;
}


/*

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

*/

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