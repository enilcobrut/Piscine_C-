#include <iostream>
#include <string>



#define WHITE "\033[38;2;255;255;255m"
#define GRAS "\033[1m"
#define RESET "\033[0m"
#define PINK "\033[38;2;255;20;147m"

using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::ostream;

class Contact {
    public:
        Contact();
        ~Contact();
        void    create_contact();
        void    put_contact();
        const   string& get_first_name() const;
        const   string& get_last_name() const;
        const   string& get_nickname() const;
    private:
        string first_name;
        string last_name;
        string nickname;
        string phone_number;
        string darkest_secret;
};
