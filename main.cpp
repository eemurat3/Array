#include <iostream>
#include "Array.h"
#include <string>

int main(){

    Array<int> arr(10);

    arr.display();
    std::cout<<"append the values\n";
    arr.append(5);
    arr.append(3);
    arr.append(4);
    arr.append(34);
    arr.append(95);
    arr.append(55);
    arr.append(44);
    arr.append(99);

    arr.display();
    std::cout<<"insert the value 25 index 2\n";
    arr.insert(2,25);
    arr.display();
    std::cout<<"erase the value index 3:"<<arr.erase(3)<<"\n";
    arr.display();
    std::cout<<"get the value of index 6 :" <<arr.getElement(6)<<"\n";
    arr.display();
    std::cout<<"set the index 0 and value 35\n";
    arr.setElement(0,35);
    arr.display();
    std::cout<<"reverse the array\n";
    arr.reverse();
    arr.display();
    std::cout<<"get the index value 2 :"<<arr[2]<<"\n";
    std::cout<<"search the value 81 :"<<arr.search(81)<<"\n";
    std::cout<<"get the length of array : "<<arr.length()<<"\n";
    return 0;
}