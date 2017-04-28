//Author: Gusev Nikita
//Time: 19/02/2017
//Description: Realization of some options of function `cat` in Linux/Windows.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void helpNote();
void fillVector(std::vector<std::string>& lines, std::ifstream& stream);
void printRecord(std::vector<std::string>);
int main(int argc, char *argv[]) {
	std::string help("-h");
	std::ofstream wRecord;
	std::ifstream rRecord;
	std::ifstream zRecord;
	std::ifstream pRecord;
	std::vector<std::string> lines;
	std::vector<std::string> strs;
	std::string str;
	std::string big("w");

	if(argc==1)
	{
		std::cout << "Warning:" << std::endl;
		std::cout << "\t\t\t0 arguments" << std::endl;
		std::cout << "\t\t\tcall for help: [./cat] -h "<< std::endl;
		exit(1);
	}

	if (argv[1] == help)
	{
		helpNote();
		exit(1);
	}

	if (argc == 2)
	{
		
		rRecord.open(argv[1]);
		fillVector(lines, rRecord);
		printRecord(lines);
	}
	if (argc == 5)
	{

		rRecord.open(argv[1]);
		fillVector(lines, rRecord);

		zRecord.open(argv[2]);
		fillVector(lines, zRecord);
		
		if (argv[3]==big) 
		{
			wRecord.open(argv[4], std::ios_base::app);
			if (!wRecord)
			{
				std::cerr << "Error: can't open a text file" << std::endl;
				exit(-1);
			}
			for (int i = 0; i < lines.size(); i++)
			{
				wRecord << lines[i] << std::endl;
			}

			lines.clear();
		}
			pRecord.open(argv[4]);
			fillVector(lines, pRecord);
			printRecord(lines);
	
	}
	if (argc > 5)
	{
		std::cout << "Warning:" << std::endl;
		std::cout << "\t\t\tToo much arguments" << std::endl;
		std::cout << "\t\t\tcall for help: [./cat] -h " << std::endl;
		exit(1);
	}
	rRecord.close();
	zRecord.close();
	pRecord.close();

	return 0;
}
void printRecord(std::vector<std::string> x)
{
	for (int i = 0; i <x.size(); i++)
	{
		std::cout << x[i] << std::endl;
	}
}

void fillVector(std::vector<std::string>& lines,std::ifstream& stream)
{
	std::string str;
	while (!stream.eof())
	{
		std::getline(stream, str);
		lines.push_back(str);
	}
}
void helpNote()
{
	std::cout << "Help note: " << std::endl;
	std::cout << "\t\t\tFor correct using a program" << std::endl<<"You can enter:"<<std::endl;
	std::cout << "\t\t\t1)[./cat] filename.txt" << std::endl;
	std::cout << "\t\t\t2)[./cat] filename1.txt  filename2.txt w [filename3].txt"<<std::endl;
	std::cout << "\t\t\t3)call for help: [./cat] -h" << std::endl;
}