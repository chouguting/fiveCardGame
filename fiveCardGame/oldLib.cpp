#include "oldLib.h"

//�P�_���X�ӹ�l
int countPairs(Card wDeck[], int size)
{
	int i;
	int pairsCount = 0;
	for (i = 0; i < size - 1; i++)
	{
		int j;
		int sameFaceCount = 0;
		int firstFace = (wDeck[i].id) / 4;
		for (j = i; j < size; j++)
		{
			if (firstFace == (wDeck[j].id) / 4)
			{
				sameFaceCount++;
			}
		}
		if (sameFaceCount == 2)
		{
			pairsCount++;
		}
	}
	return pairsCount;
}

//�P�_�T��
int hasThreeOfaKind(Card wDeck[], int size)
{
	int maxSameCount = 0;
	int i;
	for (i = 0; i < 3; i++)
	{
		int sameCount = 0;
		int firstFace = (wDeck[i].id) / 4;
		int j;
		for (j = 0; j < size; j++)
		{
			if ((wDeck[i].id) / 4 == firstFace) {
				sameCount++;
			}
		}
		if (sameCount > maxSameCount)
		{
			maxSameCount = sameCount;
		}
	}
	if (maxSameCount == 3)
	{
		return 1;
	}
	return 0;
}

//�P�_��Ī
int isFullHouse(Card wDeck[], int size)
{
	int isfullhouse = 1;
	int firstFace = (wDeck[0].id) / 4;
	int secondFace;
	int firstFaceCount = 0;
	int secondFaceCount = 0;
	int i;
	for (i = 1; i < size; i++)
	{
		if ((wDeck[i].id) / 4 != firstFace)
		{
			secondFace = (wDeck[i].id) / 4;
			break;
		}
	}
	//printf("firstFace:%d  secondFace:%d\n", firstFace, secondFace);
	for (i = 0; i < size; i++)
	{

		//printf("\nNow:%d first:%d second:%d\n", (wDeck[i].id) / 4,firstFace,secondFace);
		if ((wDeck[i].id) / 4 == firstFace)
		{
			firstFaceCount++;
		}

		if ((wDeck[i].id) / 4 == secondFace)
		{
			secondFaceCount++;
		}
	}

	//printf("FCOUNT:%d SCOUNT:%d\n",firstFaceCount,secondFaceCount);
	if (firstFaceCount == 3 && secondFaceCount == 2 || firstFaceCount == 2 && secondFaceCount == 3)
	{
		return 1;
	}

	return 0;

}



//�P�_�|��
int hasFourOfaKind(Card wDeck[], int size)
{
	int sameFaceCount = 1;
	int firstFace = (wDeck[0].id) / 4;
	int i;
	for (i = 1; i < 5; i++)
	{
		//printf("firstFace:%d FACE:%d\n", firstFace, (wDeck[i].id));
		if ((wDeck[i].id) / 4 == firstFace)
		{
			sameFaceCount++;
		}
	}
	//printf("sameCount:%d\n", sameFaceCount);
	if (sameFaceCount == 4)
	{
		return 1;
	}


	//�q�ĤG�i�}�l�A�ˬd�@��
	firstFace = (wDeck[1].id) / 4;
	sameFaceCount = 1;
	for (i = 2; i < 5; i++)
	{
		if ((wDeck[i].id) / 4 == firstFace)
		{
			sameFaceCount++;
		}
	}

	//printf("sameCount2:%d\n", sameFaceCount);
	if (sameFaceCount == 4)
	{
		return 1;
	}

	return 0;
}