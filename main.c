#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Game Mechanics
void ViewNavigator() {
    printf("||WELCOME TO SECRET POTIONS OF THE GEFFEN WITCHES||\n");
    printf("[1] Travel options\n");
    printf("[2] Inventory\n");
    printf("[3] Crafting Area\n");
    printf("[4] Fishing Area\n");
    printf("[5] Shop\n"); 
    printf("[6] Exit game\n");
    printf("---------------------------------------------------------\n");
}
void ViewLocations() {
    printf("[1] Geffen\n"); 
    printf("[2] Holgrehenn Store\n");
    printf("[3] Taal Lake\n "); 
    printf("[4] Galathea Deep\n");
    printf("[5] Dagupan Mongrove Forests\n"); 
    printf("[6] Mindanao Current\n");
}
void Navigator(int choice){
    switch (choice)
    {
    case 1:
        printf("||Travel Options||\n");
        ViewLocations();
        break;
    case 2: 
        printf("||Inventory||"); 
        break;
    case 3: 
        printf("||Crafting Area||"); 
        break; 
    case 4: 
        printf("||Fishing Area||"); 
        break; 
    case 5: 
        printf("||Shop||"); 
        break;
    case 6: 
        printf("||Goodbye :)||");
    default:
        break;
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
    ViewNavigator();
    int choice; 
    while(choice !=6) {
        scanf("%d",&choice);
        Navigator(choice);
    }

    return 0; 
}