[4/19/2024, 20:09] +91 88604 49744: #include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#define PARKING_FEE_PER_DAY 1
#define MAX_SERVICES 10
#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 50
#define MAX_FEEDBACK_LENGTH 200
#define MAX_COMPLAINT_LENGTH 200
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MENU_SIZE 8
#define GST_RATE 0.18
//----------------------------------------------------------------------------------------------------------//
//Structure to represent personal information 
typedef struct 
{
    int hotelid;
    int rno;
    char name[40];
    char resadd[80];
    char peradd[80];
    char phone[20];
    char telpho[20];
    char DOB[20];
    int PINCODE;
    char state[20];
    char country[20];
    char mail[30];
    char whatno[20];
    char bnkacntno[30];
    char IFSC[20];
    char Aadhar[20];
    char passport[20];
    char voterid[20];
    struct info* next;
}info;
//----------------------------------------------------------------------------------------------------------//
// Structure to represent a hotel room
typedef struct {
    int room_number;
    char guest_name[50];
    int is_booked;
} Room;
//----------------------------------------------------------------------------------------------------------//
// Define a structure for user credentials
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} UserCredentials;
//----------------------------------------------------------------------------------------------------------//
// Structure to represent menu items
typedef struct
{
    char name[50];
    float price;
} MenuItem;
//----------------------------------------------------------------------------------------------------------//
//Structure to represent check in and Check out of customer
typedef struct {
    char checkin_date[15];
    char checkout_date[15];
} Customer;
//----------------------------------------------------------------------------------------------------------//
//Structure to Store Feedback
struct Guest {
    char name[MAX_NAME_LENGTH];
    int roomNumber;
    char feedback[MAX_FEEDBACK_LENGTH];
    char complaint[MAX_COMPLAINT_LENGTH];
};
//----------------------------------------------------------------------------------------------------------//
// Structure to represent a service
typedef struct {
    char name[50];
    float price;
} Service;
//----------------------------------------------------------------------------------------------------------//
// Structure for payment gateway
typedef struct { 
    float bill;
    int payment_status;

}booking;
//----------------------------------------------------------------------------------------------------------//
//Structure to represent Parking systme
struct Car {
    int id;

    int checked_in; // 1 if checked in, 0 if checked out
    int days_parked;
};
//----------------------------------------------------------------------------------------------------------//
    // Define the number of rooms in the hotel
    const int room_count = 10;
    struct Guest guests[MAX_ROOMS];
    int numGuests = 0;
    // Global variables
    Service services[MAX_SERVICES];
    int numServices = 0;
    int days[15][31];
