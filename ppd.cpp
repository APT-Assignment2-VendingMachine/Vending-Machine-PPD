#include <iostream>
#include <limits>
#include "LinkedList.h"
#include "Purchase.h"
#include "Display.h"


/**
 * manages the running of the program, initialises data structures, loads
 * data, display the main menu, and handles the processing of options. 
 * Make sure free memory and close all files before exiting the program.
 **/
int main(int argc, char **argv)
{
    /* validate command line arguments */
    // TODO
    LinkedList linkedlist;
    // Check if 3 command line parameters have been entered
    if (argc != 3){
        std::cerr << "Error:invalid arguments passed in. " << std::endl;
        std::cerr << "Correct arguments are:"<< std::endl << argv[0] << " <stockfile> <coinsfile>" << std::endl;
        std::cerr << "Where <stockfile> and <coinfile> are two valid files in the expected format." << std::endl;
        EXIT_FAILURE; 
    }

    const char* StockFile = argv[1];
    const char* CoinsFile = argv[2];

    linkedlist.loadStockData(StockFile);
    linkedlist.loadCoinsData(CoinsFile);  

    Purchase purchase(linkedlist);
    Display display;

    display.show_menu();

    int num = 0;
    while(std::cin>>num)
    {
        if(num == 1)
        {
        std::cout<<"Items Menu\n";
        std::cout<<"----------\n";
        std::cout<<"ID   |Name \t\t\t\t |Available |Price\n";
        std::cout<<"------------------------------------------------------------\n";
        
        linkedlist.displayItems();
        std::cout<<"\n";
        
        display.show_menu();

        }
        else if(num == 2)
        {
            purchase.purchase_room();
        }

        else if(num == 4)
        {
            std::cout<<"You will now add a new stock item to the Vending Machine:\n";

            std::string new_id = "I0006";
            std::string name, desc;
            double price;
            int onHand = 10;

            std::cout<<"The id of the new item will be: " << new_id << "\n";

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter the item name: ";
            std::getline(std::cin, name);

            std::cout << "Enter the item description: ";
            std::getline(std::cin, desc);

            std::cout << "Enter item price (in the format x.yy): ";
            std::cin >> price;

            // Extract dollars and cents from the user-input price
            int dollars = static_cast<int>(price);
            int cents = static_cast<int>((price - dollars) * 100 + 0.5); // Add 0.5 for rounding

            // Add the item to the linked list using the addStock function and user-input parameters
            linkedlist.addStock(new_id, name, desc, dollars, cents, onHand);
            
            std::cout << "This item: \""<< name << " - " << desc << "\" has now been added to the menu.";
            display.show_menu();

        }
        else if(num == 5)
        {
            std::cout<<"You will now remove a stock item from the Vending Machine based on it's given ID:\n";
            
            std::string itemId;
            std::cout << "Enter the ID of the item you want to remove: ";
            std::cin >> itemId;

            if (linkedlist.removeStock(itemId)) {
                std::cout << "Item with ID " << itemId << " has been removed." << std::endl;
            } else {
                std::cout << "Item with ID " << itemId << " not found." << std::endl;
            }
        }
    }


}
