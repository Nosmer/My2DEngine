#pragma once

#include <fstream>

namespace MyEngine {
	
	inline std::string read_file(const char* filepath) {

		FILE* file = fopen(filepath, "rt");
		fseek(file, 0, SEEK_END);
		unsigned long length = ftell(file);
		unsigned long temp = length + 1;
		char* data = new char[temp];
		memset(data, 0, temp);
		fseek(file, 0, SEEK_SET);
		fread(data, 1, length, file);
		fclose(file);

		std::string result(data);
		delete[]data;
		return result;
	}
}