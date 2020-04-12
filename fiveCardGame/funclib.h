#ifndef FIG1003_H  // 避免重覆包含標頭檔
#define FIG1003_H


struct card
{
	const char* face;
	const char* suit;

	int id;
};


typedef struct card Card;


void shuffle(Card*); 
void deal(const Card*, int quantity);

int giveScore(Card wDeck[], int size);

void fillDeckFaceFirst(Card* wDeck, const char* wFace[], const char* wSuit[]);


int isFlush(Card wDeck[], int size);
int isStraight(Card wDeck[], int size);


int howManyOfaKind(int multipleKind, Card wDeck[], int size);
int determine(Card wDeck[], int size);
void sort(Card wDeck[], int size);
#endif
