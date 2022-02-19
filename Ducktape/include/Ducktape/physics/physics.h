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

#ifndef DUCKTAPE_PHYSICS_PHYSICS_H_
#define DUCKTAPE_PHYSICS_PHYSICS_H_

#include <box2d/box2d.h>

#include <Ducktape/engine/projectsettings.h>
#include <Ducktape/engine/entity.h>

namespace DT
{
	/**
	 * @brief Handling contact callbacks.
	 */
	class ContactListener : public b2ContactListener
	{
	public:
		void BeginContact(b2Contact *contact);

		void EndContact(b2Contact *contact);
	};

	/**
	 * @brief Namespace for dealing with physics.
	 */
	namespace Physics
	{
		extern b2Vec2 b2Gravity;
		extern b2World physicsWorld;
		extern int32 velocityIterations;
		extern int32 positionIterations;
		extern Vector2 globalGravity;

		extern ContactListener contactListener;

		/**
		 * @brief Initialize the physics world.
		 */
		void Init();

		/**
		 * @brief Send a raycast from a point origin to a direction.
		 *
		 * @param origin The origin of the raycast.
		 * @param direction The direction of the raycast.
		 *
		 * @return Collision Info about the collision that was hit by the raycast.
		 */
		Collision Raycast(Vector2 origin, Vector2 direction);
	};
}

#endif