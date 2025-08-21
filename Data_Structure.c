//-----------------------------------------------------------------------------
//----------------------Movie ticket booking using BST-------------------------
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

// Define a node for the binary search tree
struct Node {
    int ticketNumber;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int ticketNumber) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->ticketNumber = ticketNumber;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new ticket into the tree (booking a ticket)
struct Node* bookTicket(struct Node* root, int ticketNumber) {
    if (root == NULL) {
        return createNode(ticketNumber);
    }
    if (ticketNumber < root->ticketNumber) {
        root->left = bookTicket(root->left, ticketNumber);
    } else if (ticketNumber > root->ticketNumber) {
        root->right = bookTicket(root->right, ticketNumber);
    } else {
        printf("Ticket %d is already booked!\n", ticketNumber);
    }
    return root;
}

// Function to check if a ticket is available
int isTicketAvailable(struct Node* root, int ticketNumber) {
    if (root == NULL) {
        return 1; // Ticket is available
    }
    if (ticketNumber < root->ticketNumber) {
        return isTicketAvailable(root->left, ticketNumber);
    } else if (ticketNumber > root->ticketNumber) {
        return isTicketAvailable(root->right, ticketNumber);
    }
    return 0; // Ticket is booked
}

// Function to display all booked tickets in ascending order (in-order traversal)
void displayBookedTickets(struct Node* root) {
    if (root != NULL) {
        displayBookedTickets(root->left);
        printf("Ticket %d\n", root->ticketNumber);
        displayBookedTickets(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, ticketNumber;

    while (1) {
        printf("\nCinema Ticket Booking System\n");
        printf("1. Book a Ticket\n");
        printf("2. Check Ticket Availability\n");
        printf("3. Display All Booked Tickets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ticket number to book: ");
                scanf("%d", &ticketNumber);
                if (isTicketAvailable(root, ticketNumber)) {
                    root = bookTicket(root, ticketNumber);
                    printf("Ticket %d successfully booked.\n", ticketNumber);
                } else {
                    printf("Ticket %d is already booked.\n", ticketNumber);
                }
                break;
            case 2:
                printf("Enter ticket number to check availability: ");
                scanf("%d", &ticketNumber);
                if (isTicketAvailable(root, ticketNumber)) {
                    printf("Ticket %d is available.\n", ticketNumber);
                } else {
                    printf("Ticket %d is already booked.\n", ticketNumber);
                }
                break;
            case 3:
                printf("Booked Tickets in Ascending Order:\n");
                displayBookedTickets(root);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}



//------------------------------------------------------------------------
//----------------------Taxi Queue using Circular queue-------------------
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum number of taxis in the queue

// Circular Queue structure
struct CircularQueue {
    int taxis[MAX];
    int front, rear;
};

// Initialize the queue
void initializeQueue(struct CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Add a taxi to the queue
void enqueue(struct CircularQueue* queue, int taxiID) {
    if (isFull(queue)) {
        printf("Queue is full. Taxi %d cannot join the queue.\n", taxiID);
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->taxis[queue->rear] = taxiID;
    printf("Taxi %d joined the queue.\n", taxiID);
}

// Remove a taxi from the queue (taxi assigned to a customer)
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No taxis available.\n");
        return -1;
    }
    int taxiID = queue->taxis[queue->front];
    if (queue->front == queue->rear) {
        // Queue is now empty
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    printf("Taxi %d has been assigned to a customer.\n", taxiID);
    return taxiID;
}

// Display all taxis in the queue
void displayQueue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("No taxis in the queue.\n");
        return;
    }
    printf("Taxis in the queue: ");
    int i = queue->front;
    while (1) {
        printf("%d ", queue->taxis[i]);
        if (i == queue->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    int choice, taxiID;

    while (1) {
        printf("\nTaxi Queue System\n");
        printf("1. Add Taxi to Queue\n");
        printf("2. Assign Taxi to Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Taxi ID to add: ");
                scanf("%d", &taxiID);
                enqueue(&queue, taxiID);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}




//------------------------------------------------------------------------
//------------------Patient Management using linked list------------------
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store patient information
struct Patient {
    int id;
    char name[50];
    int age;
    struct Patient* next;
};

// Function to create a new patient node
struct Patient* createPatient(int id, char name[], int age) {
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->age = age;
    newPatient->next = NULL;
    return newPatient;
}

// Function to add a patient to the list
void addPatient(struct Patient** head, int id, char name[], int age) {
    struct Patient* newPatient = createPatient(id, name, age);
    newPatient->next = *head;
    *head = newPatient;
    printf("Patient %s (ID: %d) added to the system.\n", name, id);
}

// Function to remove a patient from the list by name
void removePatient(struct Patient** head, char name[]) {
    struct Patient *temp = *head, *prev = NULL;

    // Check if the head node holds the patient's name
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        printf("Patient %s (ID: %d) has been discharged.\n", temp->name, temp->id);
        free(temp);
        return;
    }

    // Search for the patient by name, keeping track of previous node
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If patient was not found
    if (temp == NULL) {
        printf("Patient with name %s not found.\n", name);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    printf("Patient %s (ID: %d) has been discharged.\n", temp->name, temp->id);
    free(temp);
}

// Function to display all patients in the list
void displayPatients(struct Patient* head) {
    if (head == NULL) {
        printf("No patients in the system.\n");
        return;
    }

    printf("List of patients:\n");
    struct Patient* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Age: %d\n", current->id, current->name, current->age);
        current = current->next;
    }
}

// Main function
int main() {
    struct Patient* head = NULL;
    int choice, id, age;
    char name[50];

    while (1) {
        printf("\nHospital Patient Management System\n");
        printf("1. Add Patient\n");
        printf("2. Discharge Patient\n");
        printf("3. Display All Patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter patient ID: ");
                scanf("%d", &id);
                printf("Enter patient name: ");
                scanf(" %[^\n]", name);  // To read string with spaces
                printf("Enter patient age: ");
                scanf("%d", &age);
                addPatient(&head, id, name, age);
                break;
            case 2:
                printf("Enter patient name to discharge: ");
                scanf(" %[^\n]", name);
                removePatient(&head, name);
                break;
            case 3:
                displayPatients(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}






//-------------------------------------------------------------------------------------
//-----------------------Restaurant order management using Linked list-----------------
//-------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store order information
struct Order {
    int orderID;
    char item[50];
    int quantity;
    struct Order* next;
};

// Function to create a new order node
struct Order* createOrder(int orderID, char item[], int quantity) {
    struct Order* newOrder = (struct Order*)malloc(sizeof(struct Order));
    newOrder->orderID = orderID;
    strcpy(newOrder->item, item);
    newOrder->quantity = quantity;
    newOrder->next = NULL;
    return newOrder;
}

// Function to add an order to the end of the list
void addOrder(struct Order** head, int orderID, char item[], int quantity) {
    struct Order* newOrder = createOrder(orderID, item, quantity);
    if (*head == NULL) {
        *head = newOrder;
    } else {
        struct Order* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newOrder;
    }
    printf("Order %d for %d x %s added to the list.\n", orderID, quantity, item);
}

// Function to process (remove) the first order in the list
void processOrder(struct Order** head) {
    if (*head == NULL) {
        printf("No orders to process.\n");
        return;
    }
    struct Order* temp = *head;
    *head = (*head)->next;
    printf("Processing Order %d: %d x %s\n", temp->orderID, temp->quantity, temp->item);
    free(temp);
}

// Function to display all orders in the list
void displayOrders(struct Order* head) {
    if (head == NULL) {
        printf("No orders in the list.\n");
        return;
    }

    printf("Current Orders:\n");
    struct Order* temp = head;
    while (temp != NULL) {
        printf("Order ID: %d, Item: %s, Quantity: %d\n", temp->orderID, temp->item, temp->quantity);
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Order* head = NULL;
    int choice, orderID, quantity;
    char item[50];

    while (1) {
        printf("\nRestaurant Order Management System\n");
        printf("1. Add Order\n");
        printf("2. Process Order\n");
        printf("3. Display All Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Order ID: ");
                scanf("%d", &orderID);
                printf("Enter item name: ");
                scanf(" %[^\n]", item);  // To read string with spaces
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                addOrder(&head, orderID, item, quantity);
                break;
            case 2:
                processOrder(&head);
                break;
            case 3:
                displayOrders(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}




//------------------------------------------------------------------------------
//----------------------------Browser History using Stack-----------------------
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define URL_LENGTH 256

// Define the Stack structure
typedef struct
{
    char history[MAX][URL_LENGTH]; // Array to store URLs
    int top;                       // Index of the top of the stack
} Stack;

// Initialize the stack
void init(Stack *stack)
{
    stack->top = -1;
}

// Push a URL onto the stack
void push(Stack *stack, const char *url)
{
    if (stack->top < MAX - 1)
    {
        stack->top++;
        strncpy(stack->history[stack->top], url, URL_LENGTH);
    }
    else
    {
        printf("History stack is full. Cannot visit a new page.\n");
    }
}

// Pop a URL from the stack
char *pop(Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->history[stack->top--];
    }
    else
    {
        return NULL;
    }
}

// Browser navigation system
typedef struct
{
    Stack history;                 // Stack for history
    char current_page[URL_LENGTH]; // Current page URL
} BrowserHistory;

// Initialize the browser history
void init_browser(BrowserHistory *browser)
{
    init(&browser->history);
    strcpy(browser->current_page, "No page currently open");
}

// Visit a new page
void visit_page(BrowserHistory *browser, const char *url)
{
    if (strlen(browser->current_page) > 0 && strcmp(browser->current_page, "No page currently open") != 0)
    {
        push(&browser->history, browser->current_page); // Push current page onto the stack
    }
    strncpy(browser->current_page, url, URL_LENGTH); // Set the new URL as the current page
    printf("Visited: %s\n", browser->current_page);
}

// Go back to the previous page
void go_back(BrowserHistory *browser)
{
    char *previous_page = pop(&browser->history);
    if (previous_page)
    {
        strncpy(browser->current_page, previous_page, URL_LENGTH);
        printf("Back to: %s\n", browser->current_page);
    }
    else
    {
        printf("No previous pages to go back to.\n");
    }
}

// Display the current page
void display_current_page(BrowserHistory *browser)
{
    printf("Current page: %s\n", browser->current_page);
}

// Main function to demonstrate the browser history navigation
int main()
{
    int choice;
    BrowserHistory browser;
    init_browser(&browser);
    while (1)
    {
        printf("\n1.Visited pages\n");
        printf("1.Go Back\n");
        printf("3.Display current page\n");
        printf("4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Visiting pages
            visit_page(&browser, "https://wikipedia.com");
            visit_page(&browser, "https://google.com");
            visit_page(&browser, "https://github.com");
            break;

        case 2:
            // Going back in history
            go_back(&browser);
            break;

        case 3:
            // Displaying the current page
            display_current_page(&browser);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice");
        }
    }

    return 0;
}


//---------------------------------------------------------
//--------------------------- END -------------------------
//---------------------------------------------------------
