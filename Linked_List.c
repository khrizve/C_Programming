#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node
struct Casper {
    int hauntingPower;            // Holds data
    struct Casper* nextBoo;       // Points to the next ghost
};

// Doubly Linked List Node
struct Banshee {
    int screamLevel;              // Holds data
    struct Banshee* leftWail;     // Points to the previous ghost
    struct Banshee* rightWail;    // Points to the next ghost
};

// Circular Linked List Node
struct Phantom {
    int spookiness;               // Holds data
    struct Phantom* spectralLoop;  // Points to the next ghost (circular)
};

// ============ Singly Linked List Functions ============

struct Casper* createCasper(int hauntingPower) {
    struct Casper* newGhost = (struct Casper*)malloc(sizeof(struct Casper));
    newGhost->hauntingPower = hauntingPower;
    newGhost->nextBoo = NULL;
    return newGhost;
}

void addCasper(struct Casper** hauntedHouse, int hauntingPower) {
    struct Casper* newGhost = createCasper(hauntingPower);
    newGhost->nextBoo = *hauntedHouse;
    *hauntedHouse = newGhost;
}

void addCasperInBetween(struct Casper** hauntedHouse, int newPower, int afterPower) {
    struct Casper* current = *hauntedHouse;

    while (current != NULL && current->hauntingPower != afterPower) {
        current = current->nextBoo;
    }

    if (current == NULL) {
        printf("No Casper with haunting power %d found!\n", afterPower);
        return;
    }

    struct Casper* newGhost = createCasper(newPower);
    newGhost->nextBoo = current->nextBoo;
    current->nextBoo = newGhost;
}

void deleteInBetweenCasper(struct Casper** hauntedHouse, int key) {
    struct Casper *prev = NULL, *current = *hauntedHouse;

    while (current != NULL && current->hauntingPower != key) {
        prev = current;
        current = current->nextBoo;
    }

    if (current == NULL) {
        printf("No Casper with haunting power %d found!\n", key);
        return;
    }

    if (prev == NULL) {  // Node to delete is the head
        *hauntedHouse = current->nextBoo;
    } else {
        prev->nextBoo = current->nextBoo;
    }
    free(current);
}

void deleteEntireCasper(struct Casper** hauntedHouse) {
    struct Casper* current = *hauntedHouse;
    while (current != NULL) {
        struct Casper* next = current->nextBoo;
        free(current);
        current = next;
    }
    *hauntedHouse = NULL;
    printf("Entire haunted house cleared!\n");
}

void displayCasper(struct Casper* hauntedHouse) {
    struct Casper* ghost = hauntedHouse;
    while (ghost != NULL) {
        printf("%d -> ", ghost->hauntingPower);
        ghost = ghost->nextBoo;
    }
    printf("NULL\n");
}

// ============ Doubly Linked List Functions ============

struct Banshee* createBanshee(int screamLevel) {
    struct Banshee* newWail = (struct Banshee*)malloc(sizeof(struct Banshee));
    newWail->screamLevel = screamLevel;
    newWail->leftWail = NULL;
    newWail->rightWail = NULL;
    return newWail;
}

void addBanshee(struct Banshee** graveyard, int screamLevel) {
    struct Banshee* newWail = createBanshee(screamLevel);
    newWail->rightWail = *graveyard;
    if (*graveyard != NULL)
        (*graveyard)->leftWail = newWail;
    *graveyard = newWail;
}

void addBansheeInBetween(struct Banshee** graveyard, int newLevel, int afterLevel) {
    struct Banshee* current = *graveyard;

    while (current != NULL && current->screamLevel != afterLevel) {
        current = current->rightWail;
    }

    if (current == NULL) {
        printf("No Banshee with scream level %d found!\n", afterLevel);
        return;
    }

    struct Banshee* newWail = createBanshee(newLevel);
    newWail->rightWail = current->rightWail;
    newWail->leftWail = current;
    current->rightWail = newWail;
    if (newWail->rightWail != NULL)
        newWail->rightWail->leftWail = newWail;
}

