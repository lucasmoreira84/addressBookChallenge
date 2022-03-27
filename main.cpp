#include <set>
#include <string>
#include <iostream>
#include <regex>
#include "address_book_entry.hpp"
#include "address_book.hpp"
#include "operations.hpp"

using namespace std;

static void addMockupData(AddressBook & addressBook)
{
  addressBook.addNewEntry("Lucas", "Moreira", "123456789");
  addressBook.addNewEntry("Marcos", "Monteiro", "456789123");
  addressBook.addNewEntry("Humberto", "Politi", "789456123");
  addressBook.addNewEntry("Morgana", "Gleibe", "000000000");
  addressBook.addNewEntry("Lucas", "Moreira", "111111111");
}

int main()
{
  AddressBook addressBook;
  string selectedOperationCode;
  EntriesOrder entriesOrder = FIRST_NAME;
  addMockupData(addressBook);
  while (true) {
    cout << "0 - Add entry" << endl;
    cout << "1 - Delete entry" << endl;
    cout << "2 - Find entry" << endl;
    cout << "3 - Swap order in which to display entries [" << ((entriesOrder == FIRST_NAME) ? "First Name]" : "Last Name]") << endl;
    cout << "4 - Print all entries" << endl;
    cout << "5 - Quit" << endl;
    selectedOperationCode = getUserInput("Choose option");
    switch (atoi(selectedOperationCode.c_str())) {
      case 0:
        addEntryOperation(addressBook);
        break;
      case 1:
        deleteEntryOperation(addressBook);
        break;
      case 2:
        findEntriesOperation(addressBook, entriesOrder);
        break;
      case 3:
        entriesOrder = getOrderType();
        break;
      case 4:
        printAllEntries(addressBook, entriesOrder);
        break;
      case 5:
        return 0;
      default:
        continue;
    }
  }
  return 0;
}
