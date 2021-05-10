#include <iostream>
#include "words.hpp"

int main()
{
   textFileReader words("/usr/dict/words");
   std::cout << "<< /usr/dict/words" << std::endl;
   binaryFileWriter records("words.bin", words.getLines());
   std::cout << ">> words.bin" << std::endl;
   binaryFileReader lines("words.bin");
   std::cout << "<< words.bin" << std::endl;
   textFileWriter textfile("words.txt", lines.getRecords());
   std::cout << ">> words.txt" << std::endl;
   return 0;
}
