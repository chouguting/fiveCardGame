#include "funclib.h"
#include "testLib.h"

#include <cstdio>

void setupTest3_onePair_1(Card* const wDeck)
{
	wDeck[0].id = 5; //Three of Diamonds
	wDeck[1].id = 8; //Four of Clubs
	wDeck[2].id = 7; //Three of Spades
}

void setupTest3_onePair_2(Card* const wDeck)
{
	wDeck[0].id = 8; //Four of Clubs
	wDeck[1].id = 4; //  Three of Clubs
	wDeck[2].id = 12; //  Five of Clubs
}


void setupTest3_onePair_3(Card* const wDeck)
{
	wDeck[0].id = 4; // Three of Clubs
	wDeck[1].id = 6; // Four of Hearts
	wDeck[2].id = 5; //Three of Spades
}


void setupTest5_fourOfAKind_1(Card* const wDeck)
{
	wDeck[0].id = 1;
	wDeck[1].id = 0;
	wDeck[2].id = 3;
	wDeck[3].id = 4;
	wDeck[4].id = 5;
}


void setupTest5_fourOfAKind_2(Card* const wDeck)
{
	wDeck[0].id = 0;
	wDeck[1].id = 8;
	wDeck[2].id = 4;
	wDeck[3].id = 12;
	wDeck[4].id = 16;
}


void setupTest5_fourOfAKind_3(Card* const wDeck)
{
	wDeck[0].id = 0;
	wDeck[1].id = 28;
	wDeck[2].id = 34;
	wDeck[3].id = 29;
	wDeck[4].id = 33;
}

void testF(Card* const deck)
{
	shuffle(deck);
	test3(deck);
	sort(deck, 3);//�]�w���յP���@��(3�i)
	determine(deck, 3); //�M�w�P���@��(3�i): return true

	setupTest3_onePair_2(deck);   //�]�w���յP���@��(3�i)
	sort(deck, 3);
	determine(deck, 3); //�M�w�P���@��(3�i): return true

	setupTest3_onePair_3(deck);   //�]�w���յP�����O�@��(3�i)
	sort(deck, 3);
	determine(deck, 3); //�M�w�P���@��(3�i): return false

	setupTest5_fourOfAKind_1(deck);		//�]�w���յP���|��
	sort(deck, 5);
	determine(deck, 5);		//�M�w�P���|�� (5�i): return true


	setupTest5_fourOfAKind_2(deck);	//�]�w���յP���|��
	sort(deck, 5);
	determine(deck, 5);		//�M�w�P���|�� (5�i): return true


	setupTest5_fourOfAKind_3(deck);	//�]�w���յP�����O�|��
	sort(deck, 5);
	determine(deck, 5);		//�M�w�P���|�� (5�i): return false

	
}

void test3(Card* const wDeck)
{
	//sort(wDeck, 3);
	wDeck[0].id = 5; //Three of Diamonds
	wDeck[1].id = 8; //Four of Clubs
	wDeck[2].id = 7; //Three of Spades	 //�]�w���յP���@��(3�i)
}
