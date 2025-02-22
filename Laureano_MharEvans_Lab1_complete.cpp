#include <iostream>
using namespace std;

int myArray[30];
int NumElem = 0;
int MaxElem = 20;

void bubbleSort(){
    int i, j;
    bool swapped;
    for(int i = 0; i < NumElem - 1; i++){
        swapped = false;
        for(j = 0; j < NumElem - i - 1; j++){
            if(myArray[j] > myArray[j + 1]){
                swap(myArray[j], myArray[j + 1]);
                swapped = true;
            }
        }

        if(swapped == false){
            break;
        } 
    }

}

//Searching Operations
int BinarySearch(int num, int lowest, int highest){
    while(lowest <= highest){
        int middle = lowest +((highest - 1) /2);

        if(myArray[middle] == num){
            return middle;
        }

        if(myArray[middle] < num){
            lowest = middle + 1;
        }else{
            highest = middle - 1;
        }
    }

    return -1;
}

void traverseArray(){
    cout << "Showing elements in my array \n";
    for (int i = 0; i < NumElem; i++){
        cout << myArray[i] << "|";
    }
    cout << "\n";
}


string InsertAtTheEnd(int num){
    if(NumElem != MaxElem){
        myArray[NumElem] = num;
        NumElem++;
        return "An element is successfully inserted at the end! \n";
    }
    
    return "The array is full. please remove elements before inserting new one. \n";
}

string InsertAtTheBeginning(int num){
    if(NumElem != MaxElem){
        for(int i = NumElem; i >= 0; i--)
            myArray[i+1] = myArray[i];
        
        myArray[0] = num;
        NumElem++;
        return "An element is successfully inserted at the Beginning! \n";
    }
    
    return "The array is full. please remove elements before inserting new one. \n";
}


string InsertAtTheGivenPosition(int num, int ElementAfter){
    if(NumElem != MaxElem){
        int position = BinarySearch(ElementAfter, 0, NumElem);
        /*if(position < 0 || position > NumElem) {
            return "invalid position| \n";
        }*/
       
        
        for(int i = NumElem; i>=position; i--){
            myArray[i+1] = myArray[i-1];
        }
        
        myArray[position + 1] = num;
        NumElem++;
        return "An element is successfully inserted at the specified location! \n";
    }
    
    return "The array is full. please remove elements before inserting new one. \n";
}

string InsertAtSortedArray(int num){
    if(NumElem != MaxElem){
        bubbleSort();
        int position;
        for(int i = 0; i < NumElem; i++){
            if(num < myArray[i]){
                position = i;
                break;
            }
        }

        for(int i = NumElem; i>=position; i--){ 
            myArray[i + 1] = myArray[i]; 
        }

        myArray[position] = num; 
        NumElem++;
        return "An element is successfully inserted at a sorted array! \n";
    }
    return "The array is full. Please remove elements before inserting new one. \n";
}

string DeleteFromTheEnd(){
    if(NumElem != 0){
        NumElem--;
        return "An element has been deleted from the end!";
    }
    return "The array is underflow! Delete is not possible";
}

string DeleteFromTheBeginnning(){
    if(NumElem != 0){
        for(int i = 0; i<= NumElem; i++){
            myArray[i] = myArray[i + 1];
        }
        NumElem--;
        return "An element has been deleted from the beginning!";
    }
    return "The array is underflow! Delete is not possible";
}

string DeleteFromTheGivenElement(int element){
    if(NumElem != 0){
        int index = BinarySearch(element,0 , NumElem);
        /*for(int i = 0; i <= NumElem; i++){
            if(myArray[i] == element){
                index = i;
                break;
            }
        }*/

        for(int i = index; i <= NumElem; i++){
            myArray[i] = myArray[i + 1];
        }
        NumElem--;
        return to_string(element) + "has been deleted!";

    }
    return "The array is underflow! Delete is not possible";
}

int main() {
    
    cout << InsertAtTheBeginning(3);
    cout << InsertAtTheEnd(7);
    cout << InsertAtTheEnd(9);
    cout << InsertAtTheBeginning(20);
    cout << InsertAtTheGivenPosition(37,3);
    cout << InsertAtTheBeginning(256);
    cout << InsertAtTheGivenPosition(128,5);
    cout << InsertAtTheBeginning(19);
    
    traverseArray();

    cout << InsertAtSortedArray(3);
    cout << InsertAtSortedArray(30);
    cout << InsertAtSortedArray(38);
    cout << InsertAtSortedArray(19);

    traverseArray();
    
    DeleteFromTheEnd();
    DeleteFromTheEnd();
    
    traverseArray();

    DeleteFromTheBeginnning();
    DeleteFromTheBeginnning();

    traverseArray();

    DeleteFromTheGivenElement(19);
    DeleteFromTheGivenElement(9);

    traverseArray();

    cout << BinarySearch(20, 0, NumElem) << endl;
    cout << BinarySearch(38, 0, NumElem) << endl;

    return 0;
}
