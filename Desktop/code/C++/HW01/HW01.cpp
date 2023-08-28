#include <iostream>
#include <string>
#include "card.cpp"

using namespace std;

class CardList{

public:
	Card* head;
    Card* cur;
    int size;
    CardList(){
        head = NULL;
        size = 0;
        
    }

	void pop_back(){
        Card *temp;
        if(head != NULL){
            if(head -> next == NULL){
                head = NULL;
            }else{
            temp = head;
            while(temp->next->next != NULL)
                temp = temp->next;
           Card* lastCard = temp -> next;
            temp -> next = NULL;
            free(lastCard);
            size--;
            }
            
        }
    }

    void insert_back(string newItem){
      Card* newCard = new Card;
      newCard -> name = newItem; 
      newCard -> next = NULL; 
      Card* curr = head;
      
        if(head == NULL)
          head = newCard;
        else{
          while (curr -> next != NULL){
              curr = curr -> next;
          }
          curr ->next = newCard;
        }
        
        size++;
      
    }


    void shuffle(int pos){ //1<=pos<=size-1
        if(1<=pos<=size-1){
            Card* cur = head;
            while ( cur -> next != NULL){
                cur = cur -> next;
            }
            cur ->next = head;

            int count = 0;
            Card* temp = head;
            
            while (pos-1 > count){
                temp = temp ->  next;
                count++;
            }
            head = temp -> next;
            temp -> next = NULL;
            }
        
        }
    void printCardList(){
        /*
         DO NOT DELETE OR EDIT
         */
        cout << "[ ";
        Card* ptr = head;
        while(ptr!=NULL){
            cout << ptr->name << " ";
            ptr = ptr->next;
        }
        cout << "]\n";
    }
};
