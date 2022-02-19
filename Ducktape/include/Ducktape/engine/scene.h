/*
MIT License

Copyright (c) 2022 Ducktape

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef DUCKTAPE_ENGINE_SCENE_H_
#define DUCKTAPE_ENGINE_SCENE_H_

#include <vector>

#include <Ducktape/engine/vector2.h>

namespace DT
{
	class Entity;

	/**
	 * @brief Scene system for Ducktape. This class can be used to create and manage entities
	 * in different scenes.
	 * 
	 * Ducktape allows your game to be split into different Scenes, for easier Entity management. For example, users usually would like to split their menu screen and actual game into two different scenes. 
	 * Scripting a Scene is done by creating a class that inherits `DT::Scene` like:
	 * ```cpp
	 * class SampleScene : public Scene 
	 * {
	 * };
	 * ```
	 * Through inheritence, the engine lets you override the `Scene::Init()` method, through which you can manage the entities that needs to be in that specific scene.
	 * 
	 * Example:
	 * ```cpp
	 * // Creating a sample scene
	 * class SampleScene : public Scene
	 * {
	 * public:
	 *     void Init()
	 *     {
	 *         // Creating the Camera
	 *         Entity* player = Entity::Instantiate("Main Camera");
	 *         player->AddComponent<Camera>();
	 * 
	 *         // Creating a player entity
	 *         Entity* player = Entity::Instantiate("Player");
	 *         player->AddComponent<PlayerController>();
	 *         player->AddComponent<SpriteRenderer>();
	 *     }
	 * };
	 * ```
	 */
	class Scene
	{
	public:
		/**
		 * @brief List of entities the scene contains.
		 */
		std::vector<Entity *> entities;

		/**
		 * @brief Called by the Scene Manager when the scene is loaded.
		 */
		virtual void Init() {}

		/**
		 * @brief Called by the Scene Manager when another scene is loaded.
		 */
		void Destroy();
	};
}

#endif