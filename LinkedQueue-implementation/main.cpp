#include <iostream>
#include <cassert>
using namespace std;

template<class dataType>
class LinkedQueue{
private:
    struct node{
        dataType d;
        node *next;

    };
    typedef node *NodePointer;
    NodePointer front , rear , cursor ;
    int length;
public:
    LinkedQueue(){

        front = NULL;
        rear  = NULL;
        length = 0;
        cursor = NULL;
    }
    dataType getfront(){
        assert(!isEmpty());
            return front->d;
    }

    dataType getRear(){
        assert(!isEmpty());
            return rear->d;
    }

    bool isEmpty(){
        return (length == 0);
    }

  void enqueue(dataType item)
	{
		NodePointer newNode = new node;
		newNode->d = item;
		newNode->next = NULL;

		if (length == 0)
			rear = front = newNode;
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
		length++;
	}
    void dequeue(){
        if(!isEmpty()){
        NodePointer temp = front;
        if(front == rear){
            front == NULL;
            rear = NULL;
            length = 0;
        }else{
         front = front->next;
         delete temp;
         length--;
             }
        }else {
         cout<<"You can't dequeue the queue is Empty "<<endl;
        }

    }

    void toFirst(){

        cursor = front;
    }
    void toEnd(){
        if(!isEmpty())
            cursor = rear;
    }

    void clearQueue(){
        if(!isEmpty()){
            while (front!=NULL){
                cursor = front;
                front = front->next;
                delete cursor;
            }
            rear = NULL;
        }else{
            cout<<"the Queue is Empty ..!";
        }
    }

    void print(){
        toFirst();
            while(cursor!=NULL){
                cout<<"\n"<<cursor->d<<endl;
                cursor = cursor->next;
            }

    }

};
int main()
{
    LinkedQueue<string> s;
    s.enqueue("shehab");
    s.enqueue("osama");
    s.enqueue("fathi");
    //s.clearQueue();
    cout<<"first print :::::::::::::::: "<<endl;
    s.print();
    s.dequeue();
    cout<<"second print ::::::::::::::::"<<endl;
    s.print();
    return 0;
}
