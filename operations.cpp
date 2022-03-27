#include "operations.hpp"
#include <iostream>

using namespace std;

string getUserInput(string userInstructions)
{
  char userInput[100];

  if (userInstructions != "") {
    cout << userInstructions << ": ";
  }

  cin.getline(userInput, 100);
  if (userInput[0] != '\n') {
    return string(userInput);
  }

  return "";
}

void addEntryOperation(AddressBook & addressBook)
{
  string firstName = "";
  string lastName = "";
  string phoneNumber = "";

  firstName = getUserInput("Type entry first name");
  while (firstName == "") {
    firstName = getUserInput("First name is required.\nType entry first name");
  }

  lastName = getUserInput("Type entry last name");
  phoneNumber = getUserInput("Type entry phone number");

  addressBook.addNewEntry(firstName, lastName, phoneNumber);
}

void deleteEntryOperation(AddressBook & addressBook)
{
  string firstName = "";
  string lastName = "";
  string phoneNumber = "";

  firstName = getUserInput("Type entry first name");
  while (firstName == "") {
    firstName = getUserInput("First name is required.\nType entry first name");
  }

  lastName = getUserInput("Type entry last name");

  addressBook.deleteEntry(firstName, lastName);
}

void printAllEntries(AddressBook & addressBook, EntriesOrder entriesOrder)
{
  cout << endl << "----------- ENTRIES -----------" << endl << endl;
  if (entriesOrder == FIRST_NAME) {
    for(AddressBookEntry currentEntry : addressBook.getEntriesInFistNameOrder()) {
      cout << "First name: " << currentEntry.firstName << endl << "Last name: " << currentEntry.lastName << endl << "Phone number: " << currentEntry.phoneNumber << endl;
      cout << endl;
    }
  }
  else {
    for(AddressBookEntry currentEntry : addressBook.getEntriesInLastNameOrder()) {
      cout << "Last name: " << currentEntry.lastName << endl << "First name: " << currentEntry.firstName << endl << "Phone number: " << currentEntry.phoneNumber << endl;
      cout << endl;
    }
  }
  cout << "-------------------------------" << endl << endl;
}

static void printEntries(vector<AddressBookEntry> const & entries, EntriesOrder entriesOrder)
{
  cout << endl << "----------- ENTRIES -----------" << endl << endl;
  cout << endl;
  for(AddressBookEntry currentEntry : entries) {
    if (entriesOrder == FIRST_NAME) {
      cout << "First name: " << currentEntry.firstName << endl << "Last name: " << currentEntry.lastName << endl << "Phone number: " << currentEntry.phoneNumber << endl;
    } else {
      cout << "Last name: " << currentEntry.lastName << endl << "First name: " << currentEntry.firstName << endl << "Phone number: " << currentEntry.phoneNumber << endl;
    }
    cout << endl;
  }
  cout << "-------------------------------" << endl << endl;
}

EntriesOrder getOrderType()
{
  string seletctedOption;
  EntriesOrder entriesOrder;
  cout << "0 - First name order" << endl;
  cout << "1 - Last name order" << endl;
  seletctedOption = getUserInput("Select the order in which to display entries");
  while (seletctedOption == "") seletctedOption = getUserInput("Select the order in which to display entries");
  switch(atoi(seletctedOption.c_str())){
    case 0:
      entriesOrder = FIRST_NAME;
      cout << "First name order selected" << endl;
      break;
    case 1:
      entriesOrder = LAST_NAME;
      cout << "First name order selected" << endl;
      break;
    default:
      entriesOrder = FIRST_NAME;
      cout << "Invalid option. First name order selected" << endl;
      break;
  }
  return entriesOrder;
}

void findEntriesOperation(AddressBook & addressBook, EntriesOrder entriesOrder)
{
  string nameToSearch;
  nameToSearch = getUserInput("Type name to find");
  while (nameToSearch == "") {
    nameToSearch = getUserInput("Name must not be empty.\nType name to find");
  }

  vector<AddressBookEntry> foundEntries = addressBook.findEntryByName(nameToSearch, entriesOrder);
  printEntries(foundEntries, entriesOrder);
}