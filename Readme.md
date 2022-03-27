# Address book programming challenge

This application was writen to demonstrate a fisrt version of an address book based on an interview challenge. The current implementation runs a non persistent address book, which means every time the application is run any previous changes made on previous executions are not saved.

## Building and running the application

The instructions documented in this section were ment to be run on a UNIX based OS terminal

### Building

- Run make

### Running

- Run ./address_book

## Using the application

The application was implemented with a command line interface that guides the user through all the different features. Follow the command line instructions to exploore all the implemented features.

## Design decisions

- The address book was implemented using sets to simplify the process of making sure all entries in the address book were unique
- Two sets are used to store the same entries in the address book: one in first name order and the other in last name oorder. This should improve the speed of querying entries without the need of resorting at runtime everytime the order is swapped. This decision was based on the need to demonstrate the features required for this challenge and could be replaced by an AddressBook class who's order is defined at instantiation time
- The AddressBook::findEntryByName function returns a vector instead of a set to simplify passing the results of this function to any other code that will make use of it without knowing the design of the internal structure of the AddressBook class
- The application was prepopulated with mockup data for quick verification of the features

## Next steps

- Add data persistency, preferably using a cloud based solution
- Add a feature to update the address book
- Refactor AddressBook class to have the entry order defined at instantiation time using a template approach. This should greately improve the quality of the classes code by removing all the order checks
- Improve folder structure of the application
