module rebecca
{
module impl
{
    sequence<string> StringSeq;
    
    interface CallBacksIce
	{
	    void storeGossip(string gossip, string userId, string botId, string endUserId);
		void categoryLoaded(string userId, string botId, string endUserId);
        void filePreLoad(string fileName, string userId, string botId, string endUserId);
        void filePostLoad(string fileName, string userId, string botId, string endUserId);
        void symbolicReduction(string symbol, string userId, string botId, string endUserId);
        void infiniteSymbolicReduction(string userId, string botId, string endUserId);
        void XMLParseError(string message, string userId, string botId, string endUserId);
		void XMLParseWarning(string message, string userId, string botId, string endUserId);
		void XMLParseFatalError(string message, string userId, string botId, string endUserId);
		
		void thatStarTagSizeExceeded(string userId, string botId, string endUserId);
		void topicStarTagSizeExceeded(string userId, string botId, string endUserId);
		void starTagSizeExceeded(string userId, string botId, string endUserId);
		void inputTagNumericConversionError(string message, string userId, string botId, string endUserId);
		void inputTagSizeExceeded(string userId, string botId, string endUserId);
		void starTagNumericConversionError(string message, string userId, string botId, string endUserId);
		void thatTagSizeExceeded(string userId, string botId, string endUserId);
		void thatTagNumericConversionError(string message, string userId, string botId, string endUserId);
		void topicStarTagNumericConversionError(string message, string userId, string botId, string endUserId);
		void thatStarTagNumericConversionError(string message, string userId, string botId, string endUserId);
		void learnTagFileNotFound(string message, string userId, string botId, string endUserId);
	};
	
	exception ExceptionIce
	{
	    string what;
	};
	
	exception FileNotFoundExceptionIce extends ExceptionIce
	{
	
	};

	exception IllegalArgumentExceptionIce extends ExceptionIce
	{
	
	};

	exception DirectoryNotFoundExceptionIce extends ExceptionIce
	{
	
	};

	exception XMLErrorExceptionIce extends ExceptionIce
	{
	
	};
	
	
	interface NetworkGraphBuilderIce
	{
		void addFile(string file, string userId, string botId, string endUserId)
		    throws FileNotFoundExceptionIce, ExceptionIce;

		void addFileUnlessAlreadyAdded(string file, string userId, string botId, string endUserId)
		    throws FileNotFoundExceptionIce, ExceptionIce;
            
        void removeFile(string file, string userId, string botId, string endUserId)
            throws FileNotFoundExceptionIce, ExceptionIce;
        
		void addDirectory(string directory, string userId, string botId, string endUserId)
		    throws IllegalArgumentExceptionIce, DirectoryNotFoundExceptionIce, ExceptionIce;
			
		void addDirectoryWithFilesEndingInRegularExpression(string directory, string regularExpression, string userId, string botId, string endUserId)
		    throws IllegalArgumentExceptionIce, DirectoryNotFoundExceptionIce, ExceptionIce;

		void addDirectoryUnlessAlreadyAdded(string directory, string userId, string botId, string endUserId)
		    throws IllegalArgumentExceptionIce, DirectoryNotFoundExceptionIce, ExceptionIce;
			
		void addDirectoryWithFilesEndingInRegularExpressionUnlessAlreadyAdded(string directory, string regularExpression, string userId, string botId, string endUserId)
		    throws IllegalArgumentExceptionIce, DirectoryNotFoundExceptionIce, ExceptionIce;
            
		void removeDirectory(string directory, string userId, string botId, string endUserId)
		    throws IllegalArgumentExceptionIce, DirectoryNotFoundExceptionIce, ExceptionIce;
			
		void removeDirectoryWithFilesEndingInRegularExpression(string directory, string regularExpression, string userId, string botId, string endUserId)
		    throws IllegalArgumentExceptionIce, DirectoryNotFoundExceptionIce, ExceptionIce;
			
		void addString(string stringContainingAIML, string userId, string botId, string endUserId)
		    throws ExceptionIce;

		void removeString(string stringContainingAIML, string userId, string botId, string endUserId)
		    throws ExceptionIce;
			
		idempotent void setAddStringAIMLHeader(string aimlHeader)
		    throws ExceptionIce;
			
		idempotent void setAddStringAIMLFooter(string aimlFooter)
		    throws ExceptionIce;
		
		idempotent void setAIMLSchema(string schema)
		    throws ExceptionIce, FileNotFoundExceptionIce;

		idempotent void setCommonTypesSchema(string schema)
		    throws ExceptionIce, FileNotFoundExceptionIce;
		
		idempotent void setAIMLValidation(bool trueOrFalse)
		    throws ExceptionIce;
		
		string getResponse(string input, string userId, string botId, string endUserId)
			throws ExceptionIce;

		idempotent void setThat(string that, string userId, string botId, string endUserId)
		    throws ExceptionIce;
		
		idempotent void setTopic(string topic, string userId, string botId, string endUserId)
		    throws ExceptionIce;
		
		["cpp:const"] idempotent string getThat(string userId, string botId, string endUserId)
		    throws ExceptionIce;
		
		["cpp:const"] idempotent string getTopic(string userId, string botId, string endUserId)
		    throws ExceptionIce;
		
		void createGraph(string userId, string botId, string endUserId)
			throws XMLErrorExceptionIce, ExceptionIce;

		void removeGraph(string userId, string botId, string endUserId)
			throws XMLErrorExceptionIce, ExceptionIce;
			
