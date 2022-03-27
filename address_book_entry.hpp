#include <string>

#ifndef ADDRESS_BOOK_ENTRY_HPP
#define ADDRESS_BOOK_ENTRY_HPP

struct AddressBookEntry
{
  std::string firstName;
  std::string lastName;
  std::string phoneNumber;
};

/**
 * @brief   Implements the equals operator for AddressBookEntry objects to ensure
 *          any containers that store unique AddressBookEntry objects use the correct
 *          definition of equal entries
 */
static bool operator==(AddressBookEntry const & lhsEntry, AddressBookEntry const & rhsEntry)
{
  std::string lhsFullName = lhsEntry.firstName + " " + lhsEntry.lastName;
  std::string rhsFullName = rhsEntry.firstName + " " + rhsEntry.lastName;
  return lhsFullName == rhsFullName;
}

#endif
