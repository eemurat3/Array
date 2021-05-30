/**
 * @file Array.h
 * @author murat kaymaz
 * @brief  This class is uses for array operation and can be used for all types
 * @version 0.1
 * @date 2021-05-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ARRAY_H
#define ARRAY_H

template<class T>
class Array{
    public:
        /**
         * @brief Construct a new Array object
         * default array size equal 10
         * 
         */
        Array();
        /**
         * @brief Construct a new Array object
         * 
         * @param size : array size
         */
        Array(int size);
        /**
         * @brief Destroy the Array object
         * 
         */
        ~Array();
        /**
         * @brief if array is not full add a new value end of array
         * 
         * @param value : value to add
         */
        void append(T value);
        /**
         * @brief 
         * 
         * @param index : index to add
         * @param value : insert the value in wanted index
         */
        void insert(int index,T value);
        /**
         * @brief Erase the wanted index
         * 
         * @param index : index to erase
         * @return T : Erased value
         */
        T erase(int index);
        /**
         * @brief array value to set
         * 
         * @param index : index to set
         * @param value : new value
         */
        void setElement(int index,T value);
        /**
         * @brief Get the array Element
         * 
         * @param index : index to get
         * @return T : index value -> if index is valid return the index value, else returning empty
         */
        T getElement(int index);
        /**
         * @brief Get the array element
         * 
         * @param index : index to get
         * @return T& : index value -> if index is valid return the index value, else returning empty
         */
        T& operator[](int index);
        /**
         * @brief total number of elements in the array
         * 
         * @return int : nmber of total elements
         */
        int length(); 
        /**
         * @brief : look for the desired value in the array
         * 
         * @param key : searched value
         * @return int : if value is find return the index else return -1
         */
        int search(T key);
        /**
         * @brief reverse the arrar
         * 
         */
        void reverse();
        
        /**
         * @brief show the array elements
         * 
         */
        void display();

    private:
        /**
         * @brief swap the two value
         * 
         * @param a : value 1
         * @param b : value 2
         */
        void swap(T* a, T* b);

        T *array;
        int size;
        int len;
};
#endif

template<class T>
Array<T>::Array(){
    size = 10;
    array = new T[size];
    len = 0;
}
template<class T>
Array<T>::Array(int tsize){
    size = tsize;
    len = 0;
    array = new T[size];
}

template<class T>
void Array<T>::append(T value){
    if(len < size){
        array[len]=value;
        len += 1;
    }
    else
    {
        std::cout<<"\narray size is full\n";
    }
}

template<class T>
void Array<T>::insert(int index, T value){
    if(index >= 0 && index <= len){
        for(int i=len;i>index;i--)
            array[i] = array[i-1];
        array[index] = value;
        len += 1;
    }
    else
    {
        std::cout<<"\ninvalid index\n";
    }
}

template<class T>
T Array<T>::erase(int index){
    if(index >=0 && index <= len-1){
        T deleted = array[index];
        for(int i=index;i<len-1;i++)
            array[i]=array[i+1];
        len -= 1;
        return deleted;
    }
    
    return T( );
}

template<class T>
void Array<T>::setElement(int index, T value){
    if(index >= 0 && index <= len-1)
    {
        array[index] = value;
    }
}

template<class T>
T Array<T>::getElement(int index){
    if(index >= 0 && index <= len-1)
        return array[index];
    
    return T( );
}

template<class T>
T& Array<T>::operator[](int index){
    return array[index];
}

template<class T>
int Array<T>::length(){
    return len;
}

template<class T>
int Array<T>::search(T key){
    for(int i=0;i<len;i++)
    {
        if(array[i] == key)
            return i;
    }
    return -1;
}

template<class T>
void Array<T>::reverse(){
    for(int i=0,j=length()-1;i<j;i++,j--)   
        swap(&array[i],&array[j]);

}

template<class T>
void Array<T>::swap(T* a, T* b){
    T temp=*a;
    *a=*b;
    *b=temp;
}

template<class T>
void Array<T>::display(){
    std::cout<<"\nElements are : ";
    for(int i=0;i<len;i++)
        std::cout<<array[i]<<" ";
    std::cout<<"\n";
}

template<class T>
Array<T>::~Array(){
    delete []array;
}
