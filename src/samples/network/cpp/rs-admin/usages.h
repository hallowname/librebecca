#ifndef RS_ADMIN_H
#define RS_ADMIN_H

/*
 * RebeccaAIML, Artificial Intelligence Markup Language 
 * C++ api and engine.
 *
 * Copyright (C) 2005,2006,2007 Frank Hassanabad
 *
 * This file is part of RebeccaAIML.
 *
 * RebeccaAIML is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * RebeccaAIML is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

namespace rsAdmin
{
using namespace std;

void printAddDirectoryUsage()
{
	cout << "addDirectory takes one or two arguments" 
		 << endl
		 << "Synopsis: rs-admin --addDirectory <directory name> [regular expression of what the files end in (the default is *.aiml)]"
		 << endl
		 << "          rs-admin -ad <directory name> [regular expression of what the files end in (the default is *.aiml)]"
		 << endl
		 << "Example: rs-admin c:\\someDirectory" 
		 << endl
		 << "Example 2: rs-admin \"c:\\someDirectory\" \".*\\.aiml\""
		 << endl;
}

void printSetIdsUsage()
{
	cout << "setIds takes three arguments plus another command"
		 << endl
		 << "Synopsis: rs-admin --setIds <user id> <bot id> <end user id>"
		 << endl
		 << "          rs-admin -sids <user id> <bot id> <end user id>"
		 << endl
		 << "Example: rs-admin -sids \"myUser\" \"myBot\" \"EndUser1\" -gr \"hi\""
		 << endl;
}

void printAddFileUsage()
{
	cout << "addFile takes one argument"
		 << endl
		 << "Synopsis: rs-admin --addFile <file name>"
		 << endl
		 << "          rs-admin -af <file name>"
		 << endl
		 << "Example: rs-admin --addFile \"c:\\some_dir\\someFile.aiml\"" 
		 << endl;
}

void printAddStringUsage()
{
	cout << "addString takes one argument" 
	     << endl
         << "Synopsis: rs-admin --addString <xml string>" 
         << endl
         << "          rs-admin -as <xml string>"
         << endl
         << "Example: rs-admin --addString \"<category><pattern>test aiml string</pattern><template>it simply works!</template></category>\""
         << endl;
}

void printSetAddStringAIMLHeaderUsage()
{
	cout << "setAddStringAIMLHeader takes one argument"
	     << endl
         << "Synopsis: rs-admin --setAddStringAIMLHeader \"<xml string>\""
         << endl
         << "          rs-admin -sash \"<xml string>\""
         << endl
         << "Example: rs-admin setAddStringAIMLHeader"
            "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?> "
            "<aiml version=\"1.0.1\" xmlns=\"http://alicebot.org/2001/AIML-1.0.1\" "
            "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" "
            "xsi:schemaLocation=\"http://alicebot.org/2001/AIML-1.0.1 http://aitools.org/aiml/schema/AIML.xsd\">"
         << endl;
}

void printSetAddStringAIMLFooterUsage()
{
	cout << "setAddStringAIMLFooter takes one argument"
	     << endl
         << "Synopsis: rs-admin --setAddStringAIMLFooter \"<xml string>\""
         << endl
         << "          rs-admin -sasf \"<xml string>\""
         << endl
         << "Example: rs-admin --setAddStringAIMLFooter \"</aiml>\""
         << endl;
}

void printSetAIMLSchemaUsage()
{
	cout << "setAIMLSchema takes one argument"
		 << endl
		 << "Synopsis: rs-admin --setAIMLSchema \"<file Name>\""
		 << endl
		 << "          rs-admin -sas \"<file Name>\""
		 << endl
		 << "Example: rs-admin --setAIMLSchema \"c:\\rebecca\\resources\\schema\\AIML.xsd\""
		 << endl;
}

void printSetCommonTypesSchemaUsage()
{
	cout << "setCommonTypesSchema takes one argument"
	     << endl
		 << "Synopsis: rs-admin --setCommonTypesSchema \"<file Name>\""
		 << endl
		 << "          rs-admin -scts \"<file Name>\""
		 << endl
		 << "Example rs-admin --setCommonTypesSchema \"c:\\rebecca\\resources\\schema\\common-types.xsd\""
		 << endl;
}

void printSetAIMLValidationUsage()
{
	cout << "setAIMLValidation takes one argument"
		 << endl
		 << "Synopsis: rs-admin --setAIMLValidation \"(true|false)\""
		 << endl
		 << "          rs-admin -sav \"(true|false)\""
		 << endl
		 << "Example rs-admin --setAIMLValidation \"true\""
		 << endl;
}

void printGetResponseUsage()
{
	cout << "getResponse takes one argument"
		 << endl
		 << "Synopsis: rs-admin --getResponse \"<some text to talk to the bot>\""
		 << endl
		 << "          rs-admin -gr \"<some text to talk to the bot>\""
		 << endl
		 << "Example rs-admin --getResponse \"Hello\""
		 << endl
		 << "        Hi"
		 << endl;
}

void printCreateGraphUsage()
{
	cout << "createGraph takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --createGraph"
		 << endl
		 << "          rs-admin -cg"
		 << endl
		 << "Example rs-admin --createGraph"
		 << endl;
}

void printSetThatUsage()
{

	cout << "setThat takes one arugment"
		 << endl
		 << "Synopsis: rs-admin --setThat \"<that to set>\" "
		 << endl
		 << "          rs-admin -st \"<that to set>\" "
		 << endl
		 << "Example rs-admin --setThat \"some words\" "
		 << endl;
}

void printSetTopicUsage()
{
	cout << "setTopic takes one arugment"
		 << endl
		 << "Synopsis: rs-admin --setTopic \"<topic to set>\" "
		 << endl
		 << "          rs-admin -stp \"<that to set>\" "
		 << endl
		 << "Example rs-admin --setTopic \"some words\" "
		 << endl;
}

void printGetThatUsage()
{
	cout << "getThat takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getThat"
		 << endl
		 << "          rs-admin -gt"
		 << endl
		 << "Example rs-admin --getThat"
		 << endl
		 << "some words"
		 << endl;
}

void printGetTopicUsage()
{
	cout << "getTopic takes no arugment"
		 << endl
		 << "Synopsis: rs-admin --getTopic"
		 << endl
		 << "          rs-admin -gtp"
		 << endl
		 << "Example rs-admin --getTopic"
		 << endl
		 << "some words"
		 << endl;
}

void printPredicateMatchUsage()
{
	cout << "predicateMatch takes two arguments"
		 << endl
		 << "Synopsis: rs-admin --predicateMatch \"<predicate name>\" \"<aiml pattern>\" "
		 << endl
		 << "          rs-admin -pm \"<predicate name>\" \"<aiml pattern>\" "
		 << endl
		 << "Example rs-admin --predicateMatch \"Hello how are you\" \"Hello *\""
		 << endl
		 << "true"
		 << endl;
}

void printSetPredicateUsage()
{
	cout << "setPredicate takes two arguments"
		 << endl
		 << "Synopsis: rs-admin --setPredicate \"<name>\" \"<value>\""
		 << endl
		 << "          rs-admin -sp \"<name>\" \"<value>\""
		 << endl
		 << "Example rs-admin --setPredicate \"name\" \"Frank\""
		 << endl;
}

void printGetPredicateUsage()
{
	cout << "getPredicate takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getPredicate"
		 << endl
		 << "          rs-admin -gp"
		 << endl
		 << "Example rs-admin --getPredicate \"name\""
		 << endl
		 << "Frank"
		 << endl;
}

void printBotPredicateUsage()
{
	cout << "getBotPredicate takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getBotPredicate"
		 << endl
		 << "          rs-admin -gbp"
		 << endl
		 << "Example rs-admin --getBotPredicate \"name\""
		 << endl
		 << "Rebecca"
		 << endl;
}

void printSetBotPredicateUsage()
{
	cout << "setBotPredicate takes two arguments"
		 << endl
		 << "Synopsis: rs-admin --setBotPredicate \"<name>\" \"<value>\""
		 << endl
		 << "          rs-admin -sbp \"<name>\" \"<value>\""
		 << endl
		 << "Example rs-admin --setBotPredicate \"name\" \"Rebecca\""
		 << endl;
}

void printGetPreviousBotResponseUsage()
{
	cout << "getPreviousBotResponse takes two arguments"
		 << endl
		 << "Synopsis: rs-admin --getPreviousBotResponse \"<previous bot repsonse>\" \"<sentence>\" "
		 << endl
		 << "          rs-admin -gpbr \"<previous bot repsonse>\" \"<sentence>\""
		 << endl
		 << "Example rs-admin --getPreviousBotResponse 1 1"
		 << endl
		 << "Hi"
		 << endl;
}

void printGetPreviousUserInput()
{
	cout << "getPreviousUserInput takes two arguments"
		 << endl
		 << "Synopsis: rs-admin --getPreviousUserInput \"<previous user repsonse>\" \"<sentence>\""
		 << endl
		 << "          rs-admin -gpui \"<previous user repsonse>\" \"<sentence>\""
		 << endl
		 << "Example rs-admin --getPreviousUserInput 1 1"
		 << endl
		 << "Hi"
		 << endl;
}

void printSetBotConfigurationSchemaUsage()
{
	cout << "setBotConfigurationSchema takes 1 argument"
		 << endl
		 << "Synopsis: rs-admin --setBotConfigurationSchema \"<bot schema>\" "
		 << endl
		 << "          rs-admin -sbcs \"<bot schema>\""
		 << endl
		 << "Example rs-admin --setBotConfigurationSchema ../resources/schema/bot-configuration.xsd"
		 << endl;
}

void printSetBotConfigurationValidationUsage()
{
	cout << "setBotConfigurationValidation takes 1 argument"
		 << endl
		 << "Synopsis: rs-admin --setBotConfigurationValidation \"(true|false)\""
		 << endl
		 << "          rs-admin -sbcv \"(true|false)\""
		 << endl
		 << "Example rs-admin --setBotConfigurationValidation \"true\""
		 << endl;
}

void printParseSubstitutionFileUsage()
{
	cout << "parseSubstitutionFile takes 1 argument"
		 << endl
		 << "Synopsis: rs-admin --parseSubstitutionFile \"<substitution file>\""
		 << endl
		 << "          rs-admin -psf \"<substitution file>\""
		 << endl
		 << "Example rs-admin --parseSubstitutionFile \"c:\\rebecca\\conf\\substitutions.xml\""
		 << endl;
}

void printParseSentenceSplitterFileUsage()
{
	cout << "parseSentenceSplitterFile takes 1 argument"
		 << endl
		 << "Synopsis: rs-admin --parseSentenceSplitterFile \"<sentence splitter file>\""
		 << endl
		 << "          rs-admin -pssf \"<sentence splitter file>\""
		 << endl
		 << "Example rs-admin --parseSentenceSplitterFile \"c:\\rebecca\\conf\\sentence-splitters.xml\""
		 << endl;
}

void printParsePropertiesFileUsage()
{
	cout << "parsePropertiesFile takes 1 argument"
		 << endl
		 << "Synopsis: rs-admin --parsePropertiesFile \"<properties file>\""
		 << endl
		 << "          rs-admin -ppf \"<properties file>\""
		 << endl
		 << "Example rs-admin --parsePropertiesFile \"c:\\rebecca\\conf\\properties.xml\""
		 << endl;
}

void printSetSentenceSplitterUsage()
{
	cout << "setSentenceSplitterFile takes 1 argument"
		 << endl
		 << "Synopsis: rs-admin --setSentenceSplitter \"<sentence splitter>\""
		 << endl
		 << "          rs-admin -sss \"<sentence splitter>\""
		 << endl
		 << "Example rs-admin --setSentenceSplitter \";\" "
		 << endl;
}

void printSetInputSubstitutionUsage()
{
	cout << "setInputSubstitutionUsage takes 2 arguments"
		 << endl
		 << "Synopsis: rs-admin --setInputSubstitution \"<find>\" \"<replace>\" "
		 << endl
		 << "          rs-admin -sis \"<find>\" \"<replace>\""
		 << endl
		 << "Example rs-admin --setInputSubstitution \".\" \"dot\" "
		 << endl;
}

void printSetGenderSubstitutionUsage()
{
	cout << "setGenderSubstitution takes 2 arguments"
		 << endl
		 << "Synopsis: rs-admin --setGenderSubstitution \"<find>\" \"<replace>\""
		 << endl
		 << "          rs-admin -sgs \"<find>\" \"<replace>\""
		 << endl
		 << "Example rs-admin --setGenderSubstitution \"he\" \"she\" "
		 << endl;
}

void printSetPersonSubstitutionUsage()
{
	cout << "setPersonSubstitution takes 2 arguments"
		 << endl
		 << "Synopsis: rs-admin --setPersonSubstitution \"<find>\" \"<replace>\""
		 << endl
		 << "          rs-admin -sps \"<find>\" \"<replace>\""
		 << endl
		 << "Example rs-admin --setPersonSubstitution \"he was\" \"I was\" "
		 << endl;
}

void printSetPerson2SubstitutionUsage()
{
	cout << "setPerson2Substitution takes 2 arguments"
		 << endl
		 << "Synopsis: rs-admin --setPerson2Substitution \"<find>\" \"<replace>\""
		 << endl
		 << "          rs-admin -sp2s \"<find>\" \"<replace>\""
		 << endl
		 << "Example rs-admin --setPerson2Substitution \"with you\" \"with me\" "
		 << endl;
}

void printGetVersionUsage()
{
	cout << "getVersion takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getVersion"
		 << endl
		 << "          rs-admin -gv"
		 << endl
		 << "Example rs-admin --getVersion"
		 << endl
		 << "1.1tp3"
		 << endl;
}

void printGetSizeUsage()
{
	cout << "getSize takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getSize"
		 << endl
		 << "          rs-admin -gs"
		 << endl
		 << "Example rs-admin --getSize"
		 << endl
		 << "100"
		 << endl;
}

void printStoreGossipUsage()
{
	cout << "storeGossip takes one argument"
		 << endl
		 << "Synopsis: rs-admin --storeGossip \"<gossip string>\""
		 << endl
		 << "          rs-admin -sg \"<gossip string>\""
		 << endl
		 << "Example rs-admin --storeGossip \"Did you hear the rumor\" "
		 << endl;
}

void printGetIdUsage()
{
	cout << "getId takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getId"
		 << endl
		 << "          rs-admin -gi"
		 << endl
		 << "Example rs-admin --getId"
		 << endl
		 << "id"
		 << endl;
}

void printAddCustomTagLibraryUsage()
{
	cout << "addCustomTagLibrary takes one argument"
		 << endl
		 << "Synopsis: rs-admin --addCustomTagLibrary \"<dll or shared object library>\""
		 << endl
		 << "          rs-admin -actl \"<dll or shared object library>\""
		 << endl
		 << "Example rs-admin --addCustomTagLibrary \"customHtmlTagLayer\" "
		 << endl;
}

void printRemoveCustomTagLibraryUsage()
{
	cout << "removeCustomTagLibrary takes one argument"
		 << endl
		 << "Synopsis: rs-admin --removeCustomTagLibrary \"<dll or shared object library>\""
		 << endl
		 << "          rs-admin -rctl \"<dll or shared object library>\""
		 << endl
		 << "Example rs-admin --removeCustomTagLibrary \"customHtmlTagLayer\" "
		 << endl;
}

void printCallSystemCommandUsage()
{
	cout << "callSystemCommand takes one argument"
		 << endl
		 << "Synopsis: rs-admin --callSystemCommand \"<system command>\""
		 << endl
		 << "          rs-admin -csc \"<system command>\""
		 << endl
		 << "Example rs-admin --callSystemCommand \"echo hello\" "
		 << endl
		 << "Hello"
		 << endl;
}


void printAddFileUnlessAlreadyAddedUsage()
{
	cout << "addFileUnlessAlreadyAdded unless already added takes one argument"
		 << endl
		 << "Synopsis: rs-admin --addFileUnlessAlreadyAdded \"<file to add>\""
		 << endl
		 << "          rs-admin -afuaa \"<file>\""
		 << endl
		 << "Example rs-admin --addFileUnlessAlreadyAdded \"someFile.aiml\" "
		 << endl;
}


void printRemoveFileUsage()
{
	cout << "removeFile takes one argument"
		 << endl
		 << "Synopsis: rs-admin --removeFile \"<file to remove>\""
		 << endl
		 << "          rs-admin -rf \"<file to remove>\""
		 << endl
		 << "Example rs-admin --removeFile \"someFile.aiml\" "
		 << endl;
}


void printAddDirectoryUnlessAlreadyAddedUsage()
{
	cout << "addDirectoryUnlessAlreadyAdded takes one argument"
		 << endl
		 << "Synopsis: rs-admin --addDirectoryUnlessAlreadyAdded \"<directory to add>\""
		 << endl
		 << "          rs-admin -aduaa \"<directory to add>\""
		 << endl
		 << "Example rs-admin --addDirectoryUnlessAlreadyAdded \"/rebecca/aiml/annotated_alice\" "
		 << endl;
}

void printRemoveDirectoryUsage()
{
	cout << "printRemoveDirectoryUsage takes one argument"
		 << endl
		 << "Synopsis: rs-admin --removeDirectory \"<directory to remove>\""
		 << endl
		 << "          rs-admin -rd \"<directory to remove>\""
		 << endl
		 << "Example rs-admin --removeDirectory \"/rebecca/aiml/annotated_alice\" "
		 << endl;
}

void printRemoveStringUsage()
{
	cout << "removeString takes one argument" 
	     << endl
         << "Synopsis: rs-admin --removeString <xml string>" 
         << endl
         << "          rs-admin -rs <xml string>"
         << endl
         << "Example: rs-admin --removeString \"<category><pattern>test aiml string</pattern><template>it simply works!</template></category>\""
         << endl;
}

void printRemoveGraphUsage()
{
	cout << "removeGraph takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --removeGraph"
		 << endl
		 << "          rs-admin -rg"
		 << endl
		 << "Example rs-admin --removeGraph"
		 << endl;
}

void printSynchronizeDatabaseUsage()
{
	cout << "SynchronizeDatabase no arguments"
		 << endl
		 << "Synopsis: rs-admin --synchronizeDatabase"
		 << endl
		 << "          rs-admin -sd"
		 << endl
		 << "Example rs-admin --synchronizeDatabase"
		 << endl;
}


void printGetAIMLFileListUsage()
{
	cout << "GetAIMLFileList takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getAIMLFileList "
		 << endl
		 << "          rs-admin -gafl"
		 << endl
		 << "Example rs-admin --getAIMLFileList"
		 << endl;
}


void printGetAIMLFileListSizeUsage()
{
	cout << "GetAIMLFileListSize takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getAIMLFileListSize"
		 << endl
		 << "          rs-admin -gafls"
		 << endl
		 << "Example rs-admin --getAIMLFileListSize"
		 << endl
		 << "Hello"
		 << endl;
}


void printGetAIMLStringListUsage()
{
	cout << "GetAIMLStringList takes one argument"
		 << endl
		 << "Synopsis: rs-admin --getAIMLStringList"
		 << endl
		 << "          rs-admin -gasl"
		 << endl
		 << "Example rs-admin --getAIMLStringList"
		 << endl
		 << "Hello"
		 << endl;
}

void printGetAIMLStringListSizeUsage()
{
	cout << "GetAIMLStringListSize takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getAIMLStringListSize"
		 << endl
		 << "          rs-admin -gasls"
		 << endl
		 << "Example rs-admin --getAIMLStringListSize"
		 << endl;
}

void printGetUserIdsUsage()
{
	cout << "GetUserIds takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getUserIds"
		 << endl
		 << "          rs-admin -guid"
		 << endl
		 << "Example rs-admin --getUserIds"
		 << endl;
}

void printGetUserIdsSizeUsage()
{
	cout << "GetUserIdsSize takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getUserIdsSize"
		 << endl
		 << "          rs-admin -guids"
		 << endl
		 << "Example rs-admin --getUserIdsSize"
		 << endl;
}


void printGetBotIdsUsage()
{
	cout << "GetBotIds takes one argument"
		 << endl
		 << "Synopsis: rs-admin --getBotIds <user id>"
		 << endl
		 << "          rs-admin -gbid <user id>"
		 << endl
		 << "Example rs-admin --getBotIds \"default\""
		 << endl;
}

void printGetBotIdsSizeUsage()
{
	cout << "GetBotIdsSize takes one argument"
		 << endl
		 << "Synopsis: rs-admin --getBotIdsSize <user id>"
		 << endl
		 << "          rs-admin -gbids <user id>"
		 << endl
		 << "Example rs-admin --getBotIdsSiz \"default\""
		 << endl;
}

void printGetEndUserIdsUsage()
{
	cout << "GetEndUserIds takes two argument"
		 << endl
		 << "Synopsis: rs-admin --getEndUserIds <user id> <bot id>"
		 << endl
		 << "          rs-admin -geuid <user id> <bot id>"
		 << endl
		 << "Example rs-admin --getEndUserIds \"default\" \"default\""
		 << endl;
}


void printGetEndUserIdsSizeUsage()
{
	cout << "GetEndUserIdsSize takes two arguments"
		 << endl
		 << "Synopsis: rs-admin --getEndUserIdsSize <user id> <bot id>"
		 << endl
		 << "          rs-admin -geuids <user id> <bot id>"
		 << endl
		 << "Example rs-admin --getEndUserIdsSize \"default\" \"default\""
		 << endl;
}

void printPrintEntireDatabaseUsage()
{
	cout << "PrintEntireDatabase takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --printEntireDatabase"
		 << endl
		 << "          rs-admin -ped"
		 << endl
		 << "Example rs-admin --printEntireDatabase"
		 << endl;
}

void printGetBotPredicatesUsage()
{
	cout << "GetBotPredicates takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getBotPredicates"
		 << endl
		 << "          rs-admin -gbps"
		 << endl
		 << "Example rs-admin --getBotPredicates"
		 << endl;
}

void printGetPredicatesUsage()
{
	cout << "GetPredicates takes one argument"
		 << endl
		 << "Synopsis: rs-admin --getPredicates"
		 << endl
		 << "          rs-admin -gps"
		 << endl
		 << "Example rs-admin --getPredicates"
		 << endl;
}


void printGetPredicatesSizeUsage()
{
	cout << "GetPredicatesSize takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getPredicatesSize"
		 << endl
		 << "          rs-admin -gpss"
		 << endl
		 << "Example rs-admin --getPredicatesSize"
		 << endl;
}

void printGetBotPredicatesSizeUsage()
{
	cout << "GetBotPredicatesSize takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --getBotPredicatesSize"
		 << endl
		 << "          rs-admin -gbpss"
		 << endl
		 << "Example rs-admin --getBotPredicatesSize"
		 << endl;
}


void printRemovePredicateUsage()
{
	cout << "RemovePredicate takes one argument"
		 << endl
		 << "Synopsis: rs-admin --removePredicate <predicate to remove>"
		 << endl
		 << "          rs-admin -rp <predicate to remove"
		 << endl
		 << "Example rs-admin --removePredicate \"name\" "
		 << endl;
}


void printRemoveBotPredicateUsage()
{
	cout << "RemoveBotPredicate takes one argument"
		 << endl
		 << "Synopsis: rs-admin --removeBotPredicate <predicate to remove>"
		 << endl
		 << "          rs-admin -rbp <predicate to remove"
		 << endl
		 << "Example rs-admin --removeBotPredicate \"name\" "
		 << endl;
}


void printRemoveEndUserUsage()
{
	cout << "RemoveEndUser takes three arguments"
		 << endl
		 << "Synopsis: rs-admin --removeEndUser <user id> <bot id> <end user id>"
		 << endl
		 << "          rs-admin -reu <user id> <bot id> <end user id>"
		 << endl
		 << "Example rs-admin --removeEndUser \"default\" \"default\" \"default\""
		 << endl;
}


void printRemoveBotUsage()
{
	cout << "RemoveBot takes two arguments"
		 << endl
		 << "Synopsis: rs-admin --removeBot <user id> <bot id>"
		 << endl
		 << "          rs-admin -rb <user id> <bot id>"
		 << endl
		 << "Example rs-admin --removeBot <user id> <bot id>"
		 << endl;
}

void printRemoveUserUsage()
{
	cout << "RemoveUser takes one argument"
		 << endl
		 << "Synopsis: rs-admin --removeUser <user id>"
		 << endl
		 << "          rs-admin -ru <user id>"
		 << endl
		 << "Example rs-admin --removeUser <user id>"
		 << endl;
}

void printLocalConnectUsage()
{
	cout << "Local Connect takes no arguments"
		 << endl
		 << "Synopsis: rs-admin --localConnect"
		 << endl
		 << "          rs-admin -lc"
		 << endl
		 << "Example rs-admin --localConnect --getResponse \"hi\""
		 << endl;
}


void printUsage()
{
	cout << "All commands available:" 
		 << endl << endl
         << "==============" 
	     << endl;
	printAddDirectoryUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetIdsUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printAddFileUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printAddFileUnlessAlreadyAddedUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemoveFileUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printAddDirectoryUnlessAlreadyAddedUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemoveDirectoryUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printAddStringUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetAddStringAIMLHeaderUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetAddStringAIMLFooterUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetAIMLSchemaUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetCommonTypesSchemaUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetAIMLValidationUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetResponseUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemoveStringUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printCreateGraphUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetThatUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetTopicUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetThatUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetTopicUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemoveGraphUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printPredicateMatchUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetPredicateUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetPredicateUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printBotPredicateUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetBotPredicateUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetPreviousBotResponseUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetPreviousUserInput();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetBotConfigurationSchemaUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetBotConfigurationValidationUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printParseSubstitutionFileUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printParseSentenceSplitterFileUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printParsePropertiesFileUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetSentenceSplitterUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetInputSubstitutionUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetGenderSubstitutionUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetPersonSubstitutionUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetPerson2SubstitutionUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetVersionUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetSizeUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printStoreGossipUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printAddCustomTagLibraryUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemoveCustomTagLibraryUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printCallSystemCommandUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSynchronizeDatabaseUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetAIMLFileListUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetAIMLFileListSizeUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetAIMLStringListUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetAIMLStringListSizeUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetUserIdsUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetUserIdsSizeUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetBotIdsUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetBotIdsSizeUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetEndUserIdsUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetEndUserIdsSizeUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printPrintEntireDatabaseUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetBotPredicatesUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetPredicatesUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetPredicatesSizeUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printGetBotPredicatesSizeUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemovePredicateUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemoveBotPredicateUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemoveEndUserUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemoveBotUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printRemoveUserUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printLocalConnectUsage();
	cout << "=============="
		 << endl;

	cout << endl
		 << "=============="
		 << endl;
	printSetIdsUsage();
	cout << "=============="
		 << endl;

	cout << endl << endl
		 << "Scroll up to see any individual usages of any commands."
		 << endl
		 << "You can use any of the commands in conjuntion with either" << endl
		 << "local connect (-lc, --localConnection)" << endl
		 << "or set ids (-sids, --setIds) or with both" << endl
		 << endl << endl
	     << "Here are some examples" << endl
	     << "Query server for a response" << endl
		 << "rs-admin --getResponse \"hi\"" << endl << endl
		 << "Query the embedded database without" << endl
	     << "going through the server" << endl
		 << "rs-admin --localConnection --getResponse \"hi\"" << endl << endl
		 << "Query the server for a response" << endl
		 << "using the user id of myUser, bot id of myBot" << endl
		 << "and the end user of myEndUser" << endl
		 << "rs-admin --setIds \"myUser\" \"myBot\" \"myEndUser\" --getResponse \"hi\"" << endl << endl
		 << "Query the server for a response" << endl
		 << "using the user id of myUser, bot id of myBot" << endl
		 << "and the end user of myEndUser using the embedded" << endl
		 << "database without going through the server" << endl
		 << "rs-admin -lc -sids \"myUser\" \"myBot\" \"myEndUser\" -gr \"hi\"" << endl;
};


} //end of rs-admin namespace

#endif


