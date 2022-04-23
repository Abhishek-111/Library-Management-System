#include<stdio.h>
#include<conio++.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
//global variables
int commitment = 0;
int total_list = 0;
//Linked list for storing data while executing the code

struct node
{
    int book_id;
    char book_name[50];
    char author[50];
    float price;
    int status;
    struct node *next;
};
//make start pointer of linked list
struct node *start = NULL;


// For file handeling
struct book
{
    int book_id;
    char book_name[50];
    char author[50];
    float price;
    int status;
};
struct node b4;
//create a new node
struct node *new_node()
{
    struct node *nw;
    nw = (struct node *) malloc(sizeof(struct node));
    if(start == NULL)
    {
        nw->next = NULL;
        start = nw;
    }
    else
    {
        nw->next = start; //adding each node at the beginning
        start = nw;
    }
    return nw;
}
//check whether the given ID is avialable or not!
int checkid(int thisid)
{
    struct node *cp;
    cp = start;
    while(cp->next != NULL)
    {
        if(cp->book_id == thisid)
            return 1;
        cp=cp->next;
    }
    return 0;
}

// Check book Status
int give_status(int thisid)
{
     struct node *cp;
    cp = start;
    while(cp->next != NULL)
    {
        if(cp->book_id == thisid)
        {
            if(cp->status == 0) // if not reserved, then do reserve
            {
                cp->status = 1;
                return 1;
            }
            else
                return 0; //when book is already reserved!
        }
        
        cp=cp->next;
    }
    // return 0;

}



//Load the linked list 
void load_list()
{
    struct book b1;
    struct node *nw;
    FILE *fp;

    fp = fopen("Book_record.txt","r");

    while(fread(&b1,sizeof(b1),1,fp) > 0)
        {
            nw = new_node();
            //count the no of linked list
            total_list+=1;
            nw->book_id = b1.book_id;
            strcpy(nw->book_name,b1.book_name);

            strcpy(nw->author,b1.author);
            nw->price = b1.price;

           
            if(b1.status == 0)
            {
                nw->status  = 0;
            } 
            else
            {
                nw->status = 1;
            }
        }
        fclose(fp);
}

//display the list
// void display_list()
// {
//     Clear_Screen();
//     struct node *cp;
//     cp = start;
//     while(cp->next != NULL)
//     {

//         printf("\nBook Id %d",cp->book_id);
//         printf("\nBook name %s",cp->book_name);
//         printf("\nBook author %s",cp->author);
//         printf("\nBook price %f",cp->price);
//         printf("\nBook status %d",cp->status);
//         // printf("Book Id %d",cp->book_id);
//         cp=cp->next;
//     }
//     getch();

// }


