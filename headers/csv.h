/*
 * csv.h
 *
 *  Created on: 15 Mar 2017
 *      Author: dylan
 */

#ifndef CSV_H_
#define CSV_H_


#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class CSVFile {
public:
	CSVFile(std::string fname_in, char delim_in=',') {
		fname = fname_in;
		delimeter = delim_in;
	}
	int open(char mode_in);
	int read(std::vector<std::vector<float> >* data);
	int write(std::vector<std::vector<float> >* data);
	void close();
	~CSVFile(){close();}
private:
	std::string fname;
	std::ofstream ofile;
	std::ifstream ifile;
	char mode;
	char delimeter;
};



#endif /* CSV_H_ */
