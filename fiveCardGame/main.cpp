#include <cstdlib>
#include <stdio.h>
#include <time.h>

#include "funclib.h"


int main()
{
	Card deck[52]; //�x�s�o�ӹC�����`�ư�

	//�P��(�Ʀr)
	const char* face[] = {
		"Deuce", "Three",
		"Four", "Five",
		"Six", "Seven", "Eight",
		"Nine", "Ten",
		"Jack", "Queen", "King", "Ace"
	};  

	//�P��(���)
	const char* suit[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

	//�o�Ӱ}�C�s�Ҧ��i�઺�P��(DETERMINE�^�ǬO�o�䪺�s��)
	const char* cardType[] = {"���P", "��l", "�G��", "�T��", "���l", "�P��", "��Ī", "�|��", "�P�ᶶ"};

	//�U�صP�����o��(�McardType��Index�@�P)
	int cardTypeScore[] = {0, 10, 30, 80, 100, 300, 500, 800, 1000};

	srand(time(nullptr)); //BJ4

	printf("�w��Ө�5�i�P���J!!\n"); 

	int operation = 0; //�x�s�C�����a�����
	
	fillDeckFaceFirst(deck, face, suit); //����P����n

	int score = 0; //�x�s���a���`��


	while (true)
	{
		printf("�ثe����: %d\n", score);
		printf("�ʧ@�ﶵ:\n\t(1)���s�}�l(���]�}�l�n��)\n\t(2) �~��U�@�^\n\t(3) �����F\n");
		printf("Input your operation(1~3):"); 
		scanf_s("%d", &operation, 10); //���a��J�ʧ@

		if (operation == 1) //�C�����}�l
		{
			system("cls");
			printf("�C���w����\n");
			score = 0;  //�����k�s
			system("pause");
			system("cls");
		}
		else if (operation == 2) //�C���~��U�@��
		{
			shuffle(deck); //���~�P
			sort(deck, 5); //��e���i�����a���P�A�åB�Ƨ�
			deal(deck, 5); //�⤭�i��P�L�X
			int indexToBeChanged; //indexToBeChanged:�x�s���a�Q�������P
			int changeAmount;    //changeAmount:���a�Q���X�i	 

			printf("�n���X�i�P?? (�����P�п�J0):");
			scanf_s("%d", &changeAmount, 10);

			//���P�@�~
			if (changeAmount > 0 && changeAmount <= 5)
			{
				printf("�n�����ǵP? (��J1~5):");
				Card*  cardChangerPtr = deck + 5;  //����@�i�P��(���P�ؼбq�Ĥ��i�}�l)

				//�}�l���P
				for (int i = 0; i < changeAmount; i++)
				{
					scanf_s("%d", &indexToBeChanged, 10); //�s�J�n�����i�P
					if (indexToBeChanged > 0 && indexToBeChanged <= 5)  //���b�]�p
					{
						indexToBeChanged = indexToBeChanged - 1; //INDEX�|�O��J�ȦA��@

						//SWAP���P(��ܪ��M�ؼеP��)
						Card cardtemp = deck[indexToBeChanged];
						deck[indexToBeChanged] = *cardChangerPtr;
						*cardChangerPtr = cardtemp;
						
						cardChangerPtr++;//���P�ؼд��L�F�ҥH���V�U�@�i
					}
				}
			}


			printf("\n\n���P��\n");


			deal(deck, 5); //�o�P
			sort(deck, 5); //�b�ƧǤ@����P(���i)

			int scoreThisRound = giveScore(deck, 5);//�p�⥻�^�X������
			score = score + scoreThisRound; //�`���n�[�W�o�^�X������
			printf("�P��:%s %d��  �[�W�P�����Ʀ@�[%d��\n", cardType[determine(deck, 5)], cardTypeScore[determine(deck, 5)],
			       scoreThisRound);

			printf("\n�ثe�`����: %d\n", score);
			system("pause");
			system("cls");
		}
		else if (operation == 3) //�����C��
		{
			break; 
		}
	}

	system("cls"); 
	printf("�P�¹C��");
	system("pause");
	return 0;
}
