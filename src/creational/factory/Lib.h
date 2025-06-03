#include <string>
#include <iostream>

class TextBox {
public: 
    TextBox(std::string message) : message(message) {};
    void render();

private:
    std::string message;
};

// The creator class
class Alert 
{
public: 
    // Methods common to all subclasses of Alert
    virtual TextBox createTextBox() = 0;
    virtual ~Alert() = default;  
};

// Subclasses that inherit from Alert. 
class ErrorAlert : public Alert {
public: 
    TextBox createTextBox() override;
};

class WarningAlert : public Alert {
    TextBox createTextBox() override;
};

class SuccessAlert : public Alert {
    TextBox createTextBox() override;
};