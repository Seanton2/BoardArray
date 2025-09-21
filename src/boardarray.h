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
            
            int temp = index;
    for (int i = 0; i < index; i++) {
        if (entry->compare(&array[i])) {
            temp = i;
            break;
        }
    }

    if (index < SIZE) {
        for (int i = index; i > temp; i--) {
            array[i] = array[i-1];
        }
        array[temp] = *entry;
        index++;
    } else {
        if (temp == index) {
            cout << entry->name << "'s score is too low to be added!" << endl;
            return;
        }
        for (int i = SIZE-1; i > temp; i--) {
            array[i] = array[i-1];
        }
        array[temp] = *entry;
    }
}
        

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};