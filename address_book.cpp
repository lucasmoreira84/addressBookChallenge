#include "address_book.hpp"
#include <regex>

AddressBook::AddressBook()
{
  m_entriesInFirstNameOrder.clear();
  m_entriesInLastNameOrder.clear();
}

std::set<AddressBookEntry, FirstNameOrderComparator> const & AddressBook::getEntriesInFistNameOrder() const
{
  return m_entriesInFirstNameOrder;
}

std::set<AddressBookEntry, LastNameOrderComparator> const & AddressBook::getEntriesInLastNameOrder() const
{
  return m_entriesInLastNameOrder;
}

void AddressBook::addNewEntry(std::string firstName, std::string lastName, std::string phoneNumber)
{
  AddressBookEntry newEntry;
  newEntry.firstName = firstName;
  newEntry.lastName = lastName;
  newEntry.phoneNumber = phoneNumber;
  m_entriesInFirstNameOrder.insert(newEntry);
  m_entriesInLastNameOrder.insert(newEntry);
}

void AddressBook::deleteEntry(std::string firstName, std::string lastName)
{
  AddressBookEntry entry;
  entry.firstName = firstName;
  entry.lastName = lastName;
  m_entriesInFirstNameOrder.erase(entry);
  m_entriesInLastNameOrder.erase(entry);
}

std::vector<AddressBookEntry> const & AddressBook::findEntryByName(std::string name, EntriesOrder returnOrder) const
{
  static std::vector<AddressBookEntry> foundEntries;
  foundEntries.clear();
  std::regex searchRegex("^" + name + ".*", std::regex_constants::icase);
  if (returnOrder == FIRST_NAME) {
    for (AddressBookEntry currentEntry : m_entriesInFirstNameOrder) {
      std::string currentEntryFullName = currentEntry.firstName + " " + currentEntry.lastName;
      if (std::regex_match(currentEntry.firstName, searchRegex) || std::regex_match(currentEntry.lastName, searchRegex)) {
        foundEntries.push_back(currentEntry);
      }
    }
  } else {
    for (AddressBookEntry currentEntry : m_entriesInLastNameOrder) {
      if (std::regex_match(currentEntry.firstName, searchRegex) || std::regex_match(currentEntry.lastName, searchRegex)) {
        foundEntries.push_back(currentEntry);
      }
    }
  }
  return foundEntries;
}
