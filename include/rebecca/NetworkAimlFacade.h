#ifndef REBECCA_NETWORKAIMLFACADE_H
#define REBECCA_NETWORKAIMLFACADE_H

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

//To get the REBECA_EXPORT macro
#include <rebecca/exports.h>
#include <rebecca/Exceptions.h>

//To get the size_t for the deletions
#include <cstddef>

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning ( push )
#    pragma warning( disable : 4290 )
#endif

namespace rebecca
{
namespace impl
{

//Forward decleration
class NetworkGraphBuilder;

/**
 * Facade to manage the memory allocation and
 * deallocation of concrete objects that have 
 * publicly exposed interfaces as well as 
 * provide get'ers to the concrete objects 
 * using their exposed interfaces.
 *
 * NetworkAimlFacade manages the memory for the 
 * GraphBuilder object.  When NetworkAimlFacade is 
 * instantiated it creates the GraphBuilder concrete 
 * implementation with a "new" and stores it inside of its 
 * pointer to the GraphBuilder interface, m_graphBuilder.  
 * When NetworkAimlFacade is destroyed it in turn destroys the 
 * GraphBuilder object through this same pointer.
 * 
 * This indirection is needed since GraphBuilder 
 * is an interface and users cannot directly 
 * instantiate it without access to a concrete 
 * implementation.
 * 
 * Since NetworkAimlFacade creates and deletes the 
 * GraphBuilder object from the heap with a "new", 
 * the memory management stays inside 
 * of the dll. This is a requirement for 
 * "dll memory boundary safety".
 */
class REBECCA_EXPORT NetworkAimlFacade
{
	public:

		/**
		 * Constructs the facade and all the concrete objects to the 
		 * interfaces that have get'ers.
		 * 
		 * Underneath the covers the constructor creates a factory
		 * and from that factor creates the GraphBuilder concrete 
		 * representation and stores it in the m_graphBuilder pointer.
		 * Pass in your argc and argv from your main() to this constructor
		 * so it can parse any commands it might want.  If you don't have
		 * access to your arguments from main() you can "fake" it by passing
		 * in 1 to argc, and a string with the name of your program to argv.
		 *
		 * @param argc Pass this from your main()
		 *
		 * @param argv Pass this from your main()
		 *
		 * @exception NetworkException If it cannot contact the server upon
		 * construction to make the initial connection it will throw a 
		 * network exception with the message of why it cannot contact the 
		 * server. 
		 * @exception Exception If an underlying method throws an exception, 
		 * it will be wrapped and thrown as a Exception.
		 */
		NetworkAimlFacade(int argc, char *argv[]) 
			throw(NetworkException &, Exception &);

		/**
		 * Returns the constructed GraphBuilder object from 
		 * NetworkAimlFacade's constructor.  
		 *
		 * The GraphBuilder 
		 * object and memory is constructed in the 
		 * NetworkAimlFacade constructor and destroyed in 
		 * the NetworkAimlFacade destructor. DO NOT try 
		 * to delete GraphBuilder yourself.  Instead 
		 * let NetworkAimlFacade auotmagically handle the 
		 * construction and deletion of GraphBuilder.
		 * 
		 * @return The GraphBuilder constructed in the 
		 * NetworkAimlFacade constructor.
         * 
		 * @exception No exceptions will be thrown.
		 */
		NetworkGraphBuilder &getNetworkGraphBuilder() throw();

		/**
		 * Destroys the facade and all the concrete objects to the 
		 * interfaces that have get'ers.  Underneath the covers it 
		 * deletes the GraphBuilder and its respective factory
		 * which created it.
		 */
		virtual ~NetworkAimlFacade();
		
		/**
		 * All delete's will be handled through
		 * this dll.
		 *
		 * This is required for dll boundary safety.
		 * Instead of allowing the compiler to 
		 * choose if it wants to inline this 
		 * we have made it so that it cannot.
		 * If we let the compiler choose to 
		 * inline or not inline this and the 
		 * "new operator" we can run into dll
		 * boundary issues.  The issue would be
		 * that the compiler would inline one 
		 * and not the other.  Thus, your 
		 * executable with its own heap would 
		 * allocate/delete and this dll would 
		 * do the other.  That's a dll boundary
		 * safety violation.
		 * 
         * @param p The pointer to an instance
		 * of this object.
		 */
        void operator delete(void* p);


		/**
		 * All new's will be handled through
		 * this dll.
		 *
		 * This is required for dll boundary safety.
		 * Instead of allowing the compiler to 
		 * choose if it wants to inline this 
		 * we have made it so that it cannot.
		 * If we let the compiler choose to 
		 * inline or not inline this and the 
		 * "delete operator" we can run into dll
		 * boundary issues.  The issue would be
		 * that the compiler would inline one 
		 * and not the other.  Thus, your 
		 * executable with its own heap would 
		 * allocate/delete and this dll would 
		 * do the other.  That's a dll boundary
		 * safety violation.
		 * 
         * @param size The size to allocate 
		 * an instance of this object with.
		 *
		 * @return An instance of this object
		 */
		void *operator new(size_t size);


	private:

		/**
		 * The assignment operator.
		 * For now, I am not allowing a copy to be made.  In the
		 * future, if I do, it will more than likely be a shallow 
		 * copy since it could be potentially expensive to do a 
		 * deep copy of the GraphBuilder object.
		 *
		 * @param networkAimlFacade The standard second reference.
		 */
		NetworkAimlFacade &operator=(const NetworkAimlFacade &networkAimlFacade);

		/**
		 * The copy constructor.
		 * For now, I am not allowing this to be invoked. In the
		 * future, if I do, it will more than likely be a shallow
		 * copy since it could be potentially expensive to do a 
		 * deep copy of the GraphBuilder object.
		 *
		 * @param networkAimlFacade The standard second reference
		 */
		NetworkAimlFacade(const NetworkAimlFacade& networkAimlFacade);

		/**
		 * The GraphBuilder pointer.  Use 
		 * NetworkAimlFacade::getGraphBuilder to obtain a reference 
		 * to this.  The GraphBuilder object is constructed 
		 * in the constructor of NetworkAimlFacade and deleted in the 
		 * destructor of NetworkAimlFacade.  DO NOT try to delete this 
		 * yourself. Let NetworkAimlFacade handle the memory of this for 
		 * "dll memory boundary safety".
		 */
		NetworkGraphBuilder *m_graphBuilder;
};



} //end namespace impl

//expose AimlFacade to the rebecca namespace
using rebecca::impl::NetworkAimlFacade;

} //end namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif


#endif
