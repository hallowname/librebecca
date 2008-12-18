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
#include <rebecca/framework/Random.h>
#include <rebecca/framework/InnerTemplate.h>
using namespace rebecca::impl;

//Std includes
#include <exception>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

/* Disable Windows VC 7.x warning about 
 * it ignoring the throw specification
 */
#ifdef _WIN32
#    pragma warning( disable : 4290 )
#endif

namespace rebecca
{
namespace framework
{
namespace impl
{

class RandomImpl
{
	public:
		RandomImpl() { }
		~RandomImpl() { } 
		vector<InnerTemplate *> m_sentence;
};

Random::Random()
	throw(InternalProgrammerErrorException &)
	: m_pimpl(new RandomImpl)
{
	addInstanceOf("Random");

	//Seed the random number generator once with the current time
	srand(static_cast<unsigned>(time(0)));

}

void Random::add(InnerTemplate *tag) 
	throw(InternalProgrammerErrorException &)
{
	m_pimpl->m_sentence.push_back(tag);
}

StringPimpl Random::getString() const
	throw(InternalProgrammerErrorException &)
{
	//this avoids division by zero
	if(m_pimpl->m_sentence.size() == 0)
	{
		return StringPimpl();
	}
	else
	{
		int randomNumber = (rand() % m_pimpl->m_sentence.size());	
		return m_pimpl->m_sentence.at(randomNumber)->getString().transformByTrimmingWhiteSpace();
	}
}

Random::~Random()
{ 
	delete m_pimpl;
}

} //end of namespace impl
} //end of namespace framework
} //end of namespace rebecca
