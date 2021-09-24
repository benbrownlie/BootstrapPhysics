
*Benjamin Brownlie* |
| --- |
| First Year Game Programming |
| Physics for Games Assessment |

## Game Structure
**Classes, Functions, and Variables**

***This project utilizes AIE's bootstrap***


## PhysicsGame Class

****Variables****

***Private***
* > **aie::Renderer2D m_render-** Used to represent the renderer.
* > **aie::Font m_font-** Used to represent a font.
* > **Scene m_scene-** Used to represent the scene.

****Functions****

***Public***
* > **virtual bool startup()-** Handles variable assignment and creating & adding actors to the scene when the program starts.
* > **virtual void shutdown()-** Handles deleting variables when the program closes.
* > **virtual void update(float deltatime)-** Checks for input presses.
* > **virtual void draw()-** Used to render objects to the screen.

## PhysicsObject Class

****Functions****

* > **protected PhysicsObject(ShapeType shapeID) : m_shapeID(shapeID)-** Constructor for shape objects.

***Public***
* > **virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0-** Handles gravity each frame.
* > **virtual void draw() = 0-** draws the objects.
* > **virtual void resetPosition()-** 
* > **ShapeType getShapeID()-** Returns the variable m_shapeID.

## PhysicsProject Class

Calls game->run

## PhysicsScene Class

****Variables****

***Private***
* > **glm::vec2 m_gravity**
* > **float m_timeStep**
* > **std::set<PhysicsObject m_actors**

****Functions****

***Public***
* > **PhysicsScene()-** Constructor for PhysicsScene.
* > **~PhysicsScene()-** Destructor for PhysicsScene.
* > **void addActor(PhysicsObject actor)-** Adds actors to the scene by passing in the desired actor.
* > **void removeActor(PhysicsObject actor)-** Removes actors from the scene by passing in the actor to be removed.
* > **void update(float deltaTime)-** Used to check for actor collisions.
* > **void draw()-** Calls the actor's draw functions.
* > **void setGravity(const glm::vec2 gravity)-** Sets the variable m_gravity to be the parameter gravity.
* > **glm::vec2 getGravity() const-** Returns the variable m_gravity.
* > **void setTimeStep(const float timeStep)-** Sets the variable m_timeStep to be the parameter timeStep.
* > **float getTimeStep() const-** Returns the variable m_timeStep.

***These Functions are used to check for collisions between each shape against one another.***
* > **static bool planeToPlane(PhysicsObject object1, PhysicsObject object2)-**
* > **static bool planeToSphere(PhysicsObject object1, PhysicsObject object2)-**
* > **static bool planeToBox(PhysicsObject object1, PhysicsObject object2)-**
* > **static bool sphereToPlane(PhysicsObject object1, PhysicsObject object2)-**
* > **static bool sphereToSphere(PhysicsObject object1, PhysicsObject object2)-**
* > **static bool sphereToBox(PhysicsObject object1, PhysicsObject object2)-**
* > **static bool boxToPlane(PhysicsObject object1, PhysicsObject object2)-**
* > **static bool boxToSphere(PhysicsObject object1, PhysicsObject object2)-**
* > **static bool boxToBox(PhysicsObject object1, PhysicsObject object2)-**

## Plane Class

****Variables****

***Private***
* > **glm::vec2 m_normal**
* > **float m_distance**
* > **glm::vec4 m_color**

****Functions****

***Public***
* > Plane(glm::vec2 normal, float distance, glm::vec4 color)-** Contructor for Plane.
* > ~Plane()-** Destructor for Plane.
* > **virtual void fixedUpdate(glm::vec2 gravity, float timeStep)-** Non frame dependant update.
* > **virtual void draw()-** Handles drawing the planes in the scene.
* > **void resolveCollision(RigidBody* other)-** Handles collisions with other RigidBodies.
* > **glm::vec2 getNormal()-** Returns the variable m_normal.
* > **float getDistance()-** Returns the variable m_distance.
* > **glm::vec4 getColor()-** Returns the variable m_color.

## RigidBody Class

****Variables****

***Private***
* > **glm::vec2 m_position** 
* > **glm::vec2 m_velocity**
* > **float m_orientation**
* > **float m_mass**

****Functions****

***Public***
* > **RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float orientation, float mass)-** Constructor for a RigidBody.
* > **~RigidBody()-** Destructor for a RigidBody.
* > **virtual void fixedUpdate(glm::vec2 gravity, float timeStep)-** Non frame dependant update that handles the RigidBody's forces.
* > **void applyForce(glm::vec2 force)-** Applies a force to the RigidBody based off its: acceleration, mass, and velocity. 
* > **void applyForceToOther(RigidBody other, glm::vec2 force)-** Calls applyForce on the RigidBody passed in.
* > **void resolveCollision(RigidBody other)-** Handles collisions with other RigidBodies.
* > **glm::vec2 getPosition()-** Returns the variable m_position.
* > **glm::vec2 getVelocity()-** Returns the variable m_velocity.
* > **float getOrienation()-** Returns the variable m_orientation.
* > **float getMass()-** Returns the variable m_mass.

## Sphere Class

****Variables****

***Private***
* > float m_radius;
* > glm::vec4 m_color;

****Functions****

***Public***
* > **Sphere(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color)-** Constructor for Sphere.
* > **~Sphere()-** Destructor for Sphere.
* > **virtual void draw()-** Draws the Sphere to the scene by adding a 2D circle.
* > **float getRadius()-** Returns the variable m_radius.
* > **glm::vec4 getColor()-** Returns the variable m_color.