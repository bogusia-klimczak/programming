#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

bool is_dir(const char *dir);

void create_library(const char *_Path);

vector<string> explode(char delimiter, string const &string);

string implode(char glue, vector<string> $pieces);

string readFile(const string &fileName);