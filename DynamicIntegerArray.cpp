#include <iostream>
using namespace std;

class DynamicIntegerArray {
    private:
        int *data;
        int size;
    public:
        DynamicIntegerArray(){
            this->size=0;
            data = new int[0];
        }
        DynamicIntegerArray(int arr[], int size){
            this->size = size;
            data = new int[size];
            for (int i=0; i<size; i++)
                data[i]= arr[i];
        }
        DynamicIntegerArray(const DynamicIntegerArray &o){
            this->size = o.size;
            data = new int[o.size];
            for (int i=0; i<o.size;i++)
                data[i]= o.data[i];
        }
        void set(int value, int pos){
            data[pos]=value;
        }
        int getvalue(int pos)const{
            return data[pos];
        }
        int getsize()const{
            return size;
        }
        void print() const {
            std::cout<<"{ ";
            for(int i=0;i<size; i++)
                cout << data[i] <<" ";
            cout<< "}" <<endl;
        }
        void insert(int value, int pos){
            int* newData;
            int newSize=size+1;
            newData = new int[size+1];
            for (int i=0;i<pos;i++)
                newData[i]=data[i];
            newData[pos]=value;
            for (int i=pos+1;i<newSize;i++)
                newData[i]=data[i-1];
            delete[] data;
            data=newData;
            delete[] newData;
            size=newSize;
            
        }
        void pushBack(int value){
            int* newData;            
            int newSize=size+1;
            newData= new int[newSize];
            newData[0]=value;
            for(int i = 1; i<newSize; i++)
                newData[i]=data[i-1];
                
            delete[] data;
            data=newData;
            delete[] newData;
            size=newSize;
        }
        void remove(int pos){
            int* newData;
            int newSize=size-1;
            newData = new int[newSize];
            for(int i=0; i<pos;i++)
                newData[i]=data[i];
            for(int i=pos; i<newSize; i++)
                newData[i]=data[i+1];
            delete[] data;
            data=newData;
            delete[] newData;
            size=newSize;
        }
        ~DynamicIntegerArray() {
            delete[] data;
        }
};

int main(){
    // EJEMPLO DE INSERT
    int arr[] = {1,2,3,4};
    DynamicIntegerArray d1(arr,4);
    cout<<d1.getsize()<<" ";
    d1.print();
    d1.insert(3,1);
    cout<<d1.getsize()<<" ";
    d1.print();
    //EJEMPLO DE PUSHBACK
    int arr2[] = {4,5,6};
    DynamicIntegerArray d2(arr2,3);
    cout<<d2.getsize()<<" ";
    d2.print();
    d2.pushBack(6);
    cout<<d2.getsize()<<" ";
    d2.print();
    //EJEMPLO DE REMOVE
    int arr3[] = {2,3,4,5};
    DynamicIntegerArray d3(arr3,4);
    cout<<d3.getsize()<<" ";
    d3.print();
    d3.remove(0);
    cout<<d3.getsize()<<" ";
    d3.print();    
    return 0;
    

}