void search_book()
{
    FILE *fp;
    char cho;
    int row,thisID,row2,flg;
    struct book b1,b2;
    struct node *cp,*curP;
    cp = start;
    curP = start;

    fp = fopen("Book_record.txt","r");
    Clear_Screen();
    LOCATION(1,36);
    printf(FGRN("Search Books"));
    LOCATION(2,27);
    printf(FCYN("-------------------------------\n"));

    LOCATION(4,32);
    printf(FYEL("Search By Book"));
    printf(FRED(" I"));
    printf(FYEL("D"));

    LOCATION(6,32);
    printf(FYEL("Display"));
    printf(FRED(" A"));
    printf(FYEL("ll Books in Library"));

    LOCATION(8,32);
    printf(FRED("B"));
    printf(FYEL("ack"));

    LOCATION(11,28);
    printf("Enter Your Choice: ");
    cho = getch();

    if(cho == 'A' || cho == 'a') //all records
    {
        Clear_Screen();
        LOCATION(1,1);
        printf(FRED("Book ID"));
        LOCATION(1,14);
        printf(FRED("Book Name"));
        LOCATION(1,35);
        printf(FRED("Author"));

        LOCATION(1,57);
        printf(FRED("Price"));
        LOCATION(1,68);
        printf(FRED("Status"));

        LOCATION(2,1);
        printf(FCYN("----------------------------------------------------------------------------"));

        
        row = 3;
        // while(fread(&b1,sizeof(b1),1,fp) > 0)
        while(cp->next != NULL)
        {
           
            LOCATION(row,1); //row = 3 starting
            printf("%d",cp->book_id);
            

            LOCATION(row,14);
            printf("%s",cp->book_name);
            
            LOCATION(row,35);
            printf("%s",cp->author);
             
            LOCATION(row,57);
            printf("%.2f",cp->price);
            

            LOCATION(row,68);
            if(cp->status == 0)
            {
                printf(FGRN("AVL"));
               
            } 
            else
            {
                printf(FRED("N AVL"));
                
            }
            row+=1; //for next row;
            cp=cp->next;
        }
        //display the contents

    }
    else if (cho == 'B' || cho == 'b')
    {

    }
    else if (cho == 'I' || cho == 'i') // any particular book
    {
        flg = 0;
        Clear_Screen();
        LOCATION(1,33);
        printf("Enter Book ID: ");
        scanf("%d",&thisID);
        LOCATION(3,1);
        printf(FRED("Book ID"));
        LOCATION(3,14);
        printf(FRED("Book Name"));
        LOCATION(3,35);
        printf(FRED("Author"));

        LOCATION(3,57);
        printf(FRED("Price"));
        LOCATION(3,68);
        printf(FRED("Status"));

        LOCATION(4,1);
        printf(FCYN("----------------------------------------------------------------------------"));

        row2 = 6;
        // while(fread(&b2,sizeof(b2),1,fp) > 0)
        while(curP->next != NULL)
        {
            if(curP->book_id == thisID)
            {
                    LOCATION(row2,1); //row = 3 starting
                    printf("%d",curP->book_id);

                    LOCATION(row2,14);
                    printf("%s",curP->book_name);

                    LOCATION(row2,35);
                    printf("%s",curP->author);

                    LOCATION(row2,57);
                    printf("%.2f",curP->price);

                    LOCATION(row2,68);
                    if(curP->status == 0)
                    {
                        printf(FGRN("AVL"));
                        LOCATION(row2+2,1);
                    } 
                    else
                    {
                        printf(FRED("N AVL"));
                        LOCATION(row2+2,1);

                    }
                    row2+=1; //for next row;
                    flg = 1;
                    getch(); //to hold the screen
                    break; //break the while loop if found
            }
            curP=curP->next;
        }//while closes

             if(flg == 0)
             {
                 LOCATION(6,27);
                 printf(FRED("Book of this Id is not Available!!"));
                 getch();
             }
            //  getch(); //to hold
         
        
        
    }

    fclose(fp);
    // printf("\n");
    getch(); //hold the screen;
}
void add_new_book()
{
    char c = ' ';
    FILE *fp;
    int new_id,ck;
    struct book b1;
    struct node *nw;
    do
    {
        nw = new_node();
        fp = fopen("Book_record.txt","ab+");
        Clear_Screen();
        LOCATION(1,36);
        printf(FGRN("Add New Book"));
        LOCATION(2,27);
        printf(FCYN("-------------------------------\n"));
        //book id
        LOCATION(4,32);
        printf(FCYN("Enter Book ID: "));
        scanf("%d",&new_id);
        //chcek if this id is available or not!
        ck = checkid(new_id);
        if(ck == 1)
        {
            LOCATION(7,28);
            printf(FRED("This ID has already taken!!"));
            LOCATION(8,28);
            printf(FRED("Try Another ID"));
            getch();
            getch();
            add_new_book();
        }
        else
        {
            b1.book_id = new_id;
            nw->book_id = new_id; //to linked list
            // scanf("%d",&b1.book_id);
            //book name
            LOCATION(6,32);
            printf(FCYN("Enter Book Name: "));
            fflush(stdin);
            // scanf("%s",b1.book_name);
            fgets(b1.book_name,50,stdin);
            fgets(b1.book_name,50,stdin); //it works in secord call
            strcpy(nw->book_name, b1.book_name);
           
            //book author
            LOCATION(8,32);
            printf(FCYN("Author: "));
            // scanf("%s",b1.author);
            fgets(b1.author,50,stdin);
            strcpy(nw->author,b1.author);

            //Price
            LOCATION(10,32);
            printf(FCYN("Enter Book Price: "));
            scanf("%f",&b1.price);
            nw->price = b1.price;
               
                b1.status = 0;
                nw->status = 0;

            LOCATION(13,28);
            fwrite(&b1,1,sizeof(b1),fp);
            fflush(stdin);
            printf(FBLU("Do You Want To Add Another Book? (y/n)"));
            c = getche();
            // printf("\nValue of c is %c",c);

            //write the content to the file
            
            fclose(fp);

            // scanf("%c",&c);
            c = getch();
        }

    } while (c == 'Y' || c == 'y');
    
    
}
void reserve_book()
{
    int thisID,i=0,avail,res;
    char enroll[50];
    Clear_Screen();
    LOCATION(2,33);
    printf(FBLU("Enter Your Enrollment: "));
    scanf("%s",enroll);
    //check whether the person is authourised or not
    if(enroll[i]=='0' && enroll[i+1] == '1' && enroll[i+2] == '8' && enroll[i+3] == '7')
    {
        LOCATION(4,33);
        printf(FBLU("Enter Book ID To Reverve: "));
        scanf("%d",&thisID);
        //Check the availability of this book
        //first check id
        avail = checkid(thisID);
        if(avail == 1)
        {
            //check book status
            res = give_status(thisID);
            if(res == 1)
            {
                LOCATION(6,6);
                printf(FGRN("Book Has Reserved!"));
                commitment = 1;
                getch();
                getch();
            }
            else
            {
                LOCATION(6,6);
                printf(FRED("Sorry, This Book Is Not Available Right Now."));
                getch();
                getch();
            }
        }
        else
        {
            LOCATION(6,6);
            printf(FRED("Book Of This ID Is Not Available In Library!"));
            getch();
            getch();
        }

    }
    else
    {
        LOCATION(4,6);
        printf(FRED("Sorry, You Are Not The Authourised Person To Access This Library!\n\n"));
        getch();
        getch();
    }
    
}

