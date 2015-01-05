//
//  datetime.cpp
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#include "datetime.h"


using namespace std;

DateTime::DateTime() : _day(0) , _month(0) , _year(0) , _hour(0) , _minute(0) , _second(0)
{
    cout << "defult CTOR for DateTime" << endl ;
}
DateTime::DateTime( const Str st )
{
    if ( st.get_length() < 15 )
    {
        cout << " invalid datetime string " << endl ;
        exit(1);
    }
    _day = (st.get_char(0)-'0')*10 + st.get_char(1)-'0' ;
    _month = (st.get_char(2)-'0')*10 + st.get_char(3)-'0' ;
    _year = (st.get_char(4)-'0')*1000 + (st.get_char(5)-'0') *100 + (st.get_char(6)-'0') *10 + (st.get_char(7)-'0') ;
    _hour =  (st.get_char(8)-'0')*10 + st.get_char(9)-'0' ;
    _minute =  (st.get_char(10)-'0')*10 + st.get_char(11)-'0' ;
    _second =  (st.get_char(12)-'0')*10 + st.get_char(13)-'0' ;
    cout << " CTOR for DateTime " << endl ;
    
}
DateTime::DateTime (int d , int mo , int y , int ho , int mi , int se )
{
    _day = d;
    _month = mo;
    _year = y;
    _hour = ho;
    _minute = mi;
    _second = se;
    cout << " CTOR for DateTime " << endl ;

}
DateTime::DateTime( const DateTime& dt)
{
    _day = dt._day;
    _month = dt._month;
    _year = dt._year;
    _hour = dt._hour;
    _minute = dt._minute;
    _second = dt._second;
    
    cout << " copy CTOR for DateTime " << endl ;
    
}

DateTime& DateTime::operator= (const DateTime& dt)
{
    _day = dt._day;
    _month = dt._month;
    _year = dt._year;
    _hour = dt._hour;
    _minute = dt._minute;
    _second = dt._second;
    return *this;
    
}
void DateTime::print_datetime()
{
    cout << " Date : ";
    cout.width(2);
    cout.fill('0');
    cout << _day << '/' ;
    cout.width(2);
    cout.fill('0');
    cout << _month << '/';
    cout.width(4);
    cout.fill('0');
    cout << _year << endl;
    cout << " Time : " ;
    cout.width(2);
    cout.fill('0');
    cout << _hour << ':';
    cout.width(2);
    cout.fill('0');
    cout << _minute << ':';
    cout.width(2);
    cout.fill('0');
    cout << _second << endl;
    
}

DateTime& DateTime::operator= (const Str st)
{
    if ( st.get_length() < 14 )
    {
        cout << " invalid datetime string " << endl ;
        exit(1);
    }
    _day = (st.get_char(0)-'0')*10 + st.get_char(1)-'0' ;
    _month = (st.get_char(2)-'0')*10 + st.get_char(3)-'0' ;
    _year = (st.get_char(4)-'0')*1000 + (st.get_char(5)-'0') *100 + (st.get_char(6)-'0') *10 + (st.get_char(7)-'0') ;
    _hour =  (st.get_char(8)-'0')*10 + st.get_char(9)-'0' ;
    _minute =  (st.get_char(10)-'0')*10 + st.get_char(11)-'0' ;
    _second =  (st.get_char(12)-'0')*10 + st.get_char(13)-'0' ;
    return *this;
}

Str DateTime::str_format() const {
    Str time;
    
    if (_day < 10)
        time << "0";
    time << _day;
    
    
    if (_month < 10)
        time << "0";
    time << _month;
    
    time << _year;
    
    if (_hour < 10)
        time << "0";
    time << _hour;
    
    if (_minute < 10)
        time << "0";
    time << _minute;
    
    if (_second < 10)
        time << "0";
    time << _second;
    
    return time;
}


DateTime::~DateTime()
{
    cout << " DTOR for DateTime " << endl ;
}
