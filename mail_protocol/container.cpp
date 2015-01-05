//
//  container.cpp
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#include "container.h"
using namespace std;


template <typename T> Container<T>::Container()
{
    _len=0;
    _cont = new T[20];
    _ids = new int [20];
    _size = 20;
    
    cout << " CTOR for container " << endl ;

}

template <typename T> void Container<T>::add_item (int id, T& item )
{
    if(_len == _size ){
        T* new_cont = new T[2*_size];
        int* new_ids = new int[2*_size];
        for ( int i=0 ; i<_size ; ++i )
        {
            new_cont[i] = _cont[i];
            new_ids[i] = _ids[i];
        }
        _size = 2*_size;
        delete[] _cont;
        _cont = new_cont;
        delete[] _ids;
        _ids = new_ids;
        
    }
    _cont[_len] = item ;
    _ids[_len] = id;
    _len ++;
    
}
template <typename T>  T& Container<T>::get_item ( int id )
{
    for (int i=0 ; i<_len ; ++i)
    {
        if( _ids[i] == id )
            return _cont[i];
    }
    return T();
}
template <typename T> T& Container<T>::get_item_by_index(int i)
{
    return _cont[i];
 
}
template <typename T> int Container<T>::get_len ()
{
    return _len;
}
template <typename T> void Container<T>::delete_all()
{
    _len=0;
}
template <typename T> Container<T>::~Container()
{
    delete[] _cont;
    delete[] _ids;
    cout << " DTOR for container " << endl ;
}

template <typename T> void Container<T>::delete_item(int id)
{
  
    int index_del = -1;
    for (int i=0 ; i<_len ; ++i)
    {
        if( _ids[i] == id ){
            index_del = i;
            break;
        }
    }
    
    if (index_del == -1 )
        return;
    
    
    T* new_cont = new T[_size];
    int* new_ids = new int[_size];
    for ( int i=0 ; i<_size ; ++i )
    {
        if ( i!=index_del)
        {
        new_cont[i] = _cont[i];
        new_ids[i] = _ids[i];
        }
    }
    _len--;
    delete[] _cont;
    _cont = new_cont;
    delete[] _ids;
    _ids = new_ids;

    
}