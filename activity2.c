#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int id;
    char name[50];
    char author[50];
    float price;
};

void addBook()
{
    struct Book b;
    FILE *fp;

    fp = fopen("books.dat", "ab");

    printf("\nEnter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b.name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);

    printf("Enter Price: ");
    scanf("%f", &b.price);

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);

    printf("\nBook added successfully!\n");
}

void displayBooks()
{
    struct Book b;
    FILE *fp;

    fp = fopen("books.dat", "rb");

    if(fp == NULL)
    {
        printf("\nNo books found.\n");
        return;
    }

    printf("\n--- BOOK DETAILS ---\n");

    while(fread(&b, sizeof(b), 1, fp))
    {
        printf("\nID     : %d", b.id);
        printf("\nName   : %s", b.name);
        printf("\nAuthor : %s", b.author);
        printf("\nPrice  : %.2f\n", b.price);
    }

    fclose(fp);
}

void updateBook()
{
    struct Book b;
    FILE *fp;
    int id, found = 0;

    fp = fopen("books.dat", "rb+");

    if(fp == NULL)
    {
        printf("\nNo books found.\n");
        return;
    }

    printf("\nEnter Book ID to update: ");
    scanf("%d", &id);

    while(fread(&b, sizeof(b), 1, fp))
    {
        if(b.id == id)
        {
            printf("Enter New Book Name: ");
            scanf(" %[^\n]", b.name);

            printf("Enter New Author Name: ");
            scanf(" %[^\n]", b.author);

            printf("Enter New Price: ");
            scanf("%f", &b.price);

            fseek(fp, -sizeof(b), SEEK_CUR);
            fwrite(&b, sizeof(b), 1, fp);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found)
        printf("\nBook updated successfully!\n");
    else
        printf("\nBook not found!\n");
}

void deleteBook()
{
    struct Book b;
    FILE *fp, *temp;
    int id, found = 0;

    fp = fopen("books.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if(fp == NULL)
    {
        printf("\nNo books found.\n");
        return;
    }

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    while(fread(&b, sizeof(b), 1, fp))
    {
        if(b.id == id)
        {
            found = 1;
        }
        else
        {
            fwrite(&b, sizeof(b), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("books.dat");
    rename("temp.dat", "books.dat");

    if(found)
        printf("\nBook deleted successfully!\n");
    else
        printf("\nBook not found!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n\n===== LIBRARY MANAGEMENT SYSTEM =====");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Update Book");
        printf("\n4. Delete Book");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                updateBook();
                break;

            case 4:
                deleteBook();
                break;

            case 5:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}