// void demo_open()
// {
//      struct book b1;
//     FILE *fp;

//     fp = fopen("Book_record.txt","r");

//     while(fread(&b1,sizeof(b1),1,fp) > 0)
//         {
            
            
//             printf("Book id = %d\n",b1.book_id);
//             printf("Book name = %s \n",b1.book_name);

//             printf("author %s \n",b1.author);
//             printf("Price %f \n",b1.price);

           
//             if(b1.status == 0)
//             {
//                 printf("Free\n");
//             } 
//             else
//             {
//                 printf("Booked\n");
//             }
//         }
//         fclose(fp);

// }

/*
void write_into_file(struct node b4)
{
    FILE *fp;
    fp = fopen("Book_record.txt","ab+");
    // printf("\nBook ID %d",b4.book_id);

    // printf("\nBook name %s",b4.book_name);

    fwrite(&b4,1,sizeof(b4),fp);
    // demo_open();
    fclose(fp);
}
// Re writing the file from linked list on any modification
void erease_file()
{   
    // Clear_Screen();
    struct node *cp;
    // struct book b4;
    cp = start;
    // FILE *fp;
    // fp = fopen("Book_record.txt","wb"); // only for ereasing purpose
    // fclose(fp);
    remove("Book_record.txt"); //delete old file
    getch();
    getch();

    while(cp->next != NULL)
    {

        b4.book_id = cp->book_id;
        strcpy(b4.book_name,cp->book_name);
        // printf("\nBook name %s",cp->book_name);
        strcpy(b4.author,cp->author);
        // printf("\nBook author %s",cp->author);
        b4.price = cp->price;
        // printf("\nBook price %f",cp->price);
        b4.status = cp->status;
        // printf("\nBook status %d",cp->status);
        // printf("Book Id %d",cp->book_id);

        write_into_file(b4);
        cp=cp->next;
    }

}
*/

