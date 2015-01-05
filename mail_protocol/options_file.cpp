#include "options_file.h"

using namespace std;

Options_File::Options_File(const char* filename) : _f(filename)
{
    cout << "CTOR from Options_File" << endl;
    if (!_f.is_open()) {
        cout << "Invalid file path.";
        exit(1);
    }
    _parameters = 0;
}

bool Options_File::read_line()
{
    if (_f.eof()) { return false; }
    _f.getline(_buffer, OP_N);
    if (_buffer[0] == '#' || _buffer[0] == '\n' || _buffer[0] == '\r') { return read_line(); }
    
    _parameter_count = 1;
    
    for (int j = 0; _buffer[j] != '\0'; j++) {
        if (_buffer[j] == ',')
            _parameter_count++;
    }
    
    if (_parameters != NULL) {
        delete [] _parameters;
    }
    
    _parameters = new Str[_parameter_count];
    
    int len = 0, start = 0, p = 0;
    bool started = false;
    for (int j = 0; _buffer[j] != '\0' && _buffer[j] != '\r'; j++) {
        if (_buffer[j] == ',') {
            int k = j-1;
            while(_buffer[k]==' ') {
                k--;
                len--;
            }
            char *tmp = new char[len+1];
            for (int i = 0; i < len; i++)
            {
                tmp[i] = _buffer[start+i];
            }
            tmp[len] = '\0';
            
            _parameters[p].set_str(tmp);
            
            len = 0;
            start = j + 1;
            p++;
            started = false;
            delete[] tmp;
        } else if (!started && _buffer[j] == ' '){
            start++;
        } else {
            started = true;
            len++;
        }
    }
    
    
    char *tmp = new char[len+1];
    for (int i = 0; i < len; i++) {
        tmp[i] = _buffer[start+i];
    }
    tmp[len] = '\0';
    
    _parameters[p].set_str(tmp);
    delete[] tmp;
    
    return true;
}

int Options_File::num_parameters()
{
    return _parameter_count;
}

const Str Options_File::get_parameter(int i)
{
    return Str(_parameters[i]);
}

int Options_File::get_int_parameter(int i)
{
    int x = 0;
    for (int j = 0; j < _parameters[i].get_length(); j++) {
        x *= 10;
        x += (_parameters[i].get_char(j) - '0');
    }
    return x;
}

float Options_File::get_float_parameter(int i)
{
    float x = 0;
    int j;
    for (j = 0; j < _parameters[i].get_length(); j++) {
        if (_parameters[i].get_char(j) == '.')
            break;
        x *= 10;
        x += (_parameters[i].get_char(j) - '0');
    }
    
    float decimal = 0;
    int num_digits = 0;
    
    for (j++; j < _parameters[i].get_length(); j++) {
        decimal *= 10;
        decimal += (_parameters[i].get_char(j) - '0');
        num_digits++;
    }
    
    for (int y = 0; y < num_digits; y++) {
        decimal /= 10;
    }
    
    return x + decimal;
}

char Options_File::get_char_parameter(int i)
{
   return _parameters[i].get_char(0);
    
}


Options_File::~Options_File()
{
    if (_parameters != NULL) {
        delete [] _parameters;
    }
    
    cout << "DTOR from Options_File" << endl;
}





