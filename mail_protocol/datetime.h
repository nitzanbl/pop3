//
//  datetime.h
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#ifndef __mail_protocol__datetime__
#define __mail_protocol__datetime__

#include <iostream>
#include "str.h"

class DateTime
{
    int _day;
    int _month;
    int _year;
    int _hour;
    int _minute;
    int _second;
    
public:
    
    DateTime();
    DateTime( const Str st );
    DateTime (int d , int mo , int y , int ho , int mi , int se );
    DateTime( const DateTime& dt);
    
    DateTime& operator= (const DateTime& dt);
    DateTime& operator= (const Str st);

    void print_datetime();
    Str str_format() const;
    
    ~DateTime();
    
};

#endif /* defined(__mail_protocol__datetime__) */
