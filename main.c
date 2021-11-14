#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Game Essentials 
void ViewNavigator() {
    printf("||WELCOME TO SECRET POTIONS OF THE GEFFEN WITCHES||\n");
    printf("[1] Select from Main menu\n");
    printf("[2] Check Bag\n");
    printf("[3] Craft Potion\n");
    printf("[4] Catch Fish\n");
    printf("[5] Buy Items \n"); 
    printf("[6] Sell Items \n");
    printf("---------------------------------------------------------\n");
}
void Navigator(int choice){
    while(choice != 3) {
        ViewNavigator();
        if (choice == 1) {
            printf("Coming soon..\n");
        }else if (choice == 2) {
            printf("Coming soonnn\n");
        }else if (choice == 3) {
            printf("Coming soon\n");
        }else if (choice == 4){
            printf("Coming soon...");
        }else if (choice == 5) {
            printf("Coming soon..");
        }else if (choice == 6) {
            printf("Coming soon..");
        }
    choice = 0;
    }
}


//Game resources 
struct Chakra
{
    char materials[4][20];
    char location[4][20];
    double price[1000]; 
    
};

//User 
struct UserProfile
{
    char userName [50]; 
    double userBal; 
};

//Game Functions 
double Shop(double money, char itemName[50], double itemPrice){
    if (money >= itemPrice) 
        money-=itemPrice;
    return money;
}

int main() {
    int choice; 
    Navigator(scanf("%s",&choice));
    // struct UserProfile user;
    // char userName [50]; 

    // strcpy(user.userName, scanf("%s", &userName));
    // user.userBal = 760.0;

    // printf("IGN: %s", user.userName);
    // user.userBal -= (user.userBal,"Gold",750);

    // printf("\n%.f",user.userBal);

    return 0; 
}