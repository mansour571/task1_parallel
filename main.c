#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

void registerUser(struct User **users, int *userCount) {
    struct User newUser;
    printf("\nCreate an Account\n");
    printf("Enter a username: ");
    scanf("%s", newUser.username);
    printf("Enter a strong password: ");
    scanf("%s", newUser.password);

    // Reallocate memory for users array
    *users = (struct User *)realloc(*users, (*userCount + 1) * sizeof(struct User));
    if (*users == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Add the new user to the array
    (*userCount)++;
    (*users)[*userCount - 1] = newUser;

    printf("Registration successful!\n");
}

int loginUser(struct User *users, int userCount) {
    char username[50];
    char password[50];

    printf("\nLogin\n");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;  // Authentication successful
        }
    }

    return 0;  // Authentication failed
}

int main() {
    struct User *users = NULL;
    int userCount = 0;
    int choice;

    printf("Welcome to the User Registration and Login System\n");

    while (1) {
        printf("\nChoose an Option:\n");
        printf("1. Create an Account\n");
        printf("2. Log In\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(&users, &userCount);
                break;
            case 2:
                if (loginUser(users, userCount)) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;
            case 3:
                free(users);
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
