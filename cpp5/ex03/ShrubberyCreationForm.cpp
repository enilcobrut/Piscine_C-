#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) ,target("defaut") {

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : target(copy.target) {

}
ShrubberyCreationForm::ShrubberyCreationForm(const string target) :Form("ShrubberyCreationForm", 145, 137), target(target){

}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &res) {
    if (this != &res) 
      cout << "const can not be assignable" << endl;
    return *this;
}

const string ShrubberyCreationForm::getTarget() const {
    return this->target;
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getSign())
     throw Form::NotSignedException();
    if (executor.getGrade() > this->getGradeExec())
        throw Form::GradeTooLowException();
    string name = this->target + "_shrubbery";
    std::ofstream file(name);
    if (!file)
        throw std::runtime_error("Error opening file");
    file << "                                                                                                                                                                                                    \n                                                    %#                        %%%                                                             #%%%%%                                                \n                         ..                              &%.                    %%&%%                                                         #%%&&&%%&%%%%#                   .#%%%%%%%%%%%.          \n               ,###%&&&&&&&&&&###.               ##%%##/ &%%%                  #&&%%&#             /##&&&&&&&&%##%&&&&&&&&##,           /#%%%%%&&&&&&&&&&&%%%               .%%%%%%%&&&&&%%%%%#        \n            ,&&&&&&&&&&&%%%%&&&%%%%%%           %  %%&&%%%&%  %%%%#           &%%&&%&.            %&&&&#&%%%%&&&&&&&&&&%%%&&%          %&&%%&&@%%%%%%%%%%&@&&&&&&           %%&&&&&&&&&&&&&&&&%#       \n          #%%%%&&%%%%%%%%%%&&&%%%%%&&&&%*        .//%%%(&%%%%&&&/&&%%%/       %&&%&&&%&*     .%%%%&&&&&&&&&&&&%%%#%&&&&&&&&&&&&%/     %%&%%&@&%%%%%%%%%%&%%%%%%&@/          &&&&&&&&&&&&&&&&&&&&       \n         %%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&      %%&&   ,&&&&&%%%     ,&    .%%&%%%&&&&&,        /&&* .. *#&&&%*##  ,&&&&&&&&&&&&     *%&&&&&&@@@&&&%%%%%%%%%&&&&&%           &&&&&&&&&&&&&&%%%%%%%%    \n       /%%&&&&&&&&&&&&&&&@@&&&&&&&&&&&&&&&&    %%    #%&& ,( %&%%,         .%%%%%&&%%%%,          (###&&&&&&&&&&&&&( (/  *#           &@&%%%%%%%%%&@&@&&&@&&&%&&&&%%      /%%&&&%%%&&&&&&%%%%%%%%%%%%, \n         %&&&&&&&&&&&&&&&&@&&&&&&&&&&&&&@&%     ,   *&&.    #,  &%#        .%&&&@%%%%&%%            ..(/(.    *. /# /(#,,              #%%%&%%%%%%%%%%%%%%&&&@&%%&&&*   (%&&&&&&&&&&&%%%&&&&&&&&&&&&&&%\n        %&&&&&&&&&&&&&&@@@@@@@&&&@@@@@@@@@&         ,%&      #  (&%.       %&@&%%%%%&%%%%#                ##(#* .#%                   %%%%%%%%%%%%%%%%%%%&&%&&&&&&&      &&&&&&&&&&& #&&&&&&&&&&&&&&&&(\n        (@@@@@@@@@@@@@@(/ *.(@@@@@@@@@@@&.           /%%     #   &#         ,%&%%%%%%%%%%                     (##%  (/                 .&&&&&&&&&&&&&&&&&&&&&&&           ,(&&&&&%&. (% #&&&&&&&&&&&&( \n           &@@@@@   %   /%##%#%                              #              (%%%&&%%%%%&&#                      ####.                     ,@&@@@@@ /@@&&&&&&@@                     (#%% *#%            \n                     *####%#%%                              ##             .&&&%%&&&&&&&%%                       /##                             (#%.#*##.                           ###               \n                      .#%##%%                              #%*               ,&&,%@%*                            .####                             *#%% (                            #%                \n                      %####%%#                            (%%                    ,#&                              (###(                            *##%                              #%                \n                   ,,%%//##//(%%*                      ,###%%.                  ,###(                         .,(########(                       ,#####%%                          ,####.              \n   ";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}