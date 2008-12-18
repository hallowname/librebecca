#ifndef REBECCA_AIMLFACADE_H
#define REBECCA_AIMLFACADE_H

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

/** 
 * The rebecca public namespace you should be "using".
 * 
 * Use this through the "using namespace rebecca;" to get
 * access to the rebecca public classes.
 *
 * The rebecca namespace only contains the symbols that I 
 * expose from the "impl" namespace that I want to be public.
 * ONLY use this namespace.  DO NOT use the impl namespace 
 * since this will pull in unnessary namespace pollution from
 * implementation details.
 */
namespace rebecca
{

/**
 * The implementation namespace in which you
 * *ARE NOT* to import into your project; only 
 * use the public rebecca namespace.
 * 
 * The impl namespace allows me to pollute
 * it with as many symbols through 
 * "using namespace xxxx" calls and NOT pollute
 * the public rebecca namespace with those symbols.
 * 
 * Using this idiom gives me the ability to 
 * specify which symbols I want in the public rebecca 
 * namespace and which symbols I want to remain as
 * implementation details.  Thus when someone does a 
 * "using namespace rebecca", they will only get the rebecca
 * symbols. None of the impl symbols will be there polluting 
 * their namespace.
 */	
namespace impl
{

//Forward decleration
class GraphBuilder;
class Factory;

/**
 * Facade to manage the memory allocation and
 * deallocation of concrete objects that have 
 * publicly exposed interfaces as well as 
 * provide get'ers to the concerte objects 
 * using their exposed interfaces.
 *
 * AimlFacade manages the memory for the 
 * GraphBuilder object.  When AimlFacade is 
 * instantiated it creates the GraphBuilder concerte 
 * implementation with a "new" and stores it inside of its 
 * pointer to the GraphBuilder interface, m_graphBuilder.  
 * When AimlFacade is destroyed it in turn destroys the 
 * GraphBuilder object through this same pointer.
 * 
 * This indirection is needed since GraphBuilder 
 * is an interface and users cannot directly 
 * instantiate it without access to a concrete 
 * implementation.
 * 
 * Since AimlFacade creates and deletes the 
 * GraphBuilder object from the heap with a "new", 
 * the memory management stays inside 
 * of the dll. This is a requirement for 
 * "dll memory boundary safety".
 */
class REBECCA_EXPORT AimlFacade
{
	public:

		/**
		 * Constructs the facade and all the concrete objects to the 
		 * interfaces that have get'ers.
		 * 
		 * Underneath the covers the constructor creates a factory
		 * and from that factor creates the GraphBuilder concrete 
		 * representation and stores it in the m_graphBuilder pointer.
		 *
		 * @exception Exception This constuctor will not explicitly throw an exception. 
		 * However, an underlying method or function could.  More than likely, 
		 * the only exception that would be thrown would be an out of memory 
		 * exception (bad_alloc exception).
		 */
		AimlFacade() 
			throw(Exception &);

		/**
		 * Returns the constructed GraphBuilder object from 
		 * AimlFacade's constructor.  
		 *
		 * The GraphBuilder 
		 * object and memory is constructed in the 
		 * AimlFacade constructor and destoryed in the AimlFacade
		 * destructor. DO NOT try to delete GraphBuilder yourself.
		 * Instead let AimlFacade auotmagically handle the 
		 * construction and deletion of GraphBuilder.
		 * 
		 * @return The GraphBuilder constructed in the 
		 * AimlFacade constructor.
         * 
		 * @exception Exception This constuctor will not explicitly 
		 * throw an exception. 
		 * However, an underlying method or function could.
		 */
		GraphBuilder &getGraphBuilder() 
			throw(Exception &);
	
		/**
		 * Destructs the facade and all the concrete objects to the 
		 * interfaces that have get'ers.  Underneath the covers it 
		 * deletes the GraphBuilder and its respective factory
		 * which created it.
		 */
		virtual ~AimlFacade();
		
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
		 * @param aimlFacade The standard second reference.
		 */
		AimlFacade &operator=(const AimlFacade &aimlFacade);

		/**
		 * The copy constructor.
		 * For now, I am not allowing this to be invoked. In the
		 * future, if I do, it will more than likely be a shallow
		 * copy since it could be potentially expensive to do a 
		 * deep copy of the GraphBuilder object.
		 *
		 * @param aimlFacade The standard second reference
		 */
		AimlFacade(const AimlFacade& aimlFacade);

		/**
		 * The GraphBuilder pointer.  Use 
		 * AimlFacade::getGraphBuilder to obtain a reference 
		 * to this.  The GraphBuilder object is constructed 
		 * in the constructor of AimlFacade and deleted in the 
		 * destructor of AimlFacade.  DO NOT try to delete this 
		 * yourself. Let AimlFacade handle the memory of this for 
		 * "dll memory boundary safety".
		 */
		GraphBuilder *m_graphBuilder;

		/**
		 * Hidden Factory which we use to create 
		 * particular products of AimlFacade
		 */
		Factory *m_factory;
};



} //end namespace impl

//expose AimlFacade to the rebecca namespace
using rebecca::impl::AimlFacade;

} //end namespace rebecca

#ifdef _WIN32
#    pragma warning ( pop )
#endif


#endif
