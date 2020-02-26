#ifndef BOX_H_
#define BOX_H_

#include <string>

// Print Os message
void PrintOsMessage(const std::string& os_name);

// Return message of unix os.
std::string UnixBox();

// Return message of windows os
std::string WindowsBox();

// Return message of Default os
std::string DefaultBox();

#endif
