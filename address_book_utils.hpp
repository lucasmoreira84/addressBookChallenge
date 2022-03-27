#include "address_book_entry.hpp"
#include <string>

#ifndef ADDRESS_BOOK_UTILS_HPP
#define ADDRESS_BOOK_UTILS_HPP

enum EntriesOrder
{
  FIRST_NAME,
  LAST_NAME
};

struct FirstNameOrderComparator
{
  bool operator()(AddressBookEntry const & lhsEntry, AddressBookEntry const & rhsEntry) const
  {
    std::string lhsFullName = lhsEntry.firstName + " " + lhsEntry.lastName;
    std::string rhsFullName = rhsEntry.firstName + " " + rhsEntry.lastName;
    return lhsFullName < rhsFullName;
  }
};

struct LastNameOrderComparator
{
  bool operator()(AddressBookEntry const & lhsEntry, AddressBookEntry const & rhsEntry) const
  {
    std::string lhsFullName = lhsEntry.lastName + " " + lhsEntry.firstName;
    std::string rhsFullName = rhsEntry.lastName + " " + rhsEntry.firstName;
    return lhsFullName < rhsFullName;  }
};

#endif