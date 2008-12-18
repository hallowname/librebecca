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

//Rebecca includes
#include <rebecca/impl/NodeMapper.h>
#include <rebecca/impl/DatabaseManager.h>
#include <rebecca/impl/StarsManager.h>
#include <rebecca/impl/GraphBuilderAIML.h>
#include <rebecca/impl/XercesSAXXMLManager.h>
#include <rebecca/impl/Exceptions.h>
#include <rebecca/framework/IdentificationManager.h>
using namespace rebecca::framework;

//Boost includes
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;
//Std includes
#include <iostream>
using namespace std;

namespace rebecca
{
namespace impl
{

NodeMapper::NodeMapper()
	: m_template(0),
	  m_databaseManager(DatabaseManager::getInstance()),
	  m_starsManager(StarsManager::getInstance()),
	  m_identificationManager(IdentificationManager::getInstance()),
	  m_xmlManager(XercesSAXXMLManager::getInstance())
{ }


void NodeMapper::remove(queue<StringPimpl> &wordStack)
{

	StringPimpl key2;
	deque<StringPimpl> secondStack;

	//pull the first word off
	if(wordStack.empty())
	{
		return;
	}
	key2 = wordStack.front();
	wordStack.pop();
	secondStack.push_back(key2);

	//put the other words onto the second stack
	while(!wordStack.empty()) 
	{
		key2 += " " + wordStack.front();
		secondStack.push_back(key2);
		wordStack.pop();
	}

	//delete the <BOTID> default
	key2 = secondStack.back();
	secondStack.pop_back();
	m_databaseManager->deleteRecord(key2);

	if(secondStack.empty())
	{
		return;
	}

	//are there other <BOTID's>?
	//If so just return
	key2 = secondStack.back();
	secondStack.pop_back();
	if(m_databaseManager->recordRangeExists(key2))
	{
		return;
	}
	
	//delete the <BOTID>
	m_databaseManager->deleteRecord(key2);		

	if(secondStack.empty())
	{
		return;
	}

	key2 = secondStack.back();
	secondStack.pop_back();

	//delete the <USERID> default
	//since we don't have any more bots
	m_databaseManager->deleteRecord(key2);		

	if(secondStack.empty())
	{
		return;
	}
}

void NodeMapper::add(const StringPimpl &key, 
					 const Template *templateToAdd,
					 queue<StringPimpl> &wordStack)
{
	if(wordStack.empty())
	{
		m_databaseManager->addRecord(key, templateToAdd->getString());
	}
	else
	{
		if(!m_databaseManager->recordExists(key))
		{
			//Add empty string to represent the empty template
			m_databaseManager->addRecord(key, StringPimpl());
		}
		
		StringPimpl newKey = key + " " + wordStack.front();
		wordStack.pop();
		add(newKey, templateToAdd, wordStack);
	}
}

void NodeMapper::add(const Template *templateToAdd, 
					 queue<StringPimpl> &wordStack)
{
	if(wordStack.empty())
	{
		//Stack is completely empty, I am adding the template and returning.
		m_template = templateToAdd;
	}
	else
	{
		//This is actually a reference to a node inside of the map.
		//It is faster to use a reference inside of the map and change the reference
		//inside of the map directly then to be making tons of copies.
		shared_ptr<NodeMapper> &node = m_links.add(wordStack.front());
		wordStack.pop();
		
		node->add(templateToAdd, wordStack);
	}
}

StringPimpl NodeMapper::getTemplateString(const StringPimpl &path, 
										  bool predicateGet)
{
	queue<StringPimpl> wordStack;
	m_starsManager->clearStars();
	StringPimpl stringCopy;

	StringPimpl topic = GraphBuilderAIML::getInstance()->getTopic();
	for(unsigned int i = 0; i < topic.length(); ++i)
	{
		char c = topic.at(i);
		//If space push it onto the stack
		if(c == ' ')
		{
			stringCopy.transformByTrimmingWhiteSpace();
			if(!stringCopy.empty()) 
			{
				wordStack.push(stringCopy);
				stringCopy.clear();
			}
		}
		else
		{
			//Haven't found the full word yet.
			//Just add the character and keep going.
			stringCopy.push_back(c);
		}
	}
	stringCopy.transformByTrimmingWhiteSpace();
	if(!stringCopy.empty()) 
	{
		wordStack.push(stringCopy);
		stringCopy.clear();
	}
	wordStack.push("<TOPIC>");


	StringPimpl that = GraphBuilderAIML::getInstance()->getThat();
	for(unsigned int i = 0; i < that.length(); ++i)
	{
		char c = that.at(i);
		//If space push it onto the stack
		if(c == ' ')
		{
			stringCopy.transformByTrimmingWhiteSpace();
			if(!stringCopy.empty()) 
			{
				wordStack.push(stringCopy);
				stringCopy.clear();
			}
		}
		else
		{
			//Haven't found the full word yet.
			//Just add the character and keep going.
			stringCopy.push_back(c);
		}
	}
	stringCopy.transformByTrimmingWhiteSpace();
	if(!stringCopy.empty()) 
	{
		wordStack.push(stringCopy);
		stringCopy.clear();
	}
	wordStack.push("<THAT>");

	for(unsigned int i = 0; i < path.length(); ++i)
	{
		char c = path.at(i);
		//If space push it onto the stack
		if(c == ' ')
		{
			stringCopy.transformByTrimmingWhiteSpace();
			if(!stringCopy.empty()) 
			{
				wordStack.push(stringCopy);
				stringCopy.clear();
			}
		}
		else
		{
			//Haven't found the full word yet.
			//Just add the character and keep going.
			//Convert it to upper case 
			//c = toupper(c);
			stringCopy.push_back(c);
		}
	}

	stringCopy.transformByTrimmingWhiteSpace();
	if(!stringCopy.empty()) 
	{
		wordStack.push(stringCopy);
		stringCopy.clear();
	}
	
	//User id and Bot id 
	wordStack.push("<USERID>");
	wordStack.push(m_identificationManager->getUserId());
	wordStack.push("<BOTID>");
	wordStack.push(m_identificationManager->getBotId());
	
	if(predicateGet)
	{
		//This section is for the conditional statements
		shared_ptr<NodeMapper> node = getNode(wordStack);
		if(node.get())
		{
			return node->getTemplateStringPredicate();
		}
		else
		{
			return StringPimpl();
		}
	}
	else
	{
		//Get the template string and then parse it
		StringPimpl returnString;
		bool found = getNodeUsingDB(StringPimpl(), returnString, wordStack);
		if(found && !(returnString.empty()))
		{
			return m_xmlManager->parseTemplateString(returnString);
		}
		else
		{
			return StringPimpl();
		}

	}
}

StringPimpl NodeMapper::getTemplateStringPredicate()
{
	return m_template->getString();
}

bool NodeMapper::getNodeUsingDB(const StringPimpl &key,
								StringPimpl &returnString,
	                            queue<StringPimpl> wordStack)
{
	bool found;
	StringPimpl tempKey;

	//This is used to collect our 
	//star we get from parsing 
	StringPimpl star;

	//We have no more stack left
	//So we just have to see if 
	//this current node has a template
	//and return "this" node or 
	//return a new empty node if 
	//this node does not have a 
	//template
	if(wordStack.empty())
	{
		found = m_databaseManager->getRecord(key, returnString);
		if(found)
		{
			//It has a template so return it.
			return true;
		}
		else
		{
			//No template, we got all the 
			//way through parsing but the end 
			//node doesn't have any info so 
			//just return false 
			//to indicate no template
			return false;
		}
	}
	else 
	{
		//The word stack isn't empty.  So 
		//pull the next word off the front
		StringPimpl word = wordStack.front(); 
		
		if(word == "<THAT>")
		{	
			//Set that we want all stars to be 
			//using the default star since 
			//we're to the point in the 
			//wordstack where the stars 
			//should be the default star
			m_starsManager->setUseDefaultStar();
			found = m_databaseManager->getRecord(key + "<THAT>", returnString);
			if(found)
			{
				wordStack.pop();
				found = getNodeUsingDB(key + "<THAT> ", returnString, wordStack);
				m_starsManager->setUseThatStar();
				return found;
			}
			else
			{
				//We're going backwards in the stack
				//depth so reset that we should be 
				//using the thatStar once again
				m_starsManager->setUseThatStar();
				//Return false since
				//we can't find the "<THAT>" link
				return false;
			}
		}
		else if(word == "<TOPIC>")
		{
			//Set that we want all stars to be 
			//using the thatStar since 
			//we're to the point in the 
			//wordstack where the stars 
			//should be the thatStar
			m_starsManager->setUseThatStar();
			found = m_databaseManager->getRecord(key + "<TOPIC>", returnString);
			if(found)
			{
				wordStack.pop();
				found = getNodeUsingDB(key + "<TOPIC> ", returnString, wordStack);
				//We're going backwards in the stack
				//depth so reset that we should be 
				//using the topic star once again
				m_starsManager->setUseTopicStar();
				return found;
			}
			else
			{
				//We're going backwards in the stack
				//depth so reset that we should be 
				//using the topic star once again
				m_starsManager->setUseTopicStar();
				//Return false since
				//we can't find the "<TOPIC>" link
				return false;
			}
		}
		//If it's the <USERID> that's left then what we have
		//left on the stack is 
		//<USERID> -> (user id) -> <BOTID> -> (bot id) -> template
		//We will hand parse the rest without recursive calls at this
		//point.
		else if(word == "<USERID>" && wordStack.size() == 4)
		{
			//The key 
			tempKey = key;
			tempKey.transformToUpperCase();
			
			//pop off "<USERID>" token
			//get the user id its self
			wordStack.pop();
			
			//get and pop off the userId
			word = wordStack.front();
			wordStack.pop();
			
			//pop off the "<BOTID>" token
			//get the bot id its self
			wordStack.pop();
			found = m_databaseManager->getRecord(tempKey + "<USERID> " + word + " <BOTID> " + wordStack.front(), returnString, true);
			//empty the stack
			wordStack.pop();
			return found;
		}
		
		//At this point the word isn't any of the 
		//special tokens, "<USERID>", "<BOTID>",
		//"<THAT>", or "<TOPIC>"

		//Pop the word from the stack.  We have the 
		//word stored from above into the variable
		//"word".
		wordStack.pop();
		
		//Check to see if we have a link to the "_"
		found = m_databaseManager->getRecord(key + "_", returnString);
		if(found)
		{	
			//We have found a link to the underscore
			//so we have to go down that path.
			
			//Copy the current wordstack because 
			//if we don't find a match we have to 
			//re-use the wordstack again.
			queue<StringPimpl> tempStack = wordStack;

			//Add the word as part of the star.
			star += word;
			
			//While the rest of the words left 
			//go through each one and try to get a
			//match 
			while(!tempStack.empty())
			{	
				//Check if this current stack has a match.
				found = getNodeUsingDB(key + "_ ", returnString, tempStack); 

				if(found)
				{	
					//It does, so add the star and return the result
					m_starsManager->addStar(star);
					return true;
				}
				else
				{	
					//It doesn't, so sdd the latest word to the star 
					//and pop off the temp stack and retry the new word.
					star += " " + tempStack.front();
					tempStack.pop();
				}
			}
			
			//Last chance check to see if we did have a match
			//we can't return true on an empty stack since that would
			//mean we flew past <USERID>, <BOTID>'s and will get false
			//positives
			if(found && !(tempStack.empty()))
			{	
				//It does, so add the star and return the result
				m_starsManager->addStar(star);
				return true;
			}
		}
		
		//Clear the star of whatever we might
		//have added to it.  We are going to 
		//possibly reuse it for when checking 
		//for the "*" star below.
		m_starsManager->clearStars();
		star.clear();

		//Only check directly for the word 
		//if it is not the "*" star. 
		if(word != "*")
		{			
			//See if we have a link to the 
			//word in question.
			found = m_databaseManager->getRecord(key + word, returnString);

			if(found)
			{
				//We have a link to it so recurse with 
				//the link we have and star this over again.
				//Basically, we're drilling furthur down with
				//one less word on the wordStack and have 
				//traveresed one more link in the node mapper.
				found = getNodeUsingDB(key + word + " ", returnString, wordStack);

				if(found)
				{
					return true;
				}
			}
		}
		
		//Up to this point, we have not found a link with a "_", nor
		//have we found a link to the regular word.  Now we're going to
		//try and see if we have a link to the "*".
		
		//Check if we have in our links a "*"
		found = m_databaseManager->getRecord(key + "*", returnString);
		if(found)
		{	
			//We have found a link to the "*"
			//so we have to go down that path.

			//Copy the current wordstack because 
			//if we don't find a match we have to 
			//re-use the wordstack again.
			queue<StringPimpl> tempStack = wordStack;
			
			//If the word is not another "*" then add 
			//that word as part of our star.
			if(word != "*")
			{
				star += word;
			}
			
			//While the rest of the words left 
			//go through each one and try to get 
			//a match 
			while(!tempStack.empty())
			{   	
				//Check if this current stack has a match.
				found = getNodeUsingDB(key + "* ", returnString, tempStack);
				
				if(found)
				{
					//It does, so add the star and return the result
					m_starsManager->addStar(star);
					return true;
				}
				else
				{
					//It doesn't, so sdd the latest word to the star 
					//and pop off the temp stack and retry the new word.
					star += " " + tempStack.front();
					tempStack.pop();
				}
			}

			//Last chance check to see if we did have a match
			//we can't return true on an empty stack since that would
			//mean we flew past <USERID>, <BOTID>'s and will get false
			//positives
			if(found && !(tempStack.empty()))
			{	
				//It does, so add the star and return the result
				m_starsManager->addStar(star);
				return true;
			}
			else
			{
				//It doesn't so we had a "*" but it just 
				//didn't match to anything.  Return an
				//empty pointer since we don't have any 
				//options left at this point.
				return false;
			}
		}
		else
		{
			//At this point we didn't have a link to 
			//a "_", a link to the word in question, 
			//nor did we have a link to a "*".  So, 
			//we're returning immediately with an 
			//empty pointer.
			return false;
		}
	}
}


shared_ptr<NodeMapper> NodeMapper::getNode(queue<StringPimpl> wordStack)
{
	//This is used to collect our 
	//star we get from parsing 
	StringPimpl star;

	//We have no more stack left
	//So we just have to see if 
	//this current node has a template
	//and return "this" node or 
	//return a new empty node if 
	//this node does not have a 
	//template
	if(wordStack.empty())
	{
		if(this->hasTemplate())
		{
			//It has a template so return it.
			return shared_from_this();
		}
		else
		{
			//No template, we got all the 
			//way through parsing but the end 
			//node doesn't have any info so 
			//just return an empty shared_ptr() 
			//to indicate no template
			return shared_ptr<NodeMapper>();
		}
	}
	else 
	{
		//The word stack isn't empty.  So 
		//pull the next word off the front
		StringPimpl word = wordStack.front(); 
		
		if(word == "<THAT>")
		{	
			//Set that we want all stars to be 
			//using the default star since 
			//we're to the point in the 
			//wordstack where the stars 
			//should be the default star
			m_starsManager->setUseDefaultStar(); 
			shared_ptr<NodeMapper> node = m_links.getWordNode("<THAT>", true);
			if(node.get())
			{
				wordStack.pop();
				node = node->getNode(wordStack);
				m_starsManager->setUseThatStar();
				return node;
			}
			else
			{
				//We're going backwards in the stack
				//depth so reset that we should be 
				//using the thatStar once again
				m_starsManager->setUseThatStar();
				//Return empty node since
				//we can't find the "<THAT>" link
				return shared_ptr<NodeMapper>();
			}
		}
		else if(word == "<TOPIC>")
		{
			//Set that we want all stars to be 
			//using the thatStar since 
			//we're to the point in the 
			//wordstack where the stars 
			//should be the thatStar
			m_starsManager->setUseThatStar();
			shared_ptr<NodeMapper> node = m_links.getWordNode("<TOPIC>", true);
			if(node.get())
			{
				wordStack.pop();
				node = node->getNode(wordStack);
				//We're going backwards in the stack
				//depth so reset that we should be 
				//using the topic star once again
				m_starsManager->setUseTopicStar();
				return node;
			}
			else
			{
				//We're going backwards in the stack
				//depth so reset that we should be 
				//using the topic star once again
				m_starsManager->setUseTopicStar();
				//Return empty node since
				//we can't find the "<TOPIC>" link
				return shared_ptr<NodeMapper>();
			}
		}
		//If it's the <USERID> that's left then what we have
		//left on the stack is 
		//<USERID> -> (user id) -> <BOTID> -> (bot id) -> template
		//We will hand parse the rest without recursive calls at this
		//point.
		else if(word == "<USERID>")
		{
			//Get the link connecting to the "<USERID>"
			shared_ptr<NodeMapper> node = m_links.getWordNode("<USERID>", true);
			if(node.get())
			{
				//pop off "<USERID>" token
				//get the user id its self
				//try and match the user id from the links
				//using a case sensitive search.
				wordStack.pop();                              
				word = wordStack.front();                     
				node = node->m_links.getWordNode(word, true); 
				if(node.get())
				{
					//Pop off the user id
					wordStack.pop();                                 
					word = wordStack.front();

					//Now we should only have "<BOTID>" and the 
					//actual bot id left on the stack.  The stack
					//should look like this now,
					//<BOTID> -> (botid) -> template
					node = node->m_links.getWordNode(word, true);
					if(node.get())
					{
						//Now we just have the (botid) value
						//its self.  So let us try to get that
						//value.
						//
						//If we have an empty node
						//or if we have a non empty node 
						//doesn't matter.  We're at the 
						//end so just return it.
						wordStack.pop();
						word = wordStack.front();
						return node->m_links.getWordNode(word, true);
					}
					else
					{
						//Return empty node since
						//we can't match the bot id
						return shared_ptr<NodeMapper>();
					}
				}
				else
				{
					//Return empty node since
					//we can't match the user id
					return shared_ptr<NodeMapper>();
				}
			}
			else
			{
				//Return empty node since we 
				//can't find the <USERID>
				return shared_ptr<NodeMapper>();
			}
		}
		
		//At this point the word isn't any of the 
		//special tokens, "<USERID>", "<BOTID>",
		//"<THAT>", or "<TOPIC>"

		//Pop the word from the stack.  We have the 
		//word stored from above into the variable
		//"word".
		wordStack.pop();
		
		//Check to see if we have a link to the "_"
		shared_ptr<NodeMapper> node = m_links.getUnderScoreNode();

		if(node.get())
		{	
			//We have found a link to the underscore
			//so we have to go down that path.
			
			//Copy the current wordstack because 
			//if we don't find a match we have to 
			//re-use the wordstack again.
			queue<StringPimpl> tempStack = wordStack;

			//Add the word as part of the star.
			star += word;
			
			//While the rest of the words left 
			//go through each one and try to get a
			//match 
			while(!tempStack.empty())
			{	
				//Check if this current stack has a match.
				shared_ptr<NodeMapper> returnNode = node->getNode(tempStack);

				if(returnNode.get())
				{	
					//It does, so add the star and return the result
					m_starsManager->addStar(star);
					return returnNode;					
				}
				else
				{	
					//It doesn't, so sdd the latest word to the star 
					//and pop off the temp stack and retry the new word.
					star += " " + tempStack.front();
					tempStack.pop();
				}
			}
			
			//Last chance check to see if we did have a match
			if(node->hasTemplate())
			{	
				//It does, so add the star and return the result
				m_starsManager->addStar(star);
				return node;
			}
		}
		
		//Clear the star of whatever we might
		//have added to it.  We are going to 
		//possibly reuse it for when checking 
		//for the "*" star below.
		star.clear();
		
		//Only check directly for the word 
		//if it is not the "*" star. 
		if(word != "*")
		{			
			//See if we have a link to the 
			//word in question.
			node = m_links.getWordNode(word);

			if(node.get())
			{
				//We have a link to it so recurse with 
				//the link we have and star this over again.
				//Basically, we're drilling furthur down with
				//one less word on the wordStack and have 
				//traveresed one more link in the node mapper.
				node = node->getNode(wordStack);

				if(node.get())
				{
					//We found a match, so return it.
					return node;
				}
			}
		}
		
		//Up to this point, we have not found a link with a "_", nor
		//have we found a link to the regular word.  Now we're going to
		//try and see if we have a link to the "*".
		
		//Check if we have in our links a "*"
		node = m_links.getStarNode();

		if(node.get())
		{	
			//We have found a link to the "*"
			//so we have to go down that path.

			//Copy the current wordstack because 
			//if we don't find a match we have to 
			//re-use the wordstack again.
			queue<StringPimpl> tempStack = wordStack;
			
			//If the word is not another "*" then add 
			//that word as part of our star.
			if(word != "*")
			{
				star += word;
			}
			
			//While the rest of the words left 
			//go through each one and try to get 
			//a match 
			while(!tempStack.empty())
			{   	
				//Check if this current stack has a match.
				shared_ptr<NodeMapper> returnNode = node->getNode(tempStack);
				
				if(returnNode.get())
				{
					//It does, so add the star and return the result
					m_starsManager->addStar(star);
					return returnNode;
				}
				else
				{
					//It doesn't, so sdd the latest word to the star 
					//and pop off the temp stack and retry the new word.
					star += " " + tempStack.front();
					tempStack.pop();
				}
			}

			//Last chance check to see if we did have a match
			if(node->hasTemplate())
			{	
				//It does, so add the star and return the result
				m_starsManager->addStar(star);
				return node;
			}
			else
			{
				//It doesn't so we had a "*" but it just 
				//didn't match to anything.  Return an
				//empty pointer since we don't have any 
				//options left at this point.
				return shared_ptr<NodeMapper>();
			}
		}
		else
		{
			//At this point we didn't have a link to 
			//a "_", a link to the word in question, 
			//nor did we have a link to a "*".  So, 
			//we're returning immediately with an 
			//empty pointer.
			return shared_ptr<NodeMapper>();
		}
	}
}

shared_ptr<NodeMapper> NodeMapper::Links::getWordNode(const StringPimpl &word, bool caseSensitive)
{
	
	map<StringPimpl, shared_ptr<NodeMapper> >::iterator i;
	
	if(!caseSensitive)
	{
		//match using case insensitiviy.
		StringPimpl caseInsensitiveWord = word;
		caseInsensitiveWord.transformToUpperCase();
		i = m_nodeLink.find(caseInsensitiveWord);
	}
	else
	{
		//match using case sensitivity.
		//This is used for matching userId and botId's 
		//from the graph only.
		i = m_nodeLink.find(word);
	}

	if(i != m_nodeLink.end())
	{
		//Found the node associated with this word
		return i->second;
	}
	else
	{
		//Did not find the node associated with this word
		return shared_ptr<NodeMapper>();
	}
}

shared_ptr<NodeMapper> &NodeMapper::Links::add(StringPimpl &word)
{
	map<StringPimpl, shared_ptr<NodeMapper> >::iterator i;

	i = m_nodeLink.find(word);
	
	if(i != m_nodeLink.end())
	{
		//Word is already represented as a node.  Returning that node
		return i->second;
	}
	else
	{
		//Word is not already a node.  Creating a node for it.
		//returning the reference to that node.
		return m_nodeLink[word] = shared_ptr<NodeMapper>(new NodeMapper);
	}
}

shared_ptr<NodeMapper> NodeMapper::Links::getUnderScoreNode()
{
	return getWordNode("_", true);
}

shared_ptr<NodeMapper> NodeMapper::Links::getStarNode()
{
	return getWordNode("*", true);
}


NodeMapper::~NodeMapper()
{ }


} //end of namespace impl
} //end of namespace rebecca
