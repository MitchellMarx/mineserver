/*
   Copyright (c) 2010, The Mineserver Project
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
 * Neither the name of the The Mineserver Project nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "plugin.h"
#include "blocks/basic.h"
#include "blocks/falling.h"
#include "blocks/torch.h"
#include "blocks/plant.h"
#include "blocks/snow.h"

Plugin &Plugin::get()
{
  static Plugin instance;
  return instance;
}

void Plugin::init()
{
   // Set default behaviours 
   Callback call;
   /* FIXME: must remember to delete any memory we create here upon server stop */
   
   BlockBasic* basicblock = new BlockBasic();
   call.add("onBroken", Function::from_method<BlockBasic, &BlockBasic::onBroken>(basicblock));
   call.add("onPlace", Function::from_method<BlockBasic, &BlockBasic::onPlace>(basicblock));
   setBlockCallback(BLOCK_STONE, call);
   setBlockCallback(BLOCK_GRASS, call);
   setBlockCallback(BLOCK_DIRT, call);
   setBlockCallback(BLOCK_COBBLESTONE, call);
   setBlockCallback(BLOCK_WOOD, call);
   setBlockCallback(BLOCK_LOG, call);
   setBlockCallback(BLOCK_SOIL, call);
   /* cloth */
   setBlockCallback(BLOCK_RED_CLOTH, call);
   setBlockCallback(BLOCK_ORANGE_CLOTH, call);
   setBlockCallback(BLOCK_YELLOW_CLOTH, call);
   setBlockCallback(BLOCK_LIME_CLOTH, call);
   setBlockCallback(BLOCK_GREEN_CLOTH, call);
   setBlockCallback(BLOCK_AQUA_GREEN_CLOTH, call);
   setBlockCallback(BLOCK_CYAN_CLOTH, call);
   setBlockCallback(BLOCK_BLUE_CLOTH, call);
   setBlockCallback(BLOCK_PURPLE_CLOTH, call);
   setBlockCallback(BLOCK_INDIGO_CLOTH, call);
   setBlockCallback(BLOCK_VIOLET_CLOTH, call);
   setBlockCallback(BLOCK_MAGENTA_CLOTH, call);
   setBlockCallback(BLOCK_PINK_CLOTH, call);
   setBlockCallback(BLOCK_BLACK_CLOTH, call);
   setBlockCallback(BLOCK_GRAY_CLOTH, call);
   setBlockCallback(BLOCK_WHITE_CLOTH, call);
   /* metals */
   setBlockCallback(BLOCK_GOLD_BLOCK, call);
   setBlockCallback(BLOCK_IRON_BLOCK, call);

   setBlockCallback(BLOCK_DOUBLE_STEP, call);
   setBlockCallback(BLOCK_STEP, call);
   setBlockCallback(BLOCK_BRICK, call);
   setBlockCallback(BLOCK_BOOKSHELF, call);
   setBlockCallback(BLOCK_MOSSY_COBBLESTONE, call);
   setBlockCallback(BLOCK_OBSIDIAN, call);
   setBlockCallback(BLOCK_MOB_SPAWNER, call);
   setBlockCallback(BLOCK_WOODEN_STAIRS, call);
   setBlockCallback(BLOCK_DIAMOND_BLOCK, call);
   setBlockCallback(BLOCK_PUMPKIN, call);
   setBlockCallback(BLOCK_COBBLESTONE_STAIRS, call);
   setBlockCallback(BLOCK_SIGN_POST, call);
   setBlockCallback(BLOCK_CLAY, call);
   setBlockCallback(BLOCK_NETHERSTONE, call);
   setBlockCallback(BLOCK_LIGHTSTONE, call);
   setBlockCallback(BLOCK_JACK_O_LANTERN, call);
   setBlockCallback(BLOCK_JUKEBOX, call);

   call.reset();
   BlockFalling* fallingblock = new BlockFalling();
   call.add("onBroken", Function::from_method<BlockBasic, &BlockBasic::onBroken>(basicblock));
   call.add("onPlace", Function::from_method<BlockFalling, &BlockFalling::onPlace>(fallingblock));
   call.add("onNeighbourBroken", Function::from_method<BlockFalling, &BlockFalling::onNeighbourBroken>(fallingblock));
   setBlockCallback(BLOCK_SAND, call);
   setBlockCallback(BLOCK_SLOW_SAND, call);
   setBlockCallback(BLOCK_GRAVEL, call);
   
   call.reset();
   BlockTorch* torchblock = new BlockTorch();
   call.add("onBroken", Function::from_method<BlockBasic, &BlockBasic::onBroken>(basicblock));
   call.add("onPlace", Function::from_method<BlockBasic, &BlockBasic::onPlace>(basicblock));
   call.add("onNeighbourBroken", Function::from_method<BlockTorch, &BlockTorch::onNeighbourBroken>(torchblock));
   setBlockCallback(BLOCK_TORCH, call);
   setBlockCallback(BLOCK_REDSTONE_TORCH_OFF, call);
   setBlockCallback(BLOCK_REDSTONE_TORCH_ON, call);
   
   call.reset();
   BlockPlant* plantblock = new BlockPlant();
   call.add("onBroken", Function::from_method<BlockBasic, &BlockBasic::onBroken>(basicblock));
   call.add("onPlace", Function::from_method<BlockBasic, &BlockBasic::onPlace>(basicblock));
   call.add("onNeighbourBroken", Function::from_method<BlockPlant, &BlockPlant::onNeighbourBroken>(plantblock));
   setBlockCallback(BLOCK_YELLOW_FLOWER, call);
   setBlockCallback(BLOCK_RED_ROSE, call);
   setBlockCallback(BLOCK_BROWN_MUSHROOM, call);
   setBlockCallback(BLOCK_RED_MUSHROOM, call);
   setBlockCallback(BLOCK_CROPS, call);
   setBlockCallback(BLOCK_CACTUS, call);
   setBlockCallback(BLOCK_REED, call);
   setBlockCallback(BLOCK_SAPLING, call);
   
   call.reset();
   BlockSnow* snowblock = new BlockSnow();
   call.add("onNeighbourBroken", Function::from_method<BlockSnow, &BlockSnow::onNeighbourBroken>(snowblock));
   call.add("onPlace", Function::from_method<BlockBasic, &BlockBasic::onPlace>(basicblock));
   setBlockCallback(BLOCK_SNOW, call);

  /* TODO: Unimplemented */
  /* BLOCK_WATER, BLOCK_STATIONARY_WATER */
  /* BLOCK_FIRE */
  /* BLOCK_LEAVES */
  /* BLOCK_SPONGE */
  /* BLOCK_TNT */
  /* BLOCK_CHEST, BLOCK_WORKBENCH,BLOCK_FURNACE, BLOCK_BURNING_FURNACE */
  /* BLOCK_REDSTONE_WIRE */
  /* BLOCK_PORTAL */
  /* BLOCK_GOLD_ORE, BLOCK_IRON_ORE, BLOCK_COAL_ORE, BLOCK_DIAMOND_ORE, BLOCK_GLOWING_REDSTONE_ORE, BLOCK_REDSTONE_ORE */
  /* BLOCK_MINECART_TRACKS */
  /* BLOCK_WOODEN_DOOR, BLOCK_IRON_DOOR */
  /* BLOCK_WALL_SIGN */
  /* BLOCK_LADDER */
  /* BLOCK_LEVER, BLOCK_STONE_BUTTON */
  /* BLOCK_WOODEN_PRESSURE_PLATE, BLOCK_STONE_PRESSURE_PLATE */
  /* BLOCK_FENCE */
  /* BLOCK_ICE */
  /* BLOCK_SNOW_BLOCK */
}

void Plugin::setBlockCallback(const int type, Callback call)
{
   removeBlockCallback(type);
   blockevents.insert(std::pair<int, Callback>(type, call));
}

Callback Plugin::getBlockCallback(const int type)
{
   for (Callbacks::iterator iter = blockevents.begin(); iter != blockevents.end(); iter++)
   {
      if ((*iter).first == type)
      {
         return (*iter).second;
      }
   }

   Callback call;
   return call;
}

bool Plugin::removeBlockCallback(const int type)
{
   for (Callbacks::iterator iter = blockevents.begin(); iter != blockevents.end(); ++iter)
   {
      if (iter->first == type)
      {
           delete &iter->first;
           blockevents.erase(iter);
           return true;
      }
   }
   return false;
}
