#ifndef FILES_H
#define FILES_H

#include "match.h"

void readFile(const std::string& filename, Match* match);
void writeFile(const char *filename, Match match);

#endif //FILES_H