		["cpp:const"] idempotent bool predicateMatch(string predicateName, string aimlPattern, string userId, string botId, string endUserId)
		    throws ExceptionIce;
		
		idempotent void setPredicate(string name, string value, string userId, string botId, string endUserId)
		    throws ExceptionIce;
		
		["cpp:const"] idempotent string getPredicate(string name, string userId, string botId, string endUserId)
		    throws ExceptionIce;
		
		["cpp:const"] idempotent string getBotPredicate(string name, string userId, string botId, string endUserId)
		    throws ExceptionIce;
		
		idempotent void setBotPredicate(string name, string value, string userId, string botId, string endUserId)
		    throws ExceptionIce;
		
		["cpp:const"] idempotent string getPreviousBotResponse(int previousBotResponse, int sentence, string userId, string botId, string endUserId)
		    throws IllegalArgumentExceptionIce, ExceptionIce;
		
		["cpp:const"] idempotent string getPreviousUserInput(int previousUserInput, int sentence, string userId, string botId, string endUserId)
		    throws IllegalArgumentExceptionIce, ExceptionIce;
		
		idempotent void setBotConfigurationSchema(string schema)
		    throws ExceptionIce, FileNotFoundExceptionIce;
		
		idempotent void setBotConfigurationValidation(bool trueOrFalse)
		    throws ExceptionIce;
		
		void parseSubstitutionFile(string fileName)
		    throws XMLErrorExceptionIce, FileNotFoundExceptionIce, ExceptionIce;
		
		void parseSentenceSplitterFile(string fileName)
		    throws XMLErrorExceptionIce, FileNotFoundExceptionIce, ExceptionIce;
		
		void parsePropertiesFile(string fileName, string userId, string botId, string endUserId)
		    throws XMLErrorExceptionIce, FileNotFoundExceptionIce, ExceptionIce;
		
		idempotent void setSentenceSplitter(string splitter)
		    throws ExceptionIce;
			
		idempotent void setInputSubstitution(string find, string replace)
		    throws IllegalArgumentExceptionIce, ExceptionIce;
			
		idempotent void setGenderSubstitution(string find, string replace)
		    throws IllegalArgumentExceptionIce, ExceptionIce;
			
		idempotent void setPersonSubstitution(string find, string replace)
		    throws IllegalArgumentExceptionIce, ExceptionIce;
		
		idempotent void setPerson2Substitution(string find, string replace)
		    throws IllegalArgumentExceptionIce, ExceptionIce;
		
		["cpp:const"] idempotent string getVersion()
			throws ExceptionIce;
			
		["cpp:const"] idempotent int getSize(string userId, string botId, string endUserId)
			throws ExceptionIce;
			
		idempotent void setCallBacks(string name, string category)
		    throws ExceptionIce;

        void storeGossip(string gossip)
			throws ExceptionIce;
			
		["cpp:const"] idempotent string getId()
			throws ExceptionIce;
		
		void addCustomTagLibrary(string library)
		    throws FileNotFoundExceptionIce, ExceptionIce;
			
		void removeCustomTagLibrary(string library)
		    throws FileNotFoundExceptionIce, ExceptionIce;

		["cpp:const"] string callSystemCommand(string command)
		    throws ExceptionIce;
        
        ["cpp:const"] void synchronizeDatabase()
            throws ExceptionIce;
            
		["cpp:const"] idempotent StringSeq getAIMLFileList(string userId, string botId, string endUserId)
            throws ExceptionIce;

		["cpp:const"] idempotent int getAIMLFileListSize(string userId, string botId, string endUserId)
            throws ExceptionIce;
            
		["cpp:const"] idempotent StringSeq getAIMLStringList(string userId, string botId, string endUserId)
            throws ExceptionIce;

		["cpp:const"] idempotent int getAIMLStringListSize(string userId, string botId, string endUserId)
            throws ExceptionIce;

		["cpp:const"] idempotent StringSeq getUserIds()
            throws ExceptionIce;

		["cpp:const"] idempotent int getUserIdsSize()
            throws ExceptionIce;

		["cpp:const"] idempotent StringSeq getBotIds(string userId)
            throws ExceptionIce;

		["cpp:const"] idempotent int getBotIdsSize(string userId)
            throws ExceptionIce;

		["cpp:const"] idempotent StringSeq getEndUserIds(string userId, string botId)
            throws ExceptionIce;

		["cpp:const"] idempotent int getEndUserIdsSize(string userId, string botId)
            throws ExceptionIce;

		["cpp:const"] idempotent void printEntireDatabase()
            throws ExceptionIce;

		["cpp:const"] idempotent StringSeq getBotPredicates(string userId, string botId, string endUserId)
            throws ExceptionIce;

		["cpp:const"] idempotent StringSeq getPredicates(string userId, string botId, string endUserId)
            throws ExceptionIce;

		["cpp:const"] idempotent int getBotPredicatesSize(string userId, string botId, string endUserId)
            throws ExceptionIce;

		["cpp:const"] idempotent int getPredicatesSize(string userId, string botId, string endUserId)
            throws ExceptionIce;

		idempotent void removePredicate(string name, string userId, string botId, string endUserId)
		    throws ExceptionIce;
            
		idempotent void removeBotPredicate(string name, string userId, string botId, string endUserId)
		    throws ExceptionIce;

		void removeEndUser(string userId, string botId, string endUserId)
		    throws ExceptionIce;

		void removeBot(string userId, string botId)
		    throws ExceptionIce;

		void removeUser(string userId)
		    throws ExceptionIce;
            
	};
}; //module impl
}; //module rebecca
