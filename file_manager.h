#ifndef RENTINGFORTHEWEEKEND_FILE_MANAGER_H
#define RENTINGFORTHEWEEKEND_FILE_MANAGER_H

#include <vector>

#include "User.h"

std::vector<User> load_from_file();
void save_to_file(std::vector<User>&);

#endif