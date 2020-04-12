#include <cstdio>
#include <cstdlib>

#include "funclib.h"

//�x�s�U�صP��������
int cardTypeScore[] = {0, 10, 30, 80, 100, 300, 500, 800, 1000};

//�H�P���Ʀr���u������P�覡(����2,�٧�2,����2,�®�2,����3......)
void fillDeckFaceFirst(Card* const wDeck, const char* wFace[],
                       const char* wSuit[])
{
	int i = 0;
	int j;
	for (j = 0; j < 13; j++)
	{
		int k;
		for (k = 0; k < 4; k++)
		{
			wDeck[i].face = wFace[j]; //�g�J�P���Ʀr
			wDeck[i].suit = wSuit[k]; //�g�J�P�����
			wDeck[i].id = i; //���C�@�i�Pid,�V�j���Pid�V�j(0��52)
			i++;
		}
	}
}


//�H���~�P(�~52�iwDeck���P)
void shuffle(Card* const wDeck)
{
	int i, j;
	Card temp;

	for (i = 0; i <= 51; i++)
	{
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

//�o�P(�owDeck���P�A�@�oquantity�i)
void deal(const Card* const wDeck, int quantity)
{
	int i;

	for (i = 0; i < quantity; i++)
		//�L�X�ĴX�i,�ƻ�P,�M�L��id
		printf("��%d�i�P \t %5s of %-8s \t%d%c", i + 1, wDeck[i].face,
		       wDeck[i].suit, wDeck[i].id, '\n');
}


//�P�_�P��(�^��1�O�A0���O)
int isFlush(Card wDeck[], int size)
{
	int isflush = 1; //�����]�L�O�P��
	int lastSuit = (wDeck[0].id + 1) % 4; //�W�@�i�P�����
	for (int i = 0; i < size; i++)
	{
		//�p�G�ˬd��@�i��⤣�@�˪�,�N�S���P��F
		if ((wDeck[i].id + 1) % 4 != lastSuit)
		{
			isflush = 0;
		}
		lastSuit = (wDeck[i].id + 1) % 4;
	}

	return isflush;
}

//�P�_��(�^��1�O�A0���O)
int isStraight(Card wDeck[], int size)
{
	int isstraight = 1; //�����]�L�O���l

	int lastFace = (wDeck[0].id) / 4; //�W�@�i�P���P���Ʀr
	for (int i = 1; i < size; i++)
	{
		//�p�G�ˬd��@�i�P��W�@�i���s��N���O���F
		if ((wDeck[i].id) / 4 != lastFace + 1)
		{
			isstraight = 0;
		}
		lastFace = (wDeck[i].id) / 4; //�C�ˬd���@�i�o�i�P�N�|�ܦ��U�i���W�@�i�P
	}
	return isstraight;
}


//�P�_�S��(A2345)���� (�^��1�O�A0���O)
int isSpecialStraight(Card wDeck[], int size)
{
	int isspecialstraightraight = 1; //���w�]�L�O�S��


	if (wDeck[0].id / 4 != 0) //�p�G��id�p�����i���Ʀr���O2,�N������
	{
		isspecialstraightraight = 0;
	}

	//�M�W�����@�˪��ˬd�覡(�o���ˬd��˼ƲĤG�i)
	int lastFace = (wDeck[0].id) / 4;
	for (int i = 1; i < size - 1; i++)
	{
		//�p�G�ˬd��@�i�P��W�@�i���s��N���O���F
		if ((wDeck[i].id) / 4 != lastFace + 1)
		{
			isspecialstraightraight = 0;
		}
		lastFace = (wDeck[i].id) / 4; //�C�ˬd���@�i�o�i�P�N�|�ܦ��U�i���W�@�i�P
	}

	//id�̤j�����i�P�Ʀr���ӭn�OA
	if (wDeck[size - 1].id / 4 != 12)
	{
		isspecialstraightraight = 0;
	}
	return isspecialstraightraight;
}


/*�P�_���w�ȼƶq���P�X�{�X��
  �n�P�_��l���ܲĤ@�ӰѼƴN��J2,�T���N3,�|���N4
  (�^�ǭȬO�X�{�F�X��)
*/
int howManyOfaKind(int multipleKind, Card wDeck[], int size)
{
	int howMany = 0; //�X�{�F�X��
	int i = 0;

	//�q��i�Ӷ}�l�����A�ݬO���O�P�Ʀr����n��multipleKind�i
	while (i <= size - multipleKind)
	{
		int currentFace = (wDeck[i].id) / 4; //�x�s�o���ˬd�P���Ʀr
		int sameCount = 0; //�����ݴX�i�@��
		int j = 0;


		while (currentFace == (wDeck[i + j].id) / 4 && j + i < size)
		{
			sameCount++;
			j++;
		}

		//�p�G�@�˼Ʀr���P���ƶq��n�MmultipleKind,�~�⦳���ڭ̭n��
		if (sameCount == multipleKind)
		{
			i = i + multipleKind; //�ˬd�L���P���ΦA�ˬd
			howMany++;
		}
		else
		{
			i = i + sameCount; //�ˬd�L���P���ΦA�ˬd
		}
	}
	return howMany;
}


//�Ƨ�(�bwDeck���Ƨ�size�i)
void sort(Card wDeck[], int size)
{
	int i;

	//���̤p���N���e��
	for (i = 0; i < size - 1; i++)
	{
		Card min = wDeck[i];
		int minIndex = i;
		int j;
		for (j = i; j < size; j++)
		{
			if (wDeck[j].id < min.id)
			{
				min = wDeck[j];
				minIndex = j;
			}
		}
		Card cardTemp;
		cardTemp = wDeck[i];
		wDeck[i] = wDeck[minIndex];
		wDeck[minIndex] = cardTemp;
	}
}


//�P�_wDeck���j�p��size�����ƬO�ƻ�P��
//�^�ǵP����index
int determine(Card wDeck[], int size)
{
	sort(wDeck, size);
	if (isFlush(wDeck, size) == 1 && (isSpecialStraight(wDeck, size) || isStraight(wDeck, size) == 1) && size > 3)
	{
		return 8; //�P�ᶶ 1000��
	}
	if (howManyOfaKind(4, wDeck, size) >= 1)
	{
		return 7; //�|�� 800��
	}
	if (howManyOfaKind(3, wDeck, size) >= 1 && howManyOfaKind(2, wDeck, size) >= 1)
	{
		return 6; //��Ī 500��
	}
	if (isFlush(wDeck, size) == 1 && size > 3)
	{
		return 5; //�P�� 300��
	}
	if ((isSpecialStraight(wDeck, size) == 1 || isStraight(wDeck, size) == 1) && size > 3)
	{
		return 4; //���l 100��
	}
	if (howManyOfaKind(3, wDeck, size) >= 1)
	{
		return 3; //�T�� 80��
	}
	if (howManyOfaKind(2, wDeck, size) == 2)
	{
		return 2; //�G�� 30��
	}
	if (howManyOfaKind(2, wDeck, size) == 1)
	{
		return 1; //��l 10��
	}
	return 0; //���P 0��
}

//���@�յP��,�i������̤j�P�O���@�i
//�Ҧp��Ī�����@�ӤT���[�W�@�ӹ�l�A���n������O�䤤�T�������̤j���i�A�Ӥ��O���i���̤j�����i
//�^�ǬO�̭��n���i��id
Card mostImportantCard(int multipleKind, Card wDeck[], int size)
{
	//�򥻤W�MhowManyOfaKind5��k�@�ˡA���o���O�q�᭱��^��
	int i = size - 1; //�qSize-1�}�l��
	Card veryImoprtantCard = wDeck[i];


	while (i >= multipleKind - 1)
	{
		int currentFace = (wDeck[i].id) / 4;
		int sameCount = 0;
		int j = 0;

		while (currentFace == (wDeck[i - j].id) / 4 && i - j >= 0)
		{
			sameCount++;
			j++;
		}
		if (sameCount == multipleKind)
		{
			veryImoprtantCard = wDeck[i];
			i = i - multipleKind;
			return veryImoprtantCard; //�u�n�@���N����return�F
		}
		i = i - sameCount;
	}
	return veryImoprtantCard;
}

//�n��SORT!!
//�����A�^�ǬO�o�ƵP������(�P�����[�P����)
int giveScore(Card wDeck[], int size)
{
	int type = determine(wDeck, size); //�P�_�P��
	int score = 0;

	//�P������
	if (type == 7) //�|��: �Q��mostImportantCard��X�|�����̤j�����@�i
	{
		score = score + mostImportantCard(4, wDeck, size).id;
	}
	else if (type == 6) //��Ī: �Q��mostImportantCard��X��Ī�̤T�����̤j�����@�i
	{
		score = score + mostImportantCard(3, wDeck, size).id;
	}
	else if (type == 3) //�T��: �Q��mostImportantCard��X�T�����̤j�����@�i
	{
		score = score + mostImportantCard(3, wDeck, size).id;
	}
	else if (type == 2 || type == 1) //���ι�l:���̤j��l���̤j���i
	{
		score = score + mostImportantCard(2, wDeck, size).id;
	}
	else //��L�P��: ����̤j�����@�i
	{
		score = score + (wDeck[size - 1].id);
	}

	score = score + cardTypeScore[type]; //�A�[�W�P������
	return score;
}
