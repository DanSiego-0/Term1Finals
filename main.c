#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//User 
struct UserProfile
{
    int itemAmount[7];
    char *userInventory[7];
    double userBal; 
    char *userName; 
};

//Player Functions 
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
    printf("||Item||                ||Amount||\n");
     for (int x = 0; x<7;x++) {
      printf("%s", backpackarray[x]);
      printf("          ");
      printf("%d\n", itemamount[x]);
    }
}
void PlayerStats(struct UserProfile player1) {
    printf("------------------------------------\n");
    printf("Username: %s\n",player1.userName);
    printf("Ymir: %.2f\n", player1.userBal);
    printf("------------------------------------\n");
}

//Game Functions
void ViewNavigator() {
    printf("||WELCOME TO SECRET POTIONS OF THE GEFFEN WITCHES||\n");
    printf("[1] Travel options\n");
    printf("[2] Inventory     \n");
    printf("[3] Crafting Area \n");
    printf("[4] Fishing Area  \n");
    printf("[5] Shop          \n"); 
    printf("[6] Exit game     \n");
    printf("---------------------------------------------------------\n");
}
void ViewLocations() {
    printf("[1] Taal Lake\n"); 
    printf("[2] Galathea Deep\n");
    printf("[3] Dagupan Mongrove Forests\n");
    printf("[4] Mindanao Current\n");
    printf("[5] Back\n");
}
void Taal(){
    printf("Hello Taal");
}

void MainMenu(char *backpackarray[],int itemamount[]) {
    bool exitGame = false; 
    int x;
    while(!exitGame) {
        x = 0;
        ViewNavigator();
        printf("Where to?: "); 
        scanf("%d",&x);
        if (x == 1) {
            int choice; 
            ViewLocations();
            scanf("%d",&choice); 
            if (choice == 1) {
                int y = 0;
                printf("Nothing much here </3\n");
                printf("[1] Return\n");
                scanf("%d",&y);
            }else if (choice == 2){
                int c = 0;
                printf("Nothing much here </3\n");
                printf("[1] Return\n");
                scanf("%d",&c);
            }else if (choice == 3) {
                int y = 0;
                printf("Nothing much here </3\n");
                printf("[1] Return");
                scanf("%d",&y);
            }else if (choice == 4) {
                int y = 0;
                printf("Nothing much here </3\n");
                printf("[1] Return\n");
                scanf("%d",&y);
            }else if (choice == 5) {
                char y; 
                printf("Are you sure you wanna leave? [y/n]\n");
                scanf(" %c",&y);
                if (y == 'n') ;
                else if (y == 'y'){
                    printf("Goodbye! See you again next time! :)\n ");
                }
            }else printf("Not in the choices!\n");
        }
        else if (x == 2) {
            ShowInventory(backpackarray,itemamount);
            char g;
            printf("Return? [y/n]\n");
            scanf(" %c",&g);
            if (g == 'n'){
                printf("Goodbye! See you again next time! :) \n");
                exitGame = true;
            }else if (g == 'y') {

            }else printf("Choice not found!\n");
        }    
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
     
    //Player init 
    struct UserProfile player1;
    InitPlayer(player1.itemAmount,player1.userInventory);
    player1.userBal = 20.0;
    strcpy(player1.userName,"Brendan");

    PlayerStats(player1);
    MainMenu(player1.userInventory,player1.itemAmount);
    



   

   
    return 0; 
}








// switch (choice)
    // {
    // case 1:
    //     printf("||Travel Options||\n ");
    //     ViewLocations();
    //     break;
    // case 2: 
    //     printf("||Inventory||\n\n      ");
    //     ShowInventory(backpackarr,itemamount);
    //     printf("\n[0] Main Menu");
    //     scanf("%d",&choice); 
    //     if (choice == 0){
    //         ViewNavigator();
    //     }
    //     break;
    // case 3: 
    //     printf("||Crafting Area||\n  "); 
    //     break; 
    // case 4: 
    //     printf("||Fishing Area||\n   "); 
    //     break; 
    // case 5: 
    //     printf("||Shop||\n           "); 
    //     break;
    // case 6: 
    //     printf("||Goodbye :)||\n     ");
    // default:
    //     break;
    // }