#include <iostream>
#include <fstream>
#include "words.hpp"

// textFileReader class constructor
textFileReader::textFileReader(const std::string& filename)
{
   std::string line;
   std::ifstream ifstr;
   ifstr.open(filename.c_str(), std::ifstream::in);
   while (ifstr >> line)
      lines.push_back(line);
   ifstr.close();
}

std::vector<std::string> textFileReader::getLines() const
{
   return lines;
}

void textFileReader::printLines() const
{
   std::vector<std::string>::const_iterator it;
   for (it = lines.begin(); it != lines.end(); ++it)
      std::cout << *it << '\n';
}

// binaryFileReader class constructor
binaryFileReader::binaryFileReader(const std::string& filename)
{
   char buf[33];

   buf[32] = '\0';   // null cap
   std::ifstream ifstr;
   ifstr.open(filename.c_str(), std::ifstream::in | std::ifstream::binary);
   while (ifstr.read(buf, sizeof(buf)-1))
      records.push_back(buf);
   ifstr.close();
}

std::vector<std::string> binaryFileReader::getRecords() const
{
   return records;
}

void binaryFileReader::printRecords() const
{
   std::vector<std::string>::const_iterator it;
   for (it = records.begin(); it != records.end(); ++it)
      std::cout << *it << '\n';   
}

// textFileWriter class constructor
textFileWriter::textFileWriter(const std::string& filename,
      const std::vector<std::string>& lines)
{
   std::ofstream ofstr;
   ofstr.open(filename.c_str(), std::ofstream::out);

   std::vector<std::string>::const_iterator it;
   for (it = lines.begin(); it != lines.end(); it++)
      ofstr << *it << '\n';
   ofstr.close();
}

// binaryFileWriter class constructor
binaryFileWriter::binaryFileWriter(const std::string& filename,
      const std::vector<std::string>& records)
{
   std::ofstream ofstr;
   ofstr.open(filename.c_str(), std::ofstream::out | std::ofstream::binary);

   std::vector<std::string>::const_iterator it;
   for (it = records.begin(); it != records.end(); it++)
      ofstr.write((*it).c_str(), 32);
   ofstr.close();   
}
