#include "address_book_entry.hpp"
#include "address_book_utils.hpp"
#include <set>
#include <vector>

#ifndef ADDRESS_BOOK_HPP
#define ADDRESS_BOOK_HPP

class AddressBook
{
public:
  AddressBook();

  /**
   * @brief Returns a set of entries in first name alphabetical order
   * @returns Set of AddressBook objects
   */
  std::set<AddressBookEntry, FirstNameOrderComparator> const & getEntriesInFistNameOrder() const;

  /**
   * @brief Returns a set of entries in last name alphabetical order
   * @returns Set of AddressBook objects
   */
  std::set<AddressBookEntry, LastNameOrderComparator> const & getEntriesInLastNameOrder() const;

  /**
   * @brief Adds a new entry to the address book if it already doesn't exist
   * param[in]    firstName   First name of the new entry
   * param[in]    lastName    Last name of the new enty. Empty by default
   * param[in]    phoneNumber Phone number of the new entry. Empty by default
   */
  void addNewEntry(std::string firstName, std::string lastName="", std::string phoneNumber="");

  /**
   * @brief Deletes an entry with an exact first and last name match
   */
  void deleteEntry(std::string firstName, std::string lastName);

  /**
   * @brief Returns a vector of entries when their first or last names partially or fully match
   *        the input name
   * param[in]    name    Name to be matched to entries
   * returns    Vector of matched entries
   */
  std::vector<AddressBookEntry> const & findEntryByName(std::string name, EntriesOrder returnOrder) const;

private:
  std::set<AddressBookEntry, FirstNameOrderComparator> m_entriesInFirstNameOrder;
  std::set<AddressBookEntry, LastNameOrderComparator> m_entriesInLastNameOrder;
};
#endif
