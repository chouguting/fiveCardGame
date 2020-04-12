#include <cstdlib>
#include <stdio.h>
#include <time.h>

#include "funclib.h"


int main()
{
	Card deck[52]; //儲存這個遊戲的總排堆

	//牌面(數字)
	const char* face[] = {
		"Deuce", "Three",
		"Four", "Five",
		"Six", "Seven", "Eight",
		"Nine", "Ten",
		"Jack", "Queen", "King", "Ace"
	};  

	//牌面(花色)
	const char* suit[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

	//這個陣列存所有可能的牌型(DETERMINE回傳是這邊的編號)
	const char* cardType[] = {"散牌", "對子", "二對", "三條", "順子", "同花", "葫蘆", "四條", "同花順"};

	//各種牌型的得分(和cardType的Index一致)
	int cardTypeScore[] = {0, 10, 30, 80, 100, 300, 500, 800, 1000};

	srand(time(nullptr)); //BJ4

	printf("歡迎來到5張牌撲克!!\n"); 

	int operation = 0; //儲存每輪玩家的選擇
	
	fillDeckFaceFirst(deck, face, suit); //先把牌都填好

	int score = 0; //儲存玩家的總分


	while (true)
	{
		printf("目前分數: %d\n", score);
		printf("動作選項:\n\t(1)重新開始(重設開始積分)\n\t(2) 繼續下一回\n\t(3) 不玩了\n");
		printf("Input your operation(1~3):"); 
		scanf_s("%d", &operation, 10); //玩家輸入動作

		if (operation == 1) //遊戲重開始
		{
			system("cls");
			printf("遊戲已重制\n");
			score = 0;  //分數歸零
			system("pause");
			system("cls");
		}
		else if (operation == 2) //遊戲繼續下一輪
		{
			shuffle(deck); //先洗牌
			sort(deck, 5); //把前五張給玩家當手牌，並且排序
			deal(deck, 5); //把五張手牌印出
			int indexToBeChanged; //indexToBeChanged:儲存玩家想換掉的牌
			int changeAmount;    //changeAmount:玩家想換幾張	 

			printf("要換幾張牌?? (不換牌請輸入0):");
			scanf_s("%d", &changeAmount, 10);

			//換牌作業
			if (changeAmount > 0 && changeAmount <= 5)
			{
				printf("要換那些牌? (輸入1~5):");
				Card*  cardChangerPtr = deck + 5;  //跟哪一張牌換(換牌目標從第六張開始)

				//開始換牌
				for (int i = 0; i < changeAmount; i++)
				{
					scanf_s("%d", &indexToBeChanged, 10); //存入要換哪張牌
					if (indexToBeChanged > 0 && indexToBeChanged <= 5)  //防呆設計
					{
						indexToBeChanged = indexToBeChanged - 1; //INDEX會是輸入值再減一

						//SWAP換牌(選擇的和目標牌換)
						Card cardtemp = deck[indexToBeChanged];
						deck[indexToBeChanged] = *cardChangerPtr;
						*cardChangerPtr = cardtemp;
						
						cardChangerPtr++;//換牌目標換過了所以指向下一張
					}
				}
			}


			printf("\n\n換牌後\n");


			deal(deck, 5); //發牌
			sort(deck, 5); //在排序一次手牌(五張)

			int scoreThisRound = giveScore(deck, 5);//計算本回合的分數
			score = score + scoreThisRound; //總分要加上這回合的分數
			printf("牌型:%s %d分  加上牌面分數共加%d分\n", cardType[determine(deck, 5)], cardTypeScore[determine(deck, 5)],
			       scoreThisRound);

			printf("\n目前總分數: %d\n", score);
			system("pause");
			system("cls");
		}
		else if (operation == 3) //結束遊戲
		{
			break; 
		}
	}

	system("cls"); 
	printf("感謝遊玩");
	system("pause");
	return 0;
}
