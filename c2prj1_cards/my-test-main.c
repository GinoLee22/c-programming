#include <stdio.h>
#include <assert.h>
#include "cards.h"

int main(void) {
  // valid card test
  printf("***** Valid Card Test *****\n");
  card_t valid_card_test;
  valid_card_test.value = VALUE_ACE;
  valid_card_test.suit = SPADES;
  printf("----- test of assert_card_valid() -----\n");
  assert_card_valid(valid_card_test);
  printf("----- assert_card_valid() passed -----\n");

  printf("----- test of value_letter() & suit_letter() -----\n");
  assert(value_letter(valid_card_test) == 'A');
  assert(suit_letter(valid_card_test) == 's');
  printf("----- value_letter() & suit_letter() passed -----\n");

  printf("----- test of card_from_letters() & print_card() -----\n");
  card_t new_card_from_letter = card_from_letters('A', 's');
  print_card(new_card_from_letter);
  printf("The result should be As\n");

  printf("----- test of card_from_num() -----\n");
  card_t new_card_from_number = card_from_num(12);
  print_card(new_card_from_number);
  printf("----- card_from_num() passed -----\n");

  // invalid card test
  printf("\n***** Invalid Card Test *****\n");
  card_t invalid_card_test;
  invalid_card_test.value = 100;
  invalid_card_test.suit = 10;
  printf("----- test of assert_card_valid() -----\n");
  assert_card_valid(invalid_card_test);
}
