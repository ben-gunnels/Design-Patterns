/**
 * @file Lib.cpp
 * 
 * @author Benjamin Gunnels (bengunnels8@gmail.com)
 * @brief Implements a factory design pattern for creating UI objects (notifications/alerts).
 * @date 2025-06-04
 * 
 * @copyright Copyright (Benjamin Gunnels) 2025
 *
 * 
 * 
 */

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