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
    const char* cardType[] = { "���P","��l","�G��","�T��" ,"���l" ,"�P��" ,"��Ī" ,"�|��" ,"�P�ᶶ" };
    int cardTypeScore[] = { 0,10,30,80,100,300,500,800,1000 };

    srand(time(NULL));

    printf("�w��Ө�5�i�P���J!!\n");
	
    int operation=0;
    fillDeckFaceFirst(deck, face, suit);

    int score = 0;
	
	
	while(1)
	{
        printf("�ثe����: %d\n", score);
        printf("�ʧ@�ﶵ:\n\t(1)���s�}�l(���]�}�l�n��)\n\t(2) �~��U�@�^\n\t(3) �����F\n");
        printf("Input your operation(1~3):");
        scanf_s("%d", &operation, 10);
		if(operation==1)
		{
            system("cls");
            printf("�C���w����\n");
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
			
            printf("�n���X�i�P?? (�����P�п�J0):");
            scanf_s("%d", &changeAmount, 10);
			

			if(changeAmount>0&&changeAmount<=5)
			{
                printf("�n�����ǵP? (��J1~5):");
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
			
            
            printf("\n\n���P��\n");

            
			
            deal(deck, 5);
            sort(deck, 5);
            
            int scoreThisRound = giveScore(deck, 5);
            score = score + scoreThisRound;
            printf("�P��:%s %d��  �[�W�P�����Ʀ@�[%d��\n",cardType[determine(deck,5)], cardTypeScore[determine(deck,5)],scoreThisRound);
            
            printf("\n�ثe�`����: %d\n", score);
            system("pause");
            system("cls");
			
		}else if(operation==3)
		{
            break;
		}
		
	}

    system("cls");																				// �~�P
    printf("�P�¹C��");

    system("pause");
    return 0;
}
