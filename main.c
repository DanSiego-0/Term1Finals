#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//User 
struct UserProfile
{
    int itemAmount[17];
    char *userInventory[17];
    double userBal; 
};

//Player Functions 
void InitPlayer(int itemamnt[],char *backpckarr[]) {
	int x;
    for (x = 0; x<17;x++) {
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
        case 11:
        	backpckarr[11] = "Tilapia            ";
        	break;
        case 12:
        	backpckarr[12] = "Sardines           ";
        	break;
        case 13: 
        	backpckarr[13] = "Bangus             ";
        	break;
        case 14: 
        	backpckarr[14] = "Tuna               ";
        	break;
        case 15:
        	backpckarr[15] = "Magical Bait       ";
        	break;
        case 16:
        	backpckarr[16] = "Ymir's Avatar Potion ";
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
     for (x = 0; x<17;x++) {
      printf("%s", backpackarray[x]);
      printf("          ");
      printf("%d\n", itemamount[x]);
    }
}

void Sell(double *ymir,double cost){
	*ymir += cost;
}
void Buy (double *ymir, double cost) {
	if (*ymir < cost) printf("Not enough Ymir\n");
	else *ymir -= cost;
}

void ViewStatus(double ymir) {
	printf("======================================================================\n");
	printf("Ymir: ");
	printf("%.2lf\n",ymir);
	printf("======================================================================\n");	
}
//Game Functions
void ViewNavigator(double ymir) {
    printf("||WELCOME TO SECRET POTIONS OF THE GEFFEN WITCHES||\n");
   	ViewStatus(ymir);
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
    printf("[5] Back\n");
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
	printf("==================================================================================================\n");
	printf("<--- GOAL ---->\n");
	printf("Fire Chakra: ");
	printf("%d\n",itemamount[7]);
	printf("Water Chakra: ");
	printf("%d\n",itemamount[8]);
	printf("Earth Chakra: ");
	printf("%d\n",itemamount[9]);
	printf("Air Chakra: ");
	printf("%d\n",itemamount[10]);
	printf("[5] Craft Ymir's Avatar Potion\n");
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
}void CraftYmir(int itemamount[]){
		if (itemamount[7] >= 1 && itemamount[8] >=1 && itemamount[9] >=1 && itemamount[10] >= 1){
			itemamount[7]--; //Scaleless Blackfish
			itemamount[8]--; //Gold
			itemamount[9]--; //Majestic water
			itemamount[10]--; //Wondrous Vinegar
			itemamount[16]++; //Air Chakra
			printf("Success!\n");
		}else {
			printf("Not enough resources!\n");
		}
}

void ViewBuy(double ymir) {
	printf("Ymir: ");
	printf("%.2lf\n",ymir);
	printf("=======================================\n");
	printf("Items to buy: \n");
	printf("[1] Gold ---- 750 Ymir\n[2] Majestic Water ---- 100 Ymir\n[3] Wondrous Vinegar ---- 150\n[4] Magical Bait ---- 300 Ymir\n");
}

void ViewSell( char *backpackarray[],int itemamount[]) {
	if (itemamount[1] > 0 || itemamount[2] > 0 || itemamount[3] > 0 || itemamount[15] > 0) {
		int counter; 
		printf("<----Items to sell---->\n");
		for (counter = 1; counter < 4; counter++){
			if (itemamount[counter] > 0 ) {
				if (counter == 1) {
					printf("[1] Gold -> ");
					printf("%d\n",itemamount[counter]);
				}else if (counter == 2) {
					printf("[2] Majestic Water -> ");
					printf("%d\n",itemamount[counter]);
				}else if (counter == 3) {
					printf("[3] Wondrous Vinegar -> ");
					printf("%d\n",itemamount[counter]);
				}
			}
		}
		if (itemamount[15] > 0) {
			printf("[4] Magical Bait -> ");
			printf("%d\n",itemamount[15]);
			printf("=======================================\n");
			
		}
	}
}


int main() {
     
    //Player init   
    struct UserProfile player1;
    InitPlayer(player1.itemAmount,player1.userInventory);
    float CHANCE_WITHOUT_SPECIALBAIT = 0.1, CHANCE_WITH_SPECIALBAIT = 0.3;
	int choice; 
    while (choice != 6) {
   		ViewNavigator(player1.userBal);
   		scanf("%d",&choice);
   		if (choice == 1) {
   			int c;
   			ViewLocations();
   			scanf("%d",&c);
   			if (c == 1) {
				bool isMagicalBaitUsed;
				char bait;
    			printf("Welcome to Taal Lake!\n");
    			printf("Current Balance: ");
    			printf("%.2lf",player1.userBal);
    			printf("\n[1] Fish\n[2] Sell \n[Any Number] Back\n");
    			int choice;
    			scanf("%d",&choice);
    				if (choice == 1) {
    					printf("<----Start Fishing----> \n");
    					printf("Magical Bait: ");
    					printf("%d\n",player1.itemAmount[15]);
    					if (player1.itemAmount[15] > 0) {
    						printf("Use Magical Bait? [Y or N]\n");
    						scanf(" %c",&bait);
    							if (bait == 'Y' || bait == 'y') {
									isMagicalBaitUsed = true; 
									player1.itemAmount[15]--;
								}
    							else if (bait == 'N' || bait == 'n') isMagicalBaitUsed = false; 
    							else {
									printf("Not in the choices!\n");
									isMagicalBaitUsed = false;
								}
						}else isMagicalBaitUsed = false;
					// Fishing 
					if (isMagicalBaitUsed) {
						if ((float)((rand()%100)) <= CHANCE_WITH_SPECIALBAIT * 100) {
							printf("Congratulations! You have caught a rare Scaless Blackfish!!\n");
							player1.itemAmount[0]++;
						}else {
							printf("Congratulations! You have caught Tilapia! \n");
							player1.itemAmount[11]++;
						}	
					}else if (!isMagicalBaitUsed) {
						if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
						printf("Congratulations! You have caught a rare Scaless Blackfish!!\n");
						player1.itemAmount[0]++;
						}else {
							printf("Congratulations! You have caught Tilapia! \n");
							player1.itemAmount[11]++;
						}
						}
				}else if (choice == 2) {
					int chooser;
					if (player1.itemAmount[0] > 0 || player1.itemAmount[11] > 0) {
						printf("<----Items To Sell---->\n");
							if (player1.itemAmount[0] > 0) {
								printf("[1] Scaless Blackfish: ");
								printf("%d\n",player1.itemAmount[0]);
							}
							if (player1.itemAmount[11] > 0) {
								printf("[2] Tilapia: ");
								printf("%d\n",player1.itemAmount[11]);
							}
					scanf("%d",&chooser);
						if (chooser == 1) {
							player1.itemAmount[0]--;
							Sell(&player1.userBal,1000.0);
							printf("Sold!\n");
						}
						else if (chooser == 2) {
							player1.itemAmount[11]--;
							Sell(&player1.userBal,35.0);
							printf("Sold!\n");
						}
				}else printf("Nothing to sell.\n");
		
 }
		    }else if (c == 2){
				bool isMagicalBaitUsed;
				char bait;
    			printf("Welcome to Galathea Deep!\n");
    			printf("Current Balance: ");
    			printf("%.2lf",player1.userBal);
    			printf("\n[1] Fish\n[2] Sell \n[Any Number] Back\n");
    			int choice;
    			scanf("%d",&choice);
    				if (choice == 1) {
    					printf("<----Start Fishing----> \n");
    					printf("Magical Bait: ");
    					printf("%d\n",player1.itemAmount[15]);
    					if (player1.itemAmount[15] > 0) {
    						printf("Use Magical Bait? [Y or N]\n");
    						scanf(" %c",&bait);
    							if (bait == 'Y' || bait == 'y') {
									isMagicalBaitUsed = true; 
									player1.itemAmount[15]--;
								}
    							else if (bait == 'N' || bait == 'n') isMagicalBaitUsed = false; 
    							else {
									printf("Not in the choices!\n");
									isMagicalBaitUsed = false;
								}
						}else isMagicalBaitUsed = false;
					// Fishing 
					if (isMagicalBaitUsed) {
						if ((float)((rand()%100)) <= CHANCE_WITH_SPECIALBAIT * 100) {
							printf("Congratulations! You have caught a rare Mariana Snailfish!!\n");
							player1.itemAmount[4]++;
						}else {
							printf("Congratulations! You have caught Sardines! \n");
							player1.itemAmount[12]++;
						}	
					}else if (!isMagicalBaitUsed) {
						if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
						printf("Congratulations! You have caught a rare Mariana Snailfish!!\n");
						player1.itemAmount[4]++;
						}else {
							printf("Congratulations! You have caught Sardines! \n");
							player1.itemAmount[12]++;
						}
						}
				}else if (choice == 2) {
					int chooser;
					if (player1.itemAmount[4] > 0 || player1.itemAmount[12] > 0) {
						printf("<----Items To Sell---->\n");
							if (player1.itemAmount[4] > 0) {
								printf("[1] Mariana Snailfish: ");
								printf("%d\n",player1.itemAmount[4]);
							}
							if (player1.itemAmount[12] > 0) {
								printf("[2] Sardines: ");
								printf("%d\n",player1.itemAmount[12]);
							}
					scanf("%d",&chooser);
						if (chooser == 1) {
							player1.itemAmount[4]--;
							Sell(&player1.userBal,1000.0);
							printf("Sold!\n");
						}
						else if (chooser == 2) {
							player1.itemAmount[12]--;
							Sell(&player1.userBal,40.0);
							printf("Sold!\n");
						}
				}else printf("Nothing to sell.\n");
		
	}
			   }else if (c == 3) {
				bool isMagicalBaitUsed;
				char bait;
    			printf("Welcome to Dagupan Mangrove Forests!\n");
    			printf("Current Balance: ");
    			printf("%.2lf",player1.userBal);
    			printf("\n[1] Fish\n[2] Sell \n[Any Number] Back\n");
    			int choice;
    			scanf("%d",&choice);
    				if (choice == 1) {
    					printf("<----Start Fishing----> \n");
    					printf("Magical Bait: ");
    					printf("%d\n",player1.itemAmount[15]);
    					if (player1.itemAmount[15] > 0) {
    						printf("Use Magical Bait? [Y or N]\n");
    						scanf(" %c",&bait);
    							if (bait == 'Y' || bait == 'y') {
									isMagicalBaitUsed = true; 
									player1.itemAmount[15]--;
								}
    							else if (bait == 'N' || bait == 'n') isMagicalBaitUsed = false; 
    							else {
									printf("Not in the choices!\n");
									isMagicalBaitUsed = false;
								}
						}else isMagicalBaitUsed = false;
					// Fishing 
					if (isMagicalBaitUsed) {
						if ((float)((rand()%100)) <= CHANCE_WITH_SPECIALBAIT * 100) {
							printf("Congratulations! You have caught a Mudskipper!!\n");
							player1.itemAmount[5]++;
						}else {
							printf("Congratulations! You have caught Bangus! \n");
							player1.itemAmount[13]++;
						}	
					}else if (!isMagicalBaitUsed) {
						if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
						printf("Congratulations! You have caught a rare Mudskipper!!\n");
						player1.itemAmount[5]++;
						}else {
							printf("Congratulations! You have caught Bangus! \n");
							player1.itemAmount[13]++;
						}
						}
				}else if (choice == 2) {
					int chooser;
					if (player1.itemAmount[5] > 0 || player1.itemAmount[13] > 0) {
						printf("<----Items To Sell---->\n");
							if (player1.itemAmount[5] > 0) {
								printf("[1] Scaless Blackfish: ");
								printf("%d\n",player1.itemAmount[5]);
							}
							if (player1.itemAmount[13] > 0) {
								printf("[2] Tilapia: ");
								printf("%d\n",player1.itemAmount[13]);
							}
					scanf("%d",&chooser);
						if (chooser == 1) {
							player1.itemAmount[5]--;
							Sell(&player1.userBal,1000.0);
							printf("Sold!\n");
						}
						else if (chooser == 2) {
							player1.itemAmount[13]--;
							Sell(&player1.userBal,50.0);
							printf("Sold!\n");
						}
				}else printf("Nothing to sell.\n");
		
	}
			   }else if (c == 4) {
				bool isMagicalBaitUsed;
				char bait;
    			printf("Welcome to Mindanao Current!\n");
    			printf("Current Balance: ");
    			printf("%.2lf",player1.userBal);
    			printf("\n[1] Fish\n[2] Sell \n[Any Number] Back\n");
    			int choice;
    			scanf("%d",&choice);
    				if (choice == 1) {
    					printf("<----Start Fishing----> \n");
    					printf("Magical Bait: ");
    					printf("%d\n",player1.itemAmount[15]);
    					if (player1.itemAmount[15] > 0) {
    						printf("Use Magical Bait? [Y or N]\n");
    						scanf(" %c",&bait);
    							if (bait == 'Y' || bait == 'y') {
									isMagicalBaitUsed = true; 
									player1.itemAmount[15]--;
								}
    							else if (bait == 'N' || bait == 'n') isMagicalBaitUsed = false; 
    							else {
									printf("Not in the choices!\n");
									isMagicalBaitUsed = false;
								}
						}else isMagicalBaitUsed = false;
					// Fishing 
					if (isMagicalBaitUsed) {
						if ((float)((rand()%100)) <= CHANCE_WITH_SPECIALBAIT * 100) {
							printf("Congratulations! You have caught a rare Hillstream Loach!!\n");
							player1.itemAmount[6]++;
						}else {
							printf("Congratulations! You have caught Tuna! \n");
							player1.itemAmount[14]++;
						}	
					}else if (!isMagicalBaitUsed) {
						if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
						printf("Congratulations! You have caught a rare Hillstream Loach!!\n");
						player1.itemAmount[6]++;
						}else {
							printf("Congratulations! You have caught Tuna! \n");
							player1.itemAmount[14]++;
						}
						}
				}else if (choice == 2) {
					int chooser;
					if (player1.itemAmount[6] > 0 || player1.itemAmount[14] > 0) {
						printf("<----Items To Sell---->\n");
							if (player1.itemAmount[6] > 0) {
								printf("[1] Hillstream Loaches: ");
								printf("%d\n",player1.itemAmount[6]);
							}
							if (player1.itemAmount[14] > 0) {
								printf("[2] Tuna: ");
								printf("%d\n",player1.itemAmount[14]);
							}
					scanf("%d",&chooser);
						if (chooser == 1) {
							player1.itemAmount[6]--;
							Sell(&player1.userBal,1000.0);
							printf("Sold!\n");
						}
						else if (chooser == 2) {
							player1.itemAmount[14]--;
							Sell(&player1.userBal,45.0);
							printf("Sold!\n");
						}
				}else printf("Nothing to sell.\n");
		
	}
				}	
			
			 	
		}else if(choice == 2){
			int c;
			ShowInventory(player1.userInventory,player1.itemAmount);
			printf("       <----[1] Return---->       \n");
			scanf("%d",&c);
			while(c!=1){
				printf("Not in the choices!\n");
				printf("[1] Return ");
				scanf("%d",&c);
			}
		}else if(choice == 3){
			int c;
			while(c!=6) {
				char enterPressed;
				Craft(player1.userInventory,player1.itemAmount);
				printf("       <----[6] Return---->       \n");
				scanf("%d",&c);
				if (c == 1) {
					CraftFire(player1.itemAmount);
				}else if (c == 2) {
					CraftWater(player1.itemAmount);
				}else if (c == 3) {
					CraftEarth(player1.itemAmount);
				}else if (c == 4){
					CraftAir(player1.itemAmount);
				}else if (c == 5) {
					CraftYmir(player1.itemAmount);
				}
			}
		}else if (choice == 4) {
			bool isExit = false;
			int choice,choice1;
			while (!isExit) {
				printf("Welcome to Holgrehenn Store!\n");
				printf("[1] Buy\n[2] Sell\n");
				printf("<----[3] Exit---->\n");
				scanf("%d",&choice);
				if (choice == 1) {
					ViewBuy(player1.userBal);
					if (player1.userBal <= 0 ) {
						printf("Not enough Ymir\n");
						isExit = true;
					}else 
						scanf("%d",&choice1);
						if (choice1 == 1) {
							Buy(&player1.userBal,750.0);
							player1.itemAmount[1]++;
						}else if (choice1 == 2) {
							Buy(&player1.userBal,100.0);
							player1.itemAmount[2]++;
						}else if (choice1 == 3) {
							Buy(&player1.userBal,150.0);
							player1.itemAmount[3]++;
						}else if (choice1 == 4) {
							Buy(&player1.userBal,300.0);
							player1.itemAmount[15]++;
						}
				}else if (choice == 2) {
					ViewSell(player1.userInventory,player1.itemAmount);
					int c; 
					scanf("%d",&c);
					if (player1.itemAmount[1] < 1 && player1.itemAmount[2] < 1 && player1.itemAmount[3] < 1 && player1.itemAmount[15] < 1) {
						printf("Sorry you don't have anything to sell.\n");
						isExit = true;
					}else 
						if (c == 1) {
							Sell(&player1.userBal,750.0);
							player1.itemAmount[1]--;
						}else if (c==2) {
							Sell(&player1.userBal,100.0);
							player1.itemAmount[2]--;
						}else if (c==3) {
							Sell(&player1.userBal,150.0);
							player1.itemAmount[3]--;
						}else if (c == 4) {
							Sell(&player1.userBal,300.0);
							player1.itemAmount[15]--;
						}
				}else if (choice == 3) {
					isExit = true;
				}
			}
			
		}else {
			printf("Not a choice!\n");
		}
   		
   }



   

   
    return 0; 
}