void operations(char choice)
{
    if(choice == 'A' || choice == 'a')
    {
        add_new_book();
    }

    else if (choice == 'E' || choice == 'e')
    {
        printf("\n");
        // Re-write the file from linkedlist if commitment is 1;
            // if(commitment == 1)
            // {
            //     // erease_file();
            // }
        Clear_Screen();
        printf(FBLU("Bye\n"));
        exit(0);
    }
    else if(choice == 'T' || choice == 't')
    {
        // display_list();
    }
    else if(choice == 'S' || choice == 's')
    {
        search_book();
    }
    else if(choice == 'R' || choice == 'r')
    {
        reserve_book();
    }
}
char menu()
{
    
    
        char choice;
        Clear_Screen();
        LOCATION(1,42);
        printf(FMAG("Main Menu\n"));
        LOCATION(2,31);
        printf(FCYN("-------------------------------\n"));
        LOCATION(4,34);
        printf(FRED("A"));
        printf(FYEL("dd New Books\n"));
        LOCATION(6,34);
        printf(FRED("S"));
        printf(FYEL("earch Books\n"));

        LOCATION(8,34);
        printf(FRED("I"));
        printf(FYEL("ssue Books"));

        LOCATION(10,34);
        printf(FRED("R"));
        printf(FYEL("eserve Books"));

        LOCATION(12,34);
        printf(FRED("R"));
        printf(FYEL("eturn Books"));

        LOCATION(14,34);
        printf(FYEL("Se"));
        printf(FRED("t"));
        printf(FYEL("tings"));

        LOCATION(16,34);
        printf(FRED("E"));
        printf(FYEL("xit"));


        LOCATION(18,31);
        printf(FCYN("-------------------------------\n"));

        LOCATION(19,31);
        printf("Enter Your Choice: ");
        choice = getche();
        return choice;
    

}
// void delay(int milliseconds)
// {
//     long pause;
//     clock_t now,then;

//     pause = milliseconds*(CLOCKS_PER_SEC/1000);
//     now = then = clock();
//     while( (now-then) < pause )
//         now = clock();
// }

int main()
{
    int i=0,k=0,res,flg=0;
    char ch[20],choice,ch2,get_pass = ' ',sv_pass[20];
    // ch[100] = '\0';
    FILE *fp;
    fp = fopen("password.txt","r");

    if(fgets(ch,20,fp) == NULL)
    {
        LOCATION(1,42);
        printf("No passwd");
    }
    else  //If not null
    {
        Clear_Screen();
        LOCATION(12,32);
        printf(FGRN("Enter the Password: "));
        while(get_pass != '\n')
        {
           get_pass = getch();
           printf("*");
           sv_pass[k++] = get_pass;
        }
        // printf("\nThe entered password is:%s\n",sv_pass);
        // res = strcmp(ch,sv_pass);
        // printf("Res = %d\n",res);

        // check if password matchs
        for(int i=0;i<strlen(ch);i++)
        {
            if(ch[i] == sv_pass[i])
            {
                continue;
            }
            else
            {
                flg = 1;
                break;
            }
        }
        
        //If both password matches
        if(flg == 0)
        {
            //load the data into linked list
            load_list();
            while(1)
            {
                choice = menu();
                operations(choice);
            }
            // printf(FGRN("Matched!1"));
        }
        else
        {
            Clear_Screen();
            LOCATION(12,32);
            printf(FRED("❌️ Incorrect Password!!\n"));
        }
        
    }
    
    // else 
    // {
    //     for(int i=0;i<strlen(ch);i++)
    //     {
    //         printf("%c",ch[i]);
    //     }
    //     // printf("Password is %s",fgets(ch,100,fp));
    //     // printf("\n");
    // }
    fclose(fp);
    // printf("\nYour choice is %c \n",choice);




    ch2= getch();
    return 0;
}