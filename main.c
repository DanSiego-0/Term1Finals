#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//User 
struct UserProfile
{
    int itemAmount[7];
    char *userInventory[7];
    double userBal; 
    char userName[50]; 
};

//Game Functions 
void InitPlayer(int itemamnt[],char *backpckarr[]) {
    for (int x = 0; x<7;x++) {
        itemamnt[x] = 0;
        switch (x)
        {
        case 0:
            backpckarr[0] = "Scaless Blackfish  ";
            break;
        case 1:
            backpckarr[1] = "Gold               ";
            break;
        case 2:
            backpckarr[2] = "Majestic water     ";
            break;
        case 3:
            backpckarr[3] = "Wondrous Vinegar   ";
            break;
        case 4:
            backpckarr[4] = "Mariana Snailfish  ";
            break;
        case 5: 
            backpckarr[5] = "Mudskippers        ";
            break;
        case 6:
            backpckarr[6] = "Hillstream Loaches ";
            break;
        default:
            break;
        } 
    }
}
void ShowInventory(char *backpackarray[],int itemamount[]){
    printf("||Item||                      ||Amount||\n");
     for (int x = 0; x<7;x++) {
      printf("%s", backpackarray[x]);
      printf("               ");
      printf("%d\n", itemamount[x]);
    }
}
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



int main() {
     
    struct UserProfile player1;
    InitPlayer(player1.itemAmount,player1.userInventory);
    player1.userBal = 0.0;
    ShowInventory(player1.userInventory,player1.itemAmount);



   

   
    return 0; 
}