void deleteInBetweenBanshee(struct Banshee** graveyard, int key) {
    struct Banshee* current = *graveyard;

    while (current != NULL && current->screamLevel != key)
        current = current->rightWail;

    if (current == NULL) {
        printf("No Banshee with scream level %d found!\n", key);
        return;
    }

    if (current->leftWail != NULL)
        current->leftWail->rightWail = current->rightWail;

    if (current->rightWail != NULL)
        current->rightWail->leftWail = current->leftWail;

    if (current == *graveyard)  // If deleting the head
        *graveyard = current->rightWail;

    free(current);
}

void deleteEntireBanshee(struct Banshee** graveyard) {
    struct Banshee* current = *graveyard;
    while (current != NULL) {
        struct Banshee* next = current->rightWail;
        free(current);
        current = next;
    }
    *graveyard = NULL;
    printf("Entire graveyard cleared!\n");
}

void displayBanshee(struct Banshee* graveyard) {
    struct Banshee* current = graveyard;
    while (current != NULL) {
        printf("%d <-> ", current->screamLevel);
        current = current->rightWail;
    }
    printf("NULL\n");
}

// ============ Circular Linked List Functions ============

struct Phantom* createPhantom(int spookiness) {
    struct Phantom* newPhantom = (struct Phantom*)malloc(sizeof(struct Phantom));
    newPhantom->spookiness = spookiness;
    newPhantom->spectralLoop = NULL;
    return newPhantom;
}

void addPhantom(struct Phantom** ghostRealm, int spookiness) {
    struct Phantom* newPhantom = createPhantom(spookiness);
    if (*ghostRealm == NULL) {
        *ghostRealm = newPhantom;
        newPhantom->spectralLoop = *ghostRealm;
    } else {
        struct Phantom* temp = *ghostRealm;
        while (temp->spectralLoop != *ghostRealm)
            temp = temp->spectralLoop;
        temp->spectralLoop = newPhantom;
        newPhantom->spectralLoop = *ghostRealm;
    }
}

void addPhantomInBetween(struct Phantom** ghostRealm, int newSpookiness, int afterSpookiness) {
    struct Phantom* current = *ghostRealm;

    if (current == NULL) {
        printf("The ghost realm is empty!\n");
        return;
    }

    do {
        if (current->spookiness == afterSpookiness) {
            struct Phantom* newPhantom = createPhantom(newSpookiness);
            newPhantom->spectralLoop = current->spectralLoop;
            current->spectralLoop = newPhantom;
            return;
        }
        current = current->spectralLoop;
    } while (current != *ghostRealm);

    printf("Phantom with spookiness %d not found!\n", afterSpookiness);
}

