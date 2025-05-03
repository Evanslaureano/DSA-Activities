#include <iostream>
using namespace std;

string karaoke_queue[100];

int front = 0;
int rear = -1;
int max_queue = 10;

bool isFull(){
    if(rear == max_queue -1){
        return true;
    }
    
    return false;
}

bool isEmpty(){
    if(rear == -1){
        return true;
    }
    
    return false;
}

string enqueue(string song){
    if(isFull()){
        return "The queue is full. try again later";
    }
    
    karaoke_queue[++rear] = song;
    return "A new song has been added in the queue";
}

string dequeue(){
    if(isEmpty()){
        return "There is no song in the queue. Try adding first";
    }
    
    string song = karaoke_queue[front];
    
    for(int i = 1; i <= rear; i++){
        karaoke_queue[i-1] = karaoke_queue[i];
    }
    
    rear--;
    return song;
}

int main(){
    
    string song; int choice; do{ 
        cout << "1. Add a song to the queue\n"; 
        cout << "2. Play the next song\n"; 
        cout << "3. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice;
         switch(choice){ 
            case 1: 
            cout << "Enter the name of the song: "; 
            cin >> song;
             cout << enqueue(song) << endl; 
             
            break;
             case 2:
              cout << dequeue() << endl; 
            break; 
            case 3: 
            cout << "Exiting program...\n"; 
            break;
             default: 
             cout << "Invalid choice. Try again.\n";
            } 
        }while(choice != 3); 

    return 0;
}