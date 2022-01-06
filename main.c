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
	printf("<----[6] Back---->\n");
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
	ViewStatus(ymir);
	printf("=======================================\n");
	printf("Items to buy: \n");
	printf("[1] Gold ---- 750 Ymir\n[2] Majestic Water ---- 100 Ymir\n[3] Wondrous Vinegar ---- 150\n[4] Magical Bait ---- 300 Ymir\n[5] Cancel\n");
}

void ViewSell( char *backpackarray[],int itemamount[]) {
	if (itemamount[1] > 0 || itemamount[2] > 0 || itemamount[3] > 0 || itemamount[15] > 0) {
		int counter; 
		printf("<----Items to sell---->\n");
		for (counter = 1; counter < 4; counter++){
			if (itemamount[counter] > 0 ) {
				if (counter == 1) {
					printf("[1] Gold (750 Ymir) -> ");
					printf("%d\n",itemamount[counter]);
				}else if (counter == 2) {
					printf("[2] Majestic Water (100 Ymir) -> ");
					printf("%d\n",itemamount[counter]);
				}else if (counter == 3) {
					printf("[3] Wondrous Vinegar (150 Ymir) -> ");
					printf("%d\n",itemamount[counter]);
				}
			}
		}
		if (itemamount[15] > 0) {
			printf("[4] Magical Bait (300 Ymir) -> ");
			printf("%d\n",itemamount[15]);
			printf("=======================================\n");
			
		}
		printf("[5] Cancel\n");
	}
}

void ViewTaal(double ymir,int itemamount[]) {
		printf("Welcome to Taal Lake\n");
   		ViewStatus(ymir);
   		printf("\n[1] Fish\n[2] Sell \n[3] Back\n");
}
void Taal_Fishing( int itemamount[]) {
	//Rand Settings
	srand(time(NULL));
	
	//Variables
	char bait;
	bool isMagicalBaitUsed;
	float CHANCE_WITHOUT_SPECIALBAIT = 0.1, CHANCE_WITH_SPECIALBAIT = 0.3;
	
	printf("<----Fishing----> \n");
    printf("Magical Bait: ");
    printf("%d\n",itemamount[15]);	
    if (itemamount[15] > 0) {
    	printf("Use Magical bait? [Y or N]\n");
    	scanf(" %c",&bait);
    	if (bait == 'Y' || bait == 'y') {
    		isMagicalBaitUsed = true; 
    		itemamount[15]--;
		}else if (bait == 'N' || bait == 'n') isMagicalBaitUsed = false;
		else {
			printf("Not in the choices\n");
			isMagicalBaitUsed = false;
		}
	}else isMagicalBaitUsed = false;
	
	//Fishing Algorithm 
	if (isMagicalBaitUsed) {
		if ((float)((rand()%100)) <= CHANCE_WITH_SPECIALBAIT * 100) {
			printf("Congratulations! You have caught a rare Scaless Blackfish!!\n");
			itemamount[0]++;
		}else {
			printf("Congratulations! You have caught Tilapia \n");
			itemamount[11]++;
		}
	}else if (!isMagicalBaitUsed) {
		if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
			printf("Congratulations! You have caught a rare Scaless Blackfish!!\n");
			itemamount[0]++;
		}else {
			printf("Congratulations! You have caught Tilapia! \n");
			itemamount[11]++;
		}
	}
}

