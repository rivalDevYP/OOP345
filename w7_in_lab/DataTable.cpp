//	program		:	DataTable.cpp
//	programmer	:	Yathavan, Parameshwaran
//	date 		:	March 15, 2019
// professor	:	Chris, Szalwinski

#include "DataTable.h"

namespace sict
{
	DataTable::DataTable(std::ifstream& incomingFileObject)
    {
        std::string temp;
        if (incomingFileObject.is_open())
        {
            while(!incomingFileObject.eof() && incomingFileObject.good()) //while end of file has not been met and object still good
            {
                std::getline(incomingFileObject,temp,'\n'); //extracting string line by line
                extractedFileContents.push_back(temp); //adding those extracted lines to the array
                temp.clear();
                numOfRecords++;
            }
            
            // # use if need to go back to beginning of the file
            // if (incomingFileObject.eof()) //if end of file met
            // {
            //     incomingFileObject.clear(); //clear any error flags
            //     incomingFileObject.seekg(0, incomingFileObject.beg); //go back to the beginning of the file
            // }
        }
    }

    void DataTable::displayData(std::ostream& os) const
    {
        
    }

    void DataTable::displayStatistics(std::ostream& os) const
    {
        
    }
}
