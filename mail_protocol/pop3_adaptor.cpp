//
//  pop3_adaptor.cpp
//  mail_protocol
//
//  Created by Gabriel Manricks on 1/4/15.
//  Copyright (c) 2015 Gabriel Manricks. All rights reserved.
//

#include "pop3_adaptor.h"

Pop3Adaptor::Pop3Adaptor(const char* file_name )
{
    Options_File f(file_name);
    f.read_line();
    _user = f.get_parameter(0);
    _pass = f.get_parameter(1);
    _bytes=0;
    while ( f.read_line())
    {
        int id = f.get_int_parameter(0);
        Str from(f.get_parameter(1));
        Str to(f.get_parameter(2));
        DateTime time(f.get_parameter(3));
        Str data(f.get_parameter(4));
        
        MailMessage m(id ,from , to , time , data , data.get_length());
        _container.add_item(id, m);
        _bytes +=  data.get_length();
    }
}

const char* Pop3Adaptor::User(const char* userId)
{
    if (_user.equals(userId))
        return "+OK" ;
    return "invalid user name" ;
}

const char* Pop3Adaptor::PASS(const char* password)
{
    if( _pass.equals(password))
        return "+OK" ;
    return "invalid password" ;
}

const char* Pop3Adaptor::STAT ()
{
    Str resp("+OK ");
    
    resp << _container.get_len() << " " << _bytes;
    return resp.get_string();
}

const char* Pop3Adaptor::LIST()
{
    Str resp("+OK ");
    resp << _container.get_len() << "messages";
    for (int i = 0; i < _container.get_len(); i++) {
        MailMessage &m = _container.get_item_by_index(i);
        resp << "\n" << m.get_id() << " " << m.get_size();
    }
    
    return resp.get_string();
}

const char* Pop3Adaptor::RETR(int msgNumber)
{
    Str data("+OK\n");
    data << "Message-ID: " << msgNumber << "\n" ;
    data << "FROM: " << _container.get_item(msgNumber).get_from() << "\n" ;
    data << "To: " << _container.get_item(msgNumber).get_to() << "\n" ;
    data << "Date: " << _container.get_item(msgNumber).get_date().str_format() <<"\n\n";
    data << _container.get_item(msgNumber).get_data() ;
    
    return data.get_string();
}

 
const char* Pop3Adaptor::DELE(int msgNumber)
{
    _delete_items.add_item(msgNumber, msgNumber);
    return "+OK" ;
}

const char* Pop3Adaptor::RSET()
{
    _delete_items.delete_all();
    return "+OK";
}

const char* Pop3Adaptor::QUIT()
{
    for (int i=0 ; i< _delete_items.get_len() ; ++i )
    {
        _container.delete_item(_delete_items.get_item_by_index(i));
    }
    return "+OK";
}















