#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

//User 
struct UserProfile
{
    int itemAmount[16];
    char *userInventory[16];
    double userBal; 
    char *userName; 
};

//Player Functions 
void InitPlayer(int itemamnt[],char *backpckarr[]) {
	int x;
    for (x = 0; x<16;x++) {
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
        default:
            break;
        } 
    }
}
void ShowInventory(char *backpackarray[],int itemamount[]){
	int x;
	printf("          ||Inventory||       \n");
    printf("||Item||                ||Amount||\n");
     for (x = 0; x<16;x++) {
      printf("%s", backpackarray[x]);
      printf("          ");
      printf("%d\n", itemamount[x]);
    }
}

double Sell(double *ymir,double cost){
	return *ymir += cost;
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


void Dagupan(double ymir, char *backpackarray[],int itemamount[]) {
	//(float)((rand()%100)
	float CHANCE_WITHOUT_SPECIALBAIT = 0.1, CHANCE_WITH_SPECIALBAIT = 0.3;
	bool isMagicalBaitUsed;
	char bait;
    printf("Welcome to Taal Lake!\n");
    printf("Current Balance: ");
    printf("%.2f",ymir);
    printf("\n[1] Fish\n[2] Sell \n");
    int choice;
    scanf("%d",&choice);
    if (choice == 1) {
    	printf("<----Start Fishing----> \n");
    	printf("Magical Bait: ");
    	printf("%d\n",itemamount[15]);
    	if (itemamount[15] > 0) {
    		printf("Use Magical Bait? [Y or N]\n");
    		scanf(" %c",&bait);
    		if (bait == 'Y' || bait == 'y') {
				isMagicalBaitUsed = true; 
				itemamount[15]--;
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
				printf("Congratulations! You have caught a rare Mudskippers!!\n");
				itemamount[5]++;
			}else {
				printf("Congratulations! You have caught Bangus! \n");
				itemamount[13]++;
			}
		}else if (!isMagicalBaitUsed) {
			if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
				printf("Congratulations! You have caught a rare Mudskippers!!\n");
				itemamount[5]++;
			}else {
				printf("Congratulations! You have caught Bangus! \n");
				itemamount[13]++;
			}
		}
	}else if (choice == 2) {
		int chooser;
		if (itemamount[5] > 0 || itemamount[13] > 0) {
			printf("<----Items To Sell---->\n");
			if (itemamount[5] > 0) {
				printf("[1] Mudskippers: ");
				printf("%d\n",itemamount[5]);
			}
			if (itemamount[13] > 0) {
				printf("[2] Bangus: ");
				printf("%d\n",itemamount[13]);
			}
			scanf("%d",&chooser);
			if (chooser == 1) {
				itemamount[5]--;
				printf("Sold!\n");
			}
			else if (chooser == 2) {
				itemamount[13]--;
				printf("Sold!\n");
			}
		}else printf("Nothing to sell.\n");
}
}
void Mindanao(double ymir, char *backpackarray[],int itemamount[]) {
	float CHANCE_WITHOUT_SPECIALBAIT = 0.1, CHANCE_WITH_SPECIALBAIT = 0.3;
	bool isMagicalBaitUsed;
	char bait;
    printf("Welcome to Taal Lake!\n");
    printf("Current Balance: ");
    printf("%.2f",ymir);
    printf("\n[1] Fish\n[2] Sell \n");
    int choice;
    scanf("%d",&choice);
    if (choice == 1) {
    	printf("<----Start Fishing----> \n");
    	printf("Magical Bait: ");
    	printf("%d\n",itemamount[15]);
    	if (itemamount[15] > 0) {
    		printf("Use Magical Bait? [Y or N]\n");
    		scanf(" %c",&bait);
    		if (bait == 'Y' || bait == 'y') {
				isMagicalBaitUsed = true; 
				itemamount[15]--;
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
				printf("Congratulations! You have caught a rare Hillstream Loaches!!\n");
				itemamount[6]++;
			}else {
				printf("Congratulations! You have caught Tuna! \n");
				itemamount[14]++;
			}
		}else if (!isMagicalBaitUsed) {
			if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
				printf("Congratulations! You have caught a rare Hillstream Loaches!!\n");
				itemamount[6]++;
			}else {
				printf("Congratulations! You have caught Tuna! \n");
				itemamount[14]++;
			}
		}
	}else if (choice == 2) {
		int chooser;
		if (itemamount[6] > 0 || itemamount[14] > 0) {
			printf("<----Items To Sell---->\n");
			if (itemamount[6] > 0) {
				printf("[1] Hillstream Loaches: ");
				printf("%d\n",itemamount[6]);
			}
			if (itemamount[11] > 0) {
				printf("[2] Tuna: ");
				printf("%d\n",itemamount[14]);
			}
			scanf("%d",&chooser);
			if (chooser == 1) {
				itemamount[6]--;
				printf("Sold!\n");
			}
			else if (chooser == 2) {
				itemamount[14]--;
				printf("Sold!\n");
			}
		}else printf("Nothing to sell.\n");
		
	}
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
void Shop(double ymir, double inventory) {
	printf("");
}


int main() {
     
    //Player init   
    struct UserProfile player1;
    InitPlayer(player1.itemAmount,player1.userInventory);
    float CHANCE_WITHOUT_SPECIALBAIT = 0.1, CHANCE_WITH_SPECIALBAIT = 0.3;
	int choice; 
    bool exit = false;
    while (!exit) {
   		ViewNavigator();
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
    			printf("\n[1] Fish\n[2] Sell \n");
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
    			printf("\n[1] Fish\n[2] Sell \n");
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
							Sell(&player1.userBal,35.0);
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
    			printf("\n[1] Fish\n[2] Sell \n");
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
							Sell(&player1.userBal,35.0);
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
    			printf("\n[1] Fish\n[2] Sell \n");
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
							Sell(&player1.userBal,35.0);
							printf("Sold!\n");
						}
				}else printf("Nothing to sell.\n");
		
	}
}
			   
			   
			printf("<----[5] Return---->\n");
			scanf("%d",&c);
			while(c!=5){
				printf("Not in the choices!\n");
				printf("[5] Return ");
				scanf("%d",&c);
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
			while(c!=5) {
				char enterPressed;
				Craft(player1.userInventory,player1.itemAmount);
				printf("       <----[5] Return---->       \n");
				scanf("%d",&c);
				if (c == 1) {
					CraftFire(player1.itemAmount);
				}else if (c == 2) {
					CraftWater(player1.itemAmount);
				}else if (c == 3) {
					CraftEarth(player1.itemAmount);
				}else if (c == 4){
					CraftAir(player1.itemAmount);
				}
			}
		}else if (choice == 4) {
			
			
		}else if (choice == 6) {
			exit = true; 
			
		}else {
			printf("Not a choice!\n");
		}
   		
   }



   

   
    return 0; 
}

