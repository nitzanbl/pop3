
/// This class responsible to fetch and management your mailbox.
/// this implemenation will the mail box stoarge will base on a file systems.
#include <iostream>
#include "options_file.h"
#include "str.h"
#include "mail_message.h"
#include "container.h"
#include "container.cpp"
#include "datetime.h"

class Pop3Adaptor
{
private:
    Container<MailMessage> _container;
    Str _user;
    Str _pass;
    int _bytes;
    bool _1authd;
    bool _2authd;
    Container<int> _delete_items;

public:
    
    Pop3Adaptor( const char* file_name );

	/* USER userid
	This must be the first command after the connect. 
	Supply your e-mail userid (this may or may not not the full e-mail address).
	Example: USER john.smith
	*/
	const char* User(const char* userId);

	/* PASS password
	This must be the next command after USER.
	Supply your e-mail password. 
	The password may be case sensitive.
	*/
	const char* PASS (const char* password);

	/* STAT SPEC
	STAT The response to this is: +OK #msgs #bytes Where #msgs is the number of messages 
	in the mail box and #bytes is the total bytes used by all messages. 
	Sample response: +OK 3 345910
	*/
	const char* STAT ();

	/* LIST SPEC
	LIST The response to this lists a line for each message with its 
	number and size in bytes, ending with a period on a line by itself. Sample response:
	+OK 3 messages
	1 1205
	2 305
	3 344400
	*/
	const char* LIST();

	/* RETR SPEC
	This sends message number msg# to you (displays on the Telnet screen). 
	You probably don't want to do this in Telnet (unless you have turned on Telnet logging).
	Example: RETR 2 */
	const char* RETR(int msgNumber);

	/* DELE msg# SPEC
	This marks message number msg# for deletion from the server. 
	This is the way to get rid a problem causing message. 
	It is not actually deleted until the QUIT command is issued. 
	If you lose the connection to the mail server before issuing the QUIT command,
	the server should not delete any messages. Example: DELE 3 */
	const char* DELE(int msgNumber);

	/* RSET SPEC
	This resets (unmarks) any messages previously marked for deletion in this session
	so that the QUIT command will not delete them.
	*/
	const char* RSET();

	/* QUIT SPEC
	This deletes any messages marked for deletion,
	and then logs you off of the mail server.
	This is the last command to use. 
	This does not disconnect you from the ISP, just the mailbox.
	*/
	const char* QUIT();

};