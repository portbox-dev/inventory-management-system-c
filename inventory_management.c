/* Inventory Management System Program in C Language */
#include <stdio.h>

#define MAX_PRODUCTS 50
#define STARTING_ID 101

struct Product
{
    int id;
    char name[50];
    int qty;
    float price;
};

/* Function Prototypes */
void update(struct Product inventory[], int);
void add(struct Product inventory[], int *, int *);
void check(struct Product inventory[], int);
void rem(struct Product inventory[], int *);
void search(struct Product inventory[], int);
int findProduct(struct Product inventory[], int count, int searchId);
void loadData(struct Product inventory[], int *, int *);
void saveData(struct Product inventory[], int count, int nextid);
void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(void)
{
    struct Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice;
    int nextid = STARTING_ID;

    loadData(inventory, &count, &nextid);

    printf("=============================================\n");
    printf("Hello! Welcome to our Inventory Management System.");
    printf("\n=============================================\n");

    while (1)
    {
        printf("\n1) Check Inventory\n");
        printf("2) Update Inventory\n");
        printf("3) Add Item\n");
        printf("4) Remove Items\n");
        printf("5) Search Item by ID\n");
        printf("6) Exit\n");

        printf("\nWhat will you like to do? Enter your choice from the menu (1-6) : ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input! Please enter a number (1-6).\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
        case 1:
            check(inventory, count);
            break;

        case 2:
            update(inventory, count);
            saveData(inventory, count, nextid);
            break;

        case 3:
            add(inventory, &count, &nextid);
            saveData(inventory, count, nextid);
            break;

        case 4:
            rem(inventory, &count);
            saveData(inventory, count, nextid);
            break;

        case 5:
            search(inventory, count);
            break;

        case 6:
            saveData(inventory, count, nextid);
            printf("\n---- Thank You ----\n");
            return 0;

        default:
            printf("\nPlease select a valid option from the menu.\n");
            break;
        }
    }
}

