//
//  mail_message.cpp
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#include "mail_message.h"

using namespace std;

MailMessage::MailMessage()
{
    cout<<" CTOR for MailMessage " << endl ;
}
MailMessage::MailMessage(const MailMessage& m)
{
    *this = m;
    cout<<" copy CTOR for MailMessage " << endl ;

}
MailMessage::MailMessage(Str& st)
{
    _id=atoi(st.get_line(2).get_string() + 12);
    _from = st.get_line(3).get_string() + 6 ;
    _to = st.get_line(4).get_string() + 4;
    _mailtime = st.get_line(5).get_string() +6 ;
    for (int i=1 ; i<st.get_length() ; ++i)
    {
        int j=i-1;
        if ( st.get_char(i) == '\n' && st.get_char(j) == '\n' )
            _data = st.get_string()+i+1;
    }
    _size = _data.get_length();
    
}

MailMessage& MailMessage::operator= (const MailMessage& m)
{
    _id=m._id;
    _from.set_str(m._from);
    _to.set_str(m._to);
    _mailtime = m._mailtime;
    _data.set_str(m._data);
    _size = m._size;
    return *this;
    
}

MailMessage::MailMessage(int id , Str from , Str to , DateTime d , Str data , int size)
{
    _id = id;
    _from.set_str(from);
    _to.set_str(to);
    _mailtime = d;
    _data.set_str(data);
    _size = size;
    
}

void MailMessage::print_mailmessage()
{
    cout << " ID : " << _id << endl;
    cout << " FROM : " << _from.get_string() << endl;
    cout << " TO : " << _to.get_string() << endl;
    cout << " DATE : " ;
    _mailtime.print_datetime();
    cout << endl;
    cout << " DATA : " <<_data.get_string() << endl;
    
}

int MailMessage::get_id()
{
    return _id;
}

int MailMessage::get_size()
{
    return _size;
}


const Str &MailMessage::get_from() {
    return _from;
}

const Str &MailMessage::get_to() {
    return _to;
}

const Str &MailMessage::get_data() {
    return _data;
}

const DateTime &MailMessage::get_date() {
    return _mailtime;
}

MailMessage::~MailMessage()
{
    cout << "DTOR for MailMessage " << endl;
}