void deleteInBetweenPhantom(struct Phantom** ghostRealm, int key) {
    if (*ghostRealm == NULL) {
        printf("The ghost realm is empty!\n");
        return;
    }

    struct Phantom *current = *ghostRealm, *prev = NULL;

    do {
        if (current->spookiness == key) {
            if (prev != NULL)
                prev->spectralLoop = current->spectralLoop;
            else {
                struct Phantom* temp = *ghostRealm;
                while (temp->spectralLoop != *ghostRealm)
                    temp = temp->spectralLoop;
                temp->spectralLoop = current->spectralLoop;
                *ghostRealm = current->spectralLoop;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->spectralLoop;
    } while (current != *ghostRealm);

    printf("Phantom with spookiness %d not found!\n", key);
}

void deleteEntirePhantom(struct Phantom** ghostRealm) {
    if (*ghostRealm == NULL) return;
    struct Phantom *current = *ghostRealm, *next;
    do {
        next = current->spectralLoop;
        free(current);
        current = next;
    } while (current != *ghostRealm);
    *ghostRealm = NULL;
    printf("Entire ghost realm cleared!\n");
}

void displayPhantom(struct Phantom* ghostRealm) {
    if (ghostRealm == NULL) {
        printf("The ghost realm is empty!\n");
        return;
    }
    struct Phantom* current = ghostRealm;
    do {
        printf("%d -> ", current->spookiness);
        current = current->spectralLoop;
    } while (current != ghostRealm);
    printf("(back to %d)\n", ghostRealm->spookiness);
}

// ============ Menu Functions ============

void menu() {
    printf("\n--- Ghostly Linked List Menu ---\n");
    printf("1. Singly Linked List (Casper)\n");
    printf("2. Doubly Linked List (Banshee)\n");
    printf("3. Circular Linked List (Phantom)\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void casperMenu(struct Casper** hauntedHouse) {
    int choice, hauntingPower, newPower, afterPower;

    while (1) {
        printf("\nSingly Linked List (Casper) Menu:\n");
        printf("1. Add Casper\n");
        printf("2. Add Casper in Between\n");
        printf("3. Delete Casper by haunting power\n");
        printf("4. Delete Entire Haunted House\n");
        printf("5. Display Haunted House\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter haunting power: ");
                scanf("%d", &hauntingPower);
                addCasper(hauntedHouse, hauntingPower);
                break;
            case 2:
                printf("Enter new haunting power: ");
                scanf("%d", &newPower);
                printf("Insert after haunting power: ");
                scanf("%d", &afterPower);
                addCasperInBetween(hauntedHouse, newPower, afterPower);
                break;
            case 3:
                printf("Enter haunting power to delete: ");
                scanf("%d", &hauntingPower);
                deleteInBetweenCasper(hauntedHouse, hauntingPower);
                break;
            case 4:
                deleteEntireCasper(hauntedHouse);
                break;
            case 5:
                displayCasper(*hauntedHouse);
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void bansheeMenu(struct Banshee** graveyard) {
    int choice, screamLevel, newLevel, afterLevel;

    while (1) {
        printf("\nDoubly Linked List (Banshee) Menu:\n");
        printf("1. Add Banshee\n");
        printf("2. Add Banshee in Between\n");
        printf("3. Delete Banshee by scream level\n");
        printf("4. Delete Entire Graveyard\n");
        printf("5. Display Graveyard\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter scream level: ");
                scanf("%d", &screamLevel);
                addBanshee(graveyard, screamLevel);
                break;
            case 2:
                printf("Enter new scream level: ");
                scanf("%d", &newLevel);
                printf("Insert after scream level: ");
                scanf("%d", &afterLevel);
                addBansheeInBetween(graveyard, newLevel, afterLevel);
                break;
            case 3:
                printf("Enter scream level to delete: ");
                scanf("%d", &screamLevel);
                deleteInBetweenBanshee(graveyard, screamLevel);
                break;
            case 4:
                deleteEntireBanshee(graveyard);
                break;
            case 5:
                displayBanshee(*graveyard);
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void phantomMenu(struct Phantom** ghostRealm) {
    int choice, spookiness, newSpookiness, afterSpookiness;

    while (1) {
        printf("\nCircular Linked List (Phantom) Menu:\n");
        printf("1. Add Phantom\n");
        printf("2. Add Phantom in Between\n");
        printf("3. Delete Phantom by spookiness\n");
        printf("4. Delete Entire Ghost Realm\n");
        printf("5. Display Ghost Realm\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter spookiness: ");
                scanf("%d", &spookiness);
                addPhantom(ghostRealm, spookiness);
                break;
            case 2:
                printf("Enter new spookiness: ");
                scanf("%d", &newSpookiness);
                printf("Insert after spookiness: ");
                scanf("%d", &afterSpookiness);
                addPhantomInBetween(ghostRealm, newSpookiness, afterSpookiness);
                break;
            case 3:
                printf("Enter spookiness to delete: ");
                scanf("%d", &spookiness);
                deleteInBetweenPhantom(ghostRealm, spookiness);
                break;
            case 4:
                deleteEntirePhantom(ghostRealm);
                break;
            case 5:
                displayPhantom(*ghostRealm);
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    int choice;
    struct Casper* hauntedHouse = NULL;
    struct Banshee* graveyard = NULL;
    struct Phantom* ghostRealm = NULL;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                casperMenu(&hauntedHouse);
                break;
            case 2:
                bansheeMenu(&graveyard);
                break;
            case 3:
                phantomMenu(&ghostRealm);
                break;
            case 4:
                deleteEntireCasper(&hauntedHouse);
                deleteEntireBanshee(&graveyard);
                deleteEntirePhantom(&ghostRealm);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
