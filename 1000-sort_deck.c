#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	/* Compare characters till difference or string end is reached */
	while (*s1 && *s2 && *s1 == *s2)
	{
		/* go to next character in s1 */
		s1++;
		/* go to next character in s2 */
		s2++;
	}

	if (*s1 != *s2)
		/* Return difference of corresponding characters in s1 and s2 */
		return (*s1 - *s2);
	/* If s1 equals s2, return 0 */
	return (0);
}

/**
 * get_value - Gets the numerical value of a card.
 * @card: points to deck_node_t card.
 *
 * Return: number of the card.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);  /* If card value is "Ace", return 0 */
	if (_strcmp(card->card->value, "1") == 0)
		return (1);  /* If card value is "1", return 1 */
	if (_strcmp(card->card->value, "2") == 0)
		return (2);  /* If card value is "2", return 2 */
	if (_strcmp(card->card->value, "3") == 0)
		return (3);  /* If card value is "3", return 3 */
	if (_strcmp(card->card->value, "4") == 0)
		return (4);  /* If card value is "4", return 4 */
	if (_strcmp(card->card->value, "5") == 0)
		return (5);  /* If card value is "5", return 5 */
	if (_strcmp(card->card->value, "6") == 0)
		return (6);  /* If card value is "6", return 6 */
	if (_strcmp(card->card->value, "7") == 0)
		return (7);  /* If card value is "7", return 7 */
	if (_strcmp(card->card->value, "8") == 0)
		return (8);  /* If card value is "8", return 8 */
	if (_strcmp(card->card->value, "9") == 0)
		return (9);  /* If card value is "9", return 9 */
	if (_strcmp(card->card->value, "10") == 0)
		return (10); /* If card value is "10", return 10 */
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11); /* If card value is "Jack", return 11 */
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12); /* If card value is "Queen", return 12 */
	return (13);    /* If card value is unmatched, return 13 */
}


/**
 * insertion_sort_deck_kind - Sorts deck of cards from spades to diamonds.
 * @deck: pointer to deck_node_t doubly-linked list head.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		/* Move present card to top of suite till placed in the correct position */
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			/* Set next node of insert to next node of iter */
			insert->next = iter->next;
			if (iter->next != NULL)
				/* If iter has next node, set its previous node to insert */
				iter->next->prev = insert;
			/* Set previous node of iter to previous node of insert */
			iter->prev = insert->prev;
			/* Set next node of iter to insert */
			iter->next = insert;

			if (insert->prev != NULL)
				/* If insert has a previous node, set its next node to iter */
				insert->prev->next = iter;
			else
				/* If insert is the first node, update the deck head to iter */
				*deck = iter;
			/* Set the previous node of insert to iter */
			insert->prev = iter;
			/* Update insert to the previous node */
			insert = iter->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sorts deck of cards sorted from
 * spades to diamonds from ace to king.
 * @deck: pointer to deck_node_t doubly-linked list head.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	/* Iterate through the deck starting from the second card */
	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		/* Store the next node before reordering */
		tmp = iter->next;
		/* Start with preceding node of the current node */
		insert = iter->prev;

		/* Compare kind and value of cards to ascertain correct position */
		while (insert != NULL &&
				insert->card->kind == iter->card->kind &&
				get_value(insert) > get_value(iter))
		{
			/* Adjust next pointer of preceding node */
			insert->next = iter->next;
			if (iter->next != NULL)
				/* Adjust the previous pointer of the following node */
				iter->next->prev = insert;
			/**
			 * Set previous pointer of the present
			 * node to the previous of preceding node
			 */
			iter->prev = insert->prev;
			/* Set the next pointer of present node to preceding node */
			iter->next = insert;

			if (insert->prev != NULL)
				/* Adjust the next pointer of the preceding node */
				insert->prev->next = iter;
			else
				/* Update deck head if the preceding node is NULL (indicating new head) */
				*deck = iter;
			/* Set the previous pointer of the preceding node to the current node */
			insert->prev = iter;
			/* Move to the previous node */
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Sorts deck of cards from ace to king and
 * from spades to diamonds.
 * @deck: pointer to deck_node_t doubly-linked list head.
 */
void sort_deck(deck_node_t **deck)
{
	/* Check if deck is empty or has only one card */
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	/* Sort the deck according to card kind (spades to diamonds) */
	insertion_sort_deck_kind(deck);

	/* Sort the deck according to card value (ace to king) within each kind */
	insertion_sort_deck_value(deck);
}
