#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

public:
    BoardArray() {
        array = new Entry[SIZE];
        index = 0;
    }

    void add(Entry* entry) {
        int insertPos = index;

        for (int i = 0; i < index; i++) {
            Entry existing = array[i];
            if (entry->compare(&existing)) {
                insertPos = i;
                break;
            }
        }
        if (index < SIZE) {
            for (int i = index; i > insertPos; i--) {
                array[i] = array[i - 1];
            }
            array[insertPos] = *entry;
            index++;
        } else {
            if (insertPos == index) {
                cout << entry->name << "'s score is too low to be added!" << endl;
                return;
            }

            for (int i = SIZE - 1; i > insertPos; i--) {
                array[i] = array[i - 1];
            }
            array[insertPos] = *entry;
        }
    }

    void print() {
        for (int i = 0; i < index; i++) {
            cout << i + 1 << ". ";
            array[i].print();
        }
    }
     ~BoardArray() {
        delete[] array;  
        array = nullptr; 
    }
};