/**
@file MetaDataInfo.hh
@author Eugene Nelson
@breif The header file for the MetaDataInfo class.
@version    1.0 Eugene Nelson
            Originally developed ( 9 - 19 - 17 )
*/
/////////////////////////////////////////////////////////////////////////////
// Precompiler Directives 
/////////////////////////////////////////////////////////////////////////////
#ifndef meta_data_info_hh
#define meta_data_info_hh

/////////////////////////////////////////////////////////////////////////////
// Constant Definition 
/////////////////////////////////////////////////////////////////////////////
#define MAX_STR_LEN 30
#define LINE_MAX_LEGNTH 300
#define MESSAGE_MAX_LENGTH 500

/////////////////////////////////////////////////////////////////////////////
// Header Files
/////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <queue>
#include <iomanip>
#include <sys/time.h>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>

#include "ConfigFileInput.hh"
#include "PCB.hh"

/////////////////////////////////////////////////////////////////////////////
// Struct Definition
/////////////////////////////////////////////////////////////////////////////
struct MetaDataInfoNode 
{
    char aMetaDataCode;
    char aMetaDataDescriptor[ MAX_STR_LEN ];
    int aNumberOfCycles;
    int aErrorCode;
    
    MetaDataInfoNode( )
    {
        ;
    }
    MetaDataInfoNode( const MetaDataInfoNode& copyNode )
    {
        aMetaDataCode = copyNode.aMetaDataCode;
        strcpy( aMetaDataDescriptor, copyNode.aMetaDataDescriptor );
        aNumberOfCycles = copyNode.aNumberOfCycles;
        aErrorCode = copyNode.aErrorCode;
    }
    ~MetaDataInfoNode( )
    {
        ;
    }

};

/////////////////////////////////////////////////////////////////////////////
// Class Definition
/////////////////////////////////////////////////////////////////////////////
class MetaDataInfo
{
    public:
        MetaDataInfo( char* fileName );
        ~MetaDataInfo( );

        void ProcessData(   ConfigFileInput& configFile,
                            PCB& state,
                            timeval& initTime );
    protected:
        bool ParseLine( char lineToParse[ ] );
        void RemoveSpaces( char lineToRemoveSpaces[ ] );
        void AdjustLineElements( char lineToAdjust[ ], int positionToAdjust );
        void ProcessErrorCode(  char logSpecification, 
                                char errorCode, 
                                ofstream& logFile );
        void LogOutput( char logSpecification, 
                        char* logMessage, 
                        ofstream& logFile );
        void LogTime( char logSpecification, 
                                    double time,
                                    ofstream& logFile );      
        void itoa( int inputValue, char* outputString, int base );
        void ReverseString( char* string, int size );
        double timer( long long timeToWait, timeval& initTime );
        queue<MetaDataInfoNode> aQueueOfMetaData;
};

#endif
