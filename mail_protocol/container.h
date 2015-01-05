//
//  container.h
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#ifndef __mail_protocol__container__
#define __mail_protocol__container__

#include <iostream>


template <typename T> class Container {
    int _len;
    T* _cont;
    int *_ids;
    int _size;
    
public:
    
    Container();
    void add_item (int id, T& item );
    T& get_item ( int id );
    T& get_item_by_index(int i);
    int get_len ();
    void delete_all();
    ~Container();
    void delete_item(int id);
};

#endif /* defined(__mail_protocol__container__) */