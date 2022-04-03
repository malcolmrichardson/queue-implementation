#include <iostream>
using namespace std;

// Queue (Linked List) Structure
struct queue {
    int data;
    struct queue *nextElement;
};
typedef struct queue element;
element* start = NULL;

//Function Declarations
element* getElement();
void enQueue();
void deQueue();
void displayQueue();
void programControl();
int menu();

int main() {
    programControl();
    return 0;
}

//Creates new node in queue.
element* getElement() {     
    element* newElement;
    newElement = (element*)malloc(sizeof(element));
    cout<<"\nEnter the data for the new element in the queue: ";
    cin>>newElement->data;
    newElement->nextElement = NULL;
    return newElement;
}

//Insert at end function.
void enQueue() {    
    element *newElement, *temp;
    newElement = getElement();
    if (start == NULL) {
        start = newElement;
        cout<<"\nA new element has been added to the rear of the queue.\n";
    }
    else {
        temp = start;
        while (temp->nextElement != NULL) {
            temp = temp->nextElement;
        }
        temp->nextElement = newElement;
        cout<<"\nA new element has been added to the rear of the queue.\n";
    }
}

//Delete from beginning function.
void deQueue() {
    element *temp;
    if (start == NULL) {
        cout<<"\nNo elements are in the queue.\n";
        return;
    }
    else {
        temp = start;
        start = temp->nextElement;
        free(temp);
        cout<<"\nThe element at the front of the queue has been deleted.\n";
    }
}

//Displays the queue from front to rear.
void displayQueue() {   
    element *temp;
    temp = start;
    cout<<"\nThe content of the queue are as follows: ";
    if (start == NULL) {
        cout<<"\n\nThere are no elements in the queue.";
    }
    else {
        while (temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->nextElement;
        }
    }
    cout<<endl;
}

//Controls program, based on user input.
void programControl() {
    int userChoice;
    do {
        userChoice = menu();
        switch(userChoice){
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
        }
    } while(1);
}

//Allows the user to choose what action they would like to take within the program.
int menu() {
    int choice;
    cout<<"\nEnter the number corresponding to the action you would like to perform: ";
    cout<<"\n     1: Enqueue.";
    cout<<"\n     2: Dequeue.";
    cout<<"\n     3: Display the contents of the queue.";
    cout<<"\n     4: Quit.";
    cout<<"\nYour choice: ";
    cin>>choice;
    return choice;
}
