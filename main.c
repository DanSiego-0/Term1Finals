#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//User 
struct UserProfile
{
    char userName [50]; 
    double userBal; 
    char userInventory[7][2] = { 
        {"Scaless Blackfish","0"},
        {"Gold","0"},
        {"Majestic water","0"},
        {"Wondrous vinegar","0"},
        {"Mariana Snailfish","0"},
        {"Mudskippers","0"},
        {"Hillstream Loaches","0"}
    };
};

//Game Functions 
void Shop(double money, char itemName[50], double itemPrice){
    if (money >= itemPrice) 
        printf("Success Transaction!");
        money-=itemPrice;
    else {
        printf("Not sufficient money!");
    };
    
}
void Inventory(userInv[6][2]) {
    printf("|| Inventory ||");
    for(int x = 0;x<=6;x++){
        for(int y = 0; y<=2; y++) {
            printf("%s",userInv[x][y]," ");
        }
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
      char userInventory[][7][100] = { 
        {"Scaless Blackfish","0"},
        {"Gold","0"},
        {"Majestic water","0"},
        {"Wondrous vinegar","0"},
        {"Mariana Snailfish","0"},
        {"Mudskippers","0"},
        {"Hillstream Loaches","0"}
    };

    for (int x = 0;x<=6;x++){
        for (int y = 0; y <= 1; y++) {
            printf("%s",userInventory[x][y]);
        }
    }
   
    return 0; 
}