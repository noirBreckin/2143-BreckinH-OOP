// Author:           Terry Griffin (Comments added by Breckin Hume)
// Email:            breckin.hume@gmail.com
// Label:            A03
// Title:            Comment Orientation and Structure
// Course:           CMPS 2143
// Semester:         Fall 2022 

//Description: This program was written by Professor Terry Griffin, I(Breckin Hume) am only adding comments to properly organize this program

//Files: main.cpp

#include <iostream>

using namespace std;

/*
Circular ArrayQue

This Class creates an array that contains integers and has the ability to dynamically change its size

Private Methods: Name-Data Type
*Container-Integer Pointer
Front-Integer                    *The first value in the array
Rear-Integer                     *The last value in the array
QueSize-Integer                  *The size of the array
CurrentSize-Integer              *The size of the array during specific call
init-Void                        *Initializes the array
Full-Bool                        *Checks to see if the array is full or not

Public Methods: Name-Data Type
CircularArrayQue()
Push-Void
Pop-Integer

Uses:
Push(5); -- Pushes the int 5 into the array
Push(3); -- Pushes the int 3 into the array
Pop();   -- Removes the most recently added int from the array and moves it to temp

CircularArrayQue(); -- Creates an array with the size defualting to 10
CircularArrayQue(int);; -- Creates an array with the size equalling the int that was included in the call
*/


class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);    //Function Call to Initialize an array with 5 slots

    // C1.Push(34);            //Pushes the number 34 into the array
    // C1.Push(38);            //Pushes the number 38 into the array
    // C1.Push(44);            //Pushes the number 44 into the array
    // C1.Push(22);            //Pushes the number 22 into the array
    // C1.Push(99);            //Pushes the number 99 into the array
    // C1.Push(100);           //Pushes the number 100 into the array

    C1.Push(1);                //Pushes the number 1 into the array
    C1.Push(2);                //Pushes the number 2 into the array
    C1.Push(3);                //Pushes the number 3 into the array
    // C1.Push(6);             //Pushes the number 6 into the array
    // C1.Push(7);             //Pushes the number 7 into the array
    cout << C1 << endl;        //Prints out the full array

    // C1.Push(1);             //Pushes the number 1 into the array
    // C1.Push(2);             //Pushes the number 2 into the array
    // C1.Push(3);             //Pushes the number 3 into the array

    cout << C1 << endl;        //Prints out the full array
}
