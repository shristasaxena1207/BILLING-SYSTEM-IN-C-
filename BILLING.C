#include <stdio.h>

#define ITEMS 8

// Function to display products
void showProducts(const char *names[], const float prices[])
{
    int i;

    printf("\n------------ PRODUCT LIST ------------\n");
    printf("%-5s %-20s %10s\n", "No.", "Product", "Price");

    for (i = 0; i < ITEMS; i++)
    {
        printf("%-5d %-20s Rs. %7.2f\n",
               i + 1, names[i], prices[i]);
    }

    printf("--------------------------------------\n");
}

// Function to generate bill
float printBill(const char *names[],
                const float prices[],
                const int qty[])
{
    int i, found = 0;
    float subtotal = 0.0f;
    float discount, grandTotal;

    printf("\n============= GROCERY STORE =============\n");
    printf("%-18s %5s %10s %12s\n",
           "Item", "Qty", "Price", "Amount");

    printf("------------------------------------------\n");

    for (i = 0; i < ITEMS; i++)
    {
        if (qty[i] > 0)
        {
            float amount = prices[i] * qty[i];

            printf("%-18s %5d %10.2f %12.2f\n",
                   names[i], qty[i],
                   prices[i], amount);

            subtotal += amount;
            found = 1;
        }
    }

    if (!found)
    {
        printf("No items added to the bill.\n");
        return 0.0f;
    }

    // Calculate discount
    if (subtotal >= 1000)
        discount = subtotal * 0.05f;
    else
        discount = 0.0f;

    grandTotal = subtotal - discount;

    printf("------------------------------------------\n");
    printf("Subtotal:       Rs. %.2f\n", subtotal);
    printf("Discount:       Rs. %.2f\n", discount);
    printf("Grand Total:    Rs. %.2f\n", grandTotal);

    printf("==========================================\n");
    printf("       Thank You! Visit Again.\n");

    return grandTotal;
}

// Main Function
int main()
{
    const char *productName[ITEMS] = {
        "Rice",
        "Wheat Flour",
        "Sugar",
        "Milk",
        "Bread",
        "Cooking Oil",
        "Tea",
        "Biscuits"
    };

    const float price[ITEMS] = {
        60.00, 45.00, 48.00, 30.00,
        40.00, 150.00, 120.00, 25.00
    };

    int quantity[ITEMS] = {0};

    int choice, productNo, qty;

    printf("\n========================================\n");
    printf("  WELCOME TO GROCERY STORE BILLING SYSTEM");
    printf("\n========================================\n");

    do
    {
        printf("\n--------------- MAIN MENU ---------------\n");
        printf("1. View Products\n");
        printf("2. Add Items to Bill\n");
        printf("3. Generate Bill\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Enter a number.\n");

            while (getchar() != '\n')
                ;

            choice = 0;
            continue;
        }

        switch (choice)
        {
            case 1:

                showProducts(productName, price);
                break;

            case 2:

                showProducts(productName, price);

                printf("Enter product number (1-%d): ", ITEMS);

                if (scanf("%d", &productNo) != 1)
                {
                    printf("Invalid product number!\n");

                    while (getchar() != '\n')
                        ;

                    break;
                }

                if (productNo < 1 || productNo > ITEMS)
                {
                    printf("Invalid product number!\n");
                    break;
                }

                printf("Enter quantity: ");

                if (scanf("%d", &qty) != 1)
                {
                    printf("Invalid quantity!\n");

                    while (getchar() != '\n')
                        ;

                    break;
                }

                if (qty <= 0)
                {
                    printf("Quantity must be greater than zero!\n");
                    break;
                }

                quantity[productNo - 1] += qty;

                printf("Item added successfully!\n");

                break;

            case 3:

                printBill(productName, price, quantity);
                break;

            case 4:

                printf("\nExiting Program...\n");
                printf("Thank you for visiting!\n");

                break;

            default:

                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}