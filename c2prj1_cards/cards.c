#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  /*
  * use assert() to check that the card passed in has valid values
  * value: 2 <= value <= VALUE_ACE
  * suit: SPADES <= suit <= CLUBS
  */
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  // return "";
  /*
  * convert the hand_ranking_t enumerated value passed in to a string
  */
  switch(r) {
    case STRAIGHT_FLUSH:
      return "STRAIGHT_FLUSH";
    case FOUR_OF_A_KIND:
      return "FOUR_OF_A_KIND";
    case FULL_HOUSE:
      return "FULL_HOUSE";
    case FLUSH:
      return "FLUSH";
    case STRAIGHT:
      return "STRAIGHT";
    case THREE_OF_A_KIND:
      return "THREE_OF_A_KIND";
    case TWO_PAIR:
      return "TWO_PAIR";
    case PAIR:
      return "PAIR";
    default:
      return "NOTHING";
  }
}

char value_letter(card_t c) {
  // return 'x';
  /*
  * return the character that textually represents the value of the passed-in card
  */
  char base = '0';
  switch(c.value) {
    case 10:
      return base;
    case VALUE_JACK:
      return 'J';
    case VALUE_QUEEN:
    return 'Q';
    case VALUE_KING:
      return 'K';
    case VALUE_ACE:
      return 'A';
    default:
      return base + c.value;
  }
}


char suit_letter(card_t c) {
  // return 'x';
  /*
  * return the letter that textually represents the suit of the card passed in
  */
  switch(c.suit) {
    case SPADES:
      return 's';
    case HEARTS:
      return 'h';
    case DIAMONDS:
      return 'd';
    case CLUBS:
      return 'c';
    default:
      return 'N';   // not valid
  }
}

void print_card(card_t c) {
  /*
  * print out the textual representation of the card
  */
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  // card_t temp;
  // return temp;
  /*
  * make and return a card_t whose value and suit correspond to the letters passed in
  */
  card_t temp_card;
  switch(value_let) {
    case 'A':
      temp_card.value = VALUE_ACE;
      break;
    case 'K':
      temp_card.value = VALUE_KING;
      break;
    case 'Q':
      temp_card.value = VALUE_QUEEN;
      break;
    case 'J':
      temp_card.value = VALUE_JACK;
      break;
    case '0':
      temp_card.value = 10;
      break;
    default:
      temp_card.value = value_let - '0';
  }
  switch(suit_let) {
    case 's':
      temp_card.suit = SPADES;
      break;
    case 'h':
      temp_card.suit = HEARTS;
      break;
    case 'd':
      temp_card.suit = DIAMONDS;
      break;
    case 'c':
      temp_card.suit = CLUBS;
      break;
    default:
      temp_card.suit = 100;
      printf("Should not enter here!");
  }
  // check
  assert_card_valid(temp_card);
  return temp_card;
}

card_t card_from_num(unsigned c) {
  // card_t temp;
  // return temp;
  /*
  * take a number from 0 (inclusive) to 52 (exclusive) and map it uniquely to
  * a card value/suit combination.
  */
  card_t temp;
  temp.value = c % 13 + 2;
  temp.suit = c / 13;
  return temp;
}
