/*
 * csv.cpp
 *
 *  Created on: 15 Mar 2017
 *      Author: dylan
 */

#include "../headers/csv.h"

int CSVFile::open(char mode_in) {
	if(!(mode_in == 'r' || mode_in == 'w'))
		return 0;

	mode = mode_in;

	if(mode == 'r')
		ifile.open(fname.c_str());
	else if(mode == 'w')
		ofile.open(fname.c_str());

	return 1;
}

int CSVFile::write(std::vector<std::vector<float> >* data) {
	if(mode == 'r')
		return 0;

	int rows = data->size();
	for(int i = 0; i < rows; i++) {
		std::vector<float> entries = data->at(i);
		int cols = entries.size();
		for(int j = 0; j < cols; j++) {
			ofile << entries[j];
			if(j == cols-1)
				ofile << "\n";
			else
				ofile << delimeter;
		}
	}
	return 1;
}

void CSVFile::close() {
	if(mode == 'w')
		ofile.close();
	if(mode == 'r')
		ifile.close();
}


