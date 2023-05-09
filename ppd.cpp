#include <iostream>
#include "Purchase.h"
/**
 * manages the running of the program, initialises data structures, loads
 * data, display the main menu, and handles the processing of options. 
 * Make sure free memory and close all files before exiting the program.
 **/
int main(int argc, char **argv)
{
    /* validate command line arguments */
    // TODO
    LinkedList stockList;
    LinkedList coinList;
    // Check if 3 command line parameters have been entered
    if (argc != 3 && argc !=  5){
        std::cerr << "Error:invalid arguments passed in. " << std::endl;
        std::cerr << "Correct arguments are:"<< std::endl << argv[0] << " <stockfile> <coinsfile>" << std::endl;
        std::cerr << "Where <stockfile> and <coinfile> are two valid files in the expected format." << std::endl;
        exit(0);
    }
    bool cin_or_path = true;
    const char* StockFile = argv[1];
    const char* CoinsFile = argv[2];

    std::string input_path;
    std::string output_path;
    if(argc == 5)
    {
        cin_or_path = false;
        input_path = argv[3];
        output_path = argv[4];
    }
    

    stockList.loadStockData(StockFile);
    coinList.loadCoinsData(CoinsFile);  

    Cin m_cin(input_path,cin_or_path);
    Display display(output_path,cin_or_path);
    Purchase purchase(stockList,coinList,m_cin,display);

    display.show_menu();

    int num = 0;
    std::string num_s;
    while(true)
    {
        // num_s = purchase.get_cin();
        num_s = m_cin.get_cin();
        num = std::stoi(num_s);
        if(num == 1)
        {

        }
        else if(num == 2)
        {
            purchase.purchase_room();
        }
        else if(num == 3)
        {
            stockList.saveStockData(StockFile);
            coinList.saveCoinsData(CoinsFile);
            stockList.freeMemory();
            coinList.freeMemory();
            exit(0);
        }
        else if(num == 4)
        {
            
        }
        else if(num == 5)
        {
            
        }
        else if(num == 6)
        {   
            coinList.displayCoins(coinList);         
            //display.show_menu();
        }
        else if(num == 7)
        {   
            
            Node* current = stockList.getHead();
            while (current != NULL) {
            Stock* stock = current->data;
            stock->ResetStock(stock);
            //std::cout << stock->on_hand << std::endl;
            current = current->next;
            }
            std::cout << "“All stock has been reset to the default level of " << DEFAULT_STOCK_LEVEL << "”" << std::endl;
            //display.show_menu();
            
        }
        else if(num == 8)
        {
            //coin->ResetCoins(coin);

            Node* current = coinList.getHead();
            while (current != NULL) {
            Coin* coin = current->data1;
            coin->ResetCoins(coin);
            //std::cout << stock->on_hand << std::endl;
            current = current->next;
            }
            std::cout << "“All coins has been reset to the default level of " << DEFAULT_COIN_COUNT << "”" << std::endl;
            //display.show_menu();
        }
        else if(num == 9)
        {
            
        }
          display.show_menu();
    }


}
