#ifndef REBECCA_FRAMEWORK_GRAPHBUILDERFRAMEWORK_H
#define REBECCA_FRAMEWORK_GRAPHBUILDERFRAMEWORK_H

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

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4290 )
#endif

//Rebecca includes
#include <rebecca/GraphBuilder.h>


namespace rebecca
{
namespace framework
{
namespace impl
{

/*
 * Forward declerations
 */
class CustomTags;

/**
 * Adds more operations to the already existing 
 * set of rebecca::impl::GraphBuilder in which AIML 
 * tags framework developers will need access to.
 *
 * These operations are the operations that 
 * framework developers of AIML tags will need 
 * access to in addition to the operations of 
 * rebecca::impl::GraphBuilder but in which public 
 * users of the api do not need and thus do not 
 * have access to.
 */
class GraphBuilderFramework : public GraphBuilder
{
	public:

		/**
		 * Returns the CallBacks instance so that 
		 * AIML tags can invoke operations on 
		 * the callbacks.
		 *
		 * Use this method to retrieve the callbacks 
		 * object and then invoke the callback directly 
		 * on the object from your AIML tag.  For example,
		 * the ThatStar AIML tag can use getCallBacks to 
		 * invoke 
		 * rebecca::impl::CallBacks::thatStarTagSizeExceeded() 
		 * to inform the user of the api that the tag size was 
		 * exceeded.
		 * If the user of the api has set his callback through 
		 * rebecca::impl::GraphBuilder::setCallBacks() they will 
		 * get a callback informing them that the tag size has 
		 * been exceeded and can deal with it accordingly.
         *
		 * @return The CallBacks reference so that the AIML tag 
		 * can directly call the calls and invoke the callback on 
		 * any listeners.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual CallBacks &getCallBacks() 
			throw(Exception &) = 0;

		/**
		 * Returns the value "captured" by a particular wildcard from the 
		 * pattern-specified portion of the match path during runtime of the 
		 * AIML engine.  
		 * 
		 * Usually this method is used soley by implementations of 
		 * the AIML tag Star.  For example, Star::getString() usually
		 * just calls this method with the index given as its 
		 * attribute.  So, if <star index="2"/> is encountered, the 
		 * Star::getString() method would call GraphBuilderFramework::getStar(2)
         *
		 * @param index indicates which wildcard to use.  1 for the first 
		 * wildcard, 2 for the next, so on so forth.
		 *
		 * @return The string of the value "captured" by a particular wildcard 
		 * from the pattern-specified portion of the match path during the runtime
		 * of the AIML engine.
		 *
		 * @exception IllegalArgumentException will be thrown if the 
		 * argument exceeds the number of wildcards available.  It will throw an 
		 * Exception for any underlying exceptions from other methods it might 
		 * call. 
		 */
		virtual StringPimpl getStar(const unsigned int &index) const
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns the value "captured" by a particular wildcard from the 
		 * pattern-specified portion of the match path during runtime of the 
		 * AIML engine.  
		 * 
		 * Usually this method is used soley by implementations of 
		 * the AIML tag Star.  For example, Star::getString() usually
		 * just calls this method with the index given as its 
		 * attribute.  So, if <star index="2"/> is encountered, the 
		 * Star::getString() method would call GraphBuilderFramework::getStar(2)
         *
		 * @param index indicates which wildcard to use.  1 for the first 
		 * wildcard, 2 for the next, so on so forth.
		 *
		 * @param userId The user id to get the star for.
		 *
		 * @param botId The bot id to get the star for.
		 *
		 * @param endUserId The end user id to get the star for.
		 *
		 * @return The string of the value "captured" by a particular wildcard 
		 * from the pattern-specified portion of the match path during the runtime
		 * of the AIML engine.
		 *
		 * @exception IllegalArgumentException will be thrown if the 
		 * argument exceeds the number of wildcards available.  It will throw an 
		 * Exception for any underlying exceptions from other methods it might 
		 * call. 
		 */
		virtual StringPimpl getStar(const unsigned int &index, 
			                        const StringPimpl &userId,
									const StringPimpl &botId,
									const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns the contents of a wildcard from a pattern-side 
		 * "that" element during the runtime of the AIML engine.
		 * 
		 * Usually this method is used soley by implementations of 
		 * the AIML tag ThatStar. For example, ThatStar::getString() usually
		 * just calls this method with the index given as its 
		 * attribute.  So, if <thatstar index="2"/> is encountered, the 
		 * ThatStar::getString() method would call 
		 * GraphBuilderFramework::getThatStar(2)
         * 
		 * @param index indicates which wildcard to use.  1 for the first 
		 * wildcard, 2 for the next, so on so forth.
		 *
		 * @return The contents of a wildcard from a pattern-side 
		 * "that" element during the runtime of the AIML engine.
         *
		 * @exception IllegalArgumentException will be thrown if the 
		 * argument exceeds the number of wildcards available.  It will throw an 
		 * Exception for any underlying exceptions from other methods it might 
		 * call. 
		 */
		virtual StringPimpl getThatStar(const unsigned int &index) const 
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns the contents of a wildcard from a pattern-side 
		 * "that" element during the runtime of the AIML engine.
		 * 
		 * Usually this method is used soley by implementations of 
		 * the AIML tag ThatStar. For example, ThatStar::getString() usually
		 * just calls this method with the index given as its 
		 * attribute.  So, if <thatstar index="2"/> is encountered, the 
		 * ThatStar::getString() method would call 
		 * GraphBuilderFramework::getThatStar(2)
         * 
		 * @param index indicates which wildcard to use.  1 for the first 
		 * wildcard, 2 for the next, so on so forth.
		 *
		 * @param userId The user id to get the that star for.
		 *
		 * @param botId The bot id to get the that star for.
		 *
		 * @param endUserId The end user id to get the that star for.
		 *
		 * @return The contents of a wildcard from a pattern-side 
		 * "that" element during the runtime of the AIML engine.
         *
		 * @exception IllegalArgumentException will be thrown if the 
		 * argument exceeds the number of wildcards available.  It will throw an 
		 * Exception for any underlying exceptions from other methods it might 
		 * call. 
		 */
		virtual StringPimpl getThatStar(const unsigned int &index,
			                            const StringPimpl &userId,
										const StringPimpl &botId,
										const StringPimpl &endUserId) const 
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns the contents of a wildcard from the 
		 * current topic (if the topic contains any wildcards) during the 
		 * runtime of the AIML engine.
		 * 
		 * Usually this method is used soley by implementations of 
		 * the AIML tag TopicStar. For example, TopicStar::getString() usually
		 * just calls this method with the index given as its 
		 * attribute.  So, if <topicstar index="2"/> is encountered, the 
		 * TopicStar::getString() method would call 
		 * GraphBuilderFramework::getTopicStar(2)
		 *
		 * @param index indicates which wildcard to use.  1 for the first 
		 * wildcard, 2 for the next, so on so forth.
		 * 
		 * @return The contents of a wildcard from the current topic
		 * (if the topic contains any wildcards) during the runtime 
		 * of the AIML engine.
		 *
		 * @exception IllegalArgumentException will be thrown if the 
		 * argument exceeds the number of wildcards available.  It will throw an 
		 * Exception for any underlying exceptions from other methods it might 
		 * call. 
		 */
		virtual StringPimpl getTopicStar(const unsigned int &index) const
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns the contents of a wildcard from the 
		 * current topic (if the topic contains any wildcards) during the 
		 * runtime of the AIML engine.
		 * 
		 * Usually this method is used soley by implementations of 
		 * the AIML tag TopicStar. For example, TopicStar::getString() usually
		 * just calls this method with the index given as its 
		 * attribute.  So, if <topicstar index="2"/> is encountered, the 
		 * TopicStar::getString() method would call 
		 * GraphBuilderFramework::getTopicStar(2)
		 *
		 * @param index indicates which wildcard to use.  1 for the first 
		 * wildcard, 2 for the next, so on so forth.
		 * 
		 * @param userId The user id to get the topic star for.
		 *
		 * @param botId The bot id to get the topic star for.
		 *
		 * @param endUserId The end user id get the topic star for.
         *
		 * @return The contents of a wildcard from the current topic
		 * (if the topic contains any wildcards) during the runtime 
		 * of the AIML engine.
		 *
		 * @exception IllegalArgumentException will be thrown if the 
		 * argument exceeds the number of wildcards available.  It will throw an 
		 * Exception for any underlying exceptions from other methods it might 
		 * call. 
		 */
		virtual StringPimpl getTopicStar(const unsigned int &index,
			                             const StringPimpl &userId,
										 const StringPimpl &botId,
										 const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns the contents of a gender substitution.
		 *
		 * Usually this method is used soly by implementations of 
		 * the AIML tag Gender.  For example, Gender::getString() 
		 * usually calls genderSubstitute with some input to get the 
		 * gender substitution.  
		 * 
		 * Whenever, the user of the api adds a new gender substitution through 
		 * rebecca::impl::GraphBuilder::setGenderSubstitution() this is the method 
		 * an AIML tag should call to automatically have its input 
		 * substituted accordingly.
		 *
		 * @param input The input to have "Gender" substituted
		 *
		 * @return The "Gender" substituted output.
         *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl genderSubstitute(const StringPimpl &input) const 
			throw(Exception &) = 0;

		/**
		 * Returns the contents of a person substitution.
		 *
		 * Usually this method is used soly by implementations of 
		 * the AIML tag Person.  For example, Person::getString() 
		 * usually calls personSubstitute with some input to get the 
		 * person substitution.  
		 * 
		 * Whenever, the user of the api adds a new person substitution through 
		 * rebecca::impl::GraphBuilder::setPersonSubstitution() this is the method 
		 * an AIML tag should call to automatically have its input 
		 * substituted accordingly.
		 *
		 * @param input The input to have "Person" substituted
		 *
		 * @return The "Person" substituted output.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl personSubstitute(const StringPimpl &input) const
			throw(Exception &) = 0;

		/**
		 * Returns the contents of a person2 substitution.
		 *
		 * Usually this method is used soly by implementations of 
		 * the AIML tag Person2.  For example, Person2::getString() 
		 * usually calls person2Substitute with some input to get the 
		 * person2 substitution.  
		 * 
		 * Whenever, the user of the api adds a new person2 substitution through 
		 * rebecca::impl::GraphBuilder::setPerson2Substitution() this is the method 
		 * an AIML tag should call to automatically have its input 
		 * substituted accordingly.
		 *
		 * @param input The input to have "Person2" substituted
		 *
		 * @return The "Person2" substituted output.
		 *
		 * @exception Exception This will not directly throw an exception 
		 * but if an underlying method throws an exception, it will 
		 * be wrapped and thrown as an Exception.
		 */
		virtual StringPimpl person2Substitute(const StringPimpl &input) const
			throw(Exception &) = 0;

		/** 
		 * This is the version of rebecca::impl::GraphBuilder::getResponse() 
		 * for AIML tag implementations.
		 *
		 * This does the same thing as rebecca::impl::GraphBuilder::getResponse() but when it finds 
		 * an infinite loop it throws a rebecca::impl::RecursionException.  This is usually used with 
		 * implementations of the Srai AIML tag to recursively call the AIML engine.  When 
		 * a rebecca::impl::RecursionException occurs the Srai tag calls 
		 * GraphBuilderFramework::getCallBacks() and then 
		 * rebecca::impl::CallBacks::infiniteSymbolicReduction() automatically to indicate an 
		 * infinite loop was found.  
		 *
		 * @param userInput The input to get the AIML engine response of
		 *
		 * @param keepPreviousUserInput Set this to false if you do not want 
		 * the previous user input stored internally.  Usually you only want
		 * to set this to false when you call this from implementations of 
		 * the Srai AIML tag.
		 * 
		 * @return The AIML engine's response.  If it cannot match the input, it 
		 * returns an empty string.
		 *
		 * @exception RecursionException will be thrown if the 
		 * an infinite loop occurs.  
		 * 
		 * @exception Exception will be thrown for any underlying exceptions 
		 * from other methods it might call. 
		 */
		virtual StringPimpl checkedInfiniteLoopGetResponse(const StringPimpl &userInput, 
			                                               bool keepPreviousUserInput = true)
			throw(RecursionException &, Exception &) = 0;

		/** 
		 * This is the version of rebecca::impl::GraphBuilder::getResponse() 
		 * for AIML tag implementations.
		 *
		 * This does the same thing as rebecca::impl::GraphBuilder::getResponse() but when it finds 
		 * an infinite loop it throws a rebecca::impl::RecursionException.  This is usually used with 
		 * implementations of the Srai AIML tag to recursively call the AIML engine.  When 
		 * a rebecca::impl::RecursionException occurs the Srai tag calls 
		 * GraphBuilderFramework::getCallBacks() and then 
		 * rebecca::impl::CallBacks::infiniteSymbolicReduction() automatically to indicate an 
		 * infinite loop was found.  
		 *
		 * @param userInput The input to get the AIML engine response of
		 *
		 * @param keepPreviousUserInput Set this to false if you do not want 
		 * the previous user input stored internally.  Usually you only want
		 * to set this to false when you call this from implementations of 
		 * the Srai AIML tag.
		 * 
		 * @param userId The user id to check the response for.
		 *
		 * @param botId The bot id to check the response for.
		 *
		 * @param endUserId The end user id to check the response for.
         *
		 * @return The AIML engine's response.  If it cannot match the input, it 
		 * returns an empty string.
		 *
		 * @exception RecursionException will be thrown if the 
		 * an infinite loop occurs.  
		 * 
		 * @exception Exception will be thrown for any underlying exceptions 
		 * from other methods it might call. 
		 */
		virtual StringPimpl checkedInfiniteLoopGetResponse(const StringPimpl &userInput, 
			                                               const StringPimpl &userId,
														   const StringPimpl &botId,
														   const StringPimpl &endUserId,
			                                               bool keepPreviousUserInput = true)
			throw(RecursionException &, Exception &) = 0;

		/**
		 * Returns the previous AIML engine's response with the punctuation not 
		 * stripped from the end.
		 *
		 * Usually this is used with implementations of the AIML template side tag That.
		 * 
		 * @param previousBotResponse the index of the previous AIML engine response.
		 *
		 * @param sentence From the response about to be returned, which sentence of the 
		 * previous response to return.
		 *
		 * @return The previous AIML engine's response
		 *
		 * @exception IllegalArgumentException will be thrown if the 
		 * arguments exceed the number of wildcards available.  
		 * 
		 * @exception Exception will throw an Exception for any 
		 * underlying exceptions from other methods it might 
		 * call. 
		 */
		virtual StringPimpl getPreviousBotResponsePunctuation(const unsigned int &previousBotResponse, 
			                                                  const unsigned int &sentence) const
			throw(IllegalArgumentException &, Exception &) = 0;

		/**
		 * Returns the previous AIML engine's response with the punctuation not 
		 * stripped from the end.
		 *
		 * Usually this is used with implementations of the AIML template side tag That.
		 * 
		 * @param previousBotResponse the index of the previous AIML engine response.
		 *
		 * @param sentence From the response about to be returned, which sentence of the 
		 * previous response to return.
		 *
		 * @param userId The user id to check the response for.
		 *
		 * @param botId The bot id to check the response for.
		 *
		 * @param endUserId The end user id to check the response for.
         *
		 * @return The previous AIML engine's response
		 *
		 * @exception IllegalArgumentException will be thrown if the 
		 * arguments exceed the number of wildcards available.  
		 * 
		 * @exception Exception For any underlying exceptions 
		 * from other methods it might call. 
		 */
		virtual StringPimpl getPreviousBotResponsePunctuation(const unsigned int &previousBotResponse, 
			                                                  const unsigned int &sentence,
															  const StringPimpl &userId,
															  const StringPimpl &botId,
															  const StringPimpl &endUserId) const
			throw(IllegalArgumentException &, Exception &) = 0;
};

} //end of namespace impl

//Expose just the class name to the framework namespace
using rebecca::framework::impl::GraphBuilderFramework;

} //end of namespace framework
} //end of namespace rebecca


#ifdef _WIN32
#    pragma warning ( pop )
#endif

#endif