// UPDATE FUNCTION
/* Function for updating any product details. */
void update(struct Product inventory[], int count)
{
    int choice;
    int found;
    int searchId;

    if (count == 0)
    {
        printf("\nNo item available to update.\n");
        return;
    }

    printf("\nEnter Item ID you want to update : ");

    if (scanf("%d", &searchId) != 1)
    {
        printf("Invalid ID input!\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    found = findProduct(inventory, count, searchId);

    if (found == -1)
    {
        printf("Item not found!\n");
        return;
    }

    printf("Item found!\n");
    printf("What do you want to update?\n");
    printf("1. Name\n");
    printf("2. Price\n");
    printf("3. Quantity\n");
    printf("Enter Choice (1-3) : ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid choice input!\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    switch (choice)
    {
    case 1:
        printf("Enter New Name = ");

        if (scanf(" %49[^\n]", inventory[found].name) != 1)
        {
            printf("Invalid name input!\n");
            clearInputBuffer();
            return;
        }

        clearInputBuffer();
        break;

    case 2:
        while (1)
        {
            printf("Enter New Price = Rs.");

            if (scanf("%f", &inventory[found].price) != 1)
            {
                printf("Invalid price input! Please enter a valid number.\n");
                clearInputBuffer();
                continue;
            }

            clearInputBuffer();

            if (inventory[found].price < 0)
            {
                printf("Price cannot be negative. Please try again.\n");
                continue;
            }

            break;
        }
        break;

    case 3:
        while (1)
        {
            printf("Enter New Quantity : ");

            if (scanf("%d", &inventory[found].qty) != 1)
            {
                printf("Invalid quantity input! Please enter a valid whole number.\n");
                clearInputBuffer();
                continue;
            }

            clearInputBuffer();

            if (inventory[found].qty < 0)
            {
                printf("Quantity cannot be negative. Please try again.\n");
                continue;
            }

            break;
        }
        break;

    default:
        printf("No option to update. Please select a correct option.\n");
        return;
    }

    printf("\nNew Updated Information :\n");
    printf("Product ID : %d\n", inventory[found].id);
    printf("Product Name : %s\n", inventory[found].name);
    printf("Product Price : Rs. %.2f\n", inventory[found].price);
    printf("Product Quantity : %d\n", inventory[found].qty);
}

// ADD FUNCTION
/* Function for adding products. */
void add(struct Product inventory[], int *count, int *nextid)
{
    int i = *count;
    int num;
    int added = 0;

    printf("\nHow many items do you want to add to your inventory?\n");

    if (scanf("%d", &num) != 1)
    {
        printf("Invalid input! Please enter a whole number.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    if (num <= 0)
    {
        printf("\nPlease enter a number greater than 0.\n");
        return;
    }

    if (*count + num > MAX_PRODUCTS)
    {
        printf("\nSorry! You can't add %d items.\n", num);
        printf("Only %d slot(s) are available.\n", MAX_PRODUCTS - *count);
        return;
    }

    while (added < num)
    {
        float price;
        int qty;

        inventory[i].id = *nextid;

        printf("\nEnter Product Name : ");

        if (scanf(" %49[^\n]", inventory[i].name) != 1)
        {
            printf("Invalid name input! Please try again.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        while (1)
        {
            printf("Enter Product Price : ");

            if (scanf("%f", &price) != 1)
            {
                printf("Invalid price input! Please enter a valid number.\n");
                clearInputBuffer();
                continue;
            }

            clearInputBuffer();

            if (price < 0)
            {
                printf("Price cannot be negative. Please try again.\n");
                continue;
            }

            break;
        }

        while (1)
        {
            printf("Enter Product Quantity : ");

            if (scanf("%d", &qty) != 1)
            {
                printf("Invalid quantity input! Please enter a valid whole number.\n");
                clearInputBuffer();
                continue;
            }

            clearInputBuffer();

            if (qty < 0)
            {
                printf("Quantity cannot be negative. Please try again.\n");
                continue;
            }

            break;
        }

        inventory[i].price = price;
        inventory[i].qty = qty;

        i++;
        (*count)++;
        (*nextid)++;
        added++;
    }

    printf("\n%d product(s) added to your Inventory.\n", added);
}

// CHECK FUNCTION
/* Function to print all details of all products available in inventory. */
void check(struct Product inventory[], int count)
{
    int i;

    if (count == 0)
    {
        printf("Inventory is Empty. Please add the items first.\n");
        return;
    }

    printf("\n\t==================== INVENTORY ====================\n");
    printf("\tID\t\tName\t\tPrice\t\tQuantity\n");

    for (i = 0; i < count; i++)
    {
        printf("\t%d\t\t%s\t\tRs.%.2f\t\t%d\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].price,
               inventory[i].qty);
    }
}

// REMOVE FUNCTION
/* Function to remove any product from the inventory. */
void rem(struct Product inventory[], int *count)
{
    int num;
    int searchId;
    int found;
    int i;
    int j;
    int removed = 0;

    if (*count == 0)
    {
        printf("\nInventory is empty. No items to remove.\n");
        return;
    }

    while (1)
    {
        printf("\nHow many items do you want to remove? ");

        if (scanf("%d", &num) != 1)
        {
            printf("Invalid input! Please enter a whole number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (num > 0 && num <= *count)
        {
            break;
        }

        printf("Please enter a valid number.\n");
        printf("Only %d item(s) are available in inventory.\n", *count);
    }

    for (j = 1; j <= num; j++)
    {
        while (1)
        {
            printf("\nEnter Item ID %d to remove: ", j);

            if (scanf("%d", &searchId) != 1)
            {
                printf("Invalid ID input! Please enter a valid number.\n");
                clearInputBuffer();
                continue;
            }

            clearInputBuffer();

            found = findProduct(inventory, *count, searchId);

            if (found == -1)
            {
                printf("Item ID %d not found. Please enter another ID.\n", searchId);
                continue;
            }

            break;
        }

        printf("Removed: %s (ID: %d)\n",
               inventory[found].name,
               inventory[found].id);

        for (i = found; i < *count - 1; i++)
        {
            inventory[i] = inventory[i + 1];
        }

        (*count)--;
        removed++;
    }

    printf("\nRemoval process completed. %d item(s) removed.\n", removed);
}

// SEARCH FUNCTION
/* Function created to search any product from inventory by item ID. */
void search(struct Product inventory[], int count)
{
    int found;
    int searchId;

    if (count == 0)
    {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Enter item ID you have to search : ");

    if (scanf("%d", &searchId) != 1)
    {
        printf("Invalid ID input!\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    found = findProduct(inventory, count, searchId);

    if (found == -1)
    {
        printf("Invalid ID! Item not found.\n");
        return;
    }

    printf("Item Found!\n");
    printf("--- Product Details ---\n");
    printf("Product ID : %d\n", inventory[found].id);
    printf("Product Name : %s\n", inventory[found].name);
    printf("Product Price : Rs.%.2f\n", inventory[found].price);
    printf("Product Quantity : %d\n", inventory[found].qty);
}

// FIND PRODUCT
/* Helper function created to search or find product by item ID used in multiple functions. */
int findProduct(struct Product inventory[], int count, int searchId)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (inventory[i].id == searchId)
        {
            return i;
        }
    }

    return -1;
}

// LOAD DATA FUNCTION
/* Function created to retrieve data from file where product details are stored. */
void loadData(struct Product inventory[], int *count, int *nextid)
{
    FILE *fp;
    int i;

    fp = fopen("inventory.txt", "r");

    if (fp == NULL)
    {
        *count = 0;
        *nextid = STARTING_ID;
        return;
    }

    if (fscanf(fp, "Count : %d\nNextID : %d\n\n", count, nextid) != 2)
    {
        printf("Invalid inventory file. Starting with an empty inventory.\n");
        *count = 0;
        *nextid = STARTING_ID;
        fclose(fp);
        return;
    }

    if (*count < 0 || *count > MAX_PRODUCTS || *nextid < STARTING_ID)
    {
        printf("Invalid inventory file data. Starting with an empty inventory.\n");
        *count = 0;
        *nextid = STARTING_ID;
        fclose(fp);
        return;
    }

    for (i = 0; i < *count; i++)
    {
        if (fscanf(fp, "ID : %d\n", &inventory[i].id) != 1 ||
            fscanf(fp, "Name : %49[^\n]\n", inventory[i].name) != 1 ||
            fscanf(fp, "Quantity : %d\n", &inventory[i].qty) != 1 ||
            fscanf(fp, "Price : %f\n", &inventory[i].price) != 1)
        {
            printf("Error reading product data. Loading valid records only.\n");
            *count = i;
            break;
        }

        if (inventory[i].qty < 0 || inventory[i].price < 0)
        {
            printf("Invalid data found for product ID %d. Loading valid records only.\n",
                   inventory[i].id);
            *count = i;
            break;
        }
    }

    fclose(fp);
}

// SAVE DATA FUNCTION
/* Function created to save the product details in the file after performing any operation. */
void saveData(struct Product inventory[], int count, int nextid)
{
    FILE *fp;
    int i;

    fp = fopen("inventory.txt", "w");

    if (fp == NULL)
    {
        printf("Unable to save data.\n");
        return;
    }

    fprintf(fp, "Count : %d\n", count);
    fprintf(fp, "NextID : %d\n\n", nextid);

    for (i = 0; i < count; i++)
    {
        fprintf(fp, "ID : %d\n", inventory[i].id);
        fprintf(fp, "Name : %s\n", inventory[i].name);
        fprintf(fp, "Quantity : %d\n", inventory[i].qty);
        fprintf(fp, "Price : %.2f\n\n", inventory[i].price);
    }

    fclose(fp);
}

/* Developed by Neil Singh
   Inventory Management System - C Programming Project */
