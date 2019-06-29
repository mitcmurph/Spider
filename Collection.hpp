#ifndef COLLECTION_H
#define COLLECTION_H

#include "Card.hpp"
#include "Iterator.hpp"
#include "Stack.hpp"
#include <vector>
#include <stack>
#include <iostream>

class Collection : public Stack<Card> {
private:
    std::vector<Card* >& cards;

    bool visible;
public:
    Collection();
    ~Collection();

    bool consecutive(Collection*);
    bool same_suit(Collection*);
    bool can_merge(Collection*);
    bool can_rest(Collection*);
    void merge(Collection*);
    bool is_visible();
    void make_visible();
    Collection* split(int);

    Iterator<Card> begin();
    Iterator<Card> end();
};

Collection::Collection() : visible(false), cards(v) {

}
Collection::~Collection(){
    for (auto card : cards){
        delete card;
    }
}
bool Collection::consecutive(Collection* other){
    return ((*this->cards[this->cards.size()-1]).get_rank() - 1 == (*other->cards[0]).get_rank());
}
bool Collection::same_suit(Collection* other){
    return ((*this->cards[this->cards.size()-1]).get_suit() == (*other->cards[0]).get_suit());
}
bool Collection::can_merge(Collection* other){
    return consecutive(other) && same_suit(other);
}
bool Collection::can_rest(Collection* other){
    return consecutive(other);
}
void Collection::merge(Collection * other){
    for (auto card : other->cards){
        this->cards.push_back(card);
    }
}
bool Collection::is_visible(){
    return visible;
}
void Collection::make_visible(){
    visible = true;
}
Collection* Collection::split(int k){
    Collection* collection = new Collection();
    std::stack<Card *> temp;
    for (int i = cards.size()-1; i > (size() - k - 1); i--){
        temp.push(top());
        pop();
    }
    while(!temp.empty()){
        collection->push(temp.top());
        temp.pop();
    }
    return collection;
}

Iterator<Card> Collection::begin() {
	return Iterator<Card>(cards, 0); 
}
Iterator<Card> Collection::end() {
	return Iterator<Card>(cards, cards.size()); 
}

#endif