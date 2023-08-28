#include <iostream>
#include "term.cpp"
using namespace std;
class Polynomial
{
public:
    Poly_node *head;
    int size;
    Polynomial()
    {
        head = NULL;
        size = 0;
    }
    void addTerm(int coef, int exponent)
    {

        if (size == 0)
        { // empty list
            Poly_node *newPtr = new Poly_node;
            newPtr->coef = coef;
            newPtr->exponent = exponent;
            head = newPtr;
            size++;
        }
        else

        {
            Poly_node *newPtr = new Poly_node;
            Poly_node *temp = new Poly_node;
            newPtr->coef = coef;
            newPtr->exponent = exponent;
            if (size == 1)
            { // first node
                temp = head;
                if (exponent < temp->exponent)
                {
                    temp->next = newPtr;
                }
                else if (exponent == temp->exponent)
                {
                    // cout << "in\n";
                    temp->coef += coef;
                    delete newPtr;
                }
                else
                {
                    head = newPtr;
                    newPtr->next = temp;
                }
            }
            else
            {
               
                Poly_node *temp_next = new Poly_node;
                 temp = head;
                temp_next = head -> next;
                while (temp != NULL)
                {
                    if (temp->next != NULL)
                    {
                        // cout << "temp_expo : " << temp->exponent << endl;
                        if (exponent > temp->exponent && exponent > temp_next->exponent)
                        {
                            head = newPtr;
                            newPtr->next = temp;
                            break;
                        }
                        else if (exponent < temp->exponent && exponent > temp_next->exponent)
                        {
                            temp->next = newPtr;
                            newPtr->next = temp_next;
                            break;
                        }
                        else if (exponent == temp->exponent)
                        {
                            temp->coef += coef;
                            delete newPtr;
                            break;
                        }
                        else if (exponent == temp_next->exponent)
                        {
                            temp_next->coef += coef;
                            delete newPtr;
                            break;
                        }
                    }
                    else
                    {
                        temp->next = newPtr;
                        break;
                    }
                    temp = temp->next;
                    temp_next = temp_next->next;
                }
            }
            size++;
        }
    }

    void printPolynomial()
    {
        cout << "[ ";
        Poly_node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->coef == 0)
            {
            }
            else
            {
                cout << ptr->coef << "X^{" << ptr->exponent << "} ";
            }
            ptr = ptr->next;
        }
        cout << "]\n";
    }

    void plus(Polynomial f2)
    {
        Poly_node *polynode_f2 = f2.head;
        Poly_node *polynode_f1 = head;
        // cout << f2.size << endl;
        
        for (int i = 0; i < f2.size; i++)
        {

            while (polynode_f1 != NULL)
            {

                if (polynode_f2->exponent == polynode_f1->exponent) // exponent is equl
                {
                    polynode_f1->coef += polynode_f2->coef;
                    break;
                }
                else
                {
                    Poly_node *add_node = new Poly_node;

                    int exponent = polynode_f2->exponent;
                    int coef = polynode_f2->coef;
                    addTerm(coef, exponent);
                    break;
                }
            }
            polynode_f2 = polynode_f2->next;
        }
    }

    void minus(Polynomial f2)
    {
        Poly_node *polynode_f2 = f2.head;
        Poly_node *polynode_f1 = head;
        // cout << f2.size << endl;
        int j = 0;
        for (int i = 0; i < f2.size; i++)
        {

            while (polynode_f1 != NULL)
            {

                if (polynode_f2->exponent == polynode_f1->exponent) // exponent is equl
                {
                    polynode_f1->coef -= polynode_f2->coef;
                    break;
                }
                else
                {
                    Poly_node *add_node = new Poly_node;

                    int exponent = polynode_f2->exponent;
                    int coef = -1 * polynode_f2->coef;
                    addTerm(coef, exponent);
                    break;
                }
            }
            polynode_f2 = polynode_f2->next;
        }
    }
};
