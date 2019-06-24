#ifndef TABLE_H
#define TABLE_H

#include "Card.hpp"
#include "Collection.hpp"
#include "Deck.hpp"
#include "Pile.hpp"
#include <vector>
#include <stack>
#include <iostream>

class Table {
private:
    std::vector<Pile*> table;
    Deck deck;
public:
    Table(Deck &deck);
    void build_table();
    void stock_table();
    void print_table();
};

Table::Table(Deck &deck) : deck(deck){
    build_table();
}

void Table::build_table(){
    for (int i = 0; i < 10; i++){
        Pile *pile = new Pile();
        size_t amount = 3;
        if (i < 4) amount = 4;
        for (int j = 0; j < amount; j++){
            Collection * collection = new Collection(false);
            (*collection).push(deck.deal());
            (*pile).push(collection);
        }
        Collection * collection = new Collection(true);
        (*collection).push(deck.deal());
        (*pile).push(collection);
        table.push_back(pile);
    }
}

void Table::stock_table(){
    
}

void Table::print_table(){
    for (int i = 0; i < 10; i++){
        table[i]->print_pile();
    }
}

#endif