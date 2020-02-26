#ifndef UTIL_H_
#define UTIL_H_

#include <map>
#include <memory>
#include <string>

// Register os name and  os message function to a map
void RegisterBox(std::map<std::string, std::unique_ptr<Box>>* p_mapping);

// Print Os message
void PrintOsMessage(const std::string& os_name,
                    const std::map<std::string, std::unique_ptr<Box>>& mapping);

#endif
