#include <iostream>
#include <string>
#include "station.cpp"
using namespace std;

class Trip
{

public:
     Station *header;
     Station *trailer;
     int size;
     Trip()
     {
          header = new Station;
          trailer = new Station;
          header->prev = NULL;
          header->next = trailer;
          trailer->prev = header;
          trailer->next = NULL;
          size = 0;
     }

     void printList()
     {
          cout << "[ ";
          Station *ptr = header->next;
          while (ptr != trailer)
          {
               cout << ptr->name << " ";
               ptr = ptr->next;
          }
          cout << "]\n";
     }

     void insert_front(string newItem)
     {
          Station *newStation = new Station;
          newStation->name = newItem;
          newStation->next = NULL;
          newStation->prev = NULL;
          if (header->next == trailer)
          {
               header->next = newStation;
               newStation->next = trailer;
               newStation->prev = header;
               trailer->prev = newStation;
          }
          else
          {
               Station *temp = header->next;
               newStation->prev = header;
               header->next = newStation;
               newStation->next = temp;
               temp->prev = newStation;
          }
          size++;
     }

     void insert_back(string newItem)
     {
          Station *newStation = new Station;
          newStation->name = newItem;
          newStation->next = NULL;
          newStation->prev = NULL;
          if (header->next == trailer)
          {
               header->next = newStation;
               newStation->next = trailer;
               newStation->prev = header;
               trailer->prev = newStation;
          }
          else
          {
               Station *temp = trailer->prev;

               temp->next = newStation;
               newStation->prev = temp;

               newStation->next = trailer;
               trailer->prev = newStation;
          }
          size++;
     }

     void remove_front()
     {
          Station *temp = header->next;
          if (temp->next == trailer)
          {
               header->next = trailer;
               trailer->prev = header;
               delete temp;
          }
          else
          {
               header->next = temp->next;
               header->next->prev = header;
               delete temp;
          }

          size--;
     }

     void remove_back()
     {
          Station *temp = trailer->prev;
          if (header->next == trailer->prev)
          {
               header->next = trailer;
               trailer->prev = header;
               delete temp;
          } else {
               trailer -> prev = temp -> prev;
               temp -> prev -> next = trailer;
               delete temp;

          }
          size--;
     }
          Station* visit(int nStep, string stepText)//RRRTTT
          {
               Station * temp = header -> next;
               int sizeTex = stepText.length();
               if (size != 0){
                    for(int i = 0; i<sizeTex; i++){
                         if(stepText[i] == 'R' && temp -> next != trailer)
                              temp = temp ->next;
                         else if( stepText[i] == 'L' && temp -> prev != header)
                              temp = temp ->prev;
                    }
                          
               }         
               return temp;
          } 
                   
     };          
               

          
     