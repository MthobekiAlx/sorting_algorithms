#include "deck.h"

int _str_cmp(const char *s1, const char *s2);
char g_value(decknode_t *card);
void inserts_s_deck_kind(decknode_t **deck);
void inserts_s_deck_value(decknode_t **deck);
void s_deck(decknode_t **deck);

/**
 * _str_cmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _str_cmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * g_value - Get the numerical value of a card.
 * @card: A pointer to a decknode_t card.
 *
 * Return: The numerical value of the card.
 */
char g_value(decknode_t *card)
{
	if (_str_cmp(card->card->value, "Ace") == 0)
		return (0);
	if (_str_cmp(card->card->value, "1") == 0)
		return (1);
	if (_str_cmp(card->card->value, "2") == 0)
		return (2);
	if (_str_cmp(card->card->value, "3") == 0)
		return (3);
	if (_str_cmp(card->card->value, "4") == 0)
		return (4);
	if (_str_cmp(card->card->value, "5") == 0)
		return (5);
	if (_str_cmp(card->card->value, "6") == 0)
		return (6);
	if (_str_cmp(card->card->value, "7") == 0)
		return (7);
	if (_str_cmp(card->card->value, "8") == 0)
		return (8);
	if (_str_cmp(card->card->value, "9") == 0)
		return (9);
	if (_str_cmp(card->card->value, "10") == 0)
		return (10);
	if (_str_cmp(card->card->value, "Jack") == 0)
		return (11);
	if (_str_cmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * inserts_s_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a decknode_t doubly-linked list.
 */
void inserts_s_deck_kind(decknode_t **deck)
{
	decknode_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * inserts_s_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a decknode_t doubly-linked list.
 */
void inserts_s_deck_value(decknode_t **deck)
{
	decknode_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       g_value(insert) > g_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * s_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a decknode_t doubly-linked list.
 */
void s_deck(decknode_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	inserts_s_deck_kind(deck);
	inserts_s_deck_value(deck);
}
