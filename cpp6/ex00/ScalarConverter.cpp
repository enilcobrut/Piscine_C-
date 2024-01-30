#include "ScalarConverter.hpp"
#include "MegaConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {
    *this = copy;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &res) {
    (void)res;
    return *this;
}
ScalarConverter::~ScalarConverter() {

}
void ScalarConverter::convert(string input)  {
    MegaConverter convert(input);
    bool is_int = false;
    bool is_possible = true;
    bool not_possible = false;
    bool has_only_zeros = true;
    type Type;  
    size_t dot_pos;
    try {
         Type = convert.WhichType();
    }
    
    catch (const std::exception &e) {
        not_possible = true;
    }
    if (Type == NONE) {
        cout << "The programm only accept, int, double, float or char" <<endl;
        return ;
    }
    try {
        switch (Type) {
            case 0:
                convert.setInt(atoi(input.c_str()));
                convert.setDouble(convert.TypeToDouble(Type));
                convert.setChar(convert.TypeToChar(Type));
                is_int = true;
                break ;
            case 1:
                convert.setDouble(atof(input.c_str()));
                convert.setInt(convert.TypeToInt(Type));
                has_only_zeros = true;
                dot_pos = input.find(".");
                for (size_t i = dot_pos+1; i < input.length(); i++) {
                    if (input[i] != '0' &&  input[input.length()-1] != 'f') {
                        has_only_zeros = false;
                        break;
                    }
                }
                convert.setChar(convert.TypeToChar(Type));
                break ;
            case 2:
                convert.setChar(static_cast <char>(input[0]));
                convert.setInt(convert.TypeToInt(Type));
                convert.setDouble(convert.TypeToDouble(Type));
                break;
            default:
                throw std::invalid_argument("Invalid type");    
        }
    }
    catch (const std::exception &e) {
      
            cout << "char: "<< e.what() << endl;
            is_possible = false;
    }
    if (input == "inf" || input == "inff" || input == "nan" || input == "nanf")
        not_possible = true;
    if (is_possible == true)
        cout << "char: '" << convert.getChar() << "'" << endl;
    if (not_possible == false)
        cout << "int: " << convert.getInt() << endl;
    else
        cout << "int: " << "impossible" << endl;
    if (is_int == true || has_only_zeros == true)
        cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(convert.getDouble()) << "f" << endl;
    else
        cout  << "float: " << static_cast<float>(convert.getDouble()) << "f" << endl;
   cout << "double: " << convert.getDouble() << endl;
}
