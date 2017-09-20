#include "MetaDataInfoNode.hh"

MetaDataInfoNode::MetaDataInfoNode( );
{
    aMetaDataCode = '\0';
    aMetaDataDescriptor = {'\0'};
    aNumberOfCycles = -1;
    aErrorCode = 0;
}
MetaDataInfoNode::MetaDataInfoNode( const MetaDataInfoNode& copyNode )
{
    aMetaDataCode = copyNode.aMetaDataCode;
    strcpy( aMetaDataDescriptor, copyNode.aMetaDataDescriptor );
    aNumberOfCycles = copyNode.aNumberOfCycles;
    aErrorCode = copyNode.aErrorCode;
}


MetaDataInfoNode::MetaDataInfoNode( const char newMetaDataCode, 
                                    const char newMetaDataDescriptor[ ],
                                    const int newNumberOfCycles,
                                    const int newErrorCode )
{
    aMetaDataCode = newMetaDataCode;
    strcpy( aMetaDataDescriptor, newMetaDataDescriptor );
    aNumberOfCycles = newNumberOfCycles;
    aErrorCode = newErrorCode;
}
MetaDataInfoNode::~MetaDataInfoNode( )
{
    ;
}

char MetaDataInfoNode::SetMetaDataCode( const char newMetaDataCode )
{
    aMetaDataCode = newMetaDataCode;
    return aMetaDataCode;
}
char* MetaDataInfoNode::SetMetaDataDescriptor( const char 
                                                newMetaDataDescriptor[ ] )
{
    strcpy( aMetaDataDescriptor, newMetaDataDescriptor );
    return aMetaDataDescriptor;
}
int MetaDataInfoNode::SetNumberOfCycles( const int newNumberOfCycles )
{
    aNumberOfCycles = newNumberOfCycles;
    return aNumberOfCycles;
}

int MetaDataInfoNode::SetErrorCode( const int newErrorCode )
{
    aErrorCode = newErrorCode;
}

char MetaDataInfoNode::GetMetaDataCode( ) const
{
    return aMetaDataCode;
}
char* MetaDataInfoNode::GetMetaDataDescriptor( ) const
{
    return aMetaDataDescriptor;
}
int MetaDataInfoNode::GetNumberOfCycles( ) const
{
    return aNumberOfCycles;
}
int MetaDataInfoNode::GetErrorCode( ) const
{
    return aErrorCode;
}


MetaDataInfoNode& MetaDataInfoNode::operator=( 
                                            const MetaDataInfoNode& copyNode )
{
    if( this == &copyNode )
    {
        ;
    }
    else
    {
        aMetaDataCode = copyNode.aMetaDataCode;
        strcpy( aMetaDataDescriptor, copyNode.aMetaDataDescriptor );
        aNumberOfCycles = copyNode.aNumberOfCycles;
    }

    return *this;
}