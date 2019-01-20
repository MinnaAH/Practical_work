#pragma once
#include<iostream>
using std::cout; using std::endl; using std::cin;
enum Error_code {
	success, fail, utility_range_error, underflow, overflow, fatal, not_present,
	duplicate_error, entry_inserted, entry_found, internal_error
};