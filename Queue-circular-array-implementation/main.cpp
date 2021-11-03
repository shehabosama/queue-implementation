#include <iostream>
#include <cassert>
using namespace std;

template<class dataType>
class arrayQueueType{
    int rear;
    int front;
    int length;
    dataType *arr;
    int maxSize;
public:
    arrayQueueType(int size){
        if(size<=0)
            size = 100;

        maxSize = size;
        front= 0;
        rear = size-1;
        length = 0;
        arr = new dataType[size];
    }
    bool isEmpty(){return (length == 0);}
    bool isFull(){return (length == maxSize );}
    void addQueue(dataType element){
    if(isFull())
        cout<<"Queue is Full "<<endl;
        else{
            rear = (rear+1)%maxSize; // FOR CIRCULAR ARRAY WHEN THE REAR REACH TO THE MAX OF ARRAY e.g 99 IF I ADDED AN ELMENT  REAR WIL BE (99+1)% MAX_LENGTH WILL BE WIL BE "0"
            arr[rear] = element;
            length++;
        }
    }
    void deleteQueue(){
        if(isEmpty()){
            cout<<"Empty Queue can't Dequeue .. !"<<endl;

        }else{
         front = (front+1)%maxSize;
            --length;
        }
    }

    int frontQueue(){
        assert(!isEmpty());
        return arr[front];
        }


    int rearQueue(){
        assert(!isEmpty());
    return arr[rear];
    }

  /*  void printQueue(){
     // |->->->->->->r   f->->->| circler print
     // |||||||||||||||||||||||||
     if(!isEmpty()){
        for(int i =0 ;i!=rear+1 ; i = (i+1)%MAX_LENGTH){
             cout<<arr[i]<<" ";
        }
     }else {
        cout<<"the Queue is Empty ... !";
     }

    }*/

    int queueSearch(dataType element) {
		int pos = -1;
		if (!isEmpty())
		{
			for (int i = front; i != rear; i = (i + 1) % maxSize)
				if (arr[i] == element)
				{
					pos = i;
					break;
				}
			if (pos == -1)
			{
				if (arr[rear] == element)
					pos = rear;
			}
		}
		else
			cout << "Q is empty ! " << endl;
		return pos;
	}


	~arrayQueueType() {
		delete[]arr;
	}

    void printQueue()
	{
		if (!isEmpty()) {
			for (size_t i = front; i != rear; i = (i + 1) % maxSize)
			{
				cout << arr[i] << " ";
			}
			cout << arr[rear];
		}
		else
			cout << "Empty Queue";
	}
};
int main()
{                     //   10  20  30  40  50
    arrayQueueType<int> q(5);//| =   =  =    =   =| size is 5 and full
    q.addQueue(10);
    q.addQueue(20);
    q.addQueue(30);
    q.addQueue(40);
    q.addQueue(50);//-------------------------------------
    cout<<"the first print "<<endl;
    q.printQueue();
                    //     20  30  40  50
    q.deleteQueue();//| =   =  =    =   =| size is 5 and not full
                    //  60 20  30  40  50
     q.addQueue(60);//| =   =  =    =   =| size is 5 and and full
    cout<<"\nthe second print "<<endl;
    q.printQueue();
    cout<<"\n"<<q.queueSearch(60)<<endl; // will be index 0
    return 0;
}
