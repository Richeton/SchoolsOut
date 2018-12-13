//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _ENTITY_H               // Prevent multiple definitions if this 
#define _ENTITY_H               // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "image.h"
#include "input.h"
#include "game.h"
#include "state.h"

namespace entityNS
{
	enum class COLLISION_TYPE { NONE, CIRCLE, BOX, ROTATED_BOX };
	enum class ENTITY_TYPE { NONE, GENERAL, PLAYER, RUGBYPLAYERS, TABLE, CHAIR, PROJECTILE };
}

class Collision;
class EntityCollection;

class Entity : public Image
{
	// Entity properties
protected:
	entityNS::COLLISION_TYPE collisionType;
	entityNS::ENTITY_TYPE entityType;
	Collision* collision;
	State* aiState;
	VECTOR2 center;         // center of entity
	float   radius;         // radius of collision circle
	VECTOR2 distSquared;    // used for calculating circle collision
	float   sumRadiiSquared;
	// edge specifies the collision box relative to the center of the entity.
	// left and top are typically negative numbers
	RECT    edge;           // for BOX and ROTATED_BOX collision detection
	VECTOR2 corners[4];     // for ROTATED_BOX collision detection
	VECTOR2 edge01, edge03;  // edges used for projection
	float   edge01Min, edge01Max, edge03Min, edge03Max; // min and max projections
	VECTOR2 velocity;       // velocity
	VECTOR2 deltaV;         // added to velocity during next call to update()
	float   health;         // health 0 to 100
	Input   *input;         // pointer to the input system
	HRESULT hr;             // standard return type
	bool    active;         // only active entities may collide
	bool    rotatedBoxReady;    // true when rotated collision box is ready

								// --- The following functions are protected because they are not intended to be
								// --- called from outside the class.
								// Circular collision detection 
								// Pre: &ent = Other entity
								// Post: &collisionVector contains collision vector
	virtual bool collideCircle(Entity &ent, VECTOR2 &collisionVector);
	// Axis aligned box collision detection
	// Pre: &ent = Other entity
	// Post: &collisionVector contains collision vector
	virtual bool collideBox(Entity &ent, VECTOR2 &collisionVector);
	// Separating axis collision detection between boxes
	// Pre: &ent = Other entity
	// Post: &collisionVector contains collision vector
	virtual bool collideRotatedBox(Entity &ent, VECTOR2 &collisionVector);
	// Separating axis collision detection between box and circle
	// Pre: &ent = Other entity
	// Post: &collisionVector contains collision vector
	virtual bool collideRotatedBoxCircle(Entity &ent, VECTOR2 &collisionVector);
	// Separating axis collision detection helper functions
	void computeRotatedBox();
	bool projectionsOverlap(Entity &ent);
	bool collideCornerCircle(VECTOR2 corner, Entity &ent, VECTOR2 &collisionVector);

	bool vulnerable = true;
	float vulnerableTimer = 0.2f;

public:
	// Constructor
	Entity();
	// Destructor
	virtual ~Entity() {}

	////////////////////////////////////////
	//           Get functions            //
	////////////////////////////////////////

	// Return center of scaled Entity as screen x,y.
	virtual const VECTOR2* getCenter()
	{
		center = VECTOR2(getCenterX(), getCenterY());
		return &center;
	}

	// Return radius of collision circle.
	virtual float getRadius() const { return radius; }

	// Return RECT structure used for BOX and ROTATED_BOX collision detection.
	virtual const RECT& getEdge() const { return edge; }

	// Return corner c of ROTATED_BOX
	virtual const VECTOR2* getCorner(UINT c) const
	{
		if (c >= 4)
			c = 0;
		return &corners[c];
	}

	// Return velocity vector.
	virtual const VECTOR2 getVelocity() const { return velocity; }

	// Return active.
	virtual bool  getActive()         const { return active; }

	// Return health;
	virtual float getHealth()         const { return health; }

	// Return collision type (NONE, CIRCLE, BOX, ROTATED_BOX)
	virtual entityNS::COLLISION_TYPE getCollisionType() { return collisionType; }

	////////////////////////////////////////
	//           Set functions            //
	////////////////////////////////////////

	// Set edge.
	virtual void setEdge(int l,int r,int t,int b)
	{
		edge.left = l;
		edge.top = t;
		edge.bottom = b;
		edge.right = r; 
	}

	// Set velocity.
	virtual void  setVelocity(VECTOR2 v) { velocity = v; }

	// Set delta velocity. Added to velocity in update().
	virtual void  setDeltaV(VECTOR2 dv) { deltaV = dv; }

	// Set active.
	virtual void  setActive(bool a) { active = a; }

	// Set health.
	virtual void setHealth(float h) { health = h; }

	// Set radius of collision circle.
	virtual void setCollisionRadius(float r) { radius = r; }

	////////////////////////////////////////
	//         Other functions            //
	////////////////////////////////////////

	// Update Entity.
	// typically called once per frame
	// frameTime is used to regulate the speed of movement and animation
	virtual void update(float frameTime);

	// Initialize Entity
	// Pre: *gamePtr = pointer to Game object
	//      width = width of Image in pixels  (0 = use full texture width)
	//      height = height of Image in pixels (0 = use full texture height)
	//      ncols = number of columns in texture (1 to n) (0 same as 1)
	//      *textureM = pointer to TextureManager object
	virtual bool initialize(Game *gamePtr, int width, int height, int ncols,
		TextureManager *textureM);
	// Activate Entity.
	virtual void activate();

	// Empty ai function to allow Entity objects to be instantiated.
	virtual void ai(float frameTime, Entity &ent);

	// Is this entity outside the specified rectangle?
	virtual bool outsideRect(RECT rect);

	// Possible Collisions for this Entity <Samuel>
	virtual void collidedWith(Entity &ent, VECTOR2 &collisionVector, EntityCollection &entityCollection);

	// Does this entity collide with ent?
	virtual bool collidesWith(Entity &ent, VECTOR2 &collisionVector);

	// Damage this Entity with weapon.
	virtual void damage(int weapon);

	// Entity bounces after collision with other Entity
	void bounce(Entity &ent, VECTOR2 &collisionVector);

	//void ai(float frameTime, Entity &ent);	// Execute the AI
	void setAI(State * aiState);
	State* getAI();

	entityNS::ENTITY_TYPE getEntityType() { return entityType; }

	bool getVulnerable() { return vulnerable; }
	float getVulnerableTimer() { return vulnerableTimer; }
	void resetVulnerable() { vulnerableTimer = 2.0F; vulnerable = false; }

	void updateVulnerableTimer(float frameTime) 
	{
		vulnerableTimer -= frameTime; 
		if (vulnerableTimer <= 0)
			vulnerable = true;
	}


};

#endif
