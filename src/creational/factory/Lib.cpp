#include "Lib.h"

void TextBox::render()
{
    std::cout << message << std::endl;
}

// Define the concrete instances for the three Alert subtypes
TextBox ErrorAlert::createTextBox() 
{
    return TextBox("Some Error has occurred. Exiting Program.");
}

TextBox WarningAlert::createTextBox()
{
    return TextBox("This is a warning! Continuing the program, but beware that things might not work as expected.");
}

TextBox SuccessAlert::createTextBox()
{
    return TextBox("Success! Congratulations! Everything worked as expected.");
}