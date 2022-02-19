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

#include <Ducktape/physics/physics.h>
using namespace DT;

void ContactListener::BeginContact(b2Contact *contact)
{
	Entity *bodyA = reinterpret_cast<Entity *>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	Entity *bodyB = reinterpret_cast<Entity *>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

	for (BehaviourScript *bs : bodyA->components)
	{
		if (bs != nullptr)
		{
			Collision collisionB;
			collisionB.body = bodyB;
			bs->OnCollisionEnter(collisionB);
		}
	}

	for (BehaviourScript *bs : bodyB->components)
	{
		if (bs != nullptr)
		{
			Collision collisionA;
			collisionA.body = bodyA;
			bs->OnCollisionEnter(collisionA);
		}
	}
}

void ContactListener::EndContact(b2Contact *contact)
{

	Entity *bodyA = reinterpret_cast<Entity *>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
	Entity *bodyB = reinterpret_cast<Entity *>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);

	for (BehaviourScript *bs : bodyA->components)
	{
		if (bs != nullptr)
		{
			Collision collisionB;
			collisionB.body = bodyB;
			bs->OnCollisionExit(collisionB);
		}
	}

	for (BehaviourScript *bs : bodyB->components)
	{
		if (bs != nullptr)
		{
			Collision collisionA;
			collisionA.body = bodyA;
			bs->OnCollisionExit(collisionA);
		}
	}
}

b2Vec2 Physics::b2Gravity(0.0, 0.0);
b2World Physics::physicsWorld(b2Vec2(0.0, 0.0));
int32 Physics::velocityIterations = 6;
int32 Physics::positionIterations = 2;
Vector2 Physics::globalGravity = Vector2(0.0f, 1.0f);
ContactListener Physics::contactListener;

void Physics::Init()
{
	globalGravity = ProjectSettings::Physics::globalGravity;
	physicsWorld.SetContactListener(&contactListener);
}

Collision Physics::Raycast(Vector2 origin, Vector2 direction)
{
	Collision raycastCallback;
	physicsWorld.RayCast(&raycastCallback, (b2Vec2)origin, (b2Vec2)direction);
	return raycastCallback;
}