//Galathea
void ViewGalathea(double ymir,int itemamount[]) {
		printf("Welcome to Galathea!\n");
   		ViewStatus(ymir);
   		printf("\n[1] Fish\n[2] Sell \n[3] Back\n");
}
void Galathea_Fishing( int itemamount[]) {
	//Rand Settings
	srand(time(NULL));
	
	//Variables
	char gBait;
	bool isMagicalBaitUsedG;
	float CHANCE_WITHOUT_SPECIALBAIT = 0.1, CHANCE_WITH_SPECIALBAIT = 0.3;
	
	printf("<----Fishing----> \n");
    printf("Magical Bait: ");
    printf("%d\n",itemamount[15]);	
    if (itemamount[15] > 0) {
    	printf("Use Magical bait? [Y or N]\n");
    	scanf(" %c",&gBait);
    	if (gBait == 'Y' || gBait == 'y') {
    		isMagicalBaitUsedG = true; 
    		itemamount[15]--;
		}else if (gBait == 'N' || gBait == 'n') isMagicalBaitUsedG = false;
		else {
			printf("Not in the choices\n");
			isMagicalBaitUsedG = false;
		}
	}else isMagicalBaitUsedG = false;
	
	//Fishing Algorithm 
	if (isMagicalBaitUsedG) {
		if ((float)((rand()%100)) <= CHANCE_WITH_SPECIALBAIT * 100) {
			printf("Congratulations! You have caught a rare Mariana Snailfish!!\n");
			itemamount[4]++;
		}else {
			printf("Congratulations! You have caught Sardines \n");
			itemamount[12]++;
		}
	}else if (!isMagicalBaitUsedG) {
		if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
			printf("Congratulations! You have caught a rare Mariana Snailfish!!\n");
			itemamount[4]++;
		}else {
			printf("Congratulations! You have caught Sardines! \n");
			itemamount[12]++;
		}
	}
}

//Dagupan 
void ViewDagupan(double ymir,int itemamount[]) {
		printf("Welcome to Dagupan!\n");
   		ViewStatus(ymir);
   		printf("\n[1] Fish\n[2] Sell \n[3] Back\n");
}
void Dagupan_Fishing( int itemamount[]) {
	//Rand Settings
	srand(time(NULL));
	
	//Variables
	char dBait;
	bool isMagicalBaitUsedD;
	float CHANCE_WITHOUT_SPECIALBAIT = 0.1, CHANCE_WITH_SPECIALBAIT = 0.3;
	
	printf("<----Fishing----> \n");
    printf("Magical Bait: ");
    printf("%d\n",itemamount[15]);	
    if (itemamount[15] > 0) {
    	printf("Use Magical bait? [Y or N]\n");
    	scanf(" %c",&dBait);
    	if (dBait == 'Y' || dBait == 'y') {
    		isMagicalBaitUsedD = true; 
    		itemamount[15]--;
		}else if (dBait == 'N' || dBait == 'n') isMagicalBaitUsedD = false;
		else {
			printf("Not in the choices\n");
			isMagicalBaitUsedD = false;
		}
	}else isMagicalBaitUsedD = false;
	
	//Fishing Algorithm 
	if (isMagicalBaitUsedD) {
		if ((float)((rand()%100)) <= CHANCE_WITH_SPECIALBAIT * 100) {
			printf("Congratulations! You have caught a rare Mariana Snailfish!!\n");
			itemamount[5]++;
		}else {
			printf("Congratulations! You have caught Sardines \n");
			itemamount[13]++;
		}
	}else if (!isMagicalBaitUsedD) {
		if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
			printf("Congratulations! You have caught a rare Mariana Snailfish!!\n");
			itemamount[5]++;
		}else {
			printf("Congratulations! You have caught Bangus! \n");
			itemamount[13]++;
		}
	}
}

//Mindanao Current 
void ViewMindanao(double ymir,int itemamount[]) {
		printf("Welcome to Dagupan!\n");
   		ViewStatus(ymir);
   		printf("\n[1] Fish\n[2] Sell \n[3] Back\n");
}
void Mindanao_Fishing( int itemamount[]) {
	//Rand Settings
	srand(time(NULL));
	
	//Variables
	char mBait;
	bool isMagicalBaitUsedM;
	float CHANCE_WITHOUT_SPECIALBAIT = 0.1, CHANCE_WITH_SPECIALBAIT = 0.3;
	
	printf("<----Fishing----> \n");
    printf("Magical Bait: ");
    printf("%d\n",itemamount[15]);	
    if (itemamount[15] > 0) {
    	printf("Use Magical bait? [Y or N]\n");
    	scanf(" %c",&mBait);
    	if (mBait == 'Y' || mBait == 'y') {
    		isMagicalBaitUsedM = true; 
    		itemamount[15]--;
		}else if (mBait == 'N' || mBait == 'n') isMagicalBaitUsedM = false;
		else {
			printf("Not in the choices\n");
			isMagicalBaitUsedM = false;
		}
	}else isMagicalBaitUsedM = false;
	
	//Fishing Algorithm 
	if (isMagicalBaitUsedM) {
		if ((float)((rand()%100)) <= CHANCE_WITH_SPECIALBAIT * 100) {
			printf("Congratulations! You have caught a rare Hillstream Loach!!\n");
			itemamount[6]++;
		}else {
			printf("Congratulations! You have caught Tuna! \n");
			itemamount[14]++;
		}
	}else if (!isMagicalBaitUsedM) {
		if ((float)((rand()%100)) <= CHANCE_WITHOUT_SPECIALBAIT * 100) {
			printf("Congratulations! You have caught a rare Hillstream Loach!!\n");
			itemamount[6]++;
		}else {
			printf("Congratulations! You have caught Tuna! \n");
			itemamount[14]++;
		}
	}
}

