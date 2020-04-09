#include <cstdlib>
#include <stdio.h>
#include <time.h>

#include "funclib.h"
#include "oldLib.h"
#include "testLib.h"

int main()
{
    Card deck[52];
    const char* face[] = {  "Deuce", "Three",
                           "Four", "Five",
                           "Six", "Seven", "Eight",
                           "Nine", "Ten",
                           "Jack", "Queen", "King" ,"Ace" };

    const char* suit[] = {"Clubs","Diamonds","Hearts","Spades"   };			////////////////////
    const char* cardType[] = { "散牌","對子","二對","三條" ,"順子" ,"同花" ,"葫蘆" ,"四條" ,"同花順" };
    int cardTypeScore[] = { 0,10,30,80,100,300,500,800,1000 };

    srand(time(NULL));

    printf("歡迎來到5張牌撲克!!\n");
	
    int operation=0;
    fillDeckFaceFirst(deck, face, suit);

    int score = 0;
	
	
	while(1)
	{
        printf("目前分數: %d\n", score);
        printf("動作選項:\n\t(1)重新開始(重設開始積分)\n\t(2) 繼續下一回\n\t(3) 不玩了\n");
        printf("Input your operation(1~3):");
        scanf_s("%d", &operation, 10);
		if(operation==1)
		{
            system("cls");
            printf("遊戲已重制\n");
            score = 0;
            system("pause");
            system("cls");
		}else if(operation==2)
		{
            shuffle(deck);
            sort(deck, 5);
            deal(deck,5);
            int indexToBeChanged,changeAmount,i;
            Card *cardChangerPtr;
			
            printf("要換幾張牌?? (不換牌請輸入0):");
            scanf_s("%d", &changeAmount, 10);
			

			if(changeAmount>0&&changeAmount<=5)
			{
                printf("要換那些牌? (輸入1~5):");
                cardChangerPtr = deck + 5;
                for (i = 0; i < changeAmount; i++)
                {
                    
                    scanf_s("%d", &indexToBeChanged, 10);
                    if (indexToBeChanged > 0 && indexToBeChanged <= 5)
                    {
                        indexToBeChanged = indexToBeChanged - 1;
                        int changeIndex = 5 + rand() % 47;
                        Card cardtemp = deck[indexToBeChanged];
                        deck[indexToBeChanged] = *cardChangerPtr;
                        *cardChangerPtr = cardtemp;
                        cardChangerPtr++;
                    }
                    

                }
				
			}
			
            
            printf("\n\n換牌後\n");

            
			
            deal(deck, 5);
            sort(deck, 5);
            
            int scoreThisRound = giveScore(deck, 5);
            score = score + scoreThisRound;
            printf("牌型:%s %d分  加上牌面分數共加%d分\n",cardType[determine(deck,5)], cardTypeScore[determine(deck,5)],scoreThisRound);
            
            printf("\n目前總分數: %d\n", score);
            system("pause");
            system("cls");
			
		}else if(operation==3)
		{
            break;
		}
		
	}

    system("cls");																				// 洗牌
    printf("感謝遊玩");

    system("pause");
    return 0;
}
