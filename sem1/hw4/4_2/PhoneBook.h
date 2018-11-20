#pragma once

#include "list.h"

struct PhoneBook 
{
	List *body;
};

PhoneBook *createPhoneBook();

void getNumber(PhoneBook *phoneBook);
void getName(PhoneBook *phoneBook);
void addSubscriber(PhoneBook *phoneBook);
void getBookFromFile(PhoneBook *phoneBook);
void saveBookToFile(PhoneBook *phoneBook);