void HolgrehennStoreView() {
	printf("Welcome to Holgrehenn Store!\n");
	printf("[1] Buy\n[2] Sell\n");
	printf("<---[3] Exit--->\n");
}

int main() {
    //Player init   
    struct UserProfile player1;
    InitPlayer(player1.itemAmount,player1.userInventory);
    float CHANCE_WITHOUT_SPECIALBAIT = 0.1, CHANCE_WITH_SPECIALBAIT = 0.3;
    int mainChoice;
    ViewNavigator(player1.userBal);
   	while (mainChoice != 6) { // Main Lobby
   		scanf("%d",&mainChoice);
   		if (mainChoice == 1) { // Travel Options
   			//Variables
   			int travelChoice;
   			ViewLocations();
   			travelChoice = 0; // Resetting to 0 for the user to be able to go back and forth Travel Options
   			
   			//Select Place Algorithm
   			while (travelChoice != 5) {
   				scanf("%d",&travelChoice);
   				if (travelChoice == 1) {
   					//Variables
   					int taal_Choice; 
   					
   					ViewTaal(player1.userBal,player1.itemAmount);
   					taal_Choice = 0; //Same reason as aforementioned
   					
   					//Action Algorithm (Fishing and selling) 
   					while (taal_Choice != 3) {
   						scanf("%d",&taal_Choice);
   						
   						// Fishing Algorithm
   						if (taal_Choice == 1) {
   							Taal_Fishing(player1.itemAmount);
						}else if (taal_Choice == 2) {
						//Sell Algorithm
							//Variables
							int sell_Choice; 
							sell_Choice = 0; //Reset
							
							if (player1.itemAmount[0] > 0 || player1.itemAmount[11] > 0) {
								printf("<----Items to Sell---->\n");
								
								//   View Items to sell
									if (player1.itemAmount[0] > 0) { // Scaless Blackfish view
										printf("[1] Scaless Blackfish: ");
										printf("%d\n",player1.itemAmount[0]);
									}
									if (player1.itemAmount[11] > 0) { // Tilapia View
										printf("[2] Tilapia: ");
										printf("%d\n",player1.itemAmount[11]);
									}
									printf("<---Cancel Transaction--->\n");
								//   Sell
									scanf("%d",&sell_Choice);
										if (sell_Choice == 1) {
											player1.itemAmount[0]--;
											Sell(&player1.userBal,1000.0);
											printf("Sold!\n");
										}else if (sell_Choice == 2) {
											player1.itemAmount[11]--;
											Sell(&player1.userBal,35.0);
											printf("Sold!\n");
										}else printf("Transaction Cancelled.\n");
							}else printf("Nothing to sell.\n");
													
						}
						ViewTaal(player1.userBal,player1.itemAmount);
					   }
				ViewLocations(); // Return to travel locations
   					
				
				}else if(travelChoice == 2){ //Galathea
					
					//Variables
   					int galathea_Choice; 
   					
   					ViewGalathea(player1.userBal,player1.itemAmount);
   					galathea_Choice = 0; //Same reason as aforementioned
   					
   					//Action Algorithm (Fishing and selling) 
   					while (galathea_Choice != 3) {
   						scanf("%d",&galathea_Choice);
   						
   						// Fishing Algorithm
   						if (galathea_Choice == 1) {
   							Galathea_Fishing(player1.itemAmount);
						}else if (galathea_Choice == 2) {
						//Sell Algorithm
							//Variables
							int sell_GChoice; 
							sell_GChoice = 0; //Reset
							
							if (player1.itemAmount[4] > 0 || player1.itemAmount[12] > 0) {
								printf("<----Items to Sell---->\n");
								
								//   View Items to sell
									if (player1.itemAmount[4] > 0) { // Mariana Snailfish view
										printf("[1] Mariana Snailfish: ");
										printf("%d\n",player1.itemAmount[4]);
									}
									if (player1.itemAmount[12] > 0) { // Sardines View
										printf("[2] Sardines: ");
										printf("%d\n",player1.itemAmount[12]);
									}
									printf("<---Cancel Transaction--->\n");
								//   Sell
									scanf("%d",&sell_GChoice);
										if (sell_GChoice == 1) {
											player1.itemAmount[4]--;
											Sell(&player1.userBal,1000.0);
											printf("Sold!\n");
										}else if (sell_GChoice == 2) {
											player1.itemAmount[12]--;
											Sell(&player1.userBal,40.0);
											printf("Sold!\n");
										}else printf("Transaction Cancelled\n");
							}else printf("Nothing to sell.\n");
													
						}
						ViewGalathea(player1.userBal,player1.itemAmount);
					   }
				ViewLocations(); // Return to travel locations
				
				}else if (travelChoice == 3){// Dagupan
					//Variables
   					int dagupan_Choice; 
   					
   					ViewDagupan(player1.userBal,player1.itemAmount);
   					dagupan_Choice = 0; //Same reason as aforementioned
   					
   					//Action Algorithm (Fishing and selling) 
   					while (dagupan_Choice != 3) {
   						scanf("%d",&dagupan_Choice);
   						
   						// Fishing Algorithm
   						if (dagupan_Choice == 1) {
   							Dagupan_Fishing(player1.itemAmount);
						}else if (dagupan_Choice == 2) {
						//Sell Algorithm
							//Variables
							int sell_DChoice; 
							sell_DChoice = 0; //Reset
							
							if (player1.itemAmount[5] > 0 || player1.itemAmount[13] > 0) {
								printf("<----Items to Sell---->\n");
								
								//   View Items to sell
									if (player1.itemAmount[5] > 0) { // Mariana Snailfish view
										printf("[1] Mudskippers - 1000 Ymir: ");
										printf("%d\n",player1.itemAmount[5]);
									}
									if (player1.itemAmount[13] > 0) { // Sardines View
										printf("[2] Bangus - 50 Ymir: ");
										printf("%d\n",player1.itemAmount[13]);
									}
									printf("<---Cancel Transaction--->\n");
								//   Sell
									scanf("%d",&sell_DChoice);
										if (sell_DChoice == 1) {
											player1.itemAmount[5]--;
											Sell(&player1.userBal,1000.0);
											printf("Sold!\n");
										}else if (sell_DChoice == 2) {
											player1.itemAmount[13]--;
											Sell(&player1.userBal,50.0);
											printf("Sold!\n");
										}else printf("Transaction Cancelled\n");
										
							}else printf("Nothing to sell.\n");
													
						}
						ViewGalathea(player1.userBal,player1.itemAmount);
					   }
				ViewLocations(); // Return to travel locations
					
				}else if (travelChoice == 4){
					//Variables
   					int mindanao_Choice; 
   					
   					ViewDagupan(player1.userBal,player1.itemAmount);
   					mindanao_Choice = 0; //Same reason as aforementioned
   					
   					//Action Algorithm (Fishing and selling) 
   					while (mindanao_Choice != 3) {
   						scanf("%d",&mindanao_Choice);
   						
   						// Fishing Algorithm
   						if (mindanao_Choice == 1) {
   							Mindanao_Fishing(player1.itemAmount);
						}else if (mindanao_Choice == 2) {
						//Sell Algorithm
							//Variables
							int sell_MChoice; 
							sell_MChoice = 0; //Reset
							
							if (player1.itemAmount[6] > 0 || player1.itemAmount[14] > 0) {
								printf("<----Items to Sell---->\n");
								
								//   View Items to sell
									if (player1.itemAmount[6] > 0) { // Mariana Snailfish view
										printf("[1] Hillstream Loaches - 1000 Ymir ");
										printf("%d\n",player1.itemAmount[6]);
									}
									if (player1.itemAmount[14] > 0) { // Sardines View
										printf("[2] Tuna - 45 Ymir ");
										printf("%d\n",player1.itemAmount[14]);
									}
									printf("<---Cancel Transaction--->\n");
								//   Sell
									scanf("%d",&sell_MChoice);
										if (sell_MChoice == 1) {
											player1.itemAmount[6]--;
											Sell(&player1.userBal,1000.0);
											printf("Sold!\n");
										}else if (sell_MChoice == 2) {
											player1.itemAmount[14]--;
											Sell(&player1.userBal,45.0);
											printf("Sold!\n");
										}else printf("Transaction Cancelled\n");
										
							}else printf("Nothing to sell.\n");
													
						}
						ViewGalathea(player1.userBal,player1.itemAmount);
					   }
				ViewLocations(); // Return to travel locations
					
				}else printf("Not in the choices\n");
			   }
   			
		   }else if (mainChoice == 2) { // View Inventory
		   		int inventory_Choice;
				ShowInventory(player1.userInventory,player1.itemAmount);
				inventory_Choice = 0; // Reset
				while(inventory_Choice!=1){
					printf("[1] Return ");
					scanf("%d",&inventory_Choice);
				}
		   		
		   }else if (mainChoice == 3) { // Crafting 
		   //   Variables
		   		int craft_Choice;
		   		
		   		Craft(player1.userInventory,player1.itemAmount);
		   		craft_Choice = 0; //Reset
		   		
		   		while (craft_Choice != 6) { // Access functions
		   			scanf("%d",&craft_Choice);
		   			if (craft_Choice == 1) {
		   				CraftFire(player1.itemAmount);
					}else if (craft_Choice == 2) {
						CraftWater(player1.itemAmount);
					}else if (craft_Choice == 3) {
						CraftEarth(player1.itemAmount);
					}else if (craft_Choice == 4) {
						CraftAir(player1.itemAmount);
					}else if (craft_Choice == 5) {
						CraftYmir(player1.itemAmount);
					}else printf("Not in choices\n");
				   }
		   }else if (mainChoice == 4 ) { // Shop
		   	// Variable 
				int store_Choice; 
				
				store_Choice = 0; //Reset
		   		HolgrehennStoreView(); 
		   		while (store_Choice != 3) {
		   			scanf("%d",&store_Choice);
		   			if (store_Choice == 1) {
		   				// Variables for buy
		   				int buy_Choice;
		   				buy_Choice = 0; // Reset
		   				
		   				// Buy Algorithm
		   				ViewBuy(player1.userBal); 
		   				while (buy_Choice != 5) {
		   					scanf("%d",&buy_Choice);
		   					if (buy_Choice == 1) {
		   						Buy(&player1.userBal,750.0);
		   						player1.itemAmount[1]++;
							}else if (buy_Choice == 2) {
								Buy(&player1.userBal,100.0);
								player1.itemAmount[2]++;
							}else if (buy_Choice == 3) {
								Buy(&player1.userBal,150.0);
								player1.itemAmount[3]++;
							}else if (buy_Choice == 4) {
								Buy(&player1.userBal,300.0);
								player1.itemAmount[15]++;
							}
						}
						HolgrehennStoreView(); 
					   }else if (store_Choice == 2) { // Sell
					   // Variables
					   		int sell_Choice;
					   		sell_Choice = 0;
					   		ViewSell(player1.userInventory,player1.itemAmount);
					   		while (sell_Choice != 5) {
					   			scanf("%d",&sell_Choice);
					   			if (sell_Choice == 1) {
					   				Sell(&player1.userBal,750.0);
					   				player1.itemAmount[1]--;
								}else if (sell_Choice == 2) {
									Sell(&player1.userBal,100.0);
									player1.itemAmount[2]--;
								}else if (sell_Choice == 3) {
									Sell(&player1.userBal,150.0);
									player1.itemAmount[3]--;
								}else if (sell_Choice == 4) {
									Sell(&player1.userBal,300.0);
									player1.itemAmount[15]--;
								}
							   }
							   HolgrehennStoreView(); 
					   		
					   }
				   }
		   		
		   		
		   }
		   ViewNavigator(player1.userBal);
	   }

   
    return 0; 
}

