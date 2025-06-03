#include "main.h"

int main()
{
    // Will hold the concrete class on the evaluation of the message type.
    Alert* alert;
    std::string messageType;

    std::cout << "Please enter a message type: {error, warning, success} ";

    // Get the type of message to display for the user
    std::cin >> messageType;

    if (messageType == "success") alert = new SuccessAlert();
    else if (messageType == "warning") alert = new WarningAlert();
    else alert = new ErrorAlert();

    // Create the message 
    TextBox text = alert->createTextBox();
    text.render();

    return 1;
}