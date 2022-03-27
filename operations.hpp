#include "address_book.hpp"
#include <vector>
#include <string>

#ifndef OPERATONS_HPP
#define OPERATONS_HPP

/**
 * @brief Add an entry to the address book as per the user's input
 * @param[in]   addressBook   Reference toe the system's address book
 */
void addEntryOperation(AddressBook & addressBook);

/**
 * @brief Delete an entry from the address book as per the user's input
 * @param[in]   addressBook   Reference toe the system's address book
 */
void deleteEntryOperation(AddressBook & addressBook);

/**
 * @brief Prints all entries in the input address book in the specified order
 * @param[in]   addressBook   Reference toe the system's address book
 * @param[in]   entriesOrder  Order in which to print the entries, sorted by first name or last name
 */
void printAllEntries(AddressBook & addressBook, EntriesOrder entriesOrder);

/**
 * @brief   Gets the order in which entries must be printed from the user
 */
EntriesOrder getOrderType();

/**
 * @brief   Finds entries who's full name partially or fully matching the user's input
 * @param[in]   addressBook   Reference toe the system's address book
 * @param[in]   entriesOrder  Order in which to print the entries, sorted by first name or last name
 */
void findEntriesOperation(AddressBook & addressBook, EntriesOrder entriesOrder);

/**
 * @brief   Gets user inputs from the command line
 * @param[in]   userInstructions   Instruction to be printed to the user to ask for the input
 * @returns     A string with the user's input
 */
std::string getUserInput(std::string userInstructions = "");
#endif
