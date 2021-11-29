 #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//User 
struct UserProfile
{
    int itemAmount[11];
    char *userInventory[11];
    double userBal; 
    char *userName; 
};

//Player Functions 
void InitPlayer(int itemamnt[],char *backpckarr[]) {
	int x;
    for (x = 0; x<11;x++) {
        itemamnt[x] = 1;
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
        case 7: 
        	backpckarr[7] = "Fire Chakra        ";
        	break;
        case 8: 
        	backpckarr[8] = "Water Chakra       ";
        	break;
        case 9: 
        	backpckarr[9] = "Earth Chakra       ";
        	break;
        case 10: 
        	backpckarr[10] = "Air Chakra         ";
        	break;
        default:
            break;
        } 
    }
}
void ShowInventory(char *backpackarray[],int itemamount[]){
	int x;
	printf("          ||Inventory||       \n");
    printf("||Item||                ||Amount||\n");
     for (x = 0; x<11;x++) {
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
    printf("[4] Shop          \n"); 
    printf("[6] Exit game     \n");
    printf("---------------------------------------------------------\n");
}
void ViewLocations() {
	printf("||Locations||\n");
    printf("[1] Taal Lake\n"); 
    printf("[2] Galathea Deep\n");
    printf("[3] Dagupan Mongrove Forests\n");
    printf("[4] Mindanao Current\n");
}
void Taal(){
    printf("||Fishing Area||\n");
}
void Galathea(){
    printf("Hello galathea\n");
}
void Dagupan(){
    printf("Hello dagupan\n");
}
void Mindanao(){
    printf("Hello Mindanao\n");
}
void Craft(char *backpackarray[],int itemamount[]) {
	printf("                                  <----Loots---->                                    \n");
	ShowInventory(backpackarray,itemamount);
	printf("-------------------------------------------------------------------------------------\n");
	printf("Requirements: Fire Chakra: \n");
    printf("1x Scaleless Blackfish\n1x Gold\n1x Majestic Water\n1x Wondrous Vinegar\n");
    printf("[1] Craft Fire Chakra\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("Requirements: Water Chakra: \n");
 	printf("1x Mariana Snailfish\n1x Gold\n1x Majestic Water\n1x Wondrous Vinegar\n");
	printf("[2] Craft Water Chakra\n");
    printf("--------------------------------------------------------------------------------\n");
	printf("Requirements: Earth Chakra: \n");
	printf("1x Mudskippers\n1x Gold\n1x Majestic Water\n1x Wondrous Vinegar\n");
	printf("[3] Craft Fire Chakra\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("Requirements: Air Chakra: \n");
	printf("1x Hillstream Loaches\n1x Gold\n1x Majestic Water\n1x Wondrous Vinegar\n");
	printf("[4] Craft Fire Chakra\n");
	printf("--------------------------------------------------------------------------------\n");
}
void CraftFire(int itemamount[]){ 
		if (itemamount[0] >= 1 && itemamount[1] >=1 && itemamount[2] >=1 && itemamount[3] >= 1){
			itemamount[0]--; //Scaleless Blackfish
			itemamount[1]--; //Gold
			itemamount[2]--; //Majestic water
			itemamount[3]--; //Wondrous Vinegar
			itemamount[7]++; //Fire Chakra
			printf("Success!\n");
		}else {
			printf("Not enough resources!\n");
		}
}
void CraftWater(int itemamount[]){
		if (itemamount[4] >= 1 && itemamount[1] >=1 && itemamount[2] >=1 && itemamount[3] >= 1){
			itemamount[4]--; //Mariana Snailfish
			itemamount[1]--; //Gold
			itemamount[2]--; //Majestic water
			itemamount[3]--; //Wondrous Vinegar
			itemamount[8]++; //Water Chakra
			printf("Success!\n");
		}else {
			printf("Not enough resources!\n");
		}
}
void CraftEarth(int itemamount[]){
		if (itemamount[5] >= 1 && itemamount[1] >=1 && itemamount[2] >=1 && itemamount[3] >= 1){
			itemamount[5]--; //Mudskippers
			itemamount[1]--; //Gold
			itemamount[2]--; //Majestic water
			itemamount[3]--; //Wondrous Vinegar
			itemamount[9]++; //Earth Chakra
			printf("Success!\n");
		}else {
			printf("Not enough resources!\n");
		}
}
void CraftAir(int itemamount[]){
		if (itemamount[6] >= 1 && itemamount[1] >=1 && itemamount[2] >=1 && itemamount[3] >= 1){
			itemamount[6]--; //Scaleless Blackfish
			itemamount[1]--; //Gold
			itemamount[2]--; //Majestic water
			itemamount[3]--; //Wondrous Vinegar
			itemamount[10]++; //Air Chakra
			printf("Success!\n");
		}else {
			printf("Not enough resources!\n");
		}
}

void MainMenu(char *backpackarray[],int itemamount[]) {
   int choice; 
   bool exit = false;
   while (!exit) {
   		ViewNavigator();
   		scanf("%d",&choice);
   		if (choice == 1) {
   			int c;
   			ViewLocations();
			printf("<----[5] Return---->\n");
			scanf("%d",&c);
			while(c!=5){
				printf("Not in the choices!\n");
				printf("[5] Return ");
				scanf("%d",&c);
			}
			 	
		}else if(choice == 2){
			int c;
			ShowInventory(backpackarray,itemamount);
			printf("       <----[1] Return---->       \n");
			scanf("%d",&c);
			while(c!=1){
				printf("Not in the choices!\n");
				printf("[1] Return ");
				scanf("%d",&c);
			}
		}else if(choice == 3){
			int c;
			while(c!=5) {
				char enterPressed;
				Craft(backpackarray,itemamount);
				printf("       <----[5] Return---->       \n");
				scanf("%d",&c);
				if (c == 1) {
					CraftFire(itemamount);
				}else if (c == 2) {
					CraftWater(itemamount);
				}else if (c == 3) {
					CraftEarth(itemamount);
				}else if (c == 4){
					CraftAir(itemamount);
				}
			}
		}else if (choice == 4) {
			
			
		}else if (choice == 6) {
			exit = true; 
			
		}else {
			printf("Not a choice!\n");
		}
   		
   }
}


//Game resources 



int main() {
     
    //Player init 
    struct UserProfile player1;
    InitPlayer(player1.itemAmount,player1.userInventory);
    player1.userBal = 20.0; 
//	ShowInventory(player1.userInventory,player1.itemAmount);
	MainMenu(player1.userInventory,player1.itemAmount);



   

   
    return 0; 
}

