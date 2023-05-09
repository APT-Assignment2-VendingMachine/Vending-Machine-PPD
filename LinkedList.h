#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include "Coin.h"
#include "Display.h"
#include <sstream>
#include <map>

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void loadStockData(const char* filename);
    void loadCoinsData(const char* filename);
    void loadCoinsDataDenom(const char* filename);
    void saveStockData(const char* filename);
    void saveCoinsData(const char* filename);
    void freeMemory();

    // more functions to be added perhaps...
    //Get product information node
    Stock*  find_node(std::string ID);
    //Get the money information
    Coin get_coin(int cn);
    // Use money
    void use_coin(int cn);
    //找零钱
    void change_coin(int cn);

    Denomination get_coin_enum(int cn);

    Node* getHead();

    void displayCoins(LinkedList& coinList);

private:
    // the beginning of the list
    Node* head;
  
    // how many nodes are there in the list?
    unsigned count;
    std::map<int,Coin> m_coins;
};

#endif  // LINKEDLIST_H


