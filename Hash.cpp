#pragma once
#include <cstring>
#include <iostream>
#include "datatype.hpp"
#include <map>
#include "binary_Heap.cpp"
#include "tempfile.cpp"
using namespace std;

class Hash_map
{
public:
    LinkedList *l1;
    int size = 5;   //used in case more categories are added to the heap(to increase size)
    Heap *hashPtr;  //for udemy courses
    Heap *hashPtr2; //for coursera courses
    Course *sub_root;
    Hash_map()
    {
        hashPtr = new Heap[size];
        hashPtr2 = new Heap[100];
    }
    int HashFunc(string str) //Hash function for udemy data set
    {
        if (str.compare("Business Finance") == 0)
            return 1;   
        else if (str.compare("Graphic Design") == 0)
            return 2;
        else if (str.compare("Musical Instruments") == 0)
            return 3;
        else if (str.compare("Web Development") == 0)
            return 4;
        else
            return 5;
    }
    int HashFuncC(string str) //Hash function for coursera
    {
        int ascii = 0;
        int length = 0;
        char *c;
        *c = str[0];
        while (*c != ' ')
        {
            *c = str[length];
            if (*c != ' ')
                length++;
        }
        for (int i = 0; i < length; i++)
        {
            ascii = ascii += (int)str[i];
        }
        int hashval = ascii % 100;
        return hashval;
    }
    void inserthash(int index, Course *obj) //to be used when adding new hash maps;
    {
        hashPtr[index - 1].insert(obj, obj->data.rating);
    }
    void inserthash2(int index, Course *obj) //to be used when adding new hash maps;
    {
        hashPtr2[index - 1].insert(obj, obj->data.rating);
    }

    void searchMap(string str) //searchesudemy courses
    {
        int index = HashFunc(str);
        LinkedList *newList = new LinkedList();
        hashPtr[index - 1].returnList(newList);
        cout << "Display first how many results?(Press 0 if you wish to display all)" << endl;
        int count = 0;
        cin >> count;
        newList->printList(count, 0);
    }
    void searchMapC(string str) //searches coursera courses
    {
        int index = HashFuncC(str);
        LinkedList *newList = new LinkedList();
        hashPtr2[index - 1].returnList(newList);
        cout << "Display first how many results?(Press 0 if you wish to display all)" << endl;
        int count = 0;
        cin >> count;
        newList->printList(count, 0);
    }
};