//  $Id$
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2011  Joerg Henrichs, Marianne Gagnon
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include "graphics/particle_kind_manager.hpp"
#include "io/file_manager.hpp"
#include <stdexcept>

// ----------------------------------------------------------------------------

ParticleKindManager* ParticleKindManager::singleton = NULL;

ParticleKindManager* ParticleKindManager::get()
{
    if (singleton == NULL) singleton = new ParticleKindManager();
    return singleton;
}

// ----------------------------------------------------------------------------

ParticleKindManager::ParticleKindManager()
{
}

// ----------------------------------------------------------------------------

ParticleKindManager::~ParticleKindManager()
{
    // TODO: free items in map
}

// ----------------------------------------------------------------------------

ParticleKind* ParticleKindManager::getParticles(const char* name)
{
    std::map<std::string, ParticleKind*>::iterator i = m_kinds.find(name);
    if (i == m_kinds.end())
    {
        try
        {
            ParticleKind* newkind = new ParticleKind(file_manager->getGfxFile(name));
            m_kinds[name] = newkind;
            return newkind;
        }
        catch (std::runtime_error& e)
        {
            return NULL;
        }
    }
    else
    {
        return i->second;
    }
}

// ----------------------------------------------------------------------------