//----------------------------------------------------------------------------------------------------------//
// Function to clear the screen
void clearScreen()
{
    system("cls");
}
//----------------------------------------------------------------------------------------------------------//
void Rinit(info **head)
{
    *head=NULL;   //Initialising the structure
}
//----------------------------------------------------------------------------------------------------------//
//Function to create a list of customers
info *Rcreate_list()
{                                           //To create a linked list of customers
    info *head,*p;
    int n;
    printf("NUMBER OF CUSTOMERS:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            head=(info*)malloc(sizeof(info));
            p=head;
        }
        else
        {
            p->next=(info*)malloc(sizeof(info));
            p=p->next;
        }
        p->hotelid=i;
        //----------------------------------------------------------------------------------------------------------//
        //Asking user for Input 
        printf("-----------------------------------------------CUSTOMER %d--------------------------------------------------------------\n",i);
        printf("NAME:");
        scanf("\n%[^\n]",p->name);
        printf("\nRESIDENTIAL ADDRESS:");
        scanf("\n%[^\n]",p->resadd);
        printf("\nPERMANENT ADDRESS:");
        scanf("\n%[^\n]",p->peradd);
        printf("\nPHONE:");
        scanf("%s",p->phone);
        printf("\nWHATSAPP NO:");
        scanf("%s",p->whatno);
        printf("\nTELEPHONE NO:");
        scanf("%s",p->telpho);
        printf("\nMAIL:");
        scanf("%s",p->mail);
        printf("\nDATE OF BIRTH IN DD-MM-YYYY:");
        scanf("%s",p->DOB);
        printf("\nBANK ACCOUNT NO:");
        scanf("%s",p->bnkacntno);
        printf("\nIFSC:");
        scanf("%s",p->IFSC);
        printf("\nAADHAR CARD NO:");
        scanf("%s",p->Aadhar);
        printf("\nVOTER ID NO:");
        scanf("%s",p->voterid);
        printf("\nPASSPORT:");
        scanf("%s",p->passport);
        printf("\nPINCODE:");
        scanf("%d",&p->PINCODE);
        printf("\nSTATE:");
        scanf("\n%[^\n]",p->state);
        printf("\nCOUNTRY:");
        scanf("\n%[^\n]",p->country);
    }
    p->next=NULL;
    return head;
}
//----------------------------------------------------------------------------------------------------------//
//Function to insert information about the new customer
void Rinsert(info **head)
{
    info *new,*p,*q;
    new=(info*)malloc(sizeof(info));                                //Providing the details of new customer
    printf("------------------------------------------------------NEW CUSTOMER DETAILS---------------------------------------------------\n");
    printf("NAME:");
    scanf("\n%[^\n]",new->name);
    printf("\nRESIDENTIAL ADDRESS:");
    scanf("\n%[^\n]",new->resadd);
    printf("\nPERMANENT ADDRESS:");
    scanf("\n%[^\n]",new->peradd);
    printf("\nPHONE:");
    scanf("%s",new->phone);
    printf("\nWHATSAPP NO:");
    scanf("%s",new->whatno);
    printf("\nTELEPHONE NO:");
    scanf("%s",new->telpho);
    printf("\nMAIL:");
    scanf("%s",new->mail);
    printf("\nDATE OF BIRTH IN DD-MM-YYYY FORMAT:");
    scanf("%s",new->DOB);
    printf("\nBANK ACCOUNT NO:");
    scanf("%s",new->bnkacntno);
    printf("\nIFSC:");
    scanf("%s",new->IFSC);
    printf("\nAADHAR CARD NO:");
    scanf("%s",new->Aadhar);
    printf("\nVOTER ID NO:");
    scanf("%s",new->voterid);
    printf("\nPASSPORT:");
    scanf("%s",new->passport);
    printf("\nPINCODE:");
    scanf("%d",&new->PINCODE);
    printf("\nSTATE:");
    scanf("\n%[^\n]",new->state);
    printf("\nCOUNTRY:");
    scanf("\n%[^\n]",new->country);
    p=*head;
    while(p!=NULL)
    {                                   //Inserting element at the end
        q=p;
        p=p->next;                          //Traversing the list 
    }
    new->hotelid=q->hotelid+1;
    q->next=new;
    new->next=NULL;
}
//----------------------------------------------------------------------------------------------------------//
//Function to delete the customer record
void Rdelete(info **head)
{
    info *p,*q,*r;
    int hid;
    printf("\nDelete for hotel id:");
    scanf("%d",&hid);
    p=*head;
    if(p->hotelid==hid)
    {
        r=p->next;
        *head=p->next;
        free(p);
    }
    else
    {
        while((p!=NULL)&&(p->hotelid!=hid))
        {
            q=p;
            p=p->next;
        }
        if(p==NULL)
        {
            printf("\nNo match!!Deletion Failed,Please Try Again");
        }
        else if(p->hotelid==hid)
        {
            q->next=p->next;
            r=p->next;
            free(p);
        }
    }
    while(r!=NULL)
    {
        r->hotelid=r->hotelid-1;
        r=r->next;
    }
}
//----------------------------------------------------------------------------------------------------------//
//Function to edit the customer record
void Redit(info **head)
{
    info *p;
    int hid,k=0;
    p=*head;
    printf("HOTEL ID:\n");
    scanf("%d",&hid);
    while((p->hotelid)!=hid&&(p!=NULL))
    {
        p=p->next;
    }
    if((p->hotelid)==hid)
    {
        do
        {
            printf("Input your choice to edit:\n");
            printf("1)NAME 2)RESIDENTIAL ADDRESS 3)PERMANENT ADDRESS 4)PHONE NO 5)WHATSAPP NO\n");
            printf("6)TELEPHONE NO 7)MAIL 8)DATE OF BIRTH 9)BANK ACCOUNT NO 10)IFSC 11)AADHAR CARD NO\n");
            printf("12)VOTER ID NO 13)PASSPORT 14)PINCODE 15)STATE 16)COUNTRY 17)EXIT\n");
            int c;
            scanf("%d",&c);
            switch(c)
            {
                case 1:printf("NAME:\n");
                scanf("\n%[^\n]",p->name);
                break;
                case 2:printf("RESIDENTIAL ADDRESS:\n");
                scanf("\n%[^\n]",p->resadd);
                break;
                case 3:printf("PERMANENT ADDRESS:\n");
                scanf("\n%[^\n]",p->peradd);
                break;
                case 4:printf("PHONE NO:\n");
                scanf("%s",p->phone);
                break;
                case 5:printf("WHATSAPP NO:\n");
                scanf("%s",p->whatno);
                break;
                case 6:printf("TELEPHONE NO:\n");
                scanf("%s",p->telpho);
                break;
                case 7:printf("MAIL:\n");
                scanf("%s",p->mail);
                break;
                case 8:printf("DATE OF BIRTH:\n");
                scanf("%s",p->DOB);
                break;
                case 9:printf("BANK ACCOUNT NO:\n");
                scanf("%s",p->bnkacntno);
                break;
                case 10:printf("IFSC:\n");
                scanf("%s",p->IFSC);
                break;
                case 11:printf("AADHAR CARD NO:\n");
                scanf("%s",p->Aadhar);
                break;
                case 12:printf("VOTER ID NO:\n");
                scanf("%s",p->voterid);
                break;
                case 13:printf("PASSPORT:\n");
                scanf("%s",p->passport);
                break;
                case 14:printf("PINCODE:");
                scanf("%d",&p->PINCODE);
                break;
                case 15:printf("STATE:\n");
                scanf("\n%[^\n]",p->state);
                break;
                case 16:printf("COUNTRY:\n");
                scanf("\n%[^\n]",p->country);
                break;
                case 17:printf("EXITING......\n");
                k=1;
                break;
                default:printf("WRONG INPUT!!Please Input a Valid choice:\n");
                break;
            }
        }while(k!=1);
        printf("*INFROMATION UPDATED*\n");
    }
    else if(p==NULL)
    printf("No Such Record exists!!");
}
//----------------------------------------------------------------------------------------------------------//
//Function to display the details of customer
void Rdisplay(info *head)
{
    int count=1;
    while(head!=NULL)
    {
        printf("-------------------------------------------------CUSTOMER %d--------------------------------------------------------------- \n",count++);
        printf("============================================================================================================================\n");
        printf("============================================================================================================================\n");
        printf("HOTEL ID:%d\t\t\t\t\t\t\t\t\t\t\t\tRoom no:%d\n",head->hotelid,head->rno);
        printf("NAME:%s\t\t\t\t\t\t\t\t\t\tDATE OF BIRTH:%s\n",head->name,head->DOB);
        printf("RESIDENTIAL ADDRESS:%s\n",head->resadd);
        printf("PERMANENT ADDRESS:%s\n",head->peradd);
        printf("PINCODE:%d\n",head->PINCODE);
        printf("PHONE:%s\t\t\t\t\t\t\t\t\t\tTELEPHONE NO:%s\n",head->phone,head->telpho);
        printf("WHATSAPP NO:%s\t\t\t\t\t\t\t\t\t\tMAIL:%s\n",head->whatno,head->mail);
        printf("STATE:%s\t\t\t\t\t\t\t\t\t\tCOUNTRY:%s\n",head->state,head->country);
        printf("----------------------------------------------------------------------------------------------------------------------\n");
        printf("AADHAR NO:%s\t\t\t\t\t\t\t\t\t\tPASSPORT NO:%s\n",head->Aadhar,head->passport);
        printf("VOTER ID:%s\n",head->voterid);
        printf("----------------------------------------------------------------------------------------------------------------------\n");
        printf("BANK ACCOUNT NO:%s\t\t\t\t\t\t\t\t\t\tIFSC CODE:%s\n",head->bnkacntno,head->IFSC);
        head=head->next;
    }
}
//----------------------------------------------------------------------------------------------------------//
// Function to book a room
void DbookRoom(Room *rooms, int room_count, int room_number, const char *guest_name) {
    // Check if the room number is valid
    if (room_number < 1 || room_number > room_count) {
        printf("Invalid room number\n");
        return;
    }

    // Check if the room is already booked
    if (rooms[room_number - 1].is_booked) {
        printf("Room %d is already booked\n", room_number);
        return;
    }

    // Book the room
    rooms[room_number - 1].room_number = room_number;
    strcpy(rooms[room_number - 1].guest_name, guest_name);
    rooms[room_number - 1].is_booked = 1;

    printf("Room %d booked successfully for %s\n", room_number, guest_name);
}
//----------------------------------------------------------------------------------------------------------//
// Function to display the status of all rooms
void DdisplayRooms(Room *rooms, int room_count) {
    printf("\n");
    printf("-----------Room Availability-----------");
    printf("\n");
    printf("Room\tGuest Name\tBooked\n");
    for (int i = 0; i < room_count; i++) {
        printf("%d\t%s\t\t%s\n", rooms[i].room_number, 
               rooms[i].guest_name, rooms[i].is_booked ? "Yes" : "No");
    }
}
//------------------------------------------------------------------------------------------------------------//
// Function to authenticate user credentials
int DauthenticateUser(UserCredentials *users, int num_users, char *username, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return the index of the authenticated user
        }
    }
    return -1; // Return -1 if authentication fails
}
//----------------------------------------------------------------------------------------------------------//
//Function to login in the system
void Dlogin()
{
	 UserCredentials users[] = {
        {"admin", "admin123"},
        {"user1", "password1"},
        {"user2", "password2"}
        // Add more users as needed
    };
    int num_users = sizeof(users) / sizeof(users[0]);

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("=== Hotel Management Login ===\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    int auth_result = DauthenticateUser(users, num_users, username, password);
    if (auth_result != -1) {
        printf("Welcome, %s!\n", username);
        // Proceed to hotel management system functionalities
    } else {
        printf("Invalid username or password. Please try again.\n");
        exit(0);
    }
}
//-----------------------------------------------------------------------------------------------------------//
//Function to initialize elements
void Dinit(){
    int i=0;
	
	time_t t;
	time(&t);
    printf("\033[0;33m");
    printf(" -------------------------------------------------------------------------\n");
    printf("|                                                                                  |\n");
    printf("|                                                                                  |\n");
    printf("|  OOOOOO   OOOOO   OOOOOO  OOOOOO  OOOOOO  OOOOOO   O      O   OOOOOO     OOOOO   |\n");
    printf("|  O        O    O  O       O         O       O      O O    O   O         O        |\n");
    printf("|  O  OOO   OOOOO   OOOOO   OOOOO     O       O      O  O   O   O  OOO     OOOO    |\n");
    printf("|  O    O   O  O    O       O         O       O      O   O  O   O    O         O   |\n");
    printf("|  OOOOOO   O   O   OOOOOO  OOOOOO    O     OOOOOO   O    O O   OOOOOO    OOOOO    |\n");
    printf("|                                                                                  |\n");
    printf(" -------------------------------------------------------------------------\n");

    // Reset color to default
    printf("\033[0m");
 	printf("\t\t*\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       --------------------------------        *\n");
	printf("\t\t*        WELCOME TO HOTEL PROJECT TWELVE        *\n");
	printf("\t\t*       --------------------------------        *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*        Brought To You By C programming        *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*     CONTACT US:18-87454575552,035455852       *\n");
	printf("\t\t*\n\n\n");
		for(int i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(int i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue:");
}

//------------------------------------------------------------------------------------------------------------//
//Function to display preface
void Dpreface(){
    int i=0;
	
	time_t t;
	time(&t);
for(int i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(int i=0;i<80;i++)
		printf("-");
		printf("\n");
	
		printf("\t\t Please enter your choice for menu:");
		printf("\n\n");
		printf(" \n Enter 1 -> New Hotel Record");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
        printf(" \n Enter 4 -> Display Room availablity");
		printf("\n-----------------------------------");
        printf(" \n Enter 5 -> Book a Room");
		printf("\n---------------------------------------");
		printf(" \n Enter 6 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 7 -> Restaurant");
		printf("\n-----------------------");
        printf(" \n Enter 8 -> Services");
		printf("\n---------------------");
        printf(" \n Enter 9 -> check out");
		printf("\n----------------------");
        printf(" \n Enter 10 -> Feedback and Complaints");
		printf("\n----------------------------------");
        printf(" \n Enter 11 -> Parking System");
		printf("\n-----------------------------");
        printf(" \n Enter 12 -> Attendance Register(workers)");
		printf("\n-------------------------------------------");
        printf(" \n Enter 13 -> Exit");
		printf("\n----------------------");
		printf("\n");
		for(int i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(int i=0;i<80;i++)
		printf("-");
}

//--------------------------------------------------------------
