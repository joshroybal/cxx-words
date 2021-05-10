#ifndef WORDS_HPP
#define WORDS_HPP

#include <string>
#include <vector>

class textFileReader
{
   public:
      textFileReader(const std::string&);
      std::vector<std::string> getLines() const;
      void printLines() const;
   private:
      std::vector<std::string> lines;
};

class binaryFileReader
{
   public:
      binaryFileReader(const std::string&);
      std::vector<std::string> getRecords() const;
      void printRecords() const;
   private:
      std::vector<std::string> records;
};

class textFileWriter
{
   public:
      textFileWriter(const std::string&, const std::vector<std::string>&);
};

class binaryFileWriter
{
   public:
      binaryFileWriter(const std::string&, const std::vector<std::string>&);
};

